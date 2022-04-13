#include "com_jci_bds_objectProxy.h"

com_jci_bds_objectProxy::com_jci_bds_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                 std::string dest,
                                                 std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_bdsProxy = com_jci_bdsProxy::create("com.jci.bds");
  this->add_interface(m_com_jci_bdsProxy);

}
std::shared_ptr <com_jci_bds_objectProxy> com_jci_bds_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                          std::string dest,
                                                                          std::string path,
                                                                          DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_bds_objectProxy>
      created = std::shared_ptr<com_jci_bds_objectProxy>(new com_jci_bds_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_bdsProxy> com_jci_bds_objectProxy::getcom_jci_bdsInterface() {
  return m_com_jci_bdsProxy;

}
