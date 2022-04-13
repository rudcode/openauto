#include "com_jci_blm_pandoraProxy.h"

com_jci_blm_pandoraProxy::com_jci_blm_pandoraProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_Connect = this->create_method<DBus::MultipleReturn<int32_t, uint32_t, bool>()>("Connect");
  m_method_Disconnect = this->create_method<int32_t(uint32_t)>("Disconnect");
  m_method_Command = this->create_method<int32_t(uint32_t, uint8_t, uint8_t, uint64_t)>("Command");
  m_method_Rate = this->create_method<int32_t(uint32_t, uint8_t, uint64_t, uint8_t)>("Rate");
  m_method_Bookmark = this->create_method<int32_t(uint32_t, uint8_t, uint64_t, uint8_t)>("Bookmark");
  m_method_SetSort = this->create_method<int32_t(uint32_t, uint8_t)>("SetSort");
  m_method_GetResource =
      this->create_method<DBus::MultipleReturn<int32_t, std::string>(uint32_t, uint32_t)>("GetResource");
  m_method_ReleaseResource = this->create_method<int32_t(uint32_t, uint32_t)>("ReleaseResource");
  m_method_GetStatus = this->create_method<DBus::MultipleReturn<int32_t,
                                                                uint8_t,
                                                                uint8_t,
                                                                uint8_t,
                                                                uint64_t,
                                                                uint64_t,
                                                                uint32_t,
                                                                uint32_t,
                                                                uint32_t>(uint32_t)>("GetStatus");
  m_method_GetTrackAllInfo = this->create_method<DBus::MultipleReturn<int32_t,
                                                                      std::string,
                                                                      std::string,
                                                                      std::string,
                                                                      std::string,
                                                                      uint32_t,
                                                                      uint32_t,
                                                                      uint32_t,
                                                                      uint64_t,
                                                                      uint8_t,
                                                                      uint32_t>(uint32_t, uint64_t)>("GetTrackAllInfo");
  m_method_GetStationAllInfo = this->create_method<DBus::MultipleReturn<int32_t,
                                                                        std::string,
                                                                        std::string,
                                                                        uint32_t,
                                                                        uint32_t,
                                                                        uint32_t>(uint32_t, uint64_t)>(
      "GetStationAllInfo");
  m_method_GetStationListAllInfo =
      this->create_method < DBus::MultipleReturn < int32_t, uint32_t, uint32_t, uint32_t, uint8_t, std::tuple
      < std::vector < std::tuple < uint64_t, uint32_t, std::string >> >> (uint32_t, uint32_t, uint32_t)
      > ("GetStationListAllInfo");
  m_method_GetGenreCategoryCount =
      this->create_method<DBus::MultipleReturn<uint8_t, int32_t>(uint32_t)>("GetGenreCategoryCount");
  m_method_GetGenreCategoryNames = this->create_method < DBus::MultipleReturn < uint8_t, std::tuple < std::vector
      < std::string >>, int32_t > (uint32_t, uint8_t, uint8_t) > ("GetGenreCategoryNames");
  m_method_GetAllGenreCategoryNames =
      this->create_method < DBus::MultipleReturn < std::tuple < std::vector < std::string >>, int32_t > (uint32_t)
      > ("GetAllGenreCategoryNames");
  m_method_GetGenreStationCount =
      this->create_method<DBus::MultipleReturn<uint8_t, uint8_t, int32_t>(uint32_t, uint8_t)>("GetGenreStationCount");
  m_method_GetGenreStationIdsNames = this->create_method < DBus::MultipleReturn < uint8_t, uint8_t, std::tuple
      < std::vector < std::tuple < uint64_t, std::string>>>,int32_t > (uint32_t, uint8_t, uint8_t, uint8_t)
      > ("GetGenreStationIdsNames");
  m_method_SelectGenreStation = this->create_method<int32_t(uint32_t, uint8_t, uint8_t)>("SelectGenreStation");
  m_method_GetListener = this->create_method<std::string(uint32_t)>("GetListener");
  m_method_CreateStationFromCurrentTrack = this->create_method<int32_t(uint32_t)>("CreateStationFromCurrentTrack");
  m_method_CreateStationFromCurrentArtist = this->create_method<int32_t(uint32_t)>("CreateStationFromCurrentArtist");
  m_method_GetSessionId = this->create_method<DBus::MultipleReturn<uint32_t, int32_t>()>("GetSessionId");
  m_method_FavoritesAdd = this->create_method<int32_t(uint32_t, uint64_t)>("FavoritesAdd");
  m_method_FavoritesRemove = this->create_method<int32_t(uint32_t, uint64_t)>("FavoritesRemove");
  m_method_FavoritesGet = this->create_method < DBus::MultipleReturn < int32_t, uint8_t, uint8_t, uint8_t, std::tuple
      < std::vector < std::tuple < uint64_t, uint32_t, std::string >> >> (uint32_t, uint8_t, uint8_t)
      > ("FavoritesGet");
  m_signalproxy_Connected = this->create_signal<void(uint32_t, bool)>("Connected");
  m_signalproxy_Disconnected = this->create_signal<void(uint32_t, uint8_t)>("Disconnected");
  m_signalproxy_UpdateStatus =
      this->create_signal<void(uint32_t, uint8_t, uint8_t, uint64_t, uint64_t, uint32_t, uint32_t)>("UpdateStatus");
  m_signalproxy_UpdateInfo = this->create_signal<void(uint32_t, uint8_t, uint64_t, uint8_t, uint64_t)>("UpdateInfo");
  m_signalproxy_UpdateSort = this->create_signal<void(uint32_t, uint8_t)>("UpdateSort");
  m_signalproxy_UpdateList = this->create_signal<void(uint32_t, uint64_t)>("UpdateList");
  m_signalproxy_UpdateStationInfo =
      this->create_signal<void(uint32_t, uint64_t, uint64_t, uint32_t)>("UpdateStationInfo");
  m_signalproxy_UpdateNoticeText = this->create_signal<void(uint32_t, uint8_t, std::string)>("UpdateNoticeText");
  m_signalproxy_StationArtReady =
      this->create_signal<void(uint32_t, uint64_t, uint64_t, std::string)>("StationArtReady");
  m_signalproxy_GenreStationArtReady =
      this->create_signal<void(uint32_t, uint64_t, uint8_t, uint8_t, std::string)>("GenreStationArtReady");

}
std::shared_ptr <com_jci_blm_pandoraProxy> com_jci_blm_pandoraProxy::create(std::string name) {
  return std::shared_ptr<com_jci_blm_pandoraProxy>(new com_jci_blm_pandoraProxy(name));

}
DBus::MultipleReturn<int32_t, uint32_t, bool> com_jci_blm_pandoraProxy::Connect() {
  return (*m_method_Connect)();

}
int32_t com_jci_blm_pandoraProxy::Disconnect(uint32_t sessionId) {
  return (*m_method_Disconnect)(sessionId);

}
int32_t com_jci_blm_pandoraProxy::Command(uint32_t sessionId, uint8_t command, uint8_t groupType, uint64_t groupId) {
  return (*m_method_Command)(sessionId, command, groupType, groupId);

}
int32_t com_jci_blm_pandoraProxy::Rate(uint32_t sessionId, uint8_t groupType, uint64_t groupId, uint8_t rating) {
  return (*m_method_Rate)(sessionId, groupType, groupId, rating);

}
int32_t com_jci_blm_pandoraProxy::Bookmark(uint32_t sessionId,
                                           uint8_t groupType,
                                           uint64_t groupId,
                                           uint8_t bookmarkType) {
  return (*m_method_Bookmark)(sessionId, groupType, groupId, bookmarkType);

}
int32_t com_jci_blm_pandoraProxy::SetSort(uint32_t sessionId, uint8_t sortType) {
  return (*m_method_SetSort)(sessionId, sortType);

}
DBus::MultipleReturn <int32_t, std::string> com_jci_blm_pandoraProxy::GetResource(uint32_t sessionId,
                                                                                  uint32_t resourceId) {
  return (*m_method_GetResource)(sessionId, resourceId);

}
int32_t com_jci_blm_pandoraProxy::ReleaseResource(uint32_t sessionId, uint32_t resourceId) {
  return (*m_method_ReleaseResource)(sessionId, resourceId);

}
DBus::MultipleReturn <int32_t, uint8_t, uint8_t, uint8_t, uint64_t, uint64_t, uint32_t, uint32_t, uint32_t> com_jci_blm_pandoraProxy::GetStatus(
    uint32_t sessionId) {
  return (*m_method_GetStatus)(sessionId);

}
DBus::MultipleReturn <int32_t, std::string, std::string, std::string, std::string, uint32_t, uint32_t, uint32_t, uint64_t, uint8_t, uint32_t> com_jci_blm_pandoraProxy::GetTrackAllInfo(
    uint32_t sessionId,
    uint64_t trackId) {
  return (*m_method_GetTrackAllInfo)(sessionId, trackId);

}
DBus::MultipleReturn <int32_t, std::string, std::string, uint32_t, uint32_t, uint32_t> com_jci_blm_pandoraProxy::GetStationAllInfo(
    uint32_t sessionId,
    uint64_t stationId) {
  return (*m_method_GetStationAllInfo)(sessionId, stationId);

}
DBus::MultipleReturn <int32_t, uint32_t, uint32_t, uint32_t, uint8_t, std::tuple<std::vector < std::tuple < uint64_t,
                                                                                 uint32_t,
                                                                                 std::string>>>>
