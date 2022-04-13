#ifndef COM_JCI_OBS_STITCHER_HMIPROXY_H
#define COM_JCI_OBS_STITCHER_HMIPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_obs_stitcher_hmiProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_obs_stitcher_hmiProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_obs_stitcher_hmiProxy> create(std::string name = "com.jci.obs.stitcher.hmi");
  DBus::MultipleReturn<int32_t, std::tuple<std::vector<std::tuple<uint32_t, std::string>>>> ListSessions();
  DBus::MultipleReturn<int32_t, std::tuple<std::vector<std::string>>> ListAttachedClients(uint32_t sessionId);
  int32_t AttachToSession(uint32_t sessionId, std::string clientName);
  int32_t DetachFromSession(uint32_t sessionId, std::string clientName);
  int32_t SetElapsedPolling(uint32_t sessionId, uint8_t groupType, uint32_t timeMs);
  DBus::MultipleReturn<int32_t, std::string> GetResource(uint32_t sessionId,
                                                         uint8_t groupType,
                                                         uint64_t groupId,
                                                         uint32_t resourceId);
  int32_t ReleaseResource(uint32_t sessionId, uint32_t resourceId);
  DBus::MultipleReturn<int32_t, int32_t, std::tuple<std::vector<uint64_t>>> StationGetListId(uint32_t sessionId,
                                                                                             uint32_t parentId,
                                                                                             uint32_t startPosition,
                                                                                             uint32_t numberOfStations);
  DBus::MultipleReturn<int32_t, Invalid> StationGetAllInfo(uint32_t sessionId, uint64_t stationId);
  DBus::MultipleReturn<int32_t, Invalid> TrackGetAllInfo(uint32_t sessionId, uint64_t trackId);
  int32_t Bookmark(uint32_t sessionId, uint8_t listType, uint8_t type, uint64_t id, std::string name);
  DBus::MultipleReturn<int32_t,
                       uint8_t,
                       uint64_t,
                       uint64_t,
                       uint32_t,
                       uint32_t> RequestPlaybackUpdateStatus(uint32_t sessionId);
  int32_t SelectFavourites(uint32_t sessionId,
                           uint8_t groupType,
                           uint64_t id,
                           std::tuple<std::vector<std::tuple<uint32_t, std::string>>> actions);
  int32_t DeleteBookmark(uint32_t sessionId, uint8_t listType, uint8_t type, uint64_t id, std::string name);
  DBus::MultipleReturn<int32_t,
                       int32_t,
                       std::tuple<std::vector<std::tuple<uint64_t, uint32_t, std::string>>>> StationGetListIdsAndNames(
      uint32_t sessionId,
      uint32_t parentId,
      uint32_t startPosition,
      uint32_t numberOfStations);
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> signal_SessionDestroyed();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         uint8_t,
                                         uint64_t,
                                         uint64_t,
                                         uint32_t,
                                         uint32_t)>> signal_PlaybackUpdateStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint8_t, uint64_t, uint8_t, uint64_t)>> signal_UpdateInfo();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint8_t, uint64_t)>> signal_UpdateList();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint8_t, std::string, uint32_t)>> signal_UpdateNotificationText();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         uint32_t,
                                         std::tuple<std::vector<std::string>>)>> signal_BookmarkList();
 protected:
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t,
                                                         std::tuple<std::vector<std::tuple<uint32_t, std::string>>>>()>>
      m_method_ListSessions;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, std::tuple<std::vector<std::string>>>(uint32_t)>>
      m_method_ListAttachedClients;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, std::string)>> m_method_AttachToSession;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, std::string)>> m_method_DetachFromSession;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint8_t, uint32_t)>> m_method_SetElapsedPolling;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, std::string>(uint32_t, uint8_t, uint64_t, uint32_t)>>
      m_method_GetResource;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t)>> m_method_ReleaseResource;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, int32_t, std::tuple<std::vector<uint64_t>>>(uint32_t,
                                                                                                              uint32_t,
                                                                                                              uint32_t,
                                                                                                              uint32_t)>>
      m_method_StationGetListId;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, Invalid>(uint32_t, uint64_t)>>
      m_method_StationGetAllInfo;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, Invalid>(uint32_t, uint64_t)>>
      m_method_TrackGetAllInfo;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint8_t, uint8_t, uint64_t, std::string)>> m_method_Bookmark;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint8_t, uint64_t, uint64_t, uint32_t, uint32_t>(
      uint32_t)>> m_method_RequestPlaybackUpdateStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t,
                                            uint8_t,
                                            uint64_t,
                                            std::tuple<std::vector<std::tuple<uint32_t, std::string>>>)>>
      m_method_SelectFavourites;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint8_t, uint8_t, uint64_t, std::string)>>
      m_method_DeleteBookmark;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t,
                                                         int32_t,
                                                         std::tuple<std::vector<std::tuple<uint64_t,
                                                                                           uint32_t,
                                                                                           std::string>>>>(uint32_t,
                                                                                                           uint32_t,
                                                                                                           uint32_t,
                                                                                                           uint32_t)>>
      m_method_StationGetListIdsAndNames;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> m_signalproxy_SessionDestroyed;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint8_t, uint64_t, uint64_t, uint32_t, uint32_t)>>
      m_signalproxy_PlaybackUpdateStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint8_t, uint64_t, uint8_t, uint64_t)>> m_signalproxy_UpdateInfo;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint8_t, uint64_t)>> m_signalproxy_UpdateList;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint8_t, std::string, uint32_t)>>
      m_signalproxy_UpdateNotificationText;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t, std::tuple<std::vector<std::string>>)>>
      m_signalproxy_BookmarkList;
};
#endif /* COM_JCI_OBS_STITCHER_HMIPROXY_H */
