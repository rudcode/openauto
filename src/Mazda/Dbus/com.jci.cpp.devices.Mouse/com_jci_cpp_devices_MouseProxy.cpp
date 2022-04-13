#include "com_jci_cpp_devices_MouseProxy.h"

com_jci_cpp_devices_MouseProxy::com_jci_cpp_devices_MouseProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_buttonClick = this->create_method<int32_t(std::string, int32_t)>("buttonClick");
  m_method_buttonPress = this->create_method<int32_t(std::string, int32_t)>("buttonPress");
  m_method_buttonRelease = this->create_method<int32_t(std::string, int32_t)>("buttonRelease");
  m_method_enumerate = this->create_method < DBus::MultipleReturn < int32_t, std::vector < std::string >> ()
      > ("enumerate");
  m_method_move = this->create_method<int32_t(std::string, int32_t, int32_t, int32_t)>("move");
  m_method_moveAxis = this->create_method<int32_t(std::string, int32_t, int32_t)>("moveAxis");
  m_method_scroll = this->create_method<int32_t(std::string, int32_t, int32_t, int32_t)>("scroll");
  m_method_scrollAxis = this->create_method<int32_t(std::string, int32_t, int32_t)>("scrollAxis");

}
std::shared_ptr <com_jci_cpp_devices_MouseProxy> com_jci_cpp_devices_MouseProxy::create(std::string name) {
  return std::shared_ptr<com_jci_cpp_devices_MouseProxy>(new com_jci_cpp_devices_MouseProxy(name));

}
int32_t com_jci_cpp_devices_MouseProxy::buttonClick(std::string name, int32_t button) {
  return (*m_method_buttonClick)(name, button);

}
int32_t com_jci_cpp_devices_MouseProxy::buttonPress(std::string name, int32_t button) {
  return (*m_method_buttonPress)(name, button);

}
int32_t com_jci_cpp_devices_MouseProxy::buttonRelease(std::string name, int32_t button) {
  return (*m_method_buttonRelease)(name, button);

}
DBus::MultipleReturn <int32_t, std::vector<std::string>> com_jci_cpp_devices_MouseProxy::enumerate() {
  return (*m_method_enumerate)();

}
int32_t com_jci_cpp_devices_MouseProxy::move(std::string name, int32_t x, int32_t y, int32_t z) {
  return (*m_method_move)(name, x, y, z);

}
int32_t com_jci_cpp_devices_MouseProxy::moveAxis(std::string name, int32_t axis, int32_t distance) {
  return (*m_method_moveAxis)(name, axis, distance);

}
int32_t com_jci_cpp_devices_MouseProxy::scroll(std::string name, int32_t x, int32_t y, int32_t z) {
  return (*m_method_scroll)(name, x, y, z);

}
int32_t com_jci_cpp_devices_MouseProxy::scrollAxis(std::string name, int32_t axis, int32_t distance) {
  return (*m_method_scrollAxis)(name, axis, distance);

}
