#include "com_jci_audiosettingsProxy.h"

com_jci_audiosettingsProxy::com_jci_audiosettingsProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_BLM_GetSettingInfo = this->create_method<int32_t(int32_t)>("BLM_GetSettingInfo");
  m_method_BLM_SetVolume = this->create_method<int32_t(int32_t, int32_t, int32_t, std::string)>("BLM_SetVolume");
  m_method_Exit = this->create_method<int32_t()>("Exit");
  m_method_BLM_Exit = this->create_method<int32_t()>("BLM_Exit");
  m_method_BLM_BeepPlay = this->create_method<void(int32_t)>("BLM_BeepPlay");
  m_method_BLM_BeepPlay_Async = this->create_method<int32_t(int32_t)>("BLM_BeepPlay_Async");
  m_method_BLM_BeepSet_Async = this->create_method<int32_t(int32_t)>("BLM_BeepSet_Async");
  m_method_BLM_GetEnableDisableInfo = this->create_method<int32_t(int32_t)>("BLM_GetEnableDisableInfo");
  m_signalproxy_BLM_SettingInfo =
      this->create_signal<void(int32_t, int32_t, int32_t, int32_t, int32_t)>("BLM_SettingInfo");
  m_signalproxy_BLM_VolumeLevel = this->create_signal<void(int32_t, int32_t, int32_t, int32_t)>("BLM_VolumeLevel");
  m_signalproxy_BLM_EnableDisableSettingsType =
      this->create_signal<void(int32_t, bool)>("BLM_EnableDisableSettingsType");

}
std::shared_ptr <com_jci_audiosettingsProxy> com_jci_audiosettingsProxy::create(std::string name) {
  return std::shared_ptr<com_jci_audiosettingsProxy>(new com_jci_audiosettingsProxy(name));

}
int32_t com_jci_audiosettingsProxy::BLM_GetSettingInfo(int32_t setting_type) {
  return (*m_method_BLM_GetSettingInfo)(setting_type);

}
int32_t com_jci_audiosettingsProxy::BLM_SetVolume(int32_t setting_type,
                                                  int32_t absolute,
                                                  int32_t step,
                                                  std::string string_to_play) {
  return (*m_method_BLM_SetVolume)(setting_type, absolute, step, string_to_play);

}
int32_t com_jci_audiosettingsProxy::Exit() {
  return (*m_method_Exit)();

}
int32_t com_jci_audiosettingsProxy::BLM_Exit() {
  return (*m_method_BLM_Exit)();

}
void com_jci_audiosettingsProxy::BLM_BeepPlay(int32_t beep_type) {
  (*m_method_BLM_BeepPlay)(beep_type);

}
int32_t com_jci_audiosettingsProxy::BLM_BeepPlay_Async(int32_t beep_type) {
  return (*m_method_BLM_BeepPlay_Async)(beep_type);

}
int32_t com_jci_audiosettingsProxy::BLM_BeepSet_Async(int32_t beep_type) {
  return (*m_method_BLM_BeepSet_Async)(beep_type);

}
int32_t com_jci_audiosettingsProxy::BLM_GetEnableDisableInfo(int32_t setting_type) {
  return (*m_method_BLM_GetEnableDisableInfo)(setting_type);

}
std::shared_ptr <DBus::SignalProxy<void(int32_t,
                                        int32_t,
                                        int32_t,
                                        int32_t,
                                        int32_t)>> com_jci_audiosettingsProxy::signal_BLM_SettingInfo() {
  return m_signalproxy_BLM_SettingInfo;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t,
                                        int32_t,
                                        int32_t,
                                        int32_t)>> com_jci_audiosettingsProxy::signal_BLM_VolumeLevel() {
  return m_signalproxy_BLM_VolumeLevel;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t,
                                        bool)>> com_jci_audiosettingsProxy::signal_BLM_EnableDisableSettingsType() {
  return m_signalproxy_BLM_EnableDisableSettingsType;

}
