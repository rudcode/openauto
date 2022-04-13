#include "com_jci_favProxy.h"

com_jci_favProxy::com_jci_favProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_GetFavoriteMax =
      this->create_method<DBus::MultipleReturn<int32_t, uint32_t, int32_t, int32_t, bool, uint32_t>(int32_t,
                                                                                                    uint32_t,
                                                                                                    uint32_t)>(
          "GetFavoriteMax");
  m_method_AddFavoriteRadio = this->create_method<DBus::MultipleReturn<int32_t, uint32_t, int32_t, bool>(int32_t,
                                                                                                         std::string,
                                                                                                         int32_t,
                                                                                                         uint32_t,
                                                                                                         double,
                                                                                                         std::string,
                                                                                                         uint16_t,
                                                                                                         uint32_t,
                                                                                                         uint8_t,
                                                                                                         uint8_t,
                                                                                                         uint8_t,
                                                                                                         uint8_t,
                                                                                                         std::string,
                                                                                                         std::tuple
                                                                                                             < std::string,
                                                                                                         uint16_t,
                                                                                                         uint16_t,
                                                                                                         uint8_t,
                                                                                                         std::string
                                                                                                             > )>(
      "AddFavoriteRadio");
  m_method_DeleteFavorite =
      this->create_method<DBus::MultipleReturn<int32_t, uint32_t>(int32_t, uint32_t, int32_t, uint32_t)>(
          "DeleteFavorite");
  m_method_MoveFavorite = this->create_method<DBus::MultipleReturn<int32_t, uint32_t>(int32_t,
                                                                                      uint32_t,
                                                                                      int32_t,
                                                                                      uint32_t,
                                                                                      int32_t,
                                                                                      int32_t)>("MoveFavorite");
  m_method_RenameFavorite =
      this->create_method<DBus::MultipleReturn<int32_t, uint32_t>(int32_t, uint32_t, int32_t, uint32_t, std::string)>(
          "RenameFavorite");
  m_method_GetFavoriteRadio = this->create_method < DBus::MultipleReturn
      < int32_t, int32_t, uint32_t, double, std::string, uint16_t, uint32_t, uint8_t, uint8_t, uint8_t, uint8_t, uint32_t,
      std::tuple < std::string, uint16_t, uint16_t, uint8_t, std::string >> (int32_t, int32_t) > ("GetFavoriteRadio");
  m_method_GetFavoriteList = this->create_method < DBus::MultipleReturn < int32_t, uint32_t, int32_t, int32_t, int32_t,
      std::tuple < std::vector < std::tuple < uint32_t, std::string, uint32_t, std::string, bool, std::string,
      std::string >> >> (int32_t, uint32_t, uint32_t, int32_t, int32_t) > ("GetFavoriteList");
  m_method_RenameTuneMixFavorite =
      this->create_method<DBus::MultipleReturn<int32_t, uint32_t>(int32_t, uint32_t, std::string)>(
          "RenameTuneMixFavorite");
  m_method_AddFavoriteComm = this->create_method<DBus::MultipleReturn<int32_t, uint32_t, int32_t, bool>(int32_t,
                                                                                                        std::string,
                                                                                                        int32_t,
                                                                                                        uint32_t,
                                                                                                        uint32_t,
                                                                                                        uint32_t,
                                                                                                        std::string,
                                                                                                        std::string)>(
      "AddFavoriteComm");
  m_method_GetFavoriteContactDetail =
      this->create_method < DBus::MultipleReturn < int32_t, int32_t, uint32_t, std::string, std::string, std::string,
      std::tuple < std::vector < std::tuple < uint32_t, std::string>>>,std::tuple
      < uint32_t, std::string, std::string, std::string, std::string, std::string >> (int32_t, int32_t, uint32_t)
      > ("GetFavoriteContactDetail");
  m_method_GetFavoriteComm = this->create_method<DBus::MultipleReturn<int32_t,
                                                                      int32_t,
                                                                      uint32_t,
                                                                      uint32_t,
                                                                      std::string,
                                                                      std::string,
                                                                      uint32_t>(int32_t, int32_t, uint32_t)>(
      "GetFavoriteComm");
  m_method_RadioFavoriteSeek = this->create_method < DBus::MultipleReturn
      < int32_t, int32_t, uint32_t, double, std::string, uint16_t, uint32_t, uint8_t, uint8_t, uint8_t, uint8_t, uint32_t,
      std::tuple < std::string, uint16_t, uint16_t, uint8_t
      >> (int32_t, uint32_t, double, uint32_t, uint8_t, int32_t, std::tuple < std::string, uint16_t, uint16_t, uint8_t,
          std::string >) > ("RadioFavoriteSeek");
  m_method_ReplaceFavoriteXMChannel =
      this->create_method<DBus::MultipleReturn<int32_t, uint32_t>(int32_t, std::string, uint8_t, uint8_t)>(
          "ReplaceFavoriteXMChannel");
  m_method_ReplaceFavoriteSXMChannel =
      this->create_method<DBus::MultipleReturn<int32_t, uint16_t, uint32_t>(int32_t, std::string, uint16_t, uint32_t)>(
          "ReplaceFavoriteSXMChannel");
  m_method_UpdateFromTunerStatus = this->create_method<uint32_t(std::tuple < uint8_t,
                                                                uint8_t,
                                                                uint8_t,
                                                                uint8_t,
                                                                uint8_t,
                                                                bool,
                                                                std::vector < uint8_t >> )>("UpdateFromTunerStatus");
  m_method_CurrentTunedChannelInfo = this->create_method<void(uint32_t,
                                                              bool,
                                                              double,
                                                              uint16_t,
                                                              uint32_t,
                                                              uint8_t,
                                                              std::tuple < std::string,
                                                              uint16_t,
                                                              uint16_t,
                                                              uint8_t > )>("CurrentTunedChannelInfo");
  m_method_RadioFastFavoriteSeek =
      this->create_method<DBus::MultipleReturn<int32_t, uint32_t>(int32_t, int32_t, uint32_t)>("RadioFastFavoriteSeek");
  m_method_GetFavoriteXMADAudio = this->create_method < DBus::MultipleReturn < int32_t, int32_t, std::tuple
      < std::vector < uint32_t>>>(int32_t) > ("GetFavoriteXMADAudio");
  m_method_DelXMADChannelFavID =
      this->create_method<DBus::MultipleReturn<uint32_t, uint32_t>(uint32_t)>("DelXMADChannelFavID");
  m_method_ShowSXMSFav =
      this->create_method<DBus::MultipleReturn<uint32_t, uint32_t>(uint32_t, uint32_t)>("ShowSXMSFav");
  m_method_SmartFavoritesImpactList =
      this->create_method<uint32_t(std::tuple < std::vector < uint32_t >> )>("SmartFavoritesImpactList");
  m_method_GetXMChipType = this->create_method<DBus::MultipleReturn<uint32_t, uint32_t>(uint32_t)>("GetXMChipType");
  m_method_GetTunemixactiveStatus =
      this->create_method<DBus::MultipleReturn<uint32_t, uint32_t>(uint32_t)>("GetTunemixactiveStatus");
  m_signalproxy_SeekStatusResp = this->create_signal<void(uint32_t, uint32_t)>("SeekStatusResp");
  m_signalproxy_FavRadioChangeEvent = this->create_signal<void(int32_t,
                                                               uint32_t,
                                                               double,
                                                               std::string,
                                                               uint16_t,
                                                               uint32_t,
                                                               uint8_t,
                                                               uint8_t,
                                                               uint8_t,
                                                               uint8_t,
                                                               uint32_t,
                                                               std::tuple < std::string,
                                                               uint16_t,
                                                               uint16_t,
                                                               uint8_t,
                                                               std::string > )>("FavRadioChangeEvent");
  m_signalproxy_SendActiveFavIdEvent = this->create_signal<void(uint32_t, bool)>("SendActiveFavIdEvent");
  m_signalproxy_SendFavInitStatusEvent = this->create_signal<void(bool)>("SendFavInitStatusEvent");
  m_signalproxy_XMADFavAddedEvent = this->create_signal<void(uint32_t)>("XMADFavAddedEvent");
  m_signalproxy_XMADFavDeletedEvent = this->create_signal<void(uint32_t)>("XMADFavDeletedEvent");
  m_signalproxy_SetSmartFavoritesImpactList =
      this->create_signal<void(std::tuple < std::vector < uint32_t >> )>("SetSmartFavoritesImpactList");
  m_signalproxy_XMChiptype = this->create_signal<void(uint32_t)>("XMChiptype");
  m_signalproxy_TuneMixActiveStatus = this->create_signal<void(bool)>("TuneMixActiveStatus");

}
std::shared_ptr <com_jci_favProxy> com_jci_favProxy::create(std::string name) {
  return std::shared_ptr<com_jci_favProxy>(new com_jci_favProxy(name));

}
DBus::MultipleReturn<int32_t, uint32_t, int32_t, int32_t, bool, uint32_t> com_jci_favProxy::GetFavoriteMax(int32_t requestId,
                                                                                                           uint32_t category,
                                                                                                           uint32_t deviceId) {
  return (*m_method_GetFavoriteMax)(requestId, category, deviceId);

}
DBus::MultipleReturn<int32_t, uint32_t, int32_t, bool> com_jci_favProxy::AddFavoriteRadio(int32_t requestId,
                                                                                          std::string displayText,
                                                                                          int32_t replaceFavId,
                                                                                          uint32_t stationType,
                                                                                          double frequency,
                                                                                          std::string stationName,
                                                                                          uint16_t piCode,
                                                                                          uint32_t hdSPS,
                                                                                          uint8_t xM_step,
                                                                                          uint8_t xM_category,
                                                                                          uint8_t xM_channel,
                                                                                          uint8_t xM_SID,
                                                                                          std::string relayName,
                                                                                          std::tuple <std::string, uint16_t, uint16_t, uint8_t, std::string> fav_dab_data) {
  return (*m_method_AddFavoriteRadio)(requestId,
                                      displayText,
                                      replaceFavId,
                                      stationType,
                                      frequency,
                                      stationName,
                                      piCode,
                                      hdSPS,
                                      xM_step,
                                      xM_category,
                                      xM_channel,
                                      xM_SID,
                                      relayName,
                                      fav_dab_data);

}
DBus::MultipleReturn <int32_t, uint32_t> com_jci_favProxy::DeleteFavorite(int32_t requestId,
                                                                          uint32_t category,
                                                                          int32_t favId,
                                                                          uint32_t deviceId) {
  return (*m_method_DeleteFavorite)(requestId, category, favId, deviceId);

}
DBus::MultipleReturn <int32_t, uint32_t> com_jci_favProxy::MoveFavorite(int32_t requestId,
                                                                        uint32_t category,
                                                                        int32_t favId,
                                                                        uint32_t deviceId,
                                                                        int32_t oldIndex,
                                                                        int32_t newIndex) {
  return (*m_method_MoveFavorite)(requestId, category, favId, deviceId, oldIndex, newIndex);

}
DBus::MultipleReturn <int32_t, uint32_t> com_jci_favProxy::RenameFavorite(int32_t requestId,
                                                                          uint32_t category,
                                                                          int32_t favId,
                                                                          uint32_t deviceId,
                                                                          std::string displayText) {
  return (*m_method_RenameFavorite)(requestId, category, favId, deviceId, displayText);

}
DBus::MultipleReturn<int32_t, int32_t, uint32_t, double, std::string, uint16_t, uint32_t, uint8_t, uint8_t, uint8_t, uint8_t, uint32_t, std::tuple<
    std::string,
    uint16_t,
    uint16_t,
    uint8_t,
    std::string>> com_jci_favProxy::GetFavoriteRadio(int32_t requestId, int32_t favId) {
  return (*m_method_GetFavoriteRadio)(requestId, favId);

}
DBus::MultipleReturn <int32_t, uint32_t, int32_t, int32_t, int32_t, std::tuple<std::vector < std::tuple < uint32_t,
                                                                               std::string,
                                                                               uint32_t,
                                                                               std::string,
                                                                               bool,
                                                                               std::string,
                                                                               std::string>>>>
