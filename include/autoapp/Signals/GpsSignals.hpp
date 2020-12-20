#pragma once

#include <memory>
#include <sigc++/sigc++.h>

class GpsSignals : public sigc::trackable {
 public:
  typedef std::shared_ptr<GpsSignals> Pointer;
  sigc::signal<void()> requestUpdate;
  sigc::signal<void(uint64_t time, int32_t latitude, int32_t longitude, uint32_t accuracy, int32_t altitude,
                    int32_t speed, int32_t bearing)> returnUpdate;
};