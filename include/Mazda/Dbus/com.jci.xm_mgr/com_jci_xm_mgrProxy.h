#ifndef COM_JCI_XM_MGRPROXY_H
#define COM_JCI_XM_MGRPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_xm_mgrProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_xm_mgrProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_xm_mgrProxy> create(std::string name = "com.jci.xm_mgr");
  int32_t GetSubscriptionStatus();
  int32_t GetXMInstalled();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t,
                                                    int32_t,
                                                    int32_t,
                                                    std::string,
                                                    std::string>)>> signal_SubscriptionStatus();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetSubscriptionStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetXMInstalled;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t, int32_t, int32_t, std::string, std::string>)>>
      m_signalproxy_SubscriptionStatus;
};
#endif /* COM_JCI_XM_MGRPROXY_H */
