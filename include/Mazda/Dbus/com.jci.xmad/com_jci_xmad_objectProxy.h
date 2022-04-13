#ifndef COM_JCI_XMAD_OBJECTPROXY_H
#define COM_JCI_XMAD_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_xmadProxy.h"
class com_jci_xmad_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_xmad_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_xmad_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                          std::string dest,
                                                          std::string path,
                                                          DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_xmadProxy> getcom_jci_xmadInterface();
 protected:
  std::shared_ptr<com_jci_xmadProxy> m_com_jci_xmadProxy;
};
#endif /* COM_JCI_XMAD_OBJECTPROXY_H */
