#include "com_jci_trafficProxy.h"

com_jci_trafficProxy::com_jci_trafficProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_SetNewMapUpdateEnable_async = this->create_method<int32_t(uint32_t)>("SetNewMapUpdateEnable_async");
  m_method_SetMapInFocus_async = this->create_method<int32_t(uint32_t)>("SetMapInFocus_async");
  m_method_GetGpsInfo_async = this->create_method<int32_t()>("GetGpsInfo_async");
  m_signalproxy_BGColorInfo = this->create_signal<void(uint32_t, uint32_t, uint32_t)>("BGColorInfo");
  m_signalproxy_NewTrafficMap = this->create_signal<void(uint32_t)>("NewTrafficMap");
  m_signalproxy_MapUpdate = this->create_signal
      < void(uint32_t, std::tuple < std::vector < std::tuple < uint32_t, std::string>>>)>("MapUpdate");
  m_signalproxy_GpsInfoUpdate = this->create_signal<void(std::tuple < int32_t, int32_t, uint32_t > )>("GpsInfoUpdate");
  m_signalproxy_LockedToStation = this->create_signal<void(uint32_t)>("LockedToStation");
  m_signalproxy_ApplicationStatus = this->create_signal<void(uint32_t)>("ApplicationStatus");
  m_signalproxy_LastTileUpdatedTime = this->create_signal<void(uint32_t)>("LastTileUpdatedTime");
  m_signalproxy_TestModeText = this->create_signal<void(std::string)>("TestModeText");
  m_signalproxy_VICSFrequencyChangeAck = this->create_signal<void(double, int32_t)>("VICSFrequencyChangeAck");

}
std::shared_ptr <com_jci_trafficProxy> com_jci_trafficProxy::create(std::string name) {
  return std::shared_ptr<com_jci_trafficProxy>(new com_jci_trafficProxy(name));

}
int32_t com_jci_trafficProxy::SetNewMapUpdateEnable_async(uint32_t enable) {
  return (*m_method_SetNewMapUpdateEnable_async)(enable);

}
int32_t com_jci_trafficProxy::SetMapInFocus_async(uint32_t focus) {
  return (*m_method_SetMapInFocus_async)(focus);

}
int32_t com_jci_trafficProxy::GetGpsInfo_async() {
  return (*m_method_GetGpsInfo_async)();

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, uint32_t, uint32_t)>> com_jci_trafficProxy::signal_BGColorInfo() {
  return m_signalproxy_BGColorInfo;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_trafficProxy::signal_NewTrafficMap() {
  return m_signalproxy_NewTrafficMap;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, std::tuple < std::vector < std::tuple < uint32_t, std::string>>>)>>
com_jci_trafficProxy::signal_MapUpdate() {
  return m_signalproxy_MapUpdate;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < int32_t,
                                        int32_t,
                                        uint32_t > )>> com_jci_trafficProxy::signal_GpsInfoUpdate() {
  return m_signalproxy_GpsInfoUpdate;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_trafficProxy::signal_LockedToStation() {
  return m_signalproxy_LockedToStation;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_trafficProxy::signal_ApplicationStatus() {
  return m_signalproxy_ApplicationStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_trafficProxy::signal_LastTileUpdatedTime() {
  return m_signalproxy_LastTileUpdatedTime;

}
std::shared_ptr <DBus::SignalProxy<void(std::string)>> com_jci_trafficProxy::signal_TestModeText() {
  return m_signalproxy_TestModeText;

}
std::shared_ptr <DBus::SignalProxy<void(double, int32_t)>> com_jci_trafficProxy::signal_VICSFrequencyChangeAck() {
  return m_signalproxy_VICSFrequencyChangeAck;

}
