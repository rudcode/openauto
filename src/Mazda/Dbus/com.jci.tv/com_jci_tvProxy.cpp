#include "com_jci_tvProxy.h"

com_jci_tvProxy::com_jci_tvProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_SourceSelect = this->create_method<uint32_t()>("SourceSelect");
  m_method_UIStatus = this->create_method<void(uint32_t)>("UIStatus");
  m_method_EmBroControl = this->create_method<void(uint32_t)>("EmBroControl");
  m_method_handShakeRequest =
      this->create_method<std::tuple<uint32_t, uint32_t, uint32_t, uint32_t>()>("handShakeRequest");
  m_signalproxy_TvEvent = this->create_signal<void(uint32_t)>("TvEvent");

}
std::shared_ptr <com_jci_tvProxy> com_jci_tvProxy::create(std::string name) {
  return std::shared_ptr<com_jci_tvProxy>(new com_jci_tvProxy(name));

}
uint32_t com_jci_tvProxy::SourceSelect() {
  return (*m_method_SourceSelect)();

}
void com_jci_tvProxy::UIStatus(uint32_t uiStatusUpdate) {
  (*m_method_UIStatus)(uiStatusUpdate);

}
void com_jci_tvProxy::EmBroControl(uint32_t emBroOption) {
  (*m_method_EmBroControl)(emBroOption);

}
std::tuple <uint32_t, uint32_t, uint32_t, uint32_t> com_jci_tvProxy::handShakeRequest() {
  return (*m_method_handShakeRequest)();

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_tvProxy::signal_TvEvent() {
  return m_signalproxy_TvEvent;

}
