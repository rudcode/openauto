#ifndef COM_JCI_LVDS_OBJECTPROXY_H
#define COM_JCI_LVDS_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_lvdsProxy.h"
class com_jci_lvds_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_lvds_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_lvds_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                          std::string dest,
                                                          std::string path,
                                                          DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_lvdsProxy> getcom_jci_lvdsInterface();
 protected:
  std::shared_ptr<com_jci_lvdsProxy> m_com_jci_lvdsProxy;
};
#endif /* COM_JCI_LVDS_OBJECTPROXY_H */
