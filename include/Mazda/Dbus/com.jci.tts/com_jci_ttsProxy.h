#ifndef COM_JCI_TTSPROXY_H
#define COM_JCI_TTSPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_ttsProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_ttsProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_ttsProxy> create(std::string name = "com.jci.tts");
  int32_t ConnectToTTS(std::string clientName);
  int32_t DisconnectFromTTS(std::string clientName);
  void PlayText(std::string clientName, std::string string);
  void PausePlayback(std::string clientName);
  void ResumePlayback(std::string clientName);
  void AbortPlayback(std::string clientName);
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_Status();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t(std::string)>> m_method_ConnectToTTS;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::string)>> m_method_DisconnectFromTTS;
  std::shared_ptr<DBus::MethodProxy<void(std::string, std::string)>> m_method_PlayText;
  std::shared_ptr<DBus::MethodProxy<void(std::string)>> m_method_PausePlayback;
  std::shared_ptr<DBus::MethodProxy<void(std::string)>> m_method_ResumePlayback;
  std::shared_ptr<DBus::MethodProxy<void(std::string)>> m_method_AbortPlayback;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_Status;
};
#endif /* COM_JCI_TTSPROXY_H */
