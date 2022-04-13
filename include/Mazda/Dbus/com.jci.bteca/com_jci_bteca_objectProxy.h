#ifndef COM_JCI_BTECA_OBJECTPROXY_H
#define COM_JCI_BTECA_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_btecaProxy.h"
class com_jci_bteca_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_bteca_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_bteca_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                           std::string dest,
                                                           std::string path,
                                                           DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_btecaProxy> getcom_jci_btecaInterface();
 protected:
  std::shared_ptr<com_jci_btecaProxy> m_com_jci_btecaProxy;
};
#endif /* COM_JCI_BTECA_OBJECTPROXY_H */
