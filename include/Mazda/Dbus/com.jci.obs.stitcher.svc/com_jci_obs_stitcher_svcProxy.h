#ifndef COM_JCI_OBS_STITCHER_SVCPROXY_H
#define COM_JCI_OBS_STITCHER_SVCPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_obs_stitcher_svcProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_obs_stitcher_svcProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_obs_stitcher_svcProxy> create(std::string name = "com.jci.obs.stitcher.svc");
  DBus::MultipleReturn<int32_t, uint32_t> ConnectUsingPseudoTerminal(std::string pseudoTerminal,
                                                                     std::string sessionName);
  int32_t Disconnect(uint32_t sessionId, uint32_t reasonId);
  int32_t Command(uint32_t sessionId, uint8_t command, uint8_t groupType, uint64_t groupId);
  int32_t Rate(uint32_t sessionId, uint8_t type, uint64_t id, uint8_t rate, bool isRelative);
 protected:
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t>(std::string, std::string)>>
      m_method_ConnectUsingPseudoTerminal;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t)>> m_method_Disconnect;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint8_t, uint8_t, uint64_t)>> m_method_Command;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint8_t, uint64_t, uint8_t, bool)>> m_method_Rate;
};
#endif /* COM_JCI_OBS_STITCHER_SVCPROXY_H */
