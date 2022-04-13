#ifndef COM_JCI_LDS_CONTROL_OBJECTPROXY_H
#define COM_JCI_LDS_CONTROL_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_lds_controlProxy.h"
class com_jci_lds_control_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_lds_control_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_lds_control_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                                 std::string dest,
                                                                 std::string path,
                                                                 DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_lds_controlProxy> getcom_jci_lds_controlInterface();
 protected:
  std::shared_ptr<com_jci_lds_controlProxy> m_com_jci_lds_controlProxy;
};
#endif /* COM_JCI_LDS_CONTROL_OBJECTPROXY_H */
