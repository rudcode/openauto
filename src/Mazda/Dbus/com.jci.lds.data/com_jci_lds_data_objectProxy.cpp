#include "com_jci_lds_data_objectProxy.h"

com_jci_lds_data_objectProxy::com_jci_lds_data_objectProxy(std::shared_ptr<DBus::Connection> conn,
                                                           std::string dest,
                                                           std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_lds_dataProxy = com_jci_lds_dataProxy::create("com.jci.lds.data");
  this->add_interface(m_com_jci_lds_dataProxy);

}
std::shared_ptr<com_jci_lds_data_objectProxy> com_jci_lds_data_objectProxy::create(std::shared_ptr<DBus::Connection> conn,
                                                                                   std::string dest,
                                                                                   std::string path,
                                                                                   DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr<com_jci_lds_data_objectProxy>
      created = std::shared_ptr<com_jci_lds_data_objectProxy>(new com_jci_lds_data_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr<com_jci_lds_dataProxy> com_jci_lds_data_objectProxy::getcom_jci_lds_dataInterface() {
  return m_com_jci_lds_dataProxy;

}
