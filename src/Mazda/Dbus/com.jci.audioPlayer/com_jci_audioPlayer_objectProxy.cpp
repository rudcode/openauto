#include "com_jci_audioPlayer_objectProxy.h"

com_jci_audioPlayer_objectProxy::com_jci_audioPlayer_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                                 std::string dest,
                                                                 std::string path) : DBus::ObjectProxy(conn,
                                                                                                       dest,
                                                                                                       path) {
  m_com_jci_audioPlayerProxy = com_jci_audioPlayerProxy::create("com.jci.audioPlayer");
  this->add_interface(m_com_jci_audioPlayerProxy);

}
std::shared_ptr <com_jci_audioPlayer_objectProxy> com_jci_audioPlayer_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                          std::string dest,
                                                                                          std::string path,
                                                                                          DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_audioPlayer_objectProxy>
      created = std::shared_ptr<com_jci_audioPlayer_objectProxy>(new com_jci_audioPlayer_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_audioPlayerProxy> com_jci_audioPlayer_objectProxy::getcom_jci_audioPlayerInterface() {
  return m_com_jci_audioPlayerProxy;

}
