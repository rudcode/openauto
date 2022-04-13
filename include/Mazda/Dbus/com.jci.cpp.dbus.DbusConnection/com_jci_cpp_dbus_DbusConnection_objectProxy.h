#ifndef COM_JCI_CPP_DBUS_DBUSCONNECTION_OBJECTPROXY_H
#define COM_JCI_CPP_DBUS_DBUSCONNECTION_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_cpp_dbus_DbusConnectionProxy.h"
class com_jci_cpp_dbus_DbusConnection_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_cpp_dbus_DbusConnection_objectProxy(std::shared_ptr<DBus::Connection> conn,
                                              std::string dest,
                                              std::string path);
 public:
  static std::shared_ptr<com_jci_cpp_dbus_DbusConnection_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                                             std::string dest,
                                                                             std::string path,
                                                                             DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_cpp_dbus_DbusConnectionProxy> getcom_jci_cpp_dbus_DbusConnectionInterface();
 protected:
  std::shared_ptr<com_jci_cpp_dbus_DbusConnectionProxy> m_com_jci_cpp_dbus_DbusConnectionProxy;
};
#endif /* COM_JCI_CPP_DBUS_DBUSCONNECTION_OBJECTPROXY_H */
