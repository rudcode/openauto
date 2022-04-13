#ifndef COM_JCI_FAV_OBJECTPROXY_H
#define COM_JCI_FAV_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_favProxy.h"
class com_jci_fav_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_fav_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_fav_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                         std::string dest,
                                                         std::string path,
                                                         DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_favProxy> getcom_jci_favInterface();
 protected:
  std::shared_ptr<com_jci_favProxy> m_com_jci_favProxy;
};
#endif /* COM_JCI_FAV_OBJECTPROXY_H */
