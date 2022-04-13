#ifndef COM_JCI_UPDATEA_SYS_IPC_INTERFACEPROXY_H
#define COM_JCI_UPDATEA_SYS_IPC_INTERFACEPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_UPDATEA_Sys_Ipc_InterfaceProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_UPDATEA_Sys_Ipc_InterfaceProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_UPDATEA_Sys_Ipc_InterfaceProxy> create(std::string name = "com.jci.UPDATEA_Sys_Ipc.Interface");
  DBus::MultipleReturn<int32_t, uint32_t> Connect(uint32_t in_connId);
  DBus::MultipleReturn<int32_t, uint32_t> Disconnect(uint32_t in_connId);
  DBus::MultipleReturn<int32_t, std::string, int32_t, uint32_t> GetVersion(uint32_t in_connId, int32_t in_versionType);
  DBus::MultipleReturn<bool, int32_t, uint32_t> IsPresentFailSafeOS(uint32_t in_connId);
  DBus::MultipleReturn<std::tuple<std::vector<std::tuple<std::string, int32_t, std::string>>>,
                       int32_t,
                       uint32_t> SearchForAvailableUPs(uint32_t in_connId);
  DBus::MultipleReturn<int32_t, uint32_t> CancelSearchForUPs(uint32_t in_connId);
  DBus::MultipleReturn<int32_t, uint32_t> ValidateAndDownloadUP(uint32_t in_connId, std::string in_upLocation);
  DBus::MultipleReturn<int32_t, uint32_t> CancelValidAndDwnld(uint32_t in_connId);
  DBus::MultipleReturn<int32_t, uint32_t> InstallUP(uint32_t in_connId);
  DBus::MultipleReturn<int32_t, uint32_t, int32_t, uint32_t> GetUpdateStatus(uint32_t in_connId);
  DBus::MultipleReturn<int32_t, uint32_t> RebootBoard(uint32_t in_connId);
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<std::tuple<std::string, int32_t, std::string>>>,
                                         uint32_t)>> signal_available_ups_event();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::string, int32_t, std::string>,
                                         uint32_t)>> signal_available_autoupdate_event();
  std::shared_ptr<DBus::SignalProxy<void(int32_t, uint32_t, int32_t, uint32_t)>> signal_update_status_event();
 protected:
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t>(uint32_t)>> m_method_Connect;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t>(uint32_t)>> m_method_Disconnect;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, std::string, int32_t, uint32_t>(uint32_t, int32_t)>>
      m_method_GetVersion;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<bool, int32_t, uint32_t>(uint32_t)>>
      m_method_IsPresentFailSafeOS;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::tuple<std::vector<std::tuple<std::string,
                                                                                           int32_t,
                                                                                           std::string>>>,
                                                         int32_t,
                                                         uint32_t>(uint32_t)>> m_method_SearchForAvailableUPs;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t>(uint32_t)>> m_method_CancelSearchForUPs;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t>(uint32_t, std::string)>>
      m_method_ValidateAndDownloadUP;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t>(uint32_t)>> m_method_CancelValidAndDwnld;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t>(uint32_t)>> m_method_InstallUP;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t, int32_t, uint32_t>(uint32_t)>>
      m_method_GetUpdateStatus;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t>(uint32_t)>> m_method_RebootBoard;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<std::tuple<std::string, int32_t, std::string>>>,
                                         uint32_t)>> m_signalproxy_available_ups_event;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::string, int32_t, std::string>, uint32_t)>>
      m_signalproxy_available_autoupdate_event;
  std::shared_ptr<DBus::SignalProxy<void(int32_t, uint32_t, int32_t, uint32_t)>> m_signalproxy_update_status_event;
};
#endif /* COM_JCI_UPDATEA_SYS_IPC_INTERFACEPROXY_H */
