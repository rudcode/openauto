#ifndef COM_JCI_VBS_EEMPROXY_H
#define COM_JCI_VBS_EEMPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_vbs_eemProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_vbs_eemProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_vbs_eemProxy> create(std::string name = "com.jci.vbs.eem");
  int32_t AvgFuelEco_Rst_CMU(bool fuelEco_Rst_CMU);
  int32_t CstmzRq_Trip_Rst_Mde(uint8_t rq_trip_rst);
  int32_t BLM_Startup_Initiated(bool eem_blm_init);
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> signal_CmltAvlFuelE_D_HEC();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_AvgFuelEco_Rst_HEC();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_PTiStpRdy_B_Actl();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_iStpDenyDPF_B_Actl();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_iStpDenyBatt_B_Actl();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_iStpDenyAC_B_Actl();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_SISS_EngineState();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_SISS_WarningLamp_G();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_SISS_WarningLamp_R();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_iStpDenyPwStr_B_Actl();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_iStpDenyBrk_B_Actl();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_iStpDenyNrange_B_Actl();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_iStpKeySta_B_Actl();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_CpctCrg_Lvl_D_Actl();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_RgnPwr_Lvl_D_Actl();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_CapToElc_B_Actl();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_SISSStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_DistncUnitCnfg_D_Init();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_DistncUnitCnfg_Inh_B_Actl();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_iStpReady_Rq();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_FuelType_Delivery();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_REGEN_Types();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_EndDis_Eco_Req();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_CstmzRsp_Trip_Rst_Mde();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_CstmzStat_Trip_Rst_Mde();
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> signal_Ignition_Status();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_StDis_Eco_Req();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_CMU_Types();
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> signal_CAN_Missing();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_Reset_at_ACC_Off();
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> signal_EngAout_N_Actl();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>)>> signal_HV_CntRecord2();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_DR_SOC_MON();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_HVSYS2_copy();
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> signal_HvEngPcm_Tq_Actl();
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> signal_HvTmPcm_Tq_Actl();
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> signal_HvRgBrk_Tq_Actl();
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> signal_HvMtrGen2Aout_N_Actl();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_RvrseLmpReq_D_Actl();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_Sent_Missed_Signal_Flag();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_VehSpeedFlag();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_OneMinuteTimerExpiry();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_AvgFuelUnitCnfg_D_Init();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t(bool)>> m_method_AvgFuelEco_Rst_CMU;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint8_t)>> m_method_CstmzRq_Trip_Rst_Mde;
  std::shared_ptr<DBus::MethodProxy<int32_t(bool)>> m_method_BLM_Startup_Initiated;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> m_signalproxy_CmltAvlFuelE_D_HEC;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_AvgFuelEco_Rst_HEC;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_PTiStpRdy_B_Actl;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_iStpDenyDPF_B_Actl;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_iStpDenyBatt_B_Actl;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_iStpDenyAC_B_Actl;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_SISS_EngineState;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_SISS_WarningLamp_G;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_SISS_WarningLamp_R;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_iStpDenyPwStr_B_Actl;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_iStpDenyBrk_B_Actl;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_iStpDenyNrange_B_Actl;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_iStpKeySta_B_Actl;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_CpctCrg_Lvl_D_Actl;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_RgnPwr_Lvl_D_Actl;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_CapToElc_B_Actl;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_SISSStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_DistncUnitCnfg_D_Init;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_DistncUnitCnfg_Inh_B_Actl;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_iStpReady_Rq;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_FuelType_Delivery;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_REGEN_Types;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_EndDis_Eco_Req;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_CstmzRsp_Trip_Rst_Mde;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_CstmzStat_Trip_Rst_Mde;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> m_signalproxy_Ignition_Status;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_StDis_Eco_Req;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_CMU_Types;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> m_signalproxy_CAN_Missing;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_Reset_at_ACC_Off;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> m_signalproxy_EngAout_N_Actl;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>)>> m_signalproxy_HV_CntRecord2;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_DR_SOC_MON;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_HVSYS2_copy;
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> m_signalproxy_HvEngPcm_Tq_Actl;
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> m_signalproxy_HvTmPcm_Tq_Actl;
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> m_signalproxy_HvRgBrk_Tq_Actl;
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> m_signalproxy_HvMtrGen2Aout_N_Actl;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_RvrseLmpReq_D_Actl;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_Sent_Missed_Signal_Flag;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_VehSpeedFlag;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_OneMinuteTimerExpiry;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_AvgFuelUnitCnfg_D_Init;
};
#endif /* COM_JCI_VBS_EEMPROXY_H */
