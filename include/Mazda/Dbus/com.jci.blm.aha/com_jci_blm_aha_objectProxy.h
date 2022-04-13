#ifndef COM_JCI_BLM_AHA_OBJECTPROXY_H
#define COM_JCI_BLM_AHA_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_blm_ahaProxy.h"
class com_jci_blm_aha_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_blm_aha_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_blm_aha_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                             std::string dest,
                                                             std::string path,
                                                             DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_blm_ahaProxy> getcom_jci_blm_ahaInterface();
 protected:
  std::shared_ptr<com_jci_blm_ahaProxy> m_com_jci_blm_ahaProxy;
};
#endif /* COM_JCI_BLM_AHA_OBJECTPROXY_H */
