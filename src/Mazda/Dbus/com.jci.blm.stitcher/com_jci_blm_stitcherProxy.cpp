#include "com_jci_blm_stitcherProxy.h"

com_jci_blm_stitcherProxy::com_jci_blm_stitcherProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_Connect = this->create_method<DBus::MultipleReturn<int32_t, uint32_t, bool>()>("Connect");
  m_method_Disconnect = this->create_method<int32_t(uint32_t)>("Disconnect");
  m_method_Command = this->create_method<int32_t(uint32_t, uint8_t, uint8_t, uint64_t)>("Command");
  m_method_Rate = this->create_method<int32_t(uint32_t, uint8_t, uint64_t, uint8_t, bool)>("Rate");
  m_signalproxy_Connected = this->create_signal<void(uint32_t, bool)>("Connected");
  m_signalproxy_Disconnected = this->create_signal<void(uint32_t, uint8_t)>("Disconnected");

}
std::shared_ptr <com_jci_blm_stitcherProxy> com_jci_blm_stitcherProxy::create(std::string name) {
  return std::shared_ptr<com_jci_blm_stitcherProxy>(new com_jci_blm_stitcherProxy(name));

}
DBus::MultipleReturn<int32_t, uint32_t, bool> com_jci_blm_stitcherProxy::Connect() {
  return (*m_method_Connect)();

}
int32_t com_jci_blm_stitcherProxy::Disconnect(uint32_t sessionId) {
  return (*m_method_Disconnect)(sessionId);

}
int32_t com_jci_blm_stitcherProxy::Command(uint32_t sessionId, uint8_t command, uint8_t groupType, uint64_t groupId) {
  return (*m_method_Command)(sessionId, command, groupType, groupId);

}
int32_t com_jci_blm_stitcherProxy::Rate(uint32_t sessionId,
                                        uint8_t groupType,
                                        uint64_t id,
                                        uint8_t rate,
                                        bool isRelative) {
  return (*m_method_Rate)(sessionId, groupType, id, rate, isRelative);

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, bool)>> com_jci_blm_stitcherProxy::signal_Connected() {
  return m_signalproxy_Connected;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, uint8_t)>> com_jci_blm_stitcherProxy::signal_Disconnected() {
  return m_signalproxy_Disconnected;

}
