#ifndef COM_JCI_CPP_SERVICE_SERVICEPROXY_H
#define COM_JCI_CPP_SERVICE_SERVICEPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_cpp_service_ServiceProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_cpp_service_ServiceProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_cpp_service_ServiceProxy> create(std::string name = "com.jci.cpp.service.Service");
  void ping(uint32_t timeout);
  void save(uint32_t timeout);
  void start(uint32_t timeout);
  void stop(uint32_t timeout);
 protected:
  std::shared_ptr<DBus::MethodProxy<void(uint32_t)>> m_method_ping;
  std::shared_ptr<DBus::MethodProxy<void(uint32_t)>> m_method_save;
  std::shared_ptr<DBus::MethodProxy<void(uint32_t)>> m_method_start;
  std::shared_ptr<DBus::MethodProxy<void(uint32_t)>> m_method_stop;
};
#endif /* COM_JCI_CPP_SERVICE_SERVICEPROXY_H */
