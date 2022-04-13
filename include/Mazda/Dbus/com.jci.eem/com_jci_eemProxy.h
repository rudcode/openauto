#ifndef COM_JCI_EEMPROXY_H
#define COM_JCI_EEMPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_eemProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_eemProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_eemProxy> create(std::string name = "com.jci.eem");
  int32_t GetEquippedData();
  int32_t SetEEMUpdateScreenEnable(uint32_t screen_type);
  int32_t CMUResetSettingRequest(uint32_t reset_active);
  uint32_t CMU_UMPResetRequest();
  void EndingScreenSetting(uint32_t endSetActive);
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_SetEquippedData();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> signal_Setting_ResetResponse();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t>)>> signal_CMU_UMPResetResponse();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_HVD_EEMEndSet();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_StDisEco_Active();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_HVD_CstmzRq_Trip();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_EEMEndDispConf();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t, uint32_t>)>> signal_IEloop_ControlStatus();
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> signal_Cumulative_Avg_Fuel_Economy();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_iStop_mode_ControlStatus();
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> signal_iStop_status_ControlStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> signal_iStop_time_ControlStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<bool, bool, uint32_t>)>> signal_iStop_error_ControlStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t>)>> signal_iStop_Effective_Rate();
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> signal_iStop_Effective_time();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t>)>> signal_iEloop_Effective_Rate();
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> signal_iEloop_Effective_Data();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint16_t, uint8_t>)>> signal_CO2_reduction();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint16_t, uint8_t>)>> signal_CO2_Reduction_prevIGNcycle();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint8_t>)>> signal_EEM_Total_Saved_Distance();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    std::vector<std::tuple<uint16_t>>,
                                                    uint32_t>)>> signal_Curr_drive_fuel_eco_line_graph_data();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    std::vector<std::tuple<uint16_t>>,
                                                    uint32_t>)>> signal_Curr_drive_fuel_eco_bar_graph_data();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    std::vector<std::tuple<uint16_t>>,
                                                    uint32_t>)>> signal_Curr_drive_fuel_eco_SixtyMin_bar_graph_data();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    std::vector<std::tuple<uint16_t>>,
                                                    uint32_t>)>> signal_Curr_drive_fuel_eco_OneMin_bar_graph_data();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    std::vector<std::tuple<uint16_t, uint8_t, bool, bool>>,
                                                    uint32_t>)>> signal_Curr_drive_fuel_eco_HEV_SixtyMin_bar_graph_data();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    std::vector<std::tuple<uint16_t, uint8_t, bool, bool>>,
                                                    uint32_t>)>> signal_Curr_drive_fuel_eco_HEV_OneMin_bar_graph_data();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint16_t, uint8_t, uint8_t>)>> signal_OneDriveEVDistance();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint32_t>)>> signal_HEVSendEnergyFlowSignals();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_HEVSendBatteryDisplayLvl();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint8_t, uint8_t>)>> signal_DistDriveEV();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    std::vector<std::tuple<uint32_t>>,
                                                    uint32_t>)>> signal_Cumm_fuel_eco_reset_graph_data();
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> signal_new_Curr_drive_fuel_eco_per_inst_bar_graph_data();
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> signal_new_Curr_drive_fuel_eco_line_graph_data();
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> signal_Curr_avg_drive_fuel_eco();
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> signal_Cum_fuel_eco_after_reset_data_Y1();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_UMP_Reset_enable();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_End_Of_Screen_Data();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<bool>)>> signal_Screen_Ending_message();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_Ignition_Sts();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_HVD_LAST_DISPLAYED_SCREEN();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint32_t>)>> signal_ControlStatusSendTireStatusSignals();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetEquippedData;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_SetEEMUpdateScreenEnable;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_CMUResetSettingRequest;
  std::shared_ptr<DBus::MethodProxy<uint32_t()>> m_method_CMU_UMPResetRequest;
  std::shared_ptr<DBus::MethodProxy<void(uint32_t)>> m_method_EndingScreenSetting;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_SetEquippedData;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> m_signalproxy_Setting_ResetResponse;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t>)>> m_signalproxy_CMU_UMPResetResponse;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_HVD_EEMEndSet;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_StDisEco_Active;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_HVD_CstmzRq_Trip;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_EEMEndDispConf;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t, uint32_t>)>> m_signalproxy_IEloop_ControlStatus;
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> m_signalproxy_Cumulative_Avg_Fuel_Economy;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_iStop_mode_ControlStatus;
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> m_signalproxy_iStop_status_ControlStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> m_signalproxy_iStop_time_ControlStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<bool, bool, uint32_t>)>> m_signalproxy_iStop_error_ControlStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t>)>> m_signalproxy_iStop_Effective_Rate;
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> m_signalproxy_iStop_Effective_time;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t>)>> m_signalproxy_iEloop_Effective_Rate;
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> m_signalproxy_iEloop_Effective_Data;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint16_t, uint8_t>)>> m_signalproxy_CO2_reduction;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint16_t, uint8_t>)>> m_signalproxy_CO2_Reduction_prevIGNcycle;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint8_t>)>> m_signalproxy_EEM_Total_Saved_Distance;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, std::vector<std::tuple<uint16_t>>, uint32_t>)>>
      m_signalproxy_Curr_drive_fuel_eco_line_graph_data;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, std::vector<std::tuple<uint16_t>>, uint32_t>)>>
      m_signalproxy_Curr_drive_fuel_eco_bar_graph_data;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, std::vector<std::tuple<uint16_t>>, uint32_t>)>>
      m_signalproxy_Curr_drive_fuel_eco_SixtyMin_bar_graph_data;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, std::vector<std::tuple<uint16_t>>, uint32_t>)>>
      m_signalproxy_Curr_drive_fuel_eco_OneMin_bar_graph_data;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    std::vector<std::tuple<uint16_t, uint8_t, bool, bool>>,
                                                    uint32_t>)>>
      m_signalproxy_Curr_drive_fuel_eco_HEV_SixtyMin_bar_graph_data;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    std::vector<std::tuple<uint16_t, uint8_t, bool, bool>>,
                                                    uint32_t>)>>
      m_signalproxy_Curr_drive_fuel_eco_HEV_OneMin_bar_graph_data;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint16_t, uint8_t, uint8_t>)>> m_signalproxy_OneDriveEVDistance;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint32_t>)>>
      m_signalproxy_HEVSendEnergyFlowSignals;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_HEVSendBatteryDisplayLvl;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint8_t, uint8_t>)>> m_signalproxy_DistDriveEV;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, std::vector<std::tuple<uint32_t>>, uint32_t>)>>
      m_signalproxy_Cumm_fuel_eco_reset_graph_data;
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> m_signalproxy_new_Curr_drive_fuel_eco_per_inst_bar_graph_data;
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> m_signalproxy_new_Curr_drive_fuel_eco_line_graph_data;
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> m_signalproxy_Curr_avg_drive_fuel_eco;
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> m_signalproxy_Cum_fuel_eco_after_reset_data_Y1;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_UMP_Reset_enable;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_End_Of_Screen_Data;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<bool>)>> m_signalproxy_Screen_Ending_message;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_Ignition_Sts;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_HVD_LAST_DISPLAYED_SCREEN;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint32_t>)>>
      m_signalproxy_ControlStatusSendTireStatusSignals;
};
#endif /* COM_JCI_EEMPROXY_H */
