#include "com_jci_opera_IHU_PRIMARYProxy.h"

com_jci_opera_IHU_PRIMARYProxy::com_jci_opera_IHU_PRIMARYProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_TerminateOpera = this->create_method<void()>("TerminateOpera");
  m_method_Navigate = this->create_method<void(std::string)>("Navigate");
  m_method_GoBack = this->create_method<void()>("GoBack");
  m_method_GoForward = this->create_method<void()>("GoForward");
  m_method_Refresh = this->create_method<void()>("Refresh");
  m_signalproxy_ReportError = this->create_signal<void(std::string)>("ReportError");

}
std::shared_ptr <com_jci_opera_IHU_PRIMARYProxy> com_jci_opera_IHU_PRIMARYProxy::create(std::string name) {
  return std::shared_ptr<com_jci_opera_IHU_PRIMARYProxy>(new com_jci_opera_IHU_PRIMARYProxy(name));

}
void com_jci_opera_IHU_PRIMARYProxy::TerminateOpera() {
  (*m_method_TerminateOpera)();

}
void com_jci_opera_IHU_PRIMARYProxy::Navigate(std::string uRL) {
  (*m_method_Navigate)(uRL);

}
void com_jci_opera_IHU_PRIMARYProxy::GoBack() {
  (*m_method_GoBack)();

}
void com_jci_opera_IHU_PRIMARYProxy::GoForward() {
  (*m_method_GoForward)();

}
void com_jci_opera_IHU_PRIMARYProxy::Refresh() {
  (*m_method_Refresh)();

}
std::shared_ptr <DBus::SignalProxy<void(std::string)>> com_jci_opera_IHU_PRIMARYProxy::signal_ReportError() {
  return m_signalproxy_ReportError;

}
