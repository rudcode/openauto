#pragma once

#include <sigc++/sigc++.h>

enum class VIDEO_FOCUS_REQUESTOR : u_int8_t {
    HEADUNIT = 0, // headunit (we) has requested video focus
    ANDROID_AUTO = 1, // AA phone app has requested video focus
    BACKUP_CAMERA = 2 // CMU requested screen for backup camera
};

class VideoSignals: public sigc::trackable {
public:
    typedef std::shared_ptr<VideoSignals> Pointer;
    using type_signal_focus = sigc::signal<void(VIDEO_FOCUS_REQUESTOR)>;
    type_signal_focus focusRequest;
    type_signal_focus focusRelease;
    type_signal_focus focusChanged;

};