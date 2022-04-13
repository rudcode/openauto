#include "com_jci_cpp_dbus_DbusConnectionProxy.h"

com_jci_cpp_dbus_DbusConnectionProxy::com_jci_cpp_dbus_DbusConnectionProxy(std::string name)
    : DBus::InterfaceProxy(name) {
  m_method_Wiki = this->create_method<void(uint32_t)>("Wiki");

}
std::shared_ptr <com_jci_cpp_dbus_DbusConnectionProxy> com_jci_cpp_dbus_DbusConnectionProxy::create(std::string name) {
  return std::shared_ptr<com_jci_cpp_dbus_DbusConnectionProxy>(new com_jci_cpp_dbus_DbusConnectionProxy(name));

}
void com_jci_cpp_dbus_DbusConnectionProxy::Wiki(uint32_t timeout) {
  (*m_method_Wiki)(timeout);

}
