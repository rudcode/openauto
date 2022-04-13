#ifndef COM_JCI_BUCPSAPROXY_H
#define COM_JCI_BUCPSAPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_bucpsaProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_bucpsaProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_bucpsaProxy> create(std::string name = "com.jci.bucpsa");
  int32_t GetReverseStatus();
  int32_t DisplayCommand(uint32_t command);
  DBus::MultipleReturn<uint32_t, int32_t> GetDisplayMode_async();
  DBus::MultipleReturn<uint32_t, int32_t> GetDisplayMode();
  int32_t SetPSMEnabled(uint8_t psmEnabled);
  uint8_t GetPSMInstalledStatus();
  uint32_t GetSteeringWheelLocation();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_CommandResponse();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_DisplayMode();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_ReverseStatusChanged();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_PSMInstallStatusChanged();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_CameraType();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_SteeringWheelLocation();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetReverseStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_DisplayCommand;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, int32_t>()>> m_method_GetDisplayMode_async;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, int32_t>()>> m_method_GetDisplayMode;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint8_t)>> m_method_SetPSMEnabled;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetPSMInstalledStatus;
  std::shared_ptr<DBus::MethodProxy<uint32_t()>> m_method_GetSteeringWheelLocation;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_CommandResponse;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_DisplayMode;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_ReverseStatusChanged;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_PSMInstallStatusChanged;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_CameraType;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_SteeringWheelLocation;
};
#endif /* COM_JCI_BUCPSAPROXY_H */
