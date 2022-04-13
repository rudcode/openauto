#include "com_jci_cpp_devices_Keyboard_objectProxy.h"

com_jci_cpp_devices_Keyboard_objectProxy::com_jci_cpp_devices_Keyboard_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                                                   std::string dest,
                                                                                   std::string path)
    : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_cpp_devices_KeyboardProxy = com_jci_cpp_devices_KeyboardProxy::create("com.jci.cpp.devices.Keyboard");
  this->add_interface(m_com_jci_cpp_devices_KeyboardProxy);

}
std::shared_ptr <com_jci_cpp_devices_Keyboard_objectProxy> com_jci_cpp_devices_Keyboard_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                                            std::string dest,
                                                                                                            std::string path,
                                                                                                            DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_cpp_devices_Keyboard_objectProxy> created =
      std::shared_ptr<com_jci_cpp_devices_Keyboard_objectProxy>(new com_jci_cpp_devices_Keyboard_objectProxy(conn,
                                                                                                             dest,
                                                                                                             path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_cpp_devices_KeyboardProxy> com_jci_cpp_devices_Keyboard_objectProxy::getcom_jci_cpp_devices_KeyboardInterface() {
  return m_com_jci_cpp_devices_KeyboardProxy;

}
