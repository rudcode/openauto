#include "com_jci_eem_objectProxy.h"

com_jci_eem_objectProxy::com_jci_eem_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                 std::string dest,
                                                 std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_eemProxy = com_jci_eemProxy::create("com.jci.eem");
  this->add_interface(m_com_jci_eemProxy);

}
std::shared_ptr <com_jci_eem_objectProxy> com_jci_eem_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                          std::string dest,
                                                                          std::string path,
                                                                          DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_eem_objectProxy>
      created = std::shared_ptr<com_jci_eem_objectProxy>(new com_jci_eem_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_eemProxy> com_jci_eem_objectProxy::getcom_jci_eemInterface() {
  return m_com_jci_eemProxy;

}
