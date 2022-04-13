#ifndef COM_JCI_TTS_LANGUAGEPROXY_H
#define COM_JCI_TTS_LANGUAGEPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_tts_languageProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_tts_languageProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_tts_languageProxy> create(std::string name = "com.jci.tts.language");
  void SetLanguage(int32_t language);
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_LanguageChangedCallback();
 protected:
  std::shared_ptr<DBus::MethodProxy<void(int32_t)>> m_method_SetLanguage;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_LanguageChangedCallback;
};
#endif /* COM_JCI_TTS_LANGUAGEPROXY_H */
