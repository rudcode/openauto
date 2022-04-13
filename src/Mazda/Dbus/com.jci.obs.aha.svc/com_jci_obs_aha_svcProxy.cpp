#include "com_jci_obs_aha_svcProxy.h"

com_jci_obs_aha_svcProxy::com_jci_obs_aha_svcProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_ConnectUsingPseudoTerminal = this->create_method<DBus::MultipleReturn<int32_t, uint32_t>(std::string,
                                                                                                    std::string,
                                                                                                    std::tuple
                                                                                                        < std::string,
                                                                                                    std::string,
                                                                                                    std::string,
                                                                                                    std::string,
                                                                                                    std::string,
                                                                                                    std::string > ,
                                                                                                    uint8_t)>(
      "ConnectUsingPseudoTerminal");
  m_method_Disconnect = this->create_method<int32_t(uint32_t, uint32_t)>("Disconnect");
  m_method_ChangeClientPlaybackState =
      this->create_method<DBus::MultipleReturn<uint64_t, uint8_t, int32_t>(uint32_t, uint8_t)>(
          "ChangeClientPlaybackState");
  m_method_SelectContentForPlayback = this->create_method<int32_t(uint32_t, uint64_t)>("SelectContentForPlayback");
  m_method_SelectStationForPlayback =
      this->create_method<int32_t(uint32_t, uint64_t, uint8_t)>("SelectStationForPlayback");
  m_method_TimeShiftContent = this->create_method<int32_t(uint32_t, int16_t)>("TimeShiftContent");
  m_method_PerformAction = this->create_method<int32_t(uint32_t, uint32_t, uint64_t)>("PerformAction");
  m_method_PostNewRecording = this->create_method<int32_t(uint32_t, std::string)>("PostNewRecording");

}
std::shared_ptr <com_jci_obs_aha_svcProxy> com_jci_obs_aha_svcProxy::create(std::string name) {
  return std::shared_ptr<com_jci_obs_aha_svcProxy>(new com_jci_obs_aha_svcProxy(name));

}
DBus::MultipleReturn <int32_t, uint32_t> com_jci_obs_aha_svcProxy::ConnectUsingPseudoTerminal(std::string pseudoTerminal,
                                                                                              std::string sessionName,
                                                                                              std::tuple <std::string, std::string, std::string, std::string, std::string, std::string> vehicleInfo,
                                                                                              uint8_t shoutFormat) {
  return (*m_method_ConnectUsingPseudoTerminal)(pseudoTerminal, sessionName, vehicleInfo, shoutFormat);

}
int32_t com_jci_obs_aha_svcProxy::Disconnect(uint32_t sessionId, uint32_t reasonId) {
  return (*m_method_Disconnect)(sessionId, reasonId);

}
DBus::MultipleReturn <uint64_t, uint8_t, int32_t> com_jci_obs_aha_svcProxy::ChangeClientPlaybackState(uint32_t sessionId,
                                                                                                      uint8_t playbackState) {
  return (*m_method_ChangeClientPlaybackState)(sessionId, playbackState);

}
int32_t com_jci_obs_aha_svcProxy::SelectContentForPlayback(uint32_t sessionId, uint64_t contentId) {
  return (*m_method_SelectContentForPlayback)(sessionId, contentId);

}
int32_t com_jci_obs_aha_svcProxy::SelectStationForPlayback(uint32_t sessionId,
                                                           uint64_t stationId,
                                                           uint8_t playbackFromBegin) {
  return (*m_method_SelectStationForPlayback)(sessionId, stationId, playbackFromBegin);

}
int32_t com_jci_obs_aha_svcProxy::TimeShiftContent(uint32_t sessionId, int16_t nOSecondsToTimeShift) {
  return (*m_method_TimeShiftContent)(sessionId, nOSecondsToTimeShift);

}
int32_t com_jci_obs_aha_svcProxy::PerformAction(uint32_t sessionId, uint32_t actionId, uint64_t contentId) {
  return (*m_method_PerformAction)(sessionId, actionId, contentId);

}
int32_t com_jci_obs_aha_svcProxy::PostNewRecording(uint32_t sessionId, std::string file) {
  return (*m_method_PostNewRecording)(sessionId, file);

}
