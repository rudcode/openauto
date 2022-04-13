#include "com_jci_aapaProxy.h"

com_jci_aapaProxy::com_jci_aapaProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_MDSettingModeData = this->create_method<void(uint32_t)>("MDSettingModeData");
  m_method_VideoProjectionEventToMD = this->create_method<void(uint32_t)>("VideoProjectionEventToMD");
  m_method_InputKey = this->create_method<void(uint32_t, bool, int32_t)>("InputKey");
  m_method_SetRouteState = this->create_method<void(uint32_t)>("SetRouteState");
  m_method_GetNowPlayingInfo =
      this->create_method < DBus::MultipleReturn < std::tuple < uint8_t, std::string, std::string, std::string,
      std::string >, int32_t > () > ("GetNowPlayingInfo");
  m_method_BTPairingResult = this->create_method<void(bool)>("BTPairingResult");
  m_method_BTReadyToPair = this->create_method<void(bool)>("BTReadyToPair");
  m_method_SendBTAuthenticationData = this->create_method<void(std::string, uint32_t)>("SendBTAuthenticationData");
  m_method_SetVehicleBtMacAddress = this->create_method<void(std::string, uint32_t)>("SetVehicleBtMacAddress");
  m_method_NotifyBTHFCallStatus = this->create_method<void(bool, std::string)>("NotifyBTHFCallStatus");
  m_method_IntentPhoneCall = this->create_method<void(std::string)>("IntentPhoneCall");
  m_method_DialogWinkStatus = this->create_method<void(bool)>("DialogWinkStatus");
  m_method_ClearLastFocus = this->create_method<void(std::tuple < bool, bool > )>("ClearLastFocus");
  m_method_SbnStatus = this->create_method<void(bool)>("SbnStatus");
  m_method_GetAOASessionStatus =
      this->create_method<DBus::MultipleReturn<bool, std::string, uint32_t>()>("GetAOASessionStatus");
  m_method_GetAvailable = this->create_method<uint8_t()>("GetAvailable");
  m_method_SetNativeTurnByTurnStatus =
      this->create_method<std::tuple<int32_t>(std::tuple < bool > )>("SetNativeTurnByTurnStatus");
  m_method_SetMP911EmergencyCallStatus = this->create_method<int32_t(uint32_t)>("SetMP911EmergencyCallStatus");
  m_signalproxy_AOASessionStatus = this->create_signal<void(bool)>("AOASessionStatus");
  m_signalproxy_SendSessionInfo = this->create_signal<void(std::string)>("SendSessionInfo");
  m_signalproxy_VideoProjectionRequestFromMD = this->create_signal<void(uint32_t)>("VideoProjectionRequestFromMD");
  m_signalproxy_NowPlayingInfo =
      this->create_signal<void(std::tuple < uint8_t, std::string, std::string, std::string, std::string > )>(
          "NowPlayingInfo");
  m_signalproxy_MDModeDisplayFirstDialog = this->create_signal<void(bool)>("MDModeDisplayFirstDialog");
  m_signalproxy_DisplayReconnectingDialog = this->create_signal<void(bool)>("DisplayReconnectingDialog");
  m_signalproxy_StartBtConnection = this->create_signal<void()>("StartBtConnection");
  m_signalproxy_BTPairingRequest = this->create_signal<void(std::string, uint32_t, bool)>("BTPairingRequest");
  m_signalproxy_GetVehicleBtMacAddress = this->create_signal<void()>("GetVehicleBtMacAddress");
  m_signalproxy_NotifySpeedThreshold = this->create_signal<void(bool)>("NotifySpeedThreshold");
  m_signalproxy_DisplaySbnInfo = this->create_signal<void(uint32_t)>("DisplaySbnInfo");
  m_signalproxy_NotifyAudioFocusStatus = this->create_signal<void(uint32_t)>("NotifyAudioFocusStatus");
  m_signalproxy_NotifyBTConnectionComplete = this->create_signal<void(bool)>("NotifyBTConnectionComplete");
  m_signalproxy_Available = this->create_signal<void(uint8_t)>("Available");
  m_signalproxy_NotifyStopAndSetup = this->create_signal<void(uint32_t)>("NotifyStopAndSetup");
  m_signalproxy_NotifyNoVideoSinkSetup = this->create_signal<void(bool)>("NotifyNoVideoSinkSetup");
  m_signalproxy_NotifyDeviceNotResponding = this->create_signal<void(bool)>("NotifyDeviceNotResponding");
  m_signalproxy_NotifyASRStatus = this->create_signal<void(bool)>("NotifyASRStatus");
  m_signalproxy_ProjectionStatusResult = this->create_signal<void(bool)>("ProjectionStatusResult");
  m_signalproxy_DisplayStopForSetupDialog = this->create_signal<void(bool)>("DisplayStopForSetupDialog");
  m_signalproxy_NotifyAANaviStatus = this->create_signal<void(int32_t)>("NotifyAANaviStatus");
  m_signalproxy_GetNativeTurnByTurnStatusRequest = this->create_signal<void()>("GetNativeTurnByTurnStatusRequest");
  m_signalproxy_NotifyDeviceConnection = this->create_signal<void(bool)>("NotifyDeviceConnection");

}
std::shared_ptr <com_jci_aapaProxy> com_jci_aapaProxy::create(std::string name) {
  return std::shared_ptr<com_jci_aapaProxy>(new com_jci_aapaProxy(name));

}
void com_jci_aapaProxy::MDSettingModeData(uint32_t selectMode) {
  (*m_method_MDSettingModeData)(selectMode);

}
void com_jci_aapaProxy::VideoProjectionEventToMD(uint32_t videoProjectionEvent) {
  (*m_method_VideoProjectionEventToMD)(videoProjectionEvent);

}
void com_jci_aapaProxy::InputKey(uint32_t keyCode, bool absolute, int32_t step) {
  (*m_method_InputKey)(keyCode, absolute, step);

}
void com_jci_aapaProxy::SetRouteState(uint32_t state) {
  (*m_method_SetRouteState)(state);

}
DBus::MultipleReturn <std::tuple<uint8_t,
                                 std::string,
                                 std::string,
                                 std::string,
                                 std::string>, int32_t> com_jci_aapaProxy::GetNowPlayingInfo() {
  return (*m_method_GetNowPlayingInfo)();

}
void com_jci_aapaProxy::BTPairingResult(bool result) {
  (*m_method_BTPairingResult)(result);

}
void com_jci_aapaProxy::BTReadyToPair(bool alreadyPaired) {
  (*m_method_BTReadyToPair)(alreadyPaired);

}
void com_jci_aapaProxy::SendBTAuthenticationData(std::string btdata, uint32_t len) {
  (*m_method_SendBTAuthenticationData)(btdata, len);

}
void com_jci_aapaProxy::SetVehicleBtMacAddress(std::string macaddr, uint32_t maclen) {
  (*m_method_SetVehicleBtMacAddress)(macaddr, maclen);

}
void com_jci_aapaProxy::NotifyBTHFCallStatus(bool status, std::string macaddr) {
  (*m_method_NotifyBTHFCallStatus)(status, macaddr);

}
void com_jci_aapaProxy::IntentPhoneCall(std::string phonenumber) {
  (*m_method_IntentPhoneCall)(phonenumber);

}
void com_jci_aapaProxy::DialogWinkStatus(bool status) {
  (*m_method_DialogWinkStatus)(status);

}
void com_jci_aapaProxy::ClearLastFocus(std::tuple<bool, bool> focusInfo) {
  (*m_method_ClearLastFocus)(focusInfo);

}
void com_jci_aapaProxy::SbnStatus(bool status) {
  (*m_method_SbnStatus)(status);

}
DBus::MultipleReturn<bool, std::string, uint32_t> com_jci_aapaProxy::GetAOASessionStatus() {
  return (*m_method_GetAOASessionStatus)();

}
uint8_t com_jci_aapaProxy::GetAvailable() {
  return (*m_method_GetAvailable)();

}
std::tuple <int32_t> com_jci_aapaProxy::SetNativeTurnByTurnStatus(std::tuple<bool> setNativeTurnByTurnStatus) {
  return (*m_method_SetNativeTurnByTurnStatus)(setNativeTurnByTurnStatus);

}
int32_t com_jci_aapaProxy::SetMP911EmergencyCallStatus(uint32_t status) {
  return (*m_method_SetMP911EmergencyCallStatus)(status);

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_aapaProxy::signal_AOASessionStatus() {
  return m_signalproxy_AOASessionStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::string)>> com_jci_aapaProxy::signal_SendSessionInfo() {
  return m_signalproxy_SendSessionInfo;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_aapaProxy::signal_VideoProjectionRequestFromMD() {
  return m_signalproxy_VideoProjectionRequestFromMD;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        std::string,
                                        std::string,
                                        std::string,
                                        std::string > )>> com_jci_aapaProxy::signal_NowPlayingInfo() {
  return m_signalproxy_NowPlayingInfo;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_aapaProxy::signal_MDModeDisplayFirstDialog() {
  return m_signalproxy_MDModeDisplayFirstDialog;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_aapaProxy::signal_DisplayReconnectingDialog() {
  return m_signalproxy_DisplayReconnectingDialog;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_aapaProxy::signal_StartBtConnection() {
  return m_signalproxy_StartBtConnection;

}
std::shared_ptr <DBus::SignalProxy<void(std::string, uint32_t, bool)>> com_jci_aapaProxy::signal_BTPairingRequest() {
  return m_signalproxy_BTPairingRequest;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_aapaProxy::signal_GetVehicleBtMacAddress() {
  return m_signalproxy_GetVehicleBtMacAddress;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_aapaProxy::signal_NotifySpeedThreshold() {
  return m_signalproxy_NotifySpeedThreshold;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_aapaProxy::signal_DisplaySbnInfo() {
  return m_signalproxy_DisplaySbnInfo;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_aapaProxy::signal_NotifyAudioFocusStatus() {
  return m_signalproxy_NotifyAudioFocusStatus;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_aapaProxy::signal_NotifyBTConnectionComplete() {
  return m_signalproxy_NotifyBTConnectionComplete;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_aapaProxy::signal_Available() {
  return m_signalproxy_Available;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_aapaProxy::signal_NotifyStopAndSetup() {
  return m_signalproxy_NotifyStopAndSetup;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_aapaProxy::signal_NotifyNoVideoSinkSetup() {
  return m_signalproxy_NotifyNoVideoSinkSetup;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_aapaProxy::signal_NotifyDeviceNotResponding() {
  return m_signalproxy_NotifyDeviceNotResponding;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_aapaProxy::signal_NotifyASRStatus() {
  return m_signalproxy_NotifyASRStatus;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_aapaProxy::signal_ProjectionStatusResult() {
  return m_signalproxy_ProjectionStatusResult;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_aapaProxy::signal_DisplayStopForSetupDialog() {
  return m_signalproxy_DisplayStopForSetupDialog;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_aapaProxy::signal_NotifyAANaviStatus() {
  return m_signalproxy_NotifyAANaviStatus;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_aapaProxy::signal_GetNativeTurnByTurnStatusRequest() {
  return m_signalproxy_GetNativeTurnByTurnStatusRequest;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_aapaProxy::signal_NotifyDeviceConnection() {
  return m_signalproxy_NotifyDeviceConnection;

}
