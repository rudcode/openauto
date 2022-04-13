#include "com_jci_usbmsProxy.h"

com_jci_usbmsProxy::com_jci_usbmsProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_BrowseContext = this->create_method < std::tuple < uint32_t, std::vector < std::tuple
      < std::string, uint32_t, int32_t >>, uint32_t > (Invalid) > ("BrowseContext");
  m_method_GetBrowseFolderInfo =
      this->create_method<std::tuple<uint32_t, std::string, std::string, uint32_t>(Invalid)>("GetBrowseFolderInfo");
  m_method_PauseResume = this->create_method<std::tuple<uint32_t>(std::tuple < uint32_t > )>("PauseResume");
  m_method_PlayResume = this->create_method<Invalid(std::tuple < uint32_t, int32_t > )>("PlayResume");
  m_method_PlayContext = this->create_method<Invalid(Invalid)>("PlayContext");
  m_method_StopPlayback = this->create_method<std::tuple<uint32_t>(std::tuple < uint32_t > )>("StopPlayback");
  m_method_GetAlbumArt = this->create_method<std::tuple<std::string, uint32_t, uint32_t>(std::tuple < uint32_t,
                                                                                         uint32_t > )>("GetAlbumArt");
  m_method_PlayerSeek =
      this->create_method<std::tuple<int32_t>(std::tuple < uint32_t, int32_t, uint32_t > )>("PlayerSeek");
  m_method_PlayTrackControl =
      this->create_method<std::tuple<int32_t>(std::tuple < uint32_t, int32_t, uint32_t > )>("PlayTrackControl");
  m_method_SetPlayerSettings =
      this->create_method<std::tuple<int32_t>(std::tuple < uint32_t, int32_t, int32_t > )>("SetPlayerSettings");
  m_method_GetStorageDevicesList = this->create_method<Invalid()>("GetStorageDevicesList");
  m_method_GetPlayTrackInfo = this->create_method<Invalid()>("GetPlayTrackInfo");
  m_method_MoreLikeThis = this->create_method<Invalid(std::tuple < uint32_t > )>("MoreLikeThis");
  m_method_GetSongsInfoList =
      this->create_method<Invalid(std::tuple < uint32_t, uint32_t, uint32_t > )>("GetSongsInfoList");
  m_method_SetLanguage = this->create_method<std::tuple<int32_t>(std::tuple < uint32_t > )>("SetLanguage");
  m_method_GetAlphabet = this->create_method < std::tuple < std::vector < std::tuple < uint32_t, int32_t, std::string>>>
  (std::tuple < uint32_t, std::tuple < std::vector < std::tuple < int32_t, uint32_t, uint32_t, uint32_t, int32_t >> >>)
      > ("GetAlphabet");
  m_method_GetTaggingInfo =
      this->create_method<std::tuple<uint64_t, uint64_t, uint32_t, uint16_t, uint8_t, uint8_t, uint32_t>(
          std::tuple < uint32_t > )>("GetTaggingInfo");
  m_method_iPodSendTag = this->create_method<std::tuple<uint32_t>(Invalid)>("iPodSendTag");
  m_method_SaveData = this->create_method<std::tuple<int32_t>()>("SaveData");
  m_signalproxy_StorageAttached = this->create_signal<void(Invalid)>("StorageAttached");
  m_signalproxy_StorageDetached = this->create_signal<void(std::tuple < uint32_t > )>("StorageDetached");
  m_signalproxy_SyncEvent =
      this->create_signal<void(std::tuple < uint32_t, int32_t, int32_t, uint32_t, uint32_t > )>("SyncEvent");
  m_signalproxy_DbUpdate = this->create_signal<void(std::tuple < uint32_t, int32_t, uint32_t > )>("DbUpdate");
  m_signalproxy_TrackChanged = this->create_signal<void(Invalid)>("TrackChanged");
  m_signalproxy_PlayComplete = this->create_signal<void(std::tuple < int32_t > )>("PlayComplete");
  m_signalproxy_PlaybackTime = this->create_signal<void(std::tuple < uint32_t, uint32_t > )>("PlaybackTime");
  m_signalproxy_DeviceError = this->create_signal<void(std::tuple < uint32_t, int32_t > )>("DeviceError");
  m_signalproxy_PlayerStateChanged = this->create_signal<void(Invalid)>("PlayerStateChanged");
  m_signalproxy_PlaybackSettingsChanged =
      this->create_signal<void(std::tuple < uint32_t, int32_t, int32_t > )>("PlaybackSettingsChanged");
  m_signalproxy_AlbumArtReady = this->create_signal<void(std::tuple < uint32_t > )>("AlbumArtReady");
  m_signalproxy_Ping = this->create_signal<void()>("Ping");

}
std::shared_ptr <com_jci_usbmsProxy> com_jci_usbmsProxy::create(std::string name) {
  return std::shared_ptr<com_jci_usbmsProxy>(new com_jci_usbmsProxy(name));

}
std::tuple <uint32_t, std::vector<std::tuple < std::string, uint32_t, int32_t>>,uint32_t>
com_jci_usbmsProxy::BrowseContext(Invalid
browseContext ){
return (*m_method_BrowseContext)(browseContext);

}
std::tuple <uint32_t, std::string, std::string, uint32_t> com_jci_usbmsProxy::GetBrowseFolderInfo(Invalid
getBrowseFolderInfo ){
return (*m_method_GetBrowseFolderInfo)(getBrowseFolderInfo);

}
std::tuple <uint32_t> com_jci_usbmsProxy::PauseResume(std::tuple <uint32_t> pauseResume) {
  return (*m_method_PauseResume)(pauseResume);

}
Invalid com_jci_usbmsProxy::PlayResume(std::tuple <uint32_t, int32_t> playResume) {
  return (*m_method_PlayResume)(playResume);

}
Invalid com_jci_usbmsProxy::PlayContext(Invalid
playContext ){
return (*m_method_PlayContext)(playContext);

}
std::tuple <uint32_t> com_jci_usbmsProxy::StopPlayback(std::tuple <uint32_t> stopPlayback) {
  return (*m_method_StopPlayback)(stopPlayback);

}
std::tuple <std::string, uint32_t, uint32_t> com_jci_usbmsProxy::GetAlbumArt(std::tuple <uint32_t, uint32_t> getAlbumArt) {
  return (*m_method_GetAlbumArt)(getAlbumArt);

}
std::tuple <int32_t> com_jci_usbmsProxy::PlayerSeek(std::tuple <uint32_t, int32_t, uint32_t> playerSeek) {
  return (*m_method_PlayerSeek)(playerSeek);

}
std::tuple <int32_t> com_jci_usbmsProxy::PlayTrackControl(std::tuple <uint32_t, int32_t, uint32_t> playTrackCtrl) {
  return (*m_method_PlayTrackControl)(playTrackCtrl);

}
std::tuple <int32_t> com_jci_usbmsProxy::SetPlayerSettings(std::tuple <uint32_t, int32_t, int32_t> setPlayerSettings) {
  return (*m_method_SetPlayerSettings)(setPlayerSettings);

}
Invalid com_jci_usbmsProxy::GetStorageDevicesList() {
  return (*m_method_GetStorageDevicesList)();

}
Invalid com_jci_usbmsProxy::GetPlayTrackInfo() {
  return (*m_method_GetPlayTrackInfo)();

}
Invalid com_jci_usbmsProxy::MoreLikeThis(std::tuple <uint32_t> moreLikeThis) {
  return (*m_method_MoreLikeThis)(moreLikeThis);

}
Invalid com_jci_usbmsProxy::GetSongsInfoList(std::tuple <uint32_t, uint32_t, uint32_t> getSongsInfoList) {
  return (*m_method_GetSongsInfoList)(getSongsInfoList);

}
std::tuple <int32_t> com_jci_usbmsProxy::SetLanguage(std::tuple <uint32_t> setLanguage) {
  return (*m_method_SetLanguage)(setLanguage);

}
std::tuple <std::vector<std::tuple < uint32_t, int32_t, std::string>>>
com_jci_usbmsProxy::GetAlphabet
(std::tuple<uint32_t, std::tuple < std::vector < std::tuple < int32_t, uint32_t, uint32_t, uint32_t, int32_t>>
>> getAlphabet ){
return (*m_method_GetAlphabet)(getAlphabet);

}
std::tuple <uint64_t, uint64_t, uint32_t, uint16_t, uint8_t, uint8_t, uint32_t> com_jci_usbmsProxy::GetTaggingInfo(std::tuple <uint32_t> getTaggingInfo) {
  return (*m_method_GetTaggingInfo)(getTaggingInfo);

}
std::tuple <uint32_t> com_jci_usbmsProxy::iPodSendTag(Invalid
iPodSendTag ){
return (*m_method_iPodSendTag)(iPodSendTag);

}
std::tuple <int32_t> com_jci_usbmsProxy::SaveData() {
  return (*m_method_SaveData)();

}
std::shared_ptr <DBus::SignalProxy<void(Invalid)>> com_jci_usbmsProxy::signal_StorageAttached() {
  return m_signalproxy_StorageAttached;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t > )>> com_jci_usbmsProxy::signal_StorageDetached() {
  return m_signalproxy_StorageDetached;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        int32_t,
                                        int32_t,
                                        uint32_t,
                                        uint32_t > )>> com_jci_usbmsProxy::signal_SyncEvent() {
  return m_signalproxy_SyncEvent;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        int32_t,
                                        uint32_t > )>> com_jci_usbmsProxy::signal_DbUpdate() {
  return m_signalproxy_DbUpdate;

}
std::shared_ptr <DBus::SignalProxy<void(Invalid)>> com_jci_usbmsProxy::signal_TrackChanged() {
  return m_signalproxy_TrackChanged;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < int32_t > )>> com_jci_usbmsProxy::signal_PlayComplete() {
  return m_signalproxy_PlayComplete;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t > )>> com_jci_usbmsProxy::signal_PlaybackTime() {
  return m_signalproxy_PlaybackTime;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t, int32_t > )>> com_jci_usbmsProxy::signal_DeviceError() {
  return m_signalproxy_DeviceError;

}
std::shared_ptr <DBus::SignalProxy<void(Invalid)>> com_jci_usbmsProxy::signal_PlayerStateChanged() {
  return m_signalproxy_PlayerStateChanged;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        int32_t,
                                        int32_t > )>> com_jci_usbmsProxy::signal_PlaybackSettingsChanged() {
  return m_signalproxy_PlaybackSettingsChanged;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t > )>> com_jci_usbmsProxy::signal_AlbumArtReady() {
  return m_signalproxy_AlbumArtReady;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_usbmsProxy::signal_Ping() {
  return m_signalproxy_Ping;

}
