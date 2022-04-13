#ifndef COM_JCI_BLM_NMS_OBJECTPROXY_H
#define COM_JCI_BLM_NMS_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_blm_nmsProxy.h"
class com_jci_blm_nms_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_blm_nms_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_blm_nms_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                             std::string dest,
                                                             std::string path,
                                                             DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_blm_nmsProxy> getcom_jci_blm_nmsInterface();
 protected:
  std::shared_ptr<com_jci_blm_nmsProxy> m_com_jci_blm_nmsProxy;
};
#endif /* COM_JCI_BLM_NMS_OBJECTPROXY_H */
