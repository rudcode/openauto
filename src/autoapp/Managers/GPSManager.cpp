#include "autoapp/Managers/GPSManager.hpp"
#include <easylogging++.h>

void GPSManager::update_position() {
  GPSData data;
  try {
    gpsclient.GetPosition(data.positionAccuracy, data.uTCtime, data.latitude, data.longitude, data.altitude,
                          data.heading, data.velocity, data.horizontalAccuracy, data.verticalAccuracy);

    //timestamp 0 means "invalid" and positionAccuracy 0 means "no lock"
    if (data.uTCtime == 0 || data.positionAccuracy == 0) {
      return;
    }
    timeval tv{};
    gettimeofday(&tv, nullptr);
    time_t timestamp = data.uTCtime * 1000000 + tv.tv_usec;

    gs_->returnUpdate.emit(
        static_cast<uint64_t>(timestamp),
        static_cast<int32_t>(data.latitude * 1E7),
        static_cast<int32_t>(data.longitude * 1E7),
        static_cast<unsigned int>(data.horizontalAccuracy * 1E3),
        static_cast<int32_t>(data.altitude * 1E2),
        static_cast<int32_t>((data.velocity * 0.277778) * 1E3),
        static_cast<int32_t>(data.heading * 1E6)
    );

  }
  catch (DBus::Error &error) {
    LOG(ERROR) << "DBUS: GetPosition failed " << error.name() << ": " << error.message();
  }
}

GPSManager::GPSManager(DBus::Connection &serviceBus, GpsSignals::Pointer gs)
    : gpsclient(serviceBus), gpscontrol(serviceBus), gs_(std::move(gs)) {
  try {
    gpscontrol.ReadControl(0);
    gs_->requestUpdate.connect(sigc::mem_fun(*this, &GPSManager::update_position));
  }
  catch (DBus::Error &error) {
    LOG(ERROR) << "DBUS: ReadControl failed " << error.name() << " : " << error.message();
  }

}

GPSManager::~GPSManager() {
  try {
    gpscontrol.ReadControl(0);
  }
  catch (DBus::Error &error) {
    LOG(ERROR) << "DBUS: ReadControl failed " << error.name() << " : " << error.message();
  }
}
