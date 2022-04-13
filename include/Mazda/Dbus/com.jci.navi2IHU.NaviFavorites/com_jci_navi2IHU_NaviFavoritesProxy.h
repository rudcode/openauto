#ifndef COM_JCI_NAVI_IHU_NAVIFAVORITESPROXY_H
#define COM_JCI_NAVI_IHU_NAVIFAVORITESPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_navi2IHU_NaviFavoritesProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_navi2IHU_NaviFavoritesProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_navi2IHU_NaviFavoritesProxy> create(std::string name = "com.jci.navi2IHU.NaviFavorites");
  void AddFavorite(std::string name,
                   std::string countryName,
                   std::string stateName,
                   std::string cityName,
                   std::string streetName,
                   std::string zipCode,
                   double latitude,
                   double longitude);
  void ReplaceFavoriteWithAddress(uint32_t iD,
                                  std::string name,
                                  std::string countryName,
                                  std::string stateName,
                                  std::string cityName,
                                  std::string streetName,
                                  std::string zipCode,
                                  double latitude,
                                  double longitude);
  void DeleteFavorite(uint32_t iD);
  void DeleteAllFavorites();
  void NavigateToFavorite(uint32_t iD);
  void SetHome();
  void UnsetHome();
  void RenameFavorite(uint32_t iD, std::string name);
  void MoveFavorite(uint32_t iD1, uint32_t iD2);
  void SwapFavorite(uint32_t iD1, uint32_t iD2);
  void AddCurrentPositionToFavorites();
  void ReplaceFavoriteWithCurrentPosition(uint32_t iD);
  void AddCurrentDestinationToFavorites();
  void ReplaceFavoriteWithCurrentDestination(uint32_t iD);
  int32_t NavigatedRouteExists();
  std::tuple<int32_t, std::vector<std::tuple<uint32_t, std::string>>> GetFavoriteList(int32_t startIndex,
                                                                                      int32_t maxItems);
  int32_t GetFavoritesCount();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_FavoriteButtonPressed();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_FavoriteOperationResult();
 protected:
  std::shared_ptr<DBus::MethodProxy<void(std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         double,
                                         double)>> m_method_AddFavorite;
  std::shared_ptr<DBus::MethodProxy<void(uint32_t,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         double,
                                         double)>> m_method_ReplaceFavoriteWithAddress;
  std::shared_ptr<DBus::MethodProxy<void(uint32_t)>> m_method_DeleteFavorite;
  std::shared_ptr<DBus::MethodProxy<void()>> m_method_DeleteAllFavorites;
  std::shared_ptr<DBus::MethodProxy<void(uint32_t)>> m_method_NavigateToFavorite;
  std::shared_ptr<DBus::MethodProxy<void()>> m_method_SetHome;
  std::shared_ptr<DBus::MethodProxy<void()>> m_method_UnsetHome;
  std::shared_ptr<DBus::MethodProxy<void(uint32_t, std::string)>> m_method_RenameFavorite;
  std::shared_ptr<DBus::MethodProxy<void(uint32_t, uint32_t)>> m_method_MoveFavorite;
  std::shared_ptr<DBus::MethodProxy<void(uint32_t, uint32_t)>> m_method_SwapFavorite;
  std::shared_ptr<DBus::MethodProxy<void()>> m_method_AddCurrentPositionToFavorites;
  std::shared_ptr<DBus::MethodProxy<void(uint32_t)>> m_method_ReplaceFavoriteWithCurrentPosition;
  std::shared_ptr<DBus::MethodProxy<void()>> m_method_AddCurrentDestinationToFavorites;
  std::shared_ptr<DBus::MethodProxy<void(uint32_t)>> m_method_ReplaceFavoriteWithCurrentDestination;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_NavigatedRouteExists;
  std::shared_ptr<DBus::MethodProxy<std::tuple<int32_t, std::vector<std::tuple<uint32_t, std::string>>>(int32_t,
                                                                                                        int32_t)>>
      m_method_GetFavoriteList;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetFavoritesCount;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_FavoriteButtonPressed;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_FavoriteOperationResult;
};
#endif /* COM_JCI_NAVI_IHU_NAVIFAVORITESPROXY_H */
