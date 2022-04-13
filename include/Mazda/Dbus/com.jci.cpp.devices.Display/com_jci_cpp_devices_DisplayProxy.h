#ifndef COM_JCI_CPP_DEVICES_DISPLAYPROXY_H
#define COM_JCI_CPP_DEVICES_DISPLAYPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_cpp_devices_DisplayProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_cpp_devices_DisplayProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_cpp_devices_DisplayProxy> create(std::string name = "com.jci.cpp.devices.Display");
  DBus::MultipleReturn<int32_t, std::vector<std::string>> enumerate();
  DBus::MultipleReturn<int32_t, uint16_t> getContrast(std::string name);
  DBus::MultipleReturn<int32_t, uint16_t> getContrastSteps(std::string name);
  DBus::MultipleReturn<int32_t, bool> setContrast(std::string name, uint16_t contrast);
 protected:
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, std::vector<std::string>>()>> m_method_enumerate;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint16_t>(std::string)>> m_method_getContrast;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint16_t>(std::string)>> m_method_getContrastSteps;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, bool>(std::string, uint16_t)>> m_method_setContrast;
};
#endif /* COM_JCI_CPP_DEVICES_DISPLAYPROXY_H */
