#include "com_jci_lvds_blm_objectProxy.h"

com_jci_lvds_blm_objectProxy::com_jci_lvds_blm_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                           std::string dest,
                                                           std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_lvds_blmProxy = com_jci_lvds_blmProxy::create("com.jci.lvds_blm");
  this->add_interface(m_com_jci_lvds_blmProxy);

}
std::shared_ptr <com_jci_lvds_blm_objectProxy> com_jci_lvds_blm_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                    std::string dest,
                                                                                    std::string path,
                                                                                    DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_lvds_blm_objectProxy>
      created = std::shared_ptr<com_jci_lvds_blm_objectProxy>(new com_jci_lvds_blm_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_lvds_blmProxy> com_jci_lvds_blm_objectProxy::getcom_jci_lvds_blmInterface() {
  return m_com_jci_lvds_blmProxy;

}
