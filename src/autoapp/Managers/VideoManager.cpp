#include "autoapp/Managers/VideoManager.hpp"
#include <easylogging++.h>

VideoManager::VideoManager(VideoSignals::Pointer videosignals) :
    vs(std::move(videosignals)) {
  auto bucpsaConnection = sdbus::createSessionBusConnection();
  bucpsa = sdbus::createProxy(std::move(bucpsaConnection), "com.jci.bucpsa", "/com/jci/bucpsa");
  bucpsa->uponSignal("DisplayMode").onInterface("com.jci.bucpsa").call([this](const uint32_t &DisplayMode) {
    this->currentDisplayMode = (bool) DisplayMode;
    // currentDisplayMode != 0 means backup camera wants the screen
    if ((bool) DisplayMode) {
      this->vs->focusRelease.emit(VIDEO_FOCUS_REQUESTOR::BACKUP_CAMERA);
      if (hasFocus)
        this->waitsForFocus = true;
    } else {
      this->vs->focusRequest.emit(VIDEO_FOCUS_REQUESTOR::BACKUP_CAMERA);
    }
  });
  bucpsa->finishRegistration();
  std::tuple<uint32_t, int32_t> result;
  bucpsa->callMethod("GetDisplayMode").onInterface("com.jci.bucpsa").storeResultsTo(result);
  currentDisplayMode = (bool) std::get<0>(result);

  releaseFocusConnection = vs->focusRelease.connect(sigc::mem_fun(*this, &VideoManager::releaseFocus));
  requestFocusConnection = vs->focusRequest.connect(sigc::mem_fun(*this, &VideoManager::requestFocus));
}

void VideoManager::requestFocus(VIDEO_FOCUS_REQUESTOR requestor) {
  if (currentDisplayMode && requestor == VIDEO_FOCUS_REQUESTOR::ANDROID_AUTO) {
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
  hasFocus = true;
  vs->focusChanged.emit(true);
}

void VideoManager::releaseFocus(VIDEO_FOCUS_REQUESTOR requestor) {
  LOG(DEBUG) << "Releasing focus, requested by "
             << static_cast<std::underlying_type<VIDEO_FOCUS_REQUESTOR>::type>(requestor);
  hasFocus = false;
  vs->focusChanged.emit(false);
}

VideoManager::~VideoManager() {
  LOG(DEBUG) << "Stopping VideoManager";
  releaseFocusConnection.disconnect();
  requestFocusConnection.disconnect();
  releaseFocus(VIDEO_FOCUS_REQUESTOR::HEADUNIT);
  bucpsa.reset();
}
