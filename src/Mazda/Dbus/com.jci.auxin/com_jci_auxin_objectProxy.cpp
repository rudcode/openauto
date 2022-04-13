#include "com_jci_auxin_objectProxy.h"

com_jci_auxin_objectProxy::com_jci_auxin_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                     std::string dest,
                                                     std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_auxinProxy = com_jci_auxinProxy::create("com.jci.auxin");
  this->add_interface(m_com_jci_auxinProxy);

}
std::shared_ptr <com_jci_auxin_objectProxy> com_jci_auxin_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                              std::string dest,
                                                                              std::string path,
                                                                              DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_auxin_objectProxy>
      created = std::shared_ptr<com_jci_auxin_objectProxy>(new com_jci_auxin_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_auxinProxy> com_jci_auxin_objectProxy::getcom_jci_auxinInterface() {
  return m_com_jci_auxinProxy;

}
