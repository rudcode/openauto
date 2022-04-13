#include "com_jci_BLM_TIMEProxy.h"

com_jci_BLM_TIMEProxy::com_jci_BLM_TIMEProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_GetClock = this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, uint32_t, uint64_t>()>("GetClock");
  m_method_GetClockEx = this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, uint64_t>()>("GetClockEx");
  m_signalproxy_ClockChanged = this->create_signal<void(uint32_t, uint32_t, uint32_t, uint64_t)>("ClockChanged");

}
std::shared_ptr <com_jci_BLM_TIMEProxy> com_jci_BLM_TIMEProxy::create(std::string name) {
  return std::shared_ptr<com_jci_BLM_TIMEProxy>(new com_jci_BLM_TIMEProxy(name));

}
DBus::MultipleReturn <uint32_t, uint32_t, uint32_t, uint64_t> com_jci_BLM_TIMEProxy::GetClock() {
  return (*m_method_GetClock)();

}
DBus::MultipleReturn <uint32_t, uint32_t, uint64_t> com_jci_BLM_TIMEProxy::GetClockEx() {
  return (*m_method_GetClockEx)();

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        uint32_t,
                                        uint32_t,
                                        uint64_t)>> com_jci_BLM_TIMEProxy::signal_ClockChanged() {
  return m_signalproxy_ClockChanged;

}
