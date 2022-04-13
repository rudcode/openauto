#ifndef COM_JCI_VIDEOCTRL_OBJECTPROXY_H
#define COM_JCI_VIDEOCTRL_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_VIDEOCTRLProxy.h"
class com_jci_VIDEOCTRL_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_VIDEOCTRL_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_VIDEOCTRL_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                               std::string dest,
                                                               std::string path,
                                                               DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_VIDEOCTRLProxy> getcom_jci_VIDEOCTRLInterface();
 protected:
  std::shared_ptr<com_jci_VIDEOCTRLProxy> m_com_jci_VIDEOCTRLProxy;
};
#endif /* COM_JCI_VIDEOCTRL_OBJECTPROXY_H */
