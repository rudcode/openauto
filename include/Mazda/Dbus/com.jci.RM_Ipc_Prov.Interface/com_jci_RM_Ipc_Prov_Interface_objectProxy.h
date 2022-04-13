#ifndef COM_JCI_RM_IPC_PROV_INTERFACE_OBJECTPROXY_H
#define COM_JCI_RM_IPC_PROV_INTERFACE_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_RM_Ipc_Prov_InterfaceProxy.h"
class com_jci_RM_Ipc_Prov_Interface_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_RM_Ipc_Prov_Interface_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_RM_Ipc_Prov_Interface_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                                           std::string dest,
                                                                           std::string path,
                                                                           DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_RM_Ipc_Prov_InterfaceProxy> getcom_jci_RM_Ipc_Prov_InterfaceInterface();
 protected:
  std::shared_ptr<com_jci_RM_Ipc_Prov_InterfaceProxy> m_com_jci_RM_Ipc_Prov_InterfaceProxy;
};
#endif /* COM_JCI_RM_IPC_PROV_INTERFACE_OBJECTPROXY_H */
