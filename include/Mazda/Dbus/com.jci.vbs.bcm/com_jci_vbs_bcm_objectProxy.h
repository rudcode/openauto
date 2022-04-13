#ifndef COM_JCI_VBS_BCM_OBJECTPROXY_H
#define COM_JCI_VBS_BCM_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_vbs_bcmProxy.h"
class com_jci_vbs_bcm_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_vbs_bcm_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_vbs_bcm_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                             std::string dest,
                                                             std::string path,
                                                             DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_vbs_bcmProxy> getcom_jci_vbs_bcmInterface();
 protected:
  std::shared_ptr<com_jci_vbs_bcmProxy> m_com_jci_vbs_bcmProxy;
};
#endif /* COM_JCI_VBS_BCM_OBJECTPROXY_H */
