#ifndef COM_JCI_ITTS_OBJECTPROXY_H
#define COM_JCI_ITTS_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_ittsProxy.h"
class com_jci_itts_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_itts_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_itts_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                          std::string dest,
                                                          std::string path,
                                                          DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_ittsProxy> getcom_jci_ittsInterface();
 protected:
  std::shared_ptr<com_jci_ittsProxy> m_com_jci_ittsProxy;
};
#endif /* COM_JCI_ITTS_OBJECTPROXY_H */
