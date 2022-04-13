#include "com_jci_cpp_settings_RegistryProxy.h"

com_jci_cpp_settings_RegistryProxy::com_jci_cpp_settings_RegistryProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_addNode = this->create_method<void(std::string)>("addNode");
  m_method_getNode = this->create_method<void(std::string)>("getNode");
  m_method_restoreNode = this->create_method<void(std::string)>("restoreNode");
  m_method_setNode = this->create_method<void(std::string)>("setNode");

}
std::shared_ptr <com_jci_cpp_settings_RegistryProxy> com_jci_cpp_settings_RegistryProxy::create(std::string name) {
  return std::shared_ptr<com_jci_cpp_settings_RegistryProxy>(new com_jci_cpp_settings_RegistryProxy(name));

}
void com_jci_cpp_settings_RegistryProxy::addNode(std::string path) {
  (*m_method_addNode)(path);

}
void com_jci_cpp_settings_RegistryProxy::getNode(std::string path) {
  (*m_method_getNode)(path);

}
void com_jci_cpp_settings_RegistryProxy::restoreNode(std::string path) {
  (*m_method_restoreNode)(path);

}
void com_jci_cpp_settings_RegistryProxy::setNode(std::string path) {
  (*m_method_setNode)(path);

}
