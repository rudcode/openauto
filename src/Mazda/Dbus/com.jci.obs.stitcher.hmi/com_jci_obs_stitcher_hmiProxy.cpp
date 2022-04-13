#include "com_jci_obs_stitcher_hmiProxy.h"

com_jci_obs_stitcher_hmiProxy::com_jci_obs_stitcher_hmiProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_ListSessions = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector < std::tuple
      < uint32_t, std::string >> >> () > ("ListSessions");
  m_method_ListAttachedClients = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector
      < std::string>>>(uint32_t) > ("ListAttachedClients");
  m_method_AttachToSession = this->create_method<int32_t(uint32_t, std::string)>("AttachToSession");
  m_method_DetachFromSession = this->create_method<int32_t(uint32_t, std::string)>("DetachFromSession");
  m_method_SetElapsedPolling = this->create_method<int32_t(uint32_t, uint8_t, uint32_t)>("SetElapsedPolling");
  m_method_GetResource =
      this->create_method<DBus::MultipleReturn<int32_t, std::string>(uint32_t, uint8_t, uint64_t, uint32_t)>(
          "GetResource");
  m_method_ReleaseResource = this->create_method<int32_t(uint32_t, uint32_t)>("ReleaseResource");
  m_method_StationGetListId = this->create_method < DBus::MultipleReturn < int32_t, int32_t, std::tuple < std::vector
      < uint64_t>>>(uint32_t, uint32_t, uint32_t, uint32_t) > ("StationGetListId");
  m_method_StationGetAllInfo =
      this->create_method<DBus::MultipleReturn<int32_t, Invalid>(uint32_t, uint64_t)>("StationGetAllInfo");
  m_method_TrackGetAllInfo =
      this->create_method<DBus::MultipleReturn<int32_t, Invalid>(uint32_t, uint64_t)>("TrackGetAllInfo");
  m_method_Bookmark = this->create_method<int32_t(uint32_t, uint8_t, uint8_t, uint64_t, std::string)>("Bookmark");
  m_method_RequestPlaybackUpdateStatus =
      this->create_method<DBus::MultipleReturn<int32_t, uint8_t, uint64_t, uint64_t, uint32_t, uint32_t>(uint32_t)>(
          "RequestPlaybackUpdateStatus");
  m_method_SelectFavourites = this->create_method < int32_t(uint32_t,
                                                            uint8_t,
                                                            uint64_t,
                                                            std::tuple < std::vector < std::tuple < uint32_t,
                                                            std::string>>>)>("SelectFavourites");
  m_method_DeleteBookmark =
      this->create_method<int32_t(uint32_t, uint8_t, uint8_t, uint64_t, std::string)>("DeleteBookmark");
  m_method_StationGetListIdsAndNames = this->create_method < DBus::MultipleReturn < int32_t, int32_t, std::tuple
      < std::vector < std::tuple < uint64_t, uint32_t, std::string >> >> (uint32_t, uint32_t, uint32_t, uint32_t)
      > ("StationGetListIdsAndNames");
  m_signalproxy_SessionDestroyed = this->create_signal<void(uint32_t, uint32_t)>("SessionDestroyed");
  m_signalproxy_PlaybackUpdateStatus =
      this->create_signal<void(uint32_t, uint8_t, uint64_t, uint64_t, uint32_t, uint32_t)>("PlaybackUpdateStatus");
  m_signalproxy_UpdateInfo = this->create_signal<void(uint32_t, uint8_t, uint64_t, uint8_t, uint64_t)>("UpdateInfo");
  m_signalproxy_UpdateList = this->create_signal<void(uint32_t, uint8_t, uint64_t)>("UpdateList");
  m_signalproxy_UpdateNotificationText =
      this->create_signal<void(uint32_t, uint8_t, std::string, uint32_t)>("UpdateNotificationText");
  m_signalproxy_BookmarkList =
      this->create_signal<void(uint32_t, uint32_t, std::tuple < std::vector < std::string >> )>("BookmarkList");

}
std::shared_ptr <com_jci_obs_stitcher_hmiProxy> com_jci_obs_stitcher_hmiProxy::create(std::string name) {
  return std::shared_ptr<com_jci_obs_stitcher_hmiProxy>(new com_jci_obs_stitcher_hmiProxy(name));

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < std::tuple < uint32_t, std::string>>>>
com_jci_obs_stitcher_hmiProxy::ListSessions() {
  return (*m_method_ListSessions)();

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < std::string>>>
com_jci_obs_stitcher_hmiProxy::ListAttachedClients(uint32_t
sessionId ){
return (*m_method_ListAttachedClients)(sessionId);

}
int32_t com_jci_obs_stitcher_hmiProxy::AttachToSession(uint32_t
sessionId,
std::string clientName
){
return (*m_method_AttachToSession)(sessionId,clientName);

}
int32_t com_jci_obs_stitcher_hmiProxy::DetachFromSession(uint32_t
sessionId,
std::string clientName
){
return (*m_method_DetachFromSession)(sessionId,clientName);

}
int32_t com_jci_obs_stitcher_hmiProxy::SetElapsedPolling(uint32_t
sessionId,
uint8_t groupType, uint32_t
timeMs ){
return (*m_method_SetElapsedPolling)(sessionId,groupType,timeMs);

}
DBus::MultipleReturn <int32_t, std::string> com_jci_obs_stitcher_hmiProxy::GetResource(uint32_t
sessionId,
uint8_t groupType, uint64_t
groupId,
uint32_t resourceId
){
return (*m_method_GetResource)(sessionId,groupType,groupId,resourceId);

}
int32_t com_jci_obs_stitcher_hmiProxy::ReleaseResource(uint32_t
sessionId,
uint32_t resourceId
){
return (*m_method_ReleaseResource)(sessionId,resourceId);

}
DBus::MultipleReturn <int32_t, int32_t, std::tuple<std::vector < uint64_t>>>
com_jci_obs_stitcher_hmiProxy::StationGetListId(uint32_t
sessionId,
uint32_t parentId, uint32_t
startPosition,
uint32_t numberOfStations
){
return (*m_method_StationGetListId)(sessionId,parentId,startPosition,numberOfStations);

}
DBus::MultipleReturn <int32_t, Invalid> com_jci_obs_stitcher_hmiProxy::StationGetAllInfo(uint32_t
sessionId,
uint64_t stationId
){
return (*m_method_StationGetAllInfo)(sessionId,stationId);

}
DBus::MultipleReturn <int32_t, Invalid> com_jci_obs_stitcher_hmiProxy::TrackGetAllInfo(uint32_t
sessionId,
uint64_t trackId
){
return (*m_method_TrackGetAllInfo)(sessionId,trackId);

}
int32_t com_jci_obs_stitcher_hmiProxy::Bookmark(uint32_t
sessionId,
uint8_t listType, uint8_t
type,
uint64_t id, std::string
name ){
return (*m_method_Bookmark)(sessionId,listType,type,id,name);

}
DBus::MultipleReturn <int32_t, uint8_t, uint64_t, uint64_t, uint32_t, uint32_t>
    com_jci_obs_stitcher_hmiProxy::RequestPlaybackUpdateStatus(uint32_t
sessionId ){
return (*m_method_RequestPlaybackUpdateStatus)(sessionId);

}
int32_t com_jci_obs_stitcher_hmiProxy::SelectFavourites(uint32_t
sessionId,
uint8_t groupType, uint64_t
id, std::tuple <std::vector<std::tuple < uint32_t, std::string>>> actions ){
return (*m_method_SelectFavourites)(sessionId,groupType,id,actions);

}
int32_t com_jci_obs_stitcher_hmiProxy::DeleteBookmark(uint32_t
sessionId,
uint8_t listType, uint8_t
type,
uint64_t id, std::string
name ){
return (*m_method_DeleteBookmark)(sessionId,listType,type,id,name);

}
DBus::MultipleReturn <int32_t, int32_t, std::tuple<std::vector < std::tuple < uint64_t, uint32_t, std::string>>>>
com_jci_obs_stitcher_hmiProxy::StationGetListIdsAndNames(uint32_t
sessionId,
uint32_t parentId, uint32_t
startPosition,
uint32_t numberOfStations
){
return (*m_method_StationGetListIdsAndNames)(sessionId,parentId,startPosition,numberOfStations);

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, uint32_t)>> com_jci_obs_stitcher_hmiProxy::signal_SessionDestroyed() {
  return m_signalproxy_SessionDestroyed;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        uint8_t,
                                        uint64_t,
                                        uint64_t,
                                        uint32_t,
                                        uint32_t)>> com_jci_obs_stitcher_hmiProxy::signal_PlaybackUpdateStatus() {
  return m_signalproxy_PlaybackUpdateStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        uint8_t,
                                        uint64_t,
                                        uint8_t,
                                        uint64_t)>> com_jci_obs_stitcher_hmiProxy::signal_UpdateInfo() {
  return m_signalproxy_UpdateInfo;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        uint8_t,
                                        uint64_t)>> com_jci_obs_stitcher_hmiProxy::signal_UpdateList() {
  return m_signalproxy_UpdateList;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        uint8_t,
                                        std::string,
                                        uint32_t)>> com_jci_obs_stitcher_hmiProxy::signal_UpdateNotificationText() {
  return m_signalproxy_UpdateNotificationText;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        uint32_t,
                                        std::tuple < std::vector
                                            < std::string >> )>> com_jci_obs_stitcher_hmiProxy::signal_BookmarkList() {
  return m_signalproxy_BookmarkList;

}
