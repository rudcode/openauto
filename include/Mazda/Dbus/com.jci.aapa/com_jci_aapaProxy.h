#ifndef COM_JCI_AAPAPROXY_H
#define COM_JCI_AAPAPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_aapaProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_aapaProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_aapaProxy> create(std::string name = "com.jci.aapa");
  void MDSettingModeData(uint32_t selectMode);
  void VideoProjectionEventToMD(uint32_t videoProjectionEvent);
  void InputKey(uint32_t keyCode, bool absolute, int32_t step);
  void SetRouteState(uint32_t state);
  DBus::MultipleReturn<std::tuple<uint8_t, std::string, std::string, std::string, std::string>,
                       int32_t> GetNowPlayingInfo();
  void BTPairingResult(bool result);
  void BTReadyToPair(bool alreadyPaired);
  void SendBTAuthenticationData(std::string btdata, uint32_t len);
  void SetVehicleBtMacAddress(std::string macaddr, uint32_t maclen);
  void NotifyBTHFCallStatus(bool status, std::string macaddr);
  void IntentPhoneCall(std::string phonenumber);
  void DialogWinkStatus(bool status);
  void ClearLastFocus(std::tuple<bool, bool> focusInfo);
  void SbnStatus(bool status);
  DBus::MultipleReturn<bool, std::string, uint32_t> GetAOASessionStatus();
  uint8_t GetAvailable();
  std::tuple<int32_t> SetNativeTurnByTurnStatus(std::tuple<bool> setNativeTurnByTurnStatus);
  int32_t SetMP911EmergencyCallStatus(uint32_t status);
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_AOASessionStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::string)>> signal_SendSessionInfo();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_VideoProjectionRequestFromMD();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    std::string,
                                                    std::string,
                                                    std::string,
                                                    std::string>)>> signal_NowPlayingInfo();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_MDModeDisplayFirstDialog();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_DisplayReconnectingDialog();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_StartBtConnection();
  std::shared_ptr<DBus::SignalProxy<void(std::string, uint32_t, bool)>> signal_BTPairingRequest();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_GetVehicleBtMacAddress();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_NotifySpeedThreshold();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_DisplaySbnInfo();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_NotifyAudioFocusStatus();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_NotifyBTConnectionComplete();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_Available();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_NotifyStopAndSetup();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_NotifyNoVideoSinkSetup();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_NotifyDeviceNotResponding();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_NotifyASRStatus();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_ProjectionStatusResult();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_DisplayStopForSetupDialog();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_NotifyAANaviStatus();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_GetNativeTurnByTurnStatusRequest();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_NotifyDeviceConnection();
 protected:
  std::shared_ptr<DBus::MethodProxy<void(uint32_t)>> m_method_MDSettingModeData;
  std::shared_ptr<DBus::MethodProxy<void(uint32_t)>> m_method_VideoProjectionEventToMD;
  std::shared_ptr<DBus::MethodProxy<void(uint32_t, bool, int32_t)>> m_method_InputKey;
  std::shared_ptr<DBus::MethodProxy<void(uint32_t)>> m_method_SetRouteState;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::tuple<uint8_t,
                                                                    std::string,
                                                                    std::string,
                                                                    std::string,
                                                                    std::string>, int32_t>()>>
      m_method_GetNowPlayingInfo;
  std::shared_ptr<DBus::MethodProxy<void(bool)>> m_method_BTPairingResult;
  std::shared_ptr<DBus::MethodProxy<void(bool)>> m_method_BTReadyToPair;
  std::shared_ptr<DBus::MethodProxy<void(std::string, uint32_t)>> m_method_SendBTAuthenticationData;
  std::shared_ptr<DBus::MethodProxy<void(std::string, uint32_t)>> m_method_SetVehicleBtMacAddress;
  std::shared_ptr<DBus::MethodProxy<void(bool, std::string)>> m_method_NotifyBTHFCallStatus;
  std::shared_ptr<DBus::MethodProxy<void(std::string)>> m_method_IntentPhoneCall;
  std::shared_ptr<DBus::MethodProxy<void(bool)>> m_method_DialogWinkStatus;
  std::shared_ptr<DBus::MethodProxy<void(std::tuple<bool, bool>)>> m_method_ClearLastFocus;
  std::shared_ptr<DBus::MethodProxy<void(bool)>> m_method_SbnStatus;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<bool, std::string, uint32_t>()>> m_method_GetAOASessionStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetAvailable;
  std::shared_ptr<DBus::MethodProxy<std::tuple<int32_t>(std::tuple<bool>)>> m_method_SetNativeTurnByTurnStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_SetMP911EmergencyCallStatus;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_AOASessionStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::string)>> m_signalproxy_SendSessionInfo;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_VideoProjectionRequestFromMD;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, std::string, std::string, std::string, std::string>)>>
      m_signalproxy_NowPlayingInfo;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_MDModeDisplayFirstDialog;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_DisplayReconnectingDialog;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_StartBtConnection;
  std::shared_ptr<DBus::SignalProxy<void(std::string, uint32_t, bool)>> m_signalproxy_BTPairingRequest;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_GetVehicleBtMacAddress;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_NotifySpeedThreshold;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_DisplaySbnInfo;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_NotifyAudioFocusStatus;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_NotifyBTConnectionComplete;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_Available;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_NotifyStopAndSetup;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_NotifyNoVideoSinkSetup;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_NotifyDeviceNotResponding;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_NotifyASRStatus;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_ProjectionStatusResult;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_DisplayStopForSetupDialog;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_NotifyAANaviStatus;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_GetNativeTurnByTurnStatusRequest;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_NotifyDeviceConnection;
};
#endif /* COM_JCI_AAPAPROXY_H */
