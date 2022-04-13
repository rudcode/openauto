#ifndef COM_JCI_NAVI_IHU_OBJECTPROXY_H
#define COM_JCI_NAVI_IHU_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_navi2IHUProxy.h"
class com_jci_navi2IHU_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_navi2IHU_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_navi2IHU_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                              std::string dest,
                                                              std::string path,
                                                              DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_navi2IHUProxy> getcom_jci_navi2IHUInterface();
 protected:
  std::shared_ptr<com_jci_navi2IHUProxy> m_com_jci_navi2IHUProxy;
};
#endif /* COM_JCI_NAVI_IHU_OBJECTPROXY_H */
