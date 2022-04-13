#ifndef COM_JCI_XMDATA_OBJECTPROXY_H
#define COM_JCI_XMDATA_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_xmdataProxy.h"
class com_jci_xmdata_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_xmdata_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_xmdata_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                            std::string dest,
                                                            std::string path,
                                                            DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_xmdataProxy> getcom_jci_xmdataInterface();
 protected:
  std::shared_ptr<com_jci_xmdataProxy> m_com_jci_xmdataProxy;
};
#endif /* COM_JCI_XMDATA_OBJECTPROXY_H */
