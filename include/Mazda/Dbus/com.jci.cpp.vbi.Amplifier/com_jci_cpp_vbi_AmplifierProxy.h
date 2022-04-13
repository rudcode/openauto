#ifndef COM_JCI_CPP_VBI_AMPLIFIERPROXY_H
#define COM_JCI_CPP_VBI_AMPLIFIERPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_cpp_vbi_AmplifierProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_cpp_vbi_AmplifierProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_cpp_vbi_AmplifierProxy> create(std::string name = "com.jci.cpp.vbi.Amplifier");
  uint32_t getVolume();
  void setVolume(uint32_t level);
 protected:
  std::shared_ptr<DBus::MethodProxy<uint32_t()>> m_method_getVolume;
  std::shared_ptr<DBus::MethodProxy<void(uint32_t)>> m_method_setVolume;
};
#endif /* COM_JCI_CPP_VBI_AMPLIFIERPROXY_H */
