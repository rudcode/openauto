#include "com_jci_pa_objectProxy.h"

com_jci_pa_objectProxy::com_jci_pa_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                               std::string dest,
                                               std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_paProxy = com_jci_paProxy::create("com.jci.pa");
  this->add_interface(m_com_jci_paProxy);

}
std::shared_ptr <com_jci_pa_objectProxy> com_jci_pa_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                        std::string dest,
                                                                        std::string path,
                                                                        DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_pa_objectProxy>
      created = std::shared_ptr<com_jci_pa_objectProxy>(new com_jci_pa_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_paProxy> com_jci_pa_objectProxy::getcom_jci_paInterface() {
  return m_com_jci_paProxy;

}
