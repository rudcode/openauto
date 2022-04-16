#ifndef COM_JCI_LDS_DATAINTERFACE_H
#define COM_JCI_LDS_DATAINTERFACE_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_lds_data.h"
class com_jci_lds_dataInterface
    : public DBus::Interface {
 private:
  com_jci_lds_dataInterface(com_jci_lds_data *adaptee, std::string name);
 public:
  static std::shared_ptr<com_jci_lds_dataInterface> create(com_jci_lds_data *adaptee,
                                                           std::string name = "com.jci.lds.data");
  std::shared_ptr<DBus::Signal<void(uint8_t, uint8_t)>> signal_GPSDiagnostics();
  void GPSDiagnostics(uint8_t dTCId, uint8_t dTCAction);
  std::shared_ptr<DBus::Signal<void(std::string, int32_t, bool, bool, bool, bool)>> signal_OneTimeDRDiagnostics();
  void OneTimeDRDiagnostics(std::string dRUnitVersion,
                            int32_t antennaStatus,
                            bool gyroSelfTest,
                            bool accelSelfTest,
                            bool resetLearning,
                            bool saveLearning);
  std::shared_ptr<DBus::Signal<void(int32_t, int32_t, bool, int32_t, int32_t, int32_t)>> signal_PeriodicDRDiagnostics();
  void PeriodicDRDiagnostics(int32_t dRUnitStatus,
                             int32_t speedPulse,
                             bool reverse,
                             int32_t dRUnitMode,
                             int32_t gyroStatus,
                             int32_t accelStatus);
 protected:
  std::shared_ptr<DBus::Signal<void(uint8_t, uint8_t)>> m_signal_GPSDiagnostics;
  std::shared_ptr<DBus::Signal<void(std::string, int32_t, bool, bool, bool, bool)>> m_signal_OneTimeDRDiagnostics;
  std::shared_ptr<DBus::Signal<void(int32_t, int32_t, bool, int32_t, int32_t, int32_t)>> m_signal_PeriodicDRDiagnostics;
};
#endif /* COM_JCI_LDS_DATAINTERFACE_H */
