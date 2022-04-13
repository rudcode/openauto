#include "com_jci_vdtcon_objectProxy.h"

com_jci_vdtcon_objectProxy::com_jci_vdtcon_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                       std::string dest,
                                                       std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_vdtconProxy = com_jci_vdtconProxy::create("com.jci.vdtcon");
  this->add_interface(m_com_jci_vdtconProxy);

}
std::shared_ptr <com_jci_vdtcon_objectProxy> com_jci_vdtcon_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                std::string dest,
                                                                                std::string path,
                                                                                DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_vdtcon_objectProxy>
      created = std::shared_ptr<com_jci_vdtcon_objectProxy>(new com_jci_vdtcon_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_vdtconProxy> com_jci_vdtcon_objectProxy::getcom_jci_vdtconInterface() {
  return m_com_jci_vdtconProxy;

}
