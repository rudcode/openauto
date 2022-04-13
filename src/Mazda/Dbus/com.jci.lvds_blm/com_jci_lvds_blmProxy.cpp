#include "com_jci_lvds_blmProxy.h"

com_jci_lvds_blmProxy::com_jci_lvds_blmProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_KillWaylandclient = this->create_method<uint32_t()>("KillWaylandclient");
  m_signalproxy_DiagScreenKilledResp = this->create_signal<void(int16_t)>("DiagScreenKilledResp");

}
std::shared_ptr <com_jci_lvds_blmProxy> com_jci_lvds_blmProxy::create(std::string name) {
  return std::shared_ptr<com_jci_lvds_blmProxy>(new com_jci_lvds_blmProxy(name));

}
uint32_t com_jci_lvds_blmProxy::KillWaylandclient() {
  return (*m_method_KillWaylandclient)();

}
std::shared_ptr <DBus::SignalProxy<void(int16_t)>> com_jci_lvds_blmProxy::signal_DiagScreenKilledResp() {
  return m_signalproxy_DiagScreenKilledResp;

}
