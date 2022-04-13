#ifndef COM_JCI_VBS_NAVI_OBJECTPROXY_H
#define COM_JCI_VBS_NAVI_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_vbs_naviProxy.h"
class com_jci_vbs_navi_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_vbs_navi_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_vbs_navi_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                              std::string dest,
                                                              std::string path,
                                                              DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_vbs_naviProxy> getcom_jci_vbs_naviInterface();
 protected:
  std::shared_ptr<com_jci_vbs_naviProxy> m_com_jci_vbs_naviProxy;
};
#endif /* COM_JCI_VBS_NAVI_OBJECTPROXY_H */
