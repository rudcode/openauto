#include "com_jci_dabProxy.h"

com_jci_dabProxy::com_jci_dabProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_Get_Dab_Mode_Status = this->create_method<int32_t()>("Get_Dab_Mode_Status");
  m_method_Get_Tuner_Mode_Status = this->create_method<int32_t()>("Get_Tuner_Mode_Status");
  m_method_Get_Install_Status = this->create_method<int32_t()>("Get_Install_Status");
  m_method_Get_Channel_Status = this->create_method<int32_t()>("Get_Channel_Status");
  m_method_Get_Signal_Strength_Status = this->create_method<int32_t()>("Get_Signal_Strength_Status");
  m_method_Get_TAU_List_Status = this->create_method<int32_t()>("Get_TAU_List_Status");
  m_method_Tuner_Mode_Change = this->create_method<int32_t(int32_t)>("Tuner_Mode_Change");
  m_method_Scan_Req = this->create_method<int32_t(int32_t)>("Scan_Req");
  m_method_Compo_Seek_Req = this->create_method<int32_t(int32_t)>("Compo_Seek_Req");
  m_method_Ens_Seek_Req = this->create_method<int32_t(int32_t)>("Ens_Seek_Req");
  m_method_Direct_Control_Req =
      this->create_method<int32_t(std::tuple < std::vector < uint8_t > , uint16_t, uint16_t, uint8_t > )>(
          "Direct_Control_Req");
  m_method_Update_TAU_List_Req = this->create_method<int32_t()>("Update_TAU_List_Req");
  m_method_Link_Setting_Change_Req =
      this->create_method<int32_t(std::tuple < int32_t, int32_t > )>("Link_Setting_Change_Req");
  m_method_Band_Setting_Change_Req = this->create_method<int32_t(int32_t)>("Band_Setting_Change_Req");
  m_method_TA_Setting_Change_Req = this->create_method<int32_t(int32_t)>("TA_Setting_Change_Req");
  m_method_Radio_Text_Setting_Change_Req = this->create_method<int32_t(int32_t)>("Radio_Text_Setting_Change_Req");
  m_method_Get_DAB_DAB_Setting_Req = this->create_method<int32_t()>("Get_DAB_DAB_Setting_Req");
  m_method_Get_DAB_FM_Setting_Req = this->create_method<int32_t()>("Get_DAB_FM_Setting_Req");
  m_method_Get_Band_Setting_Req = this->create_method<int32_t()>("Get_Band_Setting_Req");
  m_method_Get_TA_Setting_Req = this->create_method<int32_t()>("Get_TA_Setting_Req");
  m_method_Get_Radio_Text_Setting_Status = this->create_method<int32_t()>("Get_Radio_Text_Setting_Status");
  m_method_Get_TAU_Connection_Status = this->create_method<int32_t()>("Get_TAU_Connection_Status");
  m_method_Fav_Seek_Req =
      this->create_method<int32_t(int32_t, std::tuple < std::vector < uint8_t > , uint16_t, uint16_t, uint8_t > )>(
          "Fav_Seek_Req");
  m_method_Factory_Reset_Setting = this->create_method<int32_t()>("Factory_Reset_Setting");
  m_signalproxy_TAU_Connection_Status = this->create_signal<void(int32_t)>("TAU_Connection_Status");
  m_signalproxy_Signal_Strength_Status = this->create_signal<void(int32_t)>("Signal_Strength_Status");
  m_signalproxy_Link_Setting_Status =
      this->create_signal<void(std::tuple < int32_t, int32_t > )>("Link_Setting_Status");
  m_signalproxy_Band_Setting_Status = this->create_signal<void(int32_t)>("Band_Setting_Status");
  m_signalproxy_TA_Setting_Status = this->create_signal<void(int32_t)>("TA_Setting_Status");
  m_signalproxy_Radio_Text_Setting_Status = this->create_signal<void(int32_t)>("Radio_Text_Setting_Status");
  m_signalproxy_Full_List_Update_Status = this->create_signal<void(int32_t)>("Full_List_Update_Status");
  m_signalproxy_Tuner_Mode_Status = this->create_signal<void(int32_t)>("Tuner_Mode_Status");
  m_signalproxy_Dab_Mode_Status = this->create_signal<void(std::tuple < int32_t, int32_t > )>("Dab_Mode_Status");
  m_signalproxy_TAU_List_Status = this->create_signal<void(int32_t)>("TAU_List_Status");
  m_signalproxy_Channel_Status = this->create_signal<void(std::tuple < std::vector < uint8_t > ,
                                                          uint16_t,
                                                          uint16_t,
                                                          uint8_t > )>("Channel_Status");
  m_signalproxy_Info_Change_Status =
      this->create_signal<void(std::tuple < bool, bool, bool, bool, int32_t, std::vector < uint8_t >> )>(
          "Info_Change_Status");
  m_signalproxy_Clear_Label_Field_Status =
      this->create_signal<void(std::tuple < bool, bool, bool, bool > )>("Clear_Label_Field_Status");
  m_signalproxy_Install_Status = this->create_signal<void(int32_t)>("Install_Status");
  m_signalproxy_Ens_List_Status = this->create_signal<void(bool)>("Ens_List_Status");
  m_signalproxy_Compo_List_Status = this->create_signal<void(std::tuple < uint16_t, bool > )>("Compo_List_Status");
  m_signalproxy_New_List_Available = this->create_signal<void()>("New_List_Available");

}
std::shared_ptr <com_jci_dabProxy> com_jci_dabProxy::create(std::string name) {
  return std::shared_ptr<com_jci_dabProxy>(new com_jci_dabProxy(name));

}
int32_t com_jci_dabProxy::Get_Dab_Mode_Status() {
  return (*m_method_Get_Dab_Mode_Status)();

}
int32_t com_jci_dabProxy::Get_Tuner_Mode_Status() {
  return (*m_method_Get_Tuner_Mode_Status)();

}
int32_t com_jci_dabProxy::Get_Install_Status() {
  return (*m_method_Get_Install_Status)();

}
int32_t com_jci_dabProxy::Get_Channel_Status() {
  return (*m_method_Get_Channel_Status)();

}
int32_t com_jci_dabProxy::Get_Signal_Strength_Status() {
  return (*m_method_Get_Signal_Strength_Status)();

}
int32_t com_jci_dabProxy::Get_TAU_List_Status() {
  return (*m_method_Get_TAU_List_Status)();

}
int32_t com_jci_dabProxy::Tuner_Mode_Change(int32_t tuner_mode) {
  return (*m_method_Tuner_Mode_Change)(tuner_mode);

}
int32_t com_jci_dabProxy::Scan_Req(int32_t request) {
  return (*m_method_Scan_Req)(request);

}
int32_t com_jci_dabProxy::Compo_Seek_Req(int32_t request) {
  return (*m_method_Compo_Seek_Req)(request);

}
int32_t com_jci_dabProxy::Ens_Seek_Req(int32_t request) {
  return (*m_method_Ens_Seek_Req)(request);

}
int32_t com_jci_dabProxy::Direct_Control_Req(std::tuple <std::vector<uint8_t>, uint16_t, uint16_t, uint8_t> channel_info) {
  return (*m_method_Direct_Control_Req)(channel_info);

}
int32_t com_jci_dabProxy::Update_TAU_List_Req() {
  return (*m_method_Update_TAU_List_Req)();

}
int32_t com_jci_dabProxy::Link_Setting_Change_Req(std::tuple <int32_t, int32_t> link_setting) {
  return (*m_method_Link_Setting_Change_Req)(link_setting);

}
int32_t com_jci_dabProxy::Band_Setting_Change_Req(int32_t band_mode) {
  return (*m_method_Band_Setting_Change_Req)(band_mode);

}
int32_t com_jci_dabProxy::TA_Setting_Change_Req(int32_t ta_mode) {
  return (*m_method_TA_Setting_Change_Req)(ta_mode);

}
int32_t com_jci_dabProxy::Radio_Text_Setting_Change_Req(int32_t radio_text_mode) {
  return (*m_method_Radio_Text_Setting_Change_Req)(radio_text_mode);

}
int32_t com_jci_dabProxy::Get_DAB_DAB_Setting_Req() {
  return (*m_method_Get_DAB_DAB_Setting_Req)();

}
int32_t com_jci_dabProxy::Get_DAB_FM_Setting_Req() {
  return (*m_method_Get_DAB_FM_Setting_Req)();

}
int32_t com_jci_dabProxy::Get_Band_Setting_Req() {
  return (*m_method_Get_Band_Setting_Req)();

}
int32_t com_jci_dabProxy::Get_TA_Setting_Req() {
  return (*m_method_Get_TA_Setting_Req)();

}
int32_t com_jci_dabProxy::Get_Radio_Text_Setting_Status() {
  return (*m_method_Get_Radio_Text_Setting_Status)();

}
int32_t com_jci_dabProxy::Get_TAU_Connection_Status() {
  return (*m_method_Get_TAU_Connection_Status)();

}
int32_t com_jci_dabProxy::Fav_Seek_Req(int32_t fav_seek_dir,
                                       std::tuple <std::vector<uint8_t>, uint16_t, uint16_t, uint8_t> channel_info) {
  return (*m_method_Fav_Seek_Req)(fav_seek_dir, channel_info);

}
int32_t com_jci_dabProxy::Factory_Reset_Setting() {
  return (*m_method_Factory_Reset_Setting)();

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_dabProxy::signal_TAU_Connection_Status() {
  return m_signalproxy_TAU_Connection_Status;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_dabProxy::signal_Signal_Strength_Status() {
  return m_signalproxy_Signal_Strength_Status;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < int32_t,
                                        int32_t > )>> com_jci_dabProxy::signal_Link_Setting_Status() {
  return m_signalproxy_Link_Setting_Status;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_dabProxy::signal_Band_Setting_Status() {
  return m_signalproxy_Band_Setting_Status;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_dabProxy::signal_TA_Setting_Status() {
  return m_signalproxy_TA_Setting_Status;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_dabProxy::signal_Radio_Text_Setting_Status() {
  return m_signalproxy_Radio_Text_Setting_Status;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_dabProxy::signal_Full_List_Update_Status() {
  return m_signalproxy_Full_List_Update_Status;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_dabProxy::signal_Tuner_Mode_Status() {
  return m_signalproxy_Tuner_Mode_Status;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < int32_t, int32_t > )>> com_jci_dabProxy::signal_Dab_Mode_Status() {
  return m_signalproxy_Dab_Mode_Status;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_dabProxy::signal_TAU_List_Status() {
  return m_signalproxy_TAU_List_Status;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < std::vector < uint8_t > ,
                                        uint16_t,
                                        uint16_t,
                                        uint8_t > )>> com_jci_dabProxy::signal_Channel_Status() {
  return m_signalproxy_Channel_Status;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < bool,
                                        bool,
                                        bool,
                                        bool,
                                        int32_t,
                                        std::vector < uint8_t >> )>> com_jci_dabProxy::signal_Info_Change_Status() {
  return m_signalproxy_Info_Change_Status;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < bool,
                                        bool,
                                        bool,
                                        bool > )>> com_jci_dabProxy::signal_Clear_Label_Field_Status() {
  return m_signalproxy_Clear_Label_Field_Status;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_dabProxy::signal_Install_Status() {
  return m_signalproxy_Install_Status;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_dabProxy::signal_Ens_List_Status() {
  return m_signalproxy_Ens_List_Status;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint16_t, bool > )>> com_jci_dabProxy::signal_Compo_List_Status() {
  return m_signalproxy_Compo_List_Status;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_dabProxy::signal_New_List_Available() {
  return m_signalproxy_New_List_Available;

}
