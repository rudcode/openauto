#ifndef COM_JCI_NATIVEGUICTRLPROXY_H
#define COM_JCI_NATIVEGUICTRLPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_nativeguictrlProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_nativeguictrlProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_nativeguictrlProxy> create(std::string name = "com.jci.nativeguictrl");
  void SetRequiredSurfaces(std::string surfaces, int16_t bFadeOpera);
 protected:
  std::shared_ptr<DBus::MethodProxy<void(std::string, int16_t)>> m_method_SetRequiredSurfaces;
};
#endif /* COM_JCI_NATIVEGUICTRLPROXY_H */
