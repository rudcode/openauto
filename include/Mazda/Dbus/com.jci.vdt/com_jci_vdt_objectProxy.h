#ifndef COM_JCI_VDT_OBJECTPROXY_H
#define COM_JCI_VDT_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_vdtProxy.h"
class com_jci_vdt_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_vdt_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_vdt_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                         std::string dest,
                                                         std::string path,
                                                         DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_vdtProxy> getcom_jci_vdtInterface();
 protected:
  std::shared_ptr<com_jci_vdtProxy> m_com_jci_vdtProxy;
};
#endif /* COM_JCI_VDT_OBJECTPROXY_H */
