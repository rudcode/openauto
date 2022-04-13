#ifndef COM_JCI_TVPROXY_H
#define COM_JCI_TVPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_tvProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_tvProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_tvProxy> create(std::string name = "com.jci.tv");
  uint32_t SourceSelect();
  void UIStatus(uint32_t uiStatusUpdate);
  void EmBroControl(uint32_t emBroOption);
  std::tuple<uint32_t, uint32_t, uint32_t, uint32_t> handShakeRequest();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_TvEvent();
 protected:
  std::shared_ptr<DBus::MethodProxy<uint32_t()>> m_method_SourceSelect;
  std::shared_ptr<DBus::MethodProxy<void(uint32_t)>> m_method_UIStatus;
  std::shared_ptr<DBus::MethodProxy<void(uint32_t)>> m_method_EmBroControl;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t, uint32_t, uint32_t, uint32_t>()>> m_method_handShakeRequest;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_TvEvent;
};
#endif /* COM_JCI_TVPROXY_H */
