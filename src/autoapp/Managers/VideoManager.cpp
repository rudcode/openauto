#include "autoapp/Managers/VideoManager.hpp"
#include <easylogging++.h>

BucpsaClient::BucpsaClient(std::unique_ptr<sdbus::IConnection> &connection,
                           std::string destination,
                           std::string objectPath,
                           VideoSignals::Pointer videosignals)
    :
    sdbus::ProxyInterfaces<com::jci::bucpsa_proxy>(std::move(connection),
                                                   std::move(destination),
                                                   std::move(objectPath)),
    _videosignals(std::move(videosignals)) {
  registerProxy();
  // check if backup camera is not visible at the moment and get output only when not
  auto mode = GetDisplayMode();
  currentDisplayMode = (bool) std::get<0>(mode);
}

VideoManager::VideoManager(VideoSignals::Pointer videosignals) :
    vs(std::move(videosignals)) {
  auto bucpsaConnection = sdbus::createSessionBusConnection();
  auto guiConnection = sdbus::createSessionBusConnection();
  bucpsa = new BucpsaClient(bucpsaConnection, "com.jci.bucpsa", "/com/jci/bucpsa", videosignals);
  gui = new NativeGUICtrlClient(guiConnection, "com.jci.nativeguictrl", "/com/jci/nativeguictrl");
  releaseFocusConnection = vs->focusRelease.connect(sigc::mem_fun(*this, &VideoManager::releaseFocus));
  requestFocusConnection = vs->focusRequest.connect(sigc::mem_fun(*this, &VideoManager::requestFocus));
}

void VideoManager::requestFocus(VIDEO_FOCUS_REQUESTOR requestor) {
  if (bucpsa->currentDisplayMode && requestor == VIDEO_FOCUS_REQUESTOR::ANDROID_AUTO) {
    // we can safely exit - backup camera will notice us when finish and we request focus back
    waitsForFocus = true;
    return;
  }
  if (waitsForFocus && requestor == VIDEO_FOCUS_REQUESTOR::BACKUP_CAMERA) {
    // need to wait for a second (maybe less but 100ms is too early) to make sure
    // the CMU has already changed the surface from backup camera to opera
    sleep(1);
    waitsForFocus = false;
  }
  LOG(DEBUG) << "Setting focus, requested by "
             << static_cast<std::underlying_type<VIDEO_FOCUS_REQUESTOR>::type>(requestor);
  gui->SetRequiredSurfacesByEnum(NativeGUICtrlClient::TV_TOUCH_SURFACE, true);
  vs->focusChanged.emit(true);
}

void VideoManager::releaseFocus(VIDEO_FOCUS_REQUESTOR requestor) {
  LOG(DEBUG) << "Releasing focus, requested by "
             << static_cast<std::underlying_type<VIDEO_FOCUS_REQUESTOR>::type>(requestor);
  gui->SetRequiredSurfacesByEnum(NativeGUICtrlClient::JCI_OPERA_PRIMARY, true);
  vs->focusChanged.emit(false);
}

VideoManager::~VideoManager() = default;

void VideoManager::stop() {
  releaseFocusConnection.disconnect();
  requestFocusConnection.disconnect();
  releaseFocus(VIDEO_FOCUS_REQUESTOR::HEADUNIT);
  delete gui;
  delete bucpsa;
}

void BucpsaClient::onDisplayMode(const uint32_t &DisplayMode) {
  currentDisplayMode = (bool) DisplayMode;
  // currentDisplayMode != 0 means backup camera wants the screen
  if ((bool) DisplayMode) {
    _videosignals->focusRelease.emit(VIDEO_FOCUS_REQUESTOR::BACKUP_CAMERA);
  } else {
    _videosignals->focusRequest.emit(VIDEO_FOCUS_REQUESTOR::BACKUP_CAMERA);
  }
}