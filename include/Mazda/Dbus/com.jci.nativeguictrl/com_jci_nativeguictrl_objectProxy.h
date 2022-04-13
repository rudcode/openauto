#ifndef COM_JCI_NATIVEGUICTRL_OBJECTPROXY_H
#define COM_JCI_NATIVEGUICTRL_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_nativeguictrlProxy.h"
class com_jci_nativeguictrl_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_nativeguictrl_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_nativeguictrl_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                                   std::string dest,
                                                                   std::string path,
                                                                   DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_nativeguictrlProxy> getcom_jci_nativeguictrlInterface();
 protected:
  std::shared_ptr<com_jci_nativeguictrlProxy> m_com_jci_nativeguictrlProxy;
};
#endif /* COM_JCI_NATIVEGUICTRL_OBJECTPROXY_H */
