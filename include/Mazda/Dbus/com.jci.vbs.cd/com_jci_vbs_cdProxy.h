#ifndef COM_JCI_VBS_CDPROXY_H
#define COM_JCI_VBS_CDPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_vbs_cdProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_vbs_cdProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_vbs_cdProxy> create(std::string name = "com.jci.vbs.cd");
  uint8_t PlayCDRequest();
  uint8_t PauseCDRequest();
  uint8_t NextTrackCDRequest();
  uint8_t PreviousTrackCDRequest();
  uint8_t FastForwardCDRequest();
  uint8_t FastReverseCDRequest();
  uint8_t EjectCDRequest();
  uint8_t FolderUpCDRequest();
  uint8_t FolderDownCDRequest();
  uint8_t UpdateDiscCDRequest();
  uint8_t ScanCDRequest();
  uint8_t SlowForwardCDRequest();
  uint8_t SlowRewindCDRequest();
  uint8_t GotoMenuCDRequest();
  uint8_t GotoPlayerMenuCDRequest();
  uint8_t RepeatCDRequest(uint8_t trackFolderRepeat);
  uint8_t RandomCDRequest(uint8_t trackFolderRandom);
  uint8_t SubtitleSettingCDRequest(uint8_t subtitleSetting);
  uint8_t DirectTrackSeekCDRequest(uint32_t directTrackSeek);
  uint8_t MultiAngleCDRequest(uint8_t multiAngle);
  uint8_t DVDMenuOperationCDCommand(uint8_t dVDMenuOperationCmd);
  uint8_t PlaybackJumpCDRequest(uint8_t playbackJump, uint8_t playbackJumpPercentage);
  uint8_t DVDAspectRatioChange(uint8_t dVDAspectRatioValue);
  uint8_t TrackFolderListRequest(uint8_t listDirectoryType,
                                 uint8_t listTypeReq,
                                 uint16_t folderIndexReq,
                                 uint16_t indexReqStart,
                                 uint16_t indexReqStop);
  uint8_t GetMetaDataCDRequest();
  uint8_t GetCDDVDReadyStatus();
  uint8_t GetCDDVDStatus(uint8_t statusType, uint8_t metadataType);
  uint8_t GetOperationStatus();
  uint8_t GetDiscType();
  uint8_t GetCDDTVStatus(uint8_t statusType);
  uint8_t GetDVDConfigStatus();
  uint16_t GetMaxAllowedMovieRatingRequest();
  uint8_t DVDParentalCntlNotification(uint8_t parentalCntlType, uint16_t parentalCntlVal);
  uint8_t GetAllCDDVDStatus();
  uint8_t TouchPanelID(uint16_t touchXCoord, uint16_t touchYCoord);
  uint8_t TVControlRequest(uint8_t controlCmdType, uint8_t controlCmdVal);
  uint8_t DTV_VideoSource_Change_Request(uint8_t videoSrcChange);
  uint8_t GetCDTVRoutineTestRespStatus();
  uint8_t RoutineTest_Request(uint8_t routineTestType, uint8_t routineTestVal);
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, std::vector<uint8_t>>)>> signal_cdDVDStatusResp();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t)>> signal_cdDTVStatusResp();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>>)>> signal_metaDataResponse();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint16_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t>)>> signal_trackPlayStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t)>> signal_cdSourceChangeResponse();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_cdDvdConfigStatusResponse();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint8_t,
                                                    uint16_t,
                                                    uint16_t,
                                                    std::vector<uint8_t>>)>> signal_cdTrackFolderList();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint16_t,
                                                    uint16_t,
                                                    uint16_t>)>> signal_cdDvdFolderContents();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>,
                                                    std::vector<uint8_t>>)>> signal_cdDvdVersionResp();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_cdDvdCurrTrackFoldernum();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>,
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
                                                    std::vector<uint8_t>>)>> signal_GetAllCDVDStatusResp();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_DTV_VideoSource_Change_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t)>> signal_DTVSourceChangeResponse();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_DTVReady();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_BeepControlDTVResponse();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_BeepControlDVDResponse();
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> signal_DTVMaxAllowedMovieRating();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_DTVRoutineTestResponse();
 protected:
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_PlayCDRequest;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_PauseCDRequest;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_NextTrackCDRequest;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_PreviousTrackCDRequest;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_FastForwardCDRequest;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_FastReverseCDRequest;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_EjectCDRequest;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_FolderUpCDRequest;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_FolderDownCDRequest;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_UpdateDiscCDRequest;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_ScanCDRequest;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_SlowForwardCDRequest;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_SlowRewindCDRequest;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GotoMenuCDRequest;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GotoPlayerMenuCDRequest;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_RepeatCDRequest;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_RandomCDRequest;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_SubtitleSettingCDRequest;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint32_t)>> m_method_DirectTrackSeekCDRequest;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_MultiAngleCDRequest;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_DVDMenuOperationCDCommand;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t, uint8_t)>> m_method_PlaybackJumpCDRequest;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_DVDAspectRatioChange;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t, uint8_t, uint16_t, uint16_t, uint16_t)>>
      m_method_TrackFolderListRequest;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetMetaDataCDRequest;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetCDDVDReadyStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t, uint8_t)>> m_method_GetCDDVDStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetOperationStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetDiscType;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_GetCDDTVStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetDVDConfigStatus;
  std::shared_ptr<DBus::MethodProxy<uint16_t()>> m_method_GetMaxAllowedMovieRatingRequest;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t, uint16_t)>> m_method_DVDParentalCntlNotification;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetAllCDDVDStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint16_t, uint16_t)>> m_method_TouchPanelID;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t, uint8_t)>> m_method_TVControlRequest;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_DTV_VideoSource_Change_Request;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetCDTVRoutineTestRespStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t, uint8_t)>> m_method_RoutineTest_Request;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, std::vector<uint8_t>>)>> m_signalproxy_cdDVDStatusResp;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t)>> m_signalproxy_cdDTVStatusResp;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>>)>> m_signalproxy_metaDataResponse;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint16_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t>)>> m_signalproxy_trackPlayStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t)>> m_signalproxy_cdSourceChangeResponse;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_cdDvdConfigStatusResponse;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t, uint16_t, uint16_t, std::vector<uint8_t>>)>>
      m_signalproxy_cdTrackFolderList;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint16_t, uint16_t, uint16_t>)>>
      m_signalproxy_cdDvdFolderContents;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>, std::vector<uint8_t>>)>>
      m_signalproxy_cdDvdVersionResp;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_cdDvdCurrTrackFoldernum;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>,
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
                                                    std::vector<uint8_t>>)>> m_signalproxy_GetAllCDVDStatusResp;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_DTV_VideoSource_Change_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t)>> m_signalproxy_DTVSourceChangeResponse;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_DTVReady;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_BeepControlDTVResponse;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_BeepControlDVDResponse;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> m_signalproxy_DTVMaxAllowedMovieRating;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_DTVRoutineTestResponse;
};
#endif /* COM_JCI_VBS_CDPROXY_H */
