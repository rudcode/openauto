#include "com_jci_lvds_objectProxy.h"

com_jci_lvds_objectProxy::com_jci_lvds_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                   std::string dest,
                                                   std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_lvdsProxy = com_jci_lvdsProxy::create("com.jci.lvds");
  this->add_interface(m_com_jci_lvdsProxy);

}
std::shared_ptr <com_jci_lvds_objectProxy> com_jci_lvds_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                            std::string dest,
                                                                            std::string path,
                                                                            DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_lvds_objectProxy>
      created = std::shared_ptr<com_jci_lvds_objectProxy>(new com_jci_lvds_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_lvdsProxy> com_jci_lvds_objectProxy::getcom_jci_lvdsInterface() {
  return m_com_jci_lvdsProxy;

}
