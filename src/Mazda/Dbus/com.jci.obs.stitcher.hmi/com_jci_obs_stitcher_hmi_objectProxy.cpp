#include "com_jci_obs_stitcher_hmi_objectProxy.h"

com_jci_obs_stitcher_hmi_objectProxy::com_jci_obs_stitcher_hmi_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                                           std::string dest,
                                                                           std::string path) : DBus::ObjectProxy(conn,
                                                                                                                 dest,
                                                                                                                 path) {
  m_com_jci_obs_stitcher_hmiProxy = com_jci_obs_stitcher_hmiProxy::create("com.jci.obs.stitcher.hmi");
  this->add_interface(m_com_jci_obs_stitcher_hmiProxy);

}
std::shared_ptr <com_jci_obs_stitcher_hmi_objectProxy> com_jci_obs_stitcher_hmi_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                                    std::string dest,
                                                                                                    std::string path,
                                                                                                    DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_obs_stitcher_hmi_objectProxy> created =
      std::shared_ptr<com_jci_obs_stitcher_hmi_objectProxy>(new com_jci_obs_stitcher_hmi_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_obs_stitcher_hmiProxy> com_jci_obs_stitcher_hmi_objectProxy::getcom_jci_obs_stitcher_hmiInterface() {
  return m_com_jci_obs_stitcher_hmiProxy;

}
