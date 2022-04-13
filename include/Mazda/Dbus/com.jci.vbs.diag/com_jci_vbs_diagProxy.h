#ifndef COM_JCI_VBS_DIAGPROXY_H
#define COM_JCI_VBS_DIAGPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_vbs_diagProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_vbs_diagProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_vbs_diagProxy> create(std::string name = "com.jci.vbs.diag");
  uint32_t SetFault_Request(uint32_t fault_ID);
  uint32_t ClearSingleFault_Request(uint32_t fault_ID);
  uint32_t GetFaultStatus_Request(std::tuple<std::vector<uint32_t>, uint8_t> fault_ID_List);
  uint32_t ReadCMUFaults_Request();
  uint32_t ReadAVCFaults_Request();
  uint32_t ClearFaults_Request(std::tuple<std::vector<uint32_t>, uint8_t> fault_ID_List);
  uint32_t ClearFaults_HMIRequest();
  uint32_t Routine_Request(uint8_t routineID, uint16_t routine_Param);
  uint32_t Data_Request(uint8_t dIDNo);
  uint32_t GGDS_Data_Response(std::tuple<uint8_t, std::vector<uint8_t>> data_response);
  uint32_t GGDS_Routine_Response(std::tuple<uint32_t, uint8_t, uint8_t> routine_response);
  uint32_t TestScreen_Status_Response(uint8_t testScreenStatus);
  uint32_t TAU_Vehicle_Info_Data_Request(uint8_t dIDNo);
  std::tuple<uint8_t,
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
             uint8_t> BLM_Ready_Vehicle_Info_Data_Request();
  uint32_t GenericMessage_Request(uint32_t signalRequest);
  uint32_t PermanentDTCLog_Request();
  uint32_t Send_SXM_ESN(std::tuple<std::vector<uint8_t>> vbs_SXM_ESN);
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<std::tuple<uint32_t, uint8_t>>,
                                                    uint8_t>)>> signal_GetFaultStatus_Response();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<std::tuple<uint32_t, uint8_t>>,
                                                    uint8_t>)>> signal_ClearFault_Response();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint8_t, uint8_t>)>> signal_Clear_HMIResponse();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint8_t, uint8_t>)>> signal_GetRoutineStatus_Response();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, std::vector<uint8_t>>)>> signal_GetData_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_GGDSData_Request();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_GGDSRoutine_Request();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
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
                                                    uint8_t>)>> signal_GetVehicleInfoData_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t)>> signal_GetSystemFailureError_Response();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint16_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint32_t,
                                                    uint8_t,
                                                    uint8_t>)>> signal_GetTAUVehicleInfoData_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_Session_Notification();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_Vip_Reset_Notification();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> signal_ReadPermanentDTCLog_Response();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint16_t>,
                                                    uint8_t>)>> signal_ReadPermanentDTCLogCounter_Response();
 protected:
  std::shared_ptr<DBus::MethodProxy<uint32_t(uint32_t)>> m_method_SetFault_Request;
  std::shared_ptr<DBus::MethodProxy<uint32_t(uint32_t)>> m_method_ClearSingleFault_Request;
  std::shared_ptr<DBus::MethodProxy<uint32_t(std::tuple<std::vector<uint32_t>, uint8_t>)>>
      m_method_GetFaultStatus_Request;
  std::shared_ptr<DBus::MethodProxy<uint32_t()>> m_method_ReadCMUFaults_Request;
  std::shared_ptr<DBus::MethodProxy<uint32_t()>> m_method_ReadAVCFaults_Request;
  std::shared_ptr<DBus::MethodProxy<uint32_t(std::tuple<std::vector<uint32_t>, uint8_t>)>> m_method_ClearFaults_Request;
  std::shared_ptr<DBus::MethodProxy<uint32_t()>> m_method_ClearFaults_HMIRequest;
  std::shared_ptr<DBus::MethodProxy<uint32_t(uint8_t, uint16_t)>> m_method_Routine_Request;
  std::shared_ptr<DBus::MethodProxy<uint32_t(uint8_t)>> m_method_Data_Request;
  std::shared_ptr<DBus::MethodProxy<uint32_t(std::tuple<uint8_t, std::vector<uint8_t>>)>> m_method_GGDS_Data_Response;
  std::shared_ptr<DBus::MethodProxy<uint32_t(std::tuple<uint32_t, uint8_t, uint8_t>)>> m_method_GGDS_Routine_Response;
  std::shared_ptr<DBus::MethodProxy<uint32_t(uint8_t)>> m_method_TestScreen_Status_Response;
  std::shared_ptr<DBus::MethodProxy<uint32_t(uint8_t)>> m_method_TAU_Vehicle_Info_Data_Request;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint8_t,
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
                                               uint8_t>()>> m_method_BLM_Ready_Vehicle_Info_Data_Request;
  std::shared_ptr<DBus::MethodProxy<uint32_t(uint32_t)>> m_method_GenericMessage_Request;
  std::shared_ptr<DBus::MethodProxy<uint32_t()>> m_method_PermanentDTCLog_Request;
  std::shared_ptr<DBus::MethodProxy<uint32_t(std::tuple<std::vector<uint8_t>>)>> m_method_Send_SXM_ESN;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<std::tuple<uint32_t, uint8_t>>, uint8_t>)>>
      m_signalproxy_GetFaultStatus_Response;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<std::tuple<uint32_t, uint8_t>>, uint8_t>)>>
      m_signalproxy_ClearFault_Response;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint8_t, uint8_t>)>> m_signalproxy_Clear_HMIResponse;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint8_t, uint8_t>)>>
      m_signalproxy_GetRoutineStatus_Response;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, std::vector<uint8_t>>)>> m_signalproxy_GetData_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_GGDSData_Request;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_GGDSRoutine_Request;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
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
                                                    uint8_t>)>> m_signalproxy_GetVehicleInfoData_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t)>> m_signalproxy_GetSystemFailureError_Response;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint16_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint32_t,
                                                    uint8_t,
                                                    uint8_t>)>> m_signalproxy_GetTAUVehicleInfoData_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_Session_Notification;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_Vip_Reset_Notification;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> m_signalproxy_ReadPermanentDTCLog_Response;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint16_t>, uint8_t>)>>
      m_signalproxy_ReadPermanentDTCLogCounter_Response;
};
#endif /* COM_JCI_VBS_DIAGPROXY_H */
