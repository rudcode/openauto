#ifndef COM_JCI_DAB_OBJECTPROXY_H
#define COM_JCI_DAB_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_dabProxy.h"
class com_jci_dab_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_dab_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_dab_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                         std::string dest,
                                                         std::string path,
                                                         DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_dabProxy> getcom_jci_dabInterface();
 protected:
  std::shared_ptr<com_jci_dabProxy> m_com_jci_dabProxy;
};
#endif /* COM_JCI_DAB_OBJECTPROXY_H */
