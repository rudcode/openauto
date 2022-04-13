#ifndef COM_JCI_SXMS_NNG_OBJECTPROXY_H
#define COM_JCI_SXMS_NNG_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_sxms_nngProxy.h"
class com_jci_sxms_nng_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_sxms_nng_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_sxms_nng_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                              std::string dest,
                                                              std::string path,
                                                              DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_sxms_nngProxy> getcom_jci_sxms_nngInterface();
 protected:
  std::shared_ptr<com_jci_sxms_nngProxy> m_com_jci_sxms_nngProxy;
};
#endif /* COM_JCI_SXMS_NNG_OBJECTPROXY_H */
