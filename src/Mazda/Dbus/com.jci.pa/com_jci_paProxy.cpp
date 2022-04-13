#include "com_jci_paProxy.h"

com_jci_paProxy::com_jci_paProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_StartPair = this->create_method<int32_t(uint32_t)>("StartPair");
  m_method_AbortPair = this->create_method<int32_t(uint32_t)>("AbortPair");
  m_method_PairToSelectedDevice =
      this->create_method<int32_t(std::tuple < std::vector < uint8_t >> )>("PairToSelectedDevice");
  m_method_PairNumericCompResponse = this->create_method<int32_t(bool)>("PairNumericCompResponse");
  m_method_DeleteDevice = this->create_method<int32_t(uint32_t)>("DeleteDevice");
  m_method_DeleteAllDevices = this->create_method<int32_t()>("DeleteAllDevices");
  m_method_RequestSearchDeviceList = this->create_method<int32_t()>("RequestSearchDeviceList");
  m_method_GetPairingPinCode = this->create_method<int32_t()>("GetPairingPinCode");
  m_method_SetPairingPinCode =
      this->create_method<int32_t(std::tuple < std::vector < uint8_t >> )>("SetPairingPinCode");
  m_method_GetPairingModuleSettings = this->create_method<int32_t()>("GetPairingModuleSettings");
  m_method_RetrieveVehicleBtInfo = this->create_method<int32_t()>("RetrieveVehicleBtInfo");
  m_signalproxy_HftReadyStatus = this->create_signal<void(uint32_t, uint32_t)>("HftReadyStatus");
  m_signalproxy_PairingStatusResp =
      this->create_signal<void(std::tuple < std::vector < uint8_t >> )>("PairingStatusResp");
  m_signalproxy_DeleteStatusResp = this->create_signal<void(uint32_t, uint32_t)>("DeleteStatusResp");
  m_signalproxy_SearchedDeviceListResp = this->create_signal<void(uint32_t,
                                                                  uint32_t,
                                                                  uint32_t,
                                                                  std::tuple < std::vector < uint8_t >> ,
                                                                  std::tuple < std::vector < uint8_t >> )>(
      "SearchedDeviceListResp");
  m_signalproxy_RequestedSearchListResp =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("RequestedSearchListResp");
  m_signalproxy_AuthenticationResp = this->create_signal<void()>("AuthenticationResp");
  m_signalproxy_PairingPinCodeResp =
      this->create_signal<void(std::tuple < std::vector < uint8_t >> )>("PairingPinCodeResp");
  m_signalproxy_PairingModuleResp =
      this->create_signal<void(std::tuple < std::vector < uint8_t >> )>("PairingModuleResp");
  m_signalproxy_VehicleBtInformationResp =
      this->create_signal<void(std::tuple < std::vector < uint8_t >> )>("VehicleBtInformationResp");

}
std::shared_ptr <com_jci_paProxy> com_jci_paProxy::create(std::string name) {
  return std::shared_ptr<com_jci_paProxy>(new com_jci_paProxy(name));

}
int32_t com_jci_paProxy::StartPair(uint32_t pairMode) {
  return (*m_method_StartPair)(pairMode);

}
int32_t com_jci_paProxy::AbortPair(uint32_t abortMode) {
  return (*m_method_AbortPair)(abortMode);

}
int32_t com_jci_paProxy::PairToSelectedDevice(std::tuple <std::vector<uint8_t>> btaddress) {
  return (*m_method_PairToSelectedDevice)(btaddress);

}
int32_t com_jci_paProxy::PairNumericCompResponse(bool isPassecodeMatched) {
  return (*m_method_PairNumericCompResponse)(isPassecodeMatched);

}
int32_t com_jci_paProxy::DeleteDevice(uint32_t deviceId) {
  return (*m_method_DeleteDevice)(deviceId);

}
int32_t com_jci_paProxy::DeleteAllDevices() {
  return (*m_method_DeleteAllDevices)();

}
int32_t com_jci_paProxy::RequestSearchDeviceList() {
  return (*m_method_RequestSearchDeviceList)();

}
int32_t com_jci_paProxy::GetPairingPinCode() {
  return (*m_method_GetPairingPinCode)();

}
int32_t com_jci_paProxy::SetPairingPinCode(std::tuple <std::vector<uint8_t>> pinCode) {
  return (*m_method_SetPairingPinCode)(pinCode);

}
int32_t com_jci_paProxy::GetPairingModuleSettings() {
  return (*m_method_GetPairingModuleSettings)();

}
int32_t com_jci_paProxy::RetrieveVehicleBtInfo() {
  return (*m_method_RetrieveVehicleBtInfo)();

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, uint32_t)>> com_jci_paProxy::signal_HftReadyStatus() {
  return m_signalproxy_HftReadyStatus;

}
std::shared_ptr <DBus::SignalProxy<void(
    std::tuple < std::vector < uint8_t >> )>> com_jci_paProxy::signal_PairingStatusResp() {
  return m_signalproxy_PairingStatusResp;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, uint32_t)>> com_jci_paProxy::signal_DeleteStatusResp() {
  return m_signalproxy_DeleteStatusResp;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        uint32_t,
                                        uint32_t,
                                        std::tuple < std::vector < uint8_t >> ,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_paProxy::signal_SearchedDeviceListResp() {
  return m_signalproxy_SearchedDeviceListResp;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_paProxy::signal_RequestedSearchListResp() {
  return m_signalproxy_RequestedSearchListResp;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_paProxy::signal_AuthenticationResp() {
  return m_signalproxy_AuthenticationResp;

}
std::shared_ptr <DBus::SignalProxy<void(
    std::tuple < std::vector < uint8_t >> )>> com_jci_paProxy::signal_PairingPinCodeResp() {
  return m_signalproxy_PairingPinCodeResp;

}
std::shared_ptr <DBus::SignalProxy<void(
    std::tuple < std::vector < uint8_t >> )>> com_jci_paProxy::signal_PairingModuleResp() {
  return m_signalproxy_PairingModuleResp;

}
std::shared_ptr <DBus::SignalProxy<void(
    std::tuple < std::vector < uint8_t >> )>> com_jci_paProxy::signal_VehicleBtInformationResp() {
  return m_signalproxy_VehicleBtInformationResp;

}
