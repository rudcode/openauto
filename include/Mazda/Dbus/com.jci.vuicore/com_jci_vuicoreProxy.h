#ifndef COM_JCI_VUICOREPROXY_H
#define COM_JCI_VUICOREPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_vuicoreProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_vuicoreProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_vuicoreProxy> create(std::string name = "com.jci.vuicore");
  void SetParadigm(int32_t paradigm);
  void SetAppContext(std::tuple<int32_t, int32_t, uint32_t, uint32_t, std::vector<uint8_t>> appContext, int32_t action);
  void SendMessage(std::tuple<int32_t, int32_t, uint32_t, std::vector<uint8_t>> message);
  void StartReco(bool startOfSession);
  void AbortSession(int32_t action);
  void SetLang(int32_t language);
  void SendAlert(std::tuple<int32_t, int32_t, uint32_t, std::vector<uint8_t>> alert, int32_t alertAction);
  void SetTestMode(bool enableTestMode, bool enableNLU);
  void SetPrerecordedAudioFiles(std::string audioFileAttempt1,
                                std::string audioFileAttempt2,
                                std::string audioFileAttempt3);
  void AlertQueueEmpty();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t,
                                                    int32_t,
                                                    uint32_t,
                                                    std::vector<uint8_t>,
                                                    int32_t,
                                                    int32_t>)>> signal_AppEventCallback();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_LanguageChangedCallback();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_StateChangeCallback();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t, int32_t, int32_t>)>> signal_AlertCompleteCallback();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_MicLevelCallback();
 protected:
  std::shared_ptr<DBus::MethodProxy<void(int32_t)>> m_method_SetParadigm;
  std::shared_ptr<DBus::MethodProxy<void(std::tuple<int32_t, int32_t, uint32_t, uint32_t, std::vector<uint8_t>>,
                                         int32_t)>> m_method_SetAppContext;
  std::shared_ptr<DBus::MethodProxy<void(std::tuple<int32_t, int32_t, uint32_t, std::vector<uint8_t>>)>>
      m_method_SendMessage;
  std::shared_ptr<DBus::MethodProxy<void(bool)>> m_method_StartReco;
  std::shared_ptr<DBus::MethodProxy<void(int32_t)>> m_method_AbortSession;
  std::shared_ptr<DBus::MethodProxy<void(int32_t)>> m_method_SetLang;
  std::shared_ptr<DBus::MethodProxy<void(std::tuple<int32_t, int32_t, uint32_t, std::vector<uint8_t>>, int32_t)>>
      m_method_SendAlert;
  std::shared_ptr<DBus::MethodProxy<void(bool, bool)>> m_method_SetTestMode;
  std::shared_ptr<DBus::MethodProxy<void(std::string, std::string, std::string)>> m_method_SetPrerecordedAudioFiles;
  std::shared_ptr<DBus::MethodProxy<void()>> m_method_AlertQueueEmpty;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t,
                                                    int32_t,
                                                    uint32_t,
                                                    std::vector<uint8_t>,
                                                    int32_t,
                                                    int32_t>)>> m_signalproxy_AppEventCallback;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_LanguageChangedCallback;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_StateChangeCallback;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t, int32_t, int32_t>)>> m_signalproxy_AlertCompleteCallback;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_MicLevelCallback;
};
#endif /* COM_JCI_VUICOREPROXY_H */
