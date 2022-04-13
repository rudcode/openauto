#include "com_jci_bteca_objectProxy.h"

com_jci_bteca_objectProxy::com_jci_bteca_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                     std::string dest,
                                                     std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_btecaProxy = com_jci_btecaProxy::create("com.jci.bteca");
  this->add_interface(m_com_jci_btecaProxy);

}
std::shared_ptr <com_jci_bteca_objectProxy> com_jci_bteca_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                              std::string dest,
                                                                              std::string path,
                                                                              DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_bteca_objectProxy>
      created = std::shared_ptr<com_jci_bteca_objectProxy>(new com_jci_bteca_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_btecaProxy> com_jci_bteca_objectProxy::getcom_jci_btecaInterface() {
  return m_com_jci_btecaProxy;

}
