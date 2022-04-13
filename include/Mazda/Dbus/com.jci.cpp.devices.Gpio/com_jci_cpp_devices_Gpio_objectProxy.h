#ifndef COM_JCI_CPP_DEVICES_GPIO_OBJECTPROXY_H
#define COM_JCI_CPP_DEVICES_GPIO_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_cpp_devices_GpioProxy.h"
class com_jci_cpp_devices_Gpio_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_cpp_devices_Gpio_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_cpp_devices_Gpio_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                                      std::string dest,
                                                                      std::string path,
                                                                      DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_cpp_devices_GpioProxy> getcom_jci_cpp_devices_GpioInterface();
 protected:
  std::shared_ptr<com_jci_cpp_devices_GpioProxy> m_com_jci_cpp_devices_GpioProxy;
};
#endif /* COM_JCI_CPP_DEVICES_GPIO_OBJECTPROXY_H */
