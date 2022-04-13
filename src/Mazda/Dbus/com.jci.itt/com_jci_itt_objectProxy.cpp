#include "com_jci_itt_objectProxy.h"

com_jci_itt_objectProxy::com_jci_itt_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                 std::string dest,
                                                 std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_ittProxy = com_jci_ittProxy::create("com.jci.itt");
  this->add_interface(m_com_jci_ittProxy);

}
std::shared_ptr <com_jci_itt_objectProxy> com_jci_itt_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                          std::string dest,
                                                                          std::string path,
                                                                          DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_itt_objectProxy>
      created = std::shared_ptr<com_jci_itt_objectProxy>(new com_jci_itt_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_ittProxy> com_jci_itt_objectProxy::getcom_jci_ittInterface() {
  return m_com_jci_ittProxy;

}
