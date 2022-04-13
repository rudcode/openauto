#include "com_jci_vbs_bcmProxy.h"

com_jci_vbs_bcmProxy::com_jci_vbs_bcmProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_GetCarSpeed = this->create_method<uint32_t(uint32_t)>("GetCarSpeed");
  m_method_GetCarSpeedThrshld = this->create_method<uint8_t(uint8_t)>("GetCarSpeedThrshld");
  m_method_GetPSMInfo = this->create_method<uint8_t()>("GetPSMInfo");
  m_method_GetBSMInfo = this->create_method<std::tuple<bool,
                                                       bool,
                                                       uint8_t,
                                                       uint8_t,
                                                       uint8_t,
                                                       bool,
                                                       bool,
                                                       bool,
                                                       bool,
                                                       bool,
                                                       bool,
                                                       uint8_t,
                                                       uint8_t>()>("GetBSMInfo");
  m_method_getEngineTransmissionType = this->create_method<uint8_t()>("getEngineTransmissionType");
  m_method_GetIgnitionStatus = this->create_method<uint8_t()>("GetIgnitionStatus");
  m_method_GetPublicCanStatus = this->create_method<uint8_t()>("GetPublicCanStatus");
  m_method_GetPrivateCanStatus = this->create_method<uint8_t()>("GetPrivateCanStatus");
  m_method_GetNoSpeedRestrict_TouchDisplay = this->create_method<uint8_t()>("GetNoSpeedRestrict_TouchDisplay");
  m_method_GetTouchDisplayCarSpeedThrshld = this->create_method<uint8_t(uint8_t)>("GetTouchDisplayCarSpeedThrshld");
  m_method_GetFuelCutOffStatus = this->create_method<uint8_t()>("GetFuelCutOffStatus");
  m_method_GetBrkPedalDepressedStatus = this->create_method<uint8_t()>("GetBrkPedalDepressedStatus");
  m_method_GetGearPos = this->create_method<uint8_t()>("GetGearPos");
  m_method_GetTransmChangeLeverPosition = this->create_method<uint8_t()>("GetTransmChangeLeverPosition");
  m_method_GetPrkBrkActv = this->create_method<uint8_t()>("GetPrkBrkActv");
  m_method_GetPASCD = this->create_method < std::tuple < std::vector < uint8_t >> () > ("GetPASCD");
  m_method_GetWheelSpeed =
      this->create_method<std::tuple<uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint64_t>()>(
          "GetWheelSpeed");
  m_method_GetVideoRestrict = this->create_method<uint8_t()>("GetVideoRestrict");
  m_signalproxy_CarSpeedResp = this->create_signal<void(uint32_t)>("CarSpeedResp");
  m_signalproxy_CarSpeedThresholdNotification = this->create_signal<void(uint8_t)>("CarSpeedThresholdNotification");
  m_signalproxy_AccidentTriggerNotifiction = this->create_signal<void(uint8_t)>("AccidentTriggerNotifiction");
  m_signalproxy_PSM_Information1 = this->create_signal<void(std::tuple < uint8_t,
                                                            uint8_t,
                                                            uint8_t,
                                                            uint8_t,
                                                            uint8_t,
                                                            uint8_t,
                                                            uint8_t,
                                                            uint8_t,
                                                            uint8_t,
                                                            uint8_t > )>("PSM_Information1");
  m_signalproxy_BSM_Information = this->create_signal<void(std::tuple < bool,
                                                           bool,
                                                           uint8_t,
                                                           uint8_t,
                                                           uint8_t,
                                                           bool,
                                                           bool,
                                                           bool,
                                                           bool,
                                                           bool,
                                                           bool,
                                                           uint8_t,
                                                           uint8_t > )>("BSM_Information");
  m_signalproxy_PublicCanStatusNotification = this->create_signal<void(uint8_t)>("PublicCanStatusNotification");
  m_signalproxy_PrivateCanStatusNotification = this->create_signal<void(uint8_t)>("PrivateCanStatusNotification");
  m_signalproxy_engineConfigResp = this->create_signal<void(uint8_t, std::tuple < uint8_t > )>("engineConfigResp");
  m_signalproxy_IgnitionControl_Status = this->create_signal<void(uint8_t)>("IgnitionControl_Status");
  m_signalproxy_NoSpeedRestrict_TouchDisplay = this->create_signal<void(uint8_t)>("NoSpeedRestrict_TouchDisplay");
  m_signalproxy_BatteryVoltageFlag = this->create_signal<void(bool)>("BatteryVoltageFlag");
  m_signalproxy_BrakePedalDepressedStatus = this->create_signal<void(uint8_t)>("BrakePedalDepressedStatus");
  m_signalproxy_GearPosNotification = this->create_signal<void(uint8_t)>("GearPosNotification");
  m_signalproxy_TransmChangeLeverPositionNotification =
      this->create_signal<void(uint8_t)>("TransmChangeLeverPositionNotification");
  m_signalproxy_PrkBrkActvNotification = this->create_signal<void(uint8_t)>("PrkBrkActvNotification");
  m_signalproxy_PASCDNotification =
      this->create_signal<void(std::tuple < std::vector < uint8_t >> )>("PASCDNotification");
  m_signalproxy_WheelSpeedNotification =
      this->create_signal<void(std::tuple < uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint64_t > )>(
          "WheelSpeedNotification");
  m_signalproxy_VideoRestrictNotification = this->create_signal<void(uint8_t)>("VideoRestrictNotification");

}
std::shared_ptr <com_jci_vbs_bcmProxy> com_jci_vbs_bcmProxy::create(std::string name) {
  return std::shared_ptr<com_jci_vbs_bcmProxy>(new com_jci_vbs_bcmProxy(name));

}
uint32_t com_jci_vbs_bcmProxy::GetCarSpeed(uint32_t speedUnit) {
  return (*m_method_GetCarSpeed)(speedUnit);

}
uint8_t com_jci_vbs_bcmProxy::GetCarSpeedThrshld(uint8_t speedUnit) {
  return (*m_method_GetCarSpeedThrshld)(speedUnit);

}
uint8_t com_jci_vbs_bcmProxy::GetPSMInfo() {
  return (*m_method_GetPSMInfo)();

}
std::tuple<bool,
           bool, uint8_t, uint8_t, uint8_t,
           bool,
           bool,
           bool,
           bool,
           bool,
           bool, uint8_t, uint8_t> com_jci_vbs_bcmProxy::GetBSMInfo() {
  return (*m_method_GetBSMInfo)();

}
uint8_t com_jci_vbs_bcmProxy::getEngineTransmissionType() {
  return (*m_method_getEngineTransmissionType)();

}
uint8_t com_jci_vbs_bcmProxy::GetIgnitionStatus() {
  return (*m_method_GetIgnitionStatus)();

}
uint8_t com_jci_vbs_bcmProxy::GetPublicCanStatus() {
  return (*m_method_GetPublicCanStatus)();

}
uint8_t com_jci_vbs_bcmProxy::GetPrivateCanStatus() {
  return (*m_method_GetPrivateCanStatus)();

}
uint8_t com_jci_vbs_bcmProxy::GetNoSpeedRestrict_TouchDisplay() {
  return (*m_method_GetNoSpeedRestrict_TouchDisplay)();

}
uint8_t com_jci_vbs_bcmProxy::GetTouchDisplayCarSpeedThrshld(uint8_t speedUnit) {
  return (*m_method_GetTouchDisplayCarSpeedThrshld)(speedUnit);

}
uint8_t com_jci_vbs_bcmProxy::GetFuelCutOffStatus() {
  return (*m_method_GetFuelCutOffStatus)();

}
uint8_t com_jci_vbs_bcmProxy::GetBrkPedalDepressedStatus() {
  return (*m_method_GetBrkPedalDepressedStatus)();

}
uint8_t com_jci_vbs_bcmProxy::GetGearPos() {
  return (*m_method_GetGearPos)();

}
uint8_t com_jci_vbs_bcmProxy::GetTransmChangeLeverPosition() {
  return (*m_method_GetTransmChangeLeverPosition)();

}
uint8_t com_jci_vbs_bcmProxy::GetPrkBrkActv() {
  return (*m_method_GetPrkBrkActv)();

}
std::tuple <std::vector<uint8_t>> com_jci_vbs_bcmProxy::GetPASCD() {
  return (*m_method_GetPASCD)();

}
std::tuple <uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint64_t> com_jci_vbs_bcmProxy::GetWheelSpeed() {
  return (*m_method_GetWheelSpeed)();

}
uint8_t com_jci_vbs_bcmProxy::GetVideoRestrict() {
  return (*m_method_GetVideoRestrict)();

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_vbs_bcmProxy::signal_CarSpeedResp() {
  return m_signalproxy_CarSpeedResp;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_bcmProxy::signal_CarSpeedThresholdNotification() {
  return m_signalproxy_CarSpeedThresholdNotification;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_bcmProxy::signal_AccidentTriggerNotifiction() {
  return m_signalproxy_AccidentTriggerNotifiction;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t > )>> com_jci_vbs_bcmProxy::signal_PSM_Information1() {
  return m_signalproxy_PSM_Information1;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < bool,
                                        bool,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        bool,
                                        bool,
                                        bool,
                                        bool,
                                        bool,
                                        bool,
                                        uint8_t,
                                        uint8_t > )>> com_jci_vbs_bcmProxy::signal_BSM_Information() {
  return m_signalproxy_BSM_Information;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_bcmProxy::signal_PublicCanStatusNotification() {
  return m_signalproxy_PublicCanStatusNotification;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_bcmProxy::signal_PrivateCanStatusNotification() {
  return m_signalproxy_PrivateCanStatusNotification;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t,
                                        std::tuple < uint8_t > )>> com_jci_vbs_bcmProxy::signal_engineConfigResp() {
  return m_signalproxy_engineConfigResp;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_bcmProxy::signal_IgnitionControl_Status() {
  return m_signalproxy_IgnitionControl_Status;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_bcmProxy::signal_NoSpeedRestrict_TouchDisplay() {
  return m_signalproxy_NoSpeedRestrict_TouchDisplay;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_vbs_bcmProxy::signal_BatteryVoltageFlag() {
  return m_signalproxy_BatteryVoltageFlag;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_bcmProxy::signal_BrakePedalDepressedStatus() {
  return m_signalproxy_BrakePedalDepressedStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_bcmProxy::signal_GearPosNotification() {
  return m_signalproxy_GearPosNotification;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_bcmProxy::signal_TransmChangeLeverPositionNotification() {
  return m_signalproxy_TransmChangeLeverPositionNotification;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_bcmProxy::signal_PrkBrkActvNotification() {
  return m_signalproxy_PrkBrkActvNotification;

}
std::shared_ptr <DBus::SignalProxy<void(
    std::tuple < std::vector < uint8_t >> )>> com_jci_vbs_bcmProxy::signal_PASCDNotification() {
  return m_signalproxy_PASCDNotification;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint16_t,
                                        uint16_t,
                                        uint16_t,
                                        uint16_t,
                                        uint16_t,
                                        uint16_t,
                                        uint64_t > )>> com_jci_vbs_bcmProxy::signal_WheelSpeedNotification() {
  return m_signalproxy_WheelSpeedNotification;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_vbs_bcmProxy::signal_VideoRestrictNotification() {
  return m_signalproxy_VideoRestrictNotification;

}
