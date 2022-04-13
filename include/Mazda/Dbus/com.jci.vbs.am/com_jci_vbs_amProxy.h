#ifndef COM_JCI_VBS_AMPROXY_H
#define COM_JCI_VBS_AMPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_vbs_amProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_vbs_amProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_vbs_amProxy> create(std::string name = "com.jci.vbs.am");
  uint8_t SetMute(uint8_t muteType, uint8_t rampTime);
  uint8_t SetUnMute(uint8_t muteType, uint8_t rampTime);
  uint8_t SourceSelect(std::string source1,
                       std::string source2,
                       std::string source3,
                       std::string sourceOff,
                       std::string cMU_Audio_Left,
                       std::string cMU_Audio_Right);
  uint8_t SetVolume(uint8_t volumeType, uint32_t controlValue, int32_t volumeValue, std::string volSrcGrp);
  uint8_t SetAudioProfile(uint8_t controlValue,
                          uint8_t audioProfileType,
                          int32_t audioProfileValue,
                          int32_t lastProfile);
  DBus::MultipleReturn<std::string, int32_t, uint8_t> GetVolumeStatus(std::string volSrcGrp);
  uint8_t GetEntertainmentMuteStatus();
  uint8_t GetLastMode();
  uint8_t SetLastMode(std::string activeSource, std::string prevSource, std::string broadcastSource);
  DBus::MultipleReturn<int32_t, uint8_t> GetAudioProfileStatus(uint8_t profileType);
  DBus::MultipleReturn<uint8_t, uint8_t> GetMuteStatus(uint8_t muteType);
  uint8_t SetVolumeVolMgr(uint8_t bthfVol, uint8_t ringToneVol, uint8_t naviVol);
  DBus::MultipleReturn<std::string, std::string, uint8_t> GetActiveSource();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, int32_t)>> signal_AudioProfileStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_MuteStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_UnMuteStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::string,
                                         std::string,
                                         std::string,
                                         std::string)>> signal_SourceSelectResponse();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, std::string, int32_t)>> signal_VolumeStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t>)>> signal_TAUSourceChangeResponse();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_EntertainmentMuteStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         uint8_t,
                                         uint8_t,
                                         uint8_t)>> signal_LastModeStatus();
 protected:
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t, uint8_t)>> m_method_SetMute;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t, uint8_t)>> m_method_SetUnMute;
  std::shared_ptr<DBus::MethodProxy<uint8_t(std::string,
                                            std::string,
                                            std::string,
                                            std::string,
                                            std::string,
                                            std::string)>> m_method_SourceSelect;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t, uint32_t, int32_t, std::string)>> m_method_SetVolume;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t, uint8_t, int32_t, int32_t)>> m_method_SetAudioProfile;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::string, int32_t, uint8_t>(std::string)>>
      m_method_GetVolumeStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetEntertainmentMuteStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetLastMode;
  std::shared_ptr<DBus::MethodProxy<uint8_t(std::string, std::string, std::string)>> m_method_SetLastMode;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint8_t>(uint8_t)>> m_method_GetAudioProfileStatus;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint8_t, uint8_t>(uint8_t)>> m_method_GetMuteStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t, uint8_t, uint8_t)>> m_method_SetVolumeVolMgr;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::string, std::string, uint8_t>()>>
      m_method_GetActiveSource;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, int32_t)>> m_signalproxy_AudioProfileStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_MuteStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_UnMuteStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::string, std::string, std::string, std::string)>>
      m_signalproxy_SourceSelectResponse;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, std::string, int32_t)>> m_signalproxy_VolumeStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t>)>> m_signalproxy_TAUSourceChangeResponse;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_EntertainmentMuteStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         uint8_t,
                                         uint8_t,
                                         uint8_t)>> m_signalproxy_LastModeStatus;
};
#endif /* COM_JCI_VBS_AMPROXY_H */
