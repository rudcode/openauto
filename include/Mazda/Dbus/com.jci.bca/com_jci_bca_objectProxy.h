#ifndef COM_JCI_BCA_OBJECTPROXY_H
#define COM_JCI_BCA_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_bcaProxy.h"
class com_jci_bca_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_bca_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_bca_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                         std::string dest,
                                                         std::string path,
                                                         DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_bcaProxy> getcom_jci_bcaInterface();
 protected:
  std::shared_ptr<com_jci_bcaProxy> m_com_jci_bcaProxy;
};
#endif /* COM_JCI_BCA_OBJECTPROXY_H */
