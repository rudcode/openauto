#include "com_jci_bcaInterface.h"

com_jci_bcaInterface::com_jci_bcaInterface(com_jci_bca *adaptee, std::string name) : DBus::Interface(name) {
  this->create_method<int32_t(uint32_t, uint32_t)>("ConnectRequest",
                                                   sigc::mem_fun(*adaptee, &com_jci_bca::ConnectRequest));
  this->create_method<int32_t(uint32_t)>("ConnectRequestHfpAndAvp",
                                         sigc::mem_fun(*adaptee, &com_jci_bca::ConnectRequestHfpAndAvp));
  this->create_method<int32_t(uint32_t, uint32_t)>("DisconnectRequest",
                                                   sigc::mem_fun(*adaptee, &com_jci_bca::DisconnectRequest));
  this->create_method<int32_t(uint32_t, uint32_t)>("DisconnectRequestHfpAndAvp",
                                                   sigc::mem_fun(*adaptee, &com_jci_bca::DisconnectRequestHfpAndAvp));
  this->create_method<int32_t(bool)>("CancelConnect", sigc::mem_fun(*adaptee, &com_jci_bca::CancelConnect));
  this->create_method<int32_t(uint32_t)>("GetConnectStatus", sigc::mem_fun(*adaptee, &com_jci_bca::GetConnectStatus));
  this->create_method<std::tuple<int32_t, int32_t, int32_t, int32_t, std::tuple<std::vector<uint8_t>>>(uint32_t)>(
      "QueryConnectStatus",
      sigc::mem_fun(*adaptee, &com_jci_bca::QueryConnectStatus));
  this->create_method<int32_t(uint32_t)>("UnbarDevice", sigc::mem_fun(*adaptee, &com_jci_bca::UnbarDevice));
  this->create_method<int32_t(bool)>("BluetoothOn", sigc::mem_fun(*adaptee, &com_jci_bca::BluetoothOn));
  this->create_method<int32_t(bool)>("BluetoothOff", sigc::mem_fun(*adaptee, &com_jci_bca::BluetoothOff));
  this->create_method<int32_t(uint32_t)>("StartAdd", sigc::mem_fun(*adaptee, &com_jci_bca::StartAdd));
  this->create_method<int32_t(uint32_t)>("ConnectAll", sigc::mem_fun(*adaptee, &com_jci_bca::ConnectAll));
  this->create_method<int32_t()>("DisconnectAll", sigc::mem_fun(*adaptee, &com_jci_bca::DisconnectAll));
  this->create_method<int32_t(uint32_t)>("GetServiceId", sigc::mem_fun(*adaptee, &com_jci_bca::GetServiceId));
  this->create_method<int32_t()>("ReadBluetoothSetting", sigc::mem_fun(*adaptee, &com_jci_bca::ReadBluetoothSetting));
  this->create_method<int32_t()>("AvailablePairedDeviceList",
                                 sigc::mem_fun(*adaptee, &com_jci_bca::AvailablePairedDeviceList));
  this->create_method<DBus::MultipleReturn<int32_t, int32_t>()>("GetFeatureStatus",
                                                                sigc::mem_fun(*adaptee,
                                                                              &com_jci_bca::GetFeatureStatus));
  this->create_method<int32_t(uint32_t)>("SupportedProfiles", sigc::mem_fun(*adaptee, &com_jci_bca::SupportedProfiles));
  this->create_method<int32_t(uint32_t, bool)>("SetDontShowOnConnectionSetting",
                                               sigc::mem_fun(*adaptee, &com_jci_bca::SetDontShowOnConnectionSetting));
  this->create_method<int32_t(uint32_t)>("GetDontShowOnConnectionSetting",
                                         sigc::mem_fun(*adaptee, &com_jci_bca::GetDontShowOnConnectionSetting));
  this->create_method<int32_t(uint32_t)>("AAutoEnableBtResponse",
                                         sigc::mem_fun(*adaptee, &com_jci_bca::AAutoEnableBtResponse));
  this->create_method<int32_t(uint32_t)>("AAutoNoEntryAvailableResponse",
                                         sigc::mem_fun(*adaptee, &com_jci_bca::AAutoNoEntryAvailableResponse));
  this->create_method<int32_t(uint32_t, uint32_t)>("PairingStatus",
                                                   sigc::mem_fun(*adaptee, &com_jci_bca::PairingStatus));
  this->create_method<int32_t(uint32_t)>("DeviceDeleteStatus",
                                         sigc::mem_fun(*adaptee, &com_jci_bca::DeviceDeleteStatus));
  this->create_method<int32_t(uint32_t, uint32_t, uint32_t)>("CallStatus",
                                                             sigc::mem_fun(*adaptee, &com_jci_bca::CallStatus));
  this->create_method<int32_t(uint32_t)>("SetCommSettingsResetStatus",
                                         sigc::mem_fun(*adaptee, &com_jci_bca::SetCommSettingsResetStatus));
  this->create_method<int32_t(uint32_t)>("SetMP911EmergencyCallStatus",
                                         sigc::mem_fun(*adaptee, &com_jci_bca::SetMP911EmergencyCallStatus));
  m_signal_DontShowOnConnectionSettingStatusResp =
      create_signal<void(uint32_t, bool)>("DontShowOnConnectionSettingStatusResp");
  m_signal_ConnectionStatusResp =
      create_signal<void(uint32_t, uint32_t, uint32_t, uint32_t, std::tuple<std::vector<uint8_t>>)>(
          "ConnectionStatusResp");
  m_signal_HftReadyStatus = create_signal<void(uint32_t, uint32_t, uint32_t)>("HftReadyStatus");
  m_signal_ReadyStatus = create_signal<void(uint32_t, uint32_t)>("ReadyStatus");
  m_signal_AddStatusResp = create_signal<void(uint32_t, uint32_t)>("AddStatusResp");
  m_signal_DeviceUnbarringStatusResp = create_signal<void(uint32_t, uint32_t)>("DeviceUnbarringStatusResp");
  m_signal_DeviceBluetoothSettingResp = create_signal<void(bool)>("DeviceBluetoothSettingResp");
  m_signal_AvailablePairedListResp =
      create_signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>("AvailablePairedListResp");
  m_signal_SupportedProfilesResp = create_signal<void(std::tuple<std::vector<uint8_t>>)>("SupportedProfilesResp");
  m_signal_FirstHfpSupportedInfo = create_signal<void(bool)>("FirstHfpSupportedInfo");
  m_signal_CarPlayConnectionStatus = create_signal<void(uint32_t, uint32_t)>("CarPlayConnectionStatus");
  m_signal_AAutoEnableBt = create_signal<void()>("AAutoEnableBt");
  m_signal_AAutoNoEntryAvailable = create_signal<void(uint32_t)>("AAutoNoEntryAvailable");
  m_signal_ReqStartAndroidAutoPairing = create_signal<void()>("ReqStartAndroidAutoPairing");
  m_signal_ReqStopAndroidAutoPairing = create_signal<void()>("ReqStopAndroidAutoPairing");
  m_signal_ReqDeleteDevice = create_signal<void(uint32_t)>("ReqDeleteDevice");
  m_signal_AAPairingSeqResult = create_signal<void(bool)>("AAPairingSeqResult");
  m_signal_AndroidAutoPairingTimeout = create_signal<void()>("AndroidAutoPairingTimeout");
  m_signal_RequestStartAutoDownload = create_signal<void(uint32_t)>("RequestStartAutoDownload");
  m_signal_DisableBluetoothRsp = create_signal<void(uint32_t)>("DisableBluetoothRsp");
  m_signal_ConnectingCarPlayError = create_signal<void()>("ConnectingCarPlayError");

}
std::shared_ptr<com_jci_bcaInterface> com_jci_bcaInterface::create(com_jci_bca *adaptee, std::string name) {
  return std::shared_ptr<com_jci_bcaInterface>(new com_jci_bcaInterface(adaptee, name));

}
std::shared_ptr<DBus::Signal<void(uint32_t,
                                  bool)>> com_jci_bcaInterface::signal_DontShowOnConnectionSettingStatusResp() {
  return m_signal_DontShowOnConnectionSettingStatusResp;

}
void com_jci_bcaInterface::DontShowOnConnectionSettingStatusResp(uint32_t btDeviceId, bool setting) {
  (*m_signal_DontShowOnConnectionSettingStatusResp)(btDeviceId, setting);

}
std::shared_ptr<DBus::Signal<void(uint32_t,
                                  uint32_t,
                                  uint32_t,
                                  uint32_t,
                                  std::tuple<std::vector<uint8_t>>)>> com_jci_bcaInterface::signal_ConnectionStatusResp() {
  return m_signal_ConnectionStatusResp;

}
void com_jci_bcaInterface::ConnectionStatusResp(uint32_t serviceId,
                                                uint32_t connStatus,
                                                uint32_t btDeviceId,
                                                uint32_t status,
                                                std::tuple<std::vector<uint8_t>> terminalPath) {
  (*m_signal_ConnectionStatusResp)(serviceId, connStatus, btDeviceId, status, terminalPath);

}
std::shared_ptr<DBus::Signal<void(uint32_t, uint32_t, uint32_t)>> com_jci_bcaInterface::signal_HftReadyStatus() {
  return m_signal_HftReadyStatus;

}
void com_jci_bcaInterface::HftReadyStatus(uint32_t hftReady, uint32_t reasonCode, uint32_t appId) {
  (*m_signal_HftReadyStatus)(hftReady, reasonCode, appId);

}
std::shared_ptr<DBus::Signal<void(uint32_t, uint32_t)>> com_jci_bcaInterface::signal_ReadyStatus() {
  return m_signal_ReadyStatus;

}
void com_jci_bcaInterface::ReadyStatus(uint32_t isReady, uint32_t reasonCode) {
  (*m_signal_ReadyStatus)(isReady, reasonCode);

}
std::shared_ptr<DBus::Signal<void(uint32_t, uint32_t)>> com_jci_bcaInterface::signal_AddStatusResp() {
  return m_signal_AddStatusResp;

}
void com_jci_bcaInterface::AddStatusResp(uint32_t addServiceId, uint32_t status) {
  (*m_signal_AddStatusResp)(addServiceId, status);

}
std::shared_ptr<DBus::Signal<void(uint32_t, uint32_t)>> com_jci_bcaInterface::signal_DeviceUnbarringStatusResp() {
  return m_signal_DeviceUnbarringStatusResp;

}
void com_jci_bcaInterface::DeviceUnbarringStatusResp(uint32_t btDeviceId, uint32_t status) {
  (*m_signal_DeviceUnbarringStatusResp)(btDeviceId, status);

}
std::shared_ptr<DBus::Signal<void(bool)>> com_jci_bcaInterface::signal_DeviceBluetoothSettingResp() {
  return m_signal_DeviceBluetoothSettingResp;

}
void com_jci_bcaInterface::DeviceBluetoothSettingResp(bool btSetting) {
  (*m_signal_DeviceBluetoothSettingResp)(btSetting);

}
std::shared_ptr<DBus::Signal<void(uint32_t,
                                  std::tuple<std::vector<uint8_t>>)>> com_jci_bcaInterface::signal_AvailablePairedListResp() {
  return m_signal_AvailablePairedListResp;

}
void com_jci_bcaInterface::AvailablePairedListResp(uint32_t totalPairedDevices,
                                                   std::tuple<std::vector<uint8_t>> pairedDeviceList) {
  (*m_signal_AvailablePairedListResp)(totalPairedDevices, pairedDeviceList);

}
std::shared_ptr<DBus::Signal<void(std::tuple<std::vector<uint8_t>>)>> com_jci_bcaInterface::signal_SupportedProfilesResp() {
  return m_signal_SupportedProfilesResp;

}
void com_jci_bcaInterface::SupportedProfilesResp(std::tuple<std::vector<uint8_t>> supportedProfiles) {
  (*m_signal_SupportedProfilesResp)(supportedProfiles);

}
std::shared_ptr<DBus::Signal<void(bool)>> com_jci_bcaInterface::signal_FirstHfpSupportedInfo() {
  return m_signal_FirstHfpSupportedInfo;

}
void com_jci_bcaInterface::FirstHfpSupportedInfo(bool isHfpSupportedDevicePresent) {
  (*m_signal_FirstHfpSupportedInfo)(isHfpSupportedDevicePresent);

}
std::shared_ptr<DBus::Signal<void(uint32_t, uint32_t)>> com_jci_bcaInterface::signal_CarPlayConnectionStatus() {
  return m_signal_CarPlayConnectionStatus;

}
void com_jci_bcaInterface::CarPlayConnectionStatus(uint32_t connStatus, uint32_t carPlayDeviceId) {
  (*m_signal_CarPlayConnectionStatus)(connStatus, carPlayDeviceId);

}
std::shared_ptr<DBus::Signal<void()>> com_jci_bcaInterface::signal_AAutoEnableBt() {
  return m_signal_AAutoEnableBt;

}
void com_jci_bcaInterface::AAutoEnableBt() {
  (*m_signal_AAutoEnableBt)();

}
std::shared_ptr<DBus::Signal<void(uint32_t)>> com_jci_bcaInterface::signal_AAutoNoEntryAvailable() {
  return m_signal_AAutoNoEntryAvailable;

}
void com_jci_bcaInterface::AAutoNoEntryAvailable(uint32_t deleteDeviceId) {
  (*m_signal_AAutoNoEntryAvailable)(deleteDeviceId);

}
std::shared_ptr<DBus::Signal<void()>> com_jci_bcaInterface::signal_ReqStartAndroidAutoPairing() {
  return m_signal_ReqStartAndroidAutoPairing;

}
void com_jci_bcaInterface::ReqStartAndroidAutoPairing() {
  (*m_signal_ReqStartAndroidAutoPairing)();

}
std::shared_ptr<DBus::Signal<void()>> com_jci_bcaInterface::signal_ReqStopAndroidAutoPairing() {
  return m_signal_ReqStopAndroidAutoPairing;

}
void com_jci_bcaInterface::ReqStopAndroidAutoPairing() {
  (*m_signal_ReqStopAndroidAutoPairing)();

}
std::shared_ptr<DBus::Signal<void(uint32_t)>> com_jci_bcaInterface::signal_ReqDeleteDevice() {
  return m_signal_ReqDeleteDevice;

}
void com_jci_bcaInterface::ReqDeleteDevice(uint32_t deleteDeviceId) {
  (*m_signal_ReqDeleteDevice)(deleteDeviceId);

}
std::shared_ptr<DBus::Signal<void(bool)>> com_jci_bcaInterface::signal_AAPairingSeqResult() {
  return m_signal_AAPairingSeqResult;

}
void com_jci_bcaInterface::AAPairingSeqResult(bool result) {
  (*m_signal_AAPairingSeqResult)(result);

}
std::shared_ptr<DBus::Signal<void()>> com_jci_bcaInterface::signal_AndroidAutoPairingTimeout() {
  return m_signal_AndroidAutoPairingTimeout;

}
void com_jci_bcaInterface::AndroidAutoPairingTimeout() {
  (*m_signal_AndroidAutoPairingTimeout)();

}
std::shared_ptr<DBus::Signal<void(uint32_t)>> com_jci_bcaInterface::signal_RequestStartAutoDownload() {
  return m_signal_RequestStartAutoDownload;

}
void com_jci_bcaInterface::RequestStartAutoDownload(uint32_t btDeviceId) {
  (*m_signal_RequestStartAutoDownload)(btDeviceId);

}
std::shared_ptr<DBus::Signal<void(uint32_t)>> com_jci_bcaInterface::signal_DisableBluetoothRsp() {
  return m_signal_DisableBluetoothRsp;

}
void com_jci_bcaInterface::DisableBluetoothRsp(uint32_t activeCallStatus) {
  (*m_signal_DisableBluetoothRsp)(activeCallStatus);

}
std::shared_ptr<DBus::Signal<void()>> com_jci_bcaInterface::signal_ConnectingCarPlayError() {
  return m_signal_ConnectingCarPlayError;

}
void com_jci_bcaInterface::ConnectingCarPlayError() {
  (*m_signal_ConnectingCarPlayError)();

}