com_jci_favProxy::GetFavoriteList(int32_t
requestId,
uint32_t category, uint32_t
deviceId,
int32_t startIndex, int32_t
maxItems ){
return (*m_method_GetFavoriteList)(requestId,category,deviceId,startIndex,maxItems);

}
DBus::MultipleReturn <int32_t, uint32_t> com_jci_favProxy::RenameTuneMixFavorite(int32_t
requestId,
uint32_t tuneMixID, std::string
displayText ){
return (*m_method_RenameTuneMixFavorite)(requestId,tuneMixID,displayText);

}
DBus::MultipleReturn<int32_t, uint32_t, int32_t, bool> com_jci_favProxy::AddFavoriteComm(int32_t
requestId,
std::string displayText, int32_t
replaceFavId,
uint32_t deviceId, uint32_t
contactId,
uint32_t contactType, std::string
contactName,
std::string phoneNumber
){
return (*m_method_AddFavoriteComm)(requestId,displayText,replaceFavId,deviceId,contactId,contactType,contactName,phoneNumber);

}
DBus::MultipleReturn <int32_t, int32_t, uint32_t, std::string, std::string, std::string, std::tuple<
    std::vector < std::tuple < uint32_t,
    std::string>>>,std::tuple <uint32_t, std::string, std::string, std::string, std::string, std::string>>