com_jci_blm_pandoraProxy::GetStationListAllInfo(uint32_t
sessionId,
uint32_t startPosition, uint32_t
numberOfStations ){
return (*m_method_GetStationListAllInfo)(sessionId,startPosition,numberOfStations);

}
DBus::MultipleReturn <uint8_t, int32_t> com_jci_blm_pandoraProxy::GetGenreCategoryCount(uint32_t
sessionId ){
return (*m_method_GetGenreCategoryCount)(sessionId);

}
DBus::MultipleReturn <uint8_t, std::tuple<std::vector < std::string>>,int32_t>
com_jci_blm_pandoraProxy::GetGenreCategoryNames(uint32_t
sessionId,
uint8_t startPos, uint8_t
count ){
return (*m_method_GetGenreCategoryNames)(sessionId,startPos,count);

}
DBus::MultipleReturn <std::tuple<std::vector < std::string>>,int32_t>
com_jci_blm_pandoraProxy::GetAllGenreCategoryNames(uint32_t
sessionId ){
return (*m_method_GetAllGenreCategoryNames)(sessionId);

}
DBus::MultipleReturn <uint8_t, uint8_t, int32_t> com_jci_blm_pandoraProxy::GetGenreStationCount(uint32_t
sessionId,
uint8_t categoryIndex
){
return (*m_method_GetGenreStationCount)(sessionId,categoryIndex);

}
DBus::MultipleReturn <uint8_t, uint8_t, std::tuple<std::vector < std::tuple < uint64_t, std::string>>>,int32_t>
com_jci_blm_pandoraProxy::GetGenreStationIdsNames(uint32_t
sessionId,
uint8_t categoryIndex, uint8_t
startPos,
uint8_t count
){
return (*m_method_GetGenreStationIdsNames)(sessionId,categoryIndex,startPos,count);

}
int32_t com_jci_blm_pandoraProxy::SelectGenreStation(uint32_t
sessionId,
uint8_t categoryIndex, uint8_t
stationIndex ){
return (*m_method_SelectGenreStation)(sessionId,categoryIndex,stationIndex);

}
std::string com_jci_blm_pandoraProxy::GetListener(uint32_t
sessionId ){
return (*m_method_GetListener)(sessionId);

}
int32_t com_jci_blm_pandoraProxy::CreateStationFromCurrentTrack(uint32_t
sessionId ){
return (*m_method_CreateStationFromCurrentTrack)(sessionId);

}
int32_t com_jci_blm_pandoraProxy::CreateStationFromCurrentArtist(uint32_t
sessionId ){
return (*m_method_CreateStationFromCurrentArtist)(sessionId);

}
DBus::MultipleReturn <uint32_t, int32_t> com_jci_blm_pandoraProxy::GetSessionId() {
  return (*m_method_GetSessionId)();

}
int32_t com_jci_blm_pandoraProxy::FavoritesAdd(uint32_t
sessionId,
uint64_t stationId
){
return (*m_method_FavoritesAdd)(sessionId,stationId);

}
int32_t com_jci_blm_pandoraProxy::FavoritesRemove(uint32_t
sessionId,
uint64_t stationId
){
return (*m_method_FavoritesRemove)(sessionId,stationId);

}
DBus::MultipleReturn <int32_t, uint8_t, uint8_t, uint8_t, std::tuple<std::vector < std::tuple < uint64_t,
                                                                     uint32_t,
                                                                     std::string>>>>
