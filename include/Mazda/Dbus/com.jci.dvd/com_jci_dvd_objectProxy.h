#ifndef COM_JCI_DVD_OBJECTPROXY_H
#define COM_JCI_DVD_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_dvdProxy.h"
class com_jci_dvd_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_dvd_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_dvd_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                         std::string dest,
                                                         std::string path,
                                                         DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_dvdProxy> getcom_jci_dvdInterface();
 protected:
  std::shared_ptr<com_jci_dvdProxy> m_com_jci_dvdProxy;
};
#endif /* COM_JCI_DVD_OBJECTPROXY_H */
