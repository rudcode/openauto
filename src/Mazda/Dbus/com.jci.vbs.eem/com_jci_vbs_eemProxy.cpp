#include "com_jci_vbs_eemProxy.h"

com_jci_vbs_eemProxy::com_jci_vbs_eemProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_AvgFuelEco_Rst_CMU = this->create_method<int32_t(bool)>("AvgFuelEco_Rst_CMU");
  m_method_CstmzRq_Trip_Rst_Mde = this->create_method<int32_t(uint8_t)>("CstmzRq_Trip_Rst_Mde");
  m_method_BLM_Startup_Initiated = this->create_method<int32_t(bool)>("BLM_Startup_Initiated");
  m_signalproxy_CmltAvlFuelE_D_HEC = this->create_signal<void(uint16_t)>("CmltAvlFuelE_D_HEC");
  m_signalproxy_AvgFuelEco_Rst_HEC = this->create_signal<void(bool)>("AvgFuelEco_Rst_HEC");
  m_signalproxy_PTiStpRdy_B_Actl = this->create_signal<void(bool)>("PTiStpRdy_B_Actl");
  m_signalproxy_iStpDenyDPF_B_Actl = this->create_signal<void(bool)>("iStpDenyDPF_B_Actl");
  m_signalproxy_iStpDenyBatt_B_Actl = this->create_signal<void(bool)>("iStpDenyBatt_B_Actl");
  m_signalproxy_iStpDenyAC_B_Actl = this->create_signal<void(bool)>("iStpDenyAC_B_Actl");
  m_signalproxy_SISS_EngineState = this->create_signal<void(uint8_t)>("SISS_EngineState");
  m_signalproxy_SISS_WarningLamp_G = this->create_signal<void(uint8_t)>("SISS_WarningLamp_G");
  m_signalproxy_SISS_WarningLamp_R = this->create_signal<void(uint8_t)>("SISS_WarningLamp_R");
  m_signalproxy_iStpDenyPwStr_B_Actl = this->create_signal<void(bool)>("iStpDenyPwStr_B_Actl");
  m_signalproxy_iStpDenyBrk_B_Actl = this->create_signal<void(bool)>("iStpDenyBrk_B_Actl");
  m_signalproxy_iStpDenyNrange_B_Actl = this->create_signal<void(bool)>("iStpDenyNrange_B_Actl");
  m_signalproxy_iStpKeySta_B_Actl = this->create_signal<void(bool)>("iStpKeySta_B_Actl");
  m_signalproxy_CpctCrg_Lvl_D_Actl = this->create_signal<void(uint8_t)>("CpctCrg_Lvl_D_Actl");
  m_signalproxy_RgnPwr_Lvl_D_Actl = this->create_signal<void(uint8_t)>("RgnPwr_Lvl_D_Actl");
  m_signalproxy_CapToElc_B_Actl = this->create_signal<void(bool)>("CapToElc_B_Actl");
  m_signalproxy_SISSStatus = this->create_signal<void(bool)>("SISSStatus");
  m_signalproxy_DistncUnitCnfg_D_Init = this->create_signal<void(uint8_t)>("DistncUnitCnfg_D_Init");
  m_signalproxy_DistncUnitCnfg_Inh_B_Actl = this->create_signal<void(bool)>("DistncUnitCnfg_Inh_B_Actl");
  m_signalproxy_iStpReady_Rq = this->create_signal<void(bool)>("iStpReady_Rq");
  m_signalproxy_FuelType_Delivery = this->create_signal<void(uint8_t)>("FuelType_Delivery");
  m_signalproxy_REGEN_Types = this->create_signal<void(uint8_t)>("REGEN_Types");
  m_signalproxy_EndDis_Eco_Req = this->create_signal<void(bool)>("EndDis_Eco_Req");
  m_signalproxy_CstmzRsp_Trip_Rst_Mde = this->create_signal<void(uint8_t)>("CstmzRsp_Trip_Rst_Mde");
  m_signalproxy_CstmzStat_Trip_Rst_Mde = this->create_signal<void(uint8_t)>("CstmzStat_Trip_Rst_Mde");
  m_signalproxy_Ignition_Status = this->create_signal<void(uint16_t)>("Ignition_Status");
  m_signalproxy_StDis_Eco_Req = this->create_signal<void(uint32_t)>("StDis_Eco_Req");
  m_signalproxy_CMU_Types = this->create_signal<void(uint8_t)>("CMU_Types");
  m_signalproxy_CAN_Missing = this->create_signal<void(uint16_t)>("CAN_Missing");
  m_signalproxy_Reset_at_ACC_Off = this->create_signal<void(uint8_t)>("Reset_at_ACC_Off");
  m_signalproxy_EngAout_N_Actl = this->create_signal<void(uint16_t)>("EngAout_N_Actl");
  m_signalproxy_HV_CntRecord2 =
      this->create_signal<void(std::tuple < uint8_t, uint8_t, uint8_t, uint8_t > )>("HV_CntRecord2");
  m_signalproxy_DR_SOC_MON = this->create_signal<void(uint8_t)>("DR_SOC_MON");
  m_signalproxy_HVSYS2_copy = this->create_signal<void(uint8_t)>("HVSYS2_copy");
  m_signalproxy_HvEngPcm_Tq_Actl = this->create_signal<void(int16_t)>("HvEngPcm_Tq_Actl");
  m_signalproxy_HvTmPcm_Tq_Actl = this->create_signal<void(int16_t)>("HvTmPcm_Tq_Actl");
  m_signalproxy_HvRgBrk_Tq_Actl = this->create_signal<void(int16_t)>("HvRgBrk_Tq_Actl");
  m_signalproxy_HvMtrGen2Aout_N_Actl = this->create_signal<void(int16_t)>("HvMtrGen2Aout_N_Actl");
  m_signalproxy_RvrseLmpReq_D_Actl = this->create_signal<void(uint8_t)>("RvrseLmpReq_D_Actl");
  m_signalproxy_Sent_Missed_Signal_Flag = this->create_signal<void()>("Sent_Missed_Signal_Flag");
  m_signalproxy_VehSpeedFlag = this->create_signal<void(uint8_t)>("VehSpeedFlag");
  m_signalproxy_OneMinuteTimerExpiry = this->create_signal<void(bool)>("OneMinuteTimerExpiry");
  m_signalproxy_AvgFuelUnitCnfg_D_Init = this->create_signal<void(uint8_t)>("AvgFuelUnitCnfg_D_Init");

}
std::shared_ptr <com_jci_vbs_eemProxy> com_jci_vbs_eemProxy::create(std::string name) {
  return std::shared_ptr<com_jci_vbs_eemProxy>(new com_jci_vbs_eemProxy(name));

}
int32_t com_jci_vbs_eemProxy::AvgFuelEco_Rst_CMU(bool fuelEco_Rst_CMU) {
  return (*m_method_AvgFuelEco_Rst_CMU)(fuelEco_Rst_CMU);

}
int32_t com_jci_vbs_eemProxy::CstmzRq_Trip_Rst_Mde(uint8_t rq_trip_rst) {
  return (*m_method_CstmzRq_Trip_Rst_Mde)(rq_trip_rst);

}
int32_t com_jci_vbs_eemProxy::BLM_Startup_Initiated(bool eem_blm_init) {
  return (*m_method_BLM_Startup_Initiated)(eem_blm_init);

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t)>> com_jci_vbs_eemProxy::signal_CmltAvlFuelE_D_HEC() {
  return m_signalproxy_CmltAvlFuelE_D_HEC;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_vbs_eemProxy::signal_AvgFuelEco_Rst_HEC() {
  return m_signalproxy_AvgFuelEco_Rst_HEC;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_vbs_eemProxy::signal_PTiStpRdy_B_Actl() {
  return m_signalproxy_PTiStpRdy_B_Actl;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_vbs_eemProxy::signal_iStpDenyDPF_B_Actl() {
  return m_signalproxy_iStpDenyDPF_B_Actl;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_vbs_eemProxy::signal_iStpDenyBatt_B_Actl() {
  return m_signalproxy_iStpDenyBatt_B_Actl;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_vbs_eemProxy::signal_iStpDenyAC_B_Actl() {
  return m_signalproxy_iStpDenyAC_B_Actl;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_eemProxy::signal_SISS_EngineState() {
  return m_signalproxy_SISS_EngineState;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_eemProxy::signal_SISS_WarningLamp_G() {
  return m_signalproxy_SISS_WarningLamp_G;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_eemProxy::signal_SISS_WarningLamp_R() {
  return m_signalproxy_SISS_WarningLamp_R;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_vbs_eemProxy::signal_iStpDenyPwStr_B_Actl() {
  return m_signalproxy_iStpDenyPwStr_B_Actl;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_vbs_eemProxy::signal_iStpDenyBrk_B_Actl() {
  return m_signalproxy_iStpDenyBrk_B_Actl;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_vbs_eemProxy::signal_iStpDenyNrange_B_Actl() {
  return m_signalproxy_iStpDenyNrange_B_Actl;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_vbs_eemProxy::signal_iStpKeySta_B_Actl() {
  return m_signalproxy_iStpKeySta_B_Actl;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_eemProxy::signal_CpctCrg_Lvl_D_Actl() {
  return m_signalproxy_CpctCrg_Lvl_D_Actl;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_eemProxy::signal_RgnPwr_Lvl_D_Actl() {
  return m_signalproxy_RgnPwr_Lvl_D_Actl;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_vbs_eemProxy::signal_CapToElc_B_Actl() {
  return m_signalproxy_CapToElc_B_Actl;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_vbs_eemProxy::signal_SISSStatus() {
  return m_signalproxy_SISSStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_eemProxy::signal_DistncUnitCnfg_D_Init() {
  return m_signalproxy_DistncUnitCnfg_D_Init;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_vbs_eemProxy::signal_DistncUnitCnfg_Inh_B_Actl() {
  return m_signalproxy_DistncUnitCnfg_Inh_B_Actl;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_vbs_eemProxy::signal_iStpReady_Rq() {
  return m_signalproxy_iStpReady_Rq;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_eemProxy::signal_FuelType_Delivery() {
  return m_signalproxy_FuelType_Delivery;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_eemProxy::signal_REGEN_Types() {
  return m_signalproxy_REGEN_Types;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_vbs_eemProxy::signal_EndDis_Eco_Req() {
  return m_signalproxy_EndDis_Eco_Req;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_eemProxy::signal_CstmzRsp_Trip_Rst_Mde() {
  return m_signalproxy_CstmzRsp_Trip_Rst_Mde;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_eemProxy::signal_CstmzStat_Trip_Rst_Mde() {
  return m_signalproxy_CstmzStat_Trip_Rst_Mde;

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t)>> com_jci_vbs_eemProxy::signal_Ignition_Status() {
  return m_signalproxy_Ignition_Status;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_vbs_eemProxy::signal_StDis_Eco_Req() {
  return m_signalproxy_StDis_Eco_Req;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_eemProxy::signal_CMU_Types() {
  return m_signalproxy_CMU_Types;

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t)>> com_jci_vbs_eemProxy::signal_CAN_Missing() {
  return m_signalproxy_CAN_Missing;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_eemProxy::signal_Reset_at_ACC_Off() {
  return m_signalproxy_Reset_at_ACC_Off;

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t)>> com_jci_vbs_eemProxy::signal_EngAout_N_Actl() {
  return m_signalproxy_EngAout_N_Actl;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t > )>> com_jci_vbs_eemProxy::signal_HV_CntRecord2() {
  return m_signalproxy_HV_CntRecord2;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_eemProxy::signal_DR_SOC_MON() {
  return m_signalproxy_DR_SOC_MON;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_eemProxy::signal_HVSYS2_copy() {
  return m_signalproxy_HVSYS2_copy;

}
std::shared_ptr <DBus::SignalProxy<void(int16_t)>> com_jci_vbs_eemProxy::signal_HvEngPcm_Tq_Actl() {
  return m_signalproxy_HvEngPcm_Tq_Actl;

}
std::shared_ptr <DBus::SignalProxy<void(int16_t)>> com_jci_vbs_eemProxy::signal_HvTmPcm_Tq_Actl() {
  return m_signalproxy_HvTmPcm_Tq_Actl;

}
std::shared_ptr <DBus::SignalProxy<void(int16_t)>> com_jci_vbs_eemProxy::signal_HvRgBrk_Tq_Actl() {
  return m_signalproxy_HvRgBrk_Tq_Actl;

}
std::shared_ptr <DBus::SignalProxy<void(int16_t)>> com_jci_vbs_eemProxy::signal_HvMtrGen2Aout_N_Actl() {
  return m_signalproxy_HvMtrGen2Aout_N_Actl;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_eemProxy::signal_RvrseLmpReq_D_Actl() {
  return m_signalproxy_RvrseLmpReq_D_Actl;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_vbs_eemProxy::signal_Sent_Missed_Signal_Flag() {
  return m_signalproxy_Sent_Missed_Signal_Flag;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_eemProxy::signal_VehSpeedFlag() {
  return m_signalproxy_VehSpeedFlag;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_vbs_eemProxy::signal_OneMinuteTimerExpiry() {
  return m_signalproxy_OneMinuteTimerExpiry;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_eemProxy::signal_AvgFuelUnitCnfg_D_Init() {
  return m_signalproxy_AvgFuelUnitCnfg_D_Init;

}
