#include "com_jci_nativeguictrl_objectProxy.h"

com_jci_nativeguictrl_objectProxy::com_jci_nativeguictrl_objectProxy(std::shared_ptr<DBus::Connection> conn,
                                                                     std::string dest,
                                                                     std::string path) : DBus::ObjectProxy(conn,
                                                                                                           dest,
                                                                                                           path) {
  m_com_jci_nativeguictrlProxy = com_jci_nativeguictrlProxy::create("com.jci.nativeguictrl");
  this->add_interface(m_com_jci_nativeguictrlProxy);

}
std::shared_ptr<com_jci_nativeguictrl_objectProxy> com_jci_nativeguictrl_objectProxy::create(std::shared_ptr<DBus::Connection> conn,
                                                                                             std::string dest,
                                                                                             std::string path,
                                                                                             DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr<com_jci_nativeguictrl_objectProxy> created =
      std::shared_ptr<com_jci_nativeguictrl_objectProxy>(new com_jci_nativeguictrl_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr<com_jci_nativeguictrlProxy> com_jci_nativeguictrl_objectProxy::getcom_jci_nativeguictrlInterface() {
  return m_com_jci_nativeguictrlProxy;

}
