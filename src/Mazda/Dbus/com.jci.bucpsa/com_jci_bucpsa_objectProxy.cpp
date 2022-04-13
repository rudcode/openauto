#include "com_jci_bucpsa_objectProxy.h"

com_jci_bucpsa_objectProxy::com_jci_bucpsa_objectProxy(std::shared_ptr<DBus::Connection> conn,
                                                       std::string dest,
                                                       std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_bucpsaProxy = com_jci_bucpsaProxy::create("com.jci.bucpsa");
  this->add_interface(m_com_jci_bucpsaProxy);

}
std::shared_ptr<com_jci_bucpsa_objectProxy> com_jci_bucpsa_objectProxy::create(std::shared_ptr<DBus::Connection> conn,
                                                                               std::string dest,
                                                                               std::string path,
                                                                               DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr<com_jci_bucpsa_objectProxy>
      created = std::shared_ptr<com_jci_bucpsa_objectProxy>(new com_jci_bucpsa_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr<com_jci_bucpsaProxy> com_jci_bucpsa_objectProxy::getcom_jci_bucpsaInterface() {
  return m_com_jci_bucpsaProxy;

}
