#ifndef COM_JCI_VBS_VDTPROXY_H
#define COM_JCI_VBS_VDTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_vbs_vdtProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_vbs_vdtProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_vbs_vdtProxy> create(std::string name = "com.jci.vbs.vdt");
  int32_t BLM_Startup_Initiated(bool vdt_blm_init);
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_SISS_EngineState();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_SISSStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_DR_EVM_MSG();
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> signal_Veh_V_ActlEng();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_VehVActlEng_D_Qf();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_OdoCount();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_FuelPulse();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_OdoCount_2();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_FuelPulse_2();
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> signal_EngAout_N_Actl();
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> signal_ApedPos_Pc_ActlArb();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_ApedPosPcActl_D_Qf();
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> signal_SteWhlComp_An_Est();
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> signal_VehLong_A_Actl();
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> signal_FSC_Diag_Rx();
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> signal_HEC_Diag_Rx();
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> signal_HEVHEC_Diag_Rx();
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> signal_FBCM_Diag_Rx();
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> signal_EPAS_Diag_Rx();
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> signal_SSU_Diag_Rx();
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> signal_AFS_Diag_Rx();
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> signal_RCM_Diag_Rx();
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> signal_REGEN_Diag_Sig_Rx();
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> signal_ABS_Diag_Rx();
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> signal_AWD_Diag_Rx();
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> signal_CCM_Diag_Rx();
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> signal_ICA_Diag_Rx();
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> signal_AMP_Diag_Rx();
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> signal_EATC_Diag_Rx();
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> signal_RBCM_Diag_Rx();
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> signal_BSM_RVM_Diag_Rx();
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> signal_PCM_DTC();
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> signal_TCM_DTC();
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> signal_ECB_Diag_Rx();
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> signal_PLK_Diag_Rx();
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> signal_HEV_Diag_Rx();
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> signal_ACN_Diag_Rx();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_Ignition_Status();
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> signal_Lateral_Acceleration();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t>)>> signal_CAN_Missing_Ind();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_EOLDriveChartDisplay();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_EOLMyDoctorDisplay();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_EOLDriveChart_Log_Distance();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_EOLDriveChart_DataTrans();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t)>> signal_IgnitionStatus_TSec();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t)>> signal_LampActivationNotify();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_FuelType();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_OnOdrDataFullyReceived();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_Total_Distance();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_GlobalRealTime();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_Sds_TotSD_Point_D_Actl_2();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t(bool)>> m_method_BLM_Startup_Initiated;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_SISS_EngineState;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_SISSStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_DR_EVM_MSG;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> m_signalproxy_Veh_V_ActlEng;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_VehVActlEng_D_Qf;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_OdoCount;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_FuelPulse;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_OdoCount_2;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_FuelPulse_2;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> m_signalproxy_EngAout_N_Actl;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> m_signalproxy_ApedPos_Pc_ActlArb;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_ApedPosPcActl_D_Qf;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> m_signalproxy_SteWhlComp_An_Est;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> m_signalproxy_VehLong_A_Actl;
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> m_signalproxy_FSC_Diag_Rx;
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> m_signalproxy_HEC_Diag_Rx;
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> m_signalproxy_HEVHEC_Diag_Rx;
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> m_signalproxy_FBCM_Diag_Rx;
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> m_signalproxy_EPAS_Diag_Rx;
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> m_signalproxy_SSU_Diag_Rx;
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> m_signalproxy_AFS_Diag_Rx;
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> m_signalproxy_RCM_Diag_Rx;
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> m_signalproxy_REGEN_Diag_Sig_Rx;
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> m_signalproxy_ABS_Diag_Rx;
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> m_signalproxy_AWD_Diag_Rx;
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> m_signalproxy_CCM_Diag_Rx;
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> m_signalproxy_ICA_Diag_Rx;
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> m_signalproxy_AMP_Diag_Rx;
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> m_signalproxy_EATC_Diag_Rx;
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> m_signalproxy_RBCM_Diag_Rx;
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> m_signalproxy_BSM_RVM_Diag_Rx;
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> m_signalproxy_PCM_DTC;
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> m_signalproxy_TCM_DTC;
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> m_signalproxy_ECB_Diag_Rx;
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> m_signalproxy_PLK_Diag_Rx;
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> m_signalproxy_HEV_Diag_Rx;
  std::shared_ptr<DBus::SignalProxy<void(uint64_t)>> m_signalproxy_ACN_Diag_Rx;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_Ignition_Status;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> m_signalproxy_Lateral_Acceleration;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t>)>> m_signalproxy_CAN_Missing_Ind;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_EOLDriveChartDisplay;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_EOLMyDoctorDisplay;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_EOLDriveChart_Log_Distance;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_EOLDriveChart_DataTrans;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t)>> m_signalproxy_IgnitionStatus_TSec;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t)>> m_signalproxy_LampActivationNotify;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_FuelType;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_OnOdrDataFullyReceived;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_Total_Distance;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_GlobalRealTime;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_Sds_TotSD_Point_D_Actl_2;
};
#endif /* COM_JCI_VBS_VDTPROXY_H */
