#include "com_jci_cpp_devices_GpioProxy.h"

com_jci_cpp_devices_GpioProxy::com_jci_cpp_devices_GpioProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_enumerate = this->create_method < DBus::MultipleReturn < int32_t, std::vector < std::string >> ()
      > ("enumerate");
  m_method_getValue = this->create_method<DBus::MultipleReturn<int32_t, bool>(std::string)>("getValue");
  m_method_setValue = this->create_method<DBus::MultipleReturn<int32_t, bool>(std::string, bool)>("setValue");

}
std::shared_ptr <com_jci_cpp_devices_GpioProxy> com_jci_cpp_devices_GpioProxy::create(std::string name) {
  return std::shared_ptr<com_jci_cpp_devices_GpioProxy>(new com_jci_cpp_devices_GpioProxy(name));

}
DBus::MultipleReturn <int32_t, std::vector<std::string>> com_jci_cpp_devices_GpioProxy::enumerate() {
  return (*m_method_enumerate)();

}
DBus::MultipleReturn<int32_t, bool> com_jci_cpp_devices_GpioProxy::getValue(std::string name) {
  return (*m_method_getValue)(name);

}
DBus::MultipleReturn<int32_t, bool> com_jci_cpp_devices_GpioProxy::setValue(std::string name, bool value) {
  return (*m_method_setValue)(name, value);

}
