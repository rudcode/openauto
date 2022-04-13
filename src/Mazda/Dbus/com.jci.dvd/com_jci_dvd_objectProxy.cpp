#include "com_jci_dvd_objectProxy.h"

com_jci_dvd_objectProxy::com_jci_dvd_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                 std::string dest,
                                                 std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_dvdProxy = com_jci_dvdProxy::create("com.jci.dvd");
  this->add_interface(m_com_jci_dvdProxy);

}
std::shared_ptr <com_jci_dvd_objectProxy> com_jci_dvd_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                          std::string dest,
                                                                          std::string path,
                                                                          DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_dvd_objectProxy>
      created = std::shared_ptr<com_jci_dvd_objectProxy>(new com_jci_dvd_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_dvdProxy> com_jci_dvd_objectProxy::getcom_jci_dvdInterface() {
  return m_com_jci_dvdProxy;

}
