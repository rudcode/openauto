#include "com_jci_blmsystem_InterfaceProxy.h"

com_jci_blmsystem_InterfaceProxy::com_jci_blmsystem_InterfaceProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_OpenConnection = this->create_method<DBus::MultipleReturn<int32_t, uint32_t>()>("OpenConnection");
  m_method_CloseConnection = this->create_method<int32_t()>("CloseConnection");
  m_method_SafeShutDown = this->create_method<int32_t()>("SafeShutDown");
  m_method_SafeReboot = this->create_method<int32_t()>("SafeReboot");
  m_method_GenericReboot = this->create_method<int32_t(int32_t)>("GenericReboot");
  m_method_FactoryReset = this->create_method<int32_t()>("FactoryReset");
  m_method_GetCurrentAccStatus = this->create_method<DBus::MultipleReturn<int32_t, int32_t>()>("GetCurrentAccStatus");
  m_method_GetCurrentSystemState =
      this->create_method<DBus::MultipleReturn<uint32_t, int32_t>()>("GetCurrentSystemState");
  m_method_RegisterForStateTransitionAck =
      this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t, uint32_t)>(
          "RegisterForStateTransitionAck");
  m_method_AcknowledgeStateTransition =
      this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t, uint32_t)>(
          "AcknowledgeStateTransition");
  m_method_UnregisterFromStateTransitionAck =
      this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t, uint32_t)>(
          "UnregisterFromStateTransitionAck");
  m_method_RegisterForShutdownAck = this->create_method<int32_t()>("RegisterForShutdownAck");
  m_method_AcknowledgeShutdown = this->create_method<int32_t()>("AcknowledgeShutdown");
  m_method_UnregisterFromShutdownAck = this->create_method<int32_t()>("UnregisterFromShutdownAck");
  m_method_SignalSystemStateEvent =
      this->create_method<DBus::MultipleReturn<int32_t, int32_t, int32_t>(int32_t, int32_t)>("SignalSystemStateEvent");
  m_method_ReportTestDiagEntering = this->create_method<int32_t()>("ReportTestDiagEntering");
  m_method_ReportTestDiagExiting = this->create_method<int32_t()>("ReportTestDiagExiting");
  m_method_ReportGuiAvailable = this->create_method<int32_t()>("ReportGuiAvailable");
  m_method_GetFactoryResetNum = this->create_method<int32_t()>("GetFactoryResetNum");
  m_method_ReportXMInstalled = this->create_method<void(int32_t)>("ReportXMInstalled");
  m_signalproxy_NotifyStateTransition = this->create_signal<void(uint32_t, uint32_t)>("NotifyStateTransition");
  m_signalproxy_NotifyShutdown = this->create_signal<void(uint32_t)>("NotifyShutdown");
  m_signalproxy_NotifyAccChange = this->create_signal<void(int32_t, uint32_t)>("NotifyAccChange");
  m_signalproxy_NotifySystemStateChange = this->create_signal<void(uint32_t, uint32_t)>("NotifySystemStateChange");

}
std::shared_ptr <com_jci_blmsystem_InterfaceProxy> com_jci_blmsystem_InterfaceProxy::create(std::string name) {
  return std::shared_ptr<com_jci_blmsystem_InterfaceProxy>(new com_jci_blmsystem_InterfaceProxy(name));

}
DBus::MultipleReturn <int32_t, uint32_t> com_jci_blmsystem_InterfaceProxy::OpenConnection() {
  return (*m_method_OpenConnection)();

}
int32_t com_jci_blmsystem_InterfaceProxy::CloseConnection() {
  return (*m_method_CloseConnection)();

}
int32_t com_jci_blmsystem_InterfaceProxy::SafeShutDown() {
  return (*m_method_SafeShutDown)();

}
int32_t com_jci_blmsystem_InterfaceProxy::SafeReboot() {
  return (*m_method_SafeReboot)();

}
int32_t com_jci_blmsystem_InterfaceProxy::GenericReboot(int32_t mode_flags) {
  return (*m_method_GenericReboot)(mode_flags);

}
int32_t com_jci_blmsystem_InterfaceProxy::FactoryReset() {
  return (*m_method_FactoryReset)();

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_blmsystem_InterfaceProxy::GetCurrentAccStatus() {
  return (*m_method_GetCurrentAccStatus)();

}
DBus::MultipleReturn <uint32_t, int32_t> com_jci_blmsystem_InterfaceProxy::GetCurrentSystemState() {
  return (*m_method_GetCurrentSystemState)();

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t> com_jci_blmsystem_InterfaceProxy::RegisterForStateTransitionAck(
    uint32_t from_state,
    uint32_t to_state) {
  return (*m_method_RegisterForStateTransitionAck)(from_state, to_state);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t> com_jci_blmsystem_InterfaceProxy::AcknowledgeStateTransition(uint32_t from_state,
                                                                                                                uint32_t to_state) {
  return (*m_method_AcknowledgeStateTransition)(from_state, to_state);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t> com_jci_blmsystem_InterfaceProxy::UnregisterFromStateTransitionAck(
    uint32_t from_state,
    uint32_t to_state) {
  return (*m_method_UnregisterFromStateTransitionAck)(from_state, to_state);

}
int32_t com_jci_blmsystem_InterfaceProxy::RegisterForShutdownAck() {
  return (*m_method_RegisterForShutdownAck)();

}
int32_t com_jci_blmsystem_InterfaceProxy::AcknowledgeShutdown() {
  return (*m_method_AcknowledgeShutdown)();

}
int32_t com_jci_blmsystem_InterfaceProxy::UnregisterFromShutdownAck() {
  return (*m_method_UnregisterFromShutdownAck)();

}
DBus::MultipleReturn <int32_t, int32_t, int32_t> com_jci_blmsystem_InterfaceProxy::SignalSystemStateEvent(int32_t event,
                                                                                                          int32_t event_info) {
  return (*m_method_SignalSystemStateEvent)(event, event_info);

}
int32_t com_jci_blmsystem_InterfaceProxy::ReportTestDiagEntering() {
  return (*m_method_ReportTestDiagEntering)();

}
int32_t com_jci_blmsystem_InterfaceProxy::ReportTestDiagExiting() {
  return (*m_method_ReportTestDiagExiting)();

}
int32_t com_jci_blmsystem_InterfaceProxy::ReportGuiAvailable() {
  return (*m_method_ReportGuiAvailable)();

}
int32_t com_jci_blmsystem_InterfaceProxy::GetFactoryResetNum() {
  return (*m_method_GetFactoryResetNum)();

}
void com_jci_blmsystem_InterfaceProxy::ReportXMInstalled(int32_t value) {
  (*m_method_ReportXMInstalled)(value);

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        uint32_t)>> com_jci_blmsystem_InterfaceProxy::signal_NotifyStateTransition() {
  return m_signalproxy_NotifyStateTransition;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_blmsystem_InterfaceProxy::signal_NotifyShutdown() {
  return m_signalproxy_NotifyShutdown;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t,
                                        uint32_t)>> com_jci_blmsystem_InterfaceProxy::signal_NotifyAccChange() {
  return m_signalproxy_NotifyAccChange;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        uint32_t)>> com_jci_blmsystem_InterfaceProxy::signal_NotifySystemStateChange() {
  return m_signalproxy_NotifySystemStateChange;

}
