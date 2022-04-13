#ifndef COM_JCI_VBS_AM_OBJECTPROXY_H
#define COM_JCI_VBS_AM_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_vbs_amProxy.h"
class com_jci_vbs_am_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_vbs_am_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_vbs_am_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                            std::string dest,
                                                            std::string path,
                                                            DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_vbs_amProxy> getcom_jci_vbs_amInterface();
 protected:
  std::shared_ptr<com_jci_vbs_amProxy> m_com_jci_vbs_amProxy;
};
#endif /* COM_JCI_VBS_AM_OBJECTPROXY_H */
