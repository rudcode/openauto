#ifndef COM_JCI_CARPLAYPROXY_H
#define COM_JCI_CARPLAYPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_carplayProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_carplayProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_carplayProxy> create(std::string name = "com.jci.carplay");
  std::tuple<uint32_t> PressKey(std::tuple<uint32_t, bool> pressKey);
  std::tuple<uint32_t> RotateKnob(std::tuple<uint32_t> rotateKnob);
  std::tuple<uint32_t> PanKnob(std::tuple<uint32_t> panKnob);
  std::tuple<uint32_t> SiriLaunch(std::tuple<uint32_t> siriLaunch);
  std::tuple<uint32_t> TouchScreen(std::tuple<uint16_t, uint16_t, bool> touchScreen);
  std::tuple<uint32_t> DisableTouchScreenCoordinate(std::tuple<uint32_t,
                                                               uint32_t,
                                                               uint32_t,
                                                               uint32_t> disableTouchScreenCoordinate);
  std::tuple<uint32_t> SelectDevice(std::tuple<uint32_t> selectDevice);
  std::tuple<uint32_t> ScreenResourceAvailable(std::tuple<uint32_t, uint32_t> screenResourceAvailable);
  std::tuple<uint32_t> ScreenAcquireResource(std::tuple<uint32_t> screenAcquireResource);
  std::tuple<uint32_t> SetCurrentNativeScreen(std::tuple<uint32_t> setCurrentNativeScreen);
  std::tuple<uint32_t> SetTurnByTurnStatus(std::tuple<bool> setTurnByTurnStatus);
  std::tuple<uint32_t> SetPhoneCallStatus(std::tuple<bool> setPhoneCallStatus);
  std::tuple<uint32_t> SetNotifyAudioStreamState(std::tuple<bool> setNotifyAudioStreamState);
  void AcceptCallRequest();
  Invalid GetNowPlayingInfo();
  Invalid GetConnectDeviceInfo();
  uint32_t SetVehicleBtMacAddress(std::string vehicleBtMacAddress, uint32_t vehicleBtMacAddressLength);
  std::tuple<uint32_t> ClearLastFocus(std::tuple<bool, bool> clearLastFocus);
  std::tuple<uint32_t> EnableCarPlayConnection(std::tuple<std::string, uint32_t, bool> enableCarPlayConnection);
  std::tuple<uint32_t> DisplayDialogResponse(std::tuple<uint32_t> displayDialogResponse);
  std::tuple<uint32_t> UpdateBTAudioStatus(std::tuple<uint32_t> updateBTAudioStatusInfo);
  std::tuple<uint32_t> MethodCallClientDial(std::tuple<std::string, uint32_t, uint32_t> methodCallClientDial);
  std::tuple<uint32_t> MethodCancelClientDial(std::tuple<uint32_t> methodCancelClientDial);
  int32_t SetMP911EmergencyCallStatus(uint32_t status);
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::string>)>> signal_DisableBluetoothSignal();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint64_t, uint32_t>)>> signal_SessionActiveSignal();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_GetCurrentNativeScreenRequestSignal();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint64_t, uint32_t>)>> signal_DeviceErrorSignal();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint64_t>)>> signal_SessionDeactiveSignal();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t>)>> signal_NativeUILaunchSignal();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_ScreenResourceRequestSignal();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t>)>> signal_ScreenResourceRequestTimeoutSignal();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_NativeScreenDisplayRequestSignal();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_GetTurnByTurnStatusRequestSignal();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t>)>> signal_TurnByTurnEntitySignal();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_GetPhoneCallStatusRequestSignal();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::string,
                                                    std::string,
                                                    uint32_t,
                                                    uint32_t,
                                                    std::string,
                                                    std::string,
                                                    std::string>)>> signal_UpdateCallStatusInfoSignal();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t>)>> signal_SpeechEntitySignal();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::tuple<std::string,
                                                               std::string,
                                                               std::string,
                                                               std::string,
                                                               std::string>>)>> signal_UpdateNowPlayingInfoSignal();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_GetVehicleBtMacAddress();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t>)>> signal_FeatureAvailableSignal();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t,
                                                    std::string,
                                                    std::string,
                                                    uint32_t>)>> signal_DisplayDialogSignal();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t>)>> signal_UpdateAudioStatusSignal();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_DisconnectedDeviceSignal();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> signal_UsbPortStatusSignal();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint64_t, bool, bool>)>> signal_ClientConnectedSignal();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint64_t>)>> signal_ClientDisconnectedSignal();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint64_t, bool>)>> signal_ScreenResourceReadySignal();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t>)>> signal_DisplayDialogResponseSignal();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t>)>> signal_UsbErrorStatusSignal();
 protected:
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t>(std::tuple<uint32_t, bool>)>> m_method_PressKey;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t>(std::tuple<uint32_t>)>> m_method_RotateKnob;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t>(std::tuple<uint32_t>)>> m_method_PanKnob;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t>(std::tuple<uint32_t>)>> m_method_SiriLaunch;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t>(std::tuple<uint16_t, uint16_t, bool>)>> m_method_TouchScreen;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t>(std::tuple<uint32_t, uint32_t, uint32_t, uint32_t>)>>
      m_method_DisableTouchScreenCoordinate;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t>(std::tuple<uint32_t>)>> m_method_SelectDevice;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t>(std::tuple<uint32_t, uint32_t>)>>
      m_method_ScreenResourceAvailable;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t>(std::tuple<uint32_t>)>> m_method_ScreenAcquireResource;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t>(std::tuple<uint32_t>)>> m_method_SetCurrentNativeScreen;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t>(std::tuple<bool>)>> m_method_SetTurnByTurnStatus;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t>(std::tuple<bool>)>> m_method_SetPhoneCallStatus;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t>(std::tuple<bool>)>> m_method_SetNotifyAudioStreamState;
  std::shared_ptr<DBus::MethodProxy<void()>> m_method_AcceptCallRequest;
  std::shared_ptr<DBus::MethodProxy<Invalid()>> m_method_GetNowPlayingInfo;
  std::shared_ptr<DBus::MethodProxy<Invalid()>> m_method_GetConnectDeviceInfo;
  std::shared_ptr<DBus::MethodProxy<uint32_t(std::string, uint32_t)>> m_method_SetVehicleBtMacAddress;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t>(std::tuple<bool, bool>)>> m_method_ClearLastFocus;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t>(std::tuple<std::string, uint32_t, bool>)>>
      m_method_EnableCarPlayConnection;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t>(std::tuple<uint32_t>)>> m_method_DisplayDialogResponse;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t>(std::tuple<uint32_t>)>> m_method_UpdateBTAudioStatus;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t>(std::tuple<std::string, uint32_t, uint32_t>)>>
      m_method_MethodCallClientDial;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t>(std::tuple<uint32_t>)>> m_method_MethodCancelClientDial;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_SetMP911EmergencyCallStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::string>)>> m_signalproxy_DisableBluetoothSignal;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint64_t, uint32_t>)>> m_signalproxy_SessionActiveSignal;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_GetCurrentNativeScreenRequestSignal;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint64_t, uint32_t>)>> m_signalproxy_DeviceErrorSignal;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint64_t>)>> m_signalproxy_SessionDeactiveSignal;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t>)>> m_signalproxy_NativeUILaunchSignal;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_ScreenResourceRequestSignal;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t>)>> m_signalproxy_ScreenResourceRequestTimeoutSignal;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_NativeScreenDisplayRequestSignal;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_GetTurnByTurnStatusRequestSignal;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t>)>> m_signalproxy_TurnByTurnEntitySignal;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_GetPhoneCallStatusRequestSignal;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::string,
                                                    std::string,
                                                    uint32_t,
                                                    uint32_t,
                                                    std::string,
                                                    std::string,
                                                    std::string>)>> m_signalproxy_UpdateCallStatusInfoSignal;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t>)>> m_signalproxy_SpeechEntitySignal;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::tuple<std::string,
                                                               std::string,
                                                               std::string,
                                                               std::string,
                                                               std::string>>)>>
      m_signalproxy_UpdateNowPlayingInfoSignal;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_GetVehicleBtMacAddress;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t>)>> m_signalproxy_FeatureAvailableSignal;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, std::string, std::string, uint32_t>)>>
      m_signalproxy_DisplayDialogSignal;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t>)>> m_signalproxy_UpdateAudioStatusSignal;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_DisconnectedDeviceSignal;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> m_signalproxy_UsbPortStatusSignal;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint64_t, bool, bool>)>> m_signalproxy_ClientConnectedSignal;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint64_t>)>> m_signalproxy_ClientDisconnectedSignal;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint64_t, bool>)>> m_signalproxy_ScreenResourceReadySignal;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t>)>> m_signalproxy_DisplayDialogResponseSignal;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t>)>> m_signalproxy_UsbErrorStatusSignal;
};
#endif /* COM_JCI_CARPLAYPROXY_H */
