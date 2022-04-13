#include "com_jci_blm_pandora_objectProxy.h"

com_jci_blm_pandora_objectProxy::com_jci_blm_pandora_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                                 std::string dest,
                                                                 std::string path) : DBus::ObjectProxy(conn,
                                                                                                       dest,
                                                                                                       path) {
  m_com_jci_blm_pandoraProxy = com_jci_blm_pandoraProxy::create("com.jci.blm.pandora");
  this->add_interface(m_com_jci_blm_pandoraProxy);

}
std::shared_ptr <com_jci_blm_pandora_objectProxy> com_jci_blm_pandora_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                          std::string dest,
                                                                                          std::string path,
                                                                                          DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_blm_pandora_objectProxy>
      created = std::shared_ptr<com_jci_blm_pandora_objectProxy>(new com_jci_blm_pandora_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_blm_pandoraProxy> com_jci_blm_pandora_objectProxy::getcom_jci_blm_pandoraInterface() {
  return m_com_jci_blm_pandoraProxy;

}
