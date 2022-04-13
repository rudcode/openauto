#ifndef COM_JCI_LVDS_BLMPROXY_H
#define COM_JCI_LVDS_BLMPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_lvds_blmProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_lvds_blmProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_lvds_blmProxy> create(std::string name = "com.jci.lvds_blm");
  uint32_t KillWaylandclient();
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> signal_DiagScreenKilledResp();
 protected:
  std::shared_ptr<DBus::MethodProxy<uint32_t()>> m_method_KillWaylandclient;
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> m_signalproxy_DiagScreenKilledResp;
};
#endif /* COM_JCI_LVDS_BLMPROXY_H */
