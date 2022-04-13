#ifndef COM_JCI_ITT_OBJECTPROXY_H
#define COM_JCI_ITT_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_ittProxy.h"
class com_jci_itt_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_itt_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_itt_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                         std::string dest,
                                                         std::string path,
                                                         DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_ittProxy> getcom_jci_ittInterface();
 protected:
  std::shared_ptr<com_jci_ittProxy> m_com_jci_ittProxy;
};
#endif /* COM_JCI_ITT_OBJECTPROXY_H */
