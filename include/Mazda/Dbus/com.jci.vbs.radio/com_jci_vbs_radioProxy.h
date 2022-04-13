#ifndef COM_JCI_VBS_RADIOPROXY_H
#define COM_JCI_VBS_RADIOPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_vbs_radioProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_vbs_radioProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_vbs_radioProxy> create(std::string name = "com.jci.vbs.radio");
  uint8_t Tune_Request(std::tuple<uint8_t, uint8_t> tune);
  uint8_t Seek_Request(uint8_t seek);
  uint8_t QuickSeek_Request(uint8_t quickSeek);
  uint8_t Scan_Request(uint8_t scan);
  uint8_t DirectControl(std::tuple<double, uint16_t, uint8_t> directControl);
  uint8_t Control1_Request(uint8_t hARWrite);
  uint8_t PTY_Request(uint8_t pty);
  uint8_t RDS_AF_Request(uint8_t aF);
  uint8_t RDS_REG_Request(uint8_t rEG);
  uint8_t HD_Request(uint8_t hD);
  uint8_t TA_Request(uint8_t tA);
  uint8_t SubTunerControl_Request(std::tuple<uint8_t, uint16_t> subTunerReq);
  uint8_t HD_ChannelUp_Request(uint8_t hDChannelUp);
  uint8_t HD_ErrorRateDisplayMode_Request(uint8_t hDErrorRateDisplayMode, uint8_t hDTunerType);
  uint8_t HD_PageNumber_Request(uint8_t hDPageNumber);
  uint8_t HD_DiagTestNum_Request(uint8_t hDDiagTestNum);
  uint8_t HD_Parameter1_Request(uint8_t hDParameter1);
  uint8_t HD_Parameter2_Request(uint8_t hDParameter2);
  uint8_t HD_RadioErrorStatus_Request(uint8_t hDRadioErrorStatus);
  uint8_t Mute_Request(std::tuple<uint8_t, uint8_t> mute);
  uint8_t Vol_Request(uint8_t vol);
  uint8_t AudioSettings_Request(std::tuple<uint8_t, uint8_t> audioSettings);
  uint8_t ACUInitialization_Request(uint8_t aCUIn);
  uint8_t ACUAudioPilot_Request(uint8_t audioPilot);
  uint8_t ACUCenterPoint_Request(uint8_t centerPoint);
  uint8_t StationListCreation_Request(uint8_t request, uint8_t dest_id);
  uint8_t Text_Request(uint8_t textReq);
  uint8_t HD_SISStatus_Request(uint8_t sISReq);
  uint8_t HD_PSD_Request(uint8_t pSDRequest);
  uint8_t HD_ErrorStatus_Request(uint8_t errorStatusReq);
  uint8_t AUTO_M_Request(uint8_t autoM);
  uint8_t XM_DirectType_Request(uint8_t directType, uint8_t stepCH, uint8_t stepSID);
  uint8_t XM_RelativeTune_Request(uint8_t step, uint8_t tuneDirection);
  uint8_t XM_Diag_Request(uint8_t diagRequest);
  uint8_t XM_ExpandedDiagMode_Request(uint8_t expDiagMode);
  uint8_t XM_Mute_Request(uint8_t muteReq);
  uint8_t ElectricField_Request(uint8_t signalStrength);
  uint8_t Test_Mode_Variation_Page_Antenna_Request(std::tuple<uint8_t,
                                                              uint8_t,
                                                              uint8_t,
                                                              uint8_t> testMode_Variation_Page_Antenna);
  uint8_t AutoStore_Request(uint8_t autostore);
  uint8_t GetConnStatus();
  uint8_t AUX_GetConnStatus();
  uint8_t XM_Config_GetStatus();
  uint8_t GetDestinationType();
  uint8_t GetRadioID();
  uint8_t GetHDOnOffStatus();
  uint8_t GetTAOnOffStatus();
  uint8_t GetHARFreqSetting();
  uint8_t GetCurrentGenreSetting();
  uint8_t GetAlternateFreqOnOffStatus();
  uint8_t GetRegionLockOnOffStatus();
  uint8_t XM_SendSignalInfoRequest(uint8_t xMSignalInfoReqType);
  uint8_t HD_GetTunerResponse();
  uint8_t GetTunerResponse();
  uint8_t XM_GetRadioStatusResponse();
  uint8_t Get4ARegionInfo();
  uint8_t GetJapanRegionInfo();
  uint8_t DAB_Command_Request(std::tuple<uint8_t, uint8_t, uint16_t, uint16_t> dabCmdReq);
  uint8_t DAB_Control_Request(std::tuple<uint8_t, uint8_t> dabCtrlReq);
  std::tuple<bool, bool, bool> DAB_Get_InfoStatus();
  uint8_t DAB_Get_SignalStrength();
  std::tuple<uint8_t, std::vector<uint8_t>, uint16_t, uint16_t, uint8_t> DAB_Get_ChStatus();
  std::tuple<uint8_t, uint8_t> DAB_Get_ModeStatus();
  uint8_t DAB_Get_ListUpdateStatus();
  uint8_t DAB_DirectControl(std::tuple<std::vector<uint8_t>, uint16_t, uint16_t, uint8_t> directCtrl);
  uint8_t DAB_Get_Link_Status();
  uint8_t DAB_Get_FMLink_Status();
  uint8_t DAB_Get_BandSelect_Status();
  std::tuple<uint8_t, uint8_t> DAB_Get_TAUStatus();
  uint8_t DAB_InterruptNotification(uint8_t notify);
  uint8_t XM_SxiPowerSts(uint8_t sxiPowerSts);
  uint8_t XM_SxiBaudRate(uint8_t sxiBaudRate);
  uint8_t XM_XmModuleResetReq(uint8_t xmModuleResetReq);
  std::tuple<uint8_t, uint8_t> TauXmhSts_getXmModulePowerSts();
  std::tuple<uint8_t, uint8_t> TauXmhSts_getSxiCommandReq();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>, uint16_t>)>> signal_Tuner_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_FrequencyLastKeep_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_HARWrite_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t)>> signal_PTY_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_PTYChange_Notification();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_AF_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_REG_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_HD_Response();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    std::vector<uint8_t>,
                                                    uint8_t>)>> signal_HD_Tuner_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_HD_PSD_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_TA_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_RDS_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_Metadata_Response();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t>)>> signal_AudioSetting_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_ACU_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_StationList_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_PresetInfo_Response();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, std::vector<uint8_t>>)>> signal_Text_Response();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    std::vector<uint8_t>>)>> signal_HD_SISStatus_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t)>> signal_TAUSourceIndex_Response();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
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
                                                    uint8_t>)>> signal_AMP_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_TAControl_Interrupt_Response();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> signal_TAUSoftwareVersion_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_XM_RefreshStatus_Response();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t>)>> signal_XM_RadioStatus_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_XM_Mute_Status_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_AUX_Status_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_TrackChange();
  std::shared_ptr<DBus::SignalProxy<void(double)>> signal_StationChange();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, std::vector<uint8_t>>)>> signal_ModeChange();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_OffOnNotification();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_DestinationCode();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_DestinationType();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_XM_ConfigStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_ConnectionStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_RsesConnectStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, std::vector<uint8_t>>)>> signal_iTunes_TaggingInfo();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_XM_MAP_Info();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> signal_XM_Signal_Info();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t)>> signal_RDS_HAR_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_RDS_TAInterrupt_Response();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t>)>> signal_TAU_TestMode_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_XM_Title_Response();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t>)>> signal_XM_Metadata_Notification();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint16_t>)>> signal_HD_MetadataChange_Notification();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint16_t>)>> signal_HD_Tuner2_Status_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_Text_Notification();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> signal_HD_ID3_XHDR_Response();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    std::vector<uint8_t>,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    std::vector<uint8_t>>)>> signal_XM_ModuleData_Response();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> signal_XM_SerialNumber_Response();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t>)>> signal_HD_ErrorStatusResponse();
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> signal_HD_RadioNumBlend_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_SignalInfoChange_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t)>> signal_XM_MAP_DuplicateChannelNotification();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_HD_BER_Status();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_HD_BCTL_Status();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_RDS_AlarmInterrupt_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_New4ARegionInfo();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_NewJapanRegionInfo();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    std::vector<uint8_t>,
                                                    uint16_t,
                                                    uint16_t,
                                                    uint8_t>)>> signal_DAB_ChStatus_Response();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t>)>> signal_DAB_Mode_Status();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_DAB_FMLinkSetting_Status();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_DAB_LinkSetting_Status();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_DAB_List_Status();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_DAB_BandSelectSetting_Status();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_DAB_RadioText_Status();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_DAB_SignalStrength_Status();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_DAB_DiagMode_Status();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t>)>> signal_DAB_EnsembleListMgmtInfo_Response();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint8_t,
                                                    uint16_t,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>>)>> signal_DAB_EnsembleInfoList_Response();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint16_t,
                                                    uint16_t>)>> signal_DAB_CompoListMgmtInfo_Response();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint8_t,
                                                    uint16_t,
                                                    uint16_t,
                                                    uint8_t,
                                                    std::vector<uint8_t>>)>> signal_DAB_CompoInfoList_Response();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    std::vector<uint8_t>>)>> signal_DAB_Label_Response();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t>)>> signal_DAB_TAUConfig_Status();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_DAB_Info_Status();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint16_t,
                                                    uint32_t,
                                                    std::vector<uint8_t>,
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
                                                    uint8_t>)>> signal_DAB_Diag_Status();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t)>> signal_DAB_List_Current_State();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t)>> signal_DAB_Text_Info_Status();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t>)>> signal_TauXmhSts_XmModulePowerSts();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t>)>> signal_TauXmhSts_SxiCommandReq();
 protected:
  std::shared_ptr<DBus::MethodProxy<uint8_t(std::tuple<uint8_t, uint8_t>)>> m_method_Tune_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_Seek_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_QuickSeek_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_Scan_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(std::tuple<double, uint16_t, uint8_t>)>> m_method_DirectControl;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_Control1_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_PTY_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_RDS_AF_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_RDS_REG_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_HD_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_TA_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(std::tuple<uint8_t, uint16_t>)>> m_method_SubTunerControl_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_HD_ChannelUp_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t, uint8_t)>> m_method_HD_ErrorRateDisplayMode_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_HD_PageNumber_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_HD_DiagTestNum_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_HD_Parameter1_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_HD_Parameter2_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_HD_RadioErrorStatus_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(std::tuple<uint8_t, uint8_t>)>> m_method_Mute_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_Vol_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(std::tuple<uint8_t, uint8_t>)>> m_method_AudioSettings_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_ACUInitialization_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_ACUAudioPilot_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_ACUCenterPoint_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t, uint8_t)>> m_method_StationListCreation_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_Text_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_HD_SISStatus_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_HD_PSD_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_HD_ErrorStatus_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_AUTO_M_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t, uint8_t, uint8_t)>> m_method_XM_DirectType_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t, uint8_t)>> m_method_XM_RelativeTune_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_XM_Diag_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_XM_ExpandedDiagMode_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_XM_Mute_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_ElectricField_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>)>>
      m_method_Test_Mode_Variation_Page_Antenna_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_AutoStore_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetConnStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_AUX_GetConnStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_XM_Config_GetStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetDestinationType;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetRadioID;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetHDOnOffStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetTAOnOffStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetHARFreqSetting;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetCurrentGenreSetting;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetAlternateFreqOnOffStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetRegionLockOnOffStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_XM_SendSignalInfoRequest;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_HD_GetTunerResponse;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetTunerResponse;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_XM_GetRadioStatusResponse;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_Get4ARegionInfo;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetJapanRegionInfo;
  std::shared_ptr<DBus::MethodProxy<uint8_t(std::tuple<uint8_t, uint8_t, uint16_t, uint16_t>)>>
      m_method_DAB_Command_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t(std::tuple<uint8_t, uint8_t>)>> m_method_DAB_Control_Request;
  std::shared_ptr<DBus::MethodProxy<std::tuple<bool, bool, bool>()>> m_method_DAB_Get_InfoStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_DAB_Get_SignalStrength;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint8_t, std::vector<uint8_t>, uint16_t, uint16_t, uint8_t>()>>
      m_method_DAB_Get_ChStatus;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint8_t, uint8_t>()>> m_method_DAB_Get_ModeStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_DAB_Get_ListUpdateStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t(std::tuple<std::vector<uint8_t>, uint16_t, uint16_t, uint8_t>)>>
      m_method_DAB_DirectControl;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_DAB_Get_Link_Status;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_DAB_Get_FMLink_Status;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_DAB_Get_BandSelect_Status;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint8_t, uint8_t>()>> m_method_DAB_Get_TAUStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_DAB_InterruptNotification;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_XM_SxiPowerSts;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_XM_SxiBaudRate;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_XM_XmModuleResetReq;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint8_t, uint8_t>()>> m_method_TauXmhSts_getXmModulePowerSts;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint8_t, uint8_t>()>> m_method_TauXmhSts_getSxiCommandReq;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>, uint16_t>)>> m_signalproxy_Tuner_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_FrequencyLastKeep_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_HARWrite_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t)>> m_signalproxy_PTY_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_PTYChange_Notification;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_AF_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_REG_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_HD_Response;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    std::vector<uint8_t>,
                                                    uint8_t>)>> m_signalproxy_HD_Tuner_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_HD_PSD_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_TA_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_RDS_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_Metadata_Response;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t>)>> m_signalproxy_AudioSetting_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_ACU_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_StationList_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_PresetInfo_Response;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, std::vector<uint8_t>>)>> m_signalproxy_Text_Response;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t, uint8_t, uint8_t, std::vector<uint8_t>>)>>
      m_signalproxy_HD_SISStatus_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t)>> m_signalproxy_TAUSourceIndex_Response;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
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
                                                    uint8_t>)>> m_signalproxy_AMP_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_TAControl_Interrupt_Response;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> m_signalproxy_TAUSoftwareVersion_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_XM_RefreshStatus_Response;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t>)>>
      m_signalproxy_XM_RadioStatus_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_XM_Mute_Status_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_AUX_Status_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_TrackChange;
  std::shared_ptr<DBus::SignalProxy<void(double)>> m_signalproxy_StationChange;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, std::vector<uint8_t>>)>> m_signalproxy_ModeChange;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_OffOnNotification;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_DestinationCode;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_DestinationType;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_XM_ConfigStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_ConnectionStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_RsesConnectStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, std::vector<uint8_t>>)>> m_signalproxy_iTunes_TaggingInfo;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_XM_MAP_Info;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> m_signalproxy_XM_Signal_Info;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t)>> m_signalproxy_RDS_HAR_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_RDS_TAInterrupt_Response;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t>)>>
      m_signalproxy_TAU_TestMode_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_XM_Title_Response;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>)>>
      m_signalproxy_XM_Metadata_Notification;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint16_t>)>> m_signalproxy_HD_MetadataChange_Notification;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint16_t>)>> m_signalproxy_HD_Tuner2_Status_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_Text_Notification;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> m_signalproxy_HD_ID3_XHDR_Response;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    std::vector<uint8_t>,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    std::vector<uint8_t>>)>> m_signalproxy_XM_ModuleData_Response;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> m_signalproxy_XM_SerialNumber_Response;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t>)>> m_signalproxy_HD_ErrorStatusResponse;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> m_signalproxy_HD_RadioNumBlend_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_SignalInfoChange_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t)>> m_signalproxy_XM_MAP_DuplicateChannelNotification;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_HD_BER_Status;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_HD_BCTL_Status;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_RDS_AlarmInterrupt_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_New4ARegionInfo;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_NewJapanRegionInfo;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, std::vector<uint8_t>, uint16_t, uint16_t, uint8_t>)>>
      m_signalproxy_DAB_ChStatus_Response;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t>)>> m_signalproxy_DAB_Mode_Status;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_DAB_FMLinkSetting_Status;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_DAB_LinkSetting_Status;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_DAB_List_Status;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_DAB_BandSelectSetting_Status;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_DAB_RadioText_Status;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_DAB_SignalStrength_Status;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_DAB_DiagMode_Status;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t>)>>
      m_signalproxy_DAB_EnsembleListMgmtInfo_Response;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint8_t,
                                                    uint16_t,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>>)>>
      m_signalproxy_DAB_EnsembleInfoList_Response;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint16_t, uint16_t>)>>
      m_signalproxy_DAB_CompoListMgmtInfo_Response;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint8_t,
                                                    uint16_t,
                                                    uint16_t,
                                                    uint8_t,
                                                    std::vector<uint8_t>>)>> m_signalproxy_DAB_CompoInfoList_Response;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t, uint8_t, std::vector<uint8_t>>)>>
      m_signalproxy_DAB_Label_Response;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t>)>> m_signalproxy_DAB_TAUConfig_Status;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_DAB_Info_Status;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint16_t,
                                                    uint32_t,
                                                    std::vector<uint8_t>,
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
                                                    uint8_t>)>> m_signalproxy_DAB_Diag_Status;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t)>> m_signalproxy_DAB_List_Current_State;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t)>> m_signalproxy_DAB_Text_Info_Status;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t>)>> m_signalproxy_TauXmhSts_XmModulePowerSts;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t>)>> m_signalproxy_TauXmhSts_SxiCommandReq;
};
#endif /* COM_JCI_VBS_RADIOPROXY_H */
