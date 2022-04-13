#include "com_jci_bucpsaProxy.h"

com_jci_bucpsaProxy::com_jci_bucpsaProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_GetReverseStatus = this->create_method<int32_t()>("GetReverseStatus");
  m_method_DisplayCommand = this->create_method<int32_t(uint32_t)>("DisplayCommand");
  m_method_GetDisplayMode_async =
      this->create_method<DBus::MultipleReturn<uint32_t, int32_t>()>("GetDisplayMode_async");
  m_method_GetDisplayMode = this->create_method<DBus::MultipleReturn<uint32_t, int32_t>()>("GetDisplayMode");
  m_method_SetPSMEnabled = this->create_method<int32_t(uint8_t)>("SetPSMEnabled");
  m_method_GetPSMInstalledStatus = this->create_method<uint8_t()>("GetPSMInstalledStatus");
  m_method_GetSteeringWheelLocation = this->create_method<uint32_t()>("GetSteeringWheelLocation");
  m_signalproxy_CommandResponse = this->create_signal<void(uint32_t)>("CommandResponse");
  m_signalproxy_DisplayMode = this->create_signal<void(uint32_t)>("DisplayMode");
  m_signalproxy_ReverseStatusChanged = this->create_signal<void(int32_t)>("ReverseStatusChanged");
  m_signalproxy_PSMInstallStatusChanged = this->create_signal<void(uint8_t)>("PSMInstallStatusChanged");
  m_signalproxy_CameraType = this->create_signal<void(uint32_t)>("CameraType");
  m_signalproxy_SteeringWheelLocation = this->create_signal<void(uint32_t)>("SteeringWheelLocation");

}
std::shared_ptr<com_jci_bucpsaProxy> com_jci_bucpsaProxy::create(std::string name) {
  return std::shared_ptr<com_jci_bucpsaProxy>(new com_jci_bucpsaProxy(name));

}
int32_t com_jci_bucpsaProxy::GetReverseStatus() {
  return (*m_method_GetReverseStatus)();

}
int32_t com_jci_bucpsaProxy::DisplayCommand(uint32_t command) {
  return (*m_method_DisplayCommand)(command);

}
DBus::MultipleReturn<uint32_t, int32_t> com_jci_bucpsaProxy::GetDisplayMode_async() {
  return (*m_method_GetDisplayMode_async)();

}
DBus::MultipleReturn<uint32_t, int32_t> com_jci_bucpsaProxy::GetDisplayMode() {
  return (*m_method_GetDisplayMode)();

}
int32_t com_jci_bucpsaProxy::SetPSMEnabled(uint8_t psmEnabled) {
  return (*m_method_SetPSMEnabled)(psmEnabled);

}
uint8_t com_jci_bucpsaProxy::GetPSMInstalledStatus() {
  return (*m_method_GetPSMInstalledStatus)();

}
uint32_t com_jci_bucpsaProxy::GetSteeringWheelLocation() {
  return (*m_method_GetSteeringWheelLocation)();

}
std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> com_jci_bucpsaProxy::signal_CommandResponse() {
  return m_signalproxy_CommandResponse;

}
std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> com_jci_bucpsaProxy::signal_DisplayMode() {
  return m_signalproxy_DisplayMode;

}
std::shared_ptr<DBus::SignalProxy<void(int32_t)>> com_jci_bucpsaProxy::signal_ReverseStatusChanged() {
  return m_signalproxy_ReverseStatusChanged;

}
std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> com_jci_bucpsaProxy::signal_PSMInstallStatusChanged() {
  return m_signalproxy_PSMInstallStatusChanged;

}
std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> com_jci_bucpsaProxy::signal_CameraType() {
  return m_signalproxy_CameraType;

}
std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> com_jci_bucpsaProxy::signal_SteeringWheelLocation() {
  return m_signalproxy_SteeringWheelLocation;

}
