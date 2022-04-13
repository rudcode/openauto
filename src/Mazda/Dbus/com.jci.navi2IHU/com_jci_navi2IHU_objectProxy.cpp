#include "com_jci_navi2IHU_objectProxy.h"

com_jci_navi2IHU_objectProxy::com_jci_navi2IHU_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                           std::string dest,
                                                           std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_navi2IHUProxy = com_jci_navi2IHUProxy::create("com.jci.navi2IHU");
  this->add_interface(m_com_jci_navi2IHUProxy);

}
std::shared_ptr <com_jci_navi2IHU_objectProxy> com_jci_navi2IHU_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                    std::string dest,
                                                                                    std::string path,
                                                                                    DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_navi2IHU_objectProxy>
      created = std::shared_ptr<com_jci_navi2IHU_objectProxy>(new com_jci_navi2IHU_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_navi2IHUProxy> com_jci_navi2IHU_objectProxy::getcom_jci_navi2IHUInterface() {
  return m_com_jci_navi2IHUProxy;

}
