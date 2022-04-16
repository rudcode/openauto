#include "com_jci_vbs_naviInterface.h"

com_jci_vbs_naviInterface::com_jci_vbs_naviInterface(com_jci_vbs_navi *adaptee, std::string name)
    : DBus::Interface(name) {
  this->create_method<uint8_t()>("GetFuelType", sigc::mem_fun(*adaptee, &com_jci_vbs_navi::GetFuelType));
  this->create_method<uint8_t()>("GetHUDStatus", sigc::mem_fun(*adaptee, &com_jci_vbs_navi::GetHUDStatus));
  this->create_method<uint8_t()>("GetTSRStatus", sigc::mem_fun(*adaptee, &com_jci_vbs_navi::GetTSRStatus));
  this->create_method<uint8_t()>("GetTSRMode", sigc::mem_fun(*adaptee, &com_jci_vbs_navi::GetTSRMode));
  this->create_method<uint8_t(uint8_t)>("TMCServiceListReq",
                                        sigc::mem_fun(*adaptee, &com_jci_vbs_navi::TMCServiceListReq));
  this->create_method<uint8_t(std::tuple<uint8_t, uint8_t, uint8_t, uint8_t, uint8_t>)>("TMCSelectReq",
                                                                                        sigc::mem_fun(*adaptee,
                                                                                                      &com_jci_vbs_navi::TMCSelectReq));
  this->create_method<uint8_t(std::tuple<uint32_t, uint16_t, uint8_t, uint16_t, uint8_t, uint8_t>)>(
      "SetHUDDisplayMsgReq",
      sigc::mem_fun(*adaptee, &com_jci_vbs_navi::SetHUDDisplayMsgReq));
  this->create_method<uint8_t(std::tuple<std::vector<uint8_t>>)>("SetRecommLaneReq",
                                                                 sigc::mem_fun(*adaptee,
                                                                               &com_jci_vbs_navi::SetRecommLaneReq));
  this->create_method<uint8_t(std::tuple<uint8_t, bool, bool, uint8_t>)>("SetTSRNavigationSignal",
                                                                         sigc::mem_fun(*adaptee,
                                                                                       &com_jci_vbs_navi::SetTSRNavigationSignal));
  this->create_method<std::string()>("GetVINData", sigc::mem_fun(*adaptee, &com_jci_vbs_navi::GetVINData));
  m_signal_FuelTypeResp = create_signal<void(uint8_t)>("FuelTypeResp");
  m_signal_HUDResp = create_signal<void(uint8_t)>("HUDResp");
  m_signal_TSRResp = create_signal<void(uint8_t)>("TSRResp");
  m_signal_GccConfigMgmtResp = create_signal<void(std::tuple<std::vector<uint8_t>>)>("GccConfigMgmtResp");
  m_signal_TSRFeatureMode = create_signal<void(uint8_t)>("TSRFeatureMode");

}
std::shared_ptr<com_jci_vbs_naviInterface> com_jci_vbs_naviInterface::create(com_jci_vbs_navi *adaptee,
                                                                             std::string name) {
  return std::shared_ptr<com_jci_vbs_naviInterface>(new com_jci_vbs_naviInterface(adaptee, name));

}
std::shared_ptr<DBus::Signal<void(uint8_t)>> com_jci_vbs_naviInterface::signal_FuelTypeResp() {
  return m_signal_FuelTypeResp;

}
void com_jci_vbs_naviInterface::FuelTypeResp(uint8_t fuelType) {
  (*m_signal_FuelTypeResp)(fuelType);

}
std::shared_ptr<DBus::Signal<void(uint8_t)>> com_jci_vbs_naviInterface::signal_HUDResp() {
  return m_signal_HUDResp;

}
void com_jci_vbs_naviInterface::HUDResp(uint8_t hudStatus) {
  (*m_signal_HUDResp)(hudStatus);

}
std::shared_ptr<DBus::Signal<void(uint8_t)>> com_jci_vbs_naviInterface::signal_TSRResp() {
  return m_signal_TSRResp;

}
void com_jci_vbs_naviInterface::TSRResp(uint8_t tsrStatus) {
  (*m_signal_TSRResp)(tsrStatus);

}
std::shared_ptr<DBus::Signal<void(std::tuple<std::vector<uint8_t>>)>> com_jci_vbs_naviInterface::signal_GccConfigMgmtResp() {
  return m_signal_GccConfigMgmtResp;

}
void com_jci_vbs_naviInterface::GccConfigMgmtResp(std::tuple<std::vector<uint8_t>> vin_Character) {
  (*m_signal_GccConfigMgmtResp)(vin_Character);

}
std::shared_ptr<DBus::Signal<void(uint8_t)>> com_jci_vbs_naviInterface::signal_TSRFeatureMode() {
  return m_signal_TSRFeatureMode;

}
void com_jci_vbs_naviInterface::TSRFeatureMode(uint8_t tsrMode) {
  (*m_signal_TSRFeatureMode)(tsrMode);

}
