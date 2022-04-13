#include "com_jci_auxinProxy.h"

com_jci_auxinProxy::com_jci_auxinProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_Mode_Req = this->create_method<int32_t(uint8_t)>("Mode_Req");
  m_method_DeviceStatus_Req = this->create_method<int32_t()>("DeviceStatus_Req");
  m_method_GetAuxinStatus = this->create_method<int32_t()>("GetAuxinStatus");
  m_signalproxy_Status = this->create_signal<void(uint8_t)>("Status");

}
std::shared_ptr <com_jci_auxinProxy> com_jci_auxinProxy::create(std::string name) {
  return std::shared_ptr<com_jci_auxinProxy>(new com_jci_auxinProxy(name));

}
int32_t com_jci_auxinProxy::Mode_Req(uint8_t mode) {
  return (*m_method_Mode_Req)(mode);

}
int32_t com_jci_auxinProxy::DeviceStatus_Req() {
  return (*m_method_DeviceStatus_Req)();

}
int32_t com_jci_auxinProxy::GetAuxinStatus() {
  return (*m_method_GetAuxinStatus)();

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_auxinProxy::signal_Status() {
  return m_signalproxy_Status;

}
