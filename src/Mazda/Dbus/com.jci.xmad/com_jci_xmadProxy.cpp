#include "com_jci_xmadProxy.h"

com_jci_xmadProxy::com_jci_xmadProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_GetScanSetting = this->create_method<int32_t()>("GetScanSetting");
  m_method_GetInstallStatus = this->create_method<int32_t()>("GetInstallStatus");
  m_method_GetSignalQuality = this->create_method<int32_t()>("GetSignalQuality");
  m_method_GetAntennaState = this->create_method<int32_t()>("GetAntennaState");
  m_method_GetFirstXMFavAddition = this->create_method<int32_t()>("GetFirstXMFavAddition");
  m_method_GetTuneStartSettingStatus = this->create_method<int32_t()>("GetTuneStartSettingStatus");
  m_method_GetFavListID = this->create_method<int32_t()>("GetFavListID");
  m_method_GetActiveCategory = this->create_method<int32_t()>("GetActiveCategory");
  m_method_GetSessionLockStatus = this->create_method<int32_t()>("GetSessionLockStatus");
  m_method_GetParentalLockInitSetupStatus = this->create_method<int32_t()>("GetParentalLockInitSetupStatus");
  m_method_GetIsTuneScanSettingUsedBefore = this->create_method<int32_t()>("GetIsTuneScanSettingUsedBefore");
  m_method_GetTuneScanContentAvailabilityInfo = this->create_method<int32_t()>("GetTuneScanContentAvailabilityInfo");
  m_method_GetBTConnectionStatus = this->create_method<int32_t()>("GetBTConnectionStatus");
  m_method_GetIRBufferCapacity = this->create_method<int32_t()>("GetIRBufferCapacity");
  m_method_GetESN = this->create_method<int32_t()>("GetESN");
  m_method_GetSmartFavChannelsCount = this->create_method<int32_t()>("GetSmartFavChannelsCount");
  m_method_GetTuneMixActiveStatus = this->create_method<int32_t()>("GetTuneMixActiveStatus");
  m_method_GetTuneMixCount = this->create_method<int32_t()>("GetTuneMixCount");
  m_method_GetTuneStartFirstTimeUsage = this->create_method<int32_t()>("GetTuneStartFirstTimeUsage");
  m_method_GetTuneMixDetails = this->create_method<int32_t(uint32_t)>("GetTuneMixDetails");
  m_method_GetSportFlashActiveStatus = this->create_method<int32_t()>("GetSportFlashActiveStatus");
  m_method_GetSportFlashFreq = this->create_method<int32_t()>("GetSportFlashFreq");
  m_method_GetSportFlashFirstTimeUsage = this->create_method<int32_t()>("GetSportFlashFirstTimeUsage");
  m_method_GetTWReportActiveStatus = this->create_method<int32_t()>("GetTWReportActiveStatus");
  m_method_GetTWReportFreq = this->create_method<int32_t()>("GetTWReportFreq");
  m_method_GetTWReportFirstTimeUsage = this->create_method<int32_t()>("GetTWReportFirstTimeUsage");
  m_method_GetNearestCityName = this->create_method<int32_t()>("GetNearestCityName");
  m_method_GetSubscriptionUpdateStatus = this->create_method<int32_t()>("GetSubscriptionUpdateStatus");
  m_method_SourceChangeToXM = this->create_method<int32_t()>("SourceChangeToXM");
  m_method_Seek = this->create_method<int32_t(uint32_t)>("Seek");
  m_method_DirectTune = this->create_method<int32_t(uint32_t, bool)>("DirectTune");
  m_method_ChangeCategory = this->create_method<int32_t(uint32_t, uint32_t)>("ChangeCategory");
  m_method_ScanSetting = this->create_method<int32_t(uint32_t)>("ScanSetting");
  m_method_ScanReq = this->create_method<int32_t(std::tuple < uint32_t, uint32_t > )>("ScanReq");
  m_method_TuneStartSetting = this->create_method<int32_t(bool)>("TuneStartSetting");
  m_method_EditSmartFavList = this->create_method<int32_t(uint32_t, bool)>("EditSmartFavList");
  m_method_SessionLock = this->create_method<int32_t(std::tuple < uint32_t, bool > )>("SessionLock");
  m_method_ChannelLock = this->create_method<int32_t(std::tuple < uint32_t, uint32_t > )>("ChannelLock");
  m_method_RequestPinResponse =
      this->create_method<int32_t(std::tuple < uint32_t, std::tuple < uint8_t, uint8_t, uint8_t, uint8_t >> )>(
          "RequestPinResponse");
  m_method_ChangePinReq = this->create_method<int32_t(uint32_t)>("ChangePinReq");
  m_method_PlayControl = this->create_method<int32_t(uint32_t)>("PlayControl");
  m_method_SeekTime = this->create_method<int32_t(int32_t)>("SeekTime");
  m_method_SeekTrack = this->create_method<int32_t(uint32_t)>("SeekTrack");
  m_method_CreateTuneMix = this->create_method
      < int32_t(std::tuple < std::vector < std::tuple < uint32_t, std::string, bool>>>)>("CreateTuneMix");
  m_method_EditTuneMix = this->create_method
      < int32_t(std::tuple < uint32_t, std::vector < std::tuple < uint32_t, std::string, bool>>>)>("EditTuneMix");
  m_method_RenameTuneMix = this->create_method<int32_t(std::tuple < uint32_t, std::string > )>("RenameTuneMix");
  m_method_RemoveTuneMix = this->create_method<int32_t(uint32_t)>("RemoveTuneMix");
  m_method_TuneStartUsed = this->create_method<int32_t()>("TuneStartUsed");
  m_method_FirstFavoriteAdded = this->create_method<int32_t()>("FirstFavoriteAdded");
  m_method_TuneScanUsed = this->create_method<int32_t()>("TuneScanUsed");
  m_method_ExitTuneMix = this->create_method<int32_t()>("ExitTuneMix");
  m_method_TuneFeaturedFav = this->create_method<int32_t(std::tuple < uint32_t, uint32_t > )>("TuneFeaturedFav");
  m_method_SportFlashFirstTimeUsed = this->create_method<int32_t()>("SportFlashFirstTimeUsed");
  m_method_SetSportsFlashFrequency = this->create_method<int32_t(uint32_t)>("SetSportsFlashFrequency");
  m_method_EnableSportFlashAlert = this->create_method<int32_t(bool)>("EnableSportFlashAlert");
  m_method_SelectSportsFlashTeam = this->create_method<int32_t(uint32_t, uint32_t, bool)>("SelectSportsFlashTeam");
  m_method_MoveSportsFlashTeam =
      this->create_method<int32_t(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t)>("MoveSportsFlashTeam");
  m_method_DismissFlashAlert = this->create_method<int32_t(uint32_t, uint32_t, uint32_t)>("DismissFlashAlert");
  m_method_PlayFlashAlert = this->create_method<int32_t(uint32_t, uint32_t)>("PlayFlashAlert");
  m_method_TurnOffAlert = this->create_method<int32_t(uint32_t)>("TurnOffAlert");
  m_method_AbortFlashAlert = this->create_method<int32_t(uint32_t, uint32_t)>("AbortFlashAlert");
  m_method_ReplayFlashAlert = this->create_method<int32_t(uint32_t, uint32_t)>("ReplayFlashAlert");
  m_method_TWReportFirstTimeUsed = this->create_method<int32_t()>("TWReportFirstTimeUsed");
  m_method_SetTWReportFrequency = this->create_method<int32_t(uint32_t)>("SetTWReportFrequency");
  m_method_EnableTWReportAlert = this->create_method<int32_t(bool)>("EnableTWReportAlert");
  m_method_SelectTWCity = this->create_method<int32_t(std::string, bool)>("SelectTWCity");
  m_method_SuspendAlertContextStatus = this->create_method<int32_t(bool)>("SuspendAlertContextStatus");
  m_method_isValidChannelID = this->create_method<int32_t(uint32_t)>("isValidChannelID");
  m_method_PlayFirstTuneMix = this->create_method<int32_t()>("PlayFirstTuneMix");
  m_method_GetFlashAvailableStatus = this->create_method<int32_t(uint32_t)>("GetFlashAvailableStatus");
  m_method_SubscriptionUserAccept = this->create_method<int32_t()>("SubscriptionUserAccept");
  m_method_PlayTuneGame = this->create_method<int32_t(uint32_t, uint32_t, uint32_t, bool)>("PlayTuneGame");
  m_method_SubscriptionUpdateConf = this->create_method<int32_t(bool)>("SubscriptionUpdateConf");
  m_signalproxy_SourceChangeStatus = this->create_signal<void(uint32_t)>("SourceChangeStatus");
  m_signalproxy_TuneStatus = this->create_signal<void(std::tuple < uint32_t, uint32_t > )>("TuneStatus");
  m_signalproxy_installStatus = this->create_signal<void(uint32_t)>("installStatus");
  m_signalproxy_SignalQuality = this->create_signal<void(uint32_t)>("SignalQuality");
  m_signalproxy_AntennaState = this->create_signal<void(uint32_t)>("AntennaState");
  m_signalproxy_ChannelDescriptionServiceStatus = this->create_signal<void(bool)>("ChannelDescriptionServiceStatus");
  m_signalproxy_TuneStartSettingStatus = this->create_signal<void(bool)>("TuneStartSettingStatus");
  m_signalproxy_LockPinStatus = this->create_signal<void(uint32_t)>("LockPinStatus");
  m_signalproxy_CurrentTunedChannel =
      this->create_signal<void(std::tuple < uint32_t, uint32_t, std::vector < uint8_t > , uint32_t > )>(
          "CurrentTunedChannel");
  m_signalproxy_ChannelStatus =
      this->create_signal<void(std::tuple < uint32_t, bool, uint32_t, uint32_t, uint32_t > )>("ChannelStatus");
  m_signalproxy_ActiveCategory =
      this->create_signal<void(std::tuple < uint32_t, uint32_t, uint32_t, uint32_t, uint32_t > )>("ActiveCategory");
  m_signalproxy_ScanStatus = this->create_signal<void(std::tuple < uint32_t, uint32_t > )>("ScanStatus");
  m_signalproxy_ScanReqStatus = this->create_signal<void(uint32_t)>("ScanReqStatus");
  m_signalproxy_ScanSettingStatus = this->create_signal<void(uint32_t)>("ScanSettingStatus");
  m_signalproxy_DirectTuneStatus = this->create_signal<void(std::tuple < uint32_t, uint32_t > )>("DirectTuneStatus");
  m_signalproxy_ChannelListUpdateStatus =
      this->create_signal<void(uint32_t, uint32_t, uint32_t, bool, std::tuple < bool, bool, bool, bool > )>(
          "ChannelListUpdateStatus");
  m_signalproxy_CategoryUpdate =
      this->create_signal<void(uint32_t, std::string, std::tuple < bool, bool, bool > )>("CategoryUpdate");
  m_signalproxy_RequestPin = this->create_signal<void(uint32_t)>("RequestPin");
  m_signalproxy_RequestPinStatus = this->create_signal<void(uint32_t)>("RequestPinStatus");
  m_signalproxy_ChannelLockStatus = this->create_signal<void(uint32_t)>("ChannelLockStatus");
  m_signalproxy_SessionLockStatus = this->create_signal<void(uint32_t)>("SessionLockStatus");
  m_signalproxy_ParentalLockInitSetupStatus = this->create_signal<void(bool)>("ParentalLockInitSetupStatus");
  m_signalproxy_SeekStatus = this->create_signal<void(std::tuple < uint32_t, uint32_t > )>("SeekStatus");
  m_signalproxy_EditSmartFavListStatus = this->create_signal<void(uint32_t, bool, uint32_t)>("EditSmartFavListStatus");
  m_signalproxy_NotifyFirstXMFavAddition = this->create_signal<void(bool)>("NotifyFirstXMFavAddition");
  m_signalproxy_NotifyFavListID = this->create_signal<void(uint32_t)>("NotifyFavListID");
  m_signalproxy_TuneScanSettingFirstTimeUsage = this->create_signal<void(bool)>("TuneScanSettingFirstTimeUsage");
  m_signalproxy_TuneScanContentAvailabilityStatus =
      this->create_signal<void(bool)>("TuneScanContentAvailabilityStatus");
  m_signalproxy_BTConnectionStatus = this->create_signal<void(bool)>("BTConnectionStatus");
  m_signalproxy_SubscriptionStatus = this->create_signal<void(std::tuple < uint32_t,
                                                              uint8_t,
                                                              uint32_t,
                                                              std::vector < uint8_t > ,
                                                              std::vector < uint8_t >> )>("SubscriptionStatus");
  m_signalproxy_IRBufferCapacityStatus =
      this->create_signal<void(std::tuple < uint32_t, uint32_t > )>("IRBufferCapacityStatus");
  m_signalproxy_PlayControlStatus = this->create_signal<void(uint32_t)>("PlayControlStatus");
  m_signalproxy_PlayBackStatus = this->create_signal<void(std::tuple < uint32_t, uint32_t > )>("PlayBackStatus");
  m_signalproxy_PlaybackTimeStatus =
      this->create_signal<void(std::tuple < uint32_t, uint32_t, uint32_t > )>("PlaybackTimeStatus");
  m_signalproxy_SeekTimeStatus = this->create_signal<void(uint32_t)>("SeekTimeStatus");
  m_signalproxy_PlaybackOffsetIndication = this->create_signal<void(uint32_t)>("PlaybackOffsetIndication");
  m_signalproxy_ESNInfo = this->create_signal<void(std::string)>("ESNInfo");
  m_signalproxy_TracksBeforeAfter = this->create_signal<void(std::tuple < uint32_t, uint32_t > )>("TracksBeforeAfter");
  m_signalproxy_TuneMixActive =
      this->create_signal<void(std::tuple < bool, uint32_t, std::vector < uint8_t >> )>("TuneMixActive");
  m_signalproxy_PlaybackTrackTimeStatus =
      this->create_signal<void(std::tuple < uint32_t, uint32_t > )>("PlaybackTrackTimeStatus");
  m_signalproxy_CreateTuneMixStatus =
      this->create_signal<void(std::tuple < std::vector < uint8_t > , uint32_t, uint32_t, uint32_t > )>(
          "CreateTuneMixStatus");
  m_signalproxy_EditTuneMixStatus =
      this->create_signal<void(std::tuple < std::vector < uint8_t > , uint32_t, uint32_t, uint32_t > )>(
          "EditTuneMixStatus");
  m_signalproxy_RenameTunemixStatus =
      this->create_signal<void(std::tuple < std::string, uint32_t > )>("RenameTunemixStatus");
  m_signalproxy_RemoveTuneMixStatus =
      this->create_signal<void(std::tuple < uint32_t, uint32_t > )>("RemoveTuneMixStatus");
  m_signalproxy_TuneStartFirstTimeUsageStatus = this->create_signal<void(bool)>("TuneStartFirstTimeUsageStatus");
  m_signalproxy_SmartFavChannelsCount = this->create_signal<void(uint32_t)>("SmartFavChannelsCount");
  m_signalproxy_TuneMixCount = this->create_signal<void(uint32_t)>("TuneMixCount");
  m_signalproxy_TuneMixDetails = this->create_signal
      < void(std::tuple < uint32_t, std::vector < std::tuple < uint32_t, std::string, bool>>>)>("TuneMixDetails");
  m_signalproxy_TuneMixListUpdated = this->create_signal<void(uint32_t)>("TuneMixListUpdated");
  m_signalproxy_TuneFeaturedFavStatus =
      this->create_signal<void(std::tuple < uint32_t, uint32_t, uint32_t, uint32_t > )>("TuneFeaturedFavStatus");
  m_signalproxy_FeaturedFavListUpdated =
      this->create_signal<void(std::tuple < uint32_t, std::vector < uint8_t > , std::tuple < bool, bool, bool >> )>(
          "FeaturedFavListUpdated");
  m_signalproxy_SportFlashActiveStatus =
      this->create_signal<void(std::tuple < bool, uint32_t > )>("SportFlashActiveStatus");
  m_signalproxy_SportFlashFrequencyStatus = this->create_signal<void(uint32_t)>("SportFlashFrequencyStatus");
  m_signalproxy_SportFlashFirstTimeUsageStatus = this->create_signal<void(bool)>("SportFlashFirstTimeUsageStatus");
  m_signalproxy_EnableSportFlashAlertStatus = this->create_signal<void(uint32_t)>("EnableSportFlashAlertStatus");
  m_signalproxy_SelectSportsFlashTeamStatus = this->create_signal<void(uint32_t)>("SelectSportsFlashTeamStatus");
  m_signalproxy_MoveSportsFlashTeamStatus = this->create_signal<void(uint32_t)>("MoveSportsFlashTeamStatus");
  m_signalproxy_SportFlashAlert = this->create_signal<void(std::tuple < uint32_t,
                                                           uint32_t,
                                                           uint32_t,
                                                           std::vector < uint8_t > ,
                                                           std::vector < uint8_t > ,
                                                           std::vector < uint8_t > ,
                                                           uint32_t > )>("SportFlashAlert");
  m_signalproxy_CancelAlert = this->create_signal<void(std::tuple < uint32_t, uint32_t, uint32_t > )>("CancelAlert");
  m_signalproxy_PlayFlashAlertStatus =
      this->create_signal<void(std::tuple < uint32_t, uint32_t > )>("PlayFlashAlertStatus");
  m_signalproxy_AbortFlashAlertStatus =
      this->create_signal<void(std::tuple < bool, uint32_t, uint32_t > )>("AbortFlashAlertStatus");
  m_signalproxy_TurnOffAlertStatus =
      this->create_signal<void(std::tuple < uint32_t, uint32_t > )>("TurnOffAlertStatus");
  m_signalproxy_ReplayFlashAlertStatus =
      this->create_signal<void(std::tuple < uint32_t, uint32_t > )>("ReplayFlashAlertStatus");
  m_signalproxy_TWFlashActiveStatus = this->create_signal<void(bool)>("TWFlashActiveStatus");
  m_signalproxy_TWFlashFrequencyStatus = this->create_signal<void(uint32_t)>("TWFlashFrequencyStatus");
  m_signalproxy_TWFirstTimeUsageStatus = this->create_signal<void(bool)>("TWFirstTimeUsageStatus");
  m_signalproxy_EnableTWReportAlertStatus = this->create_signal<void(uint32_t)>("EnableTWReportAlertStatus");
  m_signalproxy_SelectTWCityStatus = this->create_signal<void(uint32_t)>("SelectTWCityStatus");
  m_signalproxy_TWCityNameCityID =
      this->create_signal<void(std::tuple < std::vector < uint8_t > , bool, uint32_t, uint32_t > )>("TWCityNameCityID");
  m_signalproxy_TWFlashAlert =
      this->create_signal<void(std::tuple < uint32_t, uint32_t, std::vector < uint8_t > , uint32_t > )>("TWFlashAlert");
  m_signalproxy_FAVChannelsubscribed =
      this->create_signal<void(std::tuple < uint32_t, bool, std::vector < uint8_t >> )>("FAVChannelsubscribed");
  m_signalproxy_FavSportTeamCount = this->create_signal<void(uint8_t)>("FavSportTeamCount");
  m_signalproxy_ChannelValidityStatus =
      this->create_signal<void(std::tuple < uint32_t, uint32_t > )>("ChannelValidityStatus");
  m_signalproxy_UnlockSession = this->create_signal<void()>("UnlockSession");
  m_signalproxy_SubscriptionUpdated = this->create_signal<void()>("SubscriptionUpdated");
  m_signalproxy_FlashAvailableStatus = this->create_signal<void(std::tuple < uint32_t,
                                                                uint32_t,
                                                                uint32_t,
                                                                uint32_t,
                                                                std::vector < uint8_t > ,
                                                                std::vector < uint8_t > ,
                                                                std::vector < uint8_t >> )>("FlashAvailableStatus");

}
std::shared_ptr <com_jci_xmadProxy> com_jci_xmadProxy::create(std::string name) {
  return std::shared_ptr<com_jci_xmadProxy>(new com_jci_xmadProxy(name));

}
int32_t com_jci_xmadProxy::GetScanSetting() {
  return (*m_method_GetScanSetting)();

}
int32_t com_jci_xmadProxy::GetInstallStatus() {
  return (*m_method_GetInstallStatus)();

}
int32_t com_jci_xmadProxy::GetSignalQuality() {
  return (*m_method_GetSignalQuality)();

}
int32_t com_jci_xmadProxy::GetAntennaState() {
  return (*m_method_GetAntennaState)();

}
int32_t com_jci_xmadProxy::GetFirstXMFavAddition() {
  return (*m_method_GetFirstXMFavAddition)();

}
int32_t com_jci_xmadProxy::GetTuneStartSettingStatus() {
  return (*m_method_GetTuneStartSettingStatus)();

}
int32_t com_jci_xmadProxy::GetFavListID() {
  return (*m_method_GetFavListID)();

}
int32_t com_jci_xmadProxy::GetActiveCategory() {
  return (*m_method_GetActiveCategory)();

}
int32_t com_jci_xmadProxy::GetSessionLockStatus() {
  return (*m_method_GetSessionLockStatus)();

}
int32_t com_jci_xmadProxy::GetParentalLockInitSetupStatus() {
  return (*m_method_GetParentalLockInitSetupStatus)();

}
int32_t com_jci_xmadProxy::GetIsTuneScanSettingUsedBefore() {
  return (*m_method_GetIsTuneScanSettingUsedBefore)();

}
int32_t com_jci_xmadProxy::GetTuneScanContentAvailabilityInfo() {
  return (*m_method_GetTuneScanContentAvailabilityInfo)();

}
int32_t com_jci_xmadProxy::GetBTConnectionStatus() {
  return (*m_method_GetBTConnectionStatus)();

}
int32_t com_jci_xmadProxy::GetIRBufferCapacity() {
  return (*m_method_GetIRBufferCapacity)();

}
int32_t com_jci_xmadProxy::GetESN() {
  return (*m_method_GetESN)();

}
int32_t com_jci_xmadProxy::GetSmartFavChannelsCount() {
  return (*m_method_GetSmartFavChannelsCount)();

}
int32_t com_jci_xmadProxy::GetTuneMixActiveStatus() {
  return (*m_method_GetTuneMixActiveStatus)();

}
int32_t com_jci_xmadProxy::GetTuneMixCount() {
  return (*m_method_GetTuneMixCount)();

}
int32_t com_jci_xmadProxy::GetTuneStartFirstTimeUsage() {
  return (*m_method_GetTuneStartFirstTimeUsage)();

}
int32_t com_jci_xmadProxy::GetTuneMixDetails(uint32_t tunemix_Id) {
  return (*m_method_GetTuneMixDetails)(tunemix_Id);

}
int32_t com_jci_xmadProxy::GetSportFlashActiveStatus() {
  return (*m_method_GetSportFlashActiveStatus)();

}
int32_t com_jci_xmadProxy::GetSportFlashFreq() {
  return (*m_method_GetSportFlashFreq)();

}
int32_t com_jci_xmadProxy::GetSportFlashFirstTimeUsage() {
  return (*m_method_GetSportFlashFirstTimeUsage)();

}
int32_t com_jci_xmadProxy::GetTWReportActiveStatus() {
  return (*m_method_GetTWReportActiveStatus)();

}
int32_t com_jci_xmadProxy::GetTWReportFreq() {
  return (*m_method_GetTWReportFreq)();

}
int32_t com_jci_xmadProxy::GetTWReportFirstTimeUsage() {
  return (*m_method_GetTWReportFirstTimeUsage)();

}
int32_t com_jci_xmadProxy::GetNearestCityName() {
  return (*m_method_GetNearestCityName)();

}
int32_t com_jci_xmadProxy::GetSubscriptionUpdateStatus() {
  return (*m_method_GetSubscriptionUpdateStatus)();

}
int32_t com_jci_xmadProxy::SourceChangeToXM() {
  return (*m_method_SourceChangeToXM)();

}
int32_t com_jci_xmadProxy::Seek(uint32_t seek_type) {
  return (*m_method_Seek)(seek_type);

}
int32_t com_jci_xmadProxy::DirectTune(uint32_t id, bool tuneToServiceID) {
  return (*m_method_DirectTune)(id, tuneToServiceID);

}
int32_t com_jci_xmadProxy::ChangeCategory(uint32_t ch_list_type, uint32_t category_id) {
  return (*m_method_ChangeCategory)(ch_list_type, category_id);

}
int32_t com_jci_xmadProxy::ScanSetting(uint32_t scan_type) {
  return (*m_method_ScanSetting)(scan_type);

}
int32_t com_jci_xmadProxy::ScanReq(std::tuple <uint32_t, uint32_t> scan_req) {
  return (*m_method_ScanReq)(scan_req);

}
int32_t com_jci_xmadProxy::TuneStartSetting(bool tune_start_enable) {
  return (*m_method_TuneStartSetting)(tune_start_enable);

}
int32_t com_jci_xmadProxy::EditSmartFavList(uint32_t chanID, bool isSFChannel) {
  return (*m_method_EditSmartFavList)(chanID, isSFChannel);

}
int32_t com_jci_xmadProxy::SessionLock(std::tuple<uint32_t, bool> session_lock_req) {
  return (*m_method_SessionLock)(session_lock_req);

}
int32_t com_jci_xmadProxy::ChannelLock(std::tuple <uint32_t, uint32_t> channel_lock_req) {
  return (*m_method_ChannelLock)(channel_lock_req);

}
int32_t com_jci_xmadProxy::RequestPinResponse(std::tuple <uint32_t, std::tuple<uint8_t,
                                                                               uint8_t,
                                                                               uint8_t,
                                                                               uint8_t>> pin_info) {
  return (*m_method_RequestPinResponse)(pin_info);

}
int32_t com_jci_xmadProxy::ChangePinReq(uint32_t pin_type) {
  return (*m_method_ChangePinReq)(pin_type);

}
int32_t com_jci_xmadProxy::PlayControl(uint32_t playControl) {
  return (*m_method_PlayControl)(playControl);

}
int32_t com_jci_xmadProxy::SeekTime(int32_t durationInSec) {
  return (*m_method_SeekTime)(durationInSec);

}
int32_t com_jci_xmadProxy::SeekTrack(uint32_t direction) {
  return (*m_method_SeekTrack)(direction);

}
int32_t com_jci_xmadProxy::CreateTuneMix(std::tuple < std::vector < std::tuple < uint32_t, std::string, bool
>>> create_tunemix_req ){
return (*m_method_CreateTuneMix)(create_tunemix_req);

}
int32_t com_jci_xmadProxy::EditTuneMix(std::tuple < uint32_t, std::vector < std::tuple < uint32_t, std::string, bool
>>> edit_tunemix_req ){
return (*m_method_EditTuneMix)(edit_tunemix_req);

}
int32_t com_jci_xmadProxy::RenameTuneMix(std::tuple <uint32_t, std::string> rename_tunemix_req) {
  return (*m_method_RenameTuneMix)(rename_tunemix_req);

}
int32_t com_jci_xmadProxy::RemoveTuneMix(uint32_t tunemix_id) {
  return (*m_method_RemoveTuneMix)(tunemix_id);

}
int32_t com_jci_xmadProxy::TuneStartUsed() {
  return (*m_method_TuneStartUsed)();

}
int32_t com_jci_xmadProxy::FirstFavoriteAdded() {
  return (*m_method_FirstFavoriteAdded)();

}
int32_t com_jci_xmadProxy::TuneScanUsed() {
  return (*m_method_TuneScanUsed)();

}
int32_t com_jci_xmadProxy::ExitTuneMix() {
  return (*m_method_ExitTuneMix)();

}
int32_t com_jci_xmadProxy::TuneFeaturedFav(std::tuple <uint32_t, uint32_t> tune_featured_fav) {
  return (*m_method_TuneFeaturedFav)(tune_featured_fav);

}
int32_t com_jci_xmadProxy::SportFlashFirstTimeUsed() {
  return (*m_method_SportFlashFirstTimeUsed)();

}
int32_t com_jci_xmadProxy::SetSportsFlashFrequency(uint32_t flashFreq) {
  return (*m_method_SetSportsFlashFrequency)(flashFreq);

}
int32_t com_jci_xmadProxy::EnableSportFlashAlert(bool enableAlert) {
  return (*m_method_EnableSportFlashAlert)(enableAlert);

}
int32_t com_jci_xmadProxy::SelectSportsFlashTeam(uint32_t leagueId, uint32_t teamId, bool favorite) {
  return (*m_method_SelectSportsFlashTeam)(leagueId, teamId, favorite);

}
int32_t com_jci_xmadProxy::MoveSportsFlashTeam(uint32_t refLeagueID,
                                               uint32_t leagueID,
                                               uint32_t refTeamId,
                                               uint32_t teamId,
                                               uint32_t moveType) {
  return (*m_method_MoveSportsFlashTeam)(refLeagueID, leagueID, refTeamId, teamId, moveType);

}
int32_t com_jci_xmadProxy::DismissFlashAlert(uint32_t channelID, uint32_t flashEventID, uint32_t flashAlertType) {
  return (*m_method_DismissFlashAlert)(channelID, flashEventID, flashAlertType);

}
int32_t com_jci_xmadProxy::PlayFlashAlert(uint32_t flashEventID, uint32_t flashAlertType) {
  return (*m_method_PlayFlashAlert)(flashEventID, flashAlertType);

}
int32_t com_jci_xmadProxy::TurnOffAlert(uint32_t flashAlertType) {
  return (*m_method_TurnOffAlert)(flashAlertType);

}
int32_t com_jci_xmadProxy::AbortFlashAlert(uint32_t flashEventID, uint32_t flashAlertType) {
  return (*m_method_AbortFlashAlert)(flashEventID, flashAlertType);

}
int32_t com_jci_xmadProxy::ReplayFlashAlert(uint32_t flashEventID, uint32_t flashAlertType) {
  return (*m_method_ReplayFlashAlert)(flashEventID, flashAlertType);

}
int32_t com_jci_xmadProxy::TWReportFirstTimeUsed() {
  return (*m_method_TWReportFirstTimeUsed)();

}
int32_t com_jci_xmadProxy::SetTWReportFrequency(uint32_t twReportFreq) {
  return (*m_method_SetTWReportFrequency)(twReportFreq);

}
int32_t com_jci_xmadProxy::EnableTWReportAlert(bool enableTWReportAlert) {
  return (*m_method_EnableTWReportAlert)(enableTWReportAlert);

}
int32_t com_jci_xmadProxy::SelectTWCity(std::string selectTWCity, bool isNearestCity) {
  return (*m_method_SelectTWCity)(selectTWCity, isNearestCity);

}
int32_t com_jci_xmadProxy::SuspendAlertContextStatus(bool suspendAlertContextRemoved) {
  return (*m_method_SuspendAlertContextStatus)(suspendAlertContextRemoved);

}
int32_t com_jci_xmadProxy::isValidChannelID(uint32_t channelID) {
  return (*m_method_isValidChannelID)(channelID);

}
int32_t com_jci_xmadProxy::PlayFirstTuneMix() {
  return (*m_method_PlayFirstTuneMix)();

}
int32_t com_jci_xmadProxy::GetFlashAvailableStatus(uint32_t flashAlertType) {
  return (*m_method_GetFlashAvailableStatus)(flashAlertType);

}
int32_t com_jci_xmadProxy::SubscriptionUserAccept() {
  return (*m_method_SubscriptionUserAccept)();

}
int32_t com_jci_xmadProxy::PlayTuneGame(uint32_t id_h, uint32_t id_m, uint32_t id_l, bool tuneToServiceID) {
  return (*m_method_PlayTuneGame)(id_h, id_m, id_l, tuneToServiceID);

}
int32_t com_jci_xmadProxy::SubscriptionUpdateConf(bool status) {
  return (*m_method_SubscriptionUpdateConf)(status);

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmadProxy::signal_SourceChangeStatus() {
  return m_signalproxy_SourceChangeStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t, uint32_t > )>> com_jci_xmadProxy::signal_TuneStatus() {
  return m_signalproxy_TuneStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmadProxy::signal_installStatus() {
  return m_signalproxy_installStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmadProxy::signal_SignalQuality() {
  return m_signalproxy_SignalQuality;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmadProxy::signal_AntennaState() {
  return m_signalproxy_AntennaState;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_xmadProxy::signal_ChannelDescriptionServiceStatus() {
  return m_signalproxy_ChannelDescriptionServiceStatus;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_xmadProxy::signal_TuneStartSettingStatus() {
  return m_signalproxy_TuneStartSettingStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmadProxy::signal_LockPinStatus() {
  return m_signalproxy_LockPinStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t,
                                        std::vector < uint8_t > ,
                                        uint32_t > )>> com_jci_xmadProxy::signal_CurrentTunedChannel() {
  return m_signalproxy_CurrentTunedChannel;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        bool,
                                        uint32_t,
                                        uint32_t,
                                        uint32_t > )>> com_jci_xmadProxy::signal_ChannelStatus() {
  return m_signalproxy_ChannelStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t,
                                        uint32_t,
                                        uint32_t,
                                        uint32_t > )>> com_jci_xmadProxy::signal_ActiveCategory() {
  return m_signalproxy_ActiveCategory;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t, uint32_t > )>> com_jci_xmadProxy::signal_ScanStatus() {
  return m_signalproxy_ScanStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmadProxy::signal_ScanReqStatus() {
  return m_signalproxy_ScanReqStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmadProxy::signal_ScanSettingStatus() {
  return m_signalproxy_ScanSettingStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t > )>> com_jci_xmadProxy::signal_DirectTuneStatus() {
  return m_signalproxy_DirectTuneStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        uint32_t,
                                        uint32_t,
                                        bool,
                                        std::tuple < bool,
                                        bool,
                                        bool,
                                        bool > )>> com_jci_xmadProxy::signal_ChannelListUpdateStatus() {
  return m_signalproxy_ChannelListUpdateStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::string,
                                        std::tuple < bool,
                                        bool,
                                        bool > )>> com_jci_xmadProxy::signal_CategoryUpdate() {
  return m_signalproxy_CategoryUpdate;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmadProxy::signal_RequestPin() {
  return m_signalproxy_RequestPin;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmadProxy::signal_RequestPinStatus() {
  return m_signalproxy_RequestPinStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmadProxy::signal_ChannelLockStatus() {
  return m_signalproxy_ChannelLockStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmadProxy::signal_SessionLockStatus() {
  return m_signalproxy_SessionLockStatus;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_xmadProxy::signal_ParentalLockInitSetupStatus() {
  return m_signalproxy_ParentalLockInitSetupStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t, uint32_t > )>> com_jci_xmadProxy::signal_SeekStatus() {
  return m_signalproxy_SeekStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, bool, uint32_t)>> com_jci_xmadProxy::signal_EditSmartFavListStatus() {
  return m_signalproxy_EditSmartFavListStatus;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_xmadProxy::signal_NotifyFirstXMFavAddition() {
  return m_signalproxy_NotifyFirstXMFavAddition;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmadProxy::signal_NotifyFavListID() {
  return m_signalproxy_NotifyFavListID;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_xmadProxy::signal_TuneScanSettingFirstTimeUsage() {
  return m_signalproxy_TuneScanSettingFirstTimeUsage;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_xmadProxy::signal_TuneScanContentAvailabilityStatus() {
  return m_signalproxy_TuneScanContentAvailabilityStatus;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_xmadProxy::signal_BTConnectionStatus() {
  return m_signalproxy_BTConnectionStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint8_t,
                                        uint32_t,
                                        std::vector < uint8_t > ,
                                        std::vector < uint8_t >> )>> com_jci_xmadProxy::signal_SubscriptionStatus() {
  return m_signalproxy_SubscriptionStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t > )>> com_jci_xmadProxy::signal_IRBufferCapacityStatus() {
  return m_signalproxy_IRBufferCapacityStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmadProxy::signal_PlayControlStatus() {
  return m_signalproxy_PlayControlStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t > )>> com_jci_xmadProxy::signal_PlayBackStatus() {
  return m_signalproxy_PlayBackStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t,
                                        uint32_t > )>> com_jci_xmadProxy::signal_PlaybackTimeStatus() {
  return m_signalproxy_PlaybackTimeStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmadProxy::signal_SeekTimeStatus() {
  return m_signalproxy_SeekTimeStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmadProxy::signal_PlaybackOffsetIndication() {
  return m_signalproxy_PlaybackOffsetIndication;

}
std::shared_ptr <DBus::SignalProxy<void(std::string)>> com_jci_xmadProxy::signal_ESNInfo() {
  return m_signalproxy_ESNInfo;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t > )>> com_jci_xmadProxy::signal_TracksBeforeAfter() {
  return m_signalproxy_TracksBeforeAfter;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < bool,
                                        uint32_t,
                                        std::vector < uint8_t >> )>> com_jci_xmadProxy::signal_TuneMixActive() {
  return m_signalproxy_TuneMixActive;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t > )>> com_jci_xmadProxy::signal_PlaybackTrackTimeStatus() {
  return m_signalproxy_PlaybackTrackTimeStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < std::vector < uint8_t > ,
                                        uint32_t,
                                        uint32_t,
                                        uint32_t > )>> com_jci_xmadProxy::signal_CreateTuneMixStatus() {
  return m_signalproxy_CreateTuneMixStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < std::vector < uint8_t > ,
                                        uint32_t,
                                        uint32_t,
                                        uint32_t > )>> com_jci_xmadProxy::signal_EditTuneMixStatus() {
  return m_signalproxy_EditTuneMixStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < std::string,
                                        uint32_t > )>> com_jci_xmadProxy::signal_RenameTunemixStatus() {
  return m_signalproxy_RenameTunemixStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t > )>> com_jci_xmadProxy::signal_RemoveTuneMixStatus() {
  return m_signalproxy_RemoveTuneMixStatus;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_xmadProxy::signal_TuneStartFirstTimeUsageStatus() {
  return m_signalproxy_TuneStartFirstTimeUsageStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmadProxy::signal_SmartFavChannelsCount() {
  return m_signalproxy_SmartFavChannelsCount;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmadProxy::signal_TuneMixCount() {
  return m_signalproxy_TuneMixCount;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        std::vector < std::tuple < uint32_t,
                                        std::string,
                                        bool>>>)>>
com_jci_xmadProxy::signal_TuneMixDetails() {
  return m_signalproxy_TuneMixDetails;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmadProxy::signal_TuneMixListUpdated() {
  return m_signalproxy_TuneMixListUpdated;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t,
                                        uint32_t,
                                        uint32_t > )>> com_jci_xmadProxy::signal_TuneFeaturedFavStatus() {
  return m_signalproxy_TuneFeaturedFavStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        std::vector < uint8_t > ,
                                        std::tuple < bool,
                                        bool,
                                        bool >> )>> com_jci_xmadProxy::signal_FeaturedFavListUpdated() {
  return m_signalproxy_FeaturedFavListUpdated;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < bool,
                                        uint32_t > )>> com_jci_xmadProxy::signal_SportFlashActiveStatus() {
  return m_signalproxy_SportFlashActiveStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmadProxy::signal_SportFlashFrequencyStatus() {
  return m_signalproxy_SportFlashFrequencyStatus;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_xmadProxy::signal_SportFlashFirstTimeUsageStatus() {
  return m_signalproxy_SportFlashFirstTimeUsageStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmadProxy::signal_EnableSportFlashAlertStatus() {
  return m_signalproxy_EnableSportFlashAlertStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmadProxy::signal_SelectSportsFlashTeamStatus() {
  return m_signalproxy_SelectSportsFlashTeamStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmadProxy::signal_MoveSportsFlashTeamStatus() {
  return m_signalproxy_MoveSportsFlashTeamStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t,
                                        uint32_t,
                                        std::vector < uint8_t > ,
                                        std::vector < uint8_t > ,
                                        std::vector < uint8_t > ,
                                        uint32_t > )>> com_jci_xmadProxy::signal_SportFlashAlert() {
  return m_signalproxy_SportFlashAlert;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t,
                                        uint32_t > )>> com_jci_xmadProxy::signal_CancelAlert() {
  return m_signalproxy_CancelAlert;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t > )>> com_jci_xmadProxy::signal_PlayFlashAlertStatus() {
  return m_signalproxy_PlayFlashAlertStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < bool,
                                        uint32_t,
                                        uint32_t > )>> com_jci_xmadProxy::signal_AbortFlashAlertStatus() {
  return m_signalproxy_AbortFlashAlertStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t > )>> com_jci_xmadProxy::signal_TurnOffAlertStatus() {
  return m_signalproxy_TurnOffAlertStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t > )>> com_jci_xmadProxy::signal_ReplayFlashAlertStatus() {
  return m_signalproxy_ReplayFlashAlertStatus;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_xmadProxy::signal_TWFlashActiveStatus() {
  return m_signalproxy_TWFlashActiveStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmadProxy::signal_TWFlashFrequencyStatus() {
  return m_signalproxy_TWFlashFrequencyStatus;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_xmadProxy::signal_TWFirstTimeUsageStatus() {
  return m_signalproxy_TWFirstTimeUsageStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmadProxy::signal_EnableTWReportAlertStatus() {
  return m_signalproxy_EnableTWReportAlertStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmadProxy::signal_SelectTWCityStatus() {
  return m_signalproxy_SelectTWCityStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < std::vector < uint8_t > ,
                                        bool,
                                        uint32_t,
                                        uint32_t > )>> com_jci_xmadProxy::signal_TWCityNameCityID() {
  return m_signalproxy_TWCityNameCityID;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t,
                                        std::vector < uint8_t > ,
                                        uint32_t > )>> com_jci_xmadProxy::signal_TWFlashAlert() {
  return m_signalproxy_TWFlashAlert;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        bool,
                                        std::vector < uint8_t >> )>> com_jci_xmadProxy::signal_FAVChannelsubscribed() {
  return m_signalproxy_FAVChannelsubscribed;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_xmadProxy::signal_FavSportTeamCount() {
  return m_signalproxy_FavSportTeamCount;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t > )>> com_jci_xmadProxy::signal_ChannelValidityStatus() {
  return m_signalproxy_ChannelValidityStatus;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_xmadProxy::signal_UnlockSession() {
  return m_signalproxy_UnlockSession;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_xmadProxy::signal_SubscriptionUpdated() {
  return m_signalproxy_SubscriptionUpdated;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t,
                                        uint32_t,
                                        uint32_t,
                                        std::vector < uint8_t > ,
                                        std::vector < uint8_t > ,
                                        std::vector < uint8_t >> )>> com_jci_xmadProxy::signal_FlashAvailableStatus() {
  return m_signalproxy_FlashAvailableStatus;

}
