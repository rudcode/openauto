#include "com_jci_blmsystem_Interface_objectProxy.h"

com_jci_blmsystem_Interface_objectProxy::com_jci_blmsystem_Interface_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                                                 std::string dest,
                                                                                 std::string path) : DBus::ObjectProxy(
    conn,
    dest,
    path) {
  m_com_jci_blmsystem_InterfaceProxy = com_jci_blmsystem_InterfaceProxy::create("com.jci.blmsystem.Interface");
  this->add_interface(m_com_jci_blmsystem_InterfaceProxy);

}
std::shared_ptr <com_jci_blmsystem_Interface_objectProxy> com_jci_blmsystem_Interface_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                                          std::string dest,
                                                                                                          std::string path,
                                                                                                          DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_blmsystem_Interface_objectProxy> created =
      std::shared_ptr<com_jci_blmsystem_Interface_objectProxy>(new com_jci_blmsystem_Interface_objectProxy(conn,
                                                                                                           dest,
                                                                                                           path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_blmsystem_InterfaceProxy> com_jci_blmsystem_Interface_objectProxy::getcom_jci_blmsystem_InterfaceInterface() {
  return m_com_jci_blmsystem_InterfaceProxy;

}
