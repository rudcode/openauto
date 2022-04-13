#include "com_jci_idm_objectProxy.h"

com_jci_idm_objectProxy::com_jci_idm_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                 std::string dest,
                                                 std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_idmProxy = com_jci_idmProxy::create("com.jci.idm");
  this->add_interface(m_com_jci_idmProxy);

}
std::shared_ptr <com_jci_idm_objectProxy> com_jci_idm_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                          std::string dest,
                                                                          std::string path,
                                                                          DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_idm_objectProxy>
      created = std::shared_ptr<com_jci_idm_objectProxy>(new com_jci_idm_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_idmProxy> com_jci_idm_objectProxy::getcom_jci_idmInterface() {
  return m_com_jci_idmProxy;

}
