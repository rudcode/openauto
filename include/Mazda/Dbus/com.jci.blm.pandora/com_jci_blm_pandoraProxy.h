#ifndef COM_JCI_BLM_PANDORAPROXY_H
#define COM_JCI_BLM_PANDORAPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_blm_pandoraProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_blm_pandoraProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_blm_pandoraProxy> create(std::string name = "com.jci.blm.pandora");
  DBus::MultipleReturn<int32_t, uint32_t, bool> Connect();
  int32_t Disconnect(uint32_t sessionId);
  int32_t Command(uint32_t sessionId, uint8_t command, uint8_t groupType, uint64_t groupId);
  int32_t Rate(uint32_t sessionId, uint8_t groupType, uint64_t groupId, uint8_t rating);
  int32_t Bookmark(uint32_t sessionId, uint8_t groupType, uint64_t groupId, uint8_t bookmarkType);
  int32_t SetSort(uint32_t sessionId, uint8_t sortType);
  DBus::MultipleReturn<int32_t, std::string> GetResource(uint32_t sessionId, uint32_t resourceId);
  int32_t ReleaseResource(uint32_t sessionId, uint32_t resourceId);
  DBus::MultipleReturn<int32_t, uint8_t, uint8_t, uint8_t, uint64_t, uint64_t, uint32_t, uint32_t, uint32_t> GetStatus(
      uint32_t sessionId);
  DBus::MultipleReturn<int32_t,
                       std::string,
                       std::string,
                       std::string,
                       std::string,
                       uint32_t,
                       uint32_t,
                       uint32_t,
                       uint64_t,
                       uint8_t,
                       uint32_t> GetTrackAllInfo(uint32_t sessionId, uint64_t trackId);
  DBus::MultipleReturn<int32_t,
                       std::string,
                       std::string,
                       uint32_t,
                       uint32_t,
                       uint32_t> GetStationAllInfo(uint32_t sessionId, uint64_t stationId);
  DBus::MultipleReturn<int32_t,
                       uint32_t,
                       uint32_t,
                       uint32_t,
                       uint8_t,
                       std::tuple<std::vector<std::tuple<uint64_t, uint32_t, std::string>>>> GetStationListAllInfo(
      uint32_t sessionId,
      uint32_t startPosition,
      uint32_t numberOfStations);
  DBus::MultipleReturn<uint8_t, int32_t> GetGenreCategoryCount(uint32_t sessionId);
  DBus::MultipleReturn<uint8_t, std::tuple<std::vector<std::string>>, int32_t> GetGenreCategoryNames(uint32_t sessionId,
                                                                                                     uint8_t startPos,
                                                                                                     uint8_t count);
  DBus::MultipleReturn<std::tuple<std::vector<std::string>>, int32_t> GetAllGenreCategoryNames(uint32_t sessionId);
  DBus::MultipleReturn<uint8_t, uint8_t, int32_t> GetGenreStationCount(uint32_t sessionId, uint8_t categoryIndex);
  DBus::MultipleReturn<uint8_t,
                       uint8_t,
                       std::tuple<std::vector<std::tuple<uint64_t, std::string>>>,
                       int32_t> GetGenreStationIdsNames(uint32_t sessionId,
                                                        uint8_t categoryIndex,
                                                        uint8_t startPos,
                                                        uint8_t count);
  int32_t SelectGenreStation(uint32_t sessionId, uint8_t categoryIndex, uint8_t stationIndex);
  std::string GetListener(uint32_t sessionId);
  int32_t CreateStationFromCurrentTrack(uint32_t sessionId);
  int32_t CreateStationFromCurrentArtist(uint32_t sessionId);
  DBus::MultipleReturn<uint32_t, int32_t> GetSessionId();
  int32_t FavoritesAdd(uint32_t sessionId, uint64_t stationId);
  int32_t FavoritesRemove(uint32_t sessionId, uint64_t stationId);
  DBus::MultipleReturn<int32_t,
                       uint8_t,
                       uint8_t,
                       uint8_t,
                       std::tuple<std::vector<std::tuple<uint64_t,
                                                         uint32_t,
                                                         std::string>>>> FavoritesGet(uint32_t sessionId,
                                                                                      uint8_t startPosition,
                                                                                      uint8_t numberOfFavorites);
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, bool)>> signal_Connected();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint8_t)>> signal_Disconnected();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         uint8_t,
                                         uint8_t,
                                         uint64_t,
                                         uint64_t,
                                         uint32_t,
                                         uint32_t)>> signal_UpdateStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint8_t, uint64_t, uint8_t, uint64_t)>> signal_UpdateInfo();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint8_t)>> signal_UpdateSort();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint64_t)>> signal_UpdateList();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint64_t, uint64_t, uint32_t)>> signal_UpdateStationInfo();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint8_t, std::string)>> signal_UpdateNoticeText();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint64_t, uint64_t, std::string)>> signal_StationArtReady();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         uint64_t,
                                         uint8_t,
                                         uint8_t,
                                         std::string)>> signal_GenreStationArtReady();
 protected:
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t, bool>()>> m_method_Connect;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_Disconnect;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint8_t, uint8_t, uint64_t)>> m_method_Command;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint8_t, uint64_t, uint8_t)>> m_method_Rate;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint8_t, uint64_t, uint8_t)>> m_method_Bookmark;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint8_t)>> m_method_SetSort;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, std::string>(uint32_t, uint32_t)>>
      m_method_GetResource;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t)>> m_method_ReleaseResource;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t,
                                                         uint8_t,
                                                         uint8_t,
                                                         uint8_t,
                                                         uint64_t,
                                                         uint64_t,
                                                         uint32_t,
                                                         uint32_t,
                                                         uint32_t>(uint32_t)>> m_method_GetStatus;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t,
                                                         std::string,
                                                         std::string,
                                                         std::string,
                                                         std::string,
                                                         uint32_t,
                                                         uint32_t,
                                                         uint32_t,
                                                         uint64_t,
                                                         uint8_t,
                                                         uint32_t>(uint32_t, uint64_t)>> m_method_GetTrackAllInfo;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t,
                                                         std::string,
                                                         std::string,
                                                         uint32_t,
                                                         uint32_t,
                                                         uint32_t>(uint32_t, uint64_t)>> m_method_GetStationAllInfo;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t,
                                                         uint32_t,
                                                         uint32_t,
                                                         uint32_t,
                                                         uint8_t,
                                                         std::tuple<std::vector<std::tuple<uint64_t,
                                                                                           uint32_t,
                                                                                           std::string>>>>(uint32_t,
                                                                                                           uint32_t,
                                                                                                           uint32_t)>>
      m_method_GetStationListAllInfo;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint8_t, int32_t>(uint32_t)>> m_method_GetGenreCategoryCount;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint8_t, std::tuple<std::vector<std::string>>, int32_t>(
      uint32_t,
      uint8_t,
      uint8_t)>> m_method_GetGenreCategoryNames;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::tuple<std::vector<std::string>>, int32_t>(uint32_t)>>
      m_method_GetAllGenreCategoryNames;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint8_t, uint8_t, int32_t>(uint32_t, uint8_t)>>
      m_method_GetGenreStationCount;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint8_t,
                                                         uint8_t,
                                                         std::tuple<std::vector<std::tuple<uint64_t, std::string>>>,
                                                         int32_t>(uint32_t, uint8_t, uint8_t, uint8_t)>>
      m_method_GetGenreStationIdsNames;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint8_t, uint8_t)>> m_method_SelectGenreStation;
  std::shared_ptr<DBus::MethodProxy<std::string(uint32_t)>> m_method_GetListener;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_CreateStationFromCurrentTrack;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_CreateStationFromCurrentArtist;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, int32_t>()>> m_method_GetSessionId;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint64_t)>> m_method_FavoritesAdd;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint64_t)>> m_method_FavoritesRemove;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t,
                                                         uint8_t,
                                                         uint8_t,
                                                         uint8_t,
                                                         std::tuple<std::vector<std::tuple<uint64_t,
                                                                                           uint32_t,
                                                                                           std::string>>>>(uint32_t,
                                                                                                           uint8_t,
                                                                                                           uint8_t)>>
      m_method_FavoritesGet;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, bool)>> m_signalproxy_Connected;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint8_t)>> m_signalproxy_Disconnected;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint8_t, uint8_t, uint64_t, uint64_t, uint32_t, uint32_t)>>
      m_signalproxy_UpdateStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint8_t, uint64_t, uint8_t, uint64_t)>> m_signalproxy_UpdateInfo;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint8_t)>> m_signalproxy_UpdateSort;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint64_t)>> m_signalproxy_UpdateList;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint64_t, uint64_t, uint32_t)>> m_signalproxy_UpdateStationInfo;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint8_t, std::string)>> m_signalproxy_UpdateNoticeText;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint64_t, uint64_t, std::string)>> m_signalproxy_StationArtReady;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint64_t, uint8_t, uint8_t, std::string)>>
      m_signalproxy_GenreStationArtReady;
};
#endif /* COM_JCI_BLM_PANDORAPROXY_H */
