#include "com_jci_btrvrProxy.h"

com_jci_btrvrProxy::com_jci_btrvrProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_StartRemoteVr = this->create_method<int32_t()>("StartRemoteVr");
  m_method_StopRemoteVr = this->create_method<int32_t()>("StopRemoteVr");
  m_method_EnableEyesFreemode = this->create_method<int32_t()>("EnableEyesFreemode");
  m_method_DisableEyesFreeMode = this->create_method<int32_t()>("DisableEyesFreeMode");
  m_method_GetRemoteVrStatus = this->create_method<int32_t()>("GetRemoteVrStatus");
  m_method_SetDontShowSetting = this->create_method<int32_t(uint32_t)>("SetDontShowSetting");
  m_method_GetDontShowSetting = this->create_method<int32_t()>("GetDontShowSetting");
  m_signalproxy_RemoteVrStatusResp = this->create_signal<void(uint32_t)>("RemoteVrStatusResp");
  m_signalproxy_DontShowSettingResp = this->create_signal<void(uint32_t)>("DontShowSettingResp");
  m_signalproxy_ShowWinkSettingResp = this->create_signal<void(uint32_t)>("ShowWinkSettingResp");

}
std::shared_ptr <com_jci_btrvrProxy> com_jci_btrvrProxy::create(std::string name) {
  return std::shared_ptr<com_jci_btrvrProxy>(new com_jci_btrvrProxy(name));

}
int32_t com_jci_btrvrProxy::StartRemoteVr() {
  return (*m_method_StartRemoteVr)();

}
int32_t com_jci_btrvrProxy::StopRemoteVr() {
  return (*m_method_StopRemoteVr)();

}
int32_t com_jci_btrvrProxy::EnableEyesFreemode() {
  return (*m_method_EnableEyesFreemode)();

}
int32_t com_jci_btrvrProxy::DisableEyesFreeMode() {
  return (*m_method_DisableEyesFreeMode)();

}
int32_t com_jci_btrvrProxy::GetRemoteVrStatus() {
  return (*m_method_GetRemoteVrStatus)();

}
int32_t com_jci_btrvrProxy::SetDontShowSetting(uint32_t dontShowSettingValue) {
  return (*m_method_SetDontShowSetting)(dontShowSettingValue);

}
int32_t com_jci_btrvrProxy::GetDontShowSetting() {
  return (*m_method_GetDontShowSetting)();

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_btrvrProxy::signal_RemoteVrStatusResp() {
  return m_signalproxy_RemoteVrStatusResp;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_btrvrProxy::signal_DontShowSettingResp() {
  return m_signalproxy_DontShowSettingResp;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_btrvrProxy::signal_ShowWinkSettingResp() {
  return m_signalproxy_ShowWinkSettingResp;

}
