#include "com_jci_xm_mgrProxy.h"

com_jci_xm_mgrProxy::com_jci_xm_mgrProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_GetSubscriptionStatus = this->create_method<int32_t()>("GetSubscriptionStatus");
  m_method_GetXMInstalled = this->create_method<int32_t()>("GetXMInstalled");
  m_signalproxy_SubscriptionStatus =
      this->create_signal<void(std::tuple < int32_t, int32_t, int32_t, std::string, std::string > )>(
          "SubscriptionStatus");

}
std::shared_ptr <com_jci_xm_mgrProxy> com_jci_xm_mgrProxy::create(std::string name) {
  return std::shared_ptr<com_jci_xm_mgrProxy>(new com_jci_xm_mgrProxy(name));

}
int32_t com_jci_xm_mgrProxy::GetSubscriptionStatus() {
  return (*m_method_GetSubscriptionStatus)();

}
int32_t com_jci_xm_mgrProxy::GetXMInstalled() {
  return (*m_method_GetXMInstalled)();

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < int32_t,
                                        int32_t,
                                        int32_t,
                                        std::string,
                                        std::string > )>> com_jci_xm_mgrProxy::signal_SubscriptionStatus() {
  return m_signalproxy_SubscriptionStatus;

}
