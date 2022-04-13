#include "com_jci_obs_stitcher_svcProxy.h"

com_jci_obs_stitcher_svcProxy::com_jci_obs_stitcher_svcProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_ConnectUsingPseudoTerminal =
      this->create_method<DBus::MultipleReturn<int32_t, uint32_t>(std::string, std::string)>(
          "ConnectUsingPseudoTerminal");
  m_method_Disconnect = this->create_method<int32_t(uint32_t, uint32_t)>("Disconnect");
  m_method_Command = this->create_method<int32_t(uint32_t, uint8_t, uint8_t, uint64_t)>("Command");
  m_method_Rate = this->create_method<int32_t(uint32_t, uint8_t, uint64_t, uint8_t, bool)>("Rate");

}
std::shared_ptr <com_jci_obs_stitcher_svcProxy> com_jci_obs_stitcher_svcProxy::create(std::string name) {
  return std::shared_ptr<com_jci_obs_stitcher_svcProxy>(new com_jci_obs_stitcher_svcProxy(name));

}
DBus::MultipleReturn <int32_t, uint32_t> com_jci_obs_stitcher_svcProxy::ConnectUsingPseudoTerminal(std::string pseudoTerminal,
                                                                                                   std::string sessionName) {
  return (*m_method_ConnectUsingPseudoTerminal)(pseudoTerminal, sessionName);

}
int32_t com_jci_obs_stitcher_svcProxy::Disconnect(uint32_t sessionId, uint32_t reasonId) {
  return (*m_method_Disconnect)(sessionId, reasonId);

}
int32_t com_jci_obs_stitcher_svcProxy::Command(uint32_t sessionId,
                                               uint8_t command,
                                               uint8_t groupType,
                                               uint64_t groupId) {
  return (*m_method_Command)(sessionId, command, groupType, groupId);

}
int32_t com_jci_obs_stitcher_svcProxy::Rate(uint32_t sessionId,
                                            uint8_t type,
                                            uint64_t id,
                                            uint8_t rate,
                                            bool isRelative) {
  return (*m_method_Rate)(sessionId, type, id, rate, isRelative);

}
