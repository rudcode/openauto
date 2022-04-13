#include "com_jci_xmProxy.h"

com_jci_xmProxy::com_jci_xmProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_GetModeStatus = this->create_method<int32_t()>("GetModeStatus");
  m_method_ModeChange = this->create_method<int32_t(int32_t)>("ModeChange");
  m_method_FavoriteModeChange = this->create_method<int32_t(int32_t, uint8_t, uint8_t)>("FavoriteModeChange");
  m_method_TuneRelative = this->create_method<int32_t(int32_t, uint8_t)>("TuneRelative");
  m_method_TuneAbsolute = this->create_method<int32_t(uint8_t, uint8_t)>("TuneAbsolute");
  m_method_MuteReq = this->create_method<int32_t(int32_t)>("MuteReq");
  m_method_IsParentalLockEnabled = this->create_method<int32_t()>("IsParentalLockEnabled");
  m_method_IsParentalLockPINSet = this->create_method<int32_t()>("IsParentalLockPINSet");
  m_method_IsChannelLocked = this->create_method<int32_t(uint8_t)>("IsChannelLocked");
  m_method_GetParentalLockPIN = this->create_method<int32_t()>("GetParentalLockPIN");
  m_method_GetDefaultParentalLockPIN = this->create_method<int32_t()>("GetDefaultParentalLockPIN");
  m_method_SetParentalLockPIN =
      this->create_method<int32_t(std::tuple < uint8_t, uint8_t, uint8_t, uint8_t > )>("SetParentalLockPIN");
  m_method_SetParentalLockStatus = this->create_method<int32_t(int32_t)>("SetParentalLockStatus");
  m_method_SetChannelLock = this->create_method<int32_t(int32_t, uint8_t)>("SetChannelLock");
  m_method_DisplayXMSettings = this->create_method<int32_t()>("DisplayXMSettings");
  m_method_ScanReq = this->create_method<int32_t(int32_t)>("ScanReq");
  m_method_GetConfigStatus = this->create_method<int32_t()>("GetConfigStatus");
  m_method_Fav_Seek_Req = this->create_method<int32_t(int32_t, uint8_t)>("Fav_Seek_Req");
  m_method_GetInstallStatus = this->create_method<int32_t()>("GetInstallStatus");
  m_signalproxy_TunerStatus = this->create_signal<void(std::tuple < uint8_t,
                                                       uint8_t,
                                                       uint8_t,
                                                       uint8_t,
                                                       uint8_t,
                                                       bool,
                                                       std::vector < uint8_t > ,
                                                       int32_t > )>("TunerStatus");
  m_signalproxy_MuteStatus = this->create_signal<void(int32_t)>("MuteStatus");
  m_signalproxy_ChannelListUpdated = this->create_signal<void(uint8_t)>("ChannelListUpdated");
  m_signalproxy_AntennaStatus = this->create_signal<void(std::tuple < uint8_t, uint8_t > )>("AntennaStatus");
  m_signalproxy_ParentalLockPin =
      this->create_signal<void(std::tuple < uint8_t, uint8_t, uint8_t, uint8_t > )>("ParentalLockPin");
  m_signalproxy_DefaultParentalLockPin =
      this->create_signal<void(std::tuple < uint8_t, uint8_t, uint8_t, uint8_t > )>("DefaultParentalLockPin");
  m_signalproxy_MetadataAvailable = this->create_signal<void(int32_t)>("MetadataAvailable");
  m_signalproxy_MetadataChange = this->create_signal<void(std::tuple < bool, bool, bool, bool > )>("MetadataChange");
  m_signalproxy_ModeStatus = this->create_signal<void(int32_t)>("ModeStatus");
  m_signalproxy_ConfigStatus = this->create_signal<void(int32_t)>("ConfigStatus");
  m_signalproxy_InstallStatus = this->create_signal<void(int32_t)>("InstallStatus");

}
std::shared_ptr <com_jci_xmProxy> com_jci_xmProxy::create(std::string name) {
  return std::shared_ptr<com_jci_xmProxy>(new com_jci_xmProxy(name));

}
int32_t com_jci_xmProxy::GetModeStatus() {
  return (*m_method_GetModeStatus)();

}
int32_t com_jci_xmProxy::ModeChange(int32_t xm_mode) {
  return (*m_method_ModeChange)(xm_mode);

}
int32_t com_jci_xmProxy::FavoriteModeChange(int32_t xm_mode, uint8_t tune_value_sid, uint8_t tune_value_ch) {
  return (*m_method_FavoriteModeChange)(xm_mode, tune_value_sid, tune_value_ch);

}
int32_t com_jci_xmProxy::TuneRelative(int32_t tune_direction, uint8_t tune_steps) {
  return (*m_method_TuneRelative)(tune_direction, tune_steps);

}
int32_t com_jci_xmProxy::TuneAbsolute(uint8_t tune_value_sid, uint8_t tune_value_ch) {
  return (*m_method_TuneAbsolute)(tune_value_sid, tune_value_ch);

}
int32_t com_jci_xmProxy::MuteReq(int32_t mute_direction) {
  return (*m_method_MuteReq)(mute_direction);

}
int32_t com_jci_xmProxy::IsParentalLockEnabled() {
  return (*m_method_IsParentalLockEnabled)();

}
int32_t com_jci_xmProxy::IsParentalLockPINSet() {
  return (*m_method_IsParentalLockPINSet)();

}
int32_t com_jci_xmProxy::IsChannelLocked(uint8_t channel_id) {
  return (*m_method_IsChannelLocked)(channel_id);

}
int32_t com_jci_xmProxy::GetParentalLockPIN() {
  return (*m_method_GetParentalLockPIN)();

}
int32_t com_jci_xmProxy::GetDefaultParentalLockPIN() {
  return (*m_method_GetDefaultParentalLockPIN)();

}
int32_t com_jci_xmProxy::SetParentalLockPIN(std::tuple <uint8_t, uint8_t, uint8_t, uint8_t> parental_lock_pin) {
  return (*m_method_SetParentalLockPIN)(parental_lock_pin);

}
int32_t com_jci_xmProxy::SetParentalLockStatus(int32_t parental_lock_status) {
  return (*m_method_SetParentalLockStatus)(parental_lock_status);

}
int32_t com_jci_xmProxy::SetChannelLock(int32_t channel_lock_status, uint8_t channel_id) {
  return (*m_method_SetChannelLock)(channel_lock_status, channel_id);

}
int32_t com_jci_xmProxy::DisplayXMSettings() {
  return (*m_method_DisplayXMSettings)();

}
int32_t com_jci_xmProxy::ScanReq(int32_t scan_req_type) {
  return (*m_method_ScanReq)(scan_req_type);

}
int32_t com_jci_xmProxy::GetConfigStatus() {
  return (*m_method_GetConfigStatus)();

}
int32_t com_jci_xmProxy::Fav_Seek_Req(int32_t fav_seek_dir, uint8_t current_ch) {
  return (*m_method_Fav_Seek_Req)(fav_seek_dir, current_ch);

}
int32_t com_jci_xmProxy::GetInstallStatus() {
  return (*m_method_GetInstallStatus)();

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        bool,
                                        std::vector < uint8_t > ,
                                        int32_t > )>> com_jci_xmProxy::signal_TunerStatus() {
  return m_signalproxy_TunerStatus;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_xmProxy::signal_MuteStatus() {
  return m_signalproxy_MuteStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_xmProxy::signal_ChannelListUpdated() {
  return m_signalproxy_ChannelListUpdated;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t, uint8_t > )>> com_jci_xmProxy::signal_AntennaStatus() {
  return m_signalproxy_AntennaStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t > )>> com_jci_xmProxy::signal_ParentalLockPin() {
  return m_signalproxy_ParentalLockPin;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t > )>> com_jci_xmProxy::signal_DefaultParentalLockPin() {
  return m_signalproxy_DefaultParentalLockPin;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_xmProxy::signal_MetadataAvailable() {
  return m_signalproxy_MetadataAvailable;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < bool,
                                        bool,
                                        bool,
                                        bool > )>> com_jci_xmProxy::signal_MetadataChange() {
  return m_signalproxy_MetadataChange;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_xmProxy::signal_ModeStatus() {
  return m_signalproxy_ModeStatus;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_xmProxy::signal_ConfigStatus() {
  return m_signalproxy_ConfigStatus;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_xmProxy::signal_InstallStatus() {
  return m_signalproxy_InstallStatus;

}
