#include "com_jci_opera_IHU_PRIMARY_objectProxy.h"

com_jci_opera_IHU_PRIMARY_objectProxy::com_jci_opera_IHU_PRIMARY_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                                             std::string dest,
                                                                             std::string path) : DBus::ObjectProxy(conn,
                                                                                                                   dest,
                                                                                                                   path) {
  m_com_jci_opera_IHU_PRIMARYProxy = com_jci_opera_IHU_PRIMARYProxy::create("com.jci.opera_IHU_PRIMARY");
  this->add_interface(m_com_jci_opera_IHU_PRIMARYProxy);

}
std::shared_ptr <com_jci_opera_IHU_PRIMARY_objectProxy> com_jci_opera_IHU_PRIMARY_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                                      std::string dest,
                                                                                                      std::string path,
                                                                                                      DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_opera_IHU_PRIMARY_objectProxy> created =
      std::shared_ptr<com_jci_opera_IHU_PRIMARY_objectProxy>(new com_jci_opera_IHU_PRIMARY_objectProxy(conn,
                                                                                                       dest,
                                                                                                       path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_opera_IHU_PRIMARYProxy> com_jci_opera_IHU_PRIMARY_objectProxy::getcom_jci_opera_IHU_PRIMARYInterface() {
  return m_com_jci_opera_IHU_PRIMARYProxy;

}
