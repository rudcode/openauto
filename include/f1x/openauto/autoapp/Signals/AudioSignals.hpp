#pragma once

#include <sigc++/sigc++.h>
#include <memory>
//#include <f1x/openauto/autoapp/Managers/AudioManager.hpp>

enum class FocusType {
    NONE,
    PERMANENT,
    TRANSIENT,
};

class AudioSignals: public sigc::trackable {
public:
    typedef std::shared_ptr<AudioSignals> Pointer;
    using type_signal_focus = sigc::signal<void(FocusType)>;
    type_signal_focus focusRequest;
    type_signal_focus focusRelease;
    type_signal_focus focusChanged;

};