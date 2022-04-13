#include "com_jci_tts_language_objectProxy.h"

com_jci_tts_language_objectProxy::com_jci_tts_language_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                                   std::string dest,
                                                                   std::string path) : DBus::ObjectProxy(conn,
                                                                                                         dest,
                                                                                                         path) {
  m_com_jci_tts_languageProxy = com_jci_tts_languageProxy::create("com.jci.tts.language");
  this->add_interface(m_com_jci_tts_languageProxy);

}
std::shared_ptr <com_jci_tts_language_objectProxy> com_jci_tts_language_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                            std::string dest,
                                                                                            std::string path,
                                                                                            DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_tts_language_objectProxy> created =
      std::shared_ptr<com_jci_tts_language_objectProxy>(new com_jci_tts_language_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_tts_languageProxy> com_jci_tts_language_objectProxy::getcom_jci_tts_languageInterface() {
  return m_com_jci_tts_languageProxy;

}
