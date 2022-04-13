#ifndef COM_JCI_VBS_NAVI_TMC_OBJECTPROXY_H
#define COM_JCI_VBS_NAVI_TMC_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_vbs_navi_tmcProxy.h"
class com_jci_vbs_navi_tmc_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_vbs_navi_tmc_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_vbs_navi_tmc_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                                  std::string dest,
                                                                  std::string path,
                                                                  DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_vbs_navi_tmcProxy> getcom_jci_vbs_navi_tmcInterface();
 protected:
  std::shared_ptr<com_jci_vbs_navi_tmcProxy> m_com_jci_vbs_navi_tmcProxy;
};
#endif /* COM_JCI_VBS_NAVI_TMC_OBJECTPROXY_H */
