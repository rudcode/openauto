#include "com_jci_navi2IHU_NaviFavoritesProxy.h"

com_jci_navi2IHU_NaviFavoritesProxy::com_jci_navi2IHU_NaviFavoritesProxy(std::string name)
    : DBus::InterfaceProxy(name) {
  m_method_AddFavorite = this->create_method<void(std::string,
                                                  std::string,
                                                  std::string,
                                                  std::string,
                                                  std::string,
                                                  std::string,
                                                  double,
                                                  double)>("AddFavorite");
  m_method_ReplaceFavoriteWithAddress = this->create_method<void(uint32_t,
                                                                 std::string,
                                                                 std::string,
                                                                 std::string,
                                                                 std::string,
                                                                 std::string,
                                                                 std::string,
                                                                 double,
                                                                 double)>("ReplaceFavoriteWithAddress");
  m_method_DeleteFavorite = this->create_method<void(uint32_t)>("DeleteFavorite");
  m_method_DeleteAllFavorites = this->create_method<void()>("DeleteAllFavorites");
  m_method_NavigateToFavorite = this->create_method<void(uint32_t)>("NavigateToFavorite");
  m_method_SetHome = this->create_method<void()>("SetHome");
  m_method_UnsetHome = this->create_method<void()>("UnsetHome");
  m_method_RenameFavorite = this->create_method<void(uint32_t, std::string)>("RenameFavorite");
  m_method_MoveFavorite = this->create_method<void(uint32_t, uint32_t)>("MoveFavorite");
  m_method_SwapFavorite = this->create_method<void(uint32_t, uint32_t)>("SwapFavorite");
  m_method_AddCurrentPositionToFavorites = this->create_method<void()>("AddCurrentPositionToFavorites");
  m_method_ReplaceFavoriteWithCurrentPosition =
      this->create_method<void(uint32_t)>("ReplaceFavoriteWithCurrentPosition");
  m_method_AddCurrentDestinationToFavorites = this->create_method<void()>("AddCurrentDestinationToFavorites");
  m_method_ReplaceFavoriteWithCurrentDestination =
      this->create_method<void(uint32_t)>("ReplaceFavoriteWithCurrentDestination");
  m_method_NavigatedRouteExists = this->create_method<int32_t()>("NavigatedRouteExists");
  m_method_GetFavoriteList = this->create_method < std::tuple < int32_t, std::vector < std::tuple
      < uint32_t, std::string>>>(int32_t, int32_t) > ("GetFavoriteList");
  m_method_GetFavoritesCount = this->create_method<int32_t()>("GetFavoritesCount");
  m_signalproxy_FavoriteButtonPressed = this->create_signal<void()>("FavoriteButtonPressed");
  m_signalproxy_FavoriteOperationResult = this->create_signal<void(int32_t)>("FavoriteOperationResult");

}
std::shared_ptr <com_jci_navi2IHU_NaviFavoritesProxy> com_jci_navi2IHU_NaviFavoritesProxy::create(std::string name) {
  return std::shared_ptr<com_jci_navi2IHU_NaviFavoritesProxy>(new com_jci_navi2IHU_NaviFavoritesProxy(name));

}
void com_jci_navi2IHU_NaviFavoritesProxy::AddFavorite(std::string name,
                                                      std::string countryName,
                                                      std::string stateName,
                                                      std::string cityName,
                                                      std::string streetName,
                                                      std::string zipCode,
                                                      double latitude,
                                                      double longitude) {
  (*m_method_AddFavorite)(name, countryName, stateName, cityName, streetName, zipCode, latitude, longitude);

}
void com_jci_navi2IHU_NaviFavoritesProxy::ReplaceFavoriteWithAddress(uint32_t iD,
                                                                     std::string name,
                                                                     std::string countryName,
                                                                     std::string stateName,
                                                                     std::string cityName,
                                                                     std::string streetName,
                                                                     std::string zipCode,
                                                                     double latitude,
                                                                     double longitude) {
  (*m_method_ReplaceFavoriteWithAddress)(iD,
                                         name,
                                         countryName,
                                         stateName,
                                         cityName,
                                         streetName,
                                         zipCode,
                                         latitude,
                                         longitude);

}
void com_jci_navi2IHU_NaviFavoritesProxy::DeleteFavorite(uint32_t iD) {
  (*m_method_DeleteFavorite)(iD);

}
void com_jci_navi2IHU_NaviFavoritesProxy::DeleteAllFavorites() {
  (*m_method_DeleteAllFavorites)();

}
void com_jci_navi2IHU_NaviFavoritesProxy::NavigateToFavorite(uint32_t iD) {
  (*m_method_NavigateToFavorite)(iD);

}
void com_jci_navi2IHU_NaviFavoritesProxy::SetHome() {
  (*m_method_SetHome)();

}
void com_jci_navi2IHU_NaviFavoritesProxy::UnsetHome() {
  (*m_method_UnsetHome)();

}
void com_jci_navi2IHU_NaviFavoritesProxy::RenameFavorite(uint32_t iD, std::string name) {
  (*m_method_RenameFavorite)(iD, name);

}
void com_jci_navi2IHU_NaviFavoritesProxy::MoveFavorite(uint32_t iD1, uint32_t iD2) {
  (*m_method_MoveFavorite)(iD1, iD2);

}
void com_jci_navi2IHU_NaviFavoritesProxy::SwapFavorite(uint32_t iD1, uint32_t iD2) {
  (*m_method_SwapFavorite)(iD1, iD2);

}
void com_jci_navi2IHU_NaviFavoritesProxy::AddCurrentPositionToFavorites() {
  (*m_method_AddCurrentPositionToFavorites)();

}
void com_jci_navi2IHU_NaviFavoritesProxy::ReplaceFavoriteWithCurrentPosition(uint32_t iD) {
  (*m_method_ReplaceFavoriteWithCurrentPosition)(iD);

}
void com_jci_navi2IHU_NaviFavoritesProxy::AddCurrentDestinationToFavorites() {
  (*m_method_AddCurrentDestinationToFavorites)();

}
void com_jci_navi2IHU_NaviFavoritesProxy::ReplaceFavoriteWithCurrentDestination(uint32_t iD) {
  (*m_method_ReplaceFavoriteWithCurrentDestination)(iD);

}
int32_t com_jci_navi2IHU_NaviFavoritesProxy::NavigatedRouteExists() {
  return (*m_method_NavigatedRouteExists)();

}
std::tuple <int32_t, std::vector<std::tuple < uint32_t, std::string>>>
com_jci_navi2IHU_NaviFavoritesProxy::GetFavoriteList(int32_t
startIndex,
int32_t maxItems
){
return (*m_method_GetFavoriteList)(startIndex,maxItems);

}
int32_t com_jci_navi2IHU_NaviFavoritesProxy::GetFavoritesCount() {
  return (*m_method_GetFavoritesCount)();

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_navi2IHU_NaviFavoritesProxy::signal_FavoriteButtonPressed() {
  return m_signalproxy_FavoriteButtonPressed;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_navi2IHU_NaviFavoritesProxy::signal_FavoriteOperationResult() {
  return m_signalproxy_FavoriteOperationResult;

}
