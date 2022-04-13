#include "com_jci_driverid_objectProxy.h"

com_jci_driverid_objectProxy::com_jci_driverid_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                           std::string dest,
                                                           std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_driveridProxy = com_jci_driveridProxy::create("com.jci.driverid");
  this->add_interface(m_com_jci_driveridProxy);

}
std::shared_ptr <com_jci_driverid_objectProxy> com_jci_driverid_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                    std::string dest,
                                                                                    std::string path,
                                                                                    DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_driverid_objectProxy>
      created = std::shared_ptr<com_jci_driverid_objectProxy>(new com_jci_driverid_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_driveridProxy> com_jci_driverid_objectProxy::getcom_jci_driveridInterface() {
  return m_com_jci_driveridProxy;

}
