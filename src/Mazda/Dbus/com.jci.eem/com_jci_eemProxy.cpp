#include "com_jci_eemProxy.h"

com_jci_eemProxy::com_jci_eemProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_GetEquippedData = this->create_method<int32_t()>("GetEquippedData");
  m_method_SetEEMUpdateScreenEnable = this->create_method<int32_t(uint32_t)>("SetEEMUpdateScreenEnable");
  m_method_CMUResetSettingRequest = this->create_method<int32_t(uint32_t)>("CMUResetSettingRequest");
  m_method_CMU_UMPResetRequest = this->create_method<uint32_t()>("CMU_UMPResetRequest");
  m_method_EndingScreenSetting = this->create_method<void(uint32_t)>("EndingScreenSetting");
  m_signalproxy_SetEquippedData = this->create_signal<void(uint32_t)>("SetEquippedData");
  m_signalproxy_Setting_ResetResponse =
      this->create_signal<void(std::tuple < uint32_t, uint32_t > )>("Setting_ResetResponse");
  m_signalproxy_CMU_UMPResetResponse = this->create_signal<void(std::tuple < uint32_t > )>("CMU_UMPResetResponse");
  m_signalproxy_HVD_EEMEndSet = this->create_signal<void(uint32_t)>("HVD_EEMEndSet");
  m_signalproxy_StDisEco_Active = this->create_signal<void(uint32_t)>("StDisEco_Active");
  m_signalproxy_HVD_CstmzRq_Trip = this->create_signal<void(uint32_t)>("HVD_CstmzRq_Trip");
  m_signalproxy_EEMEndDispConf = this->create_signal<void(uint32_t)>("EEMEndDispConf");
  m_signalproxy_IEloop_ControlStatus =
      this->create_signal<void(std::tuple < uint32_t, uint32_t, uint32_t > )>("IEloop_ControlStatus");
  m_signalproxy_Cumulative_Avg_Fuel_Economy = this->create_signal<void(Invalid)>("Cumulative_Avg_Fuel_Economy");
  m_signalproxy_iStop_mode_ControlStatus = this->create_signal<void(uint32_t)>("iStop_mode_ControlStatus");
  m_signalproxy_iStop_status_ControlStatus = this->create_signal<void(Invalid)>("iStop_status_ControlStatus");
  m_signalproxy_iStop_time_ControlStatus =
      this->create_signal<void(std::tuple < uint32_t, uint32_t > )>("iStop_time_ControlStatus");
  m_signalproxy_iStop_error_ControlStatus =
      this->create_signal<void(std::tuple < bool, bool, uint32_t > )>("iStop_error_ControlStatus");
  m_signalproxy_iStop_Effective_Rate = this->create_signal<void(std::tuple < uint8_t > )>("iStop_Effective_Rate");
  m_signalproxy_iStop_Effective_time = this->create_signal<void(Invalid)>("iStop_Effective_time");
  m_signalproxy_iEloop_Effective_Rate = this->create_signal<void(std::tuple < uint8_t > )>("iEloop_Effective_Rate");
  m_signalproxy_iEloop_Effective_Data = this->create_signal<void(Invalid)>("iEloop_Effective_Data");
  m_signalproxy_CO2_reduction = this->create_signal<void(std::tuple < uint16_t, uint8_t > )>("CO2_reduction");
  m_signalproxy_CO2_Reduction_prevIGNcycle =
      this->create_signal<void(std::tuple < uint16_t, uint8_t > )>("CO2_Reduction_prevIGNcycle");
  m_signalproxy_EEM_Total_Saved_Distance =
      this->create_signal<void(std::tuple < uint32_t, uint8_t > )>("EEM_Total_Saved_Distance");
  m_signalproxy_Curr_drive_fuel_eco_line_graph_data =
      this->create_signal<void(std::tuple < uint8_t, std::vector < std::tuple < uint16_t >> , uint32_t > )>(
          "Curr_drive_fuel_eco_line_graph_data");
  m_signalproxy_Curr_drive_fuel_eco_bar_graph_data =
      this->create_signal<void(std::tuple < uint8_t, std::vector < std::tuple < uint16_t >> , uint32_t > )>(
          "Curr_drive_fuel_eco_bar_graph_data");
  m_signalproxy_Curr_drive_fuel_eco_SixtyMin_bar_graph_data =
      this->create_signal<void(std::tuple < uint8_t, std::vector < std::tuple < uint16_t >> , uint32_t > )>(
          "Curr_drive_fuel_eco_SixtyMin_bar_graph_data");
  m_signalproxy_Curr_drive_fuel_eco_OneMin_bar_graph_data =
      this->create_signal<void(std::tuple < uint8_t, std::vector < std::tuple < uint16_t >> , uint32_t > )>(
          "Curr_drive_fuel_eco_OneMin_bar_graph_data");
  m_signalproxy_Curr_drive_fuel_eco_HEV_SixtyMin_bar_graph_data = this->create_signal<void(std::tuple < uint8_t,
                                                                                           std::vector < std::tuple
                                                                                               < uint16_t,
                                                                                           uint8_t,
                                                                                           bool,
                                                                                           bool >> ,
                                                                                           uint32_t > )>(
      "Curr_drive_fuel_eco_HEV_SixtyMin_bar_graph_data");
  m_signalproxy_Curr_drive_fuel_eco_HEV_OneMin_bar_graph_data = this->create_signal<void(std::tuple < uint8_t,
                                                                                         std::vector < std::tuple
                                                                                             < uint16_t,
                                                                                         uint8_t,
                                                                                         bool,
                                                                                         bool >> ,
                                                                                         uint32_t > )>(
      "Curr_drive_fuel_eco_HEV_OneMin_bar_graph_data");
  m_signalproxy_OneDriveEVDistance =
      this->create_signal<void(std::tuple < uint16_t, uint8_t, uint8_t > )>("OneDriveEVDistance");
  m_signalproxy_HEVSendEnergyFlowSignals =
      this->create_signal<void(std::tuple < uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint32_t > )>(
          "HEVSendEnergyFlowSignals");
  m_signalproxy_HEVSendBatteryDisplayLvl = this->create_signal<void(uint32_t)>("HEVSendBatteryDisplayLvl");
  m_signalproxy_DistDriveEV = this->create_signal<void(std::tuple < uint32_t, uint8_t, uint8_t > )>("DistDriveEV");
  m_signalproxy_Cumm_fuel_eco_reset_graph_data =
      this->create_signal<void(std::tuple < uint8_t, std::vector < std::tuple < uint32_t >> , uint32_t > )>(
          "Cumm_fuel_eco_reset_graph_data");
  m_signalproxy_new_Curr_drive_fuel_eco_per_inst_bar_graph_data =
      this->create_signal<void(Invalid)>("new_Curr_drive_fuel_eco_per_inst_bar_graph_data");
  m_signalproxy_new_Curr_drive_fuel_eco_line_graph_data =
      this->create_signal<void(Invalid)>("new_Curr_drive_fuel_eco_line_graph_data");
  m_signalproxy_Curr_avg_drive_fuel_eco = this->create_signal<void(Invalid)>("Curr_avg_drive_fuel_eco");
  m_signalproxy_Cum_fuel_eco_after_reset_data_Y1 =
      this->create_signal<void(Invalid)>("Cum_fuel_eco_after_reset_data_Y1");
  m_signalproxy_UMP_Reset_enable = this->create_signal<void(uint32_t)>("UMP_Reset_enable");
  m_signalproxy_End_Of_Screen_Data = this->create_signal<void()>("End_Of_Screen_Data");
  m_signalproxy_Screen_Ending_message = this->create_signal<void(std::tuple < bool > )>("Screen_Ending_message");
  m_signalproxy_Ignition_Sts = this->create_signal<void(uint32_t)>("Ignition_Sts");
  m_signalproxy_HVD_LAST_DISPLAYED_SCREEN = this->create_signal<void(uint32_t)>("HVD_LAST_DISPLAYED_SCREEN");
  m_signalproxy_ControlStatusSendTireStatusSignals =
      this->create_signal<void(std::tuple < uint8_t, uint32_t > )>("ControlStatusSendTireStatusSignals");

}
std::shared_ptr <com_jci_eemProxy> com_jci_eemProxy::create(std::string name) {
  return std::shared_ptr<com_jci_eemProxy>(new com_jci_eemProxy(name));

}
int32_t com_jci_eemProxy::GetEquippedData() {
  return (*m_method_GetEquippedData)();

}
int32_t com_jci_eemProxy::SetEEMUpdateScreenEnable(uint32_t screen_type) {
  return (*m_method_SetEEMUpdateScreenEnable)(screen_type);

}
int32_t com_jci_eemProxy::CMUResetSettingRequest(uint32_t reset_active) {
  return (*m_method_CMUResetSettingRequest)(reset_active);

}
uint32_t com_jci_eemProxy::CMU_UMPResetRequest() {
  return (*m_method_CMU_UMPResetRequest)();

}
void com_jci_eemProxy::EndingScreenSetting(uint32_t endSetActive) {
  (*m_method_EndingScreenSetting)(endSetActive);

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_eemProxy::signal_SetEquippedData() {
  return m_signalproxy_SetEquippedData;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t > )>> com_jci_eemProxy::signal_Setting_ResetResponse() {
  return m_signalproxy_Setting_ResetResponse;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t > )>> com_jci_eemProxy::signal_CMU_UMPResetResponse() {
  return m_signalproxy_CMU_UMPResetResponse;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_eemProxy::signal_HVD_EEMEndSet() {
  return m_signalproxy_HVD_EEMEndSet;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_eemProxy::signal_StDisEco_Active() {
  return m_signalproxy_StDisEco_Active;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_eemProxy::signal_HVD_CstmzRq_Trip() {
  return m_signalproxy_HVD_CstmzRq_Trip;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_eemProxy::signal_EEMEndDispConf() {
  return m_signalproxy_EEMEndDispConf;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t,
                                        uint32_t > )>> com_jci_eemProxy::signal_IEloop_ControlStatus() {
  return m_signalproxy_IEloop_ControlStatus;

}
std::shared_ptr <DBus::SignalProxy<void(Invalid)>> com_jci_eemProxy::signal_Cumulative_Avg_Fuel_Economy() {
  return m_signalproxy_Cumulative_Avg_Fuel_Economy;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_eemProxy::signal_iStop_mode_ControlStatus() {
  return m_signalproxy_iStop_mode_ControlStatus;

}
std::shared_ptr <DBus::SignalProxy<void(Invalid)>> com_jci_eemProxy::signal_iStop_status_ControlStatus() {
  return m_signalproxy_iStop_status_ControlStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t > )>> com_jci_eemProxy::signal_iStop_time_ControlStatus() {
  return m_signalproxy_iStop_time_ControlStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < bool,
                                        bool,
                                        uint32_t > )>> com_jci_eemProxy::signal_iStop_error_ControlStatus() {
  return m_signalproxy_iStop_error_ControlStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t > )>> com_jci_eemProxy::signal_iStop_Effective_Rate() {
  return m_signalproxy_iStop_Effective_Rate;

}
std::shared_ptr <DBus::SignalProxy<void(Invalid)>> com_jci_eemProxy::signal_iStop_Effective_time() {
  return m_signalproxy_iStop_Effective_time;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t > )>> com_jci_eemProxy::signal_iEloop_Effective_Rate() {
  return m_signalproxy_iEloop_Effective_Rate;

}
std::shared_ptr <DBus::SignalProxy<void(Invalid)>> com_jci_eemProxy::signal_iEloop_Effective_Data() {
  return m_signalproxy_iEloop_Effective_Data;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint16_t, uint8_t > )>> com_jci_eemProxy::signal_CO2_reduction() {
  return m_signalproxy_CO2_reduction;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint16_t,
                                        uint8_t > )>> com_jci_eemProxy::signal_CO2_Reduction_prevIGNcycle() {
  return m_signalproxy_CO2_Reduction_prevIGNcycle;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint8_t > )>> com_jci_eemProxy::signal_EEM_Total_Saved_Distance() {
  return m_signalproxy_EEM_Total_Saved_Distance;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        std::vector < std::tuple < uint16_t >> ,
                                        uint32_t > )>> com_jci_eemProxy::signal_Curr_drive_fuel_eco_line_graph_data() {
  return m_signalproxy_Curr_drive_fuel_eco_line_graph_data;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        std::vector < std::tuple < uint16_t >> ,
                                        uint32_t > )>> com_jci_eemProxy::signal_Curr_drive_fuel_eco_bar_graph_data() {
  return m_signalproxy_Curr_drive_fuel_eco_bar_graph_data;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        std::vector < std::tuple < uint16_t >> ,
                                        uint32_t
                                            > )>> com_jci_eemProxy::signal_Curr_drive_fuel_eco_SixtyMin_bar_graph_data() {
  return m_signalproxy_Curr_drive_fuel_eco_SixtyMin_bar_graph_data;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        std::vector < std::tuple < uint16_t >> ,
                                        uint32_t
                                            > )>> com_jci_eemProxy::signal_Curr_drive_fuel_eco_OneMin_bar_graph_data() {
  return m_signalproxy_Curr_drive_fuel_eco_OneMin_bar_graph_data;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        std::vector < std::tuple < uint16_t,
                                        uint8_t,
                                        bool,
                                        bool >> ,
                                        uint32_t
                                            > )>> com_jci_eemProxy::signal_Curr_drive_fuel_eco_HEV_SixtyMin_bar_graph_data() {
  return m_signalproxy_Curr_drive_fuel_eco_HEV_SixtyMin_bar_graph_data;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        std::vector < std::tuple < uint16_t,
                                        uint8_t,
                                        bool,
                                        bool >> ,
                                        uint32_t
                                            > )>> com_jci_eemProxy::signal_Curr_drive_fuel_eco_HEV_OneMin_bar_graph_data() {
  return m_signalproxy_Curr_drive_fuel_eco_HEV_OneMin_bar_graph_data;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint16_t,
                                        uint8_t,
                                        uint8_t > )>> com_jci_eemProxy::signal_OneDriveEVDistance() {
  return m_signalproxy_OneDriveEVDistance;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint32_t > )>> com_jci_eemProxy::signal_HEVSendEnergyFlowSignals() {
  return m_signalproxy_HEVSendEnergyFlowSignals;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_eemProxy::signal_HEVSendBatteryDisplayLvl() {
  return m_signalproxy_HEVSendBatteryDisplayLvl;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint8_t,
                                        uint8_t > )>> com_jci_eemProxy::signal_DistDriveEV() {
  return m_signalproxy_DistDriveEV;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        std::vector < std::tuple < uint32_t >> ,
                                        uint32_t > )>> com_jci_eemProxy::signal_Cumm_fuel_eco_reset_graph_data() {
  return m_signalproxy_Cumm_fuel_eco_reset_graph_data;

}
std::shared_ptr <DBus::SignalProxy<void(Invalid)>> com_jci_eemProxy::signal_new_Curr_drive_fuel_eco_per_inst_bar_graph_data() {
  return m_signalproxy_new_Curr_drive_fuel_eco_per_inst_bar_graph_data;

}
std::shared_ptr <DBus::SignalProxy<void(Invalid)>> com_jci_eemProxy::signal_new_Curr_drive_fuel_eco_line_graph_data() {
  return m_signalproxy_new_Curr_drive_fuel_eco_line_graph_data;

}
std::shared_ptr <DBus::SignalProxy<void(Invalid)>> com_jci_eemProxy::signal_Curr_avg_drive_fuel_eco() {
  return m_signalproxy_Curr_avg_drive_fuel_eco;

}
std::shared_ptr <DBus::SignalProxy<void(Invalid)>> com_jci_eemProxy::signal_Cum_fuel_eco_after_reset_data_Y1() {
  return m_signalproxy_Cum_fuel_eco_after_reset_data_Y1;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_eemProxy::signal_UMP_Reset_enable() {
  return m_signalproxy_UMP_Reset_enable;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_eemProxy::signal_End_Of_Screen_Data() {
  return m_signalproxy_End_Of_Screen_Data;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < bool > )>> com_jci_eemProxy::signal_Screen_Ending_message() {
  return m_signalproxy_Screen_Ending_message;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_eemProxy::signal_Ignition_Sts() {
  return m_signalproxy_Ignition_Sts;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_eemProxy::signal_HVD_LAST_DISPLAYED_SCREEN() {
  return m_signalproxy_HVD_LAST_DISPLAYED_SCREEN;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint32_t > )>> com_jci_eemProxy::signal_ControlStatusSendTireStatusSignals() {
  return m_signalproxy_ControlStatusSendTireStatusSignals;

}
