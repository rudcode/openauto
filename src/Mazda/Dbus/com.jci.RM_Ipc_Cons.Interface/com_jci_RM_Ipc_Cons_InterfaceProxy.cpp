#include "com_jci_RM_Ipc_Cons_InterfaceProxy.h"

com_jci_RM_Ipc_Cons_InterfaceProxy::com_jci_RM_Ipc_Cons_InterfaceProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_Connect =
      this->create_method<DBus::MultipleReturn<int32_t, uint32_t, std::string, uint32_t, uint32_t, uint32_t>(uint32_t,
                                                                                                             std::string,
                                                                                                             uint32_t,
                                                                                                             uint32_t,
                                                                                                             uint32_t)>(
          "Connect");
  m_method_Disconnect =
      this->create_method<DBus::MultipleReturn<int32_t, uint32_t, std::string, uint32_t, uint32_t, uint32_t>(uint32_t,
                                                                                                             std::string,
                                                                                                             uint32_t,
                                                                                                             uint32_t,
                                                                                                             uint32_t)>(
          "Disconnect");
  m_method_AcquireResource = this->create_method<DBus::MultipleReturn<std::string,
                                                                      int32_t,
                                                                      int32_t,
                                                                      std::string,
                                                                      uint32_t,
                                                                      uint32_t,
                                                                      uint32_t>(std::string,
                                                                                int32_t,
                                                                                std::string,
                                                                                uint32_t,
                                                                                uint32_t,
                                                                                uint32_t)>("AcquireResource");
  m_method_ReleaseResource = this->create_method<DBus::MultipleReturn<std::string,
                                                                      int32_t,
                                                                      int32_t,
                                                                      std::string,
                                                                      uint32_t,
                                                                      uint32_t,
                                                                      uint32_t>(std::string,
                                                                                int32_t,
                                                                                std::string,
                                                                                uint32_t,
                                                                                uint32_t,
                                                                                uint32_t)>("ReleaseResource");
  m_method_GetResourceInfo = this->create_method < DBus::MultipleReturn < std::string, std::tuple < std::vector
      < std::tuple < std::string, int32_t, std::vector
      < uint8_t >> >>, int32_t, int32_t, std::string, uint32_t, uint32_t, uint32_t
      > (std::string, std::string, uint32_t, uint32_t, uint32_t) > ("GetResourceInfo");
  m_method_SubscribeForEvent = this->create_method<DBus::MultipleReturn<std::string,
                                                                        int32_t,
                                                                        int32_t,
                                                                        int32_t,
                                                                        std::string,
                                                                        uint32_t,
                                                                        uint32_t,
                                                                        uint32_t>(std::string,
                                                                                  int32_t,
                                                                                  std::string,
                                                                                  uint32_t,
                                                                                  uint32_t,
                                                                                  uint32_t)>("SubscribeForEvent");
  m_method_UnsubscribeFromEvent = this->create_method<DBus::MultipleReturn<std::string,
                                                                           int32_t,
                                                                           int32_t,
                                                                           std::string,
                                                                           uint32_t,
                                                                           uint32_t,
                                                                           uint32_t>(std::string,
                                                                                     int32_t,
                                                                                     std::string,
                                                                                     uint32_t,
                                                                                     uint32_t,
                                                                                     uint32_t)>("UnsubscribeFromEvent");
  m_signalproxy_acquire_resource_cb =
      this->create_signal<void(std::string, int32_t, int32_t, std::string, uint32_t, uint32_t, uint32_t)>(
          "acquire_resource_cb");
  m_signalproxy_release_command_cb =
      this->create_signal<void(std::string, std::string, uint32_t, uint32_t)>("release_command_cb");
  m_signalproxy_resource_event_cb = this->create_signal<void(std::string,
                                                             std::tuple < std::vector < std::tuple < std::string,
                                                             int32_t,
                                                             std::vector < uint8_t >> >> ,
                                                             int32_t,
                                                             std::string,
                                                             uint32_t,
                                                             uint32_t)>("resource_event_cb");

}
std::shared_ptr <com_jci_RM_Ipc_Cons_InterfaceProxy> com_jci_RM_Ipc_Cons_InterfaceProxy::create(std::string name) {
  return std::shared_ptr<com_jci_RM_Ipc_Cons_InterfaceProxy>(new com_jci_RM_Ipc_Cons_InterfaceProxy(name));

}
DBus::MultipleReturn <int32_t, uint32_t, std::string, uint32_t, uint32_t, uint32_t> com_jci_RM_Ipc_Cons_InterfaceProxy::Connect(
    uint32_t in_consPID,
    std::string in_consName,
    uint32_t in_consConn,
    uint32_t in_consContext,
    uint32_t in_seqId) {
  return (*m_method_Connect)(in_consPID, in_consName, in_consConn, in_consContext, in_seqId);

}
DBus::MultipleReturn <int32_t, uint32_t, std::string, uint32_t, uint32_t, uint32_t> com_jci_RM_Ipc_Cons_InterfaceProxy::Disconnect(
    uint32_t in_consPID,
    std::string in_consName,
    uint32_t in_consConn,
    uint32_t in_consContext,
    uint32_t in_seqId) {
  return (*m_method_Disconnect)(in_consPID, in_consName, in_consConn, in_consContext, in_seqId);

}
DBus::MultipleReturn <std::string, int32_t, int32_t, std::string, uint32_t, uint32_t, uint32_t> com_jci_RM_Ipc_Cons_InterfaceProxy::AcquireResource(
    std::string in_resName,
    int32_t in_action,
    std::string in_consName,
    uint32_t in_consConn,
    uint32_t in_consContext,
    uint32_t in_seqId) {
  return (*m_method_AcquireResource)(in_resName, in_action, in_consName, in_consConn, in_consContext, in_seqId);

}
DBus::MultipleReturn <std::string, int32_t, int32_t, std::string, uint32_t, uint32_t, uint32_t> com_jci_RM_Ipc_Cons_InterfaceProxy::ReleaseResource(
    std::string in_resName,
    int32_t in_action,
    std::string in_consName,
    uint32_t in_consConn,
    uint32_t in_consContext,
    uint32_t in_seqId) {
  return (*m_method_ReleaseResource)(in_resName, in_action, in_consName, in_consConn, in_consContext, in_seqId);

}
DBus::MultipleReturn <std::string, std::tuple<std::vector < std::tuple < std::string,
                                              int32_t,
                                              std::vector
                                                  < uint8_t>>>>,int32_t,int32_t,std::string,uint32_t,uint32_t,uint32_t>
