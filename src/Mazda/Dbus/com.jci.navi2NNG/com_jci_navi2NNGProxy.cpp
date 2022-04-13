#include "com_jci_navi2NNGProxy.h"

com_jci_navi2NNGProxy::com_jci_navi2NNGProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_GetVDELang = this->create_method<std::string()>("GetVDELang");
  m_method_GetTTSLang = this->create_method<int32_t()>("GetTTSLang");
  m_method_GetLanguage = this->create_method<int32_t()>("GetLanguage");
  m_method_GetVIN = this->create_method<std::string()>("GetVIN");
  m_method_GetRegionAndBranding =
      this->create_method<DBus::MultipleReturn<std::string, std::string>()>("GetRegionAndBranding");
  m_method_GetSpeedLimitSign = this->create_method<int32_t()>("GetSpeedLimitSign");
  m_method_GetSpeedLimitCaution = this->create_method<int32_t()>("GetSpeedLimitCaution");
  m_method_GetSpeedLimitCautionSpeed = this->create_method<int32_t()>("GetSpeedLimitCautionSpeed");
  m_method_GetTemperatureUnit = this->create_method<int32_t()>("GetTemperatureUnit");
  m_method_GetDayNightMode = this->create_method<int32_t()>("GetDayNightMode");
  m_method_GetTimeFormat = this->create_method<int32_t()>("GetTimeFormat");
  m_method_GetLengthUnit = this->create_method<int32_t()>("GetLengthUnit");
  m_method_GetPhoneConnectionStatus = this->create_method<int32_t()>("GetPhoneConnectionStatus");
  m_method_GetFuelType = this->create_method<int32_t()>("GetFuelType");
  m_method_GetNetworkConnectionStatus = this->create_method<int32_t()>("GetNetworkConnectionStatus");
  m_method_GetAvailableLayouts = this->create_method < std::tuple < int32_t, std::vector < std::tuple < int32_t>>>()
      > ("GetAvailableLayouts");
  m_method_GetKeyboardLayout = this->create_method<int32_t()>("GetKeyboardLayout");
  m_method_GetRecentKeyboardNumber = this->create_method<int32_t()>("GetRecentKeyboardNumber");
  m_method_GetSpeedRestriction = this->create_method<int32_t()>("GetSpeedRestriction");
  m_method_GetLocalizedRecentText = this->create_method<std::string()>("GetLocalizedRecentText");
  m_method_GetShowSpeedingSettingMenu = this->create_method<int32_t()>("GetShowSpeedingSettingMenu");
  m_method_GetHubType = this->create_method<int32_t()>("GetHubType");
  m_method_GetVolumeRequestEnabled = this->create_method<int32_t()>("GetVolumeRequestEnabled");
  m_method_GetNavigationVolume = this->create_method<int32_t()>("GetNavigationVolume");
  m_method_DialPhoneNumber = this->create_method<void(std::string, std::string)>("DialPhoneNumber");
  m_method_GetTimeMode = this->create_method < DBus::MultipleReturn < int32_t, uint64_t, std::tuple
      < int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t >> () > ("GetTimeMode");
  m_method_GetDRUnitStatus = this->create_method<DBus::MultipleReturn<bool, std::string>()>("GetDRUnitStatus");
  m_signalproxy_ShutdownRequest = this->create_signal<void()>("ShutdownRequest");
  m_signalproxy_FactoryReset = this->create_signal<void()>("FactoryReset");
  m_signalproxy_ShowNavigation = this->create_signal<void()>("ShowNavigation");
  m_signalproxy_ShowNaviScreen = this->create_signal<void(int32_t)>("ShowNaviScreen");
  m_signalproxy_RequestShowNavigationDenied = this->create_signal<void()>("RequestShowNavigationDenied");
  m_signalproxy_ClearStack = this->create_signal<void()>("ClearStack");
  m_signalproxy_FavoriteLongPress = this->create_signal<void()>("FavoriteLongPress");
  m_signalproxy_NaviButtonPress = this->create_signal<void()>("NaviButtonPress");
  m_signalproxy_GuiFocusStatusUpdate = this->create_signal<void(int32_t)>("GuiFocusStatusUpdate");
  m_signalproxy_AudioDone = this->create_signal<void(int32_t, int32_t)>("AudioDone");
  m_signalproxy_SetNavigationVolume = this->create_signal<void(int32_t)>("SetNavigationVolume");
  m_signalproxy_VREvent = this->create_signal<void(std::string)>("VREvent");
  m_signalproxy_SelectedListItem = this->create_signal<void(int32_t)>("SelectedListItem");
  m_signalproxy_NavigateToPOI =
      this->create_signal < void(std::tuple < int32_t, std::vector < std::tuple < std::string>>>)>("NavigateToPOI");
  m_signalproxy_AddWaypointPOI =
      this->create_signal < void(std::tuple < int32_t, std::vector < std::tuple < std::string>>>)>("AddWaypointPOI");
  m_signalproxy_JpjIntermediateHypothesis =
      this->create_signal<void(std::tuple < uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t > )>(
          "JpjIntermediateHypothesis");
  m_signalproxy_JpjVDEHypothesisList = this->create_signal < void(std::tuple < int32_t,
                                                                  std::vector < std::tuple < uint32_t,
                                                                  uint32_t,
                                                                  uint32_t,
                                                                  uint32_t,
                                                                  uint32_t,
                                                                  uint32_t>>>)>("JpjVDEHypothesisList");
  m_signalproxy_VDEHypothesisList = this->create_signal < void(std::tuple < int32_t,
                                                               std::vector < std::tuple < uint32_t,
                                                               uint32_t,
                                                               uint32_t,
                                                               uint32_t>>>)>("VDEHypothesisList");
  m_signalproxy_SimpleHypothesisList =
      this->create_signal < void(std::tuple < int32_t, std::vector < std::tuple < uint32_t>>>)>("SimpleHypothesisList");
  m_signalproxy_UniVDEHypothesisList = this->create_signal
      < void(std::tuple < int32_t, std::vector < std::tuple < std::string>>>)>("UniVDEHypothesisList");
  m_signalproxy_UniSimpleHypothesisList = this->create_signal
      < void(std::tuple < int32_t, std::vector < std::tuple < std::string>>>)>("UniSimpleHypothesisList");
  m_signalproxy_ModeChanged = this->create_signal<void(int32_t)>("ModeChanged");
  m_signalproxy_RequestGuidanceInfo = this->create_signal<void()>("RequestGuidanceInfo");
  m_signalproxy_NavigateToAddress = this->create_signal<void(std::string,
                                                             std::string,
                                                             std::string,
                                                             std::string,
                                                             std::string,
                                                             std::string,
                                                             double,
                                                             double)>("NavigateToAddress");
  m_signalproxy_DeleteFavorite = this->create_signal<void(uint32_t)>("DeleteFavorite");
  m_signalproxy_DeleteAllFavorites = this->create_signal<void()>("DeleteAllFavorites");
  m_signalproxy_NavigateToFavorite = this->create_signal<void(uint32_t)>("NavigateToFavorite");
  m_signalproxy_RenameFavorite = this->create_signal<void(uint32_t, std::string)>("RenameFavorite");
  m_signalproxy_SetHome = this->create_signal<void()>("SetHome");
  m_signalproxy_UnsetHome = this->create_signal<void()>("UnsetHome");
  m_signalproxy_SwapFavorites = this->create_signal<void(uint32_t, uint32_t)>("SwapFavorites");
  m_signalproxy_MoveFavorite = this->create_signal<void(uint32_t, uint32_t)>("MoveFavorite");
  m_signalproxy_AddCurrentPositionToFavorites = this->create_signal<void()>("AddCurrentPositionToFavorites");
  m_signalproxy_ReplaceFavoriteWithCurrentPosition =
      this->create_signal<void(uint32_t)>("ReplaceFavoriteWithCurrentPosition");
  m_signalproxy_AddCurrentDestinationToFavorites = this->create_signal<void()>("AddCurrentDestinationToFavorites");
  m_signalproxy_ReplaceFavoriteWithCurrentDestination =
      this->create_signal<void(uint32_t)>("ReplaceFavoriteWithCurrentDestination");
  m_signalproxy_AddFavorite = this->create_signal<void(std::string,
                                                       std::string,
                                                       std::string,
                                                       std::string,
                                                       std::string,
                                                       std::string,
                                                       double,
                                                       double)>("AddFavorite");
  m_signalproxy_ReplaceFavoriteWithAddress = this->create_signal<void(uint32_t,
                                                                      std::string,
                                                                      std::string,
                                                                      std::string,
                                                                      std::string,
                                                                      std::string,
                                                                      std::string,
                                                                      double,
                                                                      double)>("ReplaceFavoriteWithAddress");

}
std::shared_ptr <com_jci_navi2NNGProxy> com_jci_navi2NNGProxy::create(std::string name) {
  return std::shared_ptr<com_jci_navi2NNGProxy>(new com_jci_navi2NNGProxy(name));

}
std::string com_jci_navi2NNGProxy::GetVDELang() {
  return (*m_method_GetVDELang)();

}
int32_t com_jci_navi2NNGProxy::GetTTSLang() {
  return (*m_method_GetTTSLang)();

}
int32_t com_jci_navi2NNGProxy::GetLanguage() {
  return (*m_method_GetLanguage)();

}
std::string com_jci_navi2NNGProxy::GetVIN() {
  return (*m_method_GetVIN)();

}
DBus::MultipleReturn <std::string, std::string> com_jci_navi2NNGProxy::GetRegionAndBranding() {
  return (*m_method_GetRegionAndBranding)();

}
int32_t com_jci_navi2NNGProxy::GetSpeedLimitSign() {
  return (*m_method_GetSpeedLimitSign)();

}
int32_t com_jci_navi2NNGProxy::GetSpeedLimitCaution() {
  return (*m_method_GetSpeedLimitCaution)();

}
int32_t com_jci_navi2NNGProxy::GetSpeedLimitCautionSpeed() {
  return (*m_method_GetSpeedLimitCautionSpeed)();

}
int32_t com_jci_navi2NNGProxy::GetTemperatureUnit() {
  return (*m_method_GetTemperatureUnit)();

}
int32_t com_jci_navi2NNGProxy::GetDayNightMode() {
  return (*m_method_GetDayNightMode)();

}
int32_t com_jci_navi2NNGProxy::GetTimeFormat() {
  return (*m_method_GetTimeFormat)();

}
int32_t com_jci_navi2NNGProxy::GetLengthUnit() {
  return (*m_method_GetLengthUnit)();

}
int32_t com_jci_navi2NNGProxy::GetPhoneConnectionStatus() {
  return (*m_method_GetPhoneConnectionStatus)();

}
int32_t com_jci_navi2NNGProxy::GetFuelType() {
  return (*m_method_GetFuelType)();

}
int32_t com_jci_navi2NNGProxy::GetNetworkConnectionStatus() {
  return (*m_method_GetNetworkConnectionStatus)();

}
std::tuple <int32_t, std::vector<std::tuple < int32_t>>>
com_jci_navi2NNGProxy::GetAvailableLayouts() {
  return (*m_method_GetAvailableLayouts)();

}
int32_t com_jci_navi2NNGProxy::GetKeyboardLayout() {
  return (*m_method_GetKeyboardLayout)();

}
int32_t com_jci_navi2NNGProxy::GetRecentKeyboardNumber() {
  return (*m_method_GetRecentKeyboardNumber)();

}
int32_t com_jci_navi2NNGProxy::GetSpeedRestriction() {
  return (*m_method_GetSpeedRestriction)();

}
std::string com_jci_navi2NNGProxy::GetLocalizedRecentText() {
  return (*m_method_GetLocalizedRecentText)();

}
int32_t com_jci_navi2NNGProxy::GetShowSpeedingSettingMenu() {
  return (*m_method_GetShowSpeedingSettingMenu)();

}
int32_t com_jci_navi2NNGProxy::GetHubType() {
  return (*m_method_GetHubType)();

}
int32_t com_jci_navi2NNGProxy::GetVolumeRequestEnabled() {
  return (*m_method_GetVolumeRequestEnabled)();

}
int32_t com_jci_navi2NNGProxy::GetNavigationVolume() {
  return (*m_method_GetNavigationVolume)();

}
void com_jci_navi2NNGProxy::DialPhoneNumber(std::string phoneNumber, std::string name) {
  (*m_method_DialPhoneNumber)(phoneNumber, name);

}
DBus::MultipleReturn <int32_t, uint64_t, std::tuple<int16_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t>> com_jci_navi2NNGProxy::GetTimeMode() {
  return (*m_method_GetTimeMode)();

}
DBus::MultipleReturn<bool, std::string> com_jci_navi2NNGProxy::GetDRUnitStatus() {
  return (*m_method_GetDRUnitStatus)();

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_navi2NNGProxy::signal_ShutdownRequest() {
  return m_signalproxy_ShutdownRequest;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_navi2NNGProxy::signal_FactoryReset() {
  return m_signalproxy_FactoryReset;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_navi2NNGProxy::signal_ShowNavigation() {
  return m_signalproxy_ShowNavigation;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_navi2NNGProxy::signal_ShowNaviScreen() {
  return m_signalproxy_ShowNaviScreen;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_navi2NNGProxy::signal_RequestShowNavigationDenied() {
  return m_signalproxy_RequestShowNavigationDenied;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_navi2NNGProxy::signal_ClearStack() {
  return m_signalproxy_ClearStack;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_navi2NNGProxy::signal_FavoriteLongPress() {
  return m_signalproxy_FavoriteLongPress;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_navi2NNGProxy::signal_NaviButtonPress() {
  return m_signalproxy_NaviButtonPress;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_navi2NNGProxy::signal_GuiFocusStatusUpdate() {
  return m_signalproxy_GuiFocusStatusUpdate;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t, int32_t)>> com_jci_navi2NNGProxy::signal_AudioDone() {
  return m_signalproxy_AudioDone;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_navi2NNGProxy::signal_SetNavigationVolume() {
  return m_signalproxy_SetNavigationVolume;

}
std::shared_ptr <DBus::SignalProxy<void(std::string)>> com_jci_navi2NNGProxy::signal_VREvent() {
  return m_signalproxy_VREvent;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_navi2NNGProxy::signal_SelectedListItem() {
  return m_signalproxy_SelectedListItem;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < int32_t, std::vector < std::tuple < std::string>>>)>>
com_jci_navi2NNGProxy::signal_NavigateToPOI() {
  return m_signalproxy_NavigateToPOI;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < int32_t, std::vector < std::tuple < std::string>>>)>>
com_jci_navi2NNGProxy::signal_AddWaypointPOI() {
  return m_signalproxy_AddWaypointPOI;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t,
                                        uint32_t,
                                        uint32_t,
                                        uint32_t,
                                        uint32_t > )>> com_jci_navi2NNGProxy::signal_JpjIntermediateHypothesis() {
  return m_signalproxy_JpjIntermediateHypothesis;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < int32_t,
                                        std::vector < std::tuple < uint32_t,
                                        uint32_t,
                                        uint32_t,
                                        uint32_t,
                                        uint32_t,
                                        uint32_t>>>)>>
com_jci_navi2NNGProxy::signal_JpjVDEHypothesisList() {
  return m_signalproxy_JpjVDEHypothesisList;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < int32_t,
                                        std::vector < std::tuple < uint32_t,
                                        uint32_t,
                                        uint32_t,
                                        uint32_t>>>)>>
com_jci_navi2NNGProxy::signal_VDEHypothesisList() {
  return m_signalproxy_VDEHypothesisList;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < int32_t, std::vector < std::tuple < uint32_t>>>)>>
com_jci_navi2NNGProxy::signal_SimpleHypothesisList() {
  return m_signalproxy_SimpleHypothesisList;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < int32_t, std::vector < std::tuple < std::string>>>)>>
com_jci_navi2NNGProxy::signal_UniVDEHypothesisList() {
  return m_signalproxy_UniVDEHypothesisList;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < int32_t, std::vector < std::tuple < std::string>>>)>>
com_jci_navi2NNGProxy::signal_UniSimpleHypothesisList() {
  return m_signalproxy_UniSimpleHypothesisList;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_navi2NNGProxy::signal_ModeChanged() {
  return m_signalproxy_ModeChanged;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_navi2NNGProxy::signal_RequestGuidanceInfo() {
  return m_signalproxy_RequestGuidanceInfo;

}
std::shared_ptr <DBus::SignalProxy<void(std::string,
                                        std::string,
                                        std::string,
                                        std::string,
                                        std::string,
                                        std::string,
                                        double,
                                        double)>> com_jci_navi2NNGProxy::signal_NavigateToAddress() {
  return m_signalproxy_NavigateToAddress;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_navi2NNGProxy::signal_DeleteFavorite() {
  return m_signalproxy_DeleteFavorite;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_navi2NNGProxy::signal_DeleteAllFavorites() {
  return m_signalproxy_DeleteAllFavorites;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_navi2NNGProxy::signal_NavigateToFavorite() {
  return m_signalproxy_NavigateToFavorite;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, std::string)>> com_jci_navi2NNGProxy::signal_RenameFavorite() {
  return m_signalproxy_RenameFavorite;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_navi2NNGProxy::signal_SetHome() {
  return m_signalproxy_SetHome;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_navi2NNGProxy::signal_UnsetHome() {
  return m_signalproxy_UnsetHome;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, uint32_t)>> com_jci_navi2NNGProxy::signal_SwapFavorites() {
  return m_signalproxy_SwapFavorites;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, uint32_t)>> com_jci_navi2NNGProxy::signal_MoveFavorite() {
  return m_signalproxy_MoveFavorite;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_navi2NNGProxy::signal_AddCurrentPositionToFavorites() {
  return m_signalproxy_AddCurrentPositionToFavorites;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_navi2NNGProxy::signal_ReplaceFavoriteWithCurrentPosition() {
  return m_signalproxy_ReplaceFavoriteWithCurrentPosition;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_navi2NNGProxy::signal_AddCurrentDestinationToFavorites() {
  return m_signalproxy_AddCurrentDestinationToFavorites;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_navi2NNGProxy::signal_ReplaceFavoriteWithCurrentDestination() {
  return m_signalproxy_ReplaceFavoriteWithCurrentDestination;

}
std::shared_ptr <DBus::SignalProxy<void(std::string,
                                        std::string,
                                        std::string,
                                        std::string,
                                        std::string,
                                        std::string,
                                        double,
                                        double)>> com_jci_navi2NNGProxy::signal_AddFavorite() {
  return m_signalproxy_AddFavorite;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::string,
                                        std::string,
                                        std::string,
                                        std::string,
                                        std::string,
                                        std::string,
                                        double,
                                        double)>> com_jci_navi2NNGProxy::signal_ReplaceFavoriteWithAddress() {
  return m_signalproxy_ReplaceFavoriteWithAddress;

}
