#include "com_jci_vbs_navi_tmcProxy.h"

com_jci_vbs_navi_tmcProxy::com_jci_vbs_navi_tmcProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_NaviCompassVal = this->create_method<uint8_t(uint8_t)>("NaviCompassVal");
  m_method_NaviSignal = this->create_method<uint8_t(uint8_t)>("NaviSignal");
  m_method_SetHUD_Display_Msg2 = this->create_method<uint8_t(std::tuple<std::string, uint8_t>)>("SetHUD_Display_Msg2");
  m_signalproxy_ServiceListResponse = this->create_signal<void(std::tuple<uint8_t,
                                                                          std::vector<uint8_t>,
                                                                          std::vector<uint8_t>,
                                                                          std::vector<uint8_t>,
                                                                          std::vector<uint8_t>,
                                                                          std::vector<uint8_t>>)>("ServiceListResponse");
  m_signalproxy_ResponseToTMCSelection = this->create_signal<void(uint8_t,
                                                                  uint8_t,
                                                                  uint8_t,
                                                                  uint8_t,
                                                                  uint8_t,
                                                                  uint8_t,
                                                                  uint8_t)>("ResponseToTMCSelection");

}
std::shared_ptr<com_jci_vbs_navi_tmcProxy> com_jci_vbs_navi_tmcProxy::create(std::string name) {
  return std::shared_ptr<com_jci_vbs_navi_tmcProxy>(new com_jci_vbs_navi_tmcProxy(name));

}
uint8_t com_jci_vbs_navi_tmcProxy::NaviCompassVal(uint8_t compass) {
  return (*m_method_NaviCompassVal)(compass);

}
uint8_t com_jci_vbs_navi_tmcProxy::NaviSignal(uint8_t navi) {
  return (*m_method_NaviSignal)(navi);

}
uint8_t com_jci_vbs_navi_tmcProxy::SetHUD_Display_Msg2(std::tuple<std::string, uint8_t> guidancePointData) {
  return (*m_method_SetHUD_Display_Msg2)(guidancePointData);

}
std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                  std::vector<uint8_t>,
                                                  std::vector<uint8_t>,
                                                  std::vector<uint8_t>,
                                                  std::vector<uint8_t>,
                                                  std::vector<uint8_t>>)>> com_jci_vbs_navi_tmcProxy::signal_ServiceListResponse() {
  return m_signalproxy_ServiceListResponse;

}
std::shared_ptr<DBus::SignalProxy<void(uint8_t,
                                       uint8_t,
                                       uint8_t,
                                       uint8_t,
                                       uint8_t,
                                       uint8_t,
                                       uint8_t)>> com_jci_vbs_navi_tmcProxy::signal_ResponseToTMCSelection() {
  return m_signalproxy_ResponseToTMCSelection;

}
