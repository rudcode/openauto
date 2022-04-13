#pragma once

#include <aasdk_proto/GPSLocationData.pb.h>

#include <memory>
#include <sigc++/sigc++.h>

class GpsSignals : public sigc::trackable {
 public:
  typedef std::shared_ptr<GpsSignals> Pointer;
  sigc::signal<aasdk::proto::data::GPSLocation(void)> requestUpdate;
};