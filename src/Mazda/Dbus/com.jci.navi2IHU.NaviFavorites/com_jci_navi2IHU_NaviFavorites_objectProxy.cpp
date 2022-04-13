#include "com_jci_navi2IHU_NaviFavorites_objectProxy.h"

com_jci_navi2IHU_NaviFavorites_objectProxy::com_jci_navi2IHU_NaviFavorites_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                                                       std::string dest,
                                                                                       std::string path)
    : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_navi2IHU_NaviFavoritesProxy = com_jci_navi2IHU_NaviFavoritesProxy::create("com.jci.navi2IHU.NaviFavorites");
  this->add_interface(m_com_jci_navi2IHU_NaviFavoritesProxy);

}
std::shared_ptr <com_jci_navi2IHU_NaviFavorites_objectProxy> com_jci_navi2IHU_NaviFavorites_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                                                std::string dest,
                                                                                                                std::string path,
                                                                                                                DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_navi2IHU_NaviFavorites_objectProxy> created =
      std::shared_ptr<com_jci_navi2IHU_NaviFavorites_objectProxy>(new com_jci_navi2IHU_NaviFavorites_objectProxy(conn,
                                                                                                                 dest,
                                                                                                                 path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_navi2IHU_NaviFavoritesProxy> com_jci_navi2IHU_NaviFavorites_objectProxy::getcom_jci_navi2IHU_NaviFavoritesInterface() {
  return m_com_jci_navi2IHU_NaviFavoritesProxy;

}
