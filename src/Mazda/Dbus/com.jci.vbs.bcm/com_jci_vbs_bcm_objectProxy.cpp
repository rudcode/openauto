#include "com_jci_vbs_bcm_objectProxy.h"

com_jci_vbs_bcm_objectProxy::com_jci_vbs_bcm_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                         std::string dest,
                                                         std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_vbs_bcmProxy = com_jci_vbs_bcmProxy::create("com.jci.vbs.bcm");
  this->add_interface(m_com_jci_vbs_bcmProxy);

}
std::shared_ptr <com_jci_vbs_bcm_objectProxy> com_jci_vbs_bcm_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                  std::string dest,
                                                                                  std::string path,
                                                                                  DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_vbs_bcm_objectProxy>
      created = std::shared_ptr<com_jci_vbs_bcm_objectProxy>(new com_jci_vbs_bcm_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_vbs_bcmProxy> com_jci_vbs_bcm_objectProxy::getcom_jci_vbs_bcmInterface() {
  return m_com_jci_vbs_bcmProxy;

}
