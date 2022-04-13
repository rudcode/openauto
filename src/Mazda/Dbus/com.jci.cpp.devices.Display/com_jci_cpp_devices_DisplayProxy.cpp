#include "com_jci_cpp_devices_DisplayProxy.h"

com_jci_cpp_devices_DisplayProxy::com_jci_cpp_devices_DisplayProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_enumerate = this->create_method < DBus::MultipleReturn < int32_t, std::vector < std::string >> ()
      > ("enumerate");
  m_method_getContrast = this->create_method<DBus::MultipleReturn<int32_t, uint16_t>(std::string)>("getContrast");
  m_method_getContrastSteps =
      this->create_method<DBus::MultipleReturn<int32_t, uint16_t>(std::string)>("getContrastSteps");
  m_method_setContrast = this->create_method<DBus::MultipleReturn<int32_t, bool>(std::string, uint16_t)>("setContrast");

}
std::shared_ptr <com_jci_cpp_devices_DisplayProxy> com_jci_cpp_devices_DisplayProxy::create(std::string name) {
  return std::shared_ptr<com_jci_cpp_devices_DisplayProxy>(new com_jci_cpp_devices_DisplayProxy(name));

}
DBus::MultipleReturn <int32_t, std::vector<std::string>> com_jci_cpp_devices_DisplayProxy::enumerate() {
  return (*m_method_enumerate)();

}
DBus::MultipleReturn <int32_t, uint16_t> com_jci_cpp_devices_DisplayProxy::getContrast(std::string name) {
  return (*m_method_getContrast)(name);

}
DBus::MultipleReturn <int32_t, uint16_t> com_jci_cpp_devices_DisplayProxy::getContrastSteps(std::string name) {
  return (*m_method_getContrastSteps)(name);

}
DBus::MultipleReturn<int32_t, bool> com_jci_cpp_devices_DisplayProxy::setContrast(std::string name, uint16_t contrast) {
  return (*m_method_setContrast)(name, contrast);

}
