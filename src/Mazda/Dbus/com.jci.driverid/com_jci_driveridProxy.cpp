#include "com_jci_driveridProxy.h"

com_jci_driveridProxy::com_jci_driveridProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_Get_DriveridConfig = this->create_method<int32_t()>("Get_DriveridConfig");
  m_method_Set_DriveridSetting = this->create_method<int32_t(uint32_t)>("Set_DriveridSetting");
  m_method_GetDriverIdData = this->create_method<int32_t()>("GetDriverIdData");
  m_method_Get_DriverList = this->create_method<int32_t()>("Get_DriverList");
  m_method_Change_DriverId = this->create_method<int32_t(uint8_t)>("Change_DriverId");
  m_method_Change_DriverNickname =
      this->create_method<int32_t(std::tuple < std::vector < uint8_t >> )>("Change_DriverNickname");
  m_method_SynUp_Ack_Rcvd = this->create_method<int32_t()>("SynUp_Ack_Rcvd");
  m_signalproxy_EOLConfig = this->create_signal<void(uint16_t)>("EOLConfig");
  m_signalproxy_Setting = this->create_signal<void(bool)>("Setting");
  m_signalproxy_Curr_DriverData =
      this->create_signal<void(std::tuple < uint8_t, std::vector < uint8_t > , bool, uint8_t > )>("Curr_DriverData");
  m_signalproxy_Curr_DriverDataAsync = this->create_signal<void(std::tuple < uint8_t,
                                                                std::vector < uint8_t > ,
                                                                bool,
                                                                uint8_t > )>("Curr_DriverDataAsync");
  m_signalproxy_Driver_List = this->create_signal < void(std::tuple < std::vector < std::tuple < uint8_t,
                                                         std::vector < uint8_t > ,
                                                         bool,
                                                         uint8_t>>>)>("Driver_List");
  m_signalproxy_Duplicate_Nickname = this->create_signal<void(int32_t)>("Duplicate_Nickname");
  m_signalproxy_SpeedRest_Flg = this->create_signal<void(uint32_t)>("SpeedRest_Flg");
  m_signalproxy_ACC_OFF = this->create_signal<void(bool)>("ACC_OFF");

}
std::shared_ptr <com_jci_driveridProxy> com_jci_driveridProxy::create(std::string name) {
  return std::shared_ptr<com_jci_driveridProxy>(new com_jci_driveridProxy(name));

}
int32_t com_jci_driveridProxy::Get_DriveridConfig() {
  return (*m_method_Get_DriveridConfig)();

}
int32_t com_jci_driveridProxy::Set_DriveridSetting(uint32_t setting_type) {
  return (*m_method_Set_DriveridSetting)(setting_type);

}
int32_t com_jci_driveridProxy::GetDriverIdData() {
  return (*m_method_GetDriverIdData)();

}
int32_t com_jci_driveridProxy::Get_DriverList() {
  return (*m_method_Get_DriverList)();

}
int32_t com_jci_driveridProxy::Change_DriverId(uint8_t drv_id) {
  return (*m_method_Change_DriverId)(drv_id);

}
int32_t com_jci_driveridProxy::Change_DriverNickname(std::tuple <std::vector<uint8_t>> nickname) {
  return (*m_method_Change_DriverNickname)(nickname);

}
int32_t com_jci_driveridProxy::SynUp_Ack_Rcvd() {
  return (*m_method_SynUp_Ack_Rcvd)();

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t)>> com_jci_driveridProxy::signal_EOLConfig() {
  return m_signalproxy_EOLConfig;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_driveridProxy::signal_Setting() {
  return m_signalproxy_Setting;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        std::vector < uint8_t > ,
                                        bool,
                                        uint8_t > )>> com_jci_driveridProxy::signal_Curr_DriverData() {
  return m_signalproxy_Curr_DriverData;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        std::vector < uint8_t > ,
                                        bool,
                                        uint8_t > )>> com_jci_driveridProxy::signal_Curr_DriverDataAsync() {
  return m_signalproxy_Curr_DriverDataAsync;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < std::vector < std::tuple < uint8_t,
                                        std::vector < uint8_t > ,
                                        bool,
                                        uint8_t>>>)>>
com_jci_driveridProxy::signal_Driver_List() {
  return m_signalproxy_Driver_List;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_driveridProxy::signal_Duplicate_Nickname() {
  return m_signalproxy_Duplicate_Nickname;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_driveridProxy::signal_SpeedRest_Flg() {
  return m_signalproxy_SpeedRest_Flg;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_driveridProxy::signal_ACC_OFF() {
  return m_signalproxy_ACC_OFF;

}
