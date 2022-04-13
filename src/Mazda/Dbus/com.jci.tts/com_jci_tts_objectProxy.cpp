#include "com_jci_tts_objectProxy.h"

com_jci_tts_objectProxy::com_jci_tts_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                 std::string dest,
                                                 std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_ttsProxy = com_jci_ttsProxy::create("com.jci.tts");
  this->add_interface(m_com_jci_ttsProxy);

}
std::shared_ptr <com_jci_tts_objectProxy> com_jci_tts_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                          std::string dest,
                                                                          std::string path,
                                                                          DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_tts_objectProxy>
      created = std::shared_ptr<com_jci_tts_objectProxy>(new com_jci_tts_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_ttsProxy> com_jci_tts_objectProxy::getcom_jci_ttsInterface() {
  return m_com_jci_ttsProxy;

}
