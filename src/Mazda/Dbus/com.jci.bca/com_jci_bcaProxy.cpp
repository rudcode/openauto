#include "com_jci_bcaProxy.h"

com_jci_bcaProxy::com_jci_bcaProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_ConnectRequest = this->create_method<int32_t(uint32_t, uint32_t)>("ConnectRequest");
  m_method_ConnectRequestHfpAndAvp = this->create_method<int32_t(uint32_t)>("ConnectRequestHfpAndAvp");
  m_method_DisconnectRequest = this->create_method<int32_t(uint32_t, uint32_t)>("DisconnectRequest");
  m_method_DisconnectRequestHfpAndAvp = this->create_method<int32_t(uint32_t, uint32_t)>("DisconnectRequestHfpAndAvp");
  m_method_CancelConnect = this->create_method<int32_t(bool)>("CancelConnect");
  m_method_GetConnectStatus = this->create_method<int32_t(uint32_t)>("GetConnectStatus");
  m_method_QueryConnectStatus =
      this->create_method<std::tuple<int32_t, int32_t, int32_t, int32_t, std::tuple<std::vector<uint8_t>>>(uint32_t)>(
          "QueryConnectStatus");
  m_method_UnbarDevice = this->create_method<int32_t(uint32_t)>("UnbarDevice");
  m_method_BluetoothOn = this->create_method<int32_t(bool)>("BluetoothOn");
  m_method_BluetoothOff = this->create_method<int32_t(bool)>("BluetoothOff");
  m_method_StartAdd = this->create_method<int32_t(uint32_t)>("StartAdd");
  m_method_ConnectAll = this->create_method<int32_t(uint32_t)>("ConnectAll");
  m_method_DisconnectAll = this->create_method<int32_t()>("DisconnectAll");
  m_method_GetServiceId = this->create_method<int32_t(uint32_t)>("GetServiceId");
  m_method_ReadBluetoothSetting = this->create_method<int32_t()>("ReadBluetoothSetting");
  m_method_AvailablePairedDeviceList = this->create_method<int32_t()>("AvailablePairedDeviceList");
  m_method_GetFeatureStatus = this->create_method<DBus::MultipleReturn<int32_t, int32_t>()>("GetFeatureStatus");
  m_method_SupportedProfiles = this->create_method<int32_t(uint32_t)>("SupportedProfiles");
  m_method_SetDontShowOnConnectionSetting =
      this->create_method<int32_t(uint32_t, bool)>("SetDontShowOnConnectionSetting");
  m_method_GetDontShowOnConnectionSetting = this->create_method<int32_t(uint32_t)>("GetDontShowOnConnectionSetting");
  m_method_AAutoEnableBtResponse = this->create_method<int32_t(uint32_t)>("AAutoEnableBtResponse");
  m_method_AAutoNoEntryAvailableResponse = this->create_method<int32_t(uint32_t)>("AAutoNoEntryAvailableResponse");
  m_method_PairingStatus = this->create_method<int32_t(uint32_t, uint32_t)>("PairingStatus");
  m_method_DeviceDeleteStatus = this->create_method<int32_t(uint32_t)>("DeviceDeleteStatus");
  m_method_CallStatus = this->create_method<int32_t(uint32_t, uint32_t, uint32_t)>("CallStatus");
  m_method_SetCommSettingsResetStatus = this->create_method<int32_t(uint32_t)>("SetCommSettingsResetStatus");
  m_method_SetMP911EmergencyCallStatus = this->create_method<int32_t(uint32_t)>("SetMP911EmergencyCallStatus");
  m_signalproxy_DontShowOnConnectionSettingStatusResp =
      this->create_signal<void(uint32_t, bool)>("DontShowOnConnectionSettingStatusResp");
  m_signalproxy_ConnectionStatusResp =
      this->create_signal<void(uint32_t, uint32_t, uint32_t, uint32_t, std::tuple<std::vector<uint8_t>>)>(
          "ConnectionStatusResp");
  m_signalproxy_HftReadyStatus = this->create_signal<void(uint32_t, uint32_t, uint32_t)>("HftReadyStatus");
  m_signalproxy_ReadyStatus = this->create_signal<void(uint32_t, uint32_t)>("ReadyStatus");
  m_signalproxy_AddStatusResp = this->create_signal<void(uint32_t, uint32_t)>("AddStatusResp");
  m_signalproxy_DeviceUnbarringStatusResp = this->create_signal<void(uint32_t, uint32_t)>("DeviceUnbarringStatusResp");
  m_signalproxy_DeviceBluetoothSettingResp = this->create_signal<void(bool)>("DeviceBluetoothSettingResp");
  m_signalproxy_AvailablePairedListResp =
      this->create_signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>("AvailablePairedListResp");
  m_signalproxy_SupportedProfilesResp =
      this->create_signal<void(std::tuple<std::vector<uint8_t>>)>("SupportedProfilesResp");
  m_signalproxy_FirstHfpSupportedInfo = this->create_signal<void(bool)>("FirstHfpSupportedInfo");
  m_signalproxy_CarPlayConnectionStatus = this->create_signal<void(uint32_t, uint32_t)>("CarPlayConnectionStatus");
  m_signalproxy_AAutoEnableBt = this->create_signal<void()>("AAutoEnableBt");
  m_signalproxy_AAutoNoEntryAvailable = this->create_signal<void(uint32_t)>("AAutoNoEntryAvailable");
  m_signalproxy_ReqStartAndroidAutoPairing = this->create_signal<void()>("ReqStartAndroidAutoPairing");
  m_signalproxy_ReqStopAndroidAutoPairing = this->create_signal<void()>("ReqStopAndroidAutoPairing");
  m_signalproxy_ReqDeleteDevice = this->create_signal<void(uint32_t)>("ReqDeleteDevice");
  m_signalproxy_AAPairingSeqResult = this->create_signal<void(bool)>("AAPairingSeqResult");
  m_signalproxy_AndroidAutoPairingTimeout = this->create_signal<void()>("AndroidAutoPairingTimeout");
  m_signalproxy_RequestStartAutoDownload = this->create_signal<void(uint32_t)>("RequestStartAutoDownload");
  m_signalproxy_DisableBluetoothRsp = this->create_signal<void(uint32_t)>("DisableBluetoothRsp");
  m_signalproxy_ConnectingCarPlayError = this->create_signal<void()>("ConnectingCarPlayError");

}
std::shared_ptr<com_jci_bcaProxy> com_jci_bcaProxy::create(std::string name) {
  return std::shared_ptr<com_jci_bcaProxy>(new com_jci_bcaProxy(name));

}
int32_t com_jci_bcaProxy::ConnectRequest(uint32_t serviceId, uint32_t btDeviceId) {
  return (*m_method_ConnectRequest)(serviceId, btDeviceId);

}
int32_t com_jci_bcaProxy::ConnectRequestHfpAndAvp(uint32_t btDeviceId) {
  return (*m_method_ConnectRequestHfpAndAvp)(btDeviceId);

}
int32_t com_jci_bcaProxy::DisconnectRequest(uint32_t serviceId, uint32_t btDeviceId) {
  return (*m_method_DisconnectRequest)(serviceId, btDeviceId);

}
int32_t com_jci_bcaProxy::DisconnectRequestHfpAndAvp(uint32_t btHfpDeviceId, uint32_t btAvpDeviceId) {
  return (*m_method_DisconnectRequestHfpAndAvp)(btHfpDeviceId, btAvpDeviceId);

}
int32_t com_jci_bcaProxy::CancelConnect(bool cancelConnect) {
  return (*m_method_CancelConnect)(cancelConnect);

}
int32_t com_jci_bcaProxy::GetConnectStatus(uint32_t serviceId) {
  return (*m_method_GetConnectStatus)(serviceId);

}
std::tuple<int32_t, int32_t, int32_t, int32_t, std::tuple<std::vector<uint8_t>>> com_jci_bcaProxy::QueryConnectStatus(
    uint32_t serviceId) {
  return (*m_method_QueryConnectStatus)(serviceId);

}
int32_t com_jci_bcaProxy::UnbarDevice(uint32_t btDeviceId) {
  return (*m_method_UnbarDevice)(btDeviceId);

}
int32_t com_jci_bcaProxy::BluetoothOn(bool isInfoToBeUpdatedToFlash) {
  return (*m_method_BluetoothOn)(isInfoToBeUpdatedToFlash);

}
int32_t com_jci_bcaProxy::BluetoothOff(bool isInfoToBeUpdatedToFlash) {
  return (*m_method_BluetoothOff)(isInfoToBeUpdatedToFlash);

}
int32_t com_jci_bcaProxy::StartAdd(uint32_t addServiceId) {
  return (*m_method_StartAdd)(addServiceId);

}
int32_t com_jci_bcaProxy::ConnectAll(uint32_t btDeviceId) {
  return (*m_method_ConnectAll)(btDeviceId);

}
int32_t com_jci_bcaProxy::DisconnectAll() {
  return (*m_method_DisconnectAll)();

}
int32_t com_jci_bcaProxy::GetServiceId(uint32_t serviceType) {
  return (*m_method_GetServiceId)(serviceType);

}
int32_t com_jci_bcaProxy::ReadBluetoothSetting() {
  return (*m_method_ReadBluetoothSetting)();

}
int32_t com_jci_bcaProxy::AvailablePairedDeviceList() {
  return (*m_method_AvailablePairedDeviceList)();

}
DBus::MultipleReturn<int32_t, int32_t> com_jci_bcaProxy::GetFeatureStatus() {
  return (*m_method_GetFeatureStatus)();

}
int32_t com_jci_bcaProxy::SupportedProfiles(uint32_t btDeviceId) {
  return (*m_method_SupportedProfiles)(btDeviceId);

}
int32_t com_jci_bcaProxy::SetDontShowOnConnectionSetting(uint32_t btDeviceId, bool setting) {
  return (*m_method_SetDontShowOnConnectionSetting)(btDeviceId, setting);

}
int32_t com_jci_bcaProxy::GetDontShowOnConnectionSetting(uint32_t btDeviceId) {
  return (*m_method_GetDontShowOnConnectionSetting)(btDeviceId);

}
int32_t com_jci_bcaProxy::AAutoEnableBtResponse(uint32_t select) {
  return (*m_method_AAutoEnableBtResponse)(select);

}
int32_t com_jci_bcaProxy::AAutoNoEntryAvailableResponse(uint32_t select) {
  return (*m_method_AAutoNoEntryAvailableResponse)(select);

}
int32_t com_jci_bcaProxy::PairingStatus(uint32_t status, uint32_t error) {
  return (*m_method_PairingStatus)(status, error);

}
int32_t com_jci_bcaProxy::DeviceDeleteStatus(uint32_t deleteStatus) {
  return (*m_method_DeviceDeleteStatus)(deleteStatus);

}
int32_t com_jci_bcaProxy::CallStatus(uint32_t bthfstate, uint32_t call1status, uint32_t call2status) {
  return (*m_method_CallStatus)(bthfstate, call1status, call2status);

}
int32_t com_jci_bcaProxy::SetCommSettingsResetStatus(uint32_t status) {
  return (*m_method_SetCommSettingsResetStatus)(status);

}
int32_t com_jci_bcaProxy::SetMP911EmergencyCallStatus(uint32_t status) {
  return (*m_method_SetMP911EmergencyCallStatus)(status);

}
std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                       bool)>> com_jci_bcaProxy::signal_DontShowOnConnectionSettingStatusResp() {
  return m_signalproxy_DontShowOnConnectionSettingStatusResp;

}
std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                       uint32_t,
                                       uint32_t,
                                       uint32_t,
                                       std::tuple<std::vector<uint8_t>>)>> com_jci_bcaProxy::signal_ConnectionStatusResp() {
  return m_signalproxy_ConnectionStatusResp;

}
std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t, uint32_t)>> com_jci_bcaProxy::signal_HftReadyStatus() {
  return m_signalproxy_HftReadyStatus;

}
std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> com_jci_bcaProxy::signal_ReadyStatus() {
  return m_signalproxy_ReadyStatus;

}
std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> com_jci_bcaProxy::signal_AddStatusResp() {
  return m_signalproxy_AddStatusResp;

}
std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> com_jci_bcaProxy::signal_DeviceUnbarringStatusResp() {
  return m_signalproxy_DeviceUnbarringStatusResp;

}
std::shared_ptr<DBus::SignalProxy<void(bool)>> com_jci_bcaProxy::signal_DeviceBluetoothSettingResp() {
  return m_signalproxy_DeviceBluetoothSettingResp;

}
std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                       std::tuple<std::vector<uint8_t>>)>> com_jci_bcaProxy::signal_AvailablePairedListResp() {
  return m_signalproxy_AvailablePairedListResp;

}
std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> com_jci_bcaProxy::signal_SupportedProfilesResp() {
  return m_signalproxy_SupportedProfilesResp;

}
std::shared_ptr<DBus::SignalProxy<void(bool)>> com_jci_bcaProxy::signal_FirstHfpSupportedInfo() {
  return m_signalproxy_FirstHfpSupportedInfo;

}
std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> com_jci_bcaProxy::signal_CarPlayConnectionStatus() {
  return m_signalproxy_CarPlayConnectionStatus;

}
std::shared_ptr<DBus::SignalProxy<void()>> com_jci_bcaProxy::signal_AAutoEnableBt() {
  return m_signalproxy_AAutoEnableBt;

}
std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> com_jci_bcaProxy::signal_AAutoNoEntryAvailable() {
  return m_signalproxy_AAutoNoEntryAvailable;

}
std::shared_ptr<DBus::SignalProxy<void()>> com_jci_bcaProxy::signal_ReqStartAndroidAutoPairing() {
  return m_signalproxy_ReqStartAndroidAutoPairing;

}
std::shared_ptr<DBus::SignalProxy<void()>> com_jci_bcaProxy::signal_ReqStopAndroidAutoPairing() {
  return m_signalproxy_ReqStopAndroidAutoPairing;

}
std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> com_jci_bcaProxy::signal_ReqDeleteDevice() {
  return m_signalproxy_ReqDeleteDevice;

}
std::shared_ptr<DBus::SignalProxy<void(bool)>> com_jci_bcaProxy::signal_AAPairingSeqResult() {
  return m_signalproxy_AAPairingSeqResult;

}
std::shared_ptr<DBus::SignalProxy<void()>> com_jci_bcaProxy::signal_AndroidAutoPairingTimeout() {
  return m_signalproxy_AndroidAutoPairingTimeout;

}
std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> com_jci_bcaProxy::signal_RequestStartAutoDownload() {
  return m_signalproxy_RequestStartAutoDownload;

}
std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> com_jci_bcaProxy::signal_DisableBluetoothRsp() {
  return m_signalproxy_DisableBluetoothRsp;

}
std::shared_ptr<DBus::SignalProxy<void()>> com_jci_bcaProxy::signal_ConnectingCarPlayError() {
  return m_signalproxy_ConnectingCarPlayError;

}
