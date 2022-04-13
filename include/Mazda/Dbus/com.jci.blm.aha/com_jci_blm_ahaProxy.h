#ifndef COM_JCI_BLM_AHAPROXY_H
#define COM_JCI_BLM_AHAPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_blm_ahaProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_blm_ahaProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_blm_ahaProxy> create(std::string name = "com.jci.blm.aha");
  DBus::MultipleReturn<int32_t, uint32_t, bool> Connect();
  int32_t Disconnect(uint32_t sessionId);
  DBus::MultipleReturn<uint64_t, uint8_t, int32_t> ChangeClientPlaybackState(uint32_t sessionId, uint8_t playbackState);
  int32_t SelectContentForPlayback(uint32_t sessionId, uint64_t contentId);
  int32_t SelectStationForPlayback(uint32_t sessionId, uint64_t stationId, uint8_t playbackFromBegin);
  int32_t TimeShiftContent(uint32_t sessionId, int16_t nOSecondsToTimeShift);
  int32_t PerformActionVoteLike(uint32_t sessionId, uint64_t contentId);
  int32_t PerformActionRetweet(uint32_t sessionId, uint64_t contentId);
  int32_t PerformActionTweetCurrentLocation(uint32_t sessionId);
  int32_t PerformActionVoteDislike(uint32_t sessionId, uint64_t contentId);
  int32_t PerformActionUnvote(uint32_t sessionId, uint64_t contentId);
  int32_t PerformActionUploadCurrentLocationToFacebook(uint32_t sessionId);
  int32_t PerformActionLogNavigate(uint32_t sessionId, uint64_t contentId);
  int32_t PerformActionLogCallAction(uint32_t sessionId, uint64_t contentId);
  int32_t RecordingStart(uint32_t sessionId, uint32_t maxRecordingTime);
  int32_t RecordingCancel(uint32_t sessionId);
  int32_t RecordingPost(uint32_t sessionId);
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t, uint8_t)>> signal_StatusUpdate();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_RecordingCancelled();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, bool)>> signal_Connected();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint8_t)>> signal_Disconnected();
 protected:
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t, bool>()>> m_method_Connect;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_Disconnect;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint64_t, uint8_t, int32_t>(uint32_t, uint8_t)>>
      m_method_ChangeClientPlaybackState;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint64_t)>> m_method_SelectContentForPlayback;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint64_t, uint8_t)>> m_method_SelectStationForPlayback;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, int16_t)>> m_method_TimeShiftContent;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint64_t)>> m_method_PerformActionVoteLike;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint64_t)>> m_method_PerformActionRetweet;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_PerformActionTweetCurrentLocation;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint64_t)>> m_method_PerformActionVoteDislike;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint64_t)>> m_method_PerformActionUnvote;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_PerformActionUploadCurrentLocationToFacebook;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint64_t)>> m_method_PerformActionLogNavigate;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint64_t)>> m_method_PerformActionLogCallAction;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t)>> m_method_RecordingStart;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_RecordingCancel;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_RecordingPost;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t, uint8_t)>> m_signalproxy_StatusUpdate;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_RecordingCancelled;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, bool)>> m_signalproxy_Connected;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint8_t)>> m_signalproxy_Disconnected;
};
#endif /* COM_JCI_BLM_AHAPROXY_H */
