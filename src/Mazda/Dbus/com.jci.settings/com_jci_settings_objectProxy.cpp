#include "com_jci_settings_objectProxy.h"

com_jci_settings_objectProxy::com_jci_settings_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                           std::string dest,
                                                           std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_settingsProxy = com_jci_settingsProxy::create("com.jci.settings");
  this->add_interface(m_com_jci_settingsProxy);

}
std::shared_ptr <com_jci_settings_objectProxy> com_jci_settings_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                    std::string dest,
                                                                                    std::string path,
                                                                                    DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_settings_objectProxy>
      created = std::shared_ptr<com_jci_settings_objectProxy>(new com_jci_settings_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_settingsProxy> com_jci_settings_objectProxy::getcom_jci_settingsInterface() {
  return m_com_jci_settingsProxy;

}
