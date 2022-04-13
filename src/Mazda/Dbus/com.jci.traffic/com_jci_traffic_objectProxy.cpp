#include "com_jci_traffic_objectProxy.h"

com_jci_traffic_objectProxy::com_jci_traffic_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                         std::string dest,
                                                         std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_trafficProxy = com_jci_trafficProxy::create("com.jci.traffic");
  this->add_interface(m_com_jci_trafficProxy);

}
std::shared_ptr <com_jci_traffic_objectProxy> com_jci_traffic_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                  std::string dest,
                                                                                  std::string path,
                                                                                  DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_traffic_objectProxy>
      created = std::shared_ptr<com_jci_traffic_objectProxy>(new com_jci_traffic_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_trafficProxy> com_jci_traffic_objectProxy::getcom_jci_trafficInterface() {
  return m_com_jci_trafficProxy;

}
