#ifndef COM_JCI_DIRECT_OBJECTPROXY_H
#define COM_JCI_DIRECT_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_directProxy.h"
class com_jci_direct_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_direct_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_direct_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                            std::string dest,
                                                            std::string path,
                                                            DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_directProxy> getcom_jci_directInterface();
 protected:
  std::shared_ptr<com_jci_directProxy> m_com_jci_directProxy;
};
#endif /* COM_JCI_DIRECT_OBJECTPROXY_H */
