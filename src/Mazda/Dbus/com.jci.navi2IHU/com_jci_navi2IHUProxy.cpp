#include "com_jci_navi2IHUProxy.h"

com_jci_navi2IHUProxy::com_jci_navi2IHUProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_ShowNavigation = this->create_method<void()>("ShowNavigation");
  m_method_ClearStack = this->create_method<void()>("ClearStack");
  m_method_FavoriteLongPress = this->create_method<void()>("FavoriteLongPress");
  m_method_NaviButtonPress = this->create_method<void()>("NaviButtonPress");
  m_method_NaviFocusStatusUpdate = this->create_method<void(int32_t)>("NaviFocusStatusUpdate");
  m_method_RequestShowNavigationDenied = this->create_method<void()>("RequestShowNavigationDenied");
  m_method_DisplayXMServices = this->create_method<int32_t(uint32_t)>("DisplayXMServices");
  m_method_GetCurrentNaviState = this->create_method<int32_t()>("GetCurrentNaviState");
  m_method_NavigateToAddress = this->create_method<void(std::string,
                                                        std::string,
                                                        std::string,
                                                        std::string,
                                                        std::string,
                                                        std::string,
                                                        std::string,
                                                        double,
                                                        double)>("NavigateToAddress");
  m_method_SetLanguage = this->create_method<void(int32_t)>("SetLanguage");
  m_method_SetLanguageEx = this->create_method<void(int32_t, bool, int32_t, int32_t, int32_t)>("SetLanguageEx");
  m_method_FactoryReset = this->create_method<void()>("FactoryReset");
  m_method_GetCurrentLocationInfo = this->create_method<void(bool)>("GetCurrentLocationInfo");
  m_method_GetVolumeScreenFocusStatus = this->create_method<bool()>("GetVolumeScreenFocusStatus");
  m_signalproxy_NaviStateUpdate = this->create_signal<void(int32_t)>("NaviStateUpdate");
  m_signalproxy_ReadyToShowNavi = this->create_signal<void()>("ReadyToShowNavi");
  m_signalproxy_RequestShowNavigation = this->create_signal<void()>("RequestShowNavigation");
  m_signalproxy_NaviButtonPressed = this->create_signal<void(int32_t)>("NaviButtonPressed");
  m_signalproxy_DialPhoneNumber = this->create_signal<void(std::string, std::string)>("DialPhoneNumber");
  m_signalproxy_NaviconDestinationRequest =
      this->create_signal<void(std::string, double, double)>("NaviconDestinationRequest");
  m_signalproxy_LanguageChangeFinished = this->create_signal<void(bool, int32_t)>("LanguageChangeFinished");
  m_signalproxy_LanguageChangeFinishedEx =
      this->create_signal<void(bool, int32_t, int32_t, int32_t, int32_t)>("LanguageChangeFinishedEx");
  m_signalproxy_FactoryResetFinished = this->create_signal<void(bool)>("FactoryResetFinished");
  m_signalproxy_CurrentLocationInfo =
      this->create_signal<void(double, double, int32_t, int32_t, bool, double, bool, uint8_t)>("CurrentLocationInfo");
  m_signalproxy_VolumeScreenFocusChanged = this->create_signal<void(bool)>("VolumeScreenFocusChanged");
  m_signalproxy_RequestScreenMode = this->create_signal<void(int32_t)>("RequestScreenMode");
  m_signalproxy_ReadyToShowNaviEx = this->create_signal<void(int32_t)>("ReadyToShowNaviEx");

}
std::shared_ptr <com_jci_navi2IHUProxy> com_jci_navi2IHUProxy::create(std::string name) {
  return std::shared_ptr<com_jci_navi2IHUProxy>(new com_jci_navi2IHUProxy(name));

}
void com_jci_navi2IHUProxy::ShowNavigation() {
  (*m_method_ShowNavigation)();

}
void com_jci_navi2IHUProxy::ClearStack() {
  (*m_method_ClearStack)();

}
void com_jci_navi2IHUProxy::FavoriteLongPress() {
  (*m_method_FavoriteLongPress)();

}
void com_jci_navi2IHUProxy::NaviButtonPress() {
  (*m_method_NaviButtonPress)();

}
void com_jci_navi2IHUProxy::NaviFocusStatusUpdate(int32_t status) {
  (*m_method_NaviFocusStatusUpdate)(status);

}
void com_jci_navi2IHUProxy::RequestShowNavigationDenied() {
  (*m_method_RequestShowNavigationDenied)();

}
int32_t com_jci_navi2IHUProxy::DisplayXMServices(uint32_t screen) {
  return (*m_method_DisplayXMServices)(screen);

}
int32_t com_jci_navi2IHUProxy::GetCurrentNaviState() {
  return (*m_method_GetCurrentNaviState)();

}
void com_jci_navi2IHUProxy::NavigateToAddress(std::string name,
                                              std::string addressLine1,
                                              std::string addressLine2,
                                              std::string city,
                                              std::string stateProvince,
                                              std::string country,
                                              std::string code,
                                              double latitude,
                                              double longitude) {
  (*m_method_NavigateToAddress)(name,
                                addressLine1,
                                addressLine2,
                                city,
                                stateProvince,
                                country,
                                code,
                                latitude,
                                longitude);

}
void com_jci_navi2IHUProxy::SetLanguage(int32_t language) {
  (*m_method_SetLanguage)(language);

}
void com_jci_navi2IHUProxy::SetLanguageEx(int32_t display_language,
                                          bool vr_supported,
                                          int32_t vr_language,
                                          int32_t tts_language,
                                          int32_t keyboard_language) {
  (*m_method_SetLanguageEx)(display_language, vr_supported, vr_language, tts_language, keyboard_language);

}
void com_jci_navi2IHUProxy::FactoryReset() {
  (*m_method_FactoryReset)();

}
void com_jci_navi2IHUProxy::GetCurrentLocationInfo(bool locinfoneeded) {
  (*m_method_GetCurrentLocationInfo)(locinfoneeded);

}
bool com_jci_navi2IHUProxy::GetVolumeScreenFocusStatus() {
  return (*m_method_GetVolumeScreenFocusStatus)();

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_navi2IHUProxy::signal_NaviStateUpdate() {
  return m_signalproxy_NaviStateUpdate;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_navi2IHUProxy::signal_ReadyToShowNavi() {
  return m_signalproxy_ReadyToShowNavi;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_navi2IHUProxy::signal_RequestShowNavigation() {
  return m_signalproxy_RequestShowNavigation;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_navi2IHUProxy::signal_NaviButtonPressed() {
  return m_signalproxy_NaviButtonPressed;

}
std::shared_ptr <DBus::SignalProxy<void(std::string, std::string)>> com_jci_navi2IHUProxy::signal_DialPhoneNumber() {
  return m_signalproxy_DialPhoneNumber;

}
std::shared_ptr <DBus::SignalProxy<void(std::string,
                                        double,
                                        double)>> com_jci_navi2IHUProxy::signal_NaviconDestinationRequest() {
  return m_signalproxy_NaviconDestinationRequest;

}
std::shared_ptr <DBus::SignalProxy<void(bool, int32_t)>> com_jci_navi2IHUProxy::signal_LanguageChangeFinished() {
  return m_signalproxy_LanguageChangeFinished;

}
std::shared_ptr <DBus::SignalProxy<void(bool,
                                        int32_t,
                                        int32_t,
                                        int32_t,
                                        int32_t)>> com_jci_navi2IHUProxy::signal_LanguageChangeFinishedEx() {
  return m_signalproxy_LanguageChangeFinishedEx;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_navi2IHUProxy::signal_FactoryResetFinished() {
  return m_signalproxy_FactoryResetFinished;

}
std::shared_ptr <DBus::SignalProxy<void(double,
                                        double,
                                        int32_t,
                                        int32_t,
                                        bool,
                                        double,
                                        bool,
                                        uint8_t)>> com_jci_navi2IHUProxy::signal_CurrentLocationInfo() {
  return m_signalproxy_CurrentLocationInfo;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_navi2IHUProxy::signal_VolumeScreenFocusChanged() {
  return m_signalproxy_VolumeScreenFocusChanged;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_navi2IHUProxy::signal_RequestScreenMode() {
  return m_signalproxy_RequestScreenMode;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_navi2IHUProxy::signal_ReadyToShowNaviEx() {
  return m_signalproxy_ReadyToShowNaviEx;

}
