#ifndef COM_JCI_IDMPROXY_H
#define COM_JCI_IDMPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_idmProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_idmProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_idmProxy> create(std::string name = "com.jci.idm");
  int32_t Get_Config_Data();
  int32_t ACK_Config_Data_Recvd();
  int32_t StopScreenData();
  int32_t GetNormalScreenData();
  int32_t GetTrainingScreenData();
  int32_t GetEndingScreenData();
  int32_t EndingScreenSetting(uint32_t ending_scrn_sett);
  int32_t MeterAmbDispSetting(uint32_t meter_amb_sett);
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_MeterAmbDisp_Rq_Rsp();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_IDM_EOLNormalScreen();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_EOLEndingScrn();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_Ending_Scrn_Setting();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_MeterAmb_Disp_Setting();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_Current_Score();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_Average_Score();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_Stage_Number();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, std::vector<uint8_t>, bool>)>> signal_Driver_Data();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint16_t>, uint8_t>)>> signal_TransitionGraph_Data();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_CurrentBarData();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t>)>> signal_CurrDrvTrend_Brake();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t>)>> signal_CurrDrvTrend_Accel();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t>)>> signal_CurrDrvTrend_Steer();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, bool>)>> signal_StageAchievedData();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_DrivingAdviceId();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_HVD_IDMMode();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_HiScore_Counter();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_MeterAmbDisp_SetRq_Retry();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_End_Of_Screen_Data();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_Display_EndScreen();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_SpeedRest_Flg();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_Ignition_Sts();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Get_Config_Data;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_ACK_Config_Data_Recvd;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_StopScreenData;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetNormalScreenData;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetTrainingScreenData;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetEndingScreenData;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_EndingScreenSetting;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_MeterAmbDispSetting;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_MeterAmbDisp_Rq_Rsp;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_IDM_EOLNormalScreen;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_EOLEndingScrn;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_Ending_Scrn_Setting;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_MeterAmb_Disp_Setting;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_Current_Score;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_Average_Score;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_Stage_Number;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, std::vector<uint8_t>, bool>)>> m_signalproxy_Driver_Data;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint16_t>, uint8_t>)>>
      m_signalproxy_TransitionGraph_Data;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_CurrentBarData;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t>)>> m_signalproxy_CurrDrvTrend_Brake;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t>)>> m_signalproxy_CurrDrvTrend_Accel;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t>)>> m_signalproxy_CurrDrvTrend_Steer;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, bool>)>> m_signalproxy_StageAchievedData;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_DrivingAdviceId;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_HVD_IDMMode;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_HiScore_Counter;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_MeterAmbDisp_SetRq_Retry;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_End_Of_Screen_Data;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_Display_EndScreen;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_SpeedRest_Flg;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_Ignition_Sts;
};
#endif /* COM_JCI_IDMPROXY_H */
