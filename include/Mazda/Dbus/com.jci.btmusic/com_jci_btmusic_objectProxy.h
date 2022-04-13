#ifndef COM_JCI_BTMUSIC_OBJECTPROXY_H
#define COM_JCI_BTMUSIC_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_btmusicProxy.h"
class com_jci_btmusic_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_btmusic_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_btmusic_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                             std::string dest,
                                                             std::string path,
                                                             DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_btmusicProxy> getcom_jci_btmusicInterface();
 protected:
  std::shared_ptr<com_jci_btmusicProxy> m_com_jci_btmusicProxy;
};
#endif /* COM_JCI_BTMUSIC_OBJECTPROXY_H */
