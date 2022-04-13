#ifndef COM_JCI_PA_OBJECTPROXY_H
#define COM_JCI_PA_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_paProxy.h"
class com_jci_pa_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_pa_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_pa_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                        std::string dest,
                                                        std::string path,
                                                        DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_paProxy> getcom_jci_paInterface();
 protected:
  std::shared_ptr<com_jci_paProxy> m_com_jci_paProxy;
};
#endif /* COM_JCI_PA_OBJECTPROXY_H */
