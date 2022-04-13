#include "com_jci_cpp_settings_Registry_objectProxy.h"

com_jci_cpp_settings_Registry_objectProxy::com_jci_cpp_settings_Registry_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                                                     std::string dest,
                                                                                     std::string path)
    : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_cpp_settings_RegistryProxy = com_jci_cpp_settings_RegistryProxy::create("com.jci.cpp.settings.Registry");
  this->add_interface(m_com_jci_cpp_settings_RegistryProxy);

}
std::shared_ptr <com_jci_cpp_settings_Registry_objectProxy> com_jci_cpp_settings_Registry_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                                              std::string dest,
                                                                                                              std::string path,
                                                                                                              DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_cpp_settings_Registry_objectProxy> created =
      std::shared_ptr<com_jci_cpp_settings_Registry_objectProxy>(new com_jci_cpp_settings_Registry_objectProxy(conn,
                                                                                                               dest,
                                                                                                               path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_cpp_settings_RegistryProxy> com_jci_cpp_settings_Registry_objectProxy::getcom_jci_cpp_settings_RegistryInterface() {
  return m_com_jci_cpp_settings_RegistryProxy;

}
