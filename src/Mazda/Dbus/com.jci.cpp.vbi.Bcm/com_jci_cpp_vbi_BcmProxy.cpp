#include "com_jci_cpp_vbi_BcmProxy.h"

com_jci_cpp_vbi_BcmProxy::com_jci_cpp_vbi_BcmProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_getSpeed = this->create_method<uint32_t()>("getSpeed");
  m_method_getBoogie = this->create_method<uint32_t()>("getBoogie");

}
std::shared_ptr <com_jci_cpp_vbi_BcmProxy> com_jci_cpp_vbi_BcmProxy::create(std::string name) {
  return std::shared_ptr<com_jci_cpp_vbi_BcmProxy>(new com_jci_cpp_vbi_BcmProxy(name));

}
uint32_t com_jci_cpp_vbi_BcmProxy::getSpeed() {
  return (*m_method_getSpeed)();

}
uint32_t com_jci_cpp_vbi_BcmProxy::getBoogie() {
  return (*m_method_getBoogie)();

}
