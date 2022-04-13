#ifndef COM_JCI_USBMS_OBJECTPROXY_H
#define COM_JCI_USBMS_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_usbmsProxy.h"
class com_jci_usbms_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_usbms_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_usbms_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                           std::string dest,
                                                           std::string path,
                                                           DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_usbmsProxy> getcom_jci_usbmsInterface();
 protected:
  std::shared_ptr<com_jci_usbmsProxy> m_com_jci_usbmsProxy;
};
#endif /* COM_JCI_USBMS_OBJECTPROXY_H */
