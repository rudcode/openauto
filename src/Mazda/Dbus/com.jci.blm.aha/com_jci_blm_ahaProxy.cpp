#include "com_jci_blm_ahaProxy.h"

com_jci_blm_ahaProxy::com_jci_blm_ahaProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_Connect = this->create_method<DBus::MultipleReturn<int32_t, uint32_t, bool>()>("Connect");
  m_method_Disconnect = this->create_method<int32_t(uint32_t)>("Disconnect");
  m_method_ChangeClientPlaybackState =
      this->create_method<DBus::MultipleReturn<uint64_t, uint8_t, int32_t>(uint32_t, uint8_t)>(
          "ChangeClientPlaybackState");
  m_method_SelectContentForPlayback = this->create_method<int32_t(uint32_t, uint64_t)>("SelectContentForPlayback");
  m_method_SelectStationForPlayback =
      this->create_method<int32_t(uint32_t, uint64_t, uint8_t)>("SelectStationForPlayback");
  m_method_TimeShiftContent = this->create_method<int32_t(uint32_t, int16_t)>("TimeShiftContent");
  m_method_PerformActionVoteLike = this->create_method<int32_t(uint32_t, uint64_t)>("PerformActionVoteLike");
  m_method_PerformActionRetweet = this->create_method<int32_t(uint32_t, uint64_t)>("PerformActionRetweet");
  m_method_PerformActionTweetCurrentLocation =
      this->create_method<int32_t(uint32_t)>("PerformActionTweetCurrentLocation");
  m_method_PerformActionVoteDislike = this->create_method<int32_t(uint32_t, uint64_t)>("PerformActionVoteDislike");
  m_method_PerformActionUnvote = this->create_method<int32_t(uint32_t, uint64_t)>("PerformActionUnvote");
  m_method_PerformActionUploadCurrentLocationToFacebook =
      this->create_method<int32_t(uint32_t)>("PerformActionUploadCurrentLocationToFacebook");
  m_method_PerformActionLogNavigate = this->create_method<int32_t(uint32_t, uint64_t)>("PerformActionLogNavigate");
  m_method_PerformActionLogCallAction = this->create_method<int32_t(uint32_t, uint64_t)>("PerformActionLogCallAction");
  m_method_RecordingStart = this->create_method<int32_t(uint32_t, uint32_t)>("RecordingStart");
  m_method_RecordingCancel = this->create_method<int32_t(uint32_t)>("RecordingCancel");
  m_method_RecordingPost = this->create_method<int32_t(uint32_t)>("RecordingPost");
  m_signalproxy_StatusUpdate = this->create_signal<void(uint32_t, uint32_t, uint8_t)>("StatusUpdate");
  m_signalproxy_RecordingCancelled = this->create_signal<void(uint32_t)>("RecordingCancelled");
  m_signalproxy_Connected = this->create_signal<void(uint32_t, bool)>("Connected");
  m_signalproxy_Disconnected = this->create_signal<void(uint32_t, uint8_t)>("Disconnected");

}
std::shared_ptr <com_jci_blm_ahaProxy> com_jci_blm_ahaProxy::create(std::string name) {
  return std::shared_ptr<com_jci_blm_ahaProxy>(new com_jci_blm_ahaProxy(name));

}
DBus::MultipleReturn<int32_t, uint32_t, bool> com_jci_blm_ahaProxy::Connect() {
  return (*m_method_Connect)();

}
int32_t com_jci_blm_ahaProxy::Disconnect(uint32_t sessionId) {
  return (*m_method_Disconnect)(sessionId);

}
DBus::MultipleReturn <uint64_t, uint8_t, int32_t> com_jci_blm_ahaProxy::ChangeClientPlaybackState(uint32_t sessionId,
                                                                                                  uint8_t playbackState) {
  return (*m_method_ChangeClientPlaybackState)(sessionId, playbackState);

}
int32_t com_jci_blm_ahaProxy::SelectContentForPlayback(uint32_t sessionId, uint64_t contentId) {
  return (*m_method_SelectContentForPlayback)(sessionId, contentId);

}
int32_t com_jci_blm_ahaProxy::SelectStationForPlayback(uint32_t sessionId,
                                                       uint64_t stationId,
                                                       uint8_t playbackFromBegin) {
  return (*m_method_SelectStationForPlayback)(sessionId, stationId, playbackFromBegin);

}
int32_t com_jci_blm_ahaProxy::TimeShiftContent(uint32_t sessionId, int16_t nOSecondsToTimeShift) {
  return (*m_method_TimeShiftContent)(sessionId, nOSecondsToTimeShift);

}
int32_t com_jci_blm_ahaProxy::PerformActionVoteLike(uint32_t sessionId, uint64_t contentId) {
  return (*m_method_PerformActionVoteLike)(sessionId, contentId);

}
int32_t com_jci_blm_ahaProxy::PerformActionRetweet(uint32_t sessionId, uint64_t contentId) {
  return (*m_method_PerformActionRetweet)(sessionId, contentId);

}
int32_t com_jci_blm_ahaProxy::PerformActionTweetCurrentLocation(uint32_t sessionId) {
  return (*m_method_PerformActionTweetCurrentLocation)(sessionId);

}
int32_t com_jci_blm_ahaProxy::PerformActionVoteDislike(uint32_t sessionId, uint64_t contentId) {
  return (*m_method_PerformActionVoteDislike)(sessionId, contentId);

}
int32_t com_jci_blm_ahaProxy::PerformActionUnvote(uint32_t sessionId, uint64_t contentId) {
  return (*m_method_PerformActionUnvote)(sessionId, contentId);

}
int32_t com_jci_blm_ahaProxy::PerformActionUploadCurrentLocationToFacebook(uint32_t sessionId) {
  return (*m_method_PerformActionUploadCurrentLocationToFacebook)(sessionId);

}
int32_t com_jci_blm_ahaProxy::PerformActionLogNavigate(uint32_t sessionId, uint64_t contentId) {
  return (*m_method_PerformActionLogNavigate)(sessionId, contentId);

}
int32_t com_jci_blm_ahaProxy::PerformActionLogCallAction(uint32_t sessionId, uint64_t contentId) {
  return (*m_method_PerformActionLogCallAction)(sessionId, contentId);

}
int32_t com_jci_blm_ahaProxy::RecordingStart(uint32_t sessionId, uint32_t maxRecordingTime) {
  return (*m_method_RecordingStart)(sessionId, maxRecordingTime);

}
int32_t com_jci_blm_ahaProxy::RecordingCancel(uint32_t sessionId) {
  return (*m_method_RecordingCancel)(sessionId);

}
int32_t com_jci_blm_ahaProxy::RecordingPost(uint32_t sessionId) {
  return (*m_method_RecordingPost)(sessionId);

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, uint32_t, uint8_t)>> com_jci_blm_ahaProxy::signal_StatusUpdate() {
  return m_signalproxy_StatusUpdate;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_blm_ahaProxy::signal_RecordingCancelled() {
  return m_signalproxy_RecordingCancelled;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, bool)>> com_jci_blm_ahaProxy::signal_Connected() {
  return m_signalproxy_Connected;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, uint8_t)>> com_jci_blm_ahaProxy::signal_Disconnected() {
  return m_signalproxy_Disconnected;

}
