#include "com_jci_btmusic_objectProxy.h"

com_jci_btmusic_objectProxy::com_jci_btmusic_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                         std::string dest,
                                                         std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_btmusicProxy = com_jci_btmusicProxy::create("com.jci.btmusic");
  this->add_interface(m_com_jci_btmusicProxy);

}
std::shared_ptr <com_jci_btmusic_objectProxy> com_jci_btmusic_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                  std::string dest,
                                                                                  std::string path,
                                                                                  DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_btmusic_objectProxy>
      created = std::shared_ptr<com_jci_btmusic_objectProxy>(new com_jci_btmusic_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_btmusicProxy> com_jci_btmusic_objectProxy::getcom_jci_btmusicInterface() {
  return m_com_jci_btmusicProxy;

}
