#include "com_jci_vbs_navi_objectProxy.h"

com_jci_vbs_navi_objectProxy::com_jci_vbs_navi_objectProxy(std::shared_ptr<DBus::Connection> conn,
                                                           std::string dest,
                                                           std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_vbs_naviProxy = com_jci_vbs_naviProxy::create("com.jci.vbs.navi");
  this->add_interface(m_com_jci_vbs_naviProxy);

}
std::shared_ptr<com_jci_vbs_navi_objectProxy> com_jci_vbs_navi_objectProxy::create(std::shared_ptr<DBus::Connection> conn,
                                                                                   std::string dest,
                                                                                   std::string path,
                                                                                   DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr<com_jci_vbs_navi_objectProxy>
      created = std::shared_ptr<com_jci_vbs_navi_objectProxy>(new com_jci_vbs_navi_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr<com_jci_vbs_naviProxy> com_jci_vbs_navi_objectProxy::getcom_jci_vbs_naviInterface() {
  return m_com_jci_vbs_naviProxy;

}
