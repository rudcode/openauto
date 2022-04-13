#include "com_jci_usbmProxy.h"

com_jci_usbmProxy::com_jci_usbmProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_GetAlbumArt = this->create_method<std::tuple<std::string, uint32_t, uint32_t>(std::tuple < uint32_t,
                                                                                         uint32_t > )>("GetAlbumArt");
  m_method_SelectDevice = this->create_method<std::tuple<uint32_t, uint32_t>(std::tuple < uint32_t > )>("SelectDevice");
  m_method_PlaybackCommand =
      this->create_method<int32_t(std::tuple < uint32_t, uint32_t, uint32_t > )>("PlaybackCommand");
  m_method_PlayResume = this->create_method<Invalid(std::tuple < uint32_t, uint32_t > )>("PlayResume");
  m_method_PlayContext = this->create_method<std::tuple<uint32_t, uint32_t, uint32_t>(Invalid)>("PlayContext");
  m_method_SetRepeatMode = this->create_method<int32_t(uint32_t, uint32_t)>("SetRepeatMode");
  m_method_SetShuffleMode = this->create_method<int32_t(uint32_t, uint32_t)>("SetShuffleMode");
  m_method_GetDeviceList = this->create_method < DBus::MultipleReturn < std::tuple < std::vector < std::tuple
      < uint32_t, uint32_t, std::string, uint32_t, uint32_t, bool, bool, bool, uint32_t, uint32_t, std::string, std::string>>>,
  int32_t > () > ("GetDeviceList");
  m_method_GetCurrentObjectInfo =
      this->create_method < DBus::MultipleReturn < std::tuple < uint32_t, std::string, std::string, std::string,
      std::string >, int32_t > () > ("GetCurrentObjectInfo");
  m_method_StartSeeking = this->create_method<int32_t(uint32_t, uint32_t, uint32_t)>("StartSeeking");
  m_method_PlaybackJumpToPosition = this->create_method<int32_t(uint32_t, uint32_t)>("PlaybackJumpToPosition");
  m_method_MoreLikeThis = this->create_method<std::tuple<std::string, uint32_t>(uint32_t)>("MoreLikeThis");
  m_method_SetLanguage = this->create_method<int32_t(int32_t)>("SetLanguage");
  m_signalproxy_DeviceConnected = this->create_signal<void(std::tuple < uint32_t,
                                                           uint32_t,
                                                           std::string,
                                                           uint32_t,
                                                           uint32_t,
                                                           bool,
                                                           bool,
                                                           bool,
                                                           uint32_t,
                                                           uint32_t,
                                                           std::string,
                                                           std::string > )>("DeviceConnected");
  m_signalproxy_DeviceDisconnected = this->create_signal<void(uint32_t, int32_t)>("DeviceDisconnected");
  m_signalproxy_UpdateDeviceInfo = this->create_signal<void(std::tuple < uint32_t,
                                                            uint32_t,
                                                            std::string,
                                                            uint32_t,
                                                            uint32_t,
                                                            bool,
                                                            bool,
                                                            bool,
                                                            uint32_t,
                                                            uint32_t,
                                                            std::string,
                                                            std::string > )>("UpdateDeviceInfo");
  m_signalproxy_PlayComplete = this->create_signal<void(uint32_t)>("PlayComplete");
  m_signalproxy_DeviceSelected = this->create_signal<void(uint32_t, int32_t)>("DeviceSelected");
  m_signalproxy_MetadataBrowsingPossible =
      this->create_signal<void(std::tuple < uint32_t, uint32_t, std::string, uint32_t, bool, bool > )>(
          "MetadataBrowsingPossible");
  m_signalproxy_MltPossible =
      this->create_signal<void(std::tuple < uint32_t, uint32_t, std::string, uint32_t > )>("MltPossible");
  m_signalproxy_PlaybackPossible =
      this->create_signal<void(std::tuple < uint32_t, uint32_t, std::string, uint32_t, bool, bool > )>(
          "PlaybackPossible");
  m_signalproxy_FolderBrowsingPossible =
      this->create_signal<void(std::tuple < uint32_t, uint32_t, std::string, uint32_t > )>("FolderBrowsingPossible");
  m_signalproxy_DeviceError = this->create_signal<void(std::tuple < uint32_t, uint32_t > )>("DeviceError");
  m_signalproxy_PlaybackInfo = this->create_signal<void(Invalid)>("PlaybackInfo");
  m_signalproxy_DbUpdate = this->create_signal<void(std::tuple < uint32_t, uint32_t, uint32_t > )>("DbUpdate");
  m_signalproxy_AlbumArtReady = this->create_signal<void(std::tuple < uint32_t > )>("AlbumArtReady");
  m_signalproxy_CurrentObjectInfo =
      this->create_signal<void(std::tuple < uint32_t, std::string, std::string, std::string, std::string > )>(
          "CurrentObjectInfo");
  m_signalproxy_PlaybackInterrupted = this->create_signal<void(Invalid)>("PlaybackInterrupted");

}
std::shared_ptr <com_jci_usbmProxy> com_jci_usbmProxy::create(std::string name) {
  return std::shared_ptr<com_jci_usbmProxy>(new com_jci_usbmProxy(name));

}
std::tuple <std::string, uint32_t, uint32_t> com_jci_usbmProxy::GetAlbumArt(std::tuple <uint32_t, uint32_t> album_art) {
  return (*m_method_GetAlbumArt)(album_art);

}
std::tuple <uint32_t, uint32_t> com_jci_usbmProxy::SelectDevice(std::tuple <uint32_t> select_device) {
  return (*m_method_SelectDevice)(select_device);

}
int32_t com_jci_usbmProxy::PlaybackCommand(std::tuple <uint32_t, uint32_t, uint32_t> playback_command) {
  return (*m_method_PlaybackCommand)(playback_command);

}
Invalid com_jci_usbmProxy::PlayResume(std::tuple <uint32_t, uint32_t> play_resume) {
  return (*m_method_PlayResume)(play_resume);

}
std::tuple <uint32_t, uint32_t, uint32_t> com_jci_usbmProxy::PlayContext(Invalid play_context) {
  return (*m_method_PlayContext)(play_context);

}
int32_t com_jci_usbmProxy::SetRepeatMode(uint32_t dev_id, uint32_t repeat_mode) {
  return (*m_method_SetRepeatMode)(dev_id, repeat_mode);

}
int32_t com_jci_usbmProxy::SetShuffleMode(uint32_t dev_id, uint32_t shuffle_mode) {
  return (*m_method_SetShuffleMode)(dev_id, shuffle_mode);

}
DBus::MultipleReturn <std::tuple<std::vector < std::tuple < uint32_t,
                                 uint32_t,
                                 std::string,
                                 uint32_t,
                                 uint32_t,
                                 bool,
                                 bool,
                                 bool,
                                 uint32_t,
                                 uint32_t,
                                 std::string,
                                 std::string>>>,int32_t>
