#include "com_jci_dab_objectProxy.h"

com_jci_dab_objectProxy::com_jci_dab_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                 std::string dest,
                                                 std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_dabProxy = com_jci_dabProxy::create("com.jci.dab");
  this->add_interface(m_com_jci_dabProxy);

}
std::shared_ptr <com_jci_dab_objectProxy> com_jci_dab_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                          std::string dest,
                                                                          std::string path,
                                                                          DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_dab_objectProxy>
      created = std::shared_ptr<com_jci_dab_objectProxy>(new com_jci_dab_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_dabProxy> com_jci_dab_objectProxy::getcom_jci_dabInterface() {
  return m_com_jci_dabProxy;

}
