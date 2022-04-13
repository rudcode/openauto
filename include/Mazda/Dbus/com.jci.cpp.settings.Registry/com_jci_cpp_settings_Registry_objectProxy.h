#ifndef COM_JCI_CPP_SETTINGS_REGISTRY_OBJECTPROXY_H
#define COM_JCI_CPP_SETTINGS_REGISTRY_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_cpp_settings_RegistryProxy.h"
class com_jci_cpp_settings_Registry_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_cpp_settings_Registry_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_cpp_settings_Registry_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                                           std::string dest,
                                                                           std::string path,
                                                                           DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_cpp_settings_RegistryProxy> getcom_jci_cpp_settings_RegistryInterface();
 protected:
  std::shared_ptr<com_jci_cpp_settings_RegistryProxy> m_com_jci_cpp_settings_RegistryProxy;
};
#endif /* COM_JCI_CPP_SETTINGS_REGISTRY_OBJECTPROXY_H */
