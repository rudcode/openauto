#ifndef COM_JCI_CPP_DEVICES_GPIOPROXY_H
#define COM_JCI_CPP_DEVICES_GPIOPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_cpp_devices_GpioProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_cpp_devices_GpioProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_cpp_devices_GpioProxy> create(std::string name = "com.jci.cpp.devices.Gpio");
  DBus::MultipleReturn<int32_t, std::vector<std::string>> enumerate();
  DBus::MultipleReturn<int32_t, bool> getValue(std::string name);
  DBus::MultipleReturn<int32_t, bool> setValue(std::string name, bool value);
 protected:
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, std::vector<std::string>>()>> m_method_enumerate;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, bool>(std::string)>> m_method_getValue;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, bool>(std::string, bool)>> m_method_setValue;
};
#endif /* COM_JCI_CPP_DEVICES_GPIOPROXY_H */
