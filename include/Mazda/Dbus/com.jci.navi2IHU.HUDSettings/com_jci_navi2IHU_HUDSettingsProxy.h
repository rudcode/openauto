#ifndef COM_JCI_NAVI_IHU_HUDSETTINGSPROXY_H
#define COM_JCI_NAVI_IHU_HUDSETTINGSPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_navi2IHU_HUDSettingsProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_navi2IHU_HUDSettingsProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_navi2IHU_HUDSettingsProxy> create(std::string name = "com.jci.navi2IHU.HUDSettings");
  bool GetHUDIsInstalled();
  bool GetHUDIsInstalled_async();
  void SetHUDSetting(int32_t hUDSettingType, int32_t hUDSettingValue);
  void SetHUDSetting_Async(int32_t hUDSettingType, int32_t hUDSettingValue);
  int32_t GetHUDSetting(int32_t hUDSettingType);
  void ResetHUDSettings();
  int32_t GetHUDControlAllowed();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_HUDInstalledChanged();
  std::shared_ptr<DBus::SignalProxy<void(int32_t, int32_t)>> signal_SetHUDSettingFailed();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_HUDControlAllowed();
  std::shared_ptr<DBus::SignalProxy<void(int32_t, int32_t)>> signal_HUDSettingChanged();
 protected:
  std::shared_ptr<DBus::MethodProxy<bool()>> m_method_GetHUDIsInstalled;
  std::shared_ptr<DBus::MethodProxy<bool()>> m_method_GetHUDIsInstalled_async;
  std::shared_ptr<DBus::MethodProxy<void(int32_t, int32_t)>> m_method_SetHUDSetting;
  std::shared_ptr<DBus::MethodProxy<void(int32_t, int32_t)>> m_method_SetHUDSetting_Async;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_GetHUDSetting;
  std::shared_ptr<DBus::MethodProxy<void()>> m_method_ResetHUDSettings;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetHUDControlAllowed;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_HUDInstalledChanged;
  std::shared_ptr<DBus::SignalProxy<void(int32_t, int32_t)>> m_signalproxy_SetHUDSettingFailed;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_HUDControlAllowed;
  std::shared_ptr<DBus::SignalProxy<void(int32_t, int32_t)>> m_signalproxy_HUDSettingChanged;
};
#endif /* COM_JCI_NAVI_IHU_HUDSETTINGSPROXY_H */
