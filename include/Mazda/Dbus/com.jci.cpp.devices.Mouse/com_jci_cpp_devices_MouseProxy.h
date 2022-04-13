#ifndef COM_JCI_CPP_DEVICES_MOUSEPROXY_H
#define COM_JCI_CPP_DEVICES_MOUSEPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_cpp_devices_MouseProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_cpp_devices_MouseProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_cpp_devices_MouseProxy> create(std::string name = "com.jci.cpp.devices.Mouse");
  int32_t buttonClick(std::string name, int32_t button);
  int32_t buttonPress(std::string name, int32_t button);
  int32_t buttonRelease(std::string name, int32_t button);
  DBus::MultipleReturn<int32_t, std::vector<std::string>> enumerate();
  int32_t move(std::string name, int32_t x, int32_t y, int32_t z);
  int32_t moveAxis(std::string name, int32_t axis, int32_t distance);
  int32_t scroll(std::string name, int32_t x, int32_t y, int32_t z);
  int32_t scrollAxis(std::string name, int32_t axis, int32_t distance);
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t(std::string, int32_t)>> m_method_buttonClick;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::string, int32_t)>> m_method_buttonPress;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::string, int32_t)>> m_method_buttonRelease;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, std::vector<std::string>>()>> m_method_enumerate;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::string, int32_t, int32_t, int32_t)>> m_method_move;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::string, int32_t, int32_t)>> m_method_moveAxis;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::string, int32_t, int32_t, int32_t)>> m_method_scroll;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::string, int32_t, int32_t)>> m_method_scrollAxis;
};
#endif /* COM_JCI_CPP_DEVICES_MOUSEPROXY_H */
