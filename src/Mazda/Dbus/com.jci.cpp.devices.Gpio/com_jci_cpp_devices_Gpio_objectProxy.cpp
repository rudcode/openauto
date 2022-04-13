#include "com_jci_cpp_devices_Gpio_objectProxy.h"

com_jci_cpp_devices_Gpio_objectProxy::com_jci_cpp_devices_Gpio_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                                           std::string dest,
                                                                           std::string path) : DBus::ObjectProxy(conn,
                                                                                                                 dest,
                                                                                                                 path) {
  m_com_jci_cpp_devices_GpioProxy = com_jci_cpp_devices_GpioProxy::create("com.jci.cpp.devices.Gpio");
  this->add_interface(m_com_jci_cpp_devices_GpioProxy);

}
std::shared_ptr <com_jci_cpp_devices_Gpio_objectProxy> com_jci_cpp_devices_Gpio_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                                    std::string dest,
                                                                                                    std::string path,
                                                                                                    DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_cpp_devices_Gpio_objectProxy> created =
      std::shared_ptr<com_jci_cpp_devices_Gpio_objectProxy>(new com_jci_cpp_devices_Gpio_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_cpp_devices_GpioProxy> com_jci_cpp_devices_Gpio_objectProxy::getcom_jci_cpp_devices_GpioInterface() {
  return m_com_jci_cpp_devices_GpioProxy;

}
