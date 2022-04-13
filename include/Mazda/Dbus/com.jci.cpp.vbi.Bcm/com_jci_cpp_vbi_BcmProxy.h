#ifndef COM_JCI_CPP_VBI_BCMPROXY_H
#define COM_JCI_CPP_VBI_BCMPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_cpp_vbi_BcmProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_cpp_vbi_BcmProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_cpp_vbi_BcmProxy> create(std::string name = "com.jci.cpp.vbi.Bcm");
  uint32_t getSpeed();
  uint32_t getBoogie();
 protected:
  std::shared_ptr<DBus::MethodProxy<uint32_t()>> m_method_getSpeed;
  std::shared_ptr<DBus::MethodProxy<uint32_t()>> m_method_getBoogie;
};
#endif /* COM_JCI_CPP_VBI_BCMPROXY_H */
