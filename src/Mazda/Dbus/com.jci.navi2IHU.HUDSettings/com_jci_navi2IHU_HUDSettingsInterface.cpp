#include "com_jci_navi2IHU_HUDSettingsInterface.h"

com_jci_navi2IHU_HUDSettingsInterface::com_jci_navi2IHU_HUDSettingsInterface(com_jci_navi2IHU_HUDSettings *adaptee,
                                                                             std::string name) : DBus::Interface(name) {
  this->create_method<bool()>("GetHUDIsInstalled",
                              sigc::mem_fun(*adaptee, &com_jci_navi2IHU_HUDSettings::GetHUDIsInstalled));
  this->create_method<bool()>("GetHUDIsInstalled_async",
                              sigc::mem_fun(*adaptee, &com_jci_navi2IHU_HUDSettings::GetHUDIsInstalled_async));
  this->create_method<void(int32_t, int32_t)>("SetHUDSetting",
                                              sigc::mem_fun(*adaptee, &com_jci_navi2IHU_HUDSettings::SetHUDSetting));
  this->create_method<void(int32_t, int32_t)>("SetHUDSetting_Async",
                                              sigc::mem_fun(*adaptee,
                                                            &com_jci_navi2IHU_HUDSettings::SetHUDSetting_Async));
  this->create_method<int32_t(int32_t)>("GetHUDSetting",
                                        sigc::mem_fun(*adaptee, &com_jci_navi2IHU_HUDSettings::GetHUDSetting));
  this->create_method<void()>("ResetHUDSettings",
                              sigc::mem_fun(*adaptee, &com_jci_navi2IHU_HUDSettings::ResetHUDSettings));
  this->create_method<int32_t()>("GetHUDControlAllowed",
                                 sigc::mem_fun(*adaptee, &com_jci_navi2IHU_HUDSettings::GetHUDControlAllowed));
  m_signal_HUDInstalledChanged = create_signal<void(bool)>("HUDInstalledChanged");
  m_signal_SetHUDSettingFailed = create_signal<void(int32_t, int32_t)>("SetHUDSettingFailed");
  m_signal_HUDControlAllowed = create_signal<void(bool)>("HUDControlAllowed");
  m_signal_HUDSettingChanged = create_signal<void(int32_t, int32_t)>("HUDSettingChanged");

}
std::shared_ptr<com_jci_navi2IHU_HUDSettingsInterface> com_jci_navi2IHU_HUDSettingsInterface::create(
    com_jci_navi2IHU_HUDSettings *adaptee,
    std::string name) {
  return std::shared_ptr<com_jci_navi2IHU_HUDSettingsInterface>(new com_jci_navi2IHU_HUDSettingsInterface(adaptee,
                                                                                                          name));

}
std::shared_ptr<DBus::Signal<void(bool)>> com_jci_navi2IHU_HUDSettingsInterface::signal_HUDInstalledChanged() {
  return m_signal_HUDInstalledChanged;

}
void com_jci_navi2IHU_HUDSettingsInterface::HUDInstalledChanged(bool hUDInstalled) {
  (*m_signal_HUDInstalledChanged)(hUDInstalled);

}
std::shared_ptr<DBus::Signal<void(int32_t,
                                  int32_t)>> com_jci_navi2IHU_HUDSettingsInterface::signal_SetHUDSettingFailed() {
  return m_signal_SetHUDSettingFailed;

}
void com_jci_navi2IHU_HUDSettingsInterface::SetHUDSettingFailed(int32_t hUDSettingType, int32_t err) {
  (*m_signal_SetHUDSettingFailed)(hUDSettingType, err);

}
std::shared_ptr<DBus::Signal<void(bool)>> com_jci_navi2IHU_HUDSettingsInterface::signal_HUDControlAllowed() {
  return m_signal_HUDControlAllowed;

}
void com_jci_navi2IHU_HUDSettingsInterface::HUDControlAllowed(bool bAllowed) {
  (*m_signal_HUDControlAllowed)(bAllowed);

}
std::shared_ptr<DBus::Signal<void(int32_t,
                                  int32_t)>> com_jci_navi2IHU_HUDSettingsInterface::signal_HUDSettingChanged() {
  return m_signal_HUDSettingChanged;

}
void com_jci_navi2IHU_HUDSettingsInterface::HUDSettingChanged(int32_t hUDSettingType, int32_t value) {
  (*m_signal_HUDSettingChanged)(hUDSettingType, value);

}
