#include "com_jci_aapa_objectProxy.h"

com_jci_aapa_objectProxy::com_jci_aapa_objectProxy(std::shared_ptr<DBus::Connection> conn,
                                                   std::string dest,
                                                   std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_aapaProxy = com_jci_aapaProxy::create("com.jci.aapa");
  this->add_interface(m_com_jci_aapaProxy);

}
std::shared_ptr<com_jci_aapa_objectProxy> com_jci_aapa_objectProxy::create(std::shared_ptr<DBus::Connection> conn,
                                                                           std::string dest,
                                                                           std::string path,
                                                                           DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr<com_jci_aapa_objectProxy>
      created = std::shared_ptr<com_jci_aapa_objectProxy>(new com_jci_aapa_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr<com_jci_aapaProxy> com_jci_aapa_objectProxy::getcom_jci_aapaInterface() {
  return m_com_jci_aapaProxy;

}
