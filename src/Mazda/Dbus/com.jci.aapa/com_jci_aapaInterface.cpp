#include "com_jci_aapaInterface.h"

com_jci_aapaInterface::com_jci_aapaInterface(com_jci_aapa *adaptee, std::string name) : DBus::Interface(name) {
  this->create_method<void(uint32_t)>("MDSettingModeData", sigc::mem_fun(*adaptee, &com_jci_aapa::MDSettingModeData));
  this->create_method<void(uint32_t)>("VideoProjectionEventToMD",
                                      sigc::mem_fun(*adaptee, &com_jci_aapa::VideoProjectionEventToMD));
  this->create_method<void(uint32_t, bool, int32_t)>("InputKey", sigc::mem_fun(*adaptee, &com_jci_aapa::InputKey));
  this->create_method<void(uint32_t)>("SetRouteState", sigc::mem_fun(*adaptee, &com_jci_aapa::SetRouteState));
  this->create_method<DBus::MultipleReturn<std::tuple<uint8_t, std::string, std::string, std::string, std::string>,
                                           int32_t>()>("GetNowPlayingInfo",
                                                       sigc::mem_fun(*adaptee, &com_jci_aapa::GetNowPlayingInfo));
  this->create_method<void(bool)>("BTPairingResult", sigc::mem_fun(*adaptee, &com_jci_aapa::BTPairingResult));
  this->create_method<void(bool)>("BTReadyToPair", sigc::mem_fun(*adaptee, &com_jci_aapa::BTReadyToPair));
  this->create_method<void(std::string, uint32_t)>("SendBTAuthenticationData",
                                                   sigc::mem_fun(*adaptee, &com_jci_aapa::SendBTAuthenticationData));
  this->create_method<void(std::string, uint32_t)>("SetVehicleBtMacAddress",
                                                   sigc::mem_fun(*adaptee, &com_jci_aapa::SetVehicleBtMacAddress));
  this->create_method<void(bool, std::string)>("NotifyBTHFCallStatus",
                                               sigc::mem_fun(*adaptee, &com_jci_aapa::NotifyBTHFCallStatus));
  this->create_method<void(std::string)>("IntentPhoneCall", sigc::mem_fun(*adaptee, &com_jci_aapa::IntentPhoneCall));
  this->create_method<void(bool)>("DialogWinkStatus", sigc::mem_fun(*adaptee, &com_jci_aapa::DialogWinkStatus));
  this->create_method<void(std::tuple<bool, bool>)>("ClearLastFocus",
                                                    sigc::mem_fun(*adaptee, &com_jci_aapa::ClearLastFocus));
  this->create_method<void(bool)>("SbnStatus", sigc::mem_fun(*adaptee, &com_jci_aapa::SbnStatus));
  this->create_method<DBus::MultipleReturn<bool, std::string, uint32_t>()>("GetAOASessionStatus",
                                                                           sigc::mem_fun(*adaptee,
                                                                                         &com_jci_aapa::GetAOASessionStatus));
  this->create_method<uint8_t()>("GetAvailable", sigc::mem_fun(*adaptee, &com_jci_aapa::GetAvailable));
  this->create_method<std::tuple<int32_t>(std::tuple<bool>)>("SetNativeTurnByTurnStatus",
                                                             sigc::mem_fun(*adaptee,
                                                                           &com_jci_aapa::SetNativeTurnByTurnStatus));
  this->create_method<int32_t(uint32_t)>("SetMP911EmergencyCallStatus",
                                         sigc::mem_fun(*adaptee, &com_jci_aapa::SetMP911EmergencyCallStatus));
  m_signal_AOASessionStatus = create_signal<void(bool)>("AOASessionStatus");
  m_signal_SendSessionInfo = create_signal<void(std::string)>("SendSessionInfo");
  m_signal_VideoProjectionRequestFromMD = create_signal<void(uint32_t)>("VideoProjectionRequestFromMD");
  m_signal_NowPlayingInfo =
      create_signal<void(std::tuple<uint8_t, std::string, std::string, std::string, std::string>)>("NowPlayingInfo");
  m_signal_MDModeDisplayFirstDialog = create_signal<void(bool)>("MDModeDisplayFirstDialog");
  m_signal_DisplayReconnectingDialog = create_signal<void(bool)>("DisplayReconnectingDialog");
  m_signal_StartBtConnection = create_signal<void()>("StartBtConnection");
  m_signal_BTPairingRequest = create_signal<void(std::string, uint32_t, bool)>("BTPairingRequest");
  m_signal_GetVehicleBtMacAddress = create_signal<void()>("GetVehicleBtMacAddress");
  m_signal_NotifySpeedThreshold = create_signal<void(bool)>("NotifySpeedThreshold");
  m_signal_DisplaySbnInfo = create_signal<void(uint32_t)>("DisplaySbnInfo");
  m_signal_NotifyAudioFocusStatus = create_signal<void(uint32_t)>("NotifyAudioFocusStatus");
  m_signal_NotifyBTConnectionComplete = create_signal<void(bool)>("NotifyBTConnectionComplete");
  m_signal_Available = create_signal<void(uint8_t)>("Available");
  m_signal_NotifyStopAndSetup = create_signal<void(uint32_t)>("NotifyStopAndSetup");
  m_signal_NotifyNoVideoSinkSetup = create_signal<void(bool)>("NotifyNoVideoSinkSetup");
  m_signal_NotifyDeviceNotResponding = create_signal<void(bool)>("NotifyDeviceNotResponding");
  m_signal_NotifyASRStatus = create_signal<void(bool)>("NotifyASRStatus");
  m_signal_ProjectionStatusResult = create_signal<void(bool)>("ProjectionStatusResult");
  m_signal_DisplayStopForSetupDialog = create_signal<void(bool)>("DisplayStopForSetupDialog");
  m_signal_NotifyAANaviStatus = create_signal<void(int32_t)>("NotifyAANaviStatus");
  m_signal_GetNativeTurnByTurnStatusRequest = create_signal<void()>("GetNativeTurnByTurnStatusRequest");
  m_signal_NotifyDeviceConnection = create_signal<void(bool)>("NotifyDeviceConnection");

}
std::shared_ptr<com_jci_aapaInterface> com_jci_aapaInterface::create(com_jci_aapa *adaptee, std::string name) {
  return std::shared_ptr<com_jci_aapaInterface>(new com_jci_aapaInterface(adaptee, name));

}
std::shared_ptr<DBus::Signal<void(bool)>> com_jci_aapaInterface::signal_AOASessionStatus() {
  return m_signal_AOASessionStatus;

}
void com_jci_aapaInterface::AOASessionStatus(bool enable) {
  (*m_signal_AOASessionStatus)(enable);

}
std::shared_ptr<DBus::Signal<void(std::string)>> com_jci_aapaInterface::signal_SendSessionInfo() {
  return m_signal_SendSessionInfo;

}
void com_jci_aapaInterface::SendSessionInfo(std::string deviceName) {
  (*m_signal_SendSessionInfo)(deviceName);

}
std::shared_ptr<DBus::Signal<void(uint32_t)>> com_jci_aapaInterface::signal_VideoProjectionRequestFromMD() {
  return m_signal_VideoProjectionRequestFromMD;

}
void com_jci_aapaInterface::VideoProjectionRequestFromMD(uint32_t enable) {
  (*m_signal_VideoProjectionRequestFromMD)(enable);

}
std::shared_ptr<DBus::Signal<void(std::tuple<uint8_t,
                                             std::string,
                                             std::string,
                                             std::string,
                                             std::string>)>> com_jci_aapaInterface::signal_NowPlayingInfo() {
  return m_signal_NowPlayingInfo;

}
void com_jci_aapaInterface::NowPlayingInfo(std::tuple<uint8_t,
                                                      std::string,
                                                      std::string,
                                                      std::string,
                                                      std::string> nowPlayingInfo) {
  (*m_signal_NowPlayingInfo)(nowPlayingInfo);

}
std::shared_ptr<DBus::Signal<void(bool)>> com_jci_aapaInterface::signal_MDModeDisplayFirstDialog() {
  return m_signal_MDModeDisplayFirstDialog;

}
void com_jci_aapaInterface::MDModeDisplayFirstDialog(bool displayFirstDialog) {
  (*m_signal_MDModeDisplayFirstDialog)(displayFirstDialog);

}
std::shared_ptr<DBus::Signal<void(bool)>> com_jci_aapaInterface::signal_DisplayReconnectingDialog() {
  return m_signal_DisplayReconnectingDialog;

}
void com_jci_aapaInterface::DisplayReconnectingDialog(bool enable) {
  (*m_signal_DisplayReconnectingDialog)(enable);

}
std::shared_ptr<DBus::Signal<void()>> com_jci_aapaInterface::signal_StartBtConnection() {
  return m_signal_StartBtConnection;

}
void com_jci_aapaInterface::StartBtConnection() {
  (*m_signal_StartBtConnection)();

}
std::shared_ptr<DBus::Signal<void(std::string, uint32_t, bool)>> com_jci_aapaInterface::signal_BTPairingRequest() {
  return m_signal_BTPairingRequest;

}
void com_jci_aapaInterface::BTPairingRequest(std::string macaddr, uint32_t maclen, bool method) {
  (*m_signal_BTPairingRequest)(macaddr, maclen, method);

}
std::shared_ptr<DBus::Signal<void()>> com_jci_aapaInterface::signal_GetVehicleBtMacAddress() {
  return m_signal_GetVehicleBtMacAddress;

}
void com_jci_aapaInterface::GetVehicleBtMacAddress() {
  (*m_signal_GetVehicleBtMacAddress)();

}
std::shared_ptr<DBus::Signal<void(bool)>> com_jci_aapaInterface::signal_NotifySpeedThreshold() {
  return m_signal_NotifySpeedThreshold;

}
void com_jci_aapaInterface::NotifySpeedThreshold(bool enable) {
  (*m_signal_NotifySpeedThreshold)(enable);

}
std::shared_ptr<DBus::Signal<void(uint32_t)>> com_jci_aapaInterface::signal_DisplaySbnInfo() {
  return m_signal_DisplaySbnInfo;

}
void com_jci_aapaInterface::DisplaySbnInfo(uint32_t info) {
  (*m_signal_DisplaySbnInfo)(info);

}
std::shared_ptr<DBus::Signal<void(uint32_t)>> com_jci_aapaInterface::signal_NotifyAudioFocusStatus() {
  return m_signal_NotifyAudioFocusStatus;

}
void com_jci_aapaInterface::NotifyAudioFocusStatus(uint32_t status) {
  (*m_signal_NotifyAudioFocusStatus)(status);

}
std::shared_ptr<DBus::Signal<void(bool)>> com_jci_aapaInterface::signal_NotifyBTConnectionComplete() {
  return m_signal_NotifyBTConnectionComplete;

}
void com_jci_aapaInterface::NotifyBTConnectionComplete(bool enable) {
  (*m_signal_NotifyBTConnectionComplete)(enable);

}
std::shared_ptr<DBus::Signal<void(uint8_t)>> com_jci_aapaInterface::signal_Available() {
  return m_signal_Available;

}
void com_jci_aapaInterface::Available(uint8_t available) {
  (*m_signal_Available)(available);

}
std::shared_ptr<DBus::Signal<void(uint32_t)>> com_jci_aapaInterface::signal_NotifyStopAndSetup() {
  return m_signal_NotifyStopAndSetup;

}
void com_jci_aapaInterface::NotifyStopAndSetup(uint32_t displaySASDialog) {
  (*m_signal_NotifyStopAndSetup)(displaySASDialog);

}
std::shared_ptr<DBus::Signal<void(bool)>> com_jci_aapaInterface::signal_NotifyNoVideoSinkSetup() {
  return m_signal_NotifyNoVideoSinkSetup;

}
void com_jci_aapaInterface::NotifyNoVideoSinkSetup(bool displayNVSSDialog) {
  (*m_signal_NotifyNoVideoSinkSetup)(displayNVSSDialog);

}
std::shared_ptr<DBus::Signal<void(bool)>> com_jci_aapaInterface::signal_NotifyDeviceNotResponding() {
  return m_signal_NotifyDeviceNotResponding;

}
void com_jci_aapaInterface::NotifyDeviceNotResponding(bool displayDNR) {
  (*m_signal_NotifyDeviceNotResponding)(displayDNR);

}
std::shared_ptr<DBus::Signal<void(bool)>> com_jci_aapaInterface::signal_NotifyASRStatus() {
  return m_signal_NotifyASRStatus;

}
void com_jci_aapaInterface::NotifyASRStatus(bool enable) {
  (*m_signal_NotifyASRStatus)(enable);

}
std::shared_ptr<DBus::Signal<void(bool)>> com_jci_aapaInterface::signal_ProjectionStatusResult() {
  return m_signal_ProjectionStatusResult;

}
void com_jci_aapaInterface::ProjectionStatusResult(bool enable) {
  (*m_signal_ProjectionStatusResult)(enable);

}
std::shared_ptr<DBus::Signal<void(bool)>> com_jci_aapaInterface::signal_DisplayStopForSetupDialog() {
  return m_signal_DisplayStopForSetupDialog;

}
void com_jci_aapaInterface::DisplayStopForSetupDialog(bool enable) {
  (*m_signal_DisplayStopForSetupDialog)(enable);

}
std::shared_ptr<DBus::Signal<void(int32_t)>> com_jci_aapaInterface::signal_NotifyAANaviStatus() {
  return m_signal_NotifyAANaviStatus;

}
void com_jci_aapaInterface::NotifyAANaviStatus(int32_t status) {
  (*m_signal_NotifyAANaviStatus)(status);

}
std::shared_ptr<DBus::Signal<void()>> com_jci_aapaInterface::signal_GetNativeTurnByTurnStatusRequest() {
  return m_signal_GetNativeTurnByTurnStatusRequest;

}
void com_jci_aapaInterface::GetNativeTurnByTurnStatusRequest() {
  (*m_signal_GetNativeTurnByTurnStatusRequest)();

}
std::shared_ptr<DBus::Signal<void(bool)>> com_jci_aapaInterface::signal_NotifyDeviceConnection() {
  return m_signal_NotifyDeviceConnection;

}
void com_jci_aapaInterface::NotifyDeviceConnection(bool status) {
  (*m_signal_NotifyDeviceConnection)(status);

}
