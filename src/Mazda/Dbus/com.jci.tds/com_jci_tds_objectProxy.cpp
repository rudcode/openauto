#include "com_jci_tds_objectProxy.h"

com_jci_tds_objectProxy::com_jci_tds_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                 std::string dest,
                                                 std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_tdsProxy = com_jci_tdsProxy::create("com.jci.tds");
  this->add_interface(m_com_jci_tdsProxy);

}
std::shared_ptr <com_jci_tds_objectProxy> com_jci_tds_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                          std::string dest,
                                                                          std::string path,
                                                                          DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_tds_objectProxy>
      created = std::shared_ptr<com_jci_tds_objectProxy>(new com_jci_tds_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_tdsProxy> com_jci_tds_objectProxy::getcom_jci_tdsInterface() {
  return m_com_jci_tdsProxy;

}
