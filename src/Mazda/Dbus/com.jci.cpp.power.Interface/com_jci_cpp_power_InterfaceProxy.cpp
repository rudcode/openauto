#include "com_jci_cpp_power_InterfaceProxy.h"

com_jci_cpp_power_InterfaceProxy::com_jci_cpp_power_InterfaceProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_OpenConnection = this->create_method<DBus::MultipleReturn<int32_t, uint32_t>()>("OpenConnection");
  m_method_CloseConnection = this->create_method<int32_t()>("CloseConnection");
  m_method_SafeShutDown = this->create_method<int32_t()>("SafeShutDown");
  m_method_SafeReboot = this->create_method<int32_t()>("SafeReboot");
  m_method_FactoryReset = this->create_method<int32_t()>("FactoryReset");
  m_method_GetCurrentAccStatus = this->create_method<DBus::MultipleReturn<int32_t, int32_t>()>("GetCurrentAccStatus");
  m_signalproxy_NotifyAccChange = this->create_signal<void(int32_t)>("NotifyAccChange");

}
std::shared_ptr <com_jci_cpp_power_InterfaceProxy> com_jci_cpp_power_InterfaceProxy::create(std::string name) {
  return std::shared_ptr<com_jci_cpp_power_InterfaceProxy>(new com_jci_cpp_power_InterfaceProxy(name));

}
DBus::MultipleReturn <int32_t, uint32_t> com_jci_cpp_power_InterfaceProxy::OpenConnection() {
  return (*m_method_OpenConnection)();

}
int32_t com_jci_cpp_power_InterfaceProxy::CloseConnection() {
  return (*m_method_CloseConnection)();

}
int32_t com_jci_cpp_power_InterfaceProxy::SafeShutDown() {
  return (*m_method_SafeShutDown)();

}
int32_t com_jci_cpp_power_InterfaceProxy::SafeReboot() {
  return (*m_method_SafeReboot)();

}
int32_t com_jci_cpp_power_InterfaceProxy::FactoryReset() {
  return (*m_method_FactoryReset)();

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_cpp_power_InterfaceProxy::GetCurrentAccStatus() {
  return (*m_method_GetCurrentAccStatus)();

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_cpp_power_InterfaceProxy::signal_NotifyAccChange() {
  return m_signalproxy_NotifyAccChange;

}
