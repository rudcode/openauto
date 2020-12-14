#pragma once

#include <memory>
#include <sigc++/sigc++.h>

#include "VideoSignals.hpp"
#include "AudioSignals.hpp"
#include "GpsSignals.hpp"

class Signals: public sigc::trackable {
public:
    typedef std::shared_ptr<Signals> Pointer;


    VideoSignals::Pointer videoSignals = std::make_shared<VideoSignals>();
    AudioSignals::Pointer audioSignals = std::make_shared<AudioSignals>();
    GpsSignals::Pointer gpsSignals = std::make_shared<GpsSignals>();

    Signals() = default;
};