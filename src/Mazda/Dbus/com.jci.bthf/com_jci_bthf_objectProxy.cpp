#include "com_jci_bthf_objectProxy.h"

com_jci_bthf_objectProxy::com_jci_bthf_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                   std::string dest,
                                                   std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_bthfProxy = com_jci_bthfProxy::create("com.jci.bthf");
  this->add_interface(m_com_jci_bthfProxy);

}
std::shared_ptr <com_jci_bthf_objectProxy> com_jci_bthf_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                            std::string dest,
                                                                            std::string path,
                                                                            DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_bthf_objectProxy>
      created = std::shared_ptr<com_jci_bthf_objectProxy>(new com_jci_bthf_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_bthfProxy> com_jci_bthf_objectProxy::getcom_jci_bthfInterface() {
  return m_com_jci_bthfProxy;

}