com_jci_usbmProxy::GetDeviceList() {
  return (*m_method_GetDeviceList)();

}
DBus::MultipleReturn <std::tuple<uint32_t,
                                 std::string,
                                 std::string,
                                 std::string,
                                 std::string>, int32_t> com_jci_usbmProxy::GetCurrentObjectInfo() {
  return (*m_method_GetCurrentObjectInfo)();

}
int32_t com_jci_usbmProxy::StartSeeking(uint32_t dev_id, uint32_t sec_step, uint32_t seek_dir) {
  return (*m_method_StartSeeking)(dev_id, sec_step, seek_dir);

}
int32_t com_jci_usbmProxy::PlaybackJumpToPosition(uint32_t dev_id, uint32_t new_pb_position) {
  return (*m_method_PlaybackJumpToPosition)(dev_id, new_pb_position);

}
std::tuple <std::string, uint32_t> com_jci_usbmProxy::MoreLikeThis(uint32_t device_id) {
  return (*m_method_MoreLikeThis)(device_id);

}
int32_t com_jci_usbmProxy::SetLanguage(int32_t sys_lang) {
  return (*m_method_SetLanguage)(sys_lang);

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t,
                                        std::string,
                                        uint32_t,
                                        uint32_t,
                                        bool,
                                        bool,
                                        bool,
                                        uint32_t,
                                        uint32_t,
                                        std::string,
                                        std::string > )>> com_jci_usbmProxy::signal_DeviceConnected() {
  return m_signalproxy_DeviceConnected;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, int32_t)>> com_jci_usbmProxy::signal_DeviceDisconnected() {
  return m_signalproxy_DeviceDisconnected;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t,
                                        std::string,
                                        uint32_t,
                                        uint32_t,
                                        bool,
                                        bool,
                                        bool,
                                        uint32_t,
                                        uint32_t,
                                        std::string,
                                        std::string > )>> com_jci_usbmProxy::signal_UpdateDeviceInfo() {
  return m_signalproxy_UpdateDeviceInfo;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_usbmProxy::signal_PlayComplete() {
  return m_signalproxy_PlayComplete;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, int32_t)>> com_jci_usbmProxy::signal_DeviceSelected() {
  return m_signalproxy_DeviceSelected;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t,
                                        std::string,
                                        uint32_t,
                                        bool,
                                        bool > )>> com_jci_usbmProxy::signal_MetadataBrowsingPossible() {
  return m_signalproxy_MetadataBrowsingPossible;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t,
                                        std::string,
                                        uint32_t > )>> com_jci_usbmProxy::signal_MltPossible() {
  return m_signalproxy_MltPossible;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t,
                                        std::string,
                                        uint32_t,
                                        bool,
                                        bool > )>> com_jci_usbmProxy::signal_PlaybackPossible() {
  return m_signalproxy_PlaybackPossible;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t,
                                        std::string,
                                        uint32_t > )>> com_jci_usbmProxy::signal_FolderBrowsingPossible() {
  return m_signalproxy_FolderBrowsingPossible;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t, uint32_t > )>> com_jci_usbmProxy::signal_DeviceError() {
  return m_signalproxy_DeviceError;

}
std::shared_ptr <DBus::SignalProxy<void(Invalid)>> com_jci_usbmProxy::signal_PlaybackInfo() {
  return m_signalproxy_PlaybackInfo;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t,
                                        uint32_t > )>> com_jci_usbmProxy::signal_DbUpdate() {
  return m_signalproxy_DbUpdate;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t > )>> com_jci_usbmProxy::signal_AlbumArtReady() {
  return m_signalproxy_AlbumArtReady;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        std::string,
                                        std::string,
                                        std::string,
                                        std::string > )>> com_jci_usbmProxy::signal_CurrentObjectInfo() {
  return m_signalproxy_CurrentObjectInfo;

}
std::shared_ptr <DBus::SignalProxy<void(Invalid)>> com_jci_usbmProxy::signal_PlaybackInterrupted() {
  return m_signalproxy_PlaybackInterrupted;

}
