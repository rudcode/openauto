#ifndef COM_JCI_OBS_AHA_SVCPROXY_H
#define COM_JCI_OBS_AHA_SVCPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_obs_aha_svcProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_obs_aha_svcProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_obs_aha_svcProxy> create(std::string name = "com.jci.obs.aha.svc");
  DBus::MultipleReturn<int32_t, uint32_t> ConnectUsingPseudoTerminal(std::string pseudoTerminal,
                                                                     std::string sessionName,
                                                                     std::tuple<std::string,
                                                                                std::string,
                                                                                std::string,
                                                                                std::string,
                                                                                std::string,
                                                                                std::string> vehicleInfo,
                                                                     uint8_t shoutFormat);
  int32_t Disconnect(uint32_t sessionId, uint32_t reasonId);
  DBus::MultipleReturn<uint64_t, uint8_t, int32_t> ChangeClientPlaybackState(uint32_t sessionId, uint8_t playbackState);
  int32_t SelectContentForPlayback(uint32_t sessionId, uint64_t contentId);
  int32_t SelectStationForPlayback(uint32_t sessionId, uint64_t stationId, uint8_t playbackFromBegin);
  int32_t TimeShiftContent(uint32_t sessionId, int16_t nOSecondsToTimeShift);
  int32_t PerformAction(uint32_t sessionId, uint32_t actionId, uint64_t contentId);
  int32_t PostNewRecording(uint32_t sessionId, std::string file);
 protected:
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t>(std::string,
                                                                            std::string,
                                                                            std::tuple<std::string,
                                                                                       std::string,
                                                                                       std::string,
                                                                                       std::string,
                                                                                       std::string,
                                                                                       std::string>,
                                                                            uint8_t)>>
      m_method_ConnectUsingPseudoTerminal;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t)>> m_method_Disconnect;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint64_t, uint8_t, int32_t>(uint32_t, uint8_t)>>
      m_method_ChangeClientPlaybackState;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint64_t)>> m_method_SelectContentForPlayback;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint64_t, uint8_t)>> m_method_SelectStationForPlayback;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, int16_t)>> m_method_TimeShiftContent;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t, uint64_t)>> m_method_PerformAction;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, std::string)>> m_method_PostNewRecording;
};
#endif /* COM_JCI_OBS_AHA_SVCPROXY_H */
