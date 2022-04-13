#ifndef COM_JCI_CPP_DEVICES_KEYBOARDPROXY_H
#define COM_JCI_CPP_DEVICES_KEYBOARDPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_cpp_devices_KeyboardProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_cpp_devices_KeyboardProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_cpp_devices_KeyboardProxy> create(std::string name = "com.jci.cpp.devices.Keyboard");
  DBus::MultipleReturn<int32_t, std::vector<std::string>> enumerate();
  int32_t keyClick(std::string name, int32_t code, bool shift);
  int32_t keyPress(std::string name, int32_t code);
  int32_t keyRelease(std::string name, int32_t code);
  int32_t keySequence(std::string name, std::string string);
 protected:
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, std::vector<std::string>>()>> m_method_enumerate;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::string, int32_t, bool)>> m_method_keyClick;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::string, int32_t)>> m_method_keyPress;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::string, int32_t)>> m_method_keyRelease;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::string, std::string)>> m_method_keySequence;
};
#endif /* COM_JCI_CPP_DEVICES_KEYBOARDPROXY_H */
