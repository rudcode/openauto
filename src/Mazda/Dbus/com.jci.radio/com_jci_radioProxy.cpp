#include "com_jci_radioProxy.h"

com_jci_radioProxy::com_jci_radioProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_Mode_Req = this->create_method<int32_t(int32_t, int32_t)>("Mode_Req");
  m_method_Japan_Region_specific_Tau_type_info_Req =
      this->create_method<int32_t()>("Japan_Region_specific_Tau_type_info_Req");
  m_method_Tune_Req = this->create_method<int32_t(int32_t, int32_t)>("Tune_Req");
  m_method_Scan_Req = this->create_method<int32_t(int32_t)>("Scan_Req");
  m_method_Seek_Req = this->create_method<int32_t(int32_t, int32_t, bool)>("Seek_Req");
  m_method_ForceSeek_Req = this->create_method<int32_t(int32_t, int32_t)>("ForceSeek_Req");
  m_method_Tune_Direct_Req = this->create_method<int32_t(std::tuple < double, uint16_t, int32_t > )>("Tune_Direct_Req");
  m_method_Favorite_Mode_Req =
      this->create_method<int32_t(int32_t, int32_t, std::tuple < double, uint16_t, int32_t > )>("Favorite_Mode_Req");
  m_method_Station_List_Req = this->create_method<int32_t(int32_t)>("Station_List_Req");
  m_method_Auto_M_Req = this->create_method<int32_t(int32_t)>("Auto_M_Req");
  m_method_Area_Preset_Req = this->create_method<int32_t()>("Area_Preset_Req");
  m_method_Get_HDsetting_Req = this->create_method<int32_t()>("Get_HDsetting_Req");
  m_method_Get_TAsetting_Req = this->create_method<int32_t()>("Get_TAsetting_Req");
  m_method_Get_AFsetting_Req = this->create_method<int32_t()>("Get_AFsetting_Req");
  m_method_Get_RegionLockSetting_Req = this->create_method<int32_t()>("Get_RegionLockSetting_Req");
  m_method_Get_HARfreqSetting_Req = this->create_method<int32_t()>("Get_HARfreqSetting_Req");
  m_method_Get_CurrentGenre_Req = this->create_method<int32_t()>("Get_CurrentGenre_Req");
  m_method_Pty_Req = this->create_method<int32_t(int32_t)>("Pty_Req");
  m_method_Setting_Change_Req = this->create_method<int32_t(int32_t, int32_t)>("Setting_Change_Req");
  m_method_HD_ChUp_Req = this->create_method<int32_t(int32_t)>("HD_ChUp_Req");
  m_method_HAR_Freq_change = this->create_method<int32_t(int32_t)>("HAR_Freq_change");
  m_method_Cancel_Traffic_alert = this->create_method<int32_t()>("Cancel_Traffic_alert");
  m_method_Get_TAU_Connection_status = this->create_method<int32_t()>("Get_TAU_Connection_status");
  m_method_Fav_Seek_Req = this->create_method<int32_t(int32_t, double)>("Fav_Seek_Req");
  m_method_Get_Tuner_status = this->create_method<int32_t()>("Get_Tuner_status");
  m_method_Get_HDTuner_status = this->create_method<int32_t()>("Get_HDTuner_status");
  m_method_Get_Mode_status = this->create_method<int32_t()>("Get_Mode_status");
  m_method_Region_specific_info_Req = this->create_method<int32_t()>("Region_specific_info_Req");
  m_method_Get_Bose_Status = this->create_method<uint8_t()>("Get_Bose_Status");
  m_method_Factory_Reset_Setting = this->create_method<int32_t()>("Factory_Reset_Setting");
  m_signalproxy_Bose_Status = this->create_signal<void(uint8_t)>("Bose_Status");
  m_signalproxy_TAU_Connection_status = this->create_signal<void(int32_t)>("TAU_Connection_status");
  m_signalproxy_Tuner_mode_status = this->create_signal<void(std::tuple < int32_t, int32_t > )>("Tuner_mode_status");
  m_signalproxy_Tuner_status = this->create_signal<void(std::tuple < int32_t,
                                                        int32_t,
                                                        double,
                                                        std::vector < uint8_t > ,
                                                        int32_t,
                                                        std::vector < uint8_t > ,
                                                        std::vector < uint8_t >> )>("Tuner_status");
  m_signalproxy_Station_list_status = this->create_signal<void(int32_t)>("Station_list_status");
  m_signalproxy_Auto_M_status = this->create_signal<void(int32_t)>("Auto_M_status");
  m_signalproxy_Area_Preset_status = this->create_signal<void(int32_t)>("Area_Preset_status");
  m_signalproxy_HD_setting_status = this->create_signal<void(int32_t)>("HD_setting_status");
  m_signalproxy_TA_setting_status = this->create_signal<void(int32_t)>("TA_setting_status");
  m_signalproxy_HAR_setting_status = this->create_signal<void(int32_t)>("HAR_setting_status");
  m_signalproxy_AF_setting_status = this->create_signal<void(int32_t)>("AF_setting_status");
  m_signalproxy_RegionLock_setting_status = this->create_signal<void(int32_t)>("RegionLock_setting_status");
  m_signalproxy_Current_genre_status = this->create_signal<void(int32_t)>("Current_genre_status");
  m_signalproxy_Metadata_status = this->create_signal<void(int32_t)>("Metadata_status");
  m_signalproxy_Setting_status = this->create_signal<void(int32_t, int32_t)>("Setting_status");
  m_signalproxy_Pty_response = this->create_signal<void(int32_t, int32_t)>("Pty_response");
  m_signalproxy_HD_tuner_status = this->create_signal<void(Invalid)>("HD_tuner_status");
  m_signalproxy_HAR_status = this->create_signal<void(std::tuple < int32_t, int32_t > )>("HAR_status");
  m_signalproxy_Traffic_alert = this->create_signal<void(int32_t)>("Traffic_alert");
  m_signalproxy_Metadata_Artisticinfo = this->create_signal<void(int32_t)>("Metadata_Artisticinfo");
  m_signalproxy_Metadata_change_notification = this->create_signal<void(std::tuple < bool,
                                                                        bool,
                                                                        bool,
                                                                        bool,
                                                                        bool,
                                                                        bool,
                                                                        bool > )>("Metadata_change_notification");
  m_signalproxy_Japan_Region_specific_notification =
      this->create_signal<void(int32_t)>("Japan_Region_specific_notification");
  m_signalproxy_Region_specific_notification = this->create_signal<void(int32_t)>("Region_specific_notification");

}
std::shared_ptr <com_jci_radioProxy> com_jci_radioProxy::create(std::string name) {
  return std::shared_ptr<com_jci_radioProxy>(new com_jci_radioProxy(name));

}
int32_t com_jci_radioProxy::Mode_Req(int32_t mode, int32_t band) {
  return (*m_method_Mode_Req)(mode, band);

}
int32_t com_jci_radioProxy::Japan_Region_specific_Tau_type_info_Req() {
  return (*m_method_Japan_Region_specific_Tau_type_info_Req)();

}
int32_t com_jci_radioProxy::Tune_Req(int32_t direction, int32_t steps) {
  return (*m_method_Tune_Req)(direction, steps);

}
int32_t com_jci_radioProxy::Scan_Req(int32_t request) {
  return (*m_method_Scan_Req)(request);

}
int32_t com_jci_radioProxy::Seek_Req(int32_t request, int32_t direction, bool genreseek_screen) {
  return (*m_method_Seek_Req)(request, direction, genreseek_screen);

}
int32_t com_jci_radioProxy::ForceSeek_Req(int32_t forceSeek_Type, int32_t direction) {
  return (*m_method_ForceSeek_Req)(forceSeek_Type, direction);

}
int32_t com_jci_radioProxy::Tune_Direct_Req(std::tuple<double, uint16_t, int32_t> tune_direct) {
  return (*m_method_Tune_Direct_Req)(tune_direct);

}
int32_t com_jci_radioProxy::Favorite_Mode_Req(int32_t mode,
                                              int32_t band,
                                              std::tuple<double, uint16_t, int32_t> tune_direct) {
  return (*m_method_Favorite_Mode_Req)(mode, band, tune_direct);

}
int32_t com_jci_radioProxy::Station_List_Req(int32_t list_req_type) {
  return (*m_method_Station_List_Req)(list_req_type);

}
int32_t com_jci_radioProxy::Auto_M_Req(int32_t auto_M_req_type) {
  return (*m_method_Auto_M_Req)(auto_M_req_type);

}
int32_t com_jci_radioProxy::Area_Preset_Req() {
  return (*m_method_Area_Preset_Req)();

}
int32_t com_jci_radioProxy::Get_HDsetting_Req() {
  return (*m_method_Get_HDsetting_Req)();

}
int32_t com_jci_radioProxy::Get_TAsetting_Req() {
  return (*m_method_Get_TAsetting_Req)();

}
int32_t com_jci_radioProxy::Get_AFsetting_Req() {
  return (*m_method_Get_AFsetting_Req)();

}
int32_t com_jci_radioProxy::Get_RegionLockSetting_Req() {
  return (*m_method_Get_RegionLockSetting_Req)();

}
int32_t com_jci_radioProxy::Get_HARfreqSetting_Req() {
  return (*m_method_Get_HARfreqSetting_Req)();

}
int32_t com_jci_radioProxy::Get_CurrentGenre_Req() {
  return (*m_method_Get_CurrentGenre_Req)();

}
int32_t com_jci_radioProxy::Pty_Req(int32_t pty_req_type) {
  return (*m_method_Pty_Req)(pty_req_type);

}
int32_t com_jci_radioProxy::Setting_Change_Req(int32_t setting_type, int32_t setting_mode) {
  return (*m_method_Setting_Change_Req)(setting_type, setting_mode);

}
int32_t com_jci_radioProxy::HD_ChUp_Req(int32_t hd_ChUp_req) {
  return (*m_method_HD_ChUp_Req)(hd_ChUp_req);

}
int32_t com_jci_radioProxy::HAR_Freq_change(int32_t frequency) {
  return (*m_method_HAR_Freq_change)(frequency);

}
int32_t com_jci_radioProxy::Cancel_Traffic_alert() {
  return (*m_method_Cancel_Traffic_alert)();

}
int32_t com_jci_radioProxy::Get_TAU_Connection_status() {
  return (*m_method_Get_TAU_Connection_status)();

}
int32_t com_jci_radioProxy::Fav_Seek_Req(int32_t fav_seek_dir, double current_freq) {
  return (*m_method_Fav_Seek_Req)(fav_seek_dir, current_freq);

}
int32_t com_jci_radioProxy::Get_Tuner_status() {
  return (*m_method_Get_Tuner_status)();

}
int32_t com_jci_radioProxy::Get_HDTuner_status() {
  return (*m_method_Get_HDTuner_status)();

}
int32_t com_jci_radioProxy::Get_Mode_status() {
  return (*m_method_Get_Mode_status)();

}
int32_t com_jci_radioProxy::Region_specific_info_Req() {
  return (*m_method_Region_specific_info_Req)();

}
uint8_t com_jci_radioProxy::Get_Bose_Status() {
  return (*m_method_Get_Bose_Status)();

}
int32_t com_jci_radioProxy::Factory_Reset_Setting() {
  return (*m_method_Factory_Reset_Setting)();

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_radioProxy::signal_Bose_Status() {
  return m_signalproxy_Bose_Status;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_radioProxy::signal_TAU_Connection_status() {
  return m_signalproxy_TAU_Connection_status;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < int32_t,
                                        int32_t > )>> com_jci_radioProxy::signal_Tuner_mode_status() {
  return m_signalproxy_Tuner_mode_status;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < int32_t,
                                        int32_t,
                                        double,
                                        std::vector < uint8_t > ,
                                        int32_t,
                                        std::vector < uint8_t > ,
                                        std::vector < uint8_t >> )>> com_jci_radioProxy::signal_Tuner_status() {
  return m_signalproxy_Tuner_status;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_radioProxy::signal_Station_list_status() {
  return m_signalproxy_Station_list_status;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_radioProxy::signal_Auto_M_status() {
  return m_signalproxy_Auto_M_status;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_radioProxy::signal_Area_Preset_status() {
  return m_signalproxy_Area_Preset_status;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_radioProxy::signal_HD_setting_status() {
  return m_signalproxy_HD_setting_status;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_radioProxy::signal_TA_setting_status() {
  return m_signalproxy_TA_setting_status;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_radioProxy::signal_HAR_setting_status() {
  return m_signalproxy_HAR_setting_status;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_radioProxy::signal_AF_setting_status() {
  return m_signalproxy_AF_setting_status;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_radioProxy::signal_RegionLock_setting_status() {
  return m_signalproxy_RegionLock_setting_status;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_radioProxy::signal_Current_genre_status() {
  return m_signalproxy_Current_genre_status;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_radioProxy::signal_Metadata_status() {
  return m_signalproxy_Metadata_status;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t, int32_t)>> com_jci_radioProxy::signal_Setting_status() {
  return m_signalproxy_Setting_status;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t, int32_t)>> com_jci_radioProxy::signal_Pty_response() {
  return m_signalproxy_Pty_response;

}
std::shared_ptr <DBus::SignalProxy<void(Invalid)>> com_jci_radioProxy::signal_HD_tuner_status() {
  return m_signalproxy_HD_tuner_status;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < int32_t, int32_t > )>> com_jci_radioProxy::signal_HAR_status() {
  return m_signalproxy_HAR_status;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_radioProxy::signal_Traffic_alert() {
  return m_signalproxy_Traffic_alert;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_radioProxy::signal_Metadata_Artisticinfo() {
  return m_signalproxy_Metadata_Artisticinfo;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < bool,
                                        bool,
                                        bool,
                                        bool,
                                        bool,
                                        bool,
                                        bool > )>> com_jci_radioProxy::signal_Metadata_change_notification() {
  return m_signalproxy_Metadata_change_notification;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_radioProxy::signal_Japan_Region_specific_notification() {
  return m_signalproxy_Japan_Region_specific_notification;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_radioProxy::signal_Region_specific_notification() {
  return m_signalproxy_Region_specific_notification;

}
