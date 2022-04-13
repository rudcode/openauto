#include "com_jci_ttsProxy.h"

com_jci_ttsProxy::com_jci_ttsProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_ConnectToTTS = this->create_method<int32_t(std::string)>("ConnectToTTS");
  m_method_DisconnectFromTTS = this->create_method<int32_t(std::string)>("DisconnectFromTTS");
  m_method_PlayText = this->create_method<void(std::string, std::string)>("PlayText");
  m_method_PausePlayback = this->create_method<void(std::string)>("PausePlayback");
  m_method_ResumePlayback = this->create_method<void(std::string)>("ResumePlayback");
  m_method_AbortPlayback = this->create_method<void(std::string)>("AbortPlayback");
  m_signalproxy_Status = this->create_signal<void(int32_t)>("Status");

}
std::shared_ptr <com_jci_ttsProxy> com_jci_ttsProxy::create(std::string name) {
  return std::shared_ptr<com_jci_ttsProxy>(new com_jci_ttsProxy(name));

}
int32_t com_jci_ttsProxy::ConnectToTTS(std::string clientName) {
  return (*m_method_ConnectToTTS)(clientName);

}
int32_t com_jci_ttsProxy::DisconnectFromTTS(std::string clientName) {
  return (*m_method_DisconnectFromTTS)(clientName);

}
void com_jci_ttsProxy::PlayText(std::string clientName, std::string string) {
  (*m_method_PlayText)(clientName, string);

}
void com_jci_ttsProxy::PausePlayback(std::string clientName) {
  (*m_method_PausePlayback)(clientName);

}
void com_jci_ttsProxy::ResumePlayback(std::string clientName) {
  (*m_method_ResumePlayback)(clientName);

}
void com_jci_ttsProxy::AbortPlayback(std::string clientName) {
  (*m_method_AbortPlayback)(clientName);

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_ttsProxy::signal_Status() {
  return m_signalproxy_Status;

}
