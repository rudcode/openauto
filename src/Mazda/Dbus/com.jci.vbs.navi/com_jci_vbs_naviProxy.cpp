#include "com_jci_vbs_naviProxy.h"

com_jci_vbs_naviProxy::com_jci_vbs_naviProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_GetFuelType = this->create_method<uint8_t()>("GetFuelType");
  m_method_GetHUDStatus = this->create_method<uint8_t()>("GetHUDStatus");
  m_method_GetTSRStatus = this->create_method<uint8_t()>("GetTSRStatus");
  m_method_GetTSRMode = this->create_method<uint8_t()>("GetTSRMode");
  m_method_TMCServiceListReq = this->create_method<uint8_t(uint8_t)>("TMCServiceListReq");
  m_method_TMCSelectReq =
      this->create_method<uint8_t(std::tuple<uint8_t, uint8_t, uint8_t, uint8_t, uint8_t>)>("TMCSelectReq");
  m_method_SetHUDDisplayMsgReq =
      this->create_method<uint8_t(std::tuple<uint32_t, uint16_t, uint8_t, uint16_t, uint8_t, uint8_t>)>(
          "SetHUDDisplayMsgReq");
  m_method_SetRecommLaneReq = this->create_method<uint8_t(std::tuple<std::vector<uint8_t>>)>("SetRecommLaneReq");
  m_method_SetTSRNavigationSignal =
      this->create_method<uint8_t(std::tuple<uint8_t, bool, bool, uint8_t>)>("SetTSRNavigationSignal");
  m_method_GetVINData = this->create_method<std::string()>("GetVINData");
  m_signalproxy_FuelTypeResp = this->create_signal<void(uint8_t)>("FuelTypeResp");
  m_signalproxy_HUDResp = this->create_signal<void(uint8_t)>("HUDResp");
  m_signalproxy_TSRResp = this->create_signal<void(uint8_t)>("TSRResp");
  m_signalproxy_GccConfigMgmtResp = this->create_signal<void(std::tuple<std::vector<uint8_t>>)>("GccConfigMgmtResp");
  m_signalproxy_TSRFeatureMode = this->create_signal<void(uint8_t)>("TSRFeatureMode");

}
std::shared_ptr<com_jci_vbs_naviProxy> com_jci_vbs_naviProxy::create(std::string name) {
  return std::shared_ptr<com_jci_vbs_naviProxy>(new com_jci_vbs_naviProxy(name));

}
uint8_t com_jci_vbs_naviProxy::GetFuelType() {
  return (*m_method_GetFuelType)();

}
uint8_t com_jci_vbs_naviProxy::GetHUDStatus() {
  return (*m_method_GetHUDStatus)();

}
uint8_t com_jci_vbs_naviProxy::GetTSRStatus() {
  return (*m_method_GetTSRStatus)();

}
uint8_t com_jci_vbs_naviProxy::GetTSRMode() {
  return (*m_method_GetTSRMode)();

}
uint8_t com_jci_vbs_naviProxy::TMCServiceListReq(uint8_t tmcSrvceLstReq) {
  return (*m_method_TMCServiceListReq)(tmcSrvceLstReq);

}
uint8_t com_jci_vbs_naviProxy::TMCSelectReq(std::tuple<uint8_t, uint8_t, uint8_t, uint8_t, uint8_t> tmcSelectReq) {
  return (*m_method_TMCSelectReq)(tmcSelectReq);

}
uint8_t com_jci_vbs_naviProxy::SetHUDDisplayMsgReq(std::tuple<uint32_t,
                                                              uint16_t,
                                                              uint8_t,
                                                              uint16_t,
                                                              uint8_t,
                                                              uint8_t> hudDisplayMsg) {
  return (*m_method_SetHUDDisplayMsgReq)(hudDisplayMsg);

}
uint8_t com_jci_vbs_naviProxy::SetRecommLaneReq(std::tuple<std::vector<uint8_t>> hudRecommLaneInfo) {
  return (*m_method_SetRecommLaneReq)(hudRecommLaneInfo);

}
uint8_t com_jci_vbs_naviProxy::SetTSRNavigationSignal(std::tuple<uint8_t, bool, bool, uint8_t> tsrNavigation) {
  return (*m_method_SetTSRNavigationSignal)(tsrNavigation);

}
std::string com_jci_vbs_naviProxy::GetVINData() {
  return (*m_method_GetVINData)();

}
std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_naviProxy::signal_FuelTypeResp() {
  return m_signalproxy_FuelTypeResp;

}
std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_naviProxy::signal_HUDResp() {
  return m_signalproxy_HUDResp;

}
std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_naviProxy::signal_TSRResp() {
  return m_signalproxy_TSRResp;

}
std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> com_jci_vbs_naviProxy::signal_GccConfigMgmtResp() {
  return m_signalproxy_GccConfigMgmtResp;

}
std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_naviProxy::signal_TSRFeatureMode() {
  return m_signalproxy_TSRFeatureMode;

}
