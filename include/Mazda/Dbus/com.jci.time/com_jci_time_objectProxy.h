#ifndef COM_JCI_TIME_OBJECTPROXY_H
#define COM_JCI_TIME_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_timeProxy.h"
class com_jci_time_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_time_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_time_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                          std::string dest,
                                                          std::string path,
                                                          DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_timeProxy> getcom_jci_timeInterface();
 protected:
  std::shared_ptr<com_jci_timeProxy> m_com_jci_timeProxy;
};
#endif /* COM_JCI_TIME_OBJECTPROXY_H */
