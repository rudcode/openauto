#include "com_jci_testdiag_objectProxy.h"

com_jci_testdiag_objectProxy::com_jci_testdiag_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                           std::string dest,
                                                           std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_testdiagProxy = com_jci_testdiagProxy::create("com.jci.testdiag");
  this->add_interface(m_com_jci_testdiagProxy);

}
std::shared_ptr <com_jci_testdiag_objectProxy> com_jci_testdiag_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                    std::string dest,
                                                                                    std::string path,
                                                                                    DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_testdiag_objectProxy>
      created = std::shared_ptr<com_jci_testdiag_objectProxy>(new com_jci_testdiag_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_testdiagProxy> com_jci_testdiag_objectProxy::getcom_jci_testdiagInterface() {
  return m_com_jci_testdiagProxy;

}
