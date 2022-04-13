#include "com_jci_vwm_objectProxy.h"

com_jci_vwm_objectProxy::com_jci_vwm_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                 std::string dest,
                                                 std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_vwmProxy = com_jci_vwmProxy::create("com.jci.vwm");
  this->add_interface(m_com_jci_vwmProxy);

}
std::shared_ptr <com_jci_vwm_objectProxy> com_jci_vwm_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                          std::string dest,
                                                                          std::string path,
                                                                          DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_vwm_objectProxy>
      created = std::shared_ptr<com_jci_vwm_objectProxy>(new com_jci_vwm_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_vwmProxy> com_jci_vwm_objectProxy::getcom_jci_vwmInterface() {
  return m_com_jci_vwmProxy;

}
