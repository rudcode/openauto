#include "com_jci_navi2IHU_HUDSettingsProxy.h"

com_jci_navi2IHU_HUDSettingsProxy::com_jci_navi2IHU_HUDSettingsProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_GetHUDIsInstalled = this->create_method<bool()>("GetHUDIsInstalled");
  m_method_GetHUDIsInstalled_async = this->create_method<bool()>("GetHUDIsInstalled_async");
  m_method_SetHUDSetting = this->create_method<void(int32_t, int32_t)>("SetHUDSetting");
  m_method_SetHUDSetting_Async = this->create_method<void(int32_t, int32_t)>("SetHUDSetting_Async");
  m_method_GetHUDSetting = this->create_method<int32_t(int32_t)>("GetHUDSetting");
  m_method_ResetHUDSettings = this->create_method<void()>("ResetHUDSettings");
  m_method_GetHUDControlAllowed = this->create_method<int32_t()>("GetHUDControlAllowed");
  m_signalproxy_HUDInstalledChanged = this->create_signal<void(bool)>("HUDInstalledChanged");
  m_signalproxy_SetHUDSettingFailed = this->create_signal<void(int32_t, int32_t)>("SetHUDSettingFailed");
  m_signalproxy_HUDControlAllowed = this->create_signal<void(bool)>("HUDControlAllowed");
  m_signalproxy_HUDSettingChanged = this->create_signal<void(int32_t, int32_t)>("HUDSettingChanged");

}
std::shared_ptr<com_jci_navi2IHU_HUDSettingsProxy> com_jci_navi2IHU_HUDSettingsProxy::create(std::string name) {
  return std::shared_ptr<com_jci_navi2IHU_HUDSettingsProxy>(new com_jci_navi2IHU_HUDSettingsProxy(name));

}
bool com_jci_navi2IHU_HUDSettingsProxy::GetHUDIsInstalled() {
  return (*m_method_GetHUDIsInstalled)();

}
bool com_jci_navi2IHU_HUDSettingsProxy::GetHUDIsInstalled_async() {
  return (*m_method_GetHUDIsInstalled_async)();

}
void com_jci_navi2IHU_HUDSettingsProxy::SetHUDSetting(int32_t hUDSettingType, int32_t hUDSettingValue) {
  (*m_method_SetHUDSetting)(hUDSettingType, hUDSettingValue);

}
void com_jci_navi2IHU_HUDSettingsProxy::SetHUDSetting_Async(int32_t hUDSettingType, int32_t hUDSettingValue) {
  (*m_method_SetHUDSetting_Async)(hUDSettingType, hUDSettingValue);

}
int32_t com_jci_navi2IHU_HUDSettingsProxy::GetHUDSetting(int32_t hUDSettingType) {
  return (*m_method_GetHUDSetting)(hUDSettingType);

}
void com_jci_navi2IHU_HUDSettingsProxy::ResetHUDSettings() {
  (*m_method_ResetHUDSettings)();

}
int32_t com_jci_navi2IHU_HUDSettingsProxy::GetHUDControlAllowed() {
  return (*m_method_GetHUDControlAllowed)();

}
std::shared_ptr<DBus::SignalProxy<void(bool)>> com_jci_navi2IHU_HUDSettingsProxy::signal_HUDInstalledChanged() {
  return m_signalproxy_HUDInstalledChanged;

}
std::shared_ptr<DBus::SignalProxy<void(int32_t,
                                       int32_t)>> com_jci_navi2IHU_HUDSettingsProxy::signal_SetHUDSettingFailed() {
  return m_signalproxy_SetHUDSettingFailed;

}
std::shared_ptr<DBus::SignalProxy<void(bool)>> com_jci_navi2IHU_HUDSettingsProxy::signal_HUDControlAllowed() {
  return m_signalproxy_HUDControlAllowed;

}
std::shared_ptr<DBus::SignalProxy<void(int32_t,
                                       int32_t)>> com_jci_navi2IHU_HUDSettingsProxy::signal_HUDSettingChanged() {
  return m_signalproxy_HUDSettingChanged;

}
