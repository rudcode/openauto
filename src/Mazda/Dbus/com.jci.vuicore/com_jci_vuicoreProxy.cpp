#include "com_jci_vuicoreProxy.h"

com_jci_vuicoreProxy::com_jci_vuicoreProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_SetParadigm = this->create_method<void(int32_t)>("SetParadigm");
  m_method_SetAppContext =
      this->create_method<void(std::tuple < int32_t, int32_t, uint32_t, uint32_t, std::vector < uint8_t >> , int32_t)>(
          "SetAppContext");
  m_method_SendMessage =
      this->create_method<void(std::tuple < int32_t, int32_t, uint32_t, std::vector < uint8_t >> )>("SendMessage");
  m_method_StartReco = this->create_method<void(bool)>("StartReco");
  m_method_AbortSession = this->create_method<void(int32_t)>("AbortSession");
  m_method_SetLang = this->create_method<void(int32_t)>("SetLang");
  m_method_SendAlert = this->create_method<void(std::tuple < int32_t,
                                                int32_t,
                                                uint32_t,
                                                std::vector < uint8_t >> ,
                                                int32_t)>("SendAlert");
  m_method_SetTestMode = this->create_method<void(bool, bool)>("SetTestMode");
  m_method_SetPrerecordedAudioFiles =
      this->create_method<void(std::string, std::string, std::string)>("SetPrerecordedAudioFiles");
  m_method_AlertQueueEmpty = this->create_method<void()>("AlertQueueEmpty");
  m_signalproxy_AppEventCallback =
      this->create_signal<void(std::tuple < int32_t, int32_t, uint32_t, std::vector < uint8_t > , int32_t, int32_t > )>(
          "AppEventCallback");
  m_signalproxy_LanguageChangedCallback = this->create_signal<void(int32_t)>("LanguageChangedCallback");
  m_signalproxy_StateChangeCallback = this->create_signal<void(int32_t)>("StateChangeCallback");
  m_signalproxy_AlertCompleteCallback =
      this->create_signal<void(std::tuple < int32_t, int32_t, int32_t > )>("AlertCompleteCallback");
  m_signalproxy_MicLevelCallback = this->create_signal<void(int32_t)>("MicLevelCallback");

}
std::shared_ptr <com_jci_vuicoreProxy> com_jci_vuicoreProxy::create(std::string name) {
  return std::shared_ptr<com_jci_vuicoreProxy>(new com_jci_vuicoreProxy(name));

}
void com_jci_vuicoreProxy::SetParadigm(int32_t paradigm) {
  (*m_method_SetParadigm)(paradigm);

}
void com_jci_vuicoreProxy::SetAppContext(std::tuple <int32_t, int32_t, uint32_t, uint32_t, std::vector<uint8_t>> appContext,
                                         int32_t action) {
  (*m_method_SetAppContext)(appContext, action);

}
void com_jci_vuicoreProxy::SendMessage(std::tuple <int32_t, int32_t, uint32_t, std::vector<uint8_t>> message) {
  (*m_method_SendMessage)(message);

}
void com_jci_vuicoreProxy::StartReco(bool startOfSession) {
  (*m_method_StartReco)(startOfSession);

}
void com_jci_vuicoreProxy::AbortSession(int32_t action) {
  (*m_method_AbortSession)(action);

}
void com_jci_vuicoreProxy::SetLang(int32_t language) {
  (*m_method_SetLang)(language);

}
void com_jci_vuicoreProxy::SendAlert(std::tuple <int32_t, int32_t, uint32_t, std::vector<uint8_t>> alert,
                                     int32_t alertAction) {
  (*m_method_SendAlert)(alert, alertAction);

}
void com_jci_vuicoreProxy::SetTestMode(bool enableTestMode, bool enableNLU) {
  (*m_method_SetTestMode)(enableTestMode, enableNLU);

}
void com_jci_vuicoreProxy::SetPrerecordedAudioFiles(std::string audioFileAttempt1,
                                                    std::string audioFileAttempt2,
                                                    std::string audioFileAttempt3) {
  (*m_method_SetPrerecordedAudioFiles)(audioFileAttempt1, audioFileAttempt2, audioFileAttempt3);

}
void com_jci_vuicoreProxy::AlertQueueEmpty() {
  (*m_method_AlertQueueEmpty)();

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < int32_t,
                                        int32_t,
                                        uint32_t,
                                        std::vector < uint8_t > ,
                                        int32_t,
                                        int32_t > )>> com_jci_vuicoreProxy::signal_AppEventCallback() {
  return m_signalproxy_AppEventCallback;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_vuicoreProxy::signal_LanguageChangedCallback() {
  return m_signalproxy_LanguageChangedCallback;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_vuicoreProxy::signal_StateChangeCallback() {
  return m_signalproxy_StateChangeCallback;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < int32_t,
                                        int32_t,
                                        int32_t > )>> com_jci_vuicoreProxy::signal_AlertCompleteCallback() {
  return m_signalproxy_AlertCompleteCallback;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_vuicoreProxy::signal_MicLevelCallback() {
  return m_signalproxy_MicLevelCallback;

}
