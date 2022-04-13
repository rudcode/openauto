#ifndef COM_JCI_AUDIOSETTINGSPROXY_H
#define COM_JCI_AUDIOSETTINGSPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_audiosettingsProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_audiosettingsProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_audiosettingsProxy> create(std::string name = "com.jci.audiosettings");
  int32_t BLM_GetSettingInfo(int32_t setting_type);
  int32_t BLM_SetVolume(int32_t setting_type, int32_t absolute, int32_t step, std::string string_to_play);
  int32_t Exit();
  int32_t BLM_Exit();
  void BLM_BeepPlay(int32_t beep_type);
  int32_t BLM_BeepPlay_Async(int32_t beep_type);
  int32_t BLM_BeepSet_Async(int32_t beep_type);
  int32_t BLM_GetEnableDisableInfo(int32_t setting_type);
  std::shared_ptr<DBus::SignalProxy<void(int32_t, int32_t, int32_t, int32_t, int32_t)>> signal_BLM_SettingInfo();
  std::shared_ptr<DBus::SignalProxy<void(int32_t, int32_t, int32_t, int32_t)>> signal_BLM_VolumeLevel();
  std::shared_ptr<DBus::SignalProxy<void(int32_t, bool)>> signal_BLM_EnableDisableSettingsType();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_BLM_GetSettingInfo;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t, int32_t, int32_t, std::string)>> m_method_BLM_SetVolume;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Exit;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_BLM_Exit;
  std::shared_ptr<DBus::MethodProxy<void(int32_t)>> m_method_BLM_BeepPlay;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_BLM_BeepPlay_Async;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_BLM_BeepSet_Async;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_BLM_GetEnableDisableInfo;
  std::shared_ptr<DBus::SignalProxy<void(int32_t, int32_t, int32_t, int32_t, int32_t)>> m_signalproxy_BLM_SettingInfo;
  std::shared_ptr<DBus::SignalProxy<void(int32_t, int32_t, int32_t, int32_t)>> m_signalproxy_BLM_VolumeLevel;
  std::shared_ptr<DBus::SignalProxy<void(int32_t, bool)>> m_signalproxy_BLM_EnableDisableSettingsType;
};
#endif /* COM_JCI_AUDIOSETTINGSPROXY_H */
