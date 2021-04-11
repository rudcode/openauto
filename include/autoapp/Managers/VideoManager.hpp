#pragma once

#include <sdbus-c++/sdbus-c++.h>

#include <atomic>
#include <set>
#include <autoapp/Service/VideoService.hpp>
#include <autoapp/Signals/VideoSignals.hpp>

#include <Mazda/Dbus/com.jci.nativeguictrl.h>

class NativeGUICtrlClient final : public sdbus::ProxyInterfaces<com::jci::nativeguictrl_proxy> {
 public:
  NativeGUICtrlClient(std::unique_ptr<sdbus::IConnection> &connection, std::string destination, std::string objectPath)
      : sdbus::ProxyInterfaces<com::jci::nativeguictrl_proxy>(std::move(connection),
                                                              std::move(destination),
                                                              std::move(objectPath)) {
    registerProxy();
  }

  ~NativeGUICtrlClient() {
    unregisterProxy();
  }

  enum SURFACES {
    NNG_NAVI_ID = 0,
    TV_TOUCH_SURFACE = 1,
    NATGUI_SURFACE = 2,
    LOOPLOGO_SURFACE = 3,
    TRANLOGOEND_SURFACE = 4,
    TRANLOGO_SURFACE = 5,
    QUICKTRANLOGO_SURFACE = 6,
    EXITLOGO_SURFACE = 8,
    JCI_OPERA_PRIMARY = 9,
    JCI_OPERA_SECONDARY = 10,
    lvdsSurface = 11,
    SCREENREP_IVI_NAME = 12,
    NNG_NAVI_MAP1 = 13,
    NNG_NAVI_MAP2 = 14,
    NNG_NAVI_HMI = 15,
    NNG_NAVI_TWN = 16,
  };

  void SetRequiredSurfacesByEnum(const int surface, bool fadeOpera) {
    SetRequiredSurfaces(std::to_string(surface), static_cast<int16_t>(fadeOpera ? 1 : 0));
  }
};

class VideoManager {
 private:
  std::unique_ptr<sdbus::IProxy> bucpsa;
  VideoSignals::Pointer vs;
  bool waitsForFocus = false;
  sigc::connection requestFocusConnection;
  sigc::connection releaseFocusConnection;
  bool currentDisplayMode;
  bool hasFocus = false;
  NativeGUICtrlClient *gui;

 public:
  explicit VideoManager(VideoSignals::Pointer videosignals);
  ~VideoManager();

  void requestFocus(VIDEO_FOCUS_REQUESTOR requestor);
  void releaseFocus(VIDEO_FOCUS_REQUESTOR requestor);

};