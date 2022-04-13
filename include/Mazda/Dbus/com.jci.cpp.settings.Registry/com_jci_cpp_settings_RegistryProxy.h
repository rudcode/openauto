#ifndef COM_JCI_CPP_SETTINGS_REGISTRYPROXY_H
#define COM_JCI_CPP_SETTINGS_REGISTRYPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_cpp_settings_RegistryProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_cpp_settings_RegistryProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_cpp_settings_RegistryProxy> create(std::string name = "com.jci.cpp.settings.Registry");
  void addNode(std::string path);
  void getNode(std::string path);
  void restoreNode(std::string path);
  void setNode(std::string path);
 protected:
  std::shared_ptr<DBus::MethodProxy<void(std::string)>> m_method_addNode;
  std::shared_ptr<DBus::MethodProxy<void(std::string)>> m_method_getNode;
  std::shared_ptr<DBus::MethodProxy<void(std::string)>> m_method_restoreNode;
  std::shared_ptr<DBus::MethodProxy<void(std::string)>> m_method_setNode;
};
#endif /* COM_JCI_CPP_SETTINGS_REGISTRYPROXY_H */
