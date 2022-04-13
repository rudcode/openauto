#ifndef COM_JCI_TESTDIAG_OBJECTPROXY_H
#define COM_JCI_TESTDIAG_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_testdiagProxy.h"
class com_jci_testdiag_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_testdiag_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_testdiag_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                              std::string dest,
                                                              std::string path,
                                                              DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_testdiagProxy> getcom_jci_testdiagInterface();
 protected:
  std::shared_ptr<com_jci_testdiagProxy> m_com_jci_testdiagProxy;
};
#endif /* COM_JCI_TESTDIAG_OBJECTPROXY_H */
