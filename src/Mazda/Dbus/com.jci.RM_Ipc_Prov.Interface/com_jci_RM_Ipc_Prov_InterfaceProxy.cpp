#include "com_jci_RM_Ipc_Prov_InterfaceProxy.h"

com_jci_RM_Ipc_Prov_InterfaceProxy::com_jci_RM_Ipc_Prov_InterfaceProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_Connect =
      this->create_method<DBus::MultipleReturn<int32_t, uint32_t, std::string, uint32_t, uint32_t, uint32_t>(uint32_t,
                                                                                                             std::string,
                                                                                                             uint32_t,
                                                                                                             uint32_t,
                                                                                                             uint32_t)>(
          "Connect");
  m_method_PreConnect =
      this->create_method<DBus::MultipleReturn<int32_t, int32_t>(uint32_t, std::string)>("PreConnect");
  m_method_Disconnect =
      this->create_method<DBus::MultipleReturn<int32_t, uint32_t, std::string, uint32_t, uint32_t, uint32_t>(bool,
                                                                                                             uint32_t,
                                                                                                             std::string,
                                                                                                             uint32_t,
                                                                                                             uint32_t,
                                                                                                             uint32_t)>(
          "Disconnect");
  m_method_RegisterResource = this->create_method<DBus::MultipleReturn<std::string,
                                                                       int32_t,
                                                                       std::string,
                                                                       uint32_t,
                                                                       uint32_t,
                                                                       uint32_t>(std::string,
                                                                                 std::tuple < std::vector < std::tuple
                                                                                     < std::string,
                                                                                 int32_t,
                                                                                 std::vector < uint8_t >> >> ,
                                                                                 bool,
                                                                                 std::string,
                                                                                 uint32_t,
                                                                                 uint32_t,
                                                                                 uint32_t)>("RegisterResource");
  m_method_UnregisterResource = this->create_method<DBus::MultipleReturn<std::string,
                                                                         int32_t,
                                                                         std::string,
                                                                         uint32_t,
                                                                         uint32_t,
                                                                         uint32_t>(std::string,
                                                                                   std::tuple < std::vector < std::tuple
                                                                                       < std::string,
                                                                                   int32_t,
                                                                                   std::vector < uint8_t >> >> ,
                                                                                   bool,
                                                                                   std::string,
                                                                                   uint32_t,
                                                                                   uint32_t,
                                                                                   uint32_t)>("UnregisterResource");
  m_method_ActivateResourceResponse = this->create_method<int32_t(std::string,
                                                                  std::tuple < std::vector < std::tuple < std::string,
                                                                  int32_t,
                                                                  std::vector < uint8_t >> >> ,
                                                                  int32_t,
                                                                  std::string,
                                                                  uint32_t)>("ActivateResourceResponse");
  m_method_DeactivateResourceResponse = this->create_method<int32_t(std::string,
                                                                    std::tuple < std::vector < std::tuple < std::string,
                                                                    int32_t,
                                                                    std::vector < uint8_t >> >> ,
                                                                    int32_t,
                                                                    std::string,
                                                                    uint32_t)>("DeactivateResourceResponse");
  m_signalproxy_activate_resource_cb =
      this->create_signal<void(std::string, std::string, uint32_t, uint32_t)>("activate_resource_cb");
  m_signalproxy_deactivate_resource_cb =
      this->create_signal<void(std::string, std::string, uint32_t, uint32_t)>("deactivate_resource_cb");

}
std::shared_ptr <com_jci_RM_Ipc_Prov_InterfaceProxy> com_jci_RM_Ipc_Prov_InterfaceProxy::create(std::string name) {
  return std::shared_ptr<com_jci_RM_Ipc_Prov_InterfaceProxy>(new com_jci_RM_Ipc_Prov_InterfaceProxy(name));

}
DBus::MultipleReturn <int32_t, uint32_t, std::string, uint32_t, uint32_t, uint32_t> com_jci_RM_Ipc_Prov_InterfaceProxy::Connect(
    uint32_t in_provPID,
    std::string in_provName,
    uint32_t in_provConn,
    uint32_t in_provContext,
    uint32_t in_seqId) {
  return (*m_method_Connect)(in_provPID, in_provName, in_provConn, in_provContext, in_seqId);

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_RM_Ipc_Prov_InterfaceProxy::PreConnect(uint32_t in_provPID,
                                                                                       std::string in_provName) {
  return (*m_method_PreConnect)(in_provPID, in_provName);

}
DBus::MultipleReturn <int32_t, uint32_t, std::string, uint32_t, uint32_t, uint32_t> com_jci_RM_Ipc_Prov_InterfaceProxy::Disconnect(
    bool in_force,
    uint32_t in_provPID,
    std::string in_provName,
    uint32_t in_provConn,
    uint32_t in_provContext,
    uint32_t in_seqId) {
  return (*m_method_Disconnect)(in_force, in_provPID, in_provName, in_provConn, in_provContext, in_seqId);

}
DBus::MultipleReturn <std::string, int32_t, std::string, uint32_t, uint32_t, uint32_t> com_jci_RM_Ipc_Prov_InterfaceProxy::RegisterResource(
    std::string in_resName,
    std::tuple <std::vector<std::tuple < std::string, int32_t, std::vector < uint8_t>>
>> in_attributes,
bool in_supportActDeactLogic, std::string
in_provName,
uint32_t in_provConn, uint32_t
in_provContext,
uint32_t in_seqId
){
return (*m_method_RegisterResource)(in_resName,in_attributes,in_supportActDeactLogic,in_provName,in_provConn,in_provContext,in_seqId);

}
DBus::MultipleReturn <std::string, int32_t, std::string, uint32_t, uint32_t, uint32_t> com_jci_RM_Ipc_Prov_InterfaceProxy::UnregisterResource(
    std::string in_resName,
    std::tuple <std::vector<std::tuple < std::string, int32_t, std::vector < uint8_t>>
>> in_attributes,
bool in_force, std::string
in_provName,
uint32_t in_provConn, uint32_t
in_provContext,
uint32_t in_seqId
){
return (*m_method_UnregisterResource)(in_resName,in_attributes,in_force,in_provName,in_provConn,in_provContext,in_seqId);

}
int32_t com_jci_RM_Ipc_Prov_InterfaceProxy::ActivateResourceResponse(std::string in_resName,
                                                                     std::tuple <std::vector<std::tuple < std::string,
                                                                                             int32_t,
                                                                                             std::vector < uint8_t>>
>> in_attributes,
int32_t in_result, std::string
in_provName,
uint32_t in_provConn
){
return (*m_method_ActivateResourceResponse)(in_resName,in_attributes,in_result,in_provName,in_provConn);

}
int32_t com_jci_RM_Ipc_Prov_InterfaceProxy::DeactivateResourceResponse(std::string in_resName,
                                                                       std::tuple <std::vector<std::tuple < std::string,
                                                                                               int32_t,
                                                                                               std::vector < uint8_t>>
>> in_attributes,
int32_t in_result, std::string
in_provName,
uint32_t in_provConn
){
return (*m_method_DeactivateResourceResponse)(in_resName,in_attributes,in_result,in_provName,in_provConn);

}
std::shared_ptr <DBus::SignalProxy<void(std::string,
                                        std::string,
                                        uint32_t,
                                        uint32_t)>> com_jci_RM_Ipc_Prov_InterfaceProxy::signal_activate_resource_cb() {
  return m_signalproxy_activate_resource_cb;

}
std::shared_ptr <DBus::SignalProxy<void(std::string,
                                        std::string,
                                        uint32_t,
                                        uint32_t)>> com_jci_RM_Ipc_Prov_InterfaceProxy::signal_deactivate_resource_cb() {
  return m_signalproxy_deactivate_resource_cb;

}
