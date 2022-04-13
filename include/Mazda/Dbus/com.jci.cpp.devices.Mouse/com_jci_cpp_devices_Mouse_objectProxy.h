#ifndef COM_JCI_CPP_DEVICES_MOUSE_OBJECTPROXY_H
#define COM_JCI_CPP_DEVICES_MOUSE_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_cpp_devices_MouseProxy.h"
class com_jci_cpp_devices_Mouse_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_cpp_devices_Mouse_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_cpp_devices_Mouse_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                                       std::string dest,
                                                                       std::string path,
                                                                       DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_cpp_devices_MouseProxy> getcom_jci_cpp_devices_MouseInterface();
 protected:
  std::shared_ptr<com_jci_cpp_devices_MouseProxy> m_com_jci_cpp_devices_MouseProxy;
};
#endif /* COM_JCI_CPP_DEVICES_MOUSE_OBJECTPROXY_H */
