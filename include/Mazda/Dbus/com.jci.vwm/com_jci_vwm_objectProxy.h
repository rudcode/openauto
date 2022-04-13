#ifndef COM_JCI_VWM_OBJECTPROXY_H
#define COM_JCI_VWM_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_vwmProxy.h"
class com_jci_vwm_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_vwm_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_vwm_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                         std::string dest,
                                                         std::string path,
                                                         DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_vwmProxy> getcom_jci_vwmInterface();
 protected:
  std::shared_ptr<com_jci_vwmProxy> m_com_jci_vwmProxy;
};
#endif /* COM_JCI_VWM_OBJECTPROXY_H */
