#ifndef COM_JCI_BLM_STITCHERPROXY_H
#define COM_JCI_BLM_STITCHERPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_blm_stitcherProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_blm_stitcherProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_blm_stitcherProxy> create(std::string name = "com.jci.blm.stitcher");
  DBus::MultipleReturn<int32_t, uint32_t, bool> Connect();
  int32_t Disconnect(uint32_t sessionId);
  int32_t Command(uint32_t sessionId, uint8_t command, uint8_t groupType, uint64_t groupId);
  int32_t Rate(uint32_t sessionId, uint8_t groupType, uint64_t id, uint8_t rate, bool isRelative);
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, bool)>> signal_Connected();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint8_t)>> signal_Disconnected();
 protected:
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t, bool>()>> m_method_Connect;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_Disconnect;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint8_t, uint8_t, uint64_t)>> m_method_Command;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint8_t, uint64_t, uint8_t, bool)>> m_method_Rate;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, bool)>> m_signalproxy_Connected;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint8_t)>> m_signalproxy_Disconnected;
};
#endif /* COM_JCI_BLM_STITCHERPROXY_H */
