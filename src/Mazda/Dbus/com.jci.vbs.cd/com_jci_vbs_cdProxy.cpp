#include "com_jci_vbs_cdProxy.h"

com_jci_vbs_cdProxy::com_jci_vbs_cdProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_PlayCDRequest = this->create_method<uint8_t()>("PlayCDRequest");
  m_method_PauseCDRequest = this->create_method<uint8_t()>("PauseCDRequest");
  m_method_NextTrackCDRequest = this->create_method<uint8_t()>("NextTrackCDRequest");
  m_method_PreviousTrackCDRequest = this->create_method<uint8_t()>("PreviousTrackCDRequest");
  m_method_FastForwardCDRequest = this->create_method<uint8_t()>("FastForwardCDRequest");
  m_method_FastReverseCDRequest = this->create_method<uint8_t()>("FastReverseCDRequest");
  m_method_EjectCDRequest = this->create_method<uint8_t()>("EjectCDRequest");
  m_method_FolderUpCDRequest = this->create_method<uint8_t()>("FolderUpCDRequest");
  m_method_FolderDownCDRequest = this->create_method<uint8_t()>("FolderDownCDRequest");
  m_method_UpdateDiscCDRequest = this->create_method<uint8_t()>("UpdateDiscCDRequest");
  m_method_ScanCDRequest = this->create_method<uint8_t()>("ScanCDRequest");
  m_method_SlowForwardCDRequest = this->create_method<uint8_t()>("SlowForwardCDRequest");
  m_method_SlowRewindCDRequest = this->create_method<uint8_t()>("SlowRewindCDRequest");
  m_method_GotoMenuCDRequest = this->create_method<uint8_t()>("GotoMenuCDRequest");
  m_method_GotoPlayerMenuCDRequest = this->create_method<uint8_t()>("GotoPlayerMenuCDRequest");
  m_method_RepeatCDRequest = this->create_method<uint8_t(uint8_t)>("RepeatCDRequest");
  m_method_RandomCDRequest = this->create_method<uint8_t(uint8_t)>("RandomCDRequest");
  m_method_SubtitleSettingCDRequest = this->create_method<uint8_t(uint8_t)>("SubtitleSettingCDRequest");
  m_method_DirectTrackSeekCDRequest = this->create_method<uint8_t(uint32_t)>("DirectTrackSeekCDRequest");
  m_method_MultiAngleCDRequest = this->create_method<uint8_t(uint8_t)>("MultiAngleCDRequest");
  m_method_DVDMenuOperationCDCommand = this->create_method<uint8_t(uint8_t)>("DVDMenuOperationCDCommand");
  m_method_PlaybackJumpCDRequest = this->create_method<uint8_t(uint8_t, uint8_t)>("PlaybackJumpCDRequest");
  m_method_DVDAspectRatioChange = this->create_method<uint8_t(uint8_t)>("DVDAspectRatioChange");
  m_method_TrackFolderListRequest =
      this->create_method<uint8_t(uint8_t, uint8_t, uint16_t, uint16_t, uint16_t)>("TrackFolderListRequest");
  m_method_GetMetaDataCDRequest = this->create_method<uint8_t()>("GetMetaDataCDRequest");
  m_method_GetCDDVDReadyStatus = this->create_method<uint8_t()>("GetCDDVDReadyStatus");
  m_method_GetCDDVDStatus = this->create_method<uint8_t(uint8_t, uint8_t)>("GetCDDVDStatus");
  m_method_GetOperationStatus = this->create_method<uint8_t()>("GetOperationStatus");
  m_method_GetDiscType = this->create_method<uint8_t()>("GetDiscType");
  m_method_GetCDDTVStatus = this->create_method<uint8_t(uint8_t)>("GetCDDTVStatus");
  m_method_GetDVDConfigStatus = this->create_method<uint8_t()>("GetDVDConfigStatus");
  m_method_GetMaxAllowedMovieRatingRequest = this->create_method<uint16_t()>("GetMaxAllowedMovieRatingRequest");
  m_method_DVDParentalCntlNotification = this->create_method<uint8_t(uint8_t, uint16_t)>("DVDParentalCntlNotification");
  m_method_GetAllCDDVDStatus = this->create_method<uint8_t()>("GetAllCDDVDStatus");
  m_method_TouchPanelID = this->create_method<uint8_t(uint16_t, uint16_t)>("TouchPanelID");
  m_method_TVControlRequest = this->create_method<uint8_t(uint8_t, uint8_t)>("TVControlRequest");
  m_method_DTV_VideoSource_Change_Request = this->create_method<uint8_t(uint8_t)>("DTV_VideoSource_Change_Request");
  m_method_GetCDTVRoutineTestRespStatus = this->create_method<uint8_t()>("GetCDTVRoutineTestRespStatus");
  m_method_RoutineTest_Request = this->create_method<uint8_t(uint8_t, uint8_t)>("RoutineTest_Request");
  m_signalproxy_cdDVDStatusResp =
      this->create_signal<void(std::tuple < uint8_t, std::vector < uint8_t >> )>("cdDVDStatusResp");
  m_signalproxy_cdDTVStatusResp = this->create_signal<void(uint8_t, uint8_t)>("cdDTVStatusResp");
  m_signalproxy_metaDataResponse = this->create_signal<void(std::tuple < std::vector < uint8_t > ,
                                                            std::vector < uint8_t > ,
                                                            std::vector < uint8_t > ,
                                                            std::vector < uint8_t > ,
                                                            std::vector < uint8_t > ,
                                                            std::vector < uint8_t > ,
                                                            std::vector < uint8_t >> )>("metaDataResponse");
  m_signalproxy_trackPlayStatus = this->create_signal<void(std::tuple < uint16_t,
                                                           uint8_t,
                                                           uint8_t,
                                                           uint8_t,
                                                           uint8_t,
                                                           uint8_t,
                                                           uint8_t,
                                                           uint8_t > )>("trackPlayStatus");
  m_signalproxy_cdSourceChangeResponse = this->create_signal<void(uint8_t, uint8_t)>("cdSourceChangeResponse");
  m_signalproxy_cdDvdConfigStatusResponse = this->create_signal<void(uint8_t)>("cdDvdConfigStatusResponse");
  m_signalproxy_cdTrackFolderList =
      this->create_signal<void(std::tuple < uint8_t, uint8_t, uint16_t, uint16_t, std::vector < uint8_t >> )>(
          "cdTrackFolderList");
  m_signalproxy_cdDvdFolderContents =
      this->create_signal<void(std::tuple < uint8_t, uint16_t, uint16_t, uint16_t > )>("cdDvdFolderContents");
  m_signalproxy_cdDvdVersionResp =
      this->create_signal<void(std::tuple < std::vector < uint8_t > , std::vector < uint8_t >> )>("cdDvdVersionResp");
  m_signalproxy_cdDvdCurrTrackFoldernum = this->create_signal<void(uint8_t)>("cdDvdCurrTrackFoldernum");
  m_signalproxy_GetAllCDVDStatusResp = this->create_signal<void(std::tuple < std::vector < uint8_t > ,
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
                                                                std::vector < uint8_t >> )>("GetAllCDVDStatusResp");
  m_signalproxy_DTV_VideoSource_Change_Response = this->create_signal<void(uint8_t)>("DTV_VideoSource_Change_Response");
  m_signalproxy_DTVSourceChangeResponse = this->create_signal<void(uint8_t, uint8_t)>("DTVSourceChangeResponse");
  m_signalproxy_DTVReady = this->create_signal<void(uint8_t)>("DTVReady");
  m_signalproxy_BeepControlDTVResponse = this->create_signal<void(uint8_t)>("BeepControlDTVResponse");
  m_signalproxy_BeepControlDVDResponse = this->create_signal<void(uint8_t)>("BeepControlDVDResponse");
  m_signalproxy_DTVMaxAllowedMovieRating = this->create_signal<void(uint16_t)>("DTVMaxAllowedMovieRating");
  m_signalproxy_DTVRoutineTestResponse = this->create_signal<void(uint8_t)>("DTVRoutineTestResponse");

}
std::shared_ptr <com_jci_vbs_cdProxy> com_jci_vbs_cdProxy::create(std::string name) {
  return std::shared_ptr<com_jci_vbs_cdProxy>(new com_jci_vbs_cdProxy(name));

}
uint8_t com_jci_vbs_cdProxy::PlayCDRequest() {
  return (*m_method_PlayCDRequest)();

}
uint8_t com_jci_vbs_cdProxy::PauseCDRequest() {
  return (*m_method_PauseCDRequest)();

}
uint8_t com_jci_vbs_cdProxy::NextTrackCDRequest() {
  return (*m_method_NextTrackCDRequest)();

}
uint8_t com_jci_vbs_cdProxy::PreviousTrackCDRequest() {
  return (*m_method_PreviousTrackCDRequest)();

}
uint8_t com_jci_vbs_cdProxy::FastForwardCDRequest() {
  return (*m_method_FastForwardCDRequest)();

}
uint8_t com_jci_vbs_cdProxy::FastReverseCDRequest() {
  return (*m_method_FastReverseCDRequest)();

}
uint8_t com_jci_vbs_cdProxy::EjectCDRequest() {
  return (*m_method_EjectCDRequest)();

}
uint8_t com_jci_vbs_cdProxy::FolderUpCDRequest() {
  return (*m_method_FolderUpCDRequest)();

}
uint8_t com_jci_vbs_cdProxy::FolderDownCDRequest() {
  return (*m_method_FolderDownCDRequest)();

}
uint8_t com_jci_vbs_cdProxy::UpdateDiscCDRequest() {
  return (*m_method_UpdateDiscCDRequest)();

}
uint8_t com_jci_vbs_cdProxy::ScanCDRequest() {
  return (*m_method_ScanCDRequest)();

}
uint8_t com_jci_vbs_cdProxy::SlowForwardCDRequest() {
  return (*m_method_SlowForwardCDRequest)();

}
uint8_t com_jci_vbs_cdProxy::SlowRewindCDRequest() {
  return (*m_method_SlowRewindCDRequest)();

}
uint8_t com_jci_vbs_cdProxy::GotoMenuCDRequest() {
  return (*m_method_GotoMenuCDRequest)();

}
uint8_t com_jci_vbs_cdProxy::GotoPlayerMenuCDRequest() {
  return (*m_method_GotoPlayerMenuCDRequest)();

}
uint8_t com_jci_vbs_cdProxy::RepeatCDRequest(uint8_t trackFolderRepeat) {
  return (*m_method_RepeatCDRequest)(trackFolderRepeat);

}
uint8_t com_jci_vbs_cdProxy::RandomCDRequest(uint8_t trackFolderRandom) {
  return (*m_method_RandomCDRequest)(trackFolderRandom);

}
uint8_t com_jci_vbs_cdProxy::SubtitleSettingCDRequest(uint8_t subtitleSetting) {
  return (*m_method_SubtitleSettingCDRequest)(subtitleSetting);

}
uint8_t com_jci_vbs_cdProxy::DirectTrackSeekCDRequest(uint32_t directTrackSeek) {
  return (*m_method_DirectTrackSeekCDRequest)(directTrackSeek);

}
uint8_t com_jci_vbs_cdProxy::MultiAngleCDRequest(uint8_t multiAngle) {
  return (*m_method_MultiAngleCDRequest)(multiAngle);

}
uint8_t com_jci_vbs_cdProxy::DVDMenuOperationCDCommand(uint8_t dVDMenuOperationCmd) {
  return (*m_method_DVDMenuOperationCDCommand)(dVDMenuOperationCmd);

}
uint8_t com_jci_vbs_cdProxy::PlaybackJumpCDRequest(uint8_t playbackJump, uint8_t playbackJumpPercentage) {
  return (*m_method_PlaybackJumpCDRequest)(playbackJump, playbackJumpPercentage);

}
uint8_t com_jci_vbs_cdProxy::DVDAspectRatioChange(uint8_t dVDAspectRatioValue) {
  return (*m_method_DVDAspectRatioChange)(dVDAspectRatioValue);

}
uint8_t com_jci_vbs_cdProxy::TrackFolderListRequest(uint8_t listDirectoryType,
                                                    uint8_t listTypeReq,
                                                    uint16_t folderIndexReq,
                                                    uint16_t indexReqStart,
                                                    uint16_t indexReqStop) {
  return (*m_method_TrackFolderListRequest)(listDirectoryType,
                                            listTypeReq,
                                            folderIndexReq,
                                            indexReqStart,
                                            indexReqStop);

}
uint8_t com_jci_vbs_cdProxy::GetMetaDataCDRequest() {
  return (*m_method_GetMetaDataCDRequest)();

}
uint8_t com_jci_vbs_cdProxy::GetCDDVDReadyStatus() {
  return (*m_method_GetCDDVDReadyStatus)();

}
uint8_t com_jci_vbs_cdProxy::GetCDDVDStatus(uint8_t statusType, uint8_t metadataType) {
  return (*m_method_GetCDDVDStatus)(statusType, metadataType);

}
uint8_t com_jci_vbs_cdProxy::GetOperationStatus() {
  return (*m_method_GetOperationStatus)();

}
uint8_t com_jci_vbs_cdProxy::GetDiscType() {
  return (*m_method_GetDiscType)();

}
uint8_t com_jci_vbs_cdProxy::GetCDDTVStatus(uint8_t statusType) {
  return (*m_method_GetCDDTVStatus)(statusType);

}
uint8_t com_jci_vbs_cdProxy::GetDVDConfigStatus() {
  return (*m_method_GetDVDConfigStatus)();

}
uint16_t com_jci_vbs_cdProxy::GetMaxAllowedMovieRatingRequest() {
  return (*m_method_GetMaxAllowedMovieRatingRequest)();

}
uint8_t com_jci_vbs_cdProxy::DVDParentalCntlNotification(uint8_t parentalCntlType, uint16_t parentalCntlVal) {
  return (*m_method_DVDParentalCntlNotification)(parentalCntlType, parentalCntlVal);

}
uint8_t com_jci_vbs_cdProxy::GetAllCDDVDStatus() {
  return (*m_method_GetAllCDDVDStatus)();

}
uint8_t com_jci_vbs_cdProxy::TouchPanelID(uint16_t touchXCoord, uint16_t touchYCoord) {
  return (*m_method_TouchPanelID)(touchXCoord, touchYCoord);

}
uint8_t com_jci_vbs_cdProxy::TVControlRequest(uint8_t controlCmdType, uint8_t controlCmdVal) {
  return (*m_method_TVControlRequest)(controlCmdType, controlCmdVal);

}
uint8_t com_jci_vbs_cdProxy::DTV_VideoSource_Change_Request(uint8_t videoSrcChange) {
  return (*m_method_DTV_VideoSource_Change_Request)(videoSrcChange);

}
uint8_t com_jci_vbs_cdProxy::GetCDTVRoutineTestRespStatus() {
  return (*m_method_GetCDTVRoutineTestRespStatus)();

}
uint8_t com_jci_vbs_cdProxy::RoutineTest_Request(uint8_t routineTestType, uint8_t routineTestVal) {
  return (*m_method_RoutineTest_Request)(routineTestType, routineTestVal);

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        std::vector < uint8_t >> )>> com_jci_vbs_cdProxy::signal_cdDVDStatusResp() {
  return m_signalproxy_cdDVDStatusResp;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t, uint8_t)>> com_jci_vbs_cdProxy::signal_cdDTVStatusResp() {
  return m_signalproxy_cdDTVStatusResp;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < std::vector < uint8_t > ,
                                        std::vector < uint8_t > ,
                                        std::vector < uint8_t > ,
                                        std::vector < uint8_t > ,
                                        std::vector < uint8_t > ,
                                        std::vector < uint8_t > ,
                                        std::vector < uint8_t >> )>> com_jci_vbs_cdProxy::signal_metaDataResponse() {
  return m_signalproxy_metaDataResponse;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint16_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t > )>> com_jci_vbs_cdProxy::signal_trackPlayStatus() {
  return m_signalproxy_trackPlayStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t, uint8_t)>> com_jci_vbs_cdProxy::signal_cdSourceChangeResponse() {
  return m_signalproxy_cdSourceChangeResponse;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_cdProxy::signal_cdDvdConfigStatusResponse() {
  return m_signalproxy_cdDvdConfigStatusResponse;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t,
                                        uint16_t,
                                        uint16_t,
                                        std::vector < uint8_t >> )>> com_jci_vbs_cdProxy::signal_cdTrackFolderList() {
  return m_signalproxy_cdTrackFolderList;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint16_t,
                                        uint16_t,
                                        uint16_t > )>> com_jci_vbs_cdProxy::signal_cdDvdFolderContents() {
  return m_signalproxy_cdDvdFolderContents;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < std::vector < uint8_t > ,
                                        std::vector < uint8_t >> )>> com_jci_vbs_cdProxy::signal_cdDvdVersionResp() {
  return m_signalproxy_cdDvdVersionResp;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_cdProxy::signal_cdDvdCurrTrackFoldernum() {
  return m_signalproxy_cdDvdCurrTrackFoldernum;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < std::vector < uint8_t > ,
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
                                        std::vector
                                            < uint8_t >> )>> com_jci_vbs_cdProxy::signal_GetAllCDVDStatusResp() {
  return m_signalproxy_GetAllCDVDStatusResp;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_cdProxy::signal_DTV_VideoSource_Change_Response() {
  return m_signalproxy_DTV_VideoSource_Change_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t, uint8_t)>> com_jci_vbs_cdProxy::signal_DTVSourceChangeResponse() {
  return m_signalproxy_DTVSourceChangeResponse;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_cdProxy::signal_DTVReady() {
  return m_signalproxy_DTVReady;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_cdProxy::signal_BeepControlDTVResponse() {
  return m_signalproxy_BeepControlDTVResponse;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_cdProxy::signal_BeepControlDVDResponse() {
  return m_signalproxy_BeepControlDVDResponse;

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t)>> com_jci_vbs_cdProxy::signal_DTVMaxAllowedMovieRating() {
  return m_signalproxy_DTVMaxAllowedMovieRating;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_cdProxy::signal_DTVRoutineTestResponse() {
  return m_signalproxy_DTVRoutineTestResponse;

}
