#include "com_jci_lds_controlProxy.h"

com_jci_lds_controlProxy::com_jci_lds_controlProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_ReadControl = this->create_method<void(int32_t)>("ReadControl");
  m_method_DRTestScreenRequest = this->create_method<void(int32_t)>("DRTestScreenRequest");
  m_method_GetDRUnitStatus_sync =
      this->create_method<DBus::MultipleReturn<bool, bool, int32_t>()>("GetDRUnitStatus_sync");
  m_method_GetLastKnownPosition_sync = this->create_method<DBus::MultipleReturn<int32_t,
                                                                                uint64_t,
                                                                                double,
                                                                                double,
                                                                                int32_t,
                                                                                double,
                                                                                double,
                                                                                double,
                                                                                double,
                                                                                int32_t>()>("GetLastKnownPosition_sync");
  m_method_SetLastKnownPosition_sync =
      this->create_method<int32_t(int32_t, uint64_t, double, double, int32_t, double, double, double, double)>(
          "SetLastKnownPosition_sync");
  m_method_DRReloadRequest = this->create_method<void()>("DRReloadRequest");
  m_signalproxy_ReadStatus = this->create_signal<void(int32_t, int32_t)>("ReadStatus");

}
std::shared_ptr<com_jci_lds_controlProxy> com_jci_lds_controlProxy::create(std::string name) {
  return std::shared_ptr<com_jci_lds_controlProxy>(new com_jci_lds_controlProxy(name));

}
void com_jci_lds_controlProxy::ReadControl(int32_t command) {
  (*m_method_ReadControl)(command);

}
void com_jci_lds_controlProxy::DRTestScreenRequest(int32_t dRUnitTestScreenRequest) {
  (*m_method_DRTestScreenRequest)(dRUnitTestScreenRequest);

}
DBus::MultipleReturn<bool, bool, int32_t> com_jci_lds_controlProxy::GetDRUnitStatus_sync() {
  return (*m_method_GetDRUnitStatus_sync)();

}
DBus::MultipleReturn<int32_t,
                     uint64_t,
                     double,
                     double,
                     int32_t,
                     double,
                     double,
                     double,
                     double,
                     int32_t> com_jci_lds_controlProxy::GetLastKnownPosition_sync() {
  return (*m_method_GetLastKnownPosition_sync)();

}
int32_t com_jci_lds_controlProxy::SetLastKnownPosition_sync(int32_t positionAccuracy,
                                                            uint64_t uTCtime,
                                                            double latitude,
                                                            double longitude,
                                                            int32_t altitude,
                                                            double heading,
                                                            double velocity,
                                                            double horizontalAccuracy,
                                                            double verticalAccuracy) {
  return (*m_method_SetLastKnownPosition_sync)(positionAccuracy,
                                               uTCtime,
                                               latitude,
                                               longitude,
                                               altitude,
                                               heading,
                                               velocity,
                                               horizontalAccuracy,
                                               verticalAccuracy);

}
void com_jci_lds_controlProxy::DRReloadRequest() {
  (*m_method_DRReloadRequest)();

}
std::shared_ptr<DBus::SignalProxy<void(int32_t, int32_t)>> com_jci_lds_controlProxy::signal_ReadStatus() {
  return m_signalproxy_ReadStatus;

}
