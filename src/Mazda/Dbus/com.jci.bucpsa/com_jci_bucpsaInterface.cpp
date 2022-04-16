#include "com_jci_bucpsaInterface.h"

com_jci_bucpsaInterface::com_jci_bucpsaInterface(com_jci_bucpsa *adaptee, std::string name) : DBus::Interface(name) {
  this->create_method<int32_t()>("GetReverseStatus", sigc::mem_fun(*adaptee, &com_jci_bucpsa::GetReverseStatus));
  this->create_method<int32_t(uint32_t)>("DisplayCommand", sigc::mem_fun(*adaptee, &com_jci_bucpsa::DisplayCommand));
  this->create_method<DBus::MultipleReturn<uint32_t, int32_t>()>("GetDisplayMode_async",
                                                                 sigc::mem_fun(*adaptee,
                                                                               &com_jci_bucpsa::GetDisplayMode_async));
  this->create_method<DBus::MultipleReturn<uint32_t, int32_t>()>("GetDisplayMode",
                                                                 sigc::mem_fun(*adaptee,
                                                                               &com_jci_bucpsa::GetDisplayMode));
  this->create_method<int32_t(uint8_t)>("SetPSMEnabled", sigc::mem_fun(*adaptee, &com_jci_bucpsa::SetPSMEnabled));
  this->create_method<uint8_t()>("GetPSMInstalledStatus",
                                 sigc::mem_fun(*adaptee, &com_jci_bucpsa::GetPSMInstalledStatus));
  this->create_method<uint32_t()>("GetSteeringWheelLocation",
                                  sigc::mem_fun(*adaptee, &com_jci_bucpsa::GetSteeringWheelLocation));
  m_signal_CommandResponse = create_signal<void(uint32_t)>("CommandResponse");
  m_signal_DisplayMode = create_signal<void(uint32_t)>("DisplayMode");
  m_signal_ReverseStatusChanged = create_signal<void(int32_t)>("ReverseStatusChanged");
  m_signal_PSMInstallStatusChanged = create_signal<void(uint8_t)>("PSMInstallStatusChanged");
  m_signal_CameraType = create_signal<void(uint32_t)>("CameraType");
  m_signal_SteeringWheelLocation = create_signal<void(uint32_t)>("SteeringWheelLocation");

}
std::shared_ptr<com_jci_bucpsaInterface> com_jci_bucpsaInterface::create(com_jci_bucpsa *adaptee, std::string name) {
  return std::shared_ptr<com_jci_bucpsaInterface>(new com_jci_bucpsaInterface(adaptee, name));

}
std::shared_ptr<DBus::Signal<void(uint32_t)>> com_jci_bucpsaInterface::signal_CommandResponse() {
  return m_signal_CommandResponse;

}
void com_jci_bucpsaInterface::CommandResponse(uint32_t cmdResponse) {
  (*m_signal_CommandResponse)(cmdResponse);

}
std::shared_ptr<DBus::Signal<void(uint32_t)>> com_jci_bucpsaInterface::signal_DisplayMode() {
  return m_signal_DisplayMode;

}
void com_jci_bucpsaInterface::DisplayMode(uint32_t currentDisplayMode) {
  (*m_signal_DisplayMode)(currentDisplayMode);

}
std::shared_ptr<DBus::Signal<void(int32_t)>> com_jci_bucpsaInterface::signal_ReverseStatusChanged() {
  return m_signal_ReverseStatusChanged;

}
void com_jci_bucpsaInterface::ReverseStatusChanged(int32_t reverseStatus) {
  (*m_signal_ReverseStatusChanged)(reverseStatus);

}
std::shared_ptr<DBus::Signal<void(uint8_t)>> com_jci_bucpsaInterface::signal_PSMInstallStatusChanged() {
  return m_signal_PSMInstallStatusChanged;

}
void com_jci_bucpsaInterface::PSMInstallStatusChanged(uint8_t psmInstalled) {
  (*m_signal_PSMInstallStatusChanged)(psmInstalled);

}
std::shared_ptr<DBus::Signal<void(uint32_t)>> com_jci_bucpsaInterface::signal_CameraType() {
  return m_signal_CameraType;

}
void com_jci_bucpsaInterface::CameraType(uint32_t currentCameraType) {
  (*m_signal_CameraType)(currentCameraType);

}
std::shared_ptr<DBus::Signal<void(uint32_t)>> com_jci_bucpsaInterface::signal_SteeringWheelLocation() {
  return m_signal_SteeringWheelLocation;

}
void com_jci_bucpsaInterface::SteeringWheelLocation(uint32_t currentSteeringWheelLocation) {
  (*m_signal_SteeringWheelLocation)(currentSteeringWheelLocation);

}
