#include "com_jci_navi2IHU_HUDSettings_objectProxy.h"

com_jci_navi2IHU_HUDSettings_objectProxy::com_jci_navi2IHU_HUDSettings_objectProxy(std::shared_ptr<DBus::Connection> conn,
                                                                                   std::string dest,
                                                                                   std::string path)
    : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_navi2IHU_HUDSettingsProxy = com_jci_navi2IHU_HUDSettingsProxy::create("com.jci.navi2IHU.HUDSettings");
  this->add_interface(m_com_jci_navi2IHU_HUDSettingsProxy);

}
std::shared_ptr<com_jci_navi2IHU_HUDSettings_objectProxy> com_jci_navi2IHU_HUDSettings_objectProxy::create(std::shared_ptr<
    DBus::Connection> conn, std::string dest, std::string path, DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr<com_jci_navi2IHU_HUDSettings_objectProxy> created =
      std::shared_ptr<com_jci_navi2IHU_HUDSettings_objectProxy>(new com_jci_navi2IHU_HUDSettings_objectProxy(conn,
                                                                                                             dest,
                                                                                                             path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr<com_jci_navi2IHU_HUDSettingsProxy> com_jci_navi2IHU_HUDSettings_objectProxy::getcom_jci_navi2IHU_HUDSettingsInterface() {
  return m_com_jci_navi2IHU_HUDSettingsProxy;

}
