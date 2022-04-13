#include "com_jci_vbs_navi_tmc_objectProxy.h"

com_jci_vbs_navi_tmc_objectProxy::com_jci_vbs_navi_tmc_objectProxy(std::shared_ptr<DBus::Connection> conn,
                                                                   std::string dest,
                                                                   std::string path) : DBus::ObjectProxy(conn,
                                                                                                         dest,
                                                                                                         path) {
  m_com_jci_vbs_navi_tmcProxy = com_jci_vbs_navi_tmcProxy::create("com.jci.vbs.navi.tmc");
  this->add_interface(m_com_jci_vbs_navi_tmcProxy);

}
std::shared_ptr<com_jci_vbs_navi_tmc_objectProxy> com_jci_vbs_navi_tmc_objectProxy::create(std::shared_ptr<DBus::Connection> conn,
                                                                                           std::string dest,
                                                                                           std::string path,
                                                                                           DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr<com_jci_vbs_navi_tmc_objectProxy> created =
      std::shared_ptr<com_jci_vbs_navi_tmc_objectProxy>(new com_jci_vbs_navi_tmc_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr<com_jci_vbs_navi_tmcProxy> com_jci_vbs_navi_tmc_objectProxy::getcom_jci_vbs_navi_tmcInterface() {
  return m_com_jci_vbs_navi_tmcProxy;

}
