#include "com_jci_vdt_objectProxy.h"

com_jci_vdt_objectProxy::com_jci_vdt_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                 std::string dest,
                                                 std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_vdtProxy = com_jci_vdtProxy::create("com.jci.vdt");
  this->add_interface(m_com_jci_vdtProxy);

}
std::shared_ptr <com_jci_vdt_objectProxy> com_jci_vdt_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                          std::string dest,
                                                                          std::string path,
                                                                          DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_vdt_objectProxy>
      created = std::shared_ptr<com_jci_vdt_objectProxy>(new com_jci_vdt_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_vdtProxy> com_jci_vdt_objectProxy::getcom_jci_vdtInterface() {
  return m_com_jci_vdtProxy;

}
