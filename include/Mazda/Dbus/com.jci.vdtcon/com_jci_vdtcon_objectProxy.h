#ifndef COM_JCI_VDTCON_OBJECTPROXY_H
#define COM_JCI_VDTCON_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_vdtconProxy.h"
class com_jci_vdtcon_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_vdtcon_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_vdtcon_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                            std::string dest,
                                                            std::string path,
                                                            DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_vdtconProxy> getcom_jci_vdtconInterface();
 protected:
  std::shared_ptr<com_jci_vdtconProxy> m_com_jci_vdtconProxy;
};
#endif /* COM_JCI_VDTCON_OBJECTPROXY_H */
