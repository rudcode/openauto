#ifndef COM_JCI_NATGUIPROXY_H
#define COM_JCI_NATGUIPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_natguiProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_natguiProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_natguiProxy> create(std::string name = "com.jci.natgui");
  int32_t SetDisplay(std::tuple<std::vector<uint32_t>, uint32_t, uint32_t> imageData);
  int32_t SetLanguage_async(uint32_t currentLanguage);
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> signal_LanguageSetStatus();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t(std::tuple<std::vector<uint32_t>, uint32_t, uint32_t>)>>
      m_method_SetDisplay;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_SetLanguage_async;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> m_signalproxy_LanguageSetStatus;
};
#endif /* COM_JCI_NATGUIPROXY_H */
