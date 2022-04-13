#include "com_jci_directProxy.h"

com_jci_directProxy::com_jci_directProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_GetDirectConnection = this->create_method<std::string()>("GetDirectConnection");

}
std::shared_ptr <com_jci_directProxy> com_jci_directProxy::create(std::string name) {
  return std::shared_ptr<com_jci_directProxy>(new com_jci_directProxy(name));

}
std::string com_jci_directProxy::GetDirectConnection() {
  return (*m_method_GetDirectConnection)();

}
