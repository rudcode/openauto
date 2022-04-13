#ifndef COM_JCI_AUXINPROXY_H
#define COM_JCI_AUXINPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_auxinProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_auxinProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_auxinProxy> create(std::string name = "com.jci.auxin");
  int32_t Mode_Req(uint8_t mode);
  int32_t DeviceStatus_Req();
  int32_t GetAuxinStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_Status();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t(uint8_t)>> m_method_Mode_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_DeviceStatus_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetAuxinStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_Status;
};
#endif /* COM_JCI_AUXINPROXY_H */
