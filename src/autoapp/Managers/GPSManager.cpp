#include "autoapp/Managers/GPSManager.hpp"
#include <easylogging++.h>

aasdk::proto::data::GPSLocation GPSManager::update_position() {
  aasdk::proto::data::GPSLocation loc;
  try {
    std::tuple<int32_t, uint64_t, double, double, int32_t, double, double, double, double>
        data = gpsclient->getcom_jci_lds_dataInterface()->GetPosition();

    //timestamp 0 means "invalid" and positionAccuracy 0 means "no lock"
    if (std::get<1>(data) == 0 || std::get<0>(data) == 0) {
      std::time_t now = time(nullptr);
      if ((now - lastError) > 60 || lastError == 0) {
        LOG(DEBUG) << "No GPS Fix";
        lastError = now;
      }
      errorCount++;
      return loc;
    }
    errorCount = 0;
    timeval tv{};
    gettimeofday(&tv, nullptr);
    time_t timestamp = std::get<1>(data) * 1000000 + tv.tv_usec;

    loc.set_timestamp(static_cast<uint64_t>(timestamp));
    loc.set_latitude(static_cast<int32_t>(std::get<2>(data) * 1E7));
    loc.set_longitude(static_cast<int32_t>(std::get<3>(data) * 1E7));
    loc.set_accuracy(static_cast<unsigned int>(std::get<7>(data) * 1E3));
    loc.set_altitude(static_cast<int32_t>(std::get<4>(data) * 1E2));
    loc.set_speed(static_cast<int32_t>((std::get<6>(data) * 0.277778) * 1E3));
    loc.set_bearing(static_cast<int32_t>(std::get<5>(data) * 1E6));
    return loc;
  }
  catch (DBus::Error &error) {
    LOG(ERROR) << "DBUS: GetPosition failed " << error.name() << ": " << error.message();
    loc.set_timestamp(0);
    loc.set_latitude(0);
    loc.set_longitude(0);
    loc.set_accuracy(0);
    loc.set_altitude(0);
    loc.set_speed(0);
    loc.set_bearing(0);
    return loc;
  }
}

GPSManager::GPSManager(GpsSignals::Pointer gs, const std::shared_ptr<DBus::Connection> &system_connection)
    : gs_(std::move(gs)), errorCount(0), lastError(0) {

  gpsclient = com_jci_lds_data_objectProxy::create(system_connection, "com.jci.lds.data", "/com/jci/lds/data");
  gpscontrol =
      com_jci_lds_control_objectProxy::create(system_connection, "com.jci.lds.control", "/com/jci/lds/control");
  try {
    gpscontrol->getcom_jci_lds_controlInterface()->ReadControl(0);
    gs_->requestUpdate.connect(sigc::mem_fun(*this, &GPSManager::update_position));
  }
  catch (DBus::Error &error) {
    LOG(ERROR) << "DBUS: ReadControl failed " << error.name() << " : " << error.message();
  }

}

GPSManager::~GPSManager() {
  LOG(DEBUG) << "Stopping GPSManager";
  try {
    gpscontrol->getcom_jci_lds_controlInterface()->ReadControl(0);
  }
  catch (DBus::Error &error) {
    LOG(ERROR) << "DBUS: ReadControl failed " << error.name() << " : " << error.message();
  }
}