com_jci_blm_pandoraProxy::FavoritesGet(uint32_t
sessionId,
uint8_t startPosition, uint8_t
numberOfFavorites ){
return (*m_method_FavoritesGet)(sessionId,startPosition,numberOfFavorites);

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, bool)>> com_jci_blm_pandoraProxy::signal_Connected() {
  return m_signalproxy_Connected;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, uint8_t)>> com_jci_blm_pandoraProxy::signal_Disconnected() {
  return m_signalproxy_Disconnected;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        uint8_t,
                                        uint8_t,
                                        uint64_t,
                                        uint64_t,
                                        uint32_t,
                                        uint32_t)>> com_jci_blm_pandoraProxy::signal_UpdateStatus() {
  return m_signalproxy_UpdateStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        uint8_t,
                                        uint64_t,
                                        uint8_t,
                                        uint64_t)>> com_jci_blm_pandoraProxy::signal_UpdateInfo() {
  return m_signalproxy_UpdateInfo;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, uint8_t)>> com_jci_blm_pandoraProxy::signal_UpdateSort() {
  return m_signalproxy_UpdateSort;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, uint64_t)>> com_jci_blm_pandoraProxy::signal_UpdateList() {
  return m_signalproxy_UpdateList;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        uint64_t,
                                        uint64_t,
                                        uint32_t)>> com_jci_blm_pandoraProxy::signal_UpdateStationInfo() {
  return m_signalproxy_UpdateStationInfo;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        uint8_t,
                                        std::string)>> com_jci_blm_pandoraProxy::signal_UpdateNoticeText() {
  return m_signalproxy_UpdateNoticeText;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        uint64_t,
                                        uint64_t,
                                        std::string)>> com_jci_blm_pandoraProxy::signal_StationArtReady() {
  return m_signalproxy_StationArtReady;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        uint64_t,
                                        uint8_t,
                                        uint8_t,
                                        std::string)>> com_jci_blm_pandoraProxy::signal_GenreStationArtReady() {
  return m_signalproxy_GenreStationArtReady;

}
