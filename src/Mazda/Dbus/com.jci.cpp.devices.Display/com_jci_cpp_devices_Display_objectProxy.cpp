#include "com_jci_cpp_devices_Display_objectProxy.h"

com_jci_cpp_devices_Display_objectProxy::com_jci_cpp_devices_Display_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                                                 std::string dest,
                                                                                 std::string path) : DBus::ObjectProxy(
    conn,
    dest,
    path) {
  m_com_jci_cpp_devices_DisplayProxy = com_jci_cpp_devices_DisplayProxy::create("com.jci.cpp.devices.Display");
  this->add_interface(m_com_jci_cpp_devices_DisplayProxy);

}
std::shared_ptr <com_jci_cpp_devices_Display_objectProxy> com_jci_cpp_devices_Display_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                                          std::string dest,
                                                                                                          std::string path,
                                                                                                          DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_cpp_devices_Display_objectProxy> created =
      std::shared_ptr<com_jci_cpp_devices_Display_objectProxy>(new com_jci_cpp_devices_Display_objectProxy(conn,
                                                                                                           dest,
                                                                                                           path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_cpp_devices_DisplayProxy> com_jci_cpp_devices_Display_objectProxy::getcom_jci_cpp_devices_DisplayInterface() {
  return m_com_jci_cpp_devices_DisplayProxy;

}
