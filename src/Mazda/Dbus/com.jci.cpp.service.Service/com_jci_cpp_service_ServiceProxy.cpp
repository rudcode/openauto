#include "com_jci_cpp_service_ServiceProxy.h"

com_jci_cpp_service_ServiceProxy::com_jci_cpp_service_ServiceProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_ping = this->create_method<void(uint32_t)>("ping");
  m_method_save = this->create_method<void(uint32_t)>("save");
  m_method_start = this->create_method<void(uint32_t)>("start");
  m_method_stop = this->create_method<void(uint32_t)>("stop");

}
std::shared_ptr <com_jci_cpp_service_ServiceProxy> com_jci_cpp_service_ServiceProxy::create(std::string name) {
  return std::shared_ptr<com_jci_cpp_service_ServiceProxy>(new com_jci_cpp_service_ServiceProxy(name));

}
void com_jci_cpp_service_ServiceProxy::ping(uint32_t timeout) {
  (*m_method_ping)(timeout);

}
void com_jci_cpp_service_ServiceProxy::save(uint32_t timeout) {
  (*m_method_save)(timeout);

}
void com_jci_cpp_service_ServiceProxy::start(uint32_t timeout) {
  (*m_method_start)(timeout);

}
void com_jci_cpp_service_ServiceProxy::stop(uint32_t timeout) {
  (*m_method_stop)(timeout);

}
