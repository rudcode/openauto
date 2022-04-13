#include "com_jci_bthfProxy.h"

com_jci_bthfProxy::com_jci_bthfProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_Dial = this->create_method<int32_t(std::tuple < std::vector < uint8_t >> , bool)>("Dial");
  m_method_EmergencyDial = this->create_method<int32_t(std::tuple < std::vector < uint8_t >> )>("EmergencyDial");
  m_method_Redial = this->create_method<int32_t()>("Redial");
  m_method_HangupCall = this->create_method<int32_t()>("HangupCall");
  m_method_RejectCall = this->create_method<int32_t()>("RejectCall");
  m_method_AcceptCall = this->create_method<int32_t()>("AcceptCall");
  m_method_MuteCall = this->create_method<int32_t()>("MuteCall");
  m_method_UnmuteCall = this->create_method<int32_t()>("UnmuteCall");
  m_method_SwapCall = this->create_method<int32_t()>("SwapCall");
  m_method_HeldCall = this->create_method<int32_t()>("HeldCall");
  m_method_UnHeldCall = this->create_method<int32_t()>("UnHeldCall");
  m_method_JoinCall = this->create_method<int32_t()>("JoinCall");
  m_method_TransferCall = this->create_method<int32_t(int32_t)>("TransferCall");
  m_method_SendDtmf = this->create_method<int32_t(std::tuple < std::vector < uint8_t >> )>("SendDtmf");
  m_method_StartPhoneVr = this->create_method<int32_t()>("StartPhoneVr");
  m_method_StopPhoneVr = this->create_method<int32_t()>("StopPhoneVr");
  m_method_StartBargein = this->create_method<int32_t()>("StartBargein");
  m_method_StopBargein = this->create_method<int32_t()>("StopBargein");
  m_method_CallSettings = this->create_method<int32_t(uint32_t, uint32_t, uint32_t)>("CallSettings");
  m_method_RingToneSettings = this->create_method<int32_t(uint32_t)>("RingToneSettings");
  m_method_AutoAnswerSettings = this->create_method<int32_t(uint32_t)>("AutoAnswerSettings");
  m_method_RampupRingToneSettings = this->create_method<int32_t(uint32_t)>("RampupRingToneSettings");
  m_method_DoNotDisturbSettings = this->create_method<int32_t(uint32_t)>("DoNotDisturbSettings");
  m_method_QueryCallStatus = this->create_method<int32_t()>("QueryCallStatus");
  m_method_EmergencyCallStart = this->create_method<int32_t()>("EmergencyCallStart");
  m_method_EmergencyCallStop = this->create_method<int32_t()>("EmergencyCallStop");
  m_method_GetBthfSettingData = this->create_method<int32_t()>("GetBthfSettingData");
  m_method_ResetBthfCommunicationSettings = this->create_method<int32_t()>("ResetBthfCommunicationSettings");
  m_signalproxy_CallStatus = this->create_signal<void(uint32_t,
                                                      uint32_t,
                                                      uint32_t,
                                                      std::tuple < std::vector < uint8_t >> ,
                                                      std::tuple < std::vector < uint8_t >> )>("CallStatus");
  m_signalproxy_BatteryIndicator = this->create_signal<void(uint32_t, uint32_t, uint32_t)>("BatteryIndicator");
  m_signalproxy_SignalStrength = this->create_signal<void(uint32_t, uint32_t, uint32_t)>("SignalStrength");
  m_signalproxy_RoamIndicator = this->create_signal<void(uint32_t)>("RoamIndicator");
  m_signalproxy_NewServiceIndicator = this->create_signal<void(bool)>("NewServiceIndicator");
  m_signalproxy_PhoneChargeIndicator = this->create_signal<void(uint32_t)>("PhoneChargeIndicator");
  m_signalproxy_SmsPresentIndicator = this->create_signal<void(bool)>("SmsPresentIndicator");
  m_signalproxy_VoiceMailIndicator = this->create_signal<void(bool)>("VoiceMailIndicator");
  m_signalproxy_LowBatteryIndicator = this->create_signal<void(bool)>("LowBatteryIndicator");
  m_signalproxy_BthfReadyStatus = this->create_signal<void(uint32_t, uint32_t)>("BthfReadyStatus");
  m_signalproxy_BthfBusyReason = this->create_signal<void(uint32_t)>("BthfBusyReason");
  m_signalproxy_MicStatus = this->create_signal<void(bool)>("MicStatus");
  m_signalproxy_BargeinStatus = this->create_signal<void(bool)>("BargeinStatus");
  m_signalproxy_BthfSettingsResponse =
      this->create_signal<void(std::tuple < std::vector < uint8_t >> )>("BthfSettingsResponse");
  m_signalproxy_FailureReasonCodes = this->create_signal<void(uint32_t)>("FailureReasonCodes");

}
std::shared_ptr <com_jci_bthfProxy> com_jci_bthfProxy::create(std::string name) {
  return std::shared_ptr<com_jci_bthfProxy>(new com_jci_bthfProxy(name));

}
int32_t com_jci_bthfProxy::Dial(std::tuple <std::vector<uint8_t>> dialNumber, bool dialPrompt) {
  return (*m_method_Dial)(dialNumber, dialPrompt);

}
int32_t com_jci_bthfProxy::EmergencyDial(std::tuple <std::vector<uint8_t>> dialNumber) {
  return (*m_method_EmergencyDial)(dialNumber);

}
int32_t com_jci_bthfProxy::Redial() {
  return (*m_method_Redial)();

}
int32_t com_jci_bthfProxy::HangupCall() {
  return (*m_method_HangupCall)();

}
int32_t com_jci_bthfProxy::RejectCall() {
  return (*m_method_RejectCall)();

}
int32_t com_jci_bthfProxy::AcceptCall() {
  return (*m_method_AcceptCall)();

}
int32_t com_jci_bthfProxy::MuteCall() {
  return (*m_method_MuteCall)();

}
int32_t com_jci_bthfProxy::UnmuteCall() {
  return (*m_method_UnmuteCall)();

}
int32_t com_jci_bthfProxy::SwapCall() {
  return (*m_method_SwapCall)();

}
int32_t com_jci_bthfProxy::HeldCall() {
  return (*m_method_HeldCall)();

}
int32_t com_jci_bthfProxy::UnHeldCall() {
  return (*m_method_UnHeldCall)();

}
int32_t com_jci_bthfProxy::JoinCall() {
  return (*m_method_JoinCall)();

}
int32_t com_jci_bthfProxy::TransferCall(int32_t transferType) {
  return (*m_method_TransferCall)(transferType);

}
int32_t com_jci_bthfProxy::SendDtmf(std::tuple <std::vector<uint8_t>> dtmfDigits) {
  return (*m_method_SendDtmf)(dtmfDigits);

}
int32_t com_jci_bthfProxy::StartPhoneVr() {
  return (*m_method_StartPhoneVr)();

}
int32_t com_jci_bthfProxy::StopPhoneVr() {
  return (*m_method_StopPhoneVr)();

}
int32_t com_jci_bthfProxy::StartBargein() {
  return (*m_method_StartBargein)();

}
int32_t com_jci_bthfProxy::StopBargein() {
  return (*m_method_StopBargein)();

}
int32_t com_jci_bthfProxy::CallSettings(uint32_t isIncallAutoXferEnabled,
                                        uint32_t isOutCallAutoXferEnabled,
                                        uint32_t isActiveCallAutoXferEnabled) {
  return (*m_method_CallSettings)(isIncallAutoXferEnabled, isOutCallAutoXferEnabled, isActiveCallAutoXferEnabled);

}
int32_t com_jci_bthfProxy::RingToneSettings(uint32_t ringToneTypeSupported) {
  return (*m_method_RingToneSettings)(ringToneTypeSupported);

}
int32_t com_jci_bthfProxy::AutoAnswerSettings(uint32_t autoAnswerValue) {
  return (*m_method_AutoAnswerSettings)(autoAnswerValue);

}
int32_t com_jci_bthfProxy::RampupRingToneSettings(uint32_t isRampUpRingToneSupported) {
  return (*m_method_RampupRingToneSettings)(isRampUpRingToneSupported);

}
int32_t com_jci_bthfProxy::DoNotDisturbSettings(uint32_t isDoNotDisturbEnabled) {
  return (*m_method_DoNotDisturbSettings)(isDoNotDisturbEnabled);

}
int32_t com_jci_bthfProxy::QueryCallStatus() {
  return (*m_method_QueryCallStatus)();

}
int32_t com_jci_bthfProxy::EmergencyCallStart() {
  return (*m_method_EmergencyCallStart)();

}
int32_t com_jci_bthfProxy::EmergencyCallStop() {
  return (*m_method_EmergencyCallStop)();

}
int32_t com_jci_bthfProxy::GetBthfSettingData() {
  return (*m_method_GetBthfSettingData)();

}
int32_t com_jci_bthfProxy::ResetBthfCommunicationSettings() {
  return (*m_method_ResetBthfCommunicationSettings)();

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        uint32_t,
                                        uint32_t,
                                        std::tuple < std::vector < uint8_t >> ,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bthfProxy::signal_CallStatus() {
  return m_signalproxy_CallStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, uint32_t, uint32_t)>> com_jci_bthfProxy::signal_BatteryIndicator() {
  return m_signalproxy_BatteryIndicator;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, uint32_t, uint32_t)>> com_jci_bthfProxy::signal_SignalStrength() {
  return m_signalproxy_SignalStrength;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_bthfProxy::signal_RoamIndicator() {
  return m_signalproxy_RoamIndicator;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_bthfProxy::signal_NewServiceIndicator() {
  return m_signalproxy_NewServiceIndicator;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_bthfProxy::signal_PhoneChargeIndicator() {
  return m_signalproxy_PhoneChargeIndicator;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_bthfProxy::signal_SmsPresentIndicator() {
  return m_signalproxy_SmsPresentIndicator;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_bthfProxy::signal_VoiceMailIndicator() {
  return m_signalproxy_VoiceMailIndicator;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_bthfProxy::signal_LowBatteryIndicator() {
  return m_signalproxy_LowBatteryIndicator;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, uint32_t)>> com_jci_bthfProxy::signal_BthfReadyStatus() {
  return m_signalproxy_BthfReadyStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_bthfProxy::signal_BthfBusyReason() {
  return m_signalproxy_BthfBusyReason;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_bthfProxy::signal_MicStatus() {
  return m_signalproxy_MicStatus;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_bthfProxy::signal_BargeinStatus() {
  return m_signalproxy_BargeinStatus;

}
std::shared_ptr <DBus::SignalProxy<void(
    std::tuple < std::vector < uint8_t >> )>> com_jci_bthfProxy::signal_BthfSettingsResponse() {
  return m_signalproxy_BthfSettingsResponse;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_bthfProxy::signal_FailureReasonCodes() {
  return m_signalproxy_FailureReasonCodes;

}
