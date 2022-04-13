#ifndef COM_JCI_PB_OBJECTPROXY_H
#define COM_JCI_PB_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_pbProxy.h"
class com_jci_pb_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_pb_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_pb_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                        std::string dest,
                                                        std::string path,
                                                        DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_pbProxy> getcom_jci_pbInterface();
 protected:
  std::shared_ptr<com_jci_pbProxy> m_com_jci_pbProxy;
};
#endif /* COM_JCI_PB_OBJECTPROXY_H */
