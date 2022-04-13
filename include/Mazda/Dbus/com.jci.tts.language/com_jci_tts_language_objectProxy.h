#ifndef COM_JCI_TTS_LANGUAGE_OBJECTPROXY_H
#define COM_JCI_TTS_LANGUAGE_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_tts_languageProxy.h"
class com_jci_tts_language_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_tts_language_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_tts_language_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                                  std::string dest,
                                                                  std::string path,
                                                                  DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_tts_languageProxy> getcom_jci_tts_languageInterface();
 protected:
  std::shared_ptr<com_jci_tts_languageProxy> m_com_jci_tts_languageProxy;
};
#endif /* COM_JCI_TTS_LANGUAGE_OBJECTPROXY_H */
