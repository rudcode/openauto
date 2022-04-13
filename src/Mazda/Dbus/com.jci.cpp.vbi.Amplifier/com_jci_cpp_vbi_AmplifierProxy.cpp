#include "com_jci_cpp_vbi_AmplifierProxy.h"

com_jci_cpp_vbi_AmplifierProxy::com_jci_cpp_vbi_AmplifierProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_getVolume = this->create_method<uint32_t()>("getVolume");
  m_method_setVolume = this->create_method<void(uint32_t)>("setVolume");

}
std::shared_ptr <com_jci_cpp_vbi_AmplifierProxy> com_jci_cpp_vbi_AmplifierProxy::create(std::string name) {
  return std::shared_ptr<com_jci_cpp_vbi_AmplifierProxy>(new com_jci_cpp_vbi_AmplifierProxy(name));

}
uint32_t com_jci_cpp_vbi_AmplifierProxy::getVolume() {
  return (*m_method_getVolume)();

}
void com_jci_cpp_vbi_AmplifierProxy::setVolume(uint32_t level) {
  (*m_method_setVolume)(level);

}
