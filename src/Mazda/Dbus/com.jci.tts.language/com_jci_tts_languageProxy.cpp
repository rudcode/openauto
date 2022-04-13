#include "com_jci_tts_languageProxy.h"

com_jci_tts_languageProxy::com_jci_tts_languageProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_SetLanguage = this->create_method<void(int32_t)>("SetLanguage");
  m_signalproxy_LanguageChangedCallback = this->create_signal<void(int32_t)>("LanguageChangedCallback");

}
std::shared_ptr <com_jci_tts_languageProxy> com_jci_tts_languageProxy::create(std::string name) {
  return std::shared_ptr<com_jci_tts_languageProxy>(new com_jci_tts_languageProxy(name));

}
void com_jci_tts_languageProxy::SetLanguage(int32_t language) {
  (*m_method_SetLanguage)(language);

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_tts_languageProxy::signal_LanguageChangedCallback() {
  return m_signalproxy_LanguageChangedCallback;

}
