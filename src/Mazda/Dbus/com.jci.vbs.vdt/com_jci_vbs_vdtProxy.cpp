#include "com_jci_vbs_vdtProxy.h"

com_jci_vbs_vdtProxy::com_jci_vbs_vdtProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_BLM_Startup_Initiated = this->create_method<int32_t(bool)>("BLM_Startup_Initiated");
  m_signalproxy_SISS_EngineState = this->create_signal<void(uint8_t)>("SISS_EngineState");
  m_signalproxy_SISSStatus = this->create_signal<void(bool)>("SISSStatus");
  m_signalproxy_DR_EVM_MSG = this->create_signal<void(uint8_t)>("DR_EVM_MSG");
  m_signalproxy_Veh_V_ActlEng = this->create_signal<void(uint16_t)>("Veh_V_ActlEng");
  m_signalproxy_VehVActlEng_D_Qf = this->create_signal<void(uint8_t)>("VehVActlEng_D_Qf");
  m_signalproxy_OdoCount = this->create_signal<void(uint8_t)>("OdoCount");
  m_signalproxy_FuelPulse = this->create_signal<void(uint8_t)>("FuelPulse");
  m_signalproxy_OdoCount_2 = this->create_signal<void(uint8_t)>("OdoCount_2");
  m_signalproxy_FuelPulse_2 = this->create_signal<void(uint8_t)>("FuelPulse_2");
  m_signalproxy_EngAout_N_Actl = this->create_signal<void(uint16_t)>("EngAout_N_Actl");
  m_signalproxy_ApedPos_Pc_ActlArb = this->create_signal<void(uint16_t)>("ApedPos_Pc_ActlArb");
  m_signalproxy_ApedPosPcActl_D_Qf = this->create_signal<void(uint8_t)>("ApedPosPcActl_D_Qf");
  m_signalproxy_SteWhlComp_An_Est = this->create_signal<void(uint16_t)>("SteWhlComp_An_Est");
  m_signalproxy_VehLong_A_Actl = this->create_signal<void(uint16_t)>("VehLong_A_Actl");
  m_signalproxy_FSC_Diag_Rx = this->create_signal<void(uint64_t)>("FSC_Diag_Rx");
  m_signalproxy_HEC_Diag_Rx = this->create_signal<void(uint64_t)>("HEC_Diag_Rx");
  m_signalproxy_HEVHEC_Diag_Rx = this->create_signal<void(uint64_t)>("HEVHEC_Diag_Rx");
  m_signalproxy_FBCM_Diag_Rx = this->create_signal<void(uint64_t)>("FBCM_Diag_Rx");
  m_signalproxy_EPAS_Diag_Rx = this->create_signal<void(uint64_t)>("EPAS_Diag_Rx");
  m_signalproxy_SSU_Diag_Rx = this->create_signal<void(uint64_t)>("SSU_Diag_Rx");
  m_signalproxy_AFS_Diag_Rx = this->create_signal<void(uint64_t)>("AFS_Diag_Rx");
  m_signalproxy_RCM_Diag_Rx = this->create_signal<void(uint64_t)>("RCM_Diag_Rx");
  m_signalproxy_REGEN_Diag_Sig_Rx = this->create_signal<void(uint64_t)>("REGEN_Diag_Sig_Rx");
  m_signalproxy_ABS_Diag_Rx = this->create_signal<void(uint64_t)>("ABS_Diag_Rx");
  m_signalproxy_AWD_Diag_Rx = this->create_signal<void(uint64_t)>("AWD_Diag_Rx");
  m_signalproxy_CCM_Diag_Rx = this->create_signal<void(uint64_t)>("CCM_Diag_Rx");
  m_signalproxy_ICA_Diag_Rx = this->create_signal<void(uint64_t)>("ICA_Diag_Rx");
  m_signalproxy_AMP_Diag_Rx = this->create_signal<void(uint64_t)>("AMP_Diag_Rx");
  m_signalproxy_EATC_Diag_Rx = this->create_signal<void(uint64_t)>("EATC_Diag_Rx");
  m_signalproxy_RBCM_Diag_Rx = this->create_signal<void(uint64_t)>("RBCM_Diag_Rx");
  m_signalproxy_BSM_RVM_Diag_Rx = this->create_signal<void(uint64_t)>("BSM_RVM_Diag_Rx");
  m_signalproxy_PCM_DTC = this->create_signal<void(uint64_t)>("PCM_DTC");
  m_signalproxy_TCM_DTC = this->create_signal<void(uint64_t)>("TCM_DTC");
  m_signalproxy_ECB_Diag_Rx = this->create_signal<void(uint64_t)>("ECB_Diag_Rx");
  m_signalproxy_PLK_Diag_Rx = this->create_signal<void(uint64_t)>("PLK_Diag_Rx");
  m_signalproxy_HEV_Diag_Rx = this->create_signal<void(uint64_t)>("HEV_Diag_Rx");
  m_signalproxy_ACN_Diag_Rx = this->create_signal<void(uint64_t)>("ACN_Diag_Rx");
  m_signalproxy_Ignition_Status = this->create_signal<void(uint8_t)>("Ignition_Status");
  m_signalproxy_Lateral_Acceleration = this->create_signal<void(uint16_t)>("Lateral_Acceleration");
  m_signalproxy_CAN_Missing_Ind =
      this->create_signal<void(std::tuple < uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t > )>(
          "CAN_Missing_Ind");
  m_signalproxy_EOLDriveChartDisplay = this->create_signal<void(uint8_t)>("EOLDriveChartDisplay");
  m_signalproxy_EOLMyDoctorDisplay = this->create_signal<void(uint8_t)>("EOLMyDoctorDisplay");
  m_signalproxy_EOLDriveChart_Log_Distance = this->create_signal<void(uint8_t)>("EOLDriveChart_Log_Distance");
  m_signalproxy_EOLDriveChart_DataTrans = this->create_signal<void(uint8_t)>("EOLDriveChart_DataTrans");
  m_signalproxy_IgnitionStatus_TSec = this->create_signal<void(uint8_t, uint8_t)>("IgnitionStatus_TSec");
  m_signalproxy_LampActivationNotify = this->create_signal<void(uint8_t, uint8_t)>("LampActivationNotify");
  m_signalproxy_FuelType = this->create_signal<void(uint8_t)>("FuelType");
  m_signalproxy_OnOdrDataFullyReceived = this->create_signal<void()>("OnOdrDataFullyReceived");
  m_signalproxy_Total_Distance = this->create_signal<void(uint32_t)>("Total_Distance");
  m_signalproxy_GlobalRealTime = this->create_signal<void(uint32_t)>("GlobalRealTime");
  m_signalproxy_Sds_TotSD_Point_D_Actl_2 = this->create_signal<void(uint8_t)>("Sds_TotSD_Point_D_Actl_2");

}
std::shared_ptr <com_jci_vbs_vdtProxy> com_jci_vbs_vdtProxy::create(std::string name) {
  return std::shared_ptr<com_jci_vbs_vdtProxy>(new com_jci_vbs_vdtProxy(name));

}
int32_t com_jci_vbs_vdtProxy::BLM_Startup_Initiated(bool vdt_blm_init) {
  return (*m_method_BLM_Startup_Initiated)(vdt_blm_init);

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_vdtProxy::signal_SISS_EngineState() {
  return m_signalproxy_SISS_EngineState;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_vbs_vdtProxy::signal_SISSStatus() {
  return m_signalproxy_SISSStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_vdtProxy::signal_DR_EVM_MSG() {
  return m_signalproxy_DR_EVM_MSG;

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t)>> com_jci_vbs_vdtProxy::signal_Veh_V_ActlEng() {
  return m_signalproxy_Veh_V_ActlEng;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_vdtProxy::signal_VehVActlEng_D_Qf() {
  return m_signalproxy_VehVActlEng_D_Qf;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_vdtProxy::signal_OdoCount() {
  return m_signalproxy_OdoCount;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_vdtProxy::signal_FuelPulse() {
  return m_signalproxy_FuelPulse;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_vdtProxy::signal_OdoCount_2() {
  return m_signalproxy_OdoCount_2;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_vdtProxy::signal_FuelPulse_2() {
  return m_signalproxy_FuelPulse_2;

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t)>> com_jci_vbs_vdtProxy::signal_EngAout_N_Actl() {
  return m_signalproxy_EngAout_N_Actl;

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t)>> com_jci_vbs_vdtProxy::signal_ApedPos_Pc_ActlArb() {
  return m_signalproxy_ApedPos_Pc_ActlArb;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_vdtProxy::signal_ApedPosPcActl_D_Qf() {
  return m_signalproxy_ApedPosPcActl_D_Qf;

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t)>> com_jci_vbs_vdtProxy::signal_SteWhlComp_An_Est() {
  return m_signalproxy_SteWhlComp_An_Est;

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t)>> com_jci_vbs_vdtProxy::signal_VehLong_A_Actl() {
  return m_signalproxy_VehLong_A_Actl;

}
std::shared_ptr <DBus::SignalProxy<void(uint64_t)>> com_jci_vbs_vdtProxy::signal_FSC_Diag_Rx() {
  return m_signalproxy_FSC_Diag_Rx;

}
std::shared_ptr <DBus::SignalProxy<void(uint64_t)>> com_jci_vbs_vdtProxy::signal_HEC_Diag_Rx() {
  return m_signalproxy_HEC_Diag_Rx;

}
std::shared_ptr <DBus::SignalProxy<void(uint64_t)>> com_jci_vbs_vdtProxy::signal_HEVHEC_Diag_Rx() {
  return m_signalproxy_HEVHEC_Diag_Rx;

}
std::shared_ptr <DBus::SignalProxy<void(uint64_t)>> com_jci_vbs_vdtProxy::signal_FBCM_Diag_Rx() {
  return m_signalproxy_FBCM_Diag_Rx;

}
std::shared_ptr <DBus::SignalProxy<void(uint64_t)>> com_jci_vbs_vdtProxy::signal_EPAS_Diag_Rx() {
  return m_signalproxy_EPAS_Diag_Rx;

}
std::shared_ptr <DBus::SignalProxy<void(uint64_t)>> com_jci_vbs_vdtProxy::signal_SSU_Diag_Rx() {
  return m_signalproxy_SSU_Diag_Rx;

}
std::shared_ptr <DBus::SignalProxy<void(uint64_t)>> com_jci_vbs_vdtProxy::signal_AFS_Diag_Rx() {
  return m_signalproxy_AFS_Diag_Rx;

}
std::shared_ptr <DBus::SignalProxy<void(uint64_t)>> com_jci_vbs_vdtProxy::signal_RCM_Diag_Rx() {
  return m_signalproxy_RCM_Diag_Rx;

}
std::shared_ptr <DBus::SignalProxy<void(uint64_t)>> com_jci_vbs_vdtProxy::signal_REGEN_Diag_Sig_Rx() {
  return m_signalproxy_REGEN_Diag_Sig_Rx;

}
std::shared_ptr <DBus::SignalProxy<void(uint64_t)>> com_jci_vbs_vdtProxy::signal_ABS_Diag_Rx() {
  return m_signalproxy_ABS_Diag_Rx;

}
std::shared_ptr <DBus::SignalProxy<void(uint64_t)>> com_jci_vbs_vdtProxy::signal_AWD_Diag_Rx() {
  return m_signalproxy_AWD_Diag_Rx;

}
std::shared_ptr <DBus::SignalProxy<void(uint64_t)>> com_jci_vbs_vdtProxy::signal_CCM_Diag_Rx() {
  return m_signalproxy_CCM_Diag_Rx;

}
std::shared_ptr <DBus::SignalProxy<void(uint64_t)>> com_jci_vbs_vdtProxy::signal_ICA_Diag_Rx() {
  return m_signalproxy_ICA_Diag_Rx;

}
std::shared_ptr <DBus::SignalProxy<void(uint64_t)>> com_jci_vbs_vdtProxy::signal_AMP_Diag_Rx() {
  return m_signalproxy_AMP_Diag_Rx;

}
std::shared_ptr <DBus::SignalProxy<void(uint64_t)>> com_jci_vbs_vdtProxy::signal_EATC_Diag_Rx() {
  return m_signalproxy_EATC_Diag_Rx;

}
std::shared_ptr <DBus::SignalProxy<void(uint64_t)>> com_jci_vbs_vdtProxy::signal_RBCM_Diag_Rx() {
  return m_signalproxy_RBCM_Diag_Rx;

}
std::shared_ptr <DBus::SignalProxy<void(uint64_t)>> com_jci_vbs_vdtProxy::signal_BSM_RVM_Diag_Rx() {
  return m_signalproxy_BSM_RVM_Diag_Rx;

}
std::shared_ptr <DBus::SignalProxy<void(uint64_t)>> com_jci_vbs_vdtProxy::signal_PCM_DTC() {
  return m_signalproxy_PCM_DTC;

}
std::shared_ptr <DBus::SignalProxy<void(uint64_t)>> com_jci_vbs_vdtProxy::signal_TCM_DTC() {
  return m_signalproxy_TCM_DTC;

}
std::shared_ptr <DBus::SignalProxy<void(uint64_t)>> com_jci_vbs_vdtProxy::signal_ECB_Diag_Rx() {
  return m_signalproxy_ECB_Diag_Rx;

}
std::shared_ptr <DBus::SignalProxy<void(uint64_t)>> com_jci_vbs_vdtProxy::signal_PLK_Diag_Rx() {
  return m_signalproxy_PLK_Diag_Rx;

}
std::shared_ptr <DBus::SignalProxy<void(uint64_t)>> com_jci_vbs_vdtProxy::signal_HEV_Diag_Rx() {
  return m_signalproxy_HEV_Diag_Rx;

}
std::shared_ptr <DBus::SignalProxy<void(uint64_t)>> com_jci_vbs_vdtProxy::signal_ACN_Diag_Rx() {
  return m_signalproxy_ACN_Diag_Rx;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_vdtProxy::signal_Ignition_Status() {
  return m_signalproxy_Ignition_Status;

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t)>> com_jci_vbs_vdtProxy::signal_Lateral_Acceleration() {
  return m_signalproxy_Lateral_Acceleration;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t > )>> com_jci_vbs_vdtProxy::signal_CAN_Missing_Ind() {
  return m_signalproxy_CAN_Missing_Ind;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_vdtProxy::signal_EOLDriveChartDisplay() {
  return m_signalproxy_EOLDriveChartDisplay;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_vdtProxy::signal_EOLMyDoctorDisplay() {
  return m_signalproxy_EOLMyDoctorDisplay;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_vdtProxy::signal_EOLDriveChart_Log_Distance() {
  return m_signalproxy_EOLDriveChart_Log_Distance;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_vdtProxy::signal_EOLDriveChart_DataTrans() {
  return m_signalproxy_EOLDriveChart_DataTrans;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t, uint8_t)>> com_jci_vbs_vdtProxy::signal_IgnitionStatus_TSec() {
  return m_signalproxy_IgnitionStatus_TSec;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t, uint8_t)>> com_jci_vbs_vdtProxy::signal_LampActivationNotify() {
  return m_signalproxy_LampActivationNotify;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_vdtProxy::signal_FuelType() {
  return m_signalproxy_FuelType;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_vbs_vdtProxy::signal_OnOdrDataFullyReceived() {
  return m_signalproxy_OnOdrDataFullyReceived;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_vbs_vdtProxy::signal_Total_Distance() {
  return m_signalproxy_Total_Distance;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_vbs_vdtProxy::signal_GlobalRealTime() {
  return m_signalproxy_GlobalRealTime;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_vdtProxy::signal_Sds_TotSD_Point_D_Actl_2() {
  return m_signalproxy_Sds_TotSD_Point_D_Actl_2;

}
