#include "com_jci_vbs_diagProxy.h"

com_jci_vbs_diagProxy::com_jci_vbs_diagProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_SetFault_Request = this->create_method<uint32_t(uint32_t)>("SetFault_Request");
  m_method_ClearSingleFault_Request = this->create_method<uint32_t(uint32_t)>("ClearSingleFault_Request");
  m_method_GetFaultStatus_Request =
      this->create_method<uint32_t(std::tuple < std::vector < uint32_t > , uint8_t > )>("GetFaultStatus_Request");
  m_method_ReadCMUFaults_Request = this->create_method<uint32_t()>("ReadCMUFaults_Request");
  m_method_ReadAVCFaults_Request = this->create_method<uint32_t()>("ReadAVCFaults_Request");
  m_method_ClearFaults_Request =
      this->create_method<uint32_t(std::tuple < std::vector < uint32_t > , uint8_t > )>("ClearFaults_Request");
  m_method_ClearFaults_HMIRequest = this->create_method<uint32_t()>("ClearFaults_HMIRequest");
  m_method_Routine_Request = this->create_method<uint32_t(uint8_t, uint16_t)>("Routine_Request");
  m_method_Data_Request = this->create_method<uint32_t(uint8_t)>("Data_Request");
  m_method_GGDS_Data_Response =
      this->create_method<uint32_t(std::tuple < uint8_t, std::vector < uint8_t >> )>("GGDS_Data_Response");
  m_method_GGDS_Routine_Response =
      this->create_method<uint32_t(std::tuple < uint32_t, uint8_t, uint8_t > )>("GGDS_Routine_Response");
  m_method_TestScreen_Status_Response = this->create_method<uint32_t(uint8_t)>("TestScreen_Status_Response");
  m_method_TAU_Vehicle_Info_Data_Request = this->create_method<uint32_t(uint8_t)>("TAU_Vehicle_Info_Data_Request");
  m_method_BLM_Ready_Vehicle_Info_Data_Request = this->create_method<std::tuple<uint8_t,
                                                                                uint8_t,
                                                                                uint8_t,
                                                                                uint8_t,
                                                                                uint8_t,
                                                                                uint8_t,
                                                                                uint8_t,
                                                                                uint8_t,
                                                                                uint8_t,
                                                                                uint8_t,
                                                                                uint8_t,
                                                                                uint8_t,
                                                                                uint8_t,
                                                                                uint8_t>()>(
      "BLM_Ready_Vehicle_Info_Data_Request");
  m_method_GenericMessage_Request = this->create_method<uint32_t(uint32_t)>("GenericMessage_Request");
  m_method_PermanentDTCLog_Request = this->create_method<uint32_t()>("PermanentDTCLog_Request");
  m_method_Send_SXM_ESN = this->create_method<uint32_t(std::tuple < std::vector < uint8_t >> )>("Send_SXM_ESN");
  m_signalproxy_GetFaultStatus_Response =
      this->create_signal<void(std::tuple < std::vector < std::tuple < uint32_t, uint8_t >> , uint8_t > )>(
          "GetFaultStatus_Response");
  m_signalproxy_ClearFault_Response =
      this->create_signal<void(std::tuple < std::vector < std::tuple < uint32_t, uint8_t >> , uint8_t > )>(
          "ClearFault_Response");
  m_signalproxy_Clear_HMIResponse =
      this->create_signal<void(std::tuple < uint32_t, uint8_t, uint8_t > )>("Clear_HMIResponse");
  m_signalproxy_GetRoutineStatus_Response =
      this->create_signal<void(std::tuple < uint32_t, uint8_t, uint8_t > )>("GetRoutineStatus_Response");
  m_signalproxy_GetData_Response =
      this->create_signal<void(std::tuple < uint8_t, std::vector < uint8_t >> )>("GetData_Response");
  m_signalproxy_GGDSData_Request = this->create_signal<void(uint8_t)>("GGDSData_Request");
  m_signalproxy_GGDSRoutine_Request = this->create_signal<void(uint8_t)>("GGDSRoutine_Request");
  m_signalproxy_GetVehicleInfoData_Response = this->create_signal<void(std::tuple < uint8_t,
                                                                       uint8_t,
                                                                       uint8_t,
                                                                       uint8_t,
                                                                       uint8_t,
                                                                       uint8_t,
                                                                       uint8_t,
                                                                       uint8_t,
                                                                       uint8_t,
                                                                       uint8_t,
                                                                       uint8_t,
                                                                       uint8_t,
                                                                       uint8_t,
                                                                       uint8_t > )>("GetVehicleInfoData_Response");
  m_signalproxy_GetSystemFailureError_Response =
      this->create_signal<void(uint8_t, uint8_t)>("GetSystemFailureError_Response");
  m_signalproxy_GetTAUVehicleInfoData_Response = this->create_signal<void(std::tuple < uint8_t,
                                                                          uint8_t,
                                                                          uint8_t,
                                                                          uint16_t,
                                                                          uint8_t,
                                                                          uint8_t,
                                                                          uint32_t,
                                                                          uint8_t,
                                                                          uint8_t
                                                                              > )>("GetTAUVehicleInfoData_Response");
  m_signalproxy_Session_Notification = this->create_signal<void(uint8_t)>("Session_Notification");
  m_signalproxy_Vip_Reset_Notification = this->create_signal<void()>("Vip_Reset_Notification");
  m_signalproxy_ReadPermanentDTCLog_Response =
      this->create_signal<void(std::tuple < std::vector < uint8_t >> )>("ReadPermanentDTCLog_Response");
  m_signalproxy_ReadPermanentDTCLogCounter_Response =
      this->create_signal<void(std::tuple < std::vector < uint16_t > , uint8_t > )>(
          "ReadPermanentDTCLogCounter_Response");

}
std::shared_ptr <com_jci_vbs_diagProxy> com_jci_vbs_diagProxy::create(std::string name) {
  return std::shared_ptr<com_jci_vbs_diagProxy>(new com_jci_vbs_diagProxy(name));

}
uint32_t com_jci_vbs_diagProxy::SetFault_Request(uint32_t fault_ID) {
  return (*m_method_SetFault_Request)(fault_ID);

}
uint32_t com_jci_vbs_diagProxy::ClearSingleFault_Request(uint32_t fault_ID) {
  return (*m_method_ClearSingleFault_Request)(fault_ID);

}
uint32_t com_jci_vbs_diagProxy::GetFaultStatus_Request(std::tuple <std::vector<uint32_t>, uint8_t> fault_ID_List) {
  return (*m_method_GetFaultStatus_Request)(fault_ID_List);

}
uint32_t com_jci_vbs_diagProxy::ReadCMUFaults_Request() {
  return (*m_method_ReadCMUFaults_Request)();

}
uint32_t com_jci_vbs_diagProxy::ReadAVCFaults_Request() {
  return (*m_method_ReadAVCFaults_Request)();

}
uint32_t com_jci_vbs_diagProxy::ClearFaults_Request(std::tuple <std::vector<uint32_t>, uint8_t> fault_ID_List) {
  return (*m_method_ClearFaults_Request)(fault_ID_List);

}
uint32_t com_jci_vbs_diagProxy::ClearFaults_HMIRequest() {
  return (*m_method_ClearFaults_HMIRequest)();

}
uint32_t com_jci_vbs_diagProxy::Routine_Request(uint8_t routineID, uint16_t routine_Param) {
  return (*m_method_Routine_Request)(routineID, routine_Param);

}
uint32_t com_jci_vbs_diagProxy::Data_Request(uint8_t dIDNo) {
  return (*m_method_Data_Request)(dIDNo);

}
uint32_t com_jci_vbs_diagProxy::GGDS_Data_Response(std::tuple <uint8_t, std::vector<uint8_t>> data_response) {
  return (*m_method_GGDS_Data_Response)(data_response);

}
uint32_t com_jci_vbs_diagProxy::GGDS_Routine_Response(std::tuple <uint32_t, uint8_t, uint8_t> routine_response) {
  return (*m_method_GGDS_Routine_Response)(routine_response);

}
uint32_t com_jci_vbs_diagProxy::TestScreen_Status_Response(uint8_t testScreenStatus) {
  return (*m_method_TestScreen_Status_Response)(testScreenStatus);

}
uint32_t com_jci_vbs_diagProxy::TAU_Vehicle_Info_Data_Request(uint8_t dIDNo) {
  return (*m_method_TAU_Vehicle_Info_Data_Request)(dIDNo);

}
std::tuple <uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t> com_jci_vbs_diagProxy::BLM_Ready_Vehicle_Info_Data_Request() {
  return (*m_method_BLM_Ready_Vehicle_Info_Data_Request)();

}
uint32_t com_jci_vbs_diagProxy::GenericMessage_Request(uint32_t signalRequest) {
  return (*m_method_GenericMessage_Request)(signalRequest);

}
uint32_t com_jci_vbs_diagProxy::PermanentDTCLog_Request() {
  return (*m_method_PermanentDTCLog_Request)();

}
uint32_t com_jci_vbs_diagProxy::Send_SXM_ESN(std::tuple <std::vector<uint8_t>> vbs_SXM_ESN) {
  return (*m_method_Send_SXM_ESN)(vbs_SXM_ESN);

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < std::vector < std::tuple < uint32_t,
                                        uint8_t >> ,
                                        uint8_t > )>> com_jci_vbs_diagProxy::signal_GetFaultStatus_Response() {
  return m_signalproxy_GetFaultStatus_Response;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < std::vector < std::tuple < uint32_t,
                                        uint8_t >> ,
                                        uint8_t > )>> com_jci_vbs_diagProxy::signal_ClearFault_Response() {
  return m_signalproxy_ClearFault_Response;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint8_t,
                                        uint8_t > )>> com_jci_vbs_diagProxy::signal_Clear_HMIResponse() {
  return m_signalproxy_Clear_HMIResponse;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint8_t,
                                        uint8_t > )>> com_jci_vbs_diagProxy::signal_GetRoutineStatus_Response() {
  return m_signalproxy_GetRoutineStatus_Response;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        std::vector < uint8_t >> )>> com_jci_vbs_diagProxy::signal_GetData_Response() {
  return m_signalproxy_GetData_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_diagProxy::signal_GGDSData_Request() {
  return m_signalproxy_GGDSData_Request;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_diagProxy::signal_GGDSRoutine_Request() {
  return m_signalproxy_GGDSRoutine_Request;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t > )>> com_jci_vbs_diagProxy::signal_GetVehicleInfoData_Response() {
  return m_signalproxy_GetVehicleInfoData_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t,
                                        uint8_t)>> com_jci_vbs_diagProxy::signal_GetSystemFailureError_Response() {
  return m_signalproxy_GetSystemFailureError_Response;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint16_t,
                                        uint8_t,
                                        uint8_t,
                                        uint32_t,
                                        uint8_t,
                                        uint8_t > )>> com_jci_vbs_diagProxy::signal_GetTAUVehicleInfoData_Response() {
  return m_signalproxy_GetTAUVehicleInfoData_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_diagProxy::signal_Session_Notification() {
  return m_signalproxy_Session_Notification;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_vbs_diagProxy::signal_Vip_Reset_Notification() {
  return m_signalproxy_Vip_Reset_Notification;

}
std::shared_ptr <DBus::SignalProxy<void(
    std::tuple < std::vector < uint8_t >> )>> com_jci_vbs_diagProxy::signal_ReadPermanentDTCLog_Response() {
  return m_signalproxy_ReadPermanentDTCLog_Response;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < std::vector < uint16_t > ,
                                        uint8_t
                                            > )>> com_jci_vbs_diagProxy::signal_ReadPermanentDTCLogCounter_Response() {
  return m_signalproxy_ReadPermanentDTCLogCounter_Response;

}
