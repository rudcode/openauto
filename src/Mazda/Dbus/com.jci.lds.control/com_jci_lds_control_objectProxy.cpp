#include "com_jci_lds_control_objectProxy.h"

com_jci_lds_control_objectProxy::com_jci_lds_control_objectProxy(std::shared_ptr<DBus::Connection> conn,
                                                                 std::string dest,
                                                                 std::string path) : DBus::ObjectProxy(conn,
                                                                                                       dest,
                                                                                                       path) {
  m_com_jci_lds_controlProxy = com_jci_lds_controlProxy::create("com.jci.lds.control");
  this->add_interface(m_com_jci_lds_controlProxy);

}
std::shared_ptr<com_jci_lds_control_objectProxy> com_jci_lds_control_objectProxy::create(std::shared_ptr<DBus::Connection> conn,
                                                                                         std::string dest,
                                                                                         std::string path,
                                                                                         DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr<com_jci_lds_control_objectProxy>
      created = std::shared_ptr<com_jci_lds_control_objectProxy>(new com_jci_lds_control_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr<com_jci_lds_controlProxy> com_jci_lds_control_objectProxy::getcom_jci_lds_controlInterface() {
  return m_com_jci_lds_controlProxy;

}
