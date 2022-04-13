#include "com_jci_vbs_am_objectProxy.h"

com_jci_vbs_am_objectProxy::com_jci_vbs_am_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                       std::string dest,
                                                       std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_vbs_amProxy = com_jci_vbs_amProxy::create("com.jci.vbs.am");
  this->add_interface(m_com_jci_vbs_amProxy);

}
std::shared_ptr <com_jci_vbs_am_objectProxy> com_jci_vbs_am_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                std::string dest,
                                                                                std::string path,
                                                                                DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_vbs_am_objectProxy>
      created = std::shared_ptr<com_jci_vbs_am_objectProxy>(new com_jci_vbs_am_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_vbs_amProxy> com_jci_vbs_am_objectProxy::getcom_jci_vbs_amInterface() {
  return m_com_jci_vbs_amProxy;

}
