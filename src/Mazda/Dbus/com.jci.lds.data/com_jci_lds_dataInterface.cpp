#include "com_jci_lds_dataInterface.h"

com_jci_lds_dataInterface::com_jci_lds_dataInterface(com_jci_lds_data *adaptee, std::string name)
    : DBus::Interface(name) {
  this->create_method<DBus::MultipleReturn<int32_t,
                                           uint64_t,
                                           double,
                                           double,
                                           int32_t,
                                           double,
                                           double,
                                           double,
                                           double>()>("GetPosition",
                                                      sigc::mem_fun(*adaptee, &com_jci_lds_data::GetPosition));
  this->create_method<DBus::MultipleReturn<uint64_t, double, double>()>("GetLastKnownPosition",
                                                                        sigc::mem_fun(*adaptee,
                                                                                      &com_jci_lds_data::GetLastKnownPosition));
  this->create_method<std::string()>("GetGPSFirmwareVersion",
                                     sigc::mem_fun(*adaptee, &com_jci_lds_data::GetGPSFirmwareVersion));
  this->create_method<int32_t()>("GetSatelliteInfo", sigc::mem_fun(*adaptee, &com_jci_lds_data::GetSatelliteInfo));
  m_signal_GPSDiagnostics = create_signal<void(uint8_t, uint8_t)>("GPSDiagnostics");
  m_signal_OneTimeDRDiagnostics =
      create_signal<void(std::string, int32_t, bool, bool, bool, bool)>("OneTimeDRDiagnostics");
  m_signal_PeriodicDRDiagnostics =
      create_signal<void(int32_t, int32_t, bool, int32_t, int32_t, int32_t)>("PeriodicDRDiagnostics");

}
std::shared_ptr<com_jci_lds_dataInterface> com_jci_lds_dataInterface::create(com_jci_lds_data *adaptee,
                                                                             std::string name) {
  return std::shared_ptr<com_jci_lds_dataInterface>(new com_jci_lds_dataInterface(adaptee, name));

}
std::shared_ptr<DBus::Signal<void(uint8_t, uint8_t)>> com_jci_lds_dataInterface::signal_GPSDiagnostics() {
  return m_signal_GPSDiagnostics;

}
void com_jci_lds_dataInterface::GPSDiagnostics(uint8_t dTCId, uint8_t dTCAction) {
  (*m_signal_GPSDiagnostics)(dTCId, dTCAction);

}
std::shared_ptr<DBus::Signal<void(std::string,
                                  int32_t,
                                  bool,
                                  bool,
                                  bool,
                                  bool)>> com_jci_lds_dataInterface::signal_OneTimeDRDiagnostics() {
  return m_signal_OneTimeDRDiagnostics;

}
void com_jci_lds_dataInterface::OneTimeDRDiagnostics(std::string dRUnitVersion,
                                                     int32_t antennaStatus,
                                                     bool gyroSelfTest,
                                                     bool accelSelfTest,
                                                     bool resetLearning,
                                                     bool saveLearning) {
  (*m_signal_OneTimeDRDiagnostics)(dRUnitVersion,
                                   antennaStatus,
                                   gyroSelfTest,
                                   accelSelfTest,
                                   resetLearning,
                                   saveLearning);

}
std::shared_ptr<DBus::Signal<void(int32_t,
                                  int32_t,
                                  bool,
                                  int32_t,
                                  int32_t,
                                  int32_t)>> com_jci_lds_dataInterface::signal_PeriodicDRDiagnostics() {
  return m_signal_PeriodicDRDiagnostics;

}
void com_jci_lds_dataInterface::PeriodicDRDiagnostics(int32_t dRUnitStatus,
                                                      int32_t speedPulse,
                                                      bool reverse,
                                                      int32_t dRUnitMode,
                                                      int32_t gyroStatus,
                                                      int32_t accelStatus) {
  (*m_signal_PeriodicDRDiagnostics)(dRUnitStatus, speedPulse, reverse, dRUnitMode, gyroStatus, accelStatus);

}
