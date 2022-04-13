#include "com_jci_UPDATES_Sys_Ipc_InterfaceProxy.h"

com_jci_UPDATES_Sys_Ipc_InterfaceProxy::com_jci_UPDATES_Sys_Ipc_InterfaceProxy(std::string name) : DBus::InterfaceProxy(
    name) {
  m_method_Connect = this->create_method<DBus::MultipleReturn<int32_t, uint32_t>(uint32_t)>("Connect");
  m_method_Disconnect = this->create_method<DBus::MultipleReturn<int32_t, uint32_t>(uint32_t)>("Disconnect");
  m_method_IsPresentFailSafeOS =
      this->create_method<DBus::MultipleReturn<bool, int32_t, uint32_t>(uint32_t)>("IsPresentFailSafeOS");
  m_method_GetPackageInfo =
      this->create_method<DBus::MultipleReturn<std::string, int32_t, int32_t, std::string, bool, int32_t, uint32_t>(
          uint32_t,
          std::string)>("GetPackageInfo");
  m_method_ValidateUP =
      this->create_method<DBus::MultipleReturn<std::string, int32_t, int32_t, std::string, bool, int32_t, uint32_t>(
          uint32_t,
          std::string)>("ValidateUP");
  m_method_CancelValidate = this->create_method<DBus::MultipleReturn<int32_t, uint32_t>(uint32_t)>("CancelValidate");
  m_method_InstallUP = this->create_method<DBus::MultipleReturn<int32_t, int32_t, int32_t, int32_t, uint32_t>(uint32_t,
                                                                                                              std::string,
                                                                                                              int32_t)>(
      "InstallUP");
  m_method_CancelInstall = this->create_method<DBus::MultipleReturn<int32_t, uint32_t>(uint32_t)>("CancelInstall");
  m_method_GetUpdateStatus =
      this->create_method<DBus::MultipleReturn<int32_t, uint32_t, int32_t, uint32_t>(uint32_t)>("GetUpdateStatus");
  m_signalproxy_update_status_event =
      this->create_signal<void(int32_t, uint32_t, int32_t, uint32_t)>("update_status_event");

}
std::shared_ptr <com_jci_UPDATES_Sys_Ipc_InterfaceProxy> com_jci_UPDATES_Sys_Ipc_InterfaceProxy::create(std::string name) {
  return std::shared_ptr<com_jci_UPDATES_Sys_Ipc_InterfaceProxy>(new com_jci_UPDATES_Sys_Ipc_InterfaceProxy(name));

}
DBus::MultipleReturn <int32_t, uint32_t> com_jci_UPDATES_Sys_Ipc_InterfaceProxy::Connect(uint32_t in_connId) {
  return (*m_method_Connect)(in_connId);

}
DBus::MultipleReturn <int32_t, uint32_t> com_jci_UPDATES_Sys_Ipc_InterfaceProxy::Disconnect(uint32_t in_connId) {
  return (*m_method_Disconnect)(in_connId);

}
DBus::MultipleReturn<bool, int32_t, uint32_t> com_jci_UPDATES_Sys_Ipc_InterfaceProxy::IsPresentFailSafeOS(uint32_t in_connId) {
  return (*m_method_IsPresentFailSafeOS)(in_connId);

}
DBus::MultipleReturn<std::string, int32_t, int32_t, std::string, bool, int32_t, uint32_t> com_jci_UPDATES_Sys_Ipc_InterfaceProxy::GetPackageInfo(
    uint32_t in_connId,
    std::string in_upLocation) {
  return (*m_method_GetPackageInfo)(in_connId, in_upLocation);

}
DBus::MultipleReturn<std::string, int32_t, int32_t, std::string, bool, int32_t, uint32_t> com_jci_UPDATES_Sys_Ipc_InterfaceProxy::ValidateUP(
    uint32_t in_connId,
    std::string in_upLocation) {
  return (*m_method_ValidateUP)(in_connId, in_upLocation);

}
DBus::MultipleReturn <int32_t, uint32_t> com_jci_UPDATES_Sys_Ipc_InterfaceProxy::CancelValidate(uint32_t in_connId) {
  return (*m_method_CancelValidate)(in_connId);

}
DBus::MultipleReturn <int32_t, int32_t, int32_t, int32_t, uint32_t> com_jci_UPDATES_Sys_Ipc_InterfaceProxy::InstallUP(
    uint32_t in_connId,
    std::string in_upLocation,
    int32_t in_installCtrlOpt) {
  return (*m_method_InstallUP)(in_connId, in_upLocation, in_installCtrlOpt);

}
DBus::MultipleReturn <int32_t, uint32_t> com_jci_UPDATES_Sys_Ipc_InterfaceProxy::CancelInstall(uint32_t in_connId) {
  return (*m_method_CancelInstall)(in_connId);

}
DBus::MultipleReturn <int32_t, uint32_t, int32_t, uint32_t> com_jci_UPDATES_Sys_Ipc_InterfaceProxy::GetUpdateStatus(
    uint32_t in_connId) {
  return (*m_method_GetUpdateStatus)(in_connId);

}
std::shared_ptr <DBus::SignalProxy<void(int32_t,
                                        uint32_t,
                                        int32_t,
                                        uint32_t)>> com_jci_UPDATES_Sys_Ipc_InterfaceProxy::signal_update_status_event() {
  return m_signalproxy_update_status_event;

}
