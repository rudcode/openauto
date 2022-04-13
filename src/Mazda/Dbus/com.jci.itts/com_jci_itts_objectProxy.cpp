#include "com_jci_itts_objectProxy.h"

com_jci_itts_objectProxy::com_jci_itts_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                   std::string dest,
                                                   std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_ittsProxy = com_jci_ittsProxy::create("com.jci.itts");
  this->add_interface(m_com_jci_ittsProxy);

}
std::shared_ptr <com_jci_itts_objectProxy> com_jci_itts_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                            std::string dest,
                                                                            std::string path,
                                                                            DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_itts_objectProxy>
      created = std::shared_ptr<com_jci_itts_objectProxy>(new com_jci_itts_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_ittsProxy> com_jci_itts_objectProxy::getcom_jci_ittsInterface() {
  return m_com_jci_ittsProxy;

}
