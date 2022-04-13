#include "com_jci_tdsProxy.h"

com_jci_tdsProxy::com_jci_tdsProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_STM_Set_ProcessMode_async = this->create_method<int32_t(uint32_t)>("STM_Set_ProcessMode_async");
  m_method_STM_GetTMIFile =
      this->create_method < DBus::MultipleReturn < std::tuple < std::vector < std::tuple < int32_t, std::string>>>,
  int32_t > (int32_t) > ("STM_GetTMIFile");
  m_method_ARTEXP_HDStationExit_async = this->create_method<int32_t(double)>("ARTEXP_HDStationExit_async");
  m_method_ARTEXP_HDStationEnter_async = this->create_method<int32_t(double)>("ARTEXP_HDStationEnter_async");
  m_method_ARTEXP_HDSubStationExit_async = this->create_method<int32_t()>("ARTEXP_HDSubStationExit_async");
  m_method_ARTEXP_GetStationLogo_async = this->create_method<int32_t(uint32_t, double)>("ARTEXP_GetStationLogo_async");
  m_method_ARTEXP_GetAlbumArt_async =
      this->create_method<int32_t(uint32_t, double, uint32_t)>("ARTEXP_GetAlbumArt_async");
  m_method_ExecuteTestCase = this->create_method<int32_t(uint32_t)>("ExecuteTestCase");
  m_signalproxy_TMC8A = this->create_signal<void(uint16_t, uint16_t, uint16_t, uint16_t)>("TMC8A");
  m_signalproxy_STM_TrafficEvent = this->create_signal<void(uint32_t)>("STM_TrafficEvent");
  m_signalproxy_STM_StationId = this->create_signal<void(uint32_t)>("STM_StationId");
  m_signalproxy_STM_RemoveTmt = this->create_signal<void(uint32_t)>("STM_RemoveTmt");
  m_signalproxy_ARTEXP_StationLogo = this->create_signal<void(uint32_t, double, bool)>("ARTEXP_StationLogo");
  m_signalproxy_ARTEXP_AlbumArt = this->create_signal<void(uint32_t, double, uint32_t, bool)>("ARTEXP_AlbumArt");
  m_signalproxy_STM_TileElapseTimeUpdate = this->create_signal<void(uint32_t)>("STM_TileElapseTimeUpdate");

}
std::shared_ptr <com_jci_tdsProxy> com_jci_tdsProxy::create(std::string name) {
  return std::shared_ptr<com_jci_tdsProxy>(new com_jci_tdsProxy(name));

}
int32_t com_jci_tdsProxy::STM_Set_ProcessMode_async(uint32_t processMode) {
  return (*m_method_STM_Set_ProcessMode_async)(processMode);

}
DBus::MultipleReturn <std::tuple<std::vector < std::tuple < int32_t, std::string>>>,int32_t>
com_jci_tdsProxy::STM_GetTMIFile(int32_t
mapID ){
return (*m_method_STM_GetTMIFile)(mapID);

}
int32_t com_jci_tdsProxy::ARTEXP_HDStationExit_async(double oldFrequency) {
  return (*m_method_ARTEXP_HDStationExit_async)(oldFrequency);

}
int32_t com_jci_tdsProxy::ARTEXP_HDStationEnter_async(double newFrequency) {
  return (*m_method_ARTEXP_HDStationEnter_async)(newFrequency);

}
int32_t com_jci_tdsProxy::ARTEXP_HDSubStationExit_async() {
  return (*m_method_ARTEXP_HDSubStationExit_async)();

}
int32_t com_jci_tdsProxy::ARTEXP_GetStationLogo_async(uint32_t serviceNumber, double frequency) {
  return (*m_method_ARTEXP_GetStationLogo_async)(serviceNumber, frequency);

}
int32_t com_jci_tdsProxy::ARTEXP_GetAlbumArt_async(uint32_t serviceNumber, double frequency, uint32_t lotId) {
  return (*m_method_ARTEXP_GetAlbumArt_async)(serviceNumber, frequency, lotId);

}
int32_t com_jci_tdsProxy::ExecuteTestCase(uint32_t testCaseID) {
  return (*m_method_ExecuteTestCase)(testCaseID);

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t, uint16_t, uint16_t, uint16_t)>> com_jci_tdsProxy::signal_TMC8A() {
  return m_signalproxy_TMC8A;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_tdsProxy::signal_STM_TrafficEvent() {
  return m_signalproxy_STM_TrafficEvent;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_tdsProxy::signal_STM_StationId() {
  return m_signalproxy_STM_StationId;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_tdsProxy::signal_STM_RemoveTmt() {
  return m_signalproxy_STM_RemoveTmt;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, double, bool)>> com_jci_tdsProxy::signal_ARTEXP_StationLogo() {
  return m_signalproxy_ARTEXP_StationLogo;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, double, uint32_t, bool)>> com_jci_tdsProxy::signal_ARTEXP_AlbumArt() {
  return m_signalproxy_ARTEXP_AlbumArt;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_tdsProxy::signal_STM_TileElapseTimeUpdate() {
  return m_signalproxy_STM_TileElapseTimeUpdate;

}
