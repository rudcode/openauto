#include "com_jci_ittsProxy.h"

com_jci_ittsProxy::com_jci_ittsProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_RequestMemoryInfo =
      this->create_method < DBus::MultipleReturn < std::tuple < std::vector < std::tuple < uint32_t, uint32_t, int32_t
      >>, uint32_t >, int32_t > (std::tuple < std::vector < uint32_t >> ) > ("RequestMemoryInfo");
  m_method_StoreTag = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector < std::tuple
      < uint32_t, uint32_t, int32_t >>, uint32_t >> (uint32_t, std::tuple < std::vector < uint32_t >>) > ("StoreTag");
  m_method_TransferTag = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector < std::tuple
      < uint32_t, uint32_t, uint32_t >>, uint32_t, uint32_t >> (uint32_t, std::tuple < std::vector < uint32_t >>)
      > ("TransferTag");
  m_method_RadioConnectionStatus = this->create_method<int32_t(uint8_t)>("RadioConnectionStatus");
  m_method_RadioModeChange = this->create_method<int32_t(int32_t)>("RadioModeChange");
  m_method_RadioOnOff = this->create_method<int32_t(uint8_t)>("RadioOnOff");
  m_method_RadioStationChange = this->create_method<int32_t(uint16_t)>("RadioStationChange");
  m_method_RadioTrackChange = this->create_method<int32_t(uint8_t)>("RadioTrackChange");
  m_method_UpdateMetadata = this->create_method<int32_t(std::tuple < std::vector < uint8_t >> )>("UpdateMetadata");
  m_method_ClearNVM = this->create_method<DBus::MultipleReturn<uint32_t, int32_t>(uint32_t)>("ClearNVM");
  m_method_CheckConnDev = this->create_method<int32_t()>("CheckConnDev");
  m_signalproxy_AppleDevConnected =
      this->create_signal<void(std::tuple < uint32_t, std::string, int32_t, uint32_t > , bool)>("AppleDevConnected");
  m_signalproxy_AppleDevDisconnected = this->create_signal<void(int32_t)>("AppleDevDisconnected");
  m_signalproxy_TaggingAvailable = this->create_signal<void(int32_t)>("TaggingAvailable");
  m_signalproxy_TaggingErrorDevice = this->create_signal<void(int32_t)>("TaggingErrorDevice");

}
std::shared_ptr <com_jci_ittsProxy> com_jci_ittsProxy::create(std::string name) {
  return std::shared_ptr<com_jci_ittsProxy>(new com_jci_ittsProxy(name));

}
DBus::MultipleReturn <std::tuple<std::vector < std::tuple < uint32_t, uint32_t, int32_t>>,uint32_t>,int32_t>
com_jci_ittsProxy::RequestMemoryInfo(std::tuple<std::vector < uint32_t>>
devIdList ){
return (*m_method_RequestMemoryInfo)(devIdList);

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < std::tuple < uint32_t, uint32_t, int32_t>>,uint32_t>>
com_jci_ittsProxy::StoreTag(uint32_t
tagMaxCntFlash,
std::tuple <std::vector<uint32_t>> devIdList
){
return (*m_method_StoreTag)(tagMaxCntFlash,devIdList);

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < std::tuple < uint32_t, uint32_t, uint32_t>>,uint32_t,uint32_t>>
com_jci_ittsProxy::TransferTag(uint32_t
tagMaxCntiPod,
std::tuple <std::vector<uint32_t>> devIdList
){
return (*m_method_TransferTag)(tagMaxCntiPod,devIdList);

}
int32_t com_jci_ittsProxy::RadioConnectionStatus(uint8_t connectStandbyStat) {
  return (*m_method_RadioConnectionStatus)(connectStandbyStat);

}
int32_t com_jci_ittsProxy::RadioModeChange(int32_t modeChangeSrc) {
  return (*m_method_RadioModeChange)(modeChangeSrc);

}
int32_t com_jci_ittsProxy::RadioOnOff(uint8_t radioOnOffStatus) {
  return (*m_method_RadioOnOff)(radioOnOffStatus);

}
int32_t com_jci_ittsProxy::RadioStationChange(uint16_t frequency) {
  return (*m_method_RadioStationChange)(frequency);

}
int32_t com_jci_ittsProxy::RadioTrackChange(uint8_t trackChange) {
  return (*m_method_RadioTrackChange)(trackChange);

}
int32_t com_jci_ittsProxy::UpdateMetadata(std::tuple <std::vector<uint8_t>> tagInfo) {
  return (*m_method_UpdateMetadata)(tagInfo);

}
DBus::MultipleReturn <uint32_t, int32_t> com_jci_ittsProxy::ClearNVM(uint32_t
tagsToClearCnt ){
return (*m_method_ClearNVM)(tagsToClearCnt);

}
int32_t com_jci_ittsProxy::CheckConnDev() {
  return (*m_method_CheckConnDev)();

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        std::string,
                                        int32_t,
                                        uint32_t > ,
                                        bool)>> com_jci_ittsProxy::signal_AppleDevConnected() {
  return m_signalproxy_AppleDevConnected;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_ittsProxy::signal_AppleDevDisconnected() {
  return m_signalproxy_AppleDevDisconnected;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_ittsProxy::signal_TaggingAvailable() {
  return m_signalproxy_TaggingAvailable;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_ittsProxy::signal_TaggingErrorDevice() {
  return m_signalproxy_TaggingErrorDevice;

}
