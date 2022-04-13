#include "com_jci_blm_aha_objectProxy.h"

com_jci_blm_aha_objectProxy::com_jci_blm_aha_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                         std::string dest,
                                                         std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_blm_ahaProxy = com_jci_blm_ahaProxy::create("com.jci.blm.aha");
  this->add_interface(m_com_jci_blm_ahaProxy);

}
std::shared_ptr <com_jci_blm_aha_objectProxy> com_jci_blm_aha_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                  std::string dest,
                                                                                  std::string path,
                                                                                  DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_blm_aha_objectProxy>
      created = std::shared_ptr<com_jci_blm_aha_objectProxy>(new com_jci_blm_aha_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_blm_ahaProxy> com_jci_blm_aha_objectProxy::getcom_jci_blm_ahaInterface() {
  return m_com_jci_blm_ahaProxy;

}