com_jci_RM_Ipc_Cons_InterfaceProxy::GetResourceInfo(std::string
in_resName,
std::string in_consName, uint32_t
in_consConn,
uint32_t in_consContext, uint32_t
in_seqId ){
return (*m_method_GetResourceInfo)(in_resName,in_consName,in_consConn,in_consContext,in_seqId);

}
DBus::MultipleReturn <std::string, int32_t, int32_t, int32_t, std::string, uint32_t, uint32_t, uint32_t> com_jci_RM_Ipc_Cons_InterfaceProxy::SubscribeForEvent(
    std::string in_resName,
    int32_t in_status,
    std::string in_consName,
    uint32_t in_consConn,
    uint32_t in_consContext,
    uint32_t in_seqId) {
  return (*m_method_SubscribeForEvent)(in_resName, in_status, in_consName, in_consConn, in_consContext, in_seqId);

}
DBus::MultipleReturn <std::string, int32_t, int32_t, std::string, uint32_t, uint32_t, uint32_t> com_jci_RM_Ipc_Cons_InterfaceProxy::UnsubscribeFromEvent(
    std::string in_resName,
    int32_t in_status,
    std::string in_consName,
    uint32_t in_consConn,
    uint32_t in_consContext,
    uint32_t in_seqId) {
  return (*m_method_UnsubscribeFromEvent)(in_resName, in_status, in_consName, in_consConn, in_consContext, in_seqId);

}
std::shared_ptr <DBus::SignalProxy<void(std::string,
                                        int32_t,
                                        int32_t,
                                        std::string,
                                        uint32_t,
                                        uint32_t,
                                        uint32_t)>> com_jci_RM_Ipc_Cons_InterfaceProxy::signal_acquire_resource_cb() {
  return m_signalproxy_acquire_resource_cb;

}
std::shared_ptr <DBus::SignalProxy<void(std::string,
                                        std::string,
                                        uint32_t,
                                        uint32_t)>> com_jci_RM_Ipc_Cons_InterfaceProxy::signal_release_command_cb() {
  return m_signalproxy_release_command_cb;

}
std::shared_ptr <DBus::SignalProxy<void(std::string,
                                        std::tuple < std::vector < std::tuple < std::string,
                                        int32_t,
                                        std::vector < uint8_t >> >> ,
                                        int32_t,
                                        std::string,
                                        uint32_t,
                                        uint32_t)>> com_jci_RM_Ipc_Cons_InterfaceProxy::signal_resource_event_cb() {
  return m_signalproxy_resource_event_cb;

}
