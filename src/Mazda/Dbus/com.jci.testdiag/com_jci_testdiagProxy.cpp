#include "com_jci_testdiagProxy.h"

com_jci_testdiagProxy::com_jci_testdiagProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_StartRoutine = this->create_method<int32_t(uint8_t)>("StartRoutine");
  m_method_ActivateTestMode = this->create_method<int32_t()>("ActivateTestMode");
  m_method_DeactivateTestMode = this->create_method<int32_t()>("DeactivateTestMode");
  m_method_CommanderInput = this->create_method<int32_t(int16_t, int16_t)>("CommanderInput");
  m_method_StopCommanderRoutine = this->create_method<int32_t()>("StopCommanderRoutine");
  m_method_GetTestInfo = this->create_method < std::tuple < uint32_t, std::vector < std::tuple < uint32_t, std::vector
      < uint8_t >> >> () > ("GetTestInfo");
  m_method_ActivateJCITestMode = this->create_method<int32_t()>("ActivateJCITestMode");
  m_method_DeactivateJCITestModeMode = this->create_method<int32_t()>("DeactivateJCITestModeMode");
  m_method_NotifyDiagLostFocus = this->create_method<int32_t()>("NotifyDiagLostFocus");
  m_method_GetDiagStatus = this->create_method<uint32_t()>("GetDiagStatus");
  m_signalproxy_TestRoutineStatus_Response = this->create_signal<void(std::string,
                                                                      std::tuple < uint32_t,
                                                                      std::vector < uint8_t >> ,
                                                                      std::tuple < int32_t,
                                                                      std::vector < uint8_t >> ,
                                                                      Invalid,
                                                                      bool,
                                                                      bool)>("TestRoutineStatus_Response");
  m_signalproxy_NotifyTestMode_Response = this->create_signal<void(uint32_t)>("NotifyTestMode_Response");
  m_signalproxy_SystemError_Response = this->create_signal<void(uint32_t, uint32_t)>("SystemError_Response");
  m_signalproxy_DVD_SpeedRestriction_Enable = this->create_signal<void(bool)>("DVD_SpeedRestriction_Enable");

}
std::shared_ptr <com_jci_testdiagProxy> com_jci_testdiagProxy::create(std::string name) {
  return std::shared_ptr<com_jci_testdiagProxy>(new com_jci_testdiagProxy(name));

}
int32_t com_jci_testdiagProxy::StartRoutine(uint8_t test_id) {
  return (*m_method_StartRoutine)(test_id);

}
int32_t com_jci_testdiagProxy::ActivateTestMode() {
  return (*m_method_ActivateTestMode)();

}
int32_t com_jci_testdiagProxy::DeactivateTestMode() {
  return (*m_method_DeactivateTestMode)();

}
int32_t com_jci_testdiagProxy::CommanderInput(int16_t buttont_id, int16_t buttont_value) {
  return (*m_method_CommanderInput)(buttont_id, buttont_value);

}
int32_t com_jci_testdiagProxy::StopCommanderRoutine() {
  return (*m_method_StopCommanderRoutine)();

}
std::tuple <uint32_t, std::vector<std::tuple < uint32_t, std::vector < uint8_t>>>>
com_jci_testdiagProxy::GetTestInfo() {
  return (*m_method_GetTestInfo)();

}
int32_t com_jci_testdiagProxy::ActivateJCITestMode() {
  return (*m_method_ActivateJCITestMode)();

}
int32_t com_jci_testdiagProxy::DeactivateJCITestModeMode() {
  return (*m_method_DeactivateJCITestModeMode)();

}
int32_t com_jci_testdiagProxy::NotifyDiagLostFocus() {
  return (*m_method_NotifyDiagLostFocus)();

}
uint32_t com_jci_testdiagProxy::GetDiagStatus() {
  return (*m_method_GetDiagStatus)();

}
std::shared_ptr <DBus::SignalProxy<void(std::string,
                                        std::tuple < uint32_t,
                                        std::vector < uint8_t >> ,
                                        std::tuple < int32_t,
                                        std::vector < uint8_t >> ,
                                        Invalid,
                                        bool,
                                        bool)>> com_jci_testdiagProxy::signal_TestRoutineStatus_Response() {
  return m_signalproxy_TestRoutineStatus_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_testdiagProxy::signal_NotifyTestMode_Response() {
  return m_signalproxy_NotifyTestMode_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, uint32_t)>> com_jci_testdiagProxy::signal_SystemError_Response() {
  return m_signalproxy_SystemError_Response;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_testdiagProxy::signal_DVD_SpeedRestriction_Enable() {
  return m_signalproxy_DVD_SpeedRestriction_Enable;

}
