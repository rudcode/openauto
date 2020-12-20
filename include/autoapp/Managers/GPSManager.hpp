#pragma once

#include <autoapp/Signals/GpsSignals.hpp>

#include <Mazda/Dbus/com.jci.lds.data.h>
#include <Mazda/Dbus/com.jci.lds.control.h>

struct GPSData {
  int32_t positionAccuracy = 0;
  uint64_t uTCtime = 0;
  double latitude = 0;
  double longitude = 0;
  int32_t altitude = 0;
  double heading = 0;
  double velocity = 0;
  double horizontalAccuracy = 0;
  double verticalAccuracy = 0;
};

class GPSLDSCLient : public com::jci::lds::data_proxy,
                     public DBus::ObjectProxy {
 public:
  GPSLDSCLient(DBus::Connection &connection)
      : DBus::ObjectProxy(connection, "/com/jci/lds/data", "com.jci.lds.data") {
  }

  void GPSDiagnostics(const uint8_t &dTCId, const uint8_t &dTCAction) override {}

  void OneTimeDRDiagnostics(const std::string &dRUnitVersion, const int32_t &antennaStatus, const bool &gyroSelfTest,
                            const bool &accelSelfTest, const bool &resetLearning,
                            const bool &saveLearning) override {}

  void PeriodicDRDiagnostics(const int32_t &dRUnitStatus, const int32_t &speedPulse, const bool &reverse,
                             const int32_t &dRUnitMode, const int32_t &gyroStatus,
                             const int32_t &accelStatus) override {}

};

class GPSLDSControl : public com::jci::lds::control_proxy,
                      public DBus::ObjectProxy {
 public:
  GPSLDSControl(DBus::Connection &connection)
      : DBus::ObjectProxy(connection, "/com/jci/lds/control", "com.jci.lds.control") {
  }

  void ReadStatus(const int32_t &commandReply, const int32_t &status) override {};
};

class GPSManager {
  struct GPSData {
    int32_t positionAccuracy = 0;
    uint64_t uTCtime = 0;
    double latitude = 0;
    double longitude = 0;
    int32_t altitude = 0;
    double heading = 0;
    double velocity = 0;
    double horizontalAccuracy = 0;
    double verticalAccuracy = 0;
  };

 public:
  GPSManager(DBus::Connection &serviceBus, GpsSignals::Pointer gs);

  ~GPSManager();

  void update_position();

 private:
  GPSLDSCLient gpsclient;
  GPSLDSControl gpscontrol;
  GpsSignals::Pointer gs_;
};