#ifndef COM_JCI_CPP_DBUS_DBUSCONNECTIONPROXY_H
#define COM_JCI_CPP_DBUS_DBUSCONNECTIONPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_cpp_dbus_DbusConnectionProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_cpp_dbus_DbusConnectionProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_cpp_dbus_DbusConnectionProxy> create(std::string name = "com.jci.cpp.dbus.DbusConnection");
  void Wiki(uint32_t timeout);
 protected:
  std::shared_ptr<DBus::MethodProxy<void(uint32_t)>> m_method_Wiki;
};
#endif /* COM_JCI_CPP_DBUS_DBUSCONNECTIONPROXY_H */
