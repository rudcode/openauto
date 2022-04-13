#include "com_jci_lvdsProxy.h"

com_jci_lvdsProxy::com_jci_lvdsProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_SetBrightness =
      this->create_method<int16_t(std::tuple < uint32_t, uint32_t, uint8_t, uint8_t > )>("SetBrightness");
  m_method_GetSoftwareTPVersion =
      this->create_method<std::string(std::tuple < uint32_t, uint32_t, uint8_t, uint8_t > )>("GetSoftwareTPVersion");
  m_method_GetSoftwareDispVersion =
      this->create_method<std::string(std::tuple < uint32_t, uint32_t, uint8_t, uint8_t > )>("GetSoftwareDispVersion");
  m_method_SetNormalMode =
      this->create_method<std::string(std::tuple < uint32_t, uint32_t, uint8_t, uint8_t > )>("SetNormalMode");
  m_method_SetSleepMode =
      this->create_method<std::string(std::tuple < uint32_t, uint32_t, uint8_t, uint8_t > )>("SetSleepMode");
  m_method_SetDiagMode =
      this->create_method<std::string(std::tuple < uint32_t, uint32_t, uint8_t, uint8_t > )>("SetDiagMode");
  m_method_SetExtendMode =
      this->create_method<std::string(std::tuple < uint32_t, uint32_t, uint8_t, uint8_t > )>("SetExtendMode");
  m_method_SetACCOff = this->create_method<int16_t(std::tuple < uint32_t, uint32_t, uint8_t, uint8_t > )>("SetACCOff");
  m_method_SetDispOn = this->create_method<int16_t(std::tuple < uint32_t, uint32_t, uint8_t, uint8_t > )>("SetDispOn");
  m_method_SetDispOff =
      this->create_method<int16_t(std::tuple < uint32_t, uint32_t, uint8_t, uint8_t > )>("SetDispOff");
  m_method_EnablePRBS =
      this->create_method<std::string(std::tuple < uint32_t, uint32_t, uint8_t, uint8_t > )>("EnablePRBS");
  m_method_DisablePRBS =
      this->create_method<std::string(std::tuple < uint32_t, uint32_t, uint8_t, uint8_t > )>("DisablePRBS");
  m_method_PRBSReport =
      this->create_method<std::string(std::tuple < uint32_t, uint32_t, uint8_t, uint8_t > )>("PRBSReport");
  m_method_SystemACCMonitoring = this->create_method<uint32_t(uint32_t)>("SystemACCMonitoring");
  m_method_SpeedRestriction = this->create_method<uint32_t(uint32_t)>("SpeedRestriction");
  m_method_SetHdcpMode = this->create_method<uint32_t(uint32_t)>("SetHdcpMode");
  m_method_GetErrorEncounteredStatus = this->create_method<uint32_t()>("GetErrorEncounteredStatus");
  m_method_BlmLvdsReady = this->create_method<uint32_t(uint32_t)>("BlmLvdsReady");
  m_method_FaultStatusResponse = this->create_method<uint32_t(uint32_t, uint32_t)>("FaultStatusResponse");
  m_method_GetDisplayStatus = this->create_method<uint32_t(uint32_t)>("GetDisplayStatus");
  m_method_GetHdcpState = this->create_method<uint32_t()>("GetHdcpState");
  m_method_SetVideoTuning =
      this->create_method<uint32_t(std::tuple < uint32_t, uint32_t, uint32_t, uint32_t > )>("SetVideoTuning");
  m_method_GetTunedValues = this->create_method<uint32_t(uint32_t)>("GetTunedValues");
  m_method_GetRegisterDump = this->create_method<uint32_t(uint32_t, bool, uint8_t, uint8_t)>("GetRegisterDump");
  m_method_TouchSimulation = this->create_method<uint32_t(Invalid)>("TouchSimulation");
  m_method_BrightnessRamp =
      this->create_method<int16_t(std::tuple < uint32_t, uint32_t, uint8_t, uint8_t > )>("BrightnessRamp");
  m_method_SetSpreadSpectrum = this->create_method<uint32_t(uint32_t)>("SetSpreadSpectrum");
  m_method_SetCMLLevel = this->create_method<uint32_t(uint32_t)>("SetCMLLevel");
  m_signalproxy_brightNessLevelResp = this->create_signal<void(int16_t)>("brightNessLevelResp");
  m_signalproxy_TPVersionResp = this->create_signal<void(std::tuple < uint32_t, std::string > )>("TPVersionResp");
  m_signalproxy_displayVersion = this->create_signal<void(std::tuple < uint32_t, std::string > )>("displayVersion");
  m_signalproxy_NormalModeResp = this->create_signal<void(int16_t)>("NormalModeResp");
  m_signalproxy_SleepModeResp = this->create_signal<void(int16_t)>("SleepModeResp");
  m_signalproxy_DiagModeResp = this->create_signal<void(int16_t)>("DiagModeResp");
  m_signalproxy_ExtendModeResp = this->create_signal<void(int16_t)>("ExtendModeResp");
  m_signalproxy_EnablePRBSResp = this->create_signal<void(int16_t)>("EnablePRBSResp");
  m_signalproxy_DisablePRBSResp = this->create_signal<void(int16_t)>("DisablePRBSResp");
  m_signalproxy_PRBSReportResp = this->create_signal<void(int16_t)>("PRBSReportResp");
  m_signalproxy_ACCOffResp = this->create_signal<void(int16_t)>("ACCOffResp");
  m_signalproxy_DispOnResp = this->create_signal<void(int16_t)>("DispOnResp");
  m_signalproxy_DispOffResp = this->create_signal<void(int16_t)>("DispOffResp");
  m_signalproxy_CurrentStatus =
      this->create_signal<void(std::tuple < uint32_t, uint32_t, uint8_t, uint8_t > )>("CurrentStatus");
  m_signalproxy_FaultStatus =
      this->create_signal<void(std::tuple < uint32_t, uint32_t, uint8_t, uint8_t > )>("FaultStatus");
  m_signalproxy_ErrorStatus = this->create_signal<void(int16_t)>("ErrorStatus");
  m_signalproxy_TouchIgnoreStatus = this->create_signal<void(uint32_t)>("TouchIgnoreStatus");
  m_signalproxy_ErrorEncounteredAlert = this->create_signal<void(uint32_t)>("ErrorEncounteredAlert");
  m_signalproxy_DisplayStatus = this->create_signal<void(std::tuple < std::vector < uint8_t >> )>("DisplayStatus");
  m_signalproxy_HdcpState = this->create_signal<void(uint32_t)>("HdcpState");
  m_signalproxy_HdcpModeStatus = this->create_signal<void(uint32_t)>("HdcpModeStatus");
  m_signalproxy_VideoTuning = this->create_signal<void(uint32_t)>("VideoTuning");
  m_signalproxy_TunedValues =
      this->create_signal<void(std::tuple < uint32_t, uint32_t, uint32_t, uint32_t > )>("TunedValues");
  m_signalproxy_RegisterDumpStatus = this->create_signal<void(uint32_t)>("RegisterDumpStatus");
  m_signalproxy_TouchSimulationStatus = this->create_signal<void(uint32_t)>("TouchSimulationStatus");
  m_signalproxy_SpreadSpectrumStatus = this->create_signal<void(uint32_t)>("SpreadSpectrumStatus");
  m_signalproxy_CMLLevelStatus = this->create_signal<void(uint32_t)>("CMLLevelStatus");

}
std::shared_ptr <com_jci_lvdsProxy> com_jci_lvdsProxy::create(std::string name) {
  return std::shared_ptr<com_jci_lvdsProxy>(new com_jci_lvdsProxy(name));

}
int16_t com_jci_lvdsProxy::SetBrightness(std::tuple <uint32_t, uint32_t, uint8_t, uint8_t> brightnessLevel) {
  return (*m_method_SetBrightness)(brightnessLevel);

}
std::string com_jci_lvdsProxy::GetSoftwareTPVersion(std::tuple <uint32_t, uint32_t, uint8_t, uint8_t> softwareTPVersion) {
  return (*m_method_GetSoftwareTPVersion)(softwareTPVersion);

}
std::string com_jci_lvdsProxy::GetSoftwareDispVersion(std::tuple <uint32_t, uint32_t, uint8_t, uint8_t> softwareDispVersion) {
  return (*m_method_GetSoftwareDispVersion)(softwareDispVersion);

}
std::string com_jci_lvdsProxy::SetNormalMode(std::tuple <uint32_t, uint32_t, uint8_t, uint8_t> normalMode) {
  return (*m_method_SetNormalMode)(normalMode);

}
std::string com_jci_lvdsProxy::SetSleepMode(std::tuple <uint32_t, uint32_t, uint8_t, uint8_t> sleepMode) {
  return (*m_method_SetSleepMode)(sleepMode);

}
std::string com_jci_lvdsProxy::SetDiagMode(std::tuple <uint32_t, uint32_t, uint8_t, uint8_t> diagMode) {
  return (*m_method_SetDiagMode)(diagMode);

}
std::string com_jci_lvdsProxy::SetExtendMode(std::tuple <uint32_t, uint32_t, uint8_t, uint8_t> extendMode) {
  return (*m_method_SetExtendMode)(extendMode);

}
int16_t com_jci_lvdsProxy::SetACCOff(std::tuple <uint32_t, uint32_t, uint8_t, uint8_t> aCCOff) {
  return (*m_method_SetACCOff)(aCCOff);

}
int16_t com_jci_lvdsProxy::SetDispOn(std::tuple <uint32_t, uint32_t, uint8_t, uint8_t> dispOn) {
  return (*m_method_SetDispOn)(dispOn);

}
int16_t com_jci_lvdsProxy::SetDispOff(std::tuple <uint32_t, uint32_t, uint8_t, uint8_t> dispOff) {
  return (*m_method_SetDispOff)(dispOff);

}
std::string com_jci_lvdsProxy::EnablePRBS(std::tuple <uint32_t, uint32_t, uint8_t, uint8_t> enablePRBSAutoTest) {
  return (*m_method_EnablePRBS)(enablePRBSAutoTest);

}
std::string com_jci_lvdsProxy::DisablePRBS(std::tuple <uint32_t, uint32_t, uint8_t, uint8_t> disablePRBSAutoTest) {
  return (*m_method_DisablePRBS)(disablePRBSAutoTest);

}
std::string com_jci_lvdsProxy::PRBSReport(std::tuple <uint32_t, uint32_t, uint8_t, uint8_t> pRBSAutoTestReport) {
  return (*m_method_PRBSReport)(pRBSAutoTestReport);

}
uint32_t com_jci_lvdsProxy::SystemACCMonitoring(uint32_t requestId) {
  return (*m_method_SystemACCMonitoring)(requestId);

}
uint32_t com_jci_lvdsProxy::SpeedRestriction(uint32_t requestId) {
  return (*m_method_SpeedRestriction)(requestId);

}
uint32_t com_jci_lvdsProxy::SetHdcpMode(uint32_t mode) {
  return (*m_method_SetHdcpMode)(mode);

}
uint32_t com_jci_lvdsProxy::GetErrorEncounteredStatus() {
  return (*m_method_GetErrorEncounteredStatus)();

}
uint32_t com_jci_lvdsProxy::BlmLvdsReady(uint32_t requestId) {
  return (*m_method_BlmLvdsReady)(requestId);

}
uint32_t com_jci_lvdsProxy::FaultStatusResponse(uint32_t faultId, uint32_t status) {
  return (*m_method_FaultStatusResponse)(faultId, status);

}
uint32_t com_jci_lvdsProxy::GetDisplayStatus(uint32_t requestId) {
  return (*m_method_GetDisplayStatus)(requestId);

}
uint32_t com_jci_lvdsProxy::GetHdcpState() {
  return (*m_method_GetHdcpState)();

}
uint32_t com_jci_lvdsProxy::SetVideoTuning(std::tuple <uint32_t, uint32_t, uint32_t, uint32_t> videoTuning) {
  return (*m_method_SetVideoTuning)(videoTuning);

}
uint32_t com_jci_lvdsProxy::GetTunedValues(uint32_t requestId) {
  return (*m_method_GetTunedValues)(requestId);

}
uint32_t com_jci_lvdsProxy::GetRegisterDump(uint32_t regType, bool all, uint8_t start, uint8_t stop) {
  return (*m_method_GetRegisterDump)(regType, all, start, stop);

}
uint32_t com_jci_lvdsProxy::TouchSimulation(Invalid touchEvents) {
  return (*m_method_TouchSimulation)(touchEvents);

}
int16_t com_jci_lvdsProxy::BrightnessRamp(std::tuple <uint32_t, uint32_t, uint8_t, uint8_t> brightnessLevel) {
  return (*m_method_BrightnessRamp)(brightnessLevel);

}
uint32_t com_jci_lvdsProxy::SetSpreadSpectrum(uint32_t spreadLevel) {
  return (*m_method_SetSpreadSpectrum)(spreadLevel);

}
uint32_t com_jci_lvdsProxy::SetCMLLevel(uint32_t cMLLevel) {
  return (*m_method_SetCMLLevel)(cMLLevel);

}
std::shared_ptr <DBus::SignalProxy<void(int16_t)>> com_jci_lvdsProxy::signal_brightNessLevelResp() {
  return m_signalproxy_brightNessLevelResp;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        std::string > )>> com_jci_lvdsProxy::signal_TPVersionResp() {
  return m_signalproxy_TPVersionResp;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        std::string > )>> com_jci_lvdsProxy::signal_displayVersion() {
  return m_signalproxy_displayVersion;

}
std::shared_ptr <DBus::SignalProxy<void(int16_t)>> com_jci_lvdsProxy::signal_NormalModeResp() {
  return m_signalproxy_NormalModeResp;

}
std::shared_ptr <DBus::SignalProxy<void(int16_t)>> com_jci_lvdsProxy::signal_SleepModeResp() {
  return m_signalproxy_SleepModeResp;

}
std::shared_ptr <DBus::SignalProxy<void(int16_t)>> com_jci_lvdsProxy::signal_DiagModeResp() {
  return m_signalproxy_DiagModeResp;

}
std::shared_ptr <DBus::SignalProxy<void(int16_t)>> com_jci_lvdsProxy::signal_ExtendModeResp() {
  return m_signalproxy_ExtendModeResp;

}
std::shared_ptr <DBus::SignalProxy<void(int16_t)>> com_jci_lvdsProxy::signal_EnablePRBSResp() {
  return m_signalproxy_EnablePRBSResp;

}
std::shared_ptr <DBus::SignalProxy<void(int16_t)>> com_jci_lvdsProxy::signal_DisablePRBSResp() {
  return m_signalproxy_DisablePRBSResp;

}
std::shared_ptr <DBus::SignalProxy<void(int16_t)>> com_jci_lvdsProxy::signal_PRBSReportResp() {
  return m_signalproxy_PRBSReportResp;

}
std::shared_ptr <DBus::SignalProxy<void(int16_t)>> com_jci_lvdsProxy::signal_ACCOffResp() {
  return m_signalproxy_ACCOffResp;

}
std::shared_ptr <DBus::SignalProxy<void(int16_t)>> com_jci_lvdsProxy::signal_DispOnResp() {
  return m_signalproxy_DispOnResp;

}
std::shared_ptr <DBus::SignalProxy<void(int16_t)>> com_jci_lvdsProxy::signal_DispOffResp() {
  return m_signalproxy_DispOffResp;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t,
                                        uint8_t,
                                        uint8_t > )>> com_jci_lvdsProxy::signal_CurrentStatus() {
  return m_signalproxy_CurrentStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t,
                                        uint8_t,
                                        uint8_t > )>> com_jci_lvdsProxy::signal_FaultStatus() {
  return m_signalproxy_FaultStatus;

}
std::shared_ptr <DBus::SignalProxy<void(int16_t)>> com_jci_lvdsProxy::signal_ErrorStatus() {
  return m_signalproxy_ErrorStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_lvdsProxy::signal_TouchIgnoreStatus() {
  return m_signalproxy_TouchIgnoreStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_lvdsProxy::signal_ErrorEncounteredAlert() {
  return m_signalproxy_ErrorEncounteredAlert;

}
std::shared_ptr <DBus::SignalProxy<void(
    std::tuple < std::vector < uint8_t >> )>> com_jci_lvdsProxy::signal_DisplayStatus() {
  return m_signalproxy_DisplayStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_lvdsProxy::signal_HdcpState() {
  return m_signalproxy_HdcpState;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_lvdsProxy::signal_HdcpModeStatus() {
  return m_signalproxy_HdcpModeStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_lvdsProxy::signal_VideoTuning() {
  return m_signalproxy_VideoTuning;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint32_t,
                                        uint32_t,
                                        uint32_t > )>> com_jci_lvdsProxy::signal_TunedValues() {
  return m_signalproxy_TunedValues;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_lvdsProxy::signal_RegisterDumpStatus() {
  return m_signalproxy_RegisterDumpStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_lvdsProxy::signal_TouchSimulationStatus() {
  return m_signalproxy_TouchSimulationStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_lvdsProxy::signal_SpreadSpectrumStatus() {
  return m_signalproxy_SpreadSpectrumStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_lvdsProxy::signal_CMLLevelStatus() {
  return m_signalproxy_CMLLevelStatus;

}
