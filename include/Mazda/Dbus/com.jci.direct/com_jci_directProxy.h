#ifndef COM_JCI_DIRECTPROXY_H
#define COM_JCI_DIRECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_directProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_directProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_directProxy> create(std::string name = "com.jci.direct");
  std::string GetDirectConnection();
 protected:
  std::shared_ptr<DBus::MethodProxy<std::string()>> m_method_GetDirectConnection;
};
#endif /* COM_JCI_DIRECTPROXY_H */
