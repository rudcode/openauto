#include "com_jci_blm_stitcher_objectProxy.h"

com_jci_blm_stitcher_objectProxy::com_jci_blm_stitcher_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                                   std::string dest,
                                                                   std::string path) : DBus::ObjectProxy(conn,
                                                                                                         dest,
                                                                                                         path) {
  m_com_jci_blm_stitcherProxy = com_jci_blm_stitcherProxy::create("com.jci.blm.stitcher");
  this->add_interface(m_com_jci_blm_stitcherProxy);

}
std::shared_ptr <com_jci_blm_stitcher_objectProxy> com_jci_blm_stitcher_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                            std::string dest,
                                                                                            std::string path,
                                                                                            DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_blm_stitcher_objectProxy> created =
      std::shared_ptr<com_jci_blm_stitcher_objectProxy>(new com_jci_blm_stitcher_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_blm_stitcherProxy> com_jci_blm_stitcher_objectProxy::getcom_jci_blm_stitcherInterface() {
  return m_com_jci_blm_stitcherProxy;

}
