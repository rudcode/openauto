#include "com_jci_idmProxy.h"

com_jci_idmProxy::com_jci_idmProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_Get_Config_Data = this->create_method<int32_t()>("Get_Config_Data");
  m_method_ACK_Config_Data_Recvd = this->create_method<int32_t()>("ACK_Config_Data_Recvd");
  m_method_StopScreenData = this->create_method<int32_t()>("StopScreenData");
  m_method_GetNormalScreenData = this->create_method<int32_t()>("GetNormalScreenData");
  m_method_GetTrainingScreenData = this->create_method<int32_t()>("GetTrainingScreenData");
  m_method_GetEndingScreenData = this->create_method<int32_t()>("GetEndingScreenData");
  m_method_EndingScreenSetting = this->create_method<int32_t(uint32_t)>("EndingScreenSetting");
  m_method_MeterAmbDispSetting = this->create_method<int32_t(uint32_t)>("MeterAmbDispSetting");
  m_signalproxy_MeterAmbDisp_Rq_Rsp = this->create_signal<void(uint32_t)>("MeterAmbDisp_Rq_Rsp");
  m_signalproxy_IDM_EOLNormalScreen = this->create_signal<void(uint32_t)>("IDM_EOLNormalScreen");
  m_signalproxy_EOLEndingScrn = this->create_signal<void(uint32_t)>("EOLEndingScrn");
  m_signalproxy_Ending_Scrn_Setting = this->create_signal<void(uint32_t)>("Ending_Scrn_Setting");
  m_signalproxy_MeterAmb_Disp_Setting = this->create_signal<void(uint32_t)>("MeterAmb_Disp_Setting");
  m_signalproxy_Current_Score = this->create_signal<void(uint32_t)>("Current_Score");
  m_signalproxy_Average_Score = this->create_signal<void(uint32_t)>("Average_Score");
  m_signalproxy_Stage_Number = this->create_signal<void(uint32_t)>("Stage_Number");
  m_signalproxy_Driver_Data =
      this->create_signal<void(std::tuple < uint8_t, std::vector < uint8_t > , bool > )>("Driver_Data");
  m_signalproxy_TransitionGraph_Data =
      this->create_signal<void(std::tuple < std::vector < uint16_t > , uint8_t > )>("TransitionGraph_Data");
  m_signalproxy_CurrentBarData = this->create_signal<void(int32_t)>("CurrentBarData");
  m_signalproxy_CurrDrvTrend_Brake = this->create_signal<void(std::tuple < uint8_t, uint8_t > )>("CurrDrvTrend_Brake");
  m_signalproxy_CurrDrvTrend_Accel = this->create_signal<void(std::tuple < uint8_t, uint8_t > )>("CurrDrvTrend_Accel");
  m_signalproxy_CurrDrvTrend_Steer = this->create_signal<void(std::tuple < uint8_t, uint8_t > )>("CurrDrvTrend_Steer");
  m_signalproxy_StageAchievedData = this->create_signal<void(std::tuple < uint8_t, bool > )>("StageAchievedData");
  m_signalproxy_DrivingAdviceId = this->create_signal<void(uint32_t)>("DrivingAdviceId");
  m_signalproxy_HVD_IDMMode = this->create_signal<void(uint32_t)>("HVD_IDMMode");
  m_signalproxy_HiScore_Counter = this->create_signal<void(uint32_t)>("HiScore_Counter");
  m_signalproxy_MeterAmbDisp_SetRq_Retry = this->create_signal<void(uint32_t)>("MeterAmbDisp_SetRq_Retry");
  m_signalproxy_End_Of_Screen_Data = this->create_signal<void(uint32_t)>("End_Of_Screen_Data");
  m_signalproxy_Display_EndScreen = this->create_signal<void(uint32_t)>("Display_EndScreen");
  m_signalproxy_SpeedRest_Flg = this->create_signal<void(uint32_t)>("SpeedRest_Flg");
  m_signalproxy_Ignition_Sts = this->create_signal<void(uint32_t)>("Ignition_Sts");

}
std::shared_ptr <com_jci_idmProxy> com_jci_idmProxy::create(std::string name) {
  return std::shared_ptr<com_jci_idmProxy>(new com_jci_idmProxy(name));

}
int32_t com_jci_idmProxy::Get_Config_Data() {
  return (*m_method_Get_Config_Data)();

}
int32_t com_jci_idmProxy::ACK_Config_Data_Recvd() {
  return (*m_method_ACK_Config_Data_Recvd)();

}
int32_t com_jci_idmProxy::StopScreenData() {
  return (*m_method_StopScreenData)();

}
int32_t com_jci_idmProxy::GetNormalScreenData() {
  return (*m_method_GetNormalScreenData)();

}
int32_t com_jci_idmProxy::GetTrainingScreenData() {
  return (*m_method_GetTrainingScreenData)();

}
int32_t com_jci_idmProxy::GetEndingScreenData() {
  return (*m_method_GetEndingScreenData)();

}
int32_t com_jci_idmProxy::EndingScreenSetting(uint32_t ending_scrn_sett) {
  return (*m_method_EndingScreenSetting)(ending_scrn_sett);

}
int32_t com_jci_idmProxy::MeterAmbDispSetting(uint32_t meter_amb_sett) {
  return (*m_method_MeterAmbDispSetting)(meter_amb_sett);

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_idmProxy::signal_MeterAmbDisp_Rq_Rsp() {
  return m_signalproxy_MeterAmbDisp_Rq_Rsp;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_idmProxy::signal_IDM_EOLNormalScreen() {
  return m_signalproxy_IDM_EOLNormalScreen;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_idmProxy::signal_EOLEndingScrn() {
  return m_signalproxy_EOLEndingScrn;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_idmProxy::signal_Ending_Scrn_Setting() {
  return m_signalproxy_Ending_Scrn_Setting;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_idmProxy::signal_MeterAmb_Disp_Setting() {
  return m_signalproxy_MeterAmb_Disp_Setting;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_idmProxy::signal_Current_Score() {
  return m_signalproxy_Current_Score;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_idmProxy::signal_Average_Score() {
  return m_signalproxy_Average_Score;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_idmProxy::signal_Stage_Number() {
  return m_signalproxy_Stage_Number;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        std::vector < uint8_t > ,
                                        bool > )>> com_jci_idmProxy::signal_Driver_Data() {
  return m_signalproxy_Driver_Data;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < std::vector < uint16_t > ,
                                        uint8_t > )>> com_jci_idmProxy::signal_TransitionGraph_Data() {
  return m_signalproxy_TransitionGraph_Data;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_idmProxy::signal_CurrentBarData() {
  return m_signalproxy_CurrentBarData;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t > )>> com_jci_idmProxy::signal_CurrDrvTrend_Brake() {
  return m_signalproxy_CurrDrvTrend_Brake;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t > )>> com_jci_idmProxy::signal_CurrDrvTrend_Accel() {
  return m_signalproxy_CurrDrvTrend_Accel;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t > )>> com_jci_idmProxy::signal_CurrDrvTrend_Steer() {
  return m_signalproxy_CurrDrvTrend_Steer;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t, bool > )>> com_jci_idmProxy::signal_StageAchievedData() {
  return m_signalproxy_StageAchievedData;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_idmProxy::signal_DrivingAdviceId() {
  return m_signalproxy_DrivingAdviceId;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_idmProxy::signal_HVD_IDMMode() {
  return m_signalproxy_HVD_IDMMode;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_idmProxy::signal_HiScore_Counter() {
  return m_signalproxy_HiScore_Counter;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_idmProxy::signal_MeterAmbDisp_SetRq_Retry() {
  return m_signalproxy_MeterAmbDisp_SetRq_Retry;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_idmProxy::signal_End_Of_Screen_Data() {
  return m_signalproxy_End_Of_Screen_Data;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_idmProxy::signal_Display_EndScreen() {
  return m_signalproxy_Display_EndScreen;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_idmProxy::signal_SpeedRest_Flg() {
  return m_signalproxy_SpeedRest_Flg;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_idmProxy::signal_Ignition_Sts() {
  return m_signalproxy_Ignition_Sts;

}
