#ifndef COM_JCI_LDS_DATA_OBJECTPROXY_H
#define COM_JCI_LDS_DATA_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_lds_dataProxy.h"
class com_jci_lds_data_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_lds_data_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_lds_data_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                              std::string dest,
                                                              std::string path,
                                                              DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_lds_dataProxy> getcom_jci_lds_dataInterface();
 protected:
  std::shared_ptr<com_jci_lds_dataProxy> m_com_jci_lds_dataProxy;
};
#endif /* COM_JCI_LDS_DATA_OBJECTPROXY_H */