com_jci_favProxy::GetFavoriteContactDetail(int32_t
requestId,
int32_t favId, uint32_t
deviceId ){
return (*m_method_GetFavoriteContactDetail)(requestId,favId,deviceId);

}
DBus::MultipleReturn <int32_t, int32_t, uint32_t, uint32_t, std::string, std::string, uint32_t>
    com_jci_favProxy::GetFavoriteComm(int32_t
requestId,
int32_t favId, uint32_t
deviceId ){
return (*m_method_GetFavoriteComm)(requestId,favId,deviceId);

}
DBus::MultipleReturn<int32_t, int32_t, uint32_t, double, std::string, uint16_t, uint32_t, uint8_t, uint8_t, uint8_t, uint8_t, uint32_t, std::tuple<
    std::string,
    uint16_t,
    uint16_t,
    uint8_t>> com_jci_favProxy::RadioFavoriteSeek(int32_t
requestId,
uint32_t radioType,
double frequency, uint32_t
hdSPS,
uint8_t xM_channel, int32_t
button,
std::tuple <std::string, uint16_t, uint16_t, uint8_t, std::string> fav_dab_data
){
return (*m_method_RadioFavoriteSeek)(requestId,radioType,frequency,hdSPS,xM_channel,button,fav_dab_data);

}
DBus::MultipleReturn <int32_t, uint32_t> com_jci_favProxy::ReplaceFavoriteXMChannel(int32_t
requestId,
std::string stationName, uint8_t
xM_channel,
uint8_t xM_SID
){
return (*m_method_ReplaceFavoriteXMChannel)(requestId,stationName,xM_channel,xM_SID);

}
DBus::MultipleReturn <int32_t, uint16_t, uint32_t> com_jci_favProxy::ReplaceFavoriteSXMChannel(int32_t
requestId,
std::string stationName, uint16_t
xM_channel,
uint32_t xM_SID
){
return (*m_method_ReplaceFavoriteSXMChannel)(requestId,stationName,xM_channel,xM_SID);

}
uint32_t com_jci_favProxy::UpdateFromTunerStatus(std::tuple<uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, bool, std::vector<
    uint8_t>> tuner_status) {
  return (*m_method_UpdateFromTunerStatus)(tuner_status);

}
void com_jci_favProxy::CurrentTunedChannelInfo(uint32_t
radioType,
bool tuneStatus,
double frequency, uint16_t
piCode,
uint32_t hdSPS, uint8_t
xM_channel,
std::tuple <std::string, uint16_t, uint16_t, uint8_t> fav_dab_data
){
(*m_method_CurrentTunedChannelInfo)(radioType,tuneStatus,frequency,piCode,hdSPS,xM_channel,fav_dab_data);

}
DBus::MultipleReturn <int32_t, uint32_t> com_jci_favProxy::RadioFastFavoriteSeek(int32_t
requestId,
int32_t button, uint32_t
fimGroupAtKeyPressed ){
return (*m_method_RadioFastFavoriteSeek)(requestId,button,fimGroupAtKeyPressed);

}
DBus::MultipleReturn <int32_t, int32_t, std::tuple<std::vector < uint32_t>>>
com_jci_favProxy::GetFavoriteXMADAudio(int32_t
requestId ){
return (*m_method_GetFavoriteXMADAudio)(requestId);

}
DBus::MultipleReturn <uint32_t, uint32_t> com_jci_favProxy::DelXMADChannelFavID(uint32_t
xmChannelId ){
return (*m_method_DelXMADChannelFavID)(xmChannelId);

}
DBus::MultipleReturn <uint32_t, uint32_t> com_jci_favProxy::ShowSXMSFav(uint32_t
requestID,
uint32_t sXMSFavStatus
){
return (*m_method_ShowSXMSFav)(requestID,sXMSFavStatus);

}
uint32_t com_jci_favProxy::SmartFavoritesImpactList(std::tuple <std::vector<uint32_t>> chId_Arry) {
  return (*m_method_SmartFavoritesImpactList)(chId_Arry);

}
DBus::MultipleReturn <uint32_t, uint32_t> com_jci_favProxy::GetXMChipType(uint32_t
requestID ){
return (*m_method_GetXMChipType)(requestID);

}
DBus::MultipleReturn <uint32_t, uint32_t> com_jci_favProxy::GetTunemixactiveStatus(uint32_t
requestID ){
return (*m_method_GetTunemixactiveStatus)(requestID);

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, uint32_t)>> com_jci_favProxy::signal_SeekStatusResp() {
  return m_signalproxy_SeekStatusResp;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t,
                                        uint32_t,
                                        double,
                                        std::string,
                                        uint16_t,
                                        uint32_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint32_t,
                                        std::tuple < std::string,
                                        uint16_t,
                                        uint16_t,
                                        uint8_t,
                                        std::string > )>> com_jci_favProxy::signal_FavRadioChangeEvent() {
  return m_signalproxy_FavRadioChangeEvent;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, bool)>> com_jci_favProxy::signal_SendActiveFavIdEvent() {
  return m_signalproxy_SendActiveFavIdEvent;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_favProxy::signal_SendFavInitStatusEvent() {
  return m_signalproxy_SendFavInitStatusEvent;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_favProxy::signal_XMADFavAddedEvent() {
  return m_signalproxy_XMADFavAddedEvent;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_favProxy::signal_XMADFavDeletedEvent() {
  return m_signalproxy_XMADFavDeletedEvent;

}
std::shared_ptr <DBus::SignalProxy<void(
    std::tuple < std::vector < uint32_t >> )>> com_jci_favProxy::signal_SetSmartFavoritesImpactList() {
  return m_signalproxy_SetSmartFavoritesImpactList;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_favProxy::signal_XMChiptype() {
  return m_signalproxy_XMChiptype;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_favProxy::signal_TuneMixActiveStatus() {
  return m_signalproxy_TuneMixActiveStatus;

}
