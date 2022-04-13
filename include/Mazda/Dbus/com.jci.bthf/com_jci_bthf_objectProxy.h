#ifndef COM_JCI_BTHF_OBJECTPROXY_H
#define COM_JCI_BTHF_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_bthfProxy.h"
class com_jci_bthf_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_bthf_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_bthf_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                          std::string dest,
                                                          std::string path,
                                                          DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_bthfProxy> getcom_jci_bthfInterface();
 protected:
  std::shared_ptr<com_jci_bthfProxy> m_com_jci_bthfProxy;
};
#endif /* COM_JCI_BTHF_OBJECTPROXY_H */
