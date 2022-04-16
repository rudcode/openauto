#include "autoapp/Managers/VideoManager.hpp"
#include <easylogging++.h>

VideoManager::VideoManager(VideoSignals::Pointer videosignals,
                           const std::shared_ptr<DBus::Connection> &session_connection) :
    vs(std::move(videosignals)) {
  gui =
      com_jci_nativeguictrl_objectProxy::create(session_connection, "com.jci.nativeguictrl", "/com/jci/nativeguictrl");
  bucpsa = com_jci_bucpsa_objectProxy::create(session_connection, "com.jci.bucpsa", "/com/jci/bucpsa");
  bucpsa->getcom_jci_bucpsaInterface()->signal_DisplayMode()->connect(sigc::mem_fun(*this, &VideoManager::DisplayMode));

  std::tuple<unsigned int, int> display_mode = bucpsa->getcom_jci_bucpsaInterface()->GetDisplayMode();

  currentDisplayMode = (bool) std::get<0>(display_mode);

  releaseFocusConnection = vs->focusRelease.connect(sigc::mem_fun(*this, &VideoManager::releaseFocus));
  requestFocusConnection = vs->focusRequest.connect(sigc::mem_fun(*this, &VideoManager::requestFocus));
}

void VideoManager::DisplayMode(uint32_t DisplayMode) {
  this->currentDisplayMode = (bool) DisplayMode;
  // currentDisplayMode != 0 means backup camera wants the screen
  if ((bool) DisplayMode) {
    this->vs->focusRelease.emit(VIDEO_FOCUS_REQUESTOR::BACKUP_CAMERA);
    if (hasFocus) {
      this->waitsForFocus = true;
    }
  } else {
    this->vs->focusRequest.emit(VIDEO_FOCUS_REQUESTOR::BACKUP_CAMERA);
  }
}

void VideoManager::requestFocus(VIDEO_FOCUS_REQUESTOR requestor) {
  if (currentDisplayMode && requestor == VIDEO_FOCUS_REQUESTOR::ANDROID_AUTO) {
    // we can safely exit - backup camera will notice us when we finish and we request focus back
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
  hasFocus = true;
  gui->getcom_jci_nativeguictrlInterface()->SetRequiredSurfaces(std::to_string(SURFACES::TV_TOUCH_SURFACE), 1);
  vs->focusChanged.emit(true);
}

void VideoManager::releaseFocus(VIDEO_FOCUS_REQUESTOR requestor) {
  LOG(DEBUG) << "Releasing focus, requested by "
             << static_cast<std::underlying_type<VIDEO_FOCUS_REQUESTOR>::type>(requestor);
  hasFocus = false;
  gui->getcom_jci_nativeguictrlInterface()->SetRequiredSurfaces(std::to_string(SURFACES::JCI_OPERA_PRIMARY), 1);
  vs->focusChanged.emit(false);
}

VideoManager::~VideoManager() {
  LOG(DEBUG) << "Stopping VideoManager";
  releaseFocusConnection.disconnect();
  requestFocusConnection.disconnect();
  releaseFocus(VIDEO_FOCUS_REQUESTOR::HEADUNIT);
  bucpsa.reset();
}
