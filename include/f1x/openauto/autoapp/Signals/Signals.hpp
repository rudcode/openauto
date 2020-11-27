#pragma once

#include <memory>
#include <sigc++/sigc++.h>

#include "VideoSignals.hpp"

class Signals{
public:
    typedef std::shared_ptr<Signals> Pointer;


    VideoSignals::Pointer videoSignals;

    Signals(): videoSignals(std::make_shared<VideoSignals>()){};
};