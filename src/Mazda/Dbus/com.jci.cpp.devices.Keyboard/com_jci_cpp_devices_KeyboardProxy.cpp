#include "com_jci_cpp_devices_KeyboardProxy.h"

com_jci_cpp_devices_KeyboardProxy::com_jci_cpp_devices_KeyboardProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_enumerate = this->create_method < DBus::MultipleReturn < int32_t, std::vector < std::string >> ()
      > ("enumerate");
  m_method_keyClick = this->create_method<int32_t(std::string, int32_t, bool)>("keyClick");
  m_method_keyPress = this->create_method<int32_t(std::string, int32_t)>("keyPress");
  m_method_keyRelease = this->create_method<int32_t(std::string, int32_t)>("keyRelease");
  m_method_keySequence = this->create_method<int32_t(std::string, std::string)>("keySequence");

}
std::shared_ptr <com_jci_cpp_devices_KeyboardProxy> com_jci_cpp_devices_KeyboardProxy::create(std::string name) {
  return std::shared_ptr<com_jci_cpp_devices_KeyboardProxy>(new com_jci_cpp_devices_KeyboardProxy(name));

}
DBus::MultipleReturn <int32_t, std::vector<std::string>> com_jci_cpp_devices_KeyboardProxy::enumerate() {
  return (*m_method_enumerate)();

}
int32_t com_jci_cpp_devices_KeyboardProxy::keyClick(std::string name, int32_t code, bool shift) {
  return (*m_method_keyClick)(name, code, shift);

}
int32_t com_jci_cpp_devices_KeyboardProxy::keyPress(std::string name, int32_t code) {
  return (*m_method_keyPress)(name, code);

}
int32_t com_jci_cpp_devices_KeyboardProxy::keyRelease(std::string name, int32_t code) {
  return (*m_method_keyRelease)(name, code);

}
int32_t com_jci_cpp_devices_KeyboardProxy::keySequence(std::string name, std::string string) {
  return (*m_method_keySequence)(name, string);

}
