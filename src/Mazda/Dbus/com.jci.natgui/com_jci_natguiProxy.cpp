#include "com_jci_natguiProxy.h"

com_jci_natguiProxy::com_jci_natguiProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_SetDisplay =
      this->create_method<int32_t(std::tuple < std::vector < uint32_t > , uint32_t, uint32_t > )>("SetDisplay");
  m_method_SetLanguage_async = this->create_method<int32_t(uint32_t)>("SetLanguage_async");
  m_signalproxy_LanguageSetStatus = this->create_signal<void(uint32_t, uint32_t)>("LanguageSetStatus");

}
std::shared_ptr <com_jci_natguiProxy> com_jci_natguiProxy::create(std::string name) {
  return std::shared_ptr<com_jci_natguiProxy>(new com_jci_natguiProxy(name));

}
int32_t com_jci_natguiProxy::SetDisplay(std::tuple <std::vector<uint32_t>, uint32_t, uint32_t> imageData) {
  return (*m_method_SetDisplay)(imageData);

}
int32_t com_jci_natguiProxy::SetLanguage_async(uint32_t currentLanguage) {
  return (*m_method_SetLanguage_async)(currentLanguage);

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, uint32_t)>> com_jci_natguiProxy::signal_LanguageSetStatus() {
  return m_signalproxy_LanguageSetStatus;

}
