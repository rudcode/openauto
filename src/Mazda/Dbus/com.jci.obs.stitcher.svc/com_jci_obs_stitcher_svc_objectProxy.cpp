#include "com_jci_obs_stitcher_svc_objectProxy.h"

com_jci_obs_stitcher_svc_objectProxy::com_jci_obs_stitcher_svc_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                                           std::string dest,
                                                                           std::string path) : DBus::ObjectProxy(conn,
                                                                                                                 dest,
                                                                                                                 path) {
  m_com_jci_obs_stitcher_svcProxy = com_jci_obs_stitcher_svcProxy::create("com.jci.obs.stitcher.svc");
  this->add_interface(m_com_jci_obs_stitcher_svcProxy);

}
std::shared_ptr <com_jci_obs_stitcher_svc_objectProxy> com_jci_obs_stitcher_svc_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                                    std::string dest,
                                                                                                    std::string path,
                                                                                                    DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_obs_stitcher_svc_objectProxy> created =
      std::shared_ptr<com_jci_obs_stitcher_svc_objectProxy>(new com_jci_obs_stitcher_svc_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_obs_stitcher_svcProxy> com_jci_obs_stitcher_svc_objectProxy::getcom_jci_obs_stitcher_svcInterface() {
  return m_com_jci_obs_stitcher_svcProxy;

}
