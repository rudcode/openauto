#include "autoapp/Managers/VideoManager.hpp"
#include <easylogging++.h>


BucpsaClient::BucpsaClient(DBus::Connection& hmiBus, VideoSignals::Pointer videosignals)
        : DBus::ObjectProxy(hmiBus, "/com/jci/bucpsa", "com.jci.bucpsa"), _videosignals(std::move(videosignals))
{
    uint32_t DisplayMode;
    int32_t returnValue;
    // check if backup camera is not visible at the moment and get output only when not
    GetDisplayMode(DisplayMode, returnValue);
    currentDisplayMode = (bool)DisplayMode;
}

BucpsaClient::~BucpsaClient() = default;

VideoManager::VideoManager(DBus::Connection &hmiBus, VideoSignals::Pointer videosignals):bucpsa(hmiBus, videosignals), gui(hmiBus), vs(std::move(videosignals)) {
    vs->focusRelease.connect(sigc::mem_fun(*this, &VideoManager::releaseFocus));
    vs->focusRequest.connect(sigc::mem_fun(*this, &VideoManager::requestFocus));
}

void VideoManager::requestFocus(VIDEO_FOCUS_REQUESTOR requestor)
{
//    if (bucpsa.currentDisplayMode && requestor == VIDEO_FOCUS_REQUESTOR::ANDROID_AUTO) {
//        // we can safely exit - backup camera will notice us when finish and we request focus back
//        waitsForFocus = true;
//        return;
//    }
//    if (waitsForFocus && requestor == VIDEO_FOCUS_REQUESTOR::BACKUP_CAMERA)
//    {
//        // need to wait for a second (maybe less but 100ms is too early) to make sure
//        // the CMU has already changed the surface from backup camera to opera
//        sleep(1);
//        waitsForFocus = false;
//    }
    LOG(DEBUG) << "Setting focus, requested by " << static_cast<std::underlying_type<VIDEO_FOCUS_REQUESTOR>::type>(requestor);
    gui.SetRequiredSurfacesByEnum(NativeGUICtrlClient::TV_TOUCH_SURFACE, true);
}

void VideoManager::releaseFocus(VIDEO_FOCUS_REQUESTOR requestor)
{
    LOG(DEBUG) << "Releasing focus, requested by " << static_cast<std::underlying_type<VIDEO_FOCUS_REQUESTOR>::type>(requestor);
    gui.SetRequiredSurfacesByEnum({NativeGUICtrlClient::JCI_OPERA_PRIMARY}, true);
}

VideoManager::~VideoManager()= default;

void BucpsaClient::DisplayMode(const uint32_t &DisplayMode)
{
    currentDisplayMode = (bool)DisplayMode;
    // currentDisplayMode != 0 means backup camera wants the screen
    if((bool)DisplayMode){
        _videosignals->focusRelease.emit(VIDEO_FOCUS_REQUESTOR::BACKUP_CAMERA);
    }
    else{
        _videosignals->focusRequest.emit(VIDEO_FOCUS_REQUESTOR::BACKUP_CAMERA);
    }
}