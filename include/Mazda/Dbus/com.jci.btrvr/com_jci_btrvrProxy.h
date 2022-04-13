#ifndef COM_JCI_BTRVRPROXY_H
#define COM_JCI_BTRVRPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_btrvrProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_btrvrProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_btrvrProxy> create(std::string name = "com.jci.btrvr");
  int32_t StartRemoteVr();
  int32_t StopRemoteVr();
  int32_t EnableEyesFreemode();
  int32_t DisableEyesFreeMode();
  int32_t GetRemoteVrStatus();
  int32_t SetDontShowSetting(uint32_t dontShowSettingValue);
  int32_t GetDontShowSetting();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_RemoteVrStatusResp();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_DontShowSettingResp();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_ShowWinkSettingResp();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_StartRemoteVr;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_StopRemoteVr;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_EnableEyesFreemode;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_DisableEyesFreeMode;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetRemoteVrStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_SetDontShowSetting;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetDontShowSetting;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_RemoteVrStatusResp;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_DontShowSettingResp;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_ShowWinkSettingResp;
};
#endif /* COM_JCI_BTRVRPROXY_H */
