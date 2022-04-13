#ifndef COM_JCI_UPDATES_SYS_IPC_INTERFACEPROXY_H
#define COM_JCI_UPDATES_SYS_IPC_INTERFACEPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_UPDATES_Sys_Ipc_InterfaceProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_UPDATES_Sys_Ipc_InterfaceProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_UPDATES_Sys_Ipc_InterfaceProxy> create(std::string name = "com.jci.UPDATES_Sys_Ipc.Interface");
  DBus::MultipleReturn<int32_t, uint32_t> Connect(uint32_t in_connId);
  DBus::MultipleReturn<int32_t, uint32_t> Disconnect(uint32_t in_connId);
  DBus::MultipleReturn<bool, int32_t, uint32_t> IsPresentFailSafeOS(uint32_t in_connId);
  DBus::MultipleReturn<std::string,
                       int32_t,
                       int32_t,
                       std::string,
                       bool,
                       int32_t,
                       uint32_t> GetPackageInfo(uint32_t in_connId, std::string in_upLocation);
  DBus::MultipleReturn<std::string,
                       int32_t,
                       int32_t,
                       std::string,
                       bool,
                       int32_t,
                       uint32_t> ValidateUP(uint32_t in_connId, std::string in_upLocation);
  DBus::MultipleReturn<int32_t, uint32_t> CancelValidate(uint32_t in_connId);
  DBus::MultipleReturn<int32_t, int32_t, int32_t, int32_t, uint32_t> InstallUP(uint32_t in_connId,
                                                                               std::string in_upLocation,
                                                                               int32_t in_installCtrlOpt);
  DBus::MultipleReturn<int32_t, uint32_t> CancelInstall(uint32_t in_connId);
  DBus::MultipleReturn<int32_t, uint32_t, int32_t, uint32_t> GetUpdateStatus(uint32_t in_connId);
  std::shared_ptr<DBus::SignalProxy<void(int32_t, uint32_t, int32_t, uint32_t)>> signal_update_status_event();
 protected:
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t>(uint32_t)>> m_method_Connect;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t>(uint32_t)>> m_method_Disconnect;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<bool, int32_t, uint32_t>(uint32_t)>>
      m_method_IsPresentFailSafeOS;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::string,
                                                         int32_t,
                                                         int32_t,
                                                         std::string,
                                                         bool,
                                                         int32_t,
                                                         uint32_t>(uint32_t, std::string)>> m_method_GetPackageInfo;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::string,
                                                         int32_t,
                                                         int32_t,
                                                         std::string,
                                                         bool,
                                                         int32_t,
                                                         uint32_t>(uint32_t, std::string)>> m_method_ValidateUP;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t>(uint32_t)>> m_method_CancelValidate;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, int32_t, int32_t, int32_t, uint32_t>(uint32_t,
                                                                                                       std::string,
                                                                                                       int32_t)>>
      m_method_InstallUP;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t>(uint32_t)>> m_method_CancelInstall;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t, int32_t, uint32_t>(uint32_t)>>
      m_method_GetUpdateStatus;
  std::shared_ptr<DBus::SignalProxy<void(int32_t, uint32_t, int32_t, uint32_t)>> m_signalproxy_update_status_event;
};
#endif /* COM_JCI_UPDATES_SYS_IPC_INTERFACEPROXY_H */
