#include "com_jci_vbs_drvididmProxy.h"

com_jci_vbs_drvididmProxy::com_jci_vbs_drvididmProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_BLM_Startup_Initiated = this->create_method<int32_t(bool)>("BLM_Startup_Initiated");
  m_method_IDM_AmbientDisplay_Request = this->create_method<int32_t(uint8_t)>("IDM_AmbientDisplay_Request");
  m_method_BLM_Startup_Initiated_Driver = this->create_method<int32_t(bool)>("BLM_Startup_Initiated_Driver");
  m_method_DI_Reliable_Delivery = this->create_method<int32_t(uint8_t)>("DI_Reliable_Delivery");
  m_method_CurrentScore_Hec = this->create_method<int32_t(uint8_t)>("CurrentScore_Hec");
  m_signalproxy_Ignition_Status = this->create_signal<void(uint16_t)>("Ignition_Status");
  m_signalproxy_Eng_StartKey = this->create_signal<void(uint16_t)>("Eng_StartKey");
  m_signalproxy_EngineState = this->create_signal<void(uint16_t)>("EngineState");
  m_signalproxy_IDM_SD_Evl_D_Num = this->create_signal<void(uint16_t)>("IDM_SD_Evl_D_Num");
  m_signalproxy_CAN_Missing_Error = this->create_signal<void(int16_t)>("CAN_Missing_Error");
  m_signalproxy_Sds_TotNG_Par_D_Rq_2 = this->create_signal<void(uint16_t)>("Sds_TotNG_Par_D_Rq_2");
  m_signalproxy_CstmzStat_Ind_Clr_OnOff = this->create_signal<void(uint8_t)>("CstmzStat_Ind_Clr_OnOff");
  m_signalproxy_IDM_SD_CalcInfo_Category = this->create_signal<void(int16_t)>("IDM_SD_CalcInfo_Category");
  m_signalproxy_IDM_SD_CalcInfo_Value = this->create_signal<void(int16_t)>("IDM_SD_CalcInfo_Value");
  m_signalproxy_Sds_TotSD_Avl_D_Actl = this->create_signal<void(uint8_t)>("Sds_TotSD_Avl_D_Actl");
  m_signalproxy_Sds_SD_Stage_D_Actl = this->create_signal<void(uint8_t)>("Sds_SD_Stage_D_Actl");
  m_signalproxy_Sds_TotSD_Point_D_Actl_2 = this->create_signal<void(int16_t)>("Sds_TotSD_Point_D_Actl_2");
  m_signalproxy_EndDis_IDM_Req = this->create_signal<void(uint8_t)>("EndDis_IDM_Req");
  m_signalproxy_StDis_IDM_Req = this->create_signal<void(uint8_t)>("StDis_IDM_Req");
  m_signalproxy_CstmzRsp_Status = this->create_signal<void(uint8_t)>("CstmzRsp_Status");
  m_signalproxy_Sds_SD_Stage_D_Actl2 = this->create_signal<void(uint8_t)>("Sds_SD_Stage_D_Actl2");
  m_signalproxy_Stat_Ign_5s = this->create_signal<void(bool)>("Stat_Ign_5s");
  m_signalproxy_driverIdentification = this->create_signal<void(uint8_t)>("driverIdentification");
  m_signalproxy_Data_Ack_DriverNumber = this->create_signal<void(bool)>("Data_Ack_DriverNumber");
  m_signalproxy_All_sinal_Idm = this->create_signal<void(bool)>("All_sinal_Idm");
  m_signalproxy_All_sinal_Drv = this->create_signal<void(bool)>("All_sinal_Drv");
  m_signalproxy_Timer_Expired_1min = this->create_signal<void()>("Timer_Expired_1min");
  m_signalproxy_CstmzRsp_49bStatus = this->create_signal<void(uint8_t)>("CstmzRsp_49bStatus");

}
std::shared_ptr <com_jci_vbs_drvididmProxy> com_jci_vbs_drvididmProxy::create(std::string name) {
  return std::shared_ptr<com_jci_vbs_drvididmProxy>(new com_jci_vbs_drvididmProxy(name));

}
int32_t com_jci_vbs_drvididmProxy::BLM_Startup_Initiated(bool drvididm_blm_init) {
  return (*m_method_BLM_Startup_Initiated)(drvididm_blm_init);

}
int32_t com_jci_vbs_drvididmProxy::IDM_AmbientDisplay_Request(uint8_t cstmzRq_Ind_Clr_OnOff) {
  return (*m_method_IDM_AmbientDisplay_Request)(cstmzRq_Ind_Clr_OnOff);

}
int32_t com_jci_vbs_drvididmProxy::BLM_Startup_Initiated_Driver(bool drvididm_blm_init_driver) {
  return (*m_method_BLM_Startup_Initiated_Driver)(drvididm_blm_init_driver);

}
int32_t com_jci_vbs_drvididmProxy::DI_Reliable_Delivery(uint8_t reliable_dr_id) {
  return (*m_method_DI_Reliable_Delivery)(reliable_dr_id);

}
int32_t com_jci_vbs_drvididmProxy::CurrentScore_Hec(uint8_t current_score_hec) {
  return (*m_method_CurrentScore_Hec)(current_score_hec);

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t)>> com_jci_vbs_drvididmProxy::signal_Ignition_Status() {
  return m_signalproxy_Ignition_Status;

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t)>> com_jci_vbs_drvididmProxy::signal_Eng_StartKey() {
  return m_signalproxy_Eng_StartKey;

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t)>> com_jci_vbs_drvididmProxy::signal_EngineState() {
  return m_signalproxy_EngineState;

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t)>> com_jci_vbs_drvididmProxy::signal_IDM_SD_Evl_D_Num() {
  return m_signalproxy_IDM_SD_Evl_D_Num;

}
std::shared_ptr <DBus::SignalProxy<void(int16_t)>> com_jci_vbs_drvididmProxy::signal_CAN_Missing_Error() {
  return m_signalproxy_CAN_Missing_Error;

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t)>> com_jci_vbs_drvididmProxy::signal_Sds_TotNG_Par_D_Rq_2() {
  return m_signalproxy_Sds_TotNG_Par_D_Rq_2;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_drvididmProxy::signal_CstmzStat_Ind_Clr_OnOff() {
  return m_signalproxy_CstmzStat_Ind_Clr_OnOff;

}
std::shared_ptr <DBus::SignalProxy<void(int16_t)>> com_jci_vbs_drvididmProxy::signal_IDM_SD_CalcInfo_Category() {
  return m_signalproxy_IDM_SD_CalcInfo_Category;

}
std::shared_ptr <DBus::SignalProxy<void(int16_t)>> com_jci_vbs_drvididmProxy::signal_IDM_SD_CalcInfo_Value() {
  return m_signalproxy_IDM_SD_CalcInfo_Value;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_drvididmProxy::signal_Sds_TotSD_Avl_D_Actl() {
  return m_signalproxy_Sds_TotSD_Avl_D_Actl;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_drvididmProxy::signal_Sds_SD_Stage_D_Actl() {
  return m_signalproxy_Sds_SD_Stage_D_Actl;

}
std::shared_ptr <DBus::SignalProxy<void(int16_t)>> com_jci_vbs_drvididmProxy::signal_Sds_TotSD_Point_D_Actl_2() {
  return m_signalproxy_Sds_TotSD_Point_D_Actl_2;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_drvididmProxy::signal_EndDis_IDM_Req() {
  return m_signalproxy_EndDis_IDM_Req;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_drvididmProxy::signal_StDis_IDM_Req() {
  return m_signalproxy_StDis_IDM_Req;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_drvididmProxy::signal_CstmzRsp_Status() {
  return m_signalproxy_CstmzRsp_Status;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_drvididmProxy::signal_Sds_SD_Stage_D_Actl2() {
  return m_signalproxy_Sds_SD_Stage_D_Actl2;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_vbs_drvididmProxy::signal_Stat_Ign_5s() {
  return m_signalproxy_Stat_Ign_5s;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_drvididmProxy::signal_driverIdentification() {
  return m_signalproxy_driverIdentification;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_vbs_drvididmProxy::signal_Data_Ack_DriverNumber() {
  return m_signalproxy_Data_Ack_DriverNumber;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_vbs_drvididmProxy::signal_All_sinal_Idm() {
  return m_signalproxy_All_sinal_Idm;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_vbs_drvididmProxy::signal_All_sinal_Drv() {
  return m_signalproxy_All_sinal_Drv;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_vbs_drvididmProxy::signal_Timer_Expired_1min() {
  return m_signalproxy_Timer_Expired_1min;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_drvididmProxy::signal_CstmzRsp_49bStatus() {
  return m_signalproxy_CstmzRsp_49bStatus;

}
