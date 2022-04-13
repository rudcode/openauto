#include "com_jci_vbs_diag_objectProxy.h"

com_jci_vbs_diag_objectProxy::com_jci_vbs_diag_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                           std::string dest,
                                                           std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_vbs_diagProxy = com_jci_vbs_diagProxy::create("com.jci.vbs.diag");
  this->add_interface(m_com_jci_vbs_diagProxy);

}
std::shared_ptr <com_jci_vbs_diag_objectProxy> com_jci_vbs_diag_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                    std::string dest,
                                                                                    std::string path,
                                                                                    DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_vbs_diag_objectProxy>
      created = std::shared_ptr<com_jci_vbs_diag_objectProxy>(new com_jci_vbs_diag_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_vbs_diagProxy> com_jci_vbs_diag_objectProxy::getcom_jci_vbs_diagInterface() {
  return m_com_jci_vbs_diagProxy;

}
