#include "com_jci_xm_mgr_objectProxy.h"

com_jci_xm_mgr_objectProxy::com_jci_xm_mgr_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                       std::string dest,
                                                       std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_xm_mgrProxy = com_jci_xm_mgrProxy::create("com.jci.xm_mgr");
  this->add_interface(m_com_jci_xm_mgrProxy);

}
std::shared_ptr <com_jci_xm_mgr_objectProxy> com_jci_xm_mgr_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                std::string dest,
                                                                                std::string path,
                                                                                DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_xm_mgr_objectProxy>
      created = std::shared_ptr<com_jci_xm_mgr_objectProxy>(new com_jci_xm_mgr_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_xm_mgrProxy> com_jci_xm_mgr_objectProxy::getcom_jci_xm_mgrInterface() {
  return m_com_jci_xm_mgrProxy;

}
