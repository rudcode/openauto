#pragma once

#include <sdbus-c++/sdbus-c++.h>

#include <atomic>
#include <set>
#include <autoapp/Service/VideoService.hpp>
#include <autoapp/Signals/VideoSignals.hpp>

class VideoManager {
 private:
  std::unique_ptr<sdbus::IProxy> bucpsa;
  VideoSignals::Pointer vs;
  bool waitsForFocus = false;
  sigc::connection requestFocusConnection;
  sigc::connection releaseFocusConnection;
  bool currentDisplayMode;
  bool hasFocus = false;

 public:
  explicit VideoManager(VideoSignals::Pointer videosignals);
  ~VideoManager();

  void requestFocus(VIDEO_FOCUS_REQUESTOR requestor);
  void releaseFocus(VIDEO_FOCUS_REQUESTOR requestor);

};