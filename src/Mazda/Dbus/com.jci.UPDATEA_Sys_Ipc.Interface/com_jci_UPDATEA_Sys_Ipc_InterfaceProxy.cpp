#include "com_jci_UPDATEA_Sys_Ipc_InterfaceProxy.h"

com_jci_UPDATEA_Sys_Ipc_InterfaceProxy::com_jci_UPDATEA_Sys_Ipc_InterfaceProxy(std::string name) : DBus::InterfaceProxy(
    name) {
  m_method_Connect = this->create_method<DBus::MultipleReturn<int32_t, uint32_t>(uint32_t)>("Connect");
  m_method_Disconnect = this->create_method<DBus::MultipleReturn<int32_t, uint32_t>(uint32_t)>("Disconnect");
  m_method_GetVersion = this->create_method<DBus::MultipleReturn<int32_t, std::string, int32_t, uint32_t>(uint32_t,
                                                                                                          int32_t)>(
      "GetVersion");
  m_method_IsPresentFailSafeOS =
      this->create_method<DBus::MultipleReturn<bool, int32_t, uint32_t>(uint32_t)>("IsPresentFailSafeOS");
  m_method_SearchForAvailableUPs = this->create_method < DBus::MultipleReturn < std::tuple < std::vector < std::tuple
      < std::string, int32_t, std::string>>>,int32_t, uint32_t > (uint32_t) > ("SearchForAvailableUPs");
  m_method_CancelSearchForUPs =
      this->create_method<DBus::MultipleReturn<int32_t, uint32_t>(uint32_t)>("CancelSearchForUPs");
  m_method_ValidateAndDownloadUP =
      this->create_method<DBus::MultipleReturn<int32_t, uint32_t>(uint32_t, std::string)>("ValidateAndDownloadUP");
  m_method_CancelValidAndDwnld =
      this->create_method<DBus::MultipleReturn<int32_t, uint32_t>(uint32_t)>("CancelValidAndDwnld");
  m_method_InstallUP = this->create_method<DBus::MultipleReturn<int32_t, uint32_t>(uint32_t)>("InstallUP");
  m_method_GetUpdateStatus =
      this->create_method<DBus::MultipleReturn<int32_t, uint32_t, int32_t, uint32_t>(uint32_t)>("GetUpdateStatus");
  m_method_RebootBoard = this->create_method<DBus::MultipleReturn<int32_t, uint32_t>(uint32_t)>("RebootBoard");
  m_signalproxy_available_ups_event = this->create_signal < void(std::tuple < std::vector < std::tuple < std::string,
                                                                 int32_t,
                                                                 std::string>>>,uint32_t)>("available_ups_event");
  m_signalproxy_available_autoupdate_event =
      this->create_signal<void(std::tuple < std::string, int32_t, std::string > , uint32_t)>(
          "available_autoupdate_event");
  m_signalproxy_update_status_event =
      this->create_signal<void(int32_t, uint32_t, int32_t, uint32_t)>("update_status_event");

}
std::shared_ptr <com_jci_UPDATEA_Sys_Ipc_InterfaceProxy> com_jci_UPDATEA_Sys_Ipc_InterfaceProxy::create(std::string name) {
  return std::shared_ptr<com_jci_UPDATEA_Sys_Ipc_InterfaceProxy>(new com_jci_UPDATEA_Sys_Ipc_InterfaceProxy(name));

}
DBus::MultipleReturn <int32_t, uint32_t> com_jci_UPDATEA_Sys_Ipc_InterfaceProxy::Connect(uint32_t in_connId) {
  return (*m_method_Connect)(in_connId);

}
DBus::MultipleReturn <int32_t, uint32_t> com_jci_UPDATEA_Sys_Ipc_InterfaceProxy::Disconnect(uint32_t in_connId) {
  return (*m_method_Disconnect)(in_connId);

}
DBus::MultipleReturn <int32_t, std::string, int32_t, uint32_t> com_jci_UPDATEA_Sys_Ipc_InterfaceProxy::GetVersion(
    uint32_t in_connId,
    int32_t in_versionType) {
  return (*m_method_GetVersion)(in_connId, in_versionType);

}
DBus::MultipleReturn<bool, int32_t, uint32_t> com_jci_UPDATEA_Sys_Ipc_InterfaceProxy::IsPresentFailSafeOS(uint32_t in_connId) {
  return (*m_method_IsPresentFailSafeOS)(in_connId);

}
DBus::MultipleReturn <std::tuple<std::vector < std::tuple < std::string, int32_t, std::string>>>,int32_t,uint32_t>
com_jci_UPDATEA_Sys_Ipc_InterfaceProxy::SearchForAvailableUPs(uint32_t
in_connId ){
return (*m_method_SearchForAvailableUPs)(in_connId);

}
DBus::MultipleReturn <int32_t, uint32_t> com_jci_UPDATEA_Sys_Ipc_InterfaceProxy::CancelSearchForUPs(uint32_t
in_connId ){
return (*m_method_CancelSearchForUPs)(in_connId);

}
DBus::MultipleReturn <int32_t, uint32_t> com_jci_UPDATEA_Sys_Ipc_InterfaceProxy::ValidateAndDownloadUP(uint32_t
in_connId,
std::string in_upLocation
){
return (*m_method_ValidateAndDownloadUP)(in_connId,in_upLocation);

}
DBus::MultipleReturn <int32_t, uint32_t> com_jci_UPDATEA_Sys_Ipc_InterfaceProxy::CancelValidAndDwnld(uint32_t
in_connId ){
return (*m_method_CancelValidAndDwnld)(in_connId);

}
DBus::MultipleReturn <int32_t, uint32_t> com_jci_UPDATEA_Sys_Ipc_InterfaceProxy::InstallUP(uint32_t
in_connId ){
return (*m_method_InstallUP)(in_connId);

}
DBus::MultipleReturn <int32_t, uint32_t, int32_t, uint32_t>
    com_jci_UPDATEA_Sys_Ipc_InterfaceProxy::GetUpdateStatus(uint32_t
in_connId ){
return (*m_method_GetUpdateStatus)(in_connId);

}
DBus::MultipleReturn <int32_t, uint32_t> com_jci_UPDATEA_Sys_Ipc_InterfaceProxy::RebootBoard(uint32_t
in_connId ){
return (*m_method_RebootBoard)(in_connId);

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < std::vector < std::tuple < std::string,
                                        int32_t,
                                        std::string>>>,uint32_t)>>
com_jci_UPDATEA_Sys_Ipc_InterfaceProxy::signal_available_ups_event() {
  return m_signalproxy_available_ups_event;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < std::string,
                                        int32_t,
                                        std::string > ,
                                        uint32_t)>> com_jci_UPDATEA_Sys_Ipc_InterfaceProxy::signal_available_autoupdate_event() {
  return m_signalproxy_available_autoupdate_event;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t,
                                        uint32_t,
                                        int32_t,
                                        uint32_t)>> com_jci_UPDATEA_Sys_Ipc_InterfaceProxy::signal_update_status_event() {
  return m_signalproxy_update_status_event;

}
