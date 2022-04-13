#ifndef COM_JCI_NAVI_IHUPROXY_H
#define COM_JCI_NAVI_IHUPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_navi2IHUProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_navi2IHUProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_navi2IHUProxy> create(std::string name = "com.jci.navi2IHU");
  void ShowNavigation();
  void ClearStack();
  void FavoriteLongPress();
  void NaviButtonPress();
  void NaviFocusStatusUpdate(int32_t status);
  void RequestShowNavigationDenied();
  int32_t DisplayXMServices(uint32_t screen);
  int32_t GetCurrentNaviState();
  void NavigateToAddress(std::string name,
                         std::string addressLine1,
                         std::string addressLine2,
                         std::string city,
                         std::string stateProvince,
                         std::string country,
                         std::string code,
                         double latitude,
                         double longitude);
  void SetLanguage(int32_t language);
  void SetLanguageEx(int32_t display_language,
                     bool vr_supported,
                     int32_t vr_language,
                     int32_t tts_language,
                     int32_t keyboard_language);
  void FactoryReset();
  void GetCurrentLocationInfo(bool locinfoneeded);
  bool GetVolumeScreenFocusStatus();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_NaviStateUpdate();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_ReadyToShowNavi();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_RequestShowNavigation();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_NaviButtonPressed();
  std::shared_ptr<DBus::SignalProxy<void(std::string, std::string)>> signal_DialPhoneNumber();
  std::shared_ptr<DBus::SignalProxy<void(std::string, double, double)>> signal_NaviconDestinationRequest();
  std::shared_ptr<DBus::SignalProxy<void(bool, int32_t)>> signal_LanguageChangeFinished();
  std::shared_ptr<DBus::SignalProxy<void(bool, int32_t, int32_t, int32_t, int32_t)>> signal_LanguageChangeFinishedEx();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_FactoryResetFinished();
  std::shared_ptr<DBus::SignalProxy<void(double,
                                         double,
                                         int32_t,
                                         int32_t,
                                         bool,
                                         double,
                                         bool,
                                         uint8_t)>> signal_CurrentLocationInfo();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_VolumeScreenFocusChanged();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_RequestScreenMode();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_ReadyToShowNaviEx();
 protected:
  std::shared_ptr<DBus::MethodProxy<void()>> m_method_ShowNavigation;
  std::shared_ptr<DBus::MethodProxy<void()>> m_method_ClearStack;
  std::shared_ptr<DBus::MethodProxy<void()>> m_method_FavoriteLongPress;
  std::shared_ptr<DBus::MethodProxy<void()>> m_method_NaviButtonPress;
  std::shared_ptr<DBus::MethodProxy<void(int32_t)>> m_method_NaviFocusStatusUpdate;
  std::shared_ptr<DBus::MethodProxy<void()>> m_method_RequestShowNavigationDenied;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_DisplayXMServices;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetCurrentNaviState;
  std::shared_ptr<DBus::MethodProxy<void(std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         double,
                                         double)>> m_method_NavigateToAddress;
  std::shared_ptr<DBus::MethodProxy<void(int32_t)>> m_method_SetLanguage;
  std::shared_ptr<DBus::MethodProxy<void(int32_t, bool, int32_t, int32_t, int32_t)>> m_method_SetLanguageEx;
  std::shared_ptr<DBus::MethodProxy<void()>> m_method_FactoryReset;
  std::shared_ptr<DBus::MethodProxy<void(bool)>> m_method_GetCurrentLocationInfo;
  std::shared_ptr<DBus::MethodProxy<bool()>> m_method_GetVolumeScreenFocusStatus;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_NaviStateUpdate;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_ReadyToShowNavi;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_RequestShowNavigation;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_NaviButtonPressed;
  std::shared_ptr<DBus::SignalProxy<void(std::string, std::string)>> m_signalproxy_DialPhoneNumber;
  std::shared_ptr<DBus::SignalProxy<void(std::string, double, double)>> m_signalproxy_NaviconDestinationRequest;
  std::shared_ptr<DBus::SignalProxy<void(bool, int32_t)>> m_signalproxy_LanguageChangeFinished;
  std::shared_ptr<DBus::SignalProxy<void(bool, int32_t, int32_t, int32_t, int32_t)>>
      m_signalproxy_LanguageChangeFinishedEx;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_FactoryResetFinished;
  std::shared_ptr<DBus::SignalProxy<void(double, double, int32_t, int32_t, bool, double, bool, uint8_t)>>
      m_signalproxy_CurrentLocationInfo;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_VolumeScreenFocusChanged;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_RequestScreenMode;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_ReadyToShowNaviEx;
};
#endif /* COM_JCI_NAVI_IHUPROXY_H */
