#ifndef COM_JCI_BDS_OBJECTPROXY_H
#define COM_JCI_BDS_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_bdsProxy.h"
class com_jci_bds_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_bds_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_bds_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                         std::string dest,
                                                         std::string path,
                                                         DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_bdsProxy> getcom_jci_bdsInterface();
 protected:
  std::shared_ptr<com_jci_bdsProxy> m_com_jci_bdsProxy;
};
#endif /* COM_JCI_BDS_OBJECTPROXY_H */
