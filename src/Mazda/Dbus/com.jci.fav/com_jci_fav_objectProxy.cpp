#include "com_jci_fav_objectProxy.h"

com_jci_fav_objectProxy::com_jci_fav_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                 std::string dest,
                                                 std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_favProxy = com_jci_favProxy::create("com.jci.fav");
  this->add_interface(m_com_jci_favProxy);

}
std::shared_ptr <com_jci_fav_objectProxy> com_jci_fav_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                          std::string dest,
                                                                          std::string path,
                                                                          DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_fav_objectProxy>
      created = std::shared_ptr<com_jci_fav_objectProxy>(new com_jci_fav_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_favProxy> com_jci_fav_objectProxy::getcom_jci_favInterface() {
  return m_com_jci_favProxy;

}
