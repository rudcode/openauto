#ifndef COM_JCI_XMADPROXY_H
#define COM_JCI_XMADPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_xmadProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_xmadProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_xmadProxy> create(std::string name = "com.jci.xmad");
  int32_t GetScanSetting();
  int32_t GetInstallStatus();
  int32_t GetSignalQuality();
  int32_t GetAntennaState();
  int32_t GetFirstXMFavAddition();
  int32_t GetTuneStartSettingStatus();
  int32_t GetFavListID();
  int32_t GetActiveCategory();
  int32_t GetSessionLockStatus();
  int32_t GetParentalLockInitSetupStatus();
  int32_t GetIsTuneScanSettingUsedBefore();
  int32_t GetTuneScanContentAvailabilityInfo();
  int32_t GetBTConnectionStatus();
  int32_t GetIRBufferCapacity();
  int32_t GetESN();
  int32_t GetSmartFavChannelsCount();
  int32_t GetTuneMixActiveStatus();
  int32_t GetTuneMixCount();
  int32_t GetTuneStartFirstTimeUsage();
  int32_t GetTuneMixDetails(uint32_t tunemix_Id);
  int32_t GetSportFlashActiveStatus();
  int32_t GetSportFlashFreq();
  int32_t GetSportFlashFirstTimeUsage();
  int32_t GetTWReportActiveStatus();
  int32_t GetTWReportFreq();
  int32_t GetTWReportFirstTimeUsage();
  int32_t GetNearestCityName();
  int32_t GetSubscriptionUpdateStatus();
  int32_t SourceChangeToXM();
  int32_t Seek(uint32_t seek_type);
  int32_t DirectTune(uint32_t id, bool tuneToServiceID);
  int32_t ChangeCategory(uint32_t ch_list_type, uint32_t category_id);
  int32_t ScanSetting(uint32_t scan_type);
  int32_t ScanReq(std::tuple<uint32_t, uint32_t> scan_req);
  int32_t TuneStartSetting(bool tune_start_enable);
  int32_t EditSmartFavList(uint32_t chanID, bool isSFChannel);
  int32_t SessionLock(std::tuple<uint32_t, bool> session_lock_req);
  int32_t ChannelLock(std::tuple<uint32_t, uint32_t> channel_lock_req);
  int32_t RequestPinResponse(std::tuple<uint32_t, std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>> pin_info);
  int32_t ChangePinReq(uint32_t pin_type);
  int32_t PlayControl(uint32_t playControl);
  int32_t SeekTime(int32_t durationInSec);
  int32_t SeekTrack(uint32_t direction);
  int32_t CreateTuneMix(std::tuple<std::vector<std::tuple<uint32_t, std::string, bool>>> create_tunemix_req);
  int32_t EditTuneMix(std::tuple<uint32_t, std::vector<std::tuple<uint32_t, std::string, bool>>> edit_tunemix_req);
  int32_t RenameTuneMix(std::tuple<uint32_t, std::string> rename_tunemix_req);
  int32_t RemoveTuneMix(uint32_t tunemix_id);
  int32_t TuneStartUsed();
  int32_t FirstFavoriteAdded();
  int32_t TuneScanUsed();
  int32_t ExitTuneMix();
  int32_t TuneFeaturedFav(std::tuple<uint32_t, uint32_t> tune_featured_fav);
  int32_t SportFlashFirstTimeUsed();
  int32_t SetSportsFlashFrequency(uint32_t flashFreq);
  int32_t EnableSportFlashAlert(bool enableAlert);
  int32_t SelectSportsFlashTeam(uint32_t leagueId, uint32_t teamId, bool favorite);
  int32_t MoveSportsFlashTeam(uint32_t refLeagueID,
                              uint32_t leagueID,
                              uint32_t refTeamId,
                              uint32_t teamId,
                              uint32_t moveType);
  int32_t DismissFlashAlert(uint32_t channelID, uint32_t flashEventID, uint32_t flashAlertType);
  int32_t PlayFlashAlert(uint32_t flashEventID, uint32_t flashAlertType);
  int32_t TurnOffAlert(uint32_t flashAlertType);
  int32_t AbortFlashAlert(uint32_t flashEventID, uint32_t flashAlertType);
  int32_t ReplayFlashAlert(uint32_t flashEventID, uint32_t flashAlertType);
  int32_t TWReportFirstTimeUsed();
  int32_t SetTWReportFrequency(uint32_t twReportFreq);
  int32_t EnableTWReportAlert(bool enableTWReportAlert);
  int32_t SelectTWCity(std::string selectTWCity, bool isNearestCity);
  int32_t SuspendAlertContextStatus(bool suspendAlertContextRemoved);
  int32_t isValidChannelID(uint32_t channelID);
  int32_t PlayFirstTuneMix();
  int32_t GetFlashAvailableStatus(uint32_t flashAlertType);
  int32_t SubscriptionUserAccept();
  int32_t PlayTuneGame(uint32_t id_h, uint32_t id_m, uint32_t id_l, bool tuneToServiceID);
  int32_t SubscriptionUpdateConf(bool status);
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_SourceChangeStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> signal_TuneStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_installStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_SignalQuality();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_AntennaState();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_ChannelDescriptionServiceStatus();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_TuneStartSettingStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_LockPinStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t,
                                                    uint32_t,
                                                    std::vector<uint8_t>,
                                                    uint32_t>)>> signal_CurrentTunedChannel();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t,
                                                    bool,
                                                    uint32_t,
                                                    uint32_t,
                                                    uint32_t>)>> signal_ChannelStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t,
                                                    uint32_t,
                                                    uint32_t,
                                                    uint32_t,
                                                    uint32_t>)>> signal_ActiveCategory();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> signal_ScanStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_ScanReqStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_ScanSettingStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> signal_DirectTuneStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         uint32_t,
                                         uint32_t,
                                         bool,
                                         std::tuple<bool, bool, bool, bool>)>> signal_ChannelListUpdateStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::string, std::tuple<bool, bool, bool>)>> signal_CategoryUpdate();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_RequestPin();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_RequestPinStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_ChannelLockStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_SessionLockStatus();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_ParentalLockInitSetupStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> signal_SeekStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, bool, uint32_t)>> signal_EditSmartFavListStatus();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_NotifyFirstXMFavAddition();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_NotifyFavListID();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_TuneScanSettingFirstTimeUsage();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_TuneScanContentAvailabilityStatus();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_BTConnectionStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t,
                                                    uint8_t,
                                                    uint32_t,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>>)>> signal_SubscriptionStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> signal_IRBufferCapacityStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_PlayControlStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> signal_PlayBackStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t, uint32_t>)>> signal_PlaybackTimeStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_SeekTimeStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_PlaybackOffsetIndication();
  std::shared_ptr<DBus::SignalProxy<void(std::string)>> signal_ESNInfo();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> signal_TracksBeforeAfter();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<bool, uint32_t, std::vector<uint8_t>>)>> signal_TuneMixActive();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> signal_PlaybackTrackTimeStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>,
                                                    uint32_t,
                                                    uint32_t,
                                                    uint32_t>)>> signal_CreateTuneMixStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>,
                                                    uint32_t,
                                                    uint32_t,
                                                    uint32_t>)>> signal_EditTuneMixStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::string, uint32_t>)>> signal_RenameTunemixStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> signal_RemoveTuneMixStatus();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_TuneStartFirstTimeUsageStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_SmartFavChannelsCount();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_TuneMixCount();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t,
                                                    std::vector<std::tuple<uint32_t,
                                                                           std::string,
                                                                           bool>>>)>> signal_TuneMixDetails();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_TuneMixListUpdated();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t,
                                                    uint32_t,
                                                    uint32_t,
                                                    uint32_t>)>> signal_TuneFeaturedFavStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t,
                                                    std::vector<uint8_t>,
                                                    std::tuple<bool, bool, bool>>)>> signal_FeaturedFavListUpdated();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<bool, uint32_t>)>> signal_SportFlashActiveStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_SportFlashFrequencyStatus();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_SportFlashFirstTimeUsageStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_EnableSportFlashAlertStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_SelectSportsFlashTeamStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_MoveSportsFlashTeamStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t,
                                                    uint32_t,
                                                    uint32_t,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    uint32_t>)>> signal_SportFlashAlert();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t, uint32_t>)>> signal_CancelAlert();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> signal_PlayFlashAlertStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<bool, uint32_t, uint32_t>)>> signal_AbortFlashAlertStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> signal_TurnOffAlertStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> signal_ReplayFlashAlertStatus();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_TWFlashActiveStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_TWFlashFrequencyStatus();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_TWFirstTimeUsageStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_EnableTWReportAlertStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_SelectTWCityStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>,
                                                    bool,
                                                    uint32_t,
                                                    uint32_t>)>> signal_TWCityNameCityID();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t,
                                                    uint32_t,
                                                    std::vector<uint8_t>,
                                                    uint32_t>)>> signal_TWFlashAlert();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t,
                                                    bool,
                                                    std::vector<uint8_t>>)>> signal_FAVChannelsubscribed();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_FavSportTeamCount();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> signal_ChannelValidityStatus();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_UnlockSession();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_SubscriptionUpdated();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t,
                                                    uint32_t,
                                                    uint32_t,
                                                    uint32_t,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>>)>> signal_FlashAvailableStatus();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetScanSetting;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetInstallStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetSignalQuality;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetAntennaState;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetFirstXMFavAddition;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetTuneStartSettingStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetFavListID;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetActiveCategory;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetSessionLockStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetParentalLockInitSetupStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetIsTuneScanSettingUsedBefore;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetTuneScanContentAvailabilityInfo;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetBTConnectionStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetIRBufferCapacity;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetESN;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetSmartFavChannelsCount;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetTuneMixActiveStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetTuneMixCount;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetTuneStartFirstTimeUsage;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_GetTuneMixDetails;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetSportFlashActiveStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetSportFlashFreq;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetSportFlashFirstTimeUsage;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetTWReportActiveStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetTWReportFreq;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetTWReportFirstTimeUsage;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetNearestCityName;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetSubscriptionUpdateStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_SourceChangeToXM;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_Seek;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, bool)>> m_method_DirectTune;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t)>> m_method_ChangeCategory;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_ScanSetting;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::tuple<uint32_t, uint32_t>)>> m_method_ScanReq;
  std::shared_ptr<DBus::MethodProxy<int32_t(bool)>> m_method_TuneStartSetting;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, bool)>> m_method_EditSmartFavList;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::tuple<uint32_t, bool>)>> m_method_SessionLock;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::tuple<uint32_t, uint32_t>)>> m_method_ChannelLock;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::tuple<uint32_t, std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>>)>>
      m_method_RequestPinResponse;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_ChangePinReq;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_PlayControl;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_SeekTime;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_SeekTrack;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::tuple<std::vector<std::tuple<uint32_t, std::string, bool>>>)>>
      m_method_CreateTuneMix;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::tuple<uint32_t,
                                                       std::vector<std::tuple<uint32_t, std::string, bool>>>)>>
      m_method_EditTuneMix;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::tuple<uint32_t, std::string>)>> m_method_RenameTuneMix;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_RemoveTuneMix;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_TuneStartUsed;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_FirstFavoriteAdded;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_TuneScanUsed;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_ExitTuneMix;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::tuple<uint32_t, uint32_t>)>> m_method_TuneFeaturedFav;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_SportFlashFirstTimeUsed;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_SetSportsFlashFrequency;
  std::shared_ptr<DBus::MethodProxy<int32_t(bool)>> m_method_EnableSportFlashAlert;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t, bool)>> m_method_SelectSportsFlashTeam;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t)>>
      m_method_MoveSportsFlashTeam;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t, uint32_t)>> m_method_DismissFlashAlert;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t)>> m_method_PlayFlashAlert;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_TurnOffAlert;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t)>> m_method_AbortFlashAlert;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t)>> m_method_ReplayFlashAlert;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_TWReportFirstTimeUsed;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_SetTWReportFrequency;
  std::shared_ptr<DBus::MethodProxy<int32_t(bool)>> m_method_EnableTWReportAlert;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::string, bool)>> m_method_SelectTWCity;
  std::shared_ptr<DBus::MethodProxy<int32_t(bool)>> m_method_SuspendAlertContextStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_isValidChannelID;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_PlayFirstTuneMix;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_GetFlashAvailableStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_SubscriptionUserAccept;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t, uint32_t, bool)>> m_method_PlayTuneGame;
  std::shared_ptr<DBus::MethodProxy<int32_t(bool)>> m_method_SubscriptionUpdateConf;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_SourceChangeStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> m_signalproxy_TuneStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_installStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_SignalQuality;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_AntennaState;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_ChannelDescriptionServiceStatus;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_TuneStartSettingStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_LockPinStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t, std::vector<uint8_t>, uint32_t>)>>
      m_signalproxy_CurrentTunedChannel;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, bool, uint32_t, uint32_t, uint32_t>)>>
      m_signalproxy_ChannelStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t, uint32_t, uint32_t, uint32_t>)>>
      m_signalproxy_ActiveCategory;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> m_signalproxy_ScanStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_ScanReqStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_ScanSettingStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> m_signalproxy_DirectTuneStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t, uint32_t, bool, std::tuple<bool, bool, bool, bool>)>>
      m_signalproxy_ChannelListUpdateStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::string, std::tuple<bool, bool, bool>)>>
      m_signalproxy_CategoryUpdate;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_RequestPin;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_RequestPinStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_ChannelLockStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_SessionLockStatus;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_ParentalLockInitSetupStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> m_signalproxy_SeekStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, bool, uint32_t)>> m_signalproxy_EditSmartFavListStatus;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_NotifyFirstXMFavAddition;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_NotifyFavListID;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_TuneScanSettingFirstTimeUsage;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_TuneScanContentAvailabilityStatus;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_BTConnectionStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t,
                                                    uint8_t,
                                                    uint32_t,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>>)>> m_signalproxy_SubscriptionStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> m_signalproxy_IRBufferCapacityStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_PlayControlStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> m_signalproxy_PlayBackStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t, uint32_t>)>> m_signalproxy_PlaybackTimeStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_SeekTimeStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_PlaybackOffsetIndication;
  std::shared_ptr<DBus::SignalProxy<void(std::string)>> m_signalproxy_ESNInfo;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> m_signalproxy_TracksBeforeAfter;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<bool, uint32_t, std::vector<uint8_t>>)>>
      m_signalproxy_TuneMixActive;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> m_signalproxy_PlaybackTrackTimeStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>, uint32_t, uint32_t, uint32_t>)>>
      m_signalproxy_CreateTuneMixStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>, uint32_t, uint32_t, uint32_t>)>>
      m_signalproxy_EditTuneMixStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::string, uint32_t>)>> m_signalproxy_RenameTunemixStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> m_signalproxy_RemoveTuneMixStatus;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_TuneStartFirstTimeUsageStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_SmartFavChannelsCount;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_TuneMixCount;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, std::vector<std::tuple<uint32_t, std::string, bool>>>)>>
      m_signalproxy_TuneMixDetails;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_TuneMixListUpdated;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t, uint32_t, uint32_t>)>>
      m_signalproxy_TuneFeaturedFavStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, std::vector<uint8_t>, std::tuple<bool, bool, bool>>)>>
      m_signalproxy_FeaturedFavListUpdated;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<bool, uint32_t>)>> m_signalproxy_SportFlashActiveStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_SportFlashFrequencyStatus;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_SportFlashFirstTimeUsageStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_EnableSportFlashAlertStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_SelectSportsFlashTeamStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_MoveSportsFlashTeamStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t,
                                                    uint32_t,
                                                    uint32_t,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    uint32_t>)>> m_signalproxy_SportFlashAlert;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t, uint32_t>)>> m_signalproxy_CancelAlert;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> m_signalproxy_PlayFlashAlertStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<bool, uint32_t, uint32_t>)>> m_signalproxy_AbortFlashAlertStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> m_signalproxy_TurnOffAlertStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> m_signalproxy_ReplayFlashAlertStatus;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_TWFlashActiveStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_TWFlashFrequencyStatus;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_TWFirstTimeUsageStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_EnableTWReportAlertStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_SelectTWCityStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>, bool, uint32_t, uint32_t>)>>
      m_signalproxy_TWCityNameCityID;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t, std::vector<uint8_t>, uint32_t>)>>
      m_signalproxy_TWFlashAlert;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, bool, std::vector<uint8_t>>)>>
      m_signalproxy_FAVChannelsubscribed;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_FavSportTeamCount;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> m_signalproxy_ChannelValidityStatus;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_UnlockSession;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_SubscriptionUpdated;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t,
                                                    uint32_t,
                                                    uint32_t,
                                                    uint32_t,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>>)>> m_signalproxy_FlashAvailableStatus;
};
#endif /* COM_JCI_XMADPROXY_H */
