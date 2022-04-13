#ifndef COM_JCI_CDRP_OBJECTPROXY_H
#define COM_JCI_CDRP_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_cdrpProxy.h"
class com_jci_cdrp_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_cdrp_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_cdrp_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                          std::string dest,
                                                          std::string path,
                                                          DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_cdrpProxy> getcom_jci_cdrpInterface();
 protected:
  std::shared_ptr<com_jci_cdrpProxy> m_com_jci_cdrpProxy;
};
#endif /* COM_JCI_CDRP_OBJECTPROXY_H */
