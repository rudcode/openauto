#ifndef COM_JCI_CPP_POWER_INTERFACEPROXY_H
#define COM_JCI_CPP_POWER_INTERFACEPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_cpp_power_InterfaceProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_cpp_power_InterfaceProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_cpp_power_InterfaceProxy> create(std::string name = "com.jci.cpp.power.Interface");
  DBus::MultipleReturn<int32_t, uint32_t> OpenConnection();
  int32_t CloseConnection();
  int32_t SafeShutDown();
  int32_t SafeReboot();
  int32_t FactoryReset();
  DBus::MultipleReturn<int32_t, int32_t> GetCurrentAccStatus();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_NotifyAccChange();
 protected:
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t>()>> m_method_OpenConnection;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_CloseConnection;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_SafeShutDown;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_SafeReboot;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_FactoryReset;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, int32_t>()>> m_method_GetCurrentAccStatus;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_NotifyAccChange;
};
#endif /* COM_JCI_CPP_POWER_INTERFACEPROXY_H */
