#ifndef COM_JCI_OPERA_IHU_OBJECTPROXY_H
#define COM_JCI_OPERA_IHU_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_opera_IHUProxy.h"
class com_jci_opera_IHU_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_opera_IHU_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_opera_IHU_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                               std::string dest,
                                                               std::string path,
                                                               DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_opera_IHUProxy> getcom_jci_opera_IHUInterface();
 protected:
  std::shared_ptr<com_jci_opera_IHUProxy> m_com_jci_opera_IHUProxy;
};
#endif /* COM_JCI_OPERA_IHU_OBJECTPROXY_H */
