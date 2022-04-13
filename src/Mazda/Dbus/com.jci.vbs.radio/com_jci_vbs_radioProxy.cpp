#include "com_jci_vbs_radioProxy.h"

com_jci_vbs_radioProxy::com_jci_vbs_radioProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_Tune_Request = this->create_method<uint8_t(std::tuple < uint8_t, uint8_t > )>("Tune_Request");
  m_method_Seek_Request = this->create_method<uint8_t(uint8_t)>("Seek_Request");
  m_method_QuickSeek_Request = this->create_method<uint8_t(uint8_t)>("QuickSeek_Request");
  m_method_Scan_Request = this->create_method<uint8_t(uint8_t)>("Scan_Request");
  m_method_DirectControl = this->create_method<uint8_t(std::tuple < double, uint16_t, uint8_t > )>("DirectControl");
  m_method_Control1_Request = this->create_method<uint8_t(uint8_t)>("Control1_Request");
  m_method_PTY_Request = this->create_method<uint8_t(uint8_t)>("PTY_Request");
  m_method_RDS_AF_Request = this->create_method<uint8_t(uint8_t)>("RDS_AF_Request");
  m_method_RDS_REG_Request = this->create_method<uint8_t(uint8_t)>("RDS_REG_Request");
  m_method_HD_Request = this->create_method<uint8_t(uint8_t)>("HD_Request");
  m_method_TA_Request = this->create_method<uint8_t(uint8_t)>("TA_Request");
  m_method_SubTunerControl_Request =
      this->create_method<uint8_t(std::tuple < uint8_t, uint16_t > )>("SubTunerControl_Request");
  m_method_HD_ChannelUp_Request = this->create_method<uint8_t(uint8_t)>("HD_ChannelUp_Request");
  m_method_HD_ErrorRateDisplayMode_Request =
      this->create_method<uint8_t(uint8_t, uint8_t)>("HD_ErrorRateDisplayMode_Request");
  m_method_HD_PageNumber_Request = this->create_method<uint8_t(uint8_t)>("HD_PageNumber_Request");
  m_method_HD_DiagTestNum_Request = this->create_method<uint8_t(uint8_t)>("HD_DiagTestNum_Request");
  m_method_HD_Parameter1_Request = this->create_method<uint8_t(uint8_t)>("HD_Parameter1_Request");
  m_method_HD_Parameter2_Request = this->create_method<uint8_t(uint8_t)>("HD_Parameter2_Request");
  m_method_HD_RadioErrorStatus_Request = this->create_method<uint8_t(uint8_t)>("HD_RadioErrorStatus_Request");
  m_method_Mute_Request = this->create_method<uint8_t(std::tuple < uint8_t, uint8_t > )>("Mute_Request");
  m_method_Vol_Request = this->create_method<uint8_t(uint8_t)>("Vol_Request");
  m_method_AudioSettings_Request =
      this->create_method<uint8_t(std::tuple < uint8_t, uint8_t > )>("AudioSettings_Request");
  m_method_ACUInitialization_Request = this->create_method<uint8_t(uint8_t)>("ACUInitialization_Request");
  m_method_ACUAudioPilot_Request = this->create_method<uint8_t(uint8_t)>("ACUAudioPilot_Request");
  m_method_ACUCenterPoint_Request = this->create_method<uint8_t(uint8_t)>("ACUCenterPoint_Request");
  m_method_StationListCreation_Request = this->create_method<uint8_t(uint8_t, uint8_t)>("StationListCreation_Request");
  m_method_Text_Request = this->create_method<uint8_t(uint8_t)>("Text_Request");
  m_method_HD_SISStatus_Request = this->create_method<uint8_t(uint8_t)>("HD_SISStatus_Request");
  m_method_HD_PSD_Request = this->create_method<uint8_t(uint8_t)>("HD_PSD_Request");
  m_method_HD_ErrorStatus_Request = this->create_method<uint8_t(uint8_t)>("HD_ErrorStatus_Request");
  m_method_AUTO_M_Request = this->create_method<uint8_t(uint8_t)>("AUTO_M_Request");
  m_method_XM_DirectType_Request = this->create_method<uint8_t(uint8_t, uint8_t, uint8_t)>("XM_DirectType_Request");
  m_method_XM_RelativeTune_Request = this->create_method<uint8_t(uint8_t, uint8_t)>("XM_RelativeTune_Request");
  m_method_XM_Diag_Request = this->create_method<uint8_t(uint8_t)>("XM_Diag_Request");
  m_method_XM_ExpandedDiagMode_Request = this->create_method<uint8_t(uint8_t)>("XM_ExpandedDiagMode_Request");
  m_method_XM_Mute_Request = this->create_method<uint8_t(uint8_t)>("XM_Mute_Request");
  m_method_ElectricField_Request = this->create_method<uint8_t(uint8_t)>("ElectricField_Request");
  m_method_Test_Mode_Variation_Page_Antenna_Request =
      this->create_method<uint8_t(std::tuple < uint8_t, uint8_t, uint8_t, uint8_t > )>(
          "Test_Mode_Variation_Page_Antenna_Request");
  m_method_AutoStore_Request = this->create_method<uint8_t(uint8_t)>("AutoStore_Request");
  m_method_GetConnStatus = this->create_method<uint8_t()>("GetConnStatus");
  m_method_AUX_GetConnStatus = this->create_method<uint8_t()>("AUX_GetConnStatus");
  m_method_XM_Config_GetStatus = this->create_method<uint8_t()>("XM_Config_GetStatus");
  m_method_GetDestinationType = this->create_method<uint8_t()>("GetDestinationType");
  m_method_GetRadioID = this->create_method<uint8_t()>("GetRadioID");
  m_method_GetHDOnOffStatus = this->create_method<uint8_t()>("GetHDOnOffStatus");
  m_method_GetTAOnOffStatus = this->create_method<uint8_t()>("GetTAOnOffStatus");
  m_method_GetHARFreqSetting = this->create_method<uint8_t()>("GetHARFreqSetting");
  m_method_GetCurrentGenreSetting = this->create_method<uint8_t()>("GetCurrentGenreSetting");
  m_method_GetAlternateFreqOnOffStatus = this->create_method<uint8_t()>("GetAlternateFreqOnOffStatus");
  m_method_GetRegionLockOnOffStatus = this->create_method<uint8_t()>("GetRegionLockOnOffStatus");
  m_method_XM_SendSignalInfoRequest = this->create_method<uint8_t(uint8_t)>("XM_SendSignalInfoRequest");
  m_method_HD_GetTunerResponse = this->create_method<uint8_t()>("HD_GetTunerResponse");
  m_method_GetTunerResponse = this->create_method<uint8_t()>("GetTunerResponse");
  m_method_XM_GetRadioStatusResponse = this->create_method<uint8_t()>("XM_GetRadioStatusResponse");
  m_method_Get4ARegionInfo = this->create_method<uint8_t()>("Get4ARegionInfo");
  m_method_GetJapanRegionInfo = this->create_method<uint8_t()>("GetJapanRegionInfo");
  m_method_DAB_Command_Request =
      this->create_method<uint8_t(std::tuple < uint8_t, uint8_t, uint16_t, uint16_t > )>("DAB_Command_Request");
  m_method_DAB_Control_Request = this->create_method<uint8_t(std::tuple < uint8_t, uint8_t > )>("DAB_Control_Request");
  m_method_DAB_Get_InfoStatus = this->create_method<std::tuple<bool, bool, bool>()>("DAB_Get_InfoStatus");
  m_method_DAB_Get_SignalStrength = this->create_method<uint8_t()>("DAB_Get_SignalStrength");
  m_method_DAB_Get_ChStatus = this->create_method < std::tuple < uint8_t, std::vector < uint8_t >, uint16_t, uint16_t,
      uint8_t > () > ("DAB_Get_ChStatus");
  m_method_DAB_Get_ModeStatus = this->create_method<std::tuple<uint8_t, uint8_t>()>("DAB_Get_ModeStatus");
  m_method_DAB_Get_ListUpdateStatus = this->create_method<uint8_t()>("DAB_Get_ListUpdateStatus");
  m_method_DAB_DirectControl =
      this->create_method<uint8_t(std::tuple < std::vector < uint8_t > , uint16_t, uint16_t, uint8_t > )>(
          "DAB_DirectControl");
  m_method_DAB_Get_Link_Status = this->create_method<uint8_t()>("DAB_Get_Link_Status");
  m_method_DAB_Get_FMLink_Status = this->create_method<uint8_t()>("DAB_Get_FMLink_Status");
  m_method_DAB_Get_BandSelect_Status = this->create_method<uint8_t()>("DAB_Get_BandSelect_Status");
  m_method_DAB_Get_TAUStatus = this->create_method<std::tuple<uint8_t, uint8_t>()>("DAB_Get_TAUStatus");
  m_method_DAB_InterruptNotification = this->create_method<uint8_t(uint8_t)>("DAB_InterruptNotification");
  m_method_XM_SxiPowerSts = this->create_method<uint8_t(uint8_t)>("XM_SxiPowerSts");
  m_method_XM_SxiBaudRate = this->create_method<uint8_t(uint8_t)>("XM_SxiBaudRate");
  m_method_XM_XmModuleResetReq = this->create_method<uint8_t(uint8_t)>("XM_XmModuleResetReq");
  m_method_TauXmhSts_getXmModulePowerSts =
      this->create_method<std::tuple<uint8_t, uint8_t>()>("TauXmhSts_getXmModulePowerSts");
  m_method_TauXmhSts_getSxiCommandReq =
      this->create_method<std::tuple<uint8_t, uint8_t>()>("TauXmhSts_getSxiCommandReq");
  m_signalproxy_Tuner_Response =
      this->create_signal<void(std::tuple < std::vector < uint8_t > , uint16_t > )>("Tuner_Response");
  m_signalproxy_FrequencyLastKeep_Response = this->create_signal<void(uint8_t)>("FrequencyLastKeep_Response");
  m_signalproxy_HARWrite_Response = this->create_signal<void(uint8_t)>("HARWrite_Response");
  m_signalproxy_PTY_Response = this->create_signal<void(uint8_t, uint8_t)>("PTY_Response");
  m_signalproxy_PTYChange_Notification = this->create_signal<void(uint8_t)>("PTYChange_Notification");
  m_signalproxy_AF_Response = this->create_signal<void(uint8_t)>("AF_Response");
  m_signalproxy_REG_Response = this->create_signal<void(uint8_t)>("REG_Response");
  m_signalproxy_HD_Response = this->create_signal<void(uint8_t)>("HD_Response");
  m_signalproxy_HD_Tuner_Response =
      this->create_signal<void(std::tuple < uint8_t, uint8_t, uint8_t, uint8_t, std::vector < uint8_t > , uint8_t > )>(
          "HD_Tuner_Response");
  m_signalproxy_HD_PSD_Response = this->create_signal<void(uint8_t)>("HD_PSD_Response");
  m_signalproxy_TA_Response = this->create_signal<void(uint8_t)>("TA_Response");
  m_signalproxy_RDS_Response = this->create_signal<void(uint8_t)>("RDS_Response");
  m_signalproxy_Metadata_Response = this->create_signal<void(uint8_t)>("Metadata_Response");
  m_signalproxy_AudioSetting_Response =
      this->create_signal<void(std::tuple < uint8_t, uint8_t > )>("AudioSetting_Response");
  m_signalproxy_ACU_Response = this->create_signal<void(uint8_t)>("ACU_Response");
  m_signalproxy_StationList_Response = this->create_signal<void(uint8_t)>("StationList_Response");
  m_signalproxy_PresetInfo_Response = this->create_signal<void(uint8_t)>("PresetInfo_Response");
  m_signalproxy_Text_Response =
      this->create_signal<void(std::tuple < uint8_t, std::vector < uint8_t >> )>("Text_Response");
  m_signalproxy_HD_SISStatus_Response =
      this->create_signal<void(std::tuple < uint8_t, uint8_t, uint8_t, uint8_t, std::vector < uint8_t >> )>(
          "HD_SISStatus_Response");
  m_signalproxy_TAUSourceIndex_Response = this->create_signal<void(uint8_t, uint8_t)>("TAUSourceIndex_Response");
  m_signalproxy_AMP_Response = this->create_signal<void(std::tuple < uint8_t,
                                                        uint8_t,
                                                        uint8_t,
                                                        uint8_t,
                                                        uint8_t,
                                                        uint8_t,
                                                        uint8_t,
                                                        uint8_t,
                                                        uint8_t,
                                                        uint8_t,
                                                        uint8_t,
                                                        uint8_t,
                                                        uint8_t,
                                                        uint8_t,
                                                        uint8_t,
                                                        uint8_t > )>("AMP_Response");
  m_signalproxy_TAControl_Interrupt_Response = this->create_signal<void(uint8_t)>("TAControl_Interrupt_Response");
  m_signalproxy_TAUSoftwareVersion_Response =
      this->create_signal<void(std::tuple < uint32_t, uint32_t > )>("TAUSoftwareVersion_Response");
  m_signalproxy_XM_RefreshStatus_Response = this->create_signal<void(uint8_t)>("XM_RefreshStatus_Response");
  m_signalproxy_XM_RadioStatus_Response =
      this->create_signal<void(std::tuple < uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t > )>(
          "XM_RadioStatus_Response");
  m_signalproxy_XM_Mute_Status_Response = this->create_signal<void(uint8_t)>("XM_Mute_Status_Response");
  m_signalproxy_AUX_Status_Response = this->create_signal<void(uint8_t)>("AUX_Status_Response");
  m_signalproxy_TrackChange = this->create_signal<void(uint8_t)>("TrackChange");
  m_signalproxy_StationChange = this->create_signal<void(double)>("StationChange");
  m_signalproxy_ModeChange = this->create_signal<void(std::tuple < uint8_t, std::vector < uint8_t >> )>("ModeChange");
  m_signalproxy_OffOnNotification = this->create_signal<void(uint8_t)>("OffOnNotification");
  m_signalproxy_DestinationCode = this->create_signal<void(uint8_t)>("DestinationCode");
  m_signalproxy_DestinationType = this->create_signal<void(uint8_t)>("DestinationType");
  m_signalproxy_XM_ConfigStatus = this->create_signal<void(uint8_t)>("XM_ConfigStatus");
  m_signalproxy_ConnectionStatus = this->create_signal<void(uint8_t)>("ConnectionStatus");
  m_signalproxy_RsesConnectStatus = this->create_signal<void(uint8_t)>("RsesConnectStatus");
  m_signalproxy_iTunes_TaggingInfo =
      this->create_signal<void(std::tuple < uint8_t, std::vector < uint8_t >> )>("iTunes_TaggingInfo");
  m_signalproxy_XM_MAP_Info = this->create_signal<void(uint8_t)>("XM_MAP_Info");
  m_signalproxy_XM_Signal_Info = this->create_signal<void(std::tuple < std::vector < uint8_t >> )>("XM_Signal_Info");
  m_signalproxy_RDS_HAR_Response = this->create_signal<void(uint8_t, uint8_t)>("RDS_HAR_Response");
  m_signalproxy_RDS_TAInterrupt_Response = this->create_signal<void(uint8_t)>("RDS_TAInterrupt_Response");
  m_signalproxy_TAU_TestMode_Response =
      this->create_signal<void(std::tuple < uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t > )>(
          "TAU_TestMode_Response");
  m_signalproxy_XM_Title_Response = this->create_signal<void(uint8_t)>("XM_Title_Response");
  m_signalproxy_XM_Metadata_Notification =
      this->create_signal<void(std::tuple < uint8_t, uint8_t, uint8_t, uint8_t > )>("XM_Metadata_Notification");
  m_signalproxy_HD_MetadataChange_Notification = this->create_signal<void(std::tuple < uint8_t,
                                                                          uint8_t,
                                                                          uint8_t,
                                                                          uint8_t,
                                                                          uint8_t,
                                                                          uint8_t,
                                                                          uint8_t,
                                                                          uint8_t,
                                                                          uint8_t,
                                                                          uint8_t,
                                                                          uint16_t
                                                                              > )>("HD_MetadataChange_Notification");
  m_signalproxy_HD_Tuner2_Status_Response =
      this->create_signal<void(std::tuple < uint8_t, uint16_t > )>("HD_Tuner2_Status_Response");
  m_signalproxy_Text_Notification = this->create_signal<void(uint8_t)>("Text_Notification");
  m_signalproxy_HD_ID3_XHDR_Response =
      this->create_signal<void(std::tuple < std::vector < uint8_t >> )>("HD_ID3_XHDR_Response");
  m_signalproxy_XM_ModuleData_Response = this->create_signal<void(std::tuple < uint8_t,
                                                                  std::vector < uint8_t > ,
                                                                  uint8_t,
                                                                  uint8_t,
                                                                  uint8_t,
                                                                  std::vector < uint8_t >> )>("XM_ModuleData_Response");
  m_signalproxy_XM_SerialNumber_Response =
      this->create_signal<void(std::tuple < uint32_t, uint32_t > )>("XM_SerialNumber_Response");
  m_signalproxy_HD_ErrorStatusResponse = this->create_signal<void(std::tuple < std::vector < uint8_t > ,
                                                                  std::vector < uint8_t > ,
                                                                  std::vector < uint8_t > ,
                                                                  std::vector < uint8_t > ,
                                                                  std::vector < uint8_t > ,
                                                                  std::vector < uint8_t > ,
                                                                  std::vector < uint8_t > ,
                                                                  std::vector < uint8_t > ,
                                                                  std::vector < uint8_t > ,
                                                                  std::vector < uint8_t > ,
                                                                  uint8_t,
                                                                  uint8_t,
                                                                  uint8_t > )>("HD_ErrorStatusResponse");
  m_signalproxy_HD_RadioNumBlend_Response = this->create_signal<void(uint16_t)>("HD_RadioNumBlend_Response");
  m_signalproxy_SignalInfoChange_Response = this->create_signal<void(uint8_t)>("SignalInfoChange_Response");
  m_signalproxy_XM_MAP_DuplicateChannelNotification =
      this->create_signal<void(uint8_t, uint8_t)>("XM_MAP_DuplicateChannelNotification");
  m_signalproxy_HD_BER_Status = this->create_signal<void(uint8_t)>("HD_BER_Status");
  m_signalproxy_HD_BCTL_Status = this->create_signal<void(uint8_t)>("HD_BCTL_Status");
  m_signalproxy_RDS_AlarmInterrupt_Response = this->create_signal<void(uint8_t)>("RDS_AlarmInterrupt_Response");
  m_signalproxy_New4ARegionInfo = this->create_signal<void(uint8_t)>("New4ARegionInfo");
  m_signalproxy_NewJapanRegionInfo = this->create_signal<void(uint8_t)>("NewJapanRegionInfo");
  m_signalproxy_DAB_ChStatus_Response =
      this->create_signal<void(std::tuple < uint8_t, std::vector < uint8_t > , uint16_t, uint16_t, uint8_t > )>(
          "DAB_ChStatus_Response");
  m_signalproxy_DAB_Mode_Status = this->create_signal<void(std::tuple < uint8_t, uint8_t > )>("DAB_Mode_Status");
  m_signalproxy_DAB_FMLinkSetting_Status = this->create_signal<void(uint8_t)>("DAB_FMLinkSetting_Status");
  m_signalproxy_DAB_LinkSetting_Status = this->create_signal<void(uint8_t)>("DAB_LinkSetting_Status");
  m_signalproxy_DAB_List_Status = this->create_signal<void(uint8_t)>("DAB_List_Status");
  m_signalproxy_DAB_BandSelectSetting_Status = this->create_signal<void(uint8_t)>("DAB_BandSelectSetting_Status");
  m_signalproxy_DAB_RadioText_Status = this->create_signal<void(uint8_t)>("DAB_RadioText_Status");
  m_signalproxy_DAB_SignalStrength_Status = this->create_signal<void(uint8_t)>("DAB_SignalStrength_Status");
  m_signalproxy_DAB_DiagMode_Status = this->create_signal<void(uint8_t)>("DAB_DiagMode_Status");
  m_signalproxy_DAB_EnsembleListMgmtInfo_Response =
      this->create_signal<void(std::tuple < uint8_t, uint8_t > )>("DAB_EnsembleListMgmtInfo_Response");
  m_signalproxy_DAB_EnsembleInfoList_Response = this->create_signal<void(std::tuple < uint8_t,
                                                                         uint8_t,
                                                                         uint16_t,
                                                                         std::vector < uint8_t > ,
                                                                         std::vector < uint8_t >> )>(
      "DAB_EnsembleInfoList_Response");
  m_signalproxy_DAB_CompoListMgmtInfo_Response =
      this->create_signal<void(std::tuple < uint8_t, uint16_t, uint16_t > )>("DAB_CompoListMgmtInfo_Response");
  m_signalproxy_DAB_CompoInfoList_Response =
      this->create_signal<void(std::tuple < uint8_t, uint8_t, uint16_t, uint16_t, uint8_t, std::vector < uint8_t >> )>(
          "DAB_CompoInfoList_Response");
  m_signalproxy_DAB_Label_Response = this->create_signal<void(std::tuple < uint8_t,
                                                              uint8_t,
                                                              uint8_t,
                                                              std::vector < uint8_t >> )>("DAB_Label_Response");
  m_signalproxy_DAB_TAUConfig_Status =
      this->create_signal<void(std::tuple < uint8_t, uint8_t > )>("DAB_TAUConfig_Status");
  m_signalproxy_DAB_Info_Status = this->create_signal<void(uint8_t)>("DAB_Info_Status");
  m_signalproxy_DAB_Diag_Status = this->create_signal<void(std::tuple < uint8_t,
                                                           uint16_t,
                                                           uint32_t,
                                                           std::vector < uint8_t > ,
                                                           uint8_t,
                                                           uint16_t,
                                                           uint16_t,
                                                           uint8_t,
                                                           uint8_t,
                                                           uint8_t,
                                                           uint16_t,
                                                           uint16_t,
                                                           uint8_t,
                                                           uint8_t,
                                                           uint8_t > )>("DAB_Diag_Status");
  m_signalproxy_DAB_List_Current_State = this->create_signal<void(uint8_t, uint8_t)>("DAB_List_Current_State");
  m_signalproxy_DAB_Text_Info_Status = this->create_signal<void(uint8_t, uint8_t)>("DAB_Text_Info_Status");
  m_signalproxy_TauXmhSts_XmModulePowerSts =
      this->create_signal<void(std::tuple < uint8_t, uint8_t > )>("TauXmhSts_XmModulePowerSts");
  m_signalproxy_TauXmhSts_SxiCommandReq =
      this->create_signal<void(std::tuple < uint8_t, uint8_t > )>("TauXmhSts_SxiCommandReq");

}
std::shared_ptr <com_jci_vbs_radioProxy> com_jci_vbs_radioProxy::create(std::string name) {
  return std::shared_ptr<com_jci_vbs_radioProxy>(new com_jci_vbs_radioProxy(name));

}
uint8_t com_jci_vbs_radioProxy::Tune_Request(std::tuple <uint8_t, uint8_t> tune) {
  return (*m_method_Tune_Request)(tune);

}
uint8_t com_jci_vbs_radioProxy::Seek_Request(uint8_t seek) {
  return (*m_method_Seek_Request)(seek);

}
uint8_t com_jci_vbs_radioProxy::QuickSeek_Request(uint8_t quickSeek) {
  return (*m_method_QuickSeek_Request)(quickSeek);

}
uint8_t com_jci_vbs_radioProxy::Scan_Request(uint8_t scan) {
  return (*m_method_Scan_Request)(scan);

}
uint8_t com_jci_vbs_radioProxy::DirectControl(std::tuple<double, uint16_t, uint8_t> directControl) {
  return (*m_method_DirectControl)(directControl);

}
uint8_t com_jci_vbs_radioProxy::Control1_Request(uint8_t hARWrite) {
  return (*m_method_Control1_Request)(hARWrite);

}
uint8_t com_jci_vbs_radioProxy::PTY_Request(uint8_t pty) {
  return (*m_method_PTY_Request)(pty);

}
uint8_t com_jci_vbs_radioProxy::RDS_AF_Request(uint8_t aF) {
  return (*m_method_RDS_AF_Request)(aF);

}
uint8_t com_jci_vbs_radioProxy::RDS_REG_Request(uint8_t rEG) {
  return (*m_method_RDS_REG_Request)(rEG);

}
uint8_t com_jci_vbs_radioProxy::HD_Request(uint8_t hD) {
  return (*m_method_HD_Request)(hD);

}
uint8_t com_jci_vbs_radioProxy::TA_Request(uint8_t tA) {
  return (*m_method_TA_Request)(tA);

}
uint8_t com_jci_vbs_radioProxy::SubTunerControl_Request(std::tuple <uint8_t, uint16_t> subTunerReq) {
  return (*m_method_SubTunerControl_Request)(subTunerReq);

}
uint8_t com_jci_vbs_radioProxy::HD_ChannelUp_Request(uint8_t hDChannelUp) {
  return (*m_method_HD_ChannelUp_Request)(hDChannelUp);

}
uint8_t com_jci_vbs_radioProxy::HD_ErrorRateDisplayMode_Request(uint8_t hDErrorRateDisplayMode, uint8_t hDTunerType) {
  return (*m_method_HD_ErrorRateDisplayMode_Request)(hDErrorRateDisplayMode, hDTunerType);

}
uint8_t com_jci_vbs_radioProxy::HD_PageNumber_Request(uint8_t hDPageNumber) {
  return (*m_method_HD_PageNumber_Request)(hDPageNumber);

}
uint8_t com_jci_vbs_radioProxy::HD_DiagTestNum_Request(uint8_t hDDiagTestNum) {
  return (*m_method_HD_DiagTestNum_Request)(hDDiagTestNum);

}
uint8_t com_jci_vbs_radioProxy::HD_Parameter1_Request(uint8_t hDParameter1) {
  return (*m_method_HD_Parameter1_Request)(hDParameter1);

}
uint8_t com_jci_vbs_radioProxy::HD_Parameter2_Request(uint8_t hDParameter2) {
  return (*m_method_HD_Parameter2_Request)(hDParameter2);

}
uint8_t com_jci_vbs_radioProxy::HD_RadioErrorStatus_Request(uint8_t hDRadioErrorStatus) {
  return (*m_method_HD_RadioErrorStatus_Request)(hDRadioErrorStatus);

}
uint8_t com_jci_vbs_radioProxy::Mute_Request(std::tuple <uint8_t, uint8_t> mute) {
  return (*m_method_Mute_Request)(mute);

}
uint8_t com_jci_vbs_radioProxy::Vol_Request(uint8_t vol) {
  return (*m_method_Vol_Request)(vol);

}
uint8_t com_jci_vbs_radioProxy::AudioSettings_Request(std::tuple <uint8_t, uint8_t> audioSettings) {
  return (*m_method_AudioSettings_Request)(audioSettings);

}
uint8_t com_jci_vbs_radioProxy::ACUInitialization_Request(uint8_t aCUIn) {
  return (*m_method_ACUInitialization_Request)(aCUIn);

}
uint8_t com_jci_vbs_radioProxy::ACUAudioPilot_Request(uint8_t audioPilot) {
  return (*m_method_ACUAudioPilot_Request)(audioPilot);

}
uint8_t com_jci_vbs_radioProxy::ACUCenterPoint_Request(uint8_t centerPoint) {
  return (*m_method_ACUCenterPoint_Request)(centerPoint);

}
uint8_t com_jci_vbs_radioProxy::StationListCreation_Request(uint8_t request, uint8_t dest_id) {
  return (*m_method_StationListCreation_Request)(request, dest_id);

}
uint8_t com_jci_vbs_radioProxy::Text_Request(uint8_t textReq) {
  return (*m_method_Text_Request)(textReq);

}
uint8_t com_jci_vbs_radioProxy::HD_SISStatus_Request(uint8_t sISReq) {
  return (*m_method_HD_SISStatus_Request)(sISReq);

}
uint8_t com_jci_vbs_radioProxy::HD_PSD_Request(uint8_t pSDRequest) {
  return (*m_method_HD_PSD_Request)(pSDRequest);

}
uint8_t com_jci_vbs_radioProxy::HD_ErrorStatus_Request(uint8_t errorStatusReq) {
  return (*m_method_HD_ErrorStatus_Request)(errorStatusReq);

}
uint8_t com_jci_vbs_radioProxy::AUTO_M_Request(uint8_t autoM) {
  return (*m_method_AUTO_M_Request)(autoM);

}
uint8_t com_jci_vbs_radioProxy::XM_DirectType_Request(uint8_t directType, uint8_t stepCH, uint8_t stepSID) {
  return (*m_method_XM_DirectType_Request)(directType, stepCH, stepSID);

}
uint8_t com_jci_vbs_radioProxy::XM_RelativeTune_Request(uint8_t step, uint8_t tuneDirection) {
  return (*m_method_XM_RelativeTune_Request)(step, tuneDirection);

}
uint8_t com_jci_vbs_radioProxy::XM_Diag_Request(uint8_t diagRequest) {
  return (*m_method_XM_Diag_Request)(diagRequest);

}
uint8_t com_jci_vbs_radioProxy::XM_ExpandedDiagMode_Request(uint8_t expDiagMode) {
  return (*m_method_XM_ExpandedDiagMode_Request)(expDiagMode);

}
uint8_t com_jci_vbs_radioProxy::XM_Mute_Request(uint8_t muteReq) {
  return (*m_method_XM_Mute_Request)(muteReq);

}
uint8_t com_jci_vbs_radioProxy::ElectricField_Request(uint8_t signalStrength) {
  return (*m_method_ElectricField_Request)(signalStrength);

}
uint8_t com_jci_vbs_radioProxy::Test_Mode_Variation_Page_Antenna_Request(std::tuple <uint8_t, uint8_t, uint8_t, uint8_t> testMode_Variation_Page_Antenna) {
  return (*m_method_Test_Mode_Variation_Page_Antenna_Request)(testMode_Variation_Page_Antenna);

}
uint8_t com_jci_vbs_radioProxy::AutoStore_Request(uint8_t autostore) {
  return (*m_method_AutoStore_Request)(autostore);

}
uint8_t com_jci_vbs_radioProxy::GetConnStatus() {
  return (*m_method_GetConnStatus)();

}
uint8_t com_jci_vbs_radioProxy::AUX_GetConnStatus() {
  return (*m_method_AUX_GetConnStatus)();

}
uint8_t com_jci_vbs_radioProxy::XM_Config_GetStatus() {
  return (*m_method_XM_Config_GetStatus)();

}
uint8_t com_jci_vbs_radioProxy::GetDestinationType() {
  return (*m_method_GetDestinationType)();

}
uint8_t com_jci_vbs_radioProxy::GetRadioID() {
  return (*m_method_GetRadioID)();

}
uint8_t com_jci_vbs_radioProxy::GetHDOnOffStatus() {
  return (*m_method_GetHDOnOffStatus)();

}
uint8_t com_jci_vbs_radioProxy::GetTAOnOffStatus() {
  return (*m_method_GetTAOnOffStatus)();

}
uint8_t com_jci_vbs_radioProxy::GetHARFreqSetting() {
  return (*m_method_GetHARFreqSetting)();

}
uint8_t com_jci_vbs_radioProxy::GetCurrentGenreSetting() {
  return (*m_method_GetCurrentGenreSetting)();

}
uint8_t com_jci_vbs_radioProxy::GetAlternateFreqOnOffStatus() {
  return (*m_method_GetAlternateFreqOnOffStatus)();

}
uint8_t com_jci_vbs_radioProxy::GetRegionLockOnOffStatus() {
  return (*m_method_GetRegionLockOnOffStatus)();

}
uint8_t com_jci_vbs_radioProxy::XM_SendSignalInfoRequest(uint8_t xMSignalInfoReqType) {
  return (*m_method_XM_SendSignalInfoRequest)(xMSignalInfoReqType);

}
uint8_t com_jci_vbs_radioProxy::HD_GetTunerResponse() {
  return (*m_method_HD_GetTunerResponse)();

}
uint8_t com_jci_vbs_radioProxy::GetTunerResponse() {
  return (*m_method_GetTunerResponse)();

}
uint8_t com_jci_vbs_radioProxy::XM_GetRadioStatusResponse() {
  return (*m_method_XM_GetRadioStatusResponse)();

}
uint8_t com_jci_vbs_radioProxy::Get4ARegionInfo() {
  return (*m_method_Get4ARegionInfo)();

}
uint8_t com_jci_vbs_radioProxy::GetJapanRegionInfo() {
  return (*m_method_GetJapanRegionInfo)();

}
uint8_t com_jci_vbs_radioProxy::DAB_Command_Request(std::tuple <uint8_t, uint8_t, uint16_t, uint16_t> dabCmdReq) {
  return (*m_method_DAB_Command_Request)(dabCmdReq);

}
uint8_t com_jci_vbs_radioProxy::DAB_Control_Request(std::tuple <uint8_t, uint8_t> dabCtrlReq) {
  return (*m_method_DAB_Control_Request)(dabCtrlReq);

}
std::tuple<bool, bool, bool> com_jci_vbs_radioProxy::DAB_Get_InfoStatus() {
  return (*m_method_DAB_Get_InfoStatus)();

}
uint8_t com_jci_vbs_radioProxy::DAB_Get_SignalStrength() {
  return (*m_method_DAB_Get_SignalStrength)();

}
std::tuple <uint8_t, std::vector<uint8_t>, uint16_t, uint16_t, uint8_t> com_jci_vbs_radioProxy::DAB_Get_ChStatus() {
  return (*m_method_DAB_Get_ChStatus)();

}
std::tuple <uint8_t, uint8_t> com_jci_vbs_radioProxy::DAB_Get_ModeStatus() {
  return (*m_method_DAB_Get_ModeStatus)();

}
uint8_t com_jci_vbs_radioProxy::DAB_Get_ListUpdateStatus() {
  return (*m_method_DAB_Get_ListUpdateStatus)();

}
uint8_t com_jci_vbs_radioProxy::DAB_DirectControl(std::tuple <std::vector<uint8_t>, uint16_t, uint16_t, uint8_t> directCtrl) {
  return (*m_method_DAB_DirectControl)(directCtrl);

}
uint8_t com_jci_vbs_radioProxy::DAB_Get_Link_Status() {
  return (*m_method_DAB_Get_Link_Status)();

}
uint8_t com_jci_vbs_radioProxy::DAB_Get_FMLink_Status() {
  return (*m_method_DAB_Get_FMLink_Status)();

}
uint8_t com_jci_vbs_radioProxy::DAB_Get_BandSelect_Status() {
  return (*m_method_DAB_Get_BandSelect_Status)();

}
std::tuple <uint8_t, uint8_t> com_jci_vbs_radioProxy::DAB_Get_TAUStatus() {
  return (*m_method_DAB_Get_TAUStatus)();

}
uint8_t com_jci_vbs_radioProxy::DAB_InterruptNotification(uint8_t notify) {
  return (*m_method_DAB_InterruptNotification)(notify);

}
uint8_t com_jci_vbs_radioProxy::XM_SxiPowerSts(uint8_t sxiPowerSts) {
  return (*m_method_XM_SxiPowerSts)(sxiPowerSts);

}
uint8_t com_jci_vbs_radioProxy::XM_SxiBaudRate(uint8_t sxiBaudRate) {
  return (*m_method_XM_SxiBaudRate)(sxiBaudRate);

}
uint8_t com_jci_vbs_radioProxy::XM_XmModuleResetReq(uint8_t xmModuleResetReq) {
  return (*m_method_XM_XmModuleResetReq)(xmModuleResetReq);

}
std::tuple <uint8_t, uint8_t> com_jci_vbs_radioProxy::TauXmhSts_getXmModulePowerSts() {
  return (*m_method_TauXmhSts_getXmModulePowerSts)();

}
std::tuple <uint8_t, uint8_t> com_jci_vbs_radioProxy::TauXmhSts_getSxiCommandReq() {
  return (*m_method_TauXmhSts_getSxiCommandReq)();

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < std::vector < uint8_t > ,
                                        uint16_t > )>> com_jci_vbs_radioProxy::signal_Tuner_Response() {
  return m_signalproxy_Tuner_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_FrequencyLastKeep_Response() {
  return m_signalproxy_FrequencyLastKeep_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_HARWrite_Response() {
  return m_signalproxy_HARWrite_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t, uint8_t)>> com_jci_vbs_radioProxy::signal_PTY_Response() {
  return m_signalproxy_PTY_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_PTYChange_Notification() {
  return m_signalproxy_PTYChange_Notification;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_AF_Response() {
  return m_signalproxy_AF_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_REG_Response() {
  return m_signalproxy_REG_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_HD_Response() {
  return m_signalproxy_HD_Response;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        std::vector < uint8_t > ,
                                        uint8_t > )>> com_jci_vbs_radioProxy::signal_HD_Tuner_Response() {
  return m_signalproxy_HD_Tuner_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_HD_PSD_Response() {
  return m_signalproxy_HD_PSD_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_TA_Response() {
  return m_signalproxy_TA_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_RDS_Response() {
  return m_signalproxy_RDS_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_Metadata_Response() {
  return m_signalproxy_Metadata_Response;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t > )>> com_jci_vbs_radioProxy::signal_AudioSetting_Response() {
  return m_signalproxy_AudioSetting_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_ACU_Response() {
  return m_signalproxy_ACU_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_StationList_Response() {
  return m_signalproxy_StationList_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_PresetInfo_Response() {
  return m_signalproxy_PresetInfo_Response;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        std::vector < uint8_t >> )>> com_jci_vbs_radioProxy::signal_Text_Response() {
  return m_signalproxy_Text_Response;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        std::vector
                                            < uint8_t >> )>> com_jci_vbs_radioProxy::signal_HD_SISStatus_Response() {
  return m_signalproxy_HD_SISStatus_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t, uint8_t)>> com_jci_vbs_radioProxy::signal_TAUSourceIndex_Response() {
  return m_signalproxy_TAUSourceIndex_Response;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t > )>> com_jci_vbs_radioProxy::signal_AMP_Response() {
  return m_signalproxy_AMP_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_TAControl_Interrupt_Response() {
  return m_signalproxy_TAControl_Interrupt_Response;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t > )>> com_jci_vbs_radioProxy::signal_TAUSoftwareVersion_Response() {
  return m_signalproxy_TAUSoftwareVersion_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_XM_RefreshStatus_Response() {
  return m_signalproxy_XM_RefreshStatus_Response;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t > )>> com_jci_vbs_radioProxy::signal_XM_RadioStatus_Response() {
  return m_signalproxy_XM_RadioStatus_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_XM_Mute_Status_Response() {
  return m_signalproxy_XM_Mute_Status_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_AUX_Status_Response() {
  return m_signalproxy_AUX_Status_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_TrackChange() {
  return m_signalproxy_TrackChange;

}
std::shared_ptr <DBus::SignalProxy<void(double)>> com_jci_vbs_radioProxy::signal_StationChange() {
  return m_signalproxy_StationChange;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        std::vector < uint8_t >> )>> com_jci_vbs_radioProxy::signal_ModeChange() {
  return m_signalproxy_ModeChange;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_OffOnNotification() {
  return m_signalproxy_OffOnNotification;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_DestinationCode() {
  return m_signalproxy_DestinationCode;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_DestinationType() {
  return m_signalproxy_DestinationType;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_XM_ConfigStatus() {
  return m_signalproxy_XM_ConfigStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_ConnectionStatus() {
  return m_signalproxy_ConnectionStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_RsesConnectStatus() {
  return m_signalproxy_RsesConnectStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        std::vector
                                            < uint8_t >> )>> com_jci_vbs_radioProxy::signal_iTunes_TaggingInfo() {
  return m_signalproxy_iTunes_TaggingInfo;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_XM_MAP_Info() {
  return m_signalproxy_XM_MAP_Info;

}
std::shared_ptr <DBus::SignalProxy<void(
    std::tuple < std::vector < uint8_t >> )>> com_jci_vbs_radioProxy::signal_XM_Signal_Info() {
  return m_signalproxy_XM_Signal_Info;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t, uint8_t)>> com_jci_vbs_radioProxy::signal_RDS_HAR_Response() {
  return m_signalproxy_RDS_HAR_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_RDS_TAInterrupt_Response() {
  return m_signalproxy_RDS_TAInterrupt_Response;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t > )>> com_jci_vbs_radioProxy::signal_TAU_TestMode_Response() {
  return m_signalproxy_TAU_TestMode_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_XM_Title_Response() {
  return m_signalproxy_XM_Title_Response;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t > )>> com_jci_vbs_radioProxy::signal_XM_Metadata_Notification() {
  return m_signalproxy_XM_Metadata_Notification;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint16_t > )>> com_jci_vbs_radioProxy::signal_HD_MetadataChange_Notification() {
  return m_signalproxy_HD_MetadataChange_Notification;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint16_t > )>> com_jci_vbs_radioProxy::signal_HD_Tuner2_Status_Response() {
  return m_signalproxy_HD_Tuner2_Status_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_Text_Notification() {
  return m_signalproxy_Text_Notification;

}
std::shared_ptr <DBus::SignalProxy<void(
    std::tuple < std::vector < uint8_t >> )>> com_jci_vbs_radioProxy::signal_HD_ID3_XHDR_Response() {
  return m_signalproxy_HD_ID3_XHDR_Response;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        std::vector < uint8_t > ,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        std::vector
                                            < uint8_t >> )>> com_jci_vbs_radioProxy::signal_XM_ModuleData_Response() {
  return m_signalproxy_XM_ModuleData_Response;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t > )>> com_jci_vbs_radioProxy::signal_XM_SerialNumber_Response() {
  return m_signalproxy_XM_SerialNumber_Response;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < std::vector < uint8_t > ,
                                        std::vector < uint8_t > ,
                                        std::vector < uint8_t > ,
                                        std::vector < uint8_t > ,
                                        std::vector < uint8_t > ,
                                        std::vector < uint8_t > ,
                                        std::vector < uint8_t > ,
                                        std::vector < uint8_t > ,
                                        std::vector < uint8_t > ,
                                        std::vector < uint8_t > ,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t > )>> com_jci_vbs_radioProxy::signal_HD_ErrorStatusResponse() {
  return m_signalproxy_HD_ErrorStatusResponse;

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t)>> com_jci_vbs_radioProxy::signal_HD_RadioNumBlend_Response() {
  return m_signalproxy_HD_RadioNumBlend_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_SignalInfoChange_Response() {
  return m_signalproxy_SignalInfoChange_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t,
                                        uint8_t)>> com_jci_vbs_radioProxy::signal_XM_MAP_DuplicateChannelNotification() {
  return m_signalproxy_XM_MAP_DuplicateChannelNotification;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_HD_BER_Status() {
  return m_signalproxy_HD_BER_Status;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_HD_BCTL_Status() {
  return m_signalproxy_HD_BCTL_Status;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_RDS_AlarmInterrupt_Response() {
  return m_signalproxy_RDS_AlarmInterrupt_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_New4ARegionInfo() {
  return m_signalproxy_New4ARegionInfo;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_NewJapanRegionInfo() {
  return m_signalproxy_NewJapanRegionInfo;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        std::vector < uint8_t > ,
                                        uint16_t,
                                        uint16_t,
                                        uint8_t > )>> com_jci_vbs_radioProxy::signal_DAB_ChStatus_Response() {
  return m_signalproxy_DAB_ChStatus_Response;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t > )>> com_jci_vbs_radioProxy::signal_DAB_Mode_Status() {
  return m_signalproxy_DAB_Mode_Status;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_DAB_FMLinkSetting_Status() {
  return m_signalproxy_DAB_FMLinkSetting_Status;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_DAB_LinkSetting_Status() {
  return m_signalproxy_DAB_LinkSetting_Status;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_DAB_List_Status() {
  return m_signalproxy_DAB_List_Status;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_DAB_BandSelectSetting_Status() {
  return m_signalproxy_DAB_BandSelectSetting_Status;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_DAB_RadioText_Status() {
  return m_signalproxy_DAB_RadioText_Status;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_DAB_SignalStrength_Status() {
  return m_signalproxy_DAB_SignalStrength_Status;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_DAB_DiagMode_Status() {
  return m_signalproxy_DAB_DiagMode_Status;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t
                                            > )>> com_jci_vbs_radioProxy::signal_DAB_EnsembleListMgmtInfo_Response() {
  return m_signalproxy_DAB_EnsembleListMgmtInfo_Response;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t,
                                        uint16_t,
                                        std::vector < uint8_t > ,
                                        std::vector < uint8_t
                                            >> )>> com_jci_vbs_radioProxy::signal_DAB_EnsembleInfoList_Response() {
  return m_signalproxy_DAB_EnsembleInfoList_Response;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint16_t,
                                        uint16_t > )>> com_jci_vbs_radioProxy::signal_DAB_CompoListMgmtInfo_Response() {
  return m_signalproxy_DAB_CompoListMgmtInfo_Response;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t,
                                        uint16_t,
                                        uint16_t,
                                        uint8_t,
                                        std::vector < uint8_t
                                            >> )>> com_jci_vbs_radioProxy::signal_DAB_CompoInfoList_Response() {
  return m_signalproxy_DAB_CompoInfoList_Response;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        std::vector
                                            < uint8_t >> )>> com_jci_vbs_radioProxy::signal_DAB_Label_Response() {
  return m_signalproxy_DAB_Label_Response;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t > )>> com_jci_vbs_radioProxy::signal_DAB_TAUConfig_Status() {
  return m_signalproxy_DAB_TAUConfig_Status;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_radioProxy::signal_DAB_Info_Status() {
  return m_signalproxy_DAB_Info_Status;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint16_t,
                                        uint32_t,
                                        std::vector < uint8_t > ,
                                        uint8_t,
                                        uint16_t,
                                        uint16_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint16_t,
                                        uint16_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t > )>> com_jci_vbs_radioProxy::signal_DAB_Diag_Status() {
  return m_signalproxy_DAB_Diag_Status;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t, uint8_t)>> com_jci_vbs_radioProxy::signal_DAB_List_Current_State() {
  return m_signalproxy_DAB_List_Current_State;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t, uint8_t)>> com_jci_vbs_radioProxy::signal_DAB_Text_Info_Status() {
  return m_signalproxy_DAB_Text_Info_Status;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t > )>> com_jci_vbs_radioProxy::signal_TauXmhSts_XmModulePowerSts() {
  return m_signalproxy_TauXmhSts_XmModulePowerSts;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t > )>> com_jci_vbs_radioProxy::signal_TauXmhSts_SxiCommandReq() {
  return m_signalproxy_TauXmhSts_SxiCommandReq;

}
