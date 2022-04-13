#ifndef COM_JCI_NAVI_NNGPROXY_H
#define COM_JCI_NAVI_NNGPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_navi2NNGProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_navi2NNGProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_navi2NNGProxy> create(std::string name = "com.jci.navi2NNG");
  std::string GetVDELang();
  int32_t GetTTSLang();
  int32_t GetLanguage();
  std::string GetVIN();
  DBus::MultipleReturn<std::string, std::string> GetRegionAndBranding();
  int32_t GetSpeedLimitSign();
  int32_t GetSpeedLimitCaution();
  int32_t GetSpeedLimitCautionSpeed();
  int32_t GetTemperatureUnit();
  int32_t GetDayNightMode();
  int32_t GetTimeFormat();
  int32_t GetLengthUnit();
  int32_t GetPhoneConnectionStatus();
  int32_t GetFuelType();
  int32_t GetNetworkConnectionStatus();
  std::tuple<int32_t, std::vector<std::tuple<int32_t>>> GetAvailableLayouts();
  int32_t GetKeyboardLayout();
  int32_t GetRecentKeyboardNumber();
  int32_t GetSpeedRestriction();
  std::string GetLocalizedRecentText();
  int32_t GetShowSpeedingSettingMenu();
  int32_t GetHubType();
  int32_t GetVolumeRequestEnabled();
  int32_t GetNavigationVolume();
  void DialPhoneNumber(std::string phoneNumber, std::string name);
  DBus::MultipleReturn<int32_t,
                       uint64_t,
                       std::tuple<int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t>> GetTimeMode();
  DBus::MultipleReturn<bool, std::string> GetDRUnitStatus();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_ShutdownRequest();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_FactoryReset();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_ShowNavigation();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_ShowNaviScreen();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_RequestShowNavigationDenied();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_ClearStack();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_FavoriteLongPress();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_NaviButtonPress();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_GuiFocusStatusUpdate();
  std::shared_ptr<DBus::SignalProxy<void(int32_t, int32_t)>> signal_AudioDone();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_SetNavigationVolume();
  std::shared_ptr<DBus::SignalProxy<void(std::string)>> signal_VREvent();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_SelectedListItem();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t,
                                                    std::vector<std::tuple<std::string>>>)>> signal_NavigateToPOI();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t,
                                                    std::vector<std::tuple<std::string>>>)>> signal_AddWaypointPOI();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t,
                                                    uint32_t,
                                                    uint32_t,
                                                    uint32_t,
                                                    uint32_t,
                                                    uint32_t>)>> signal_JpjIntermediateHypothesis();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t,
                                                    std::vector<std::tuple<uint32_t,
                                                                           uint32_t,
                                                                           uint32_t,
                                                                           uint32_t,
                                                                           uint32_t,
                                                                           uint32_t>>>)>> signal_JpjVDEHypothesisList();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t,
                                                    std::vector<std::tuple<uint32_t,
                                                                           uint32_t,
                                                                           uint32_t,
                                                                           uint32_t>>>)>> signal_VDEHypothesisList();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t,
                                                    std::vector<std::tuple<uint32_t>>>)>> signal_SimpleHypothesisList();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t,
                                                    std::vector<std::tuple<std::string>>>)>> signal_UniVDEHypothesisList();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t,
                                                    std::vector<std::tuple<std::string>>>)>> signal_UniSimpleHypothesisList();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_ModeChanged();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_RequestGuidanceInfo();
  std::shared_ptr<DBus::SignalProxy<void(std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         double,
                                         double)>> signal_NavigateToAddress();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_DeleteFavorite();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_DeleteAllFavorites();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_NavigateToFavorite();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::string)>> signal_RenameFavorite();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_SetHome();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_UnsetHome();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> signal_SwapFavorites();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> signal_MoveFavorite();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_AddCurrentPositionToFavorites();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_ReplaceFavoriteWithCurrentPosition();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_AddCurrentDestinationToFavorites();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_ReplaceFavoriteWithCurrentDestination();
  std::shared_ptr<DBus::SignalProxy<void(std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         double,
                                         double)>> signal_AddFavorite();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         double,
                                         double)>> signal_ReplaceFavoriteWithAddress();
 protected:
  std::shared_ptr<DBus::MethodProxy<std::string()>> m_method_GetVDELang;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetTTSLang;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetLanguage;
  std::shared_ptr<DBus::MethodProxy<std::string()>> m_method_GetVIN;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::string, std::string>()>> m_method_GetRegionAndBranding;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetSpeedLimitSign;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetSpeedLimitCaution;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetSpeedLimitCautionSpeed;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetTemperatureUnit;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetDayNightMode;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetTimeFormat;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetLengthUnit;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetPhoneConnectionStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetFuelType;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetNetworkConnectionStatus;
  std::shared_ptr<DBus::MethodProxy<std::tuple<int32_t, std::vector<std::tuple<int32_t>>>()>>
      m_method_GetAvailableLayouts;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetKeyboardLayout;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetRecentKeyboardNumber;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetSpeedRestriction;
  std::shared_ptr<DBus::MethodProxy<std::string()>> m_method_GetLocalizedRecentText;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetShowSpeedingSettingMenu;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetHubType;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetVolumeRequestEnabled;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetNavigationVolume;
  std::shared_ptr<DBus::MethodProxy<void(std::string, std::string)>> m_method_DialPhoneNumber;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t,
                                                         uint64_t,
                                                         std::tuple<int16_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t>>()>> m_method_GetTimeMode;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<bool, std::string>()>> m_method_GetDRUnitStatus;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_ShutdownRequest;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_FactoryReset;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_ShowNavigation;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_ShowNaviScreen;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_RequestShowNavigationDenied;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_ClearStack;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_FavoriteLongPress;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_NaviButtonPress;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_GuiFocusStatusUpdate;
  std::shared_ptr<DBus::SignalProxy<void(int32_t, int32_t)>> m_signalproxy_AudioDone;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_SetNavigationVolume;
  std::shared_ptr<DBus::SignalProxy<void(std::string)>> m_signalproxy_VREvent;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_SelectedListItem;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t, std::vector<std::tuple<std::string>>>)>>
      m_signalproxy_NavigateToPOI;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t, std::vector<std::tuple<std::string>>>)>>
      m_signalproxy_AddWaypointPOI;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t>)>>
      m_signalproxy_JpjIntermediateHypothesis;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t,
                                                    std::vector<std::tuple<uint32_t,
                                                                           uint32_t,
                                                                           uint32_t,
                                                                           uint32_t,
                                                                           uint32_t,
                                                                           uint32_t>>>)>>
      m_signalproxy_JpjVDEHypothesisList;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t,
                                                    std::vector<std::tuple<uint32_t, uint32_t, uint32_t, uint32_t>>>)>>
      m_signalproxy_VDEHypothesisList;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t, std::vector<std::tuple<uint32_t>>>)>>
      m_signalproxy_SimpleHypothesisList;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t, std::vector<std::tuple<std::string>>>)>>
      m_signalproxy_UniVDEHypothesisList;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t, std::vector<std::tuple<std::string>>>)>>
      m_signalproxy_UniSimpleHypothesisList;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_ModeChanged;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_RequestGuidanceInfo;
  std::shared_ptr<DBus::SignalProxy<void(std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         double,
                                         double)>> m_signalproxy_NavigateToAddress;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_DeleteFavorite;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_DeleteAllFavorites;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_NavigateToFavorite;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::string)>> m_signalproxy_RenameFavorite;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_SetHome;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_UnsetHome;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> m_signalproxy_SwapFavorites;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> m_signalproxy_MoveFavorite;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_AddCurrentPositionToFavorites;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_ReplaceFavoriteWithCurrentPosition;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_AddCurrentDestinationToFavorites;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_ReplaceFavoriteWithCurrentDestination;
  std::shared_ptr<DBus::SignalProxy<void(std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         double,
                                         double)>> m_signalproxy_AddFavorite;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         double,
                                         double)>> m_signalproxy_ReplaceFavoriteWithAddress;
};
#endif /* COM_JCI_NAVI_NNGPROXY_H */
