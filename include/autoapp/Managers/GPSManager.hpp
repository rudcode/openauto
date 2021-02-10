#pragma once

#include <ctime>
#include <autoapp/Signals/GpsSignals.hpp>

#include <Mazda/Dbus/com.jci.lds.data.h>
#include <Mazda/Dbus/com.jci.lds.control.h>

class GPSLDSCLient final : public sdbus::ProxyInterfaces<com::jci::lds::data_proxy> {
 public:
  GPSLDSCLient(std::string destination, std::string objectPath)
      : sdbus::ProxyInterfaces<com::jci::lds::data_proxy>(std::move(destination), std::move(objectPath)) {
  }

  void onGPSDiagnostics(const uint8_t &dTCId, const uint8_t &dTCAction) override {};
  void onOneTimeDRDiagnostics(const std::string &dRUnitVersion,
                              const int32_t &antennaStatus,
                              const bool &gyroSelfTest,
                              const bool &accelSelfTest,
                              const bool &resetLearning,
                              const bool &saveLearning) override {};
  void onPeriodicDRDiagnostics(const int32_t &dRUnitStatus,
                               const int32_t &speedPulse,
                               const bool &reverse,
                               const int32_t &dRUnitMode,
                               const int32_t &gyroStatus,
                               const int32_t &accelStatus) override {};

};

class GPSLDSControl final : public sdbus::ProxyInterfaces<com::jci::lds::control_proxy> {
 public:
  GPSLDSControl(std::string destination, std::string objectPath)
      : sdbus::ProxyInterfaces<com::jci::lds::control_proxy>(std::move(destination), std::move(objectPath)) {
  }

  void onReadStatus(const int32_t &commandReply, const int32_t &status) override {};
};

class GPSManager {

 public:
  GPSManager(GpsSignals::Pointer gs);

  ~GPSManager();

  aasdk::proto::data::GPSLocation update_position();

  void stop();

 private:
  GPSLDSCLient *gpsclient;
  GPSLDSControl *gpscontrol;
  GpsSignals::Pointer gs_;
  int errorCount;
  std::time_t lastError;
};