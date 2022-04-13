#include "com_jci_btmusicProxy.h"

com_jci_btmusicProxy::com_jci_btmusicProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_StartStreaming = this->create_method<int32_t()>("StartStreaming");
  m_method_StopStreaming = this->create_method<int32_t()>("StopStreaming");
  m_method_StreamingAudioCmd = this->create_method<int32_t(uint32_t)>("StreamingAudioCmd");
  m_method_GetTrackInfo = this->create_method<int32_t()>("GetTrackInfo");
  m_method_BrowseFolderUp = this->create_method<int32_t(uint32_t)>("BrowseFolderUp");
  m_method_BrowseFolderDown = this->create_method<int32_t(uint32_t)>("BrowseFolderDown");
  m_method_GetBrowseItemTitleForFolder =
      this->create_method<int32_t(uint32_t, uint32_t, uint32_t)>("GetBrowseItemTitleForFolder");
  m_method_GetNowPlayListTitleForFile =
      this->create_method<int32_t(uint32_t, uint32_t, uint32_t)>("GetNowPlayListTitleForFile");
  m_method_PlayBrowseItem = this->create_method<int32_t(uint32_t, uint32_t)>("PlayBrowseItem");
  m_method_SetLanguage = this->create_method<int32_t(int32_t)>("SetLanguage");
  m_signalproxy_StreamingStatus = this->create_signal<void(uint32_t)>("StreamingStatus");
  m_signalproxy_StreamingAudioCmdStatus = this->create_signal<void(uint32_t, uint32_t)>("StreamingAudioCmdStatus");
  m_signalproxy_StreamingPlayerStatus = this->create_signal<void(uint32_t, uint32_t)>("StreamingPlayerStatus");
  m_signalproxy_TrackInformation =
      this->create_signal<void(std::tuple < std::vector < uint8_t >> )>("TrackInformation");
  m_signalproxy_DeviceBatteryIndicator = this->create_signal<void(uint32_t)>("DeviceBatteryIndicator");
  m_signalproxy_BusyReason = this->create_signal<void(uint32_t)>("BusyReason");
  m_signalproxy_TrackChangeIndicator = this->create_signal<void()>("TrackChangeIndicator");
  m_signalproxy_TrackPositionIndicator = this->create_signal<void(int32_t)>("TrackPositionIndicator");
  m_signalproxy_NowPlayingChangeIndicator = this->create_signal<void()>("NowPlayingChangeIndicator");
  m_signalproxy_SettingsStatus = this->create_signal<void(uint32_t, uint32_t, uint32_t)>("SettingsStatus");
  m_signalproxy_PlayerSettingsInfo =
      this->create_signal<void(std::tuple < std::vector < uint8_t >> )>("PlayerSettingsInfo");
  m_signalproxy_FolderBrowseItemTitleResponse =
      this->create_signal<void(std::tuple < std::vector < uint8_t >> )>("FolderBrowseItemTitleResponse");
  m_signalproxy_BrowseNowPlayingTitleResponse =
      this->create_signal<void(std::tuple < std::vector < uint8_t >> )>("BrowseNowPlayingTitleResponse");
  m_signalproxy_BrowseFolderResponse =
      this->create_signal<void(std::tuple < std::vector < uint8_t >> )>("BrowseFolderResponse");
  m_signalproxy_BrowseStatus = this->create_signal<void(uint32_t)>("BrowseStatus");
  m_signalproxy_BrowseConnStatus = this->create_signal<void(uint32_t)>("BrowseConnStatus");
  m_signalproxy_NowPlayingInfo = this->create_signal<void(uint32_t, uint32_t)>("NowPlayingInfo");
  m_signalproxy_MusicProfileSupported = this->create_signal<void(uint32_t)>("MusicProfileSupported");

}
std::shared_ptr <com_jci_btmusicProxy> com_jci_btmusicProxy::create(std::string name) {
  return std::shared_ptr<com_jci_btmusicProxy>(new com_jci_btmusicProxy(name));

}
int32_t com_jci_btmusicProxy::StartStreaming() {
  return (*m_method_StartStreaming)();

}
int32_t com_jci_btmusicProxy::StopStreaming() {
  return (*m_method_StopStreaming)();

}
int32_t com_jci_btmusicProxy::StreamingAudioCmd(uint32_t commandType) {
  return (*m_method_StreamingAudioCmd)(commandType);

}
int32_t com_jci_btmusicProxy::GetTrackInfo() {
  return (*m_method_GetTrackInfo)();

}
int32_t com_jci_btmusicProxy::BrowseFolderUp(uint32_t folderType) {
  return (*m_method_BrowseFolderUp)(folderType);

}
int32_t com_jci_btmusicProxy::BrowseFolderDown(uint32_t index) {
  return (*m_method_BrowseFolderDown)(index);

}
int32_t com_jci_btmusicProxy::GetBrowseItemTitleForFolder(uint32_t itemStartIndex,
                                                          uint32_t itemEndIndex,
                                                          uint32_t requestedPage) {
  return (*m_method_GetBrowseItemTitleForFolder)(itemStartIndex, itemEndIndex, requestedPage);

}
int32_t com_jci_btmusicProxy::GetNowPlayListTitleForFile(uint32_t itemStartIndex,
                                                         uint32_t itemEndIndex,
                                                         uint32_t requestedPage) {
  return (*m_method_GetNowPlayListTitleForFile)(itemStartIndex, itemEndIndex, requestedPage);

}
int32_t com_jci_btmusicProxy::PlayBrowseItem(uint32_t playScope, uint32_t playItemId) {
  return (*m_method_PlayBrowseItem)(playScope, playItemId);

}
int32_t com_jci_btmusicProxy::SetLanguage(int32_t sys_lang) {
  return (*m_method_SetLanguage)(sys_lang);

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_btmusicProxy::signal_StreamingStatus() {
  return m_signalproxy_StreamingStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, uint32_t)>> com_jci_btmusicProxy::signal_StreamingAudioCmdStatus() {
  return m_signalproxy_StreamingAudioCmdStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, uint32_t)>> com_jci_btmusicProxy::signal_StreamingPlayerStatus() {
  return m_signalproxy_StreamingPlayerStatus;

}
std::shared_ptr <DBus::SignalProxy<void(
    std::tuple < std::vector < uint8_t >> )>> com_jci_btmusicProxy::signal_TrackInformation() {
  return m_signalproxy_TrackInformation;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_btmusicProxy::signal_DeviceBatteryIndicator() {
  return m_signalproxy_DeviceBatteryIndicator;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_btmusicProxy::signal_BusyReason() {
  return m_signalproxy_BusyReason;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_btmusicProxy::signal_TrackChangeIndicator() {
  return m_signalproxy_TrackChangeIndicator;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_btmusicProxy::signal_TrackPositionIndicator() {
  return m_signalproxy_TrackPositionIndicator;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_btmusicProxy::signal_NowPlayingChangeIndicator() {
  return m_signalproxy_NowPlayingChangeIndicator;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, uint32_t, uint32_t)>> com_jci_btmusicProxy::signal_SettingsStatus() {
  return m_signalproxy_SettingsStatus;

}
std::shared_ptr <DBus::SignalProxy<void(
    std::tuple < std::vector < uint8_t >> )>> com_jci_btmusicProxy::signal_PlayerSettingsInfo() {
  return m_signalproxy_PlayerSettingsInfo;

}
std::shared_ptr <DBus::SignalProxy<void(
    std::tuple < std::vector < uint8_t >> )>> com_jci_btmusicProxy::signal_FolderBrowseItemTitleResponse() {
  return m_signalproxy_FolderBrowseItemTitleResponse;

}
std::shared_ptr <DBus::SignalProxy<void(
    std::tuple < std::vector < uint8_t >> )>> com_jci_btmusicProxy::signal_BrowseNowPlayingTitleResponse() {
  return m_signalproxy_BrowseNowPlayingTitleResponse;

}
std::shared_ptr <DBus::SignalProxy<void(
    std::tuple < std::vector < uint8_t >> )>> com_jci_btmusicProxy::signal_BrowseFolderResponse() {
  return m_signalproxy_BrowseFolderResponse;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_btmusicProxy::signal_BrowseStatus() {
  return m_signalproxy_BrowseStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_btmusicProxy::signal_BrowseConnStatus() {
  return m_signalproxy_BrowseConnStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, uint32_t)>> com_jci_btmusicProxy::signal_NowPlayingInfo() {
  return m_signalproxy_NowPlayingInfo;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_btmusicProxy::signal_MusicProfileSupported() {
  return m_signalproxy_MusicProfileSupported;

}
