#include "com_jci_dvdProxy.h"

com_jci_dvdProxy::com_jci_dvdProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_SwitchState = this->create_method<int32_t(uint32_t)>("SwitchState");
  m_method_ChangeSetting = this->create_method<int32_t(uint32_t, int32_t)>("ChangeSetting");
  m_method_GetSetting = this->create_method<int32_t(uint32_t)>("GetSetting");
  m_method_PinOperation = this->create_method<int32_t(uint32_t, uint32_t)>("PinOperation");
  m_method_DeviceCommand = this->create_method<int32_t(uint32_t)>("DeviceCommand");
  m_method_ScrubberBarControl = this->create_method<int32_t(uint32_t)>("ScrubberBarControl");
  m_method_GetDvdStatus = this->create_method<std::tuple<uint32_t,
                                                         uint32_t,
                                                         uint32_t,
                                                         uint32_t,
                                                         uint32_t,
                                                         uint32_t,
                                                         uint32_t,
                                                         int32_t,
                                                         int32_t,
                                                         uint32_t,
                                                         uint8_t>()>("GetDvdStatus");
  m_signalproxy_DeviceStatusEvent = this->create_signal<void(uint32_t)>("DeviceStatusEvent");
  m_signalproxy_PlayingStatusEvent = this->create_signal<void(std::tuple < uint16_t,
                                                              uint8_t,
                                                              uint8_t,
                                                              uint8_t,
                                                              uint8_t,
                                                              uint8_t,
                                                              uint8_t,
                                                              uint8_t > )>("PlayingStatusEvent");

}
std::shared_ptr <com_jci_dvdProxy> com_jci_dvdProxy::create(std::string name) {
  return std::shared_ptr<com_jci_dvdProxy>(new com_jci_dvdProxy(name));

}
int32_t com_jci_dvdProxy::SwitchState(uint32_t state) {
  return (*m_method_SwitchState)(state);

}
int32_t com_jci_dvdProxy::ChangeSetting(uint32_t setting, int32_t value) {
  return (*m_method_ChangeSetting)(setting, value);

}
int32_t com_jci_dvdProxy::GetSetting(uint32_t setting) {
  return (*m_method_GetSetting)(setting);

}
int32_t com_jci_dvdProxy::PinOperation(uint32_t cmd, uint32_t pin) {
  return (*m_method_PinOperation)(cmd, pin);

}
int32_t com_jci_dvdProxy::DeviceCommand(uint32_t cmd) {
  return (*m_method_DeviceCommand)(cmd);

}
int32_t com_jci_dvdProxy::ScrubberBarControl(uint32_t percentage) {
  return (*m_method_ScrubberBarControl)(percentage);

}
std::tuple <uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, int32_t, int32_t, uint32_t, uint8_t> com_jci_dvdProxy::GetDvdStatus() {
  return (*m_method_GetDvdStatus)();

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_dvdProxy::signal_DeviceStatusEvent() {
  return m_signalproxy_DeviceStatusEvent;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint16_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t > )>> com_jci_dvdProxy::signal_PlayingStatusEvent() {
  return m_signalproxy_PlayingStatusEvent;

}
