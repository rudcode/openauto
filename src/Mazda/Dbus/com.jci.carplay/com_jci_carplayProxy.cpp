#include "com_jci_carplayProxy.h"

com_jci_carplayProxy::com_jci_carplayProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_PressKey = this->create_method<std::tuple<uint32_t>(std::tuple < uint32_t, bool > )>("PressKey");
  m_method_RotateKnob = this->create_method<std::tuple<uint32_t>(std::tuple < uint32_t > )>("RotateKnob");
  m_method_PanKnob = this->create_method<std::tuple<uint32_t>(std::tuple < uint32_t > )>("PanKnob");
  m_method_SiriLaunch = this->create_method<std::tuple<uint32_t>(std::tuple < uint32_t > )>("SiriLaunch");
  m_method_TouchScreen =
      this->create_method<std::tuple<uint32_t>(std::tuple < uint16_t, uint16_t, bool > )>("TouchScreen");
  m_method_DisableTouchScreenCoordinate =
      this->create_method<std::tuple<uint32_t>(std::tuple < uint32_t, uint32_t, uint32_t, uint32_t > )>(
          "DisableTouchScreenCoordinate");
  m_method_SelectDevice = this->create_method<std::tuple<uint32_t>(std::tuple < uint32_t > )>("SelectDevice");
  m_method_ScreenResourceAvailable =
      this->create_method<std::tuple<uint32_t>(std::tuple < uint32_t, uint32_t > )>("ScreenResourceAvailable");
  m_method_ScreenAcquireResource =
      this->create_method<std::tuple<uint32_t>(std::tuple < uint32_t > )>("ScreenAcquireResource");
  m_method_SetCurrentNativeScreen =
      this->create_method<std::tuple<uint32_t>(std::tuple < uint32_t > )>("SetCurrentNativeScreen");
  m_method_SetTurnByTurnStatus = this->create_method<std::tuple<uint32_t>(std::tuple < bool > )>("SetTurnByTurnStatus");
  m_method_SetPhoneCallStatus = this->create_method<std::tuple<uint32_t>(std::tuple < bool > )>("SetPhoneCallStatus");
  m_method_SetNotifyAudioStreamState =
      this->create_method<std::tuple<uint32_t>(std::tuple < bool > )>("SetNotifyAudioStreamState");
  m_method_AcceptCallRequest = this->create_method<void()>("AcceptCallRequest");
  m_method_GetNowPlayingInfo = this->create_method<Invalid()>("GetNowPlayingInfo");
  m_method_GetConnectDeviceInfo = this->create_method<Invalid()>("GetConnectDeviceInfo");
  m_method_SetVehicleBtMacAddress = this->create_method<uint32_t(std::string, uint32_t)>("SetVehicleBtMacAddress");
  m_method_ClearLastFocus = this->create_method<std::tuple<uint32_t>(std::tuple < bool, bool > )>("ClearLastFocus");
  m_method_EnableCarPlayConnection =
      this->create_method<std::tuple<uint32_t>(std::tuple < std::string, uint32_t, bool > )>("EnableCarPlayConnection");
  m_method_DisplayDialogResponse =
      this->create_method<std::tuple<uint32_t>(std::tuple < uint32_t > )>("DisplayDialogResponse");
  m_method_UpdateBTAudioStatus =
      this->create_method<std::tuple<uint32_t>(std::tuple < uint32_t > )>("UpdateBTAudioStatus");
  m_method_MethodCallClientDial = this->create_method<std::tuple<uint32_t>(std::tuple < std::string,
                                                                           uint32_t,
                                                                           uint32_t > )>("MethodCallClientDial");
  m_method_MethodCancelClientDial =
      this->create_method<std::tuple<uint32_t>(std::tuple < uint32_t > )>("MethodCancelClientDial");
  m_method_SetMP911EmergencyCallStatus = this->create_method<int32_t(uint32_t)>("SetMP911EmergencyCallStatus");
  m_signalproxy_DisableBluetoothSignal =
      this->create_signal<void(std::tuple < std::string > )>("DisableBluetoothSignal");
  m_signalproxy_SessionActiveSignal =
      this->create_signal<void(std::tuple < uint64_t, uint32_t > )>("SessionActiveSignal");
  m_signalproxy_GetCurrentNativeScreenRequestSignal =
      this->create_signal<void()>("GetCurrentNativeScreenRequestSignal");
  m_signalproxy_DeviceErrorSignal = this->create_signal<void(std::tuple < uint64_t, uint32_t > )>("DeviceErrorSignal");
  m_signalproxy_SessionDeactiveSignal = this->create_signal<void(std::tuple < uint64_t > )>("SessionDeactiveSignal");
  m_signalproxy_NativeUILaunchSignal = this->create_signal<void(std::tuple < uint32_t > )>("NativeUILaunchSignal");
  m_signalproxy_ScreenResourceRequestSignal = this->create_signal<void()>("ScreenResourceRequestSignal");
  m_signalproxy_ScreenResourceRequestTimeoutSignal =
      this->create_signal<void(std::tuple < uint32_t > )>("ScreenResourceRequestTimeoutSignal");
  m_signalproxy_NativeScreenDisplayRequestSignal = this->create_signal<void()>("NativeScreenDisplayRequestSignal");
  m_signalproxy_GetTurnByTurnStatusRequestSignal = this->create_signal<void()>("GetTurnByTurnStatusRequestSignal");
  m_signalproxy_TurnByTurnEntitySignal = this->create_signal<void(std::tuple < uint32_t > )>("TurnByTurnEntitySignal");
  m_signalproxy_GetPhoneCallStatusRequestSignal = this->create_signal<void()>("GetPhoneCallStatusRequestSignal");
  m_signalproxy_UpdateCallStatusInfoSignal = this->create_signal<void(std::tuple < std::string,
                                                                      std::string,
                                                                      uint32_t,
                                                                      uint32_t,
                                                                      std::string,
                                                                      std::string,
                                                                      std::string > )>("UpdateCallStatusInfoSignal");
  m_signalproxy_SpeechEntitySignal = this->create_signal<void(std::tuple < uint32_t > )>("SpeechEntitySignal");
  m_signalproxy_UpdateNowPlayingInfoSignal = this->create_signal<void(std::tuple < std::tuple < std::string,
                                                                      std::string,
                                                                      std::string,
                                                                      std::string,
                                                                      std::string >> )>("UpdateNowPlayingInfoSignal");
  m_signalproxy_GetVehicleBtMacAddress = this->create_signal<void()>("GetVehicleBtMacAddress");
  m_signalproxy_FeatureAvailableSignal = this->create_signal<void(std::tuple < uint32_t > )>("FeatureAvailableSignal");
  m_signalproxy_DisplayDialogSignal =
      this->create_signal<void(std::tuple < uint32_t, std::string, std::string, uint32_t > )>("DisplayDialogSignal");
  m_signalproxy_UpdateAudioStatusSignal =
      this->create_signal<void(std::tuple < uint32_t > )>("UpdateAudioStatusSignal");
  m_signalproxy_DisconnectedDeviceSignal = this->create_signal<void()>("DisconnectedDeviceSignal");
  m_signalproxy_UsbPortStatusSignal =
      this->create_signal<void(std::tuple < uint32_t, uint32_t > )>("UsbPortStatusSignal");
  m_signalproxy_ClientConnectedSignal =
      this->create_signal<void(std::tuple < uint64_t, bool, bool > )>("ClientConnectedSignal");
  m_signalproxy_ClientDisconnectedSignal =
      this->create_signal<void(std::tuple < uint64_t > )>("ClientDisconnectedSignal");
  m_signalproxy_ScreenResourceReadySignal =
      this->create_signal<void(std::tuple < uint64_t, bool > )>("ScreenResourceReadySignal");
  m_signalproxy_DisplayDialogResponseSignal =
      this->create_signal<void(std::tuple < uint32_t > )>("DisplayDialogResponseSignal");
  m_signalproxy_UsbErrorStatusSignal = this->create_signal<void(std::tuple < uint32_t > )>("UsbErrorStatusSignal");

}
std::shared_ptr <com_jci_carplayProxy> com_jci_carplayProxy::create(std::string name) {
  return std::shared_ptr<com_jci_carplayProxy>(new com_jci_carplayProxy(name));

}
std::tuple <uint32_t> com_jci_carplayProxy::PressKey(std::tuple<uint32_t, bool> pressKey) {
  return (*m_method_PressKey)(pressKey);

}
std::tuple <uint32_t> com_jci_carplayProxy::RotateKnob(std::tuple <uint32_t> rotateKnob) {
  return (*m_method_RotateKnob)(rotateKnob);

}
std::tuple <uint32_t> com_jci_carplayProxy::PanKnob(std::tuple <uint32_t> panKnob) {
  return (*m_method_PanKnob)(panKnob);

}
std::tuple <uint32_t> com_jci_carplayProxy::SiriLaunch(std::tuple <uint32_t> siriLaunch) {
  return (*m_method_SiriLaunch)(siriLaunch);

}
std::tuple <uint32_t> com_jci_carplayProxy::TouchScreen(std::tuple<uint16_t, uint16_t, bool> touchScreen) {
  return (*m_method_TouchScreen)(touchScreen);

}
std::tuple <uint32_t> com_jci_carplayProxy::DisableTouchScreenCoordinate(std::tuple <uint32_t, uint32_t, uint32_t, uint32_t> disableTouchScreenCoordinate) {
  return (*m_method_DisableTouchScreenCoordinate)(disableTouchScreenCoordinate);

}
std::tuple <uint32_t> com_jci_carplayProxy::SelectDevice(std::tuple <uint32_t> selectDevice) {
  return (*m_method_SelectDevice)(selectDevice);

}
std::tuple <uint32_t> com_jci_carplayProxy::ScreenResourceAvailable(std::tuple <uint32_t, uint32_t> screenResourceAvailable) {
  return (*m_method_ScreenResourceAvailable)(screenResourceAvailable);

}
std::tuple <uint32_t> com_jci_carplayProxy::ScreenAcquireResource(std::tuple <uint32_t> screenAcquireResource) {
  return (*m_method_ScreenAcquireResource)(screenAcquireResource);

}
std::tuple <uint32_t> com_jci_carplayProxy::SetCurrentNativeScreen(std::tuple <uint32_t> setCurrentNativeScreen) {
  return (*m_method_SetCurrentNativeScreen)(setCurrentNativeScreen);

}
std::tuple <uint32_t> com_jci_carplayProxy::SetTurnByTurnStatus(std::tuple<bool> setTurnByTurnStatus) {
  return (*m_method_SetTurnByTurnStatus)(setTurnByTurnStatus);

}
std::tuple <uint32_t> com_jci_carplayProxy::SetPhoneCallStatus(std::tuple<bool> setPhoneCallStatus) {
  return (*m_method_SetPhoneCallStatus)(setPhoneCallStatus);

}
std::tuple <uint32_t> com_jci_carplayProxy::SetNotifyAudioStreamState(std::tuple<bool> setNotifyAudioStreamState) {
  return (*m_method_SetNotifyAudioStreamState)(setNotifyAudioStreamState);

}
void com_jci_carplayProxy::AcceptCallRequest() {
  (*m_method_AcceptCallRequest)();

}
Invalid com_jci_carplayProxy::GetNowPlayingInfo() {
  return (*m_method_GetNowPlayingInfo)();

}
Invalid com_jci_carplayProxy::GetConnectDeviceInfo() {
  return (*m_method_GetConnectDeviceInfo)();

}
uint32_t com_jci_carplayProxy::SetVehicleBtMacAddress(std::string vehicleBtMacAddress,
                                                      uint32_t vehicleBtMacAddressLength) {
  return (*m_method_SetVehicleBtMacAddress)(vehicleBtMacAddress, vehicleBtMacAddressLength);

}
std::tuple <uint32_t> com_jci_carplayProxy::ClearLastFocus(std::tuple<bool, bool> clearLastFocus) {
  return (*m_method_ClearLastFocus)(clearLastFocus);

}
std::tuple <uint32_t> com_jci_carplayProxy::EnableCarPlayConnection(std::tuple<std::string, uint32_t, bool> enableCarPlayConnection) {
  return (*m_method_EnableCarPlayConnection)(enableCarPlayConnection);

}
std::tuple <uint32_t> com_jci_carplayProxy::DisplayDialogResponse(std::tuple <uint32_t> displayDialogResponse) {
  return (*m_method_DisplayDialogResponse)(displayDialogResponse);

}
std::tuple <uint32_t> com_jci_carplayProxy::UpdateBTAudioStatus(std::tuple <uint32_t> updateBTAudioStatusInfo) {
  return (*m_method_UpdateBTAudioStatus)(updateBTAudioStatusInfo);

}
std::tuple <uint32_t> com_jci_carplayProxy::MethodCallClientDial(std::tuple <std::string, uint32_t, uint32_t> methodCallClientDial) {
  return (*m_method_MethodCallClientDial)(methodCallClientDial);

}
std::tuple <uint32_t> com_jci_carplayProxy::MethodCancelClientDial(std::tuple <uint32_t> methodCancelClientDial) {
  return (*m_method_MethodCancelClientDial)(methodCancelClientDial);

}
int32_t com_jci_carplayProxy::SetMP911EmergencyCallStatus(uint32_t status) {
  return (*m_method_SetMP911EmergencyCallStatus)(status);

}
std::shared_ptr <DBus::SignalProxy<void(
    std::tuple < std::string > )>> com_jci_carplayProxy::signal_DisableBluetoothSignal() {
  return m_signalproxy_DisableBluetoothSignal;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint64_t,
                                        uint32_t > )>> com_jci_carplayProxy::signal_SessionActiveSignal() {
  return m_signalproxy_SessionActiveSignal;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_carplayProxy::signal_GetCurrentNativeScreenRequestSignal() {
  return m_signalproxy_GetCurrentNativeScreenRequestSignal;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint64_t,
                                        uint32_t > )>> com_jci_carplayProxy::signal_DeviceErrorSignal() {
  return m_signalproxy_DeviceErrorSignal;

}
std::shared_ptr <DBus::SignalProxy<void(
    std::tuple < uint64_t > )>> com_jci_carplayProxy::signal_SessionDeactiveSignal() {
  return m_signalproxy_SessionDeactiveSignal;

}
std::shared_ptr <DBus::SignalProxy<void(
    std::tuple < uint32_t > )>> com_jci_carplayProxy::signal_NativeUILaunchSignal() {
  return m_signalproxy_NativeUILaunchSignal;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_carplayProxy::signal_ScreenResourceRequestSignal() {
  return m_signalproxy_ScreenResourceRequestSignal;

}
std::shared_ptr <DBus::SignalProxy<void(
    std::tuple < uint32_t > )>> com_jci_carplayProxy::signal_ScreenResourceRequestTimeoutSignal() {
  return m_signalproxy_ScreenResourceRequestTimeoutSignal;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_carplayProxy::signal_NativeScreenDisplayRequestSignal() {
  return m_signalproxy_NativeScreenDisplayRequestSignal;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_carplayProxy::signal_GetTurnByTurnStatusRequestSignal() {
  return m_signalproxy_GetTurnByTurnStatusRequestSignal;

}
std::shared_ptr <DBus::SignalProxy<void(
    std::tuple < uint32_t > )>> com_jci_carplayProxy::signal_TurnByTurnEntitySignal() {
  return m_signalproxy_TurnByTurnEntitySignal;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_carplayProxy::signal_GetPhoneCallStatusRequestSignal() {
  return m_signalproxy_GetPhoneCallStatusRequestSignal;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < std::string,
                                        std::string,
                                        uint32_t,
                                        uint32_t,
                                        std::string,
                                        std::string,
                                        std::string > )>> com_jci_carplayProxy::signal_UpdateCallStatusInfoSignal() {
  return m_signalproxy_UpdateCallStatusInfoSignal;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t > )>> com_jci_carplayProxy::signal_SpeechEntitySignal() {
  return m_signalproxy_SpeechEntitySignal;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < std::tuple < std::string,
                                        std::string,
                                        std::string,
                                        std::string,
                                        std::string >> )>> com_jci_carplayProxy::signal_UpdateNowPlayingInfoSignal() {
  return m_signalproxy_UpdateNowPlayingInfoSignal;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_carplayProxy::signal_GetVehicleBtMacAddress() {
  return m_signalproxy_GetVehicleBtMacAddress;

}
std::shared_ptr <DBus::SignalProxy<void(
    std::tuple < uint32_t > )>> com_jci_carplayProxy::signal_FeatureAvailableSignal() {
  return m_signalproxy_FeatureAvailableSignal;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        std::string,
                                        std::string,
                                        uint32_t > )>> com_jci_carplayProxy::signal_DisplayDialogSignal() {
  return m_signalproxy_DisplayDialogSignal;

}
std::shared_ptr <DBus::SignalProxy<void(
    std::tuple < uint32_t > )>> com_jci_carplayProxy::signal_UpdateAudioStatusSignal() {
  return m_signalproxy_UpdateAudioStatusSignal;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_carplayProxy::signal_DisconnectedDeviceSignal() {
  return m_signalproxy_DisconnectedDeviceSignal;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t > )>> com_jci_carplayProxy::signal_UsbPortStatusSignal() {
  return m_signalproxy_UsbPortStatusSignal;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint64_t,
                                        bool,
                                        bool > )>> com_jci_carplayProxy::signal_ClientConnectedSignal() {
  return m_signalproxy_ClientConnectedSignal;

}
std::shared_ptr <DBus::SignalProxy<void(
    std::tuple < uint64_t > )>> com_jci_carplayProxy::signal_ClientDisconnectedSignal() {
  return m_signalproxy_ClientDisconnectedSignal;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint64_t,
                                        bool > )>> com_jci_carplayProxy::signal_ScreenResourceReadySignal() {
  return m_signalproxy_ScreenResourceReadySignal;

}
std::shared_ptr <DBus::SignalProxy<void(
    std::tuple < uint32_t > )>> com_jci_carplayProxy::signal_DisplayDialogResponseSignal() {
  return m_signalproxy_DisplayDialogResponseSignal;

}
std::shared_ptr <DBus::SignalProxy<void(
    std::tuple < uint32_t > )>> com_jci_carplayProxy::signal_UsbErrorStatusSignal() {
  return m_signalproxy_UsbErrorStatusSignal;

}
