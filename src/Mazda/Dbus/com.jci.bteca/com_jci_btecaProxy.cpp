#include "com_jci_btecaProxy.h"

com_jci_btecaProxy::com_jci_btecaProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_AbortCall = this->create_method<int32_t()>("AbortCall");
  m_method_TransferToHandset = this->create_method<int32_t()>("TransferToHandset");
  m_method_TransferFromHandset = this->create_method<int32_t()>("TransferFromHandset");
  m_method_BargeIntoCall = this->create_method<int32_t()>("BargeIntoCall");
  m_method_GetBTECAEnabledValue = this->create_method<uint8_t()>("GetBTECAEnabledValue");
  m_method_SetBTECAEnabledValue = this->create_method<int32_t(uint8_t)>("SetBTECAEnabledValue");
  m_method_IsBTECASupported = this->create_method<uint8_t()>("IsBTECASupported");
  m_method_RetryEcall = this->create_method<int32_t()>("RetryEcall");
  m_method_ResetEnableSetting = this->create_method<int32_t()>("ResetEnableSetting");
  m_signalproxy_EnabledChange = this->create_signal<void(uint8_t)>("EnabledChange");
  m_signalproxy_CollisionDetected = this->create_signal<void(bool)>("CollisionDetected");
  m_signalproxy_PhoneFoundStatus = this->create_signal<void(bool)>("PhoneFoundStatus");
  m_signalproxy_CollisionDetectedTimerStart = this->create_signal<void()>("CollisionDetectedTimerStart");
  m_signalproxy_CollisionDetectedTimerExpired = this->create_signal<void()>("CollisionDetectedTimerExpired");
  m_signalproxy_CallSuccess = this->create_signal<void()>("CallSuccess");
  m_signalproxy_CallNotSuccess = this->create_signal<void(bool)>("CallNotSuccess");
  m_signalproxy_AudioTransferredToPhone = this->create_signal<void()>("AudioTransferredToPhone");
  m_signalproxy_AudioTransferredToCar = this->create_signal<void()>("AudioTransferredToCar");
  m_signalproxy_EndCall = this->create_signal<void()>("EndCall");
  m_signalproxy_EmergencyCallFailure = this->create_signal<void()>("EmergencyCallFailure");
  m_signalproxy_MP911EmergencyCallStatus = this->create_signal<void(int32_t)>("MP911EmergencyCallStatus");
  m_signalproxy_PhoneBTConnectionLost = this->create_signal<void()>("PhoneBTConnectionLost");
  m_signalproxy_TransferredToHandset = this->create_signal<void(bool)>("TransferredToHandset");
  m_signalproxy_TransferredFromHandset = this->create_signal<void(bool, bool)>("TransferredFromHandset");
  m_signalproxy_ConnectedTimerStart = this->create_signal<void()>("ConnectedTimerStart");
  m_signalproxy_ShowPSAPInfoInscription = this->create_signal<void(bool)>("ShowPSAPInfoInscription");
  m_signalproxy_SetTransferredValid = this->create_signal<void(bool)>("SetTransferredValid");
  m_signalproxy_NotifyCarPlaySession = this->create_signal<void(bool)>("NotifyCarPlaySession");

}
std::shared_ptr <com_jci_btecaProxy> com_jci_btecaProxy::create(std::string name) {
  return std::shared_ptr<com_jci_btecaProxy>(new com_jci_btecaProxy(name));

}
int32_t com_jci_btecaProxy::AbortCall() {
  return (*m_method_AbortCall)();

}
int32_t com_jci_btecaProxy::TransferToHandset() {
  return (*m_method_TransferToHandset)();

}
int32_t com_jci_btecaProxy::TransferFromHandset() {
  return (*m_method_TransferFromHandset)();

}
int32_t com_jci_btecaProxy::BargeIntoCall() {
  return (*m_method_BargeIntoCall)();

}
uint8_t com_jci_btecaProxy::GetBTECAEnabledValue() {
  return (*m_method_GetBTECAEnabledValue)();

}
int32_t com_jci_btecaProxy::SetBTECAEnabledValue(uint8_t isBTECAenabled) {
  return (*m_method_SetBTECAEnabledValue)(isBTECAenabled);

}
uint8_t com_jci_btecaProxy::IsBTECASupported() {
  return (*m_method_IsBTECASupported)();

}
int32_t com_jci_btecaProxy::RetryEcall() {
  return (*m_method_RetryEcall)();

}
int32_t com_jci_btecaProxy::ResetEnableSetting() {
  return (*m_method_ResetEnableSetting)();

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_btecaProxy::signal_EnabledChange() {
  return m_signalproxy_EnabledChange;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_btecaProxy::signal_CollisionDetected() {
  return m_signalproxy_CollisionDetected;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_btecaProxy::signal_PhoneFoundStatus() {
  return m_signalproxy_PhoneFoundStatus;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_btecaProxy::signal_CollisionDetectedTimerStart() {
  return m_signalproxy_CollisionDetectedTimerStart;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_btecaProxy::signal_CollisionDetectedTimerExpired() {
  return m_signalproxy_CollisionDetectedTimerExpired;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_btecaProxy::signal_CallSuccess() {
  return m_signalproxy_CallSuccess;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_btecaProxy::signal_CallNotSuccess() {
  return m_signalproxy_CallNotSuccess;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_btecaProxy::signal_AudioTransferredToPhone() {
  return m_signalproxy_AudioTransferredToPhone;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_btecaProxy::signal_AudioTransferredToCar() {
  return m_signalproxy_AudioTransferredToCar;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_btecaProxy::signal_EndCall() {
  return m_signalproxy_EndCall;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_btecaProxy::signal_EmergencyCallFailure() {
  return m_signalproxy_EmergencyCallFailure;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_btecaProxy::signal_MP911EmergencyCallStatus() {
  return m_signalproxy_MP911EmergencyCallStatus;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_btecaProxy::signal_PhoneBTConnectionLost() {
  return m_signalproxy_PhoneBTConnectionLost;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_btecaProxy::signal_TransferredToHandset() {
  return m_signalproxy_TransferredToHandset;

}
std::shared_ptr <DBus::SignalProxy<void(bool, bool)>> com_jci_btecaProxy::signal_TransferredFromHandset() {
  return m_signalproxy_TransferredFromHandset;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_btecaProxy::signal_ConnectedTimerStart() {
  return m_signalproxy_ConnectedTimerStart;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_btecaProxy::signal_ShowPSAPInfoInscription() {
  return m_signalproxy_ShowPSAPInfoInscription;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_btecaProxy::signal_SetTransferredValid() {
  return m_signalproxy_SetTransferredValid;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_btecaProxy::signal_NotifyCarPlaySession() {
  return m_signalproxy_NotifyCarPlaySession;

}
