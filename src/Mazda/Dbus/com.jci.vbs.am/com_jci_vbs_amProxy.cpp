#include "com_jci_vbs_amProxy.h"

com_jci_vbs_amProxy::com_jci_vbs_amProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_SetMute = this->create_method<uint8_t(uint8_t, uint8_t)>("SetMute");
  m_method_SetUnMute = this->create_method<uint8_t(uint8_t, uint8_t)>("SetUnMute");
  m_method_SourceSelect =
      this->create_method<uint8_t(std::string, std::string, std::string, std::string, std::string, std::string)>(
          "SourceSelect");
  m_method_SetVolume = this->create_method<uint8_t(uint8_t, uint32_t, int32_t, std::string)>("SetVolume");
  m_method_SetAudioProfile = this->create_method<uint8_t(uint8_t, uint8_t, int32_t, int32_t)>("SetAudioProfile");
  m_method_GetVolumeStatus =
      this->create_method<DBus::MultipleReturn<std::string, int32_t, uint8_t>(std::string)>("GetVolumeStatus");
  m_method_GetEntertainmentMuteStatus = this->create_method<uint8_t()>("GetEntertainmentMuteStatus");
  m_method_GetLastMode = this->create_method<uint8_t()>("GetLastMode");
  m_method_SetLastMode = this->create_method<uint8_t(std::string, std::string, std::string)>("SetLastMode");
  m_method_GetAudioProfileStatus =
      this->create_method<DBus::MultipleReturn<int32_t, uint8_t>(uint8_t)>("GetAudioProfileStatus");
  m_method_GetMuteStatus = this->create_method<DBus::MultipleReturn<uint8_t, uint8_t>(uint8_t)>("GetMuteStatus");
  m_method_SetVolumeVolMgr = this->create_method<uint8_t(uint8_t, uint8_t, uint8_t)>("SetVolumeVolMgr");
  m_method_GetActiveSource =
      this->create_method<DBus::MultipleReturn<std::string, std::string, uint8_t>()>("GetActiveSource");
  m_signalproxy_AudioProfileStatus = this->create_signal<void(uint8_t, int32_t)>("AudioProfileStatus");
  m_signalproxy_MuteStatus = this->create_signal<void(uint8_t)>("MuteStatus");
  m_signalproxy_UnMuteStatus = this->create_signal<void(uint8_t)>("UnMuteStatus");
  m_signalproxy_SourceSelectResponse =
      this->create_signal<void(std::string, std::string, std::string, std::string)>("SourceSelectResponse");
  m_signalproxy_VolumeStatus = this->create_signal<void(uint8_t, std::string, int32_t)>("VolumeStatus");
  m_signalproxy_TAUSourceChangeResponse =
      this->create_signal<void(std::tuple < uint8_t, uint8_t > )>("TAUSourceChangeResponse");
  m_signalproxy_EntertainmentMuteStatus = this->create_signal<void(uint8_t)>("EntertainmentMuteStatus");
  m_signalproxy_LastModeStatus =
      this->create_signal<void(uint8_t, std::string, std::string, std::string, std::string, uint8_t, uint8_t, uint8_t)>(
          "LastModeStatus");

}
std::shared_ptr <com_jci_vbs_amProxy> com_jci_vbs_amProxy::create(std::string name) {
  return std::shared_ptr<com_jci_vbs_amProxy>(new com_jci_vbs_amProxy(name));

}
uint8_t com_jci_vbs_amProxy::SetMute(uint8_t muteType, uint8_t rampTime) {
  return (*m_method_SetMute)(muteType, rampTime);

}
uint8_t com_jci_vbs_amProxy::SetUnMute(uint8_t muteType, uint8_t rampTime) {
  return (*m_method_SetUnMute)(muteType, rampTime);

}
uint8_t com_jci_vbs_amProxy::SourceSelect(std::string source1,
                                          std::string source2,
                                          std::string source3,
                                          std::string sourceOff,
                                          std::string cMU_Audio_Left,
                                          std::string cMU_Audio_Right) {
  return (*m_method_SourceSelect)(source1, source2, source3, sourceOff, cMU_Audio_Left, cMU_Audio_Right);

}
uint8_t com_jci_vbs_amProxy::SetVolume(uint8_t volumeType,
                                       uint32_t controlValue,
                                       int32_t volumeValue,
                                       std::string volSrcGrp) {
  return (*m_method_SetVolume)(volumeType, controlValue, volumeValue, volSrcGrp);

}
uint8_t com_jci_vbs_amProxy::SetAudioProfile(uint8_t controlValue,
                                             uint8_t audioProfileType,
                                             int32_t audioProfileValue,
                                             int32_t lastProfile) {
  return (*m_method_SetAudioProfile)(controlValue, audioProfileType, audioProfileValue, lastProfile);

}
DBus::MultipleReturn <std::string, int32_t, uint8_t> com_jci_vbs_amProxy::GetVolumeStatus(std::string volSrcGrp) {
  return (*m_method_GetVolumeStatus)(volSrcGrp);

}
uint8_t com_jci_vbs_amProxy::GetEntertainmentMuteStatus() {
  return (*m_method_GetEntertainmentMuteStatus)();

}
uint8_t com_jci_vbs_amProxy::GetLastMode() {
  return (*m_method_GetLastMode)();

}
uint8_t com_jci_vbs_amProxy::SetLastMode(std::string activeSource,
                                         std::string prevSource,
                                         std::string broadcastSource) {
  return (*m_method_SetLastMode)(activeSource, prevSource, broadcastSource);

}
DBus::MultipleReturn <int32_t, uint8_t> com_jci_vbs_amProxy::GetAudioProfileStatus(uint8_t profileType) {
  return (*m_method_GetAudioProfileStatus)(profileType);

}
DBus::MultipleReturn <uint8_t, uint8_t> com_jci_vbs_amProxy::GetMuteStatus(uint8_t muteType) {
  return (*m_method_GetMuteStatus)(muteType);

}
uint8_t com_jci_vbs_amProxy::SetVolumeVolMgr(uint8_t bthfVol, uint8_t ringToneVol, uint8_t naviVol) {
  return (*m_method_SetVolumeVolMgr)(bthfVol, ringToneVol, naviVol);

}
DBus::MultipleReturn <std::string, std::string, uint8_t> com_jci_vbs_amProxy::GetActiveSource() {
  return (*m_method_GetActiveSource)();

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t, int32_t)>> com_jci_vbs_amProxy::signal_AudioProfileStatus() {
  return m_signalproxy_AudioProfileStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_amProxy::signal_MuteStatus() {
  return m_signalproxy_MuteStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_amProxy::signal_UnMuteStatus() {
  return m_signalproxy_UnMuteStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::string,
                                        std::string,
                                        std::string,
                                        std::string)>> com_jci_vbs_amProxy::signal_SourceSelectResponse() {
  return m_signalproxy_SourceSelectResponse;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t, std::string, int32_t)>> com_jci_vbs_amProxy::signal_VolumeStatus() {
  return m_signalproxy_VolumeStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t > )>> com_jci_vbs_amProxy::signal_TAUSourceChangeResponse() {
  return m_signalproxy_TAUSourceChangeResponse;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_amProxy::signal_EntertainmentMuteStatus() {
  return m_signalproxy_EntertainmentMuteStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t,
                                        std::string,
                                        std::string,
                                        std::string,
                                        std::string,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t)>> com_jci_vbs_amProxy::signal_LastModeStatus() {
  return m_signalproxy_LastModeStatus;

}
