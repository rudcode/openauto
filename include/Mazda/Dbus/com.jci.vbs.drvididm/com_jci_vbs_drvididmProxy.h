#ifndef COM_JCI_VBS_DRVIDIDMPROXY_H
#define COM_JCI_VBS_DRVIDIDMPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_vbs_drvididmProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_vbs_drvididmProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_vbs_drvididmProxy> create(std::string name = "com.jci.vbs.drvididm");
  int32_t BLM_Startup_Initiated(bool drvididm_blm_init);
  int32_t IDM_AmbientDisplay_Request(uint8_t cstmzRq_Ind_Clr_OnOff);
  int32_t BLM_Startup_Initiated_Driver(bool drvididm_blm_init_driver);
  int32_t DI_Reliable_Delivery(uint8_t reliable_dr_id);
  int32_t CurrentScore_Hec(uint8_t current_score_hec);
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> signal_Ignition_Status();
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> signal_Eng_StartKey();
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> signal_EngineState();
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> signal_IDM_SD_Evl_D_Num();
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> signal_CAN_Missing_Error();
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> signal_Sds_TotNG_Par_D_Rq_2();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_CstmzStat_Ind_Clr_OnOff();
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> signal_IDM_SD_CalcInfo_Category();
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> signal_IDM_SD_CalcInfo_Value();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_Sds_TotSD_Avl_D_Actl();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_Sds_SD_Stage_D_Actl();
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> signal_Sds_TotSD_Point_D_Actl_2();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_EndDis_IDM_Req();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_StDis_IDM_Req();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_CstmzRsp_Status();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_Sds_SD_Stage_D_Actl2();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_Stat_Ign_5s();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_driverIdentification();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_Data_Ack_DriverNumber();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_All_sinal_Idm();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_All_sinal_Drv();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_Timer_Expired_1min();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_CstmzRsp_49bStatus();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t(bool)>> m_method_BLM_Startup_Initiated;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint8_t)>> m_method_IDM_AmbientDisplay_Request;
  std::shared_ptr<DBus::MethodProxy<int32_t(bool)>> m_method_BLM_Startup_Initiated_Driver;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint8_t)>> m_method_DI_Reliable_Delivery;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint8_t)>> m_method_CurrentScore_Hec;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> m_signalproxy_Ignition_Status;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> m_signalproxy_Eng_StartKey;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> m_signalproxy_EngineState;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> m_signalproxy_IDM_SD_Evl_D_Num;
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> m_signalproxy_CAN_Missing_Error;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> m_signalproxy_Sds_TotNG_Par_D_Rq_2;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_CstmzStat_Ind_Clr_OnOff;
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> m_signalproxy_IDM_SD_CalcInfo_Category;
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> m_signalproxy_IDM_SD_CalcInfo_Value;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_Sds_TotSD_Avl_D_Actl;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_Sds_SD_Stage_D_Actl;
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> m_signalproxy_Sds_TotSD_Point_D_Actl_2;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_EndDis_IDM_Req;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_StDis_IDM_Req;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_CstmzRsp_Status;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_Sds_SD_Stage_D_Actl2;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_Stat_Ign_5s;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_driverIdentification;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_Data_Ack_DriverNumber;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_All_sinal_Idm;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_All_sinal_Drv;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_Timer_Expired_1min;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_CstmzRsp_49bStatus;
};
#endif /* COM_JCI_VBS_DRVIDIDMPROXY_H */
