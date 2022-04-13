#include "com_jci_lds_dataProxy.h"

com_jci_lds_dataProxy::com_jci_lds_dataProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_GetPosition = this->create_method<DBus::MultipleReturn<int32_t,
                                                                  uint64_t,
                                                                  double,
                                                                  double,
                                                                  int32_t,
                                                                  double,
                                                                  double,
                                                                  double,
                                                                  double>()>("GetPosition");
  m_method_GetLastKnownPosition =
      this->create_method<DBus::MultipleReturn<uint64_t, double, double>()>("GetLastKnownPosition");
  m_method_GetGPSFirmwareVersion = this->create_method<std::string()>("GetGPSFirmwareVersion");
  m_method_GetSatelliteInfo = this->create_method<int32_t()>("GetSatelliteInfo");
  m_signalproxy_GPSDiagnostics = this->create_signal<void(uint8_t, uint8_t)>("GPSDiagnostics");
  m_signalproxy_OneTimeDRDiagnostics =
      this->create_signal<void(std::string, int32_t, bool, bool, bool, bool)>("OneTimeDRDiagnostics");
  m_signalproxy_PeriodicDRDiagnostics =
      this->create_signal<void(int32_t, int32_t, bool, int32_t, int32_t, int32_t)>("PeriodicDRDiagnostics");

}
std::shared_ptr<com_jci_lds_dataProxy> com_jci_lds_dataProxy::create(std::string name) {
  return std::shared_ptr<com_jci_lds_dataProxy>(new com_jci_lds_dataProxy(name));

}
DBus::MultipleReturn<int32_t,
                     uint64_t,
                     double,
                     double,
                     int32_t,
                     double,
                     double,
                     double,
                     double> com_jci_lds_dataProxy::GetPosition() {
  return (*m_method_GetPosition)();

}
DBus::MultipleReturn<uint64_t, double, double> com_jci_lds_dataProxy::GetLastKnownPosition() {
  return (*m_method_GetLastKnownPosition)();

}
std::string com_jci_lds_dataProxy::GetGPSFirmwareVersion() {
  return (*m_method_GetGPSFirmwareVersion)();

}
int32_t com_jci_lds_dataProxy::GetSatelliteInfo() {
  return (*m_method_GetSatelliteInfo)();

}
std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t)>> com_jci_lds_dataProxy::signal_GPSDiagnostics() {
  return m_signalproxy_GPSDiagnostics;

}
std::shared_ptr<DBus::SignalProxy<void(std::string,
                                       int32_t,
                                       bool,
                                       bool,
                                       bool,
                                       bool)>> com_jci_lds_dataProxy::signal_OneTimeDRDiagnostics() {
  return m_signalproxy_OneTimeDRDiagnostics;

}
std::shared_ptr<DBus::SignalProxy<void(int32_t,
                                       int32_t,
                                       bool,
                                       int32_t,
                                       int32_t,
                                       int32_t)>> com_jci_lds_dataProxy::signal_PeriodicDRDiagnostics() {
  return m_signalproxy_PeriodicDRDiagnostics;

}
