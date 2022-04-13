#ifndef COM_JCI_BLM_TIMEPROXY_H
#define COM_JCI_BLM_TIMEPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_BLM_TIMEProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_BLM_TIMEProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_BLM_TIMEProxy> create(std::string name = "com.jci.BLM_TIME");
  DBus::MultipleReturn<uint32_t, uint32_t, uint32_t, uint64_t> GetClock();
  DBus::MultipleReturn<uint32_t, uint32_t, uint64_t> GetClockEx();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t, uint32_t, uint64_t)>> signal_ClockChanged();
 protected:
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, uint32_t, uint64_t>()>> m_method_GetClock;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, uint64_t>()>> m_method_GetClockEx;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t, uint32_t, uint64_t)>> m_signalproxy_ClockChanged;
};
#endif /* COM_JCI_BLM_TIMEPROXY_H */
