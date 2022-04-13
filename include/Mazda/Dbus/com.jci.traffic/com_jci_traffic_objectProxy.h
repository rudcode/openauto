#ifndef COM_JCI_TRAFFIC_OBJECTPROXY_H
#define COM_JCI_TRAFFIC_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_trafficProxy.h"
class com_jci_traffic_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_traffic_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_traffic_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                             std::string dest,
                                                             std::string path,
                                                             DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_trafficProxy> getcom_jci_trafficInterface();
 protected:
  std::shared_ptr<com_jci_trafficProxy> m_com_jci_trafficProxy;
};
#endif /* COM_JCI_TRAFFIC_OBJECTPROXY_H */
