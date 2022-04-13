#pragma once

#include <ctime>
#include <autoapp/Signals/GpsSignals.hpp>

#include <com_jci_lds_data_objectProxy.h>
#include <com_jci_lds_control_objectProxy.h>

class GPSManager {

 public:
  GPSManager(GpsSignals::Pointer gs, const std::shared_ptr<DBus::Connection> &system_connection);

  ~GPSManager();

  aasdk::proto::data::GPSLocation update_position();

 private:
  std::shared_ptr<com_jci_lds_data_objectProxy> gpsclient;
  std::shared_ptr<com_jci_lds_control_objectProxy> gpscontrol;

  GpsSignals::Pointer gs_;
  int errorCount;
  std::time_t lastError;
};