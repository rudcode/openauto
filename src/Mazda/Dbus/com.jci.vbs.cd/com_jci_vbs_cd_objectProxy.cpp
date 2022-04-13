#include "com_jci_vbs_cd_objectProxy.h"

com_jci_vbs_cd_objectProxy::com_jci_vbs_cd_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                       std::string dest,
                                                       std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_vbs_cdProxy = com_jci_vbs_cdProxy::create("com.jci.vbs.cd");
  this->add_interface(m_com_jci_vbs_cdProxy);

}
std::shared_ptr <com_jci_vbs_cd_objectProxy> com_jci_vbs_cd_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                std::string dest,
                                                                                std::string path,
                                                                                DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_vbs_cd_objectProxy>
      created = std::shared_ptr<com_jci_vbs_cd_objectProxy>(new com_jci_vbs_cd_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_vbs_cdProxy> com_jci_vbs_cd_objectProxy::getcom_jci_vbs_cdInterface() {
  return m_com_jci_vbs_cdProxy;

}
