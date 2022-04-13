#include "com_jci_cpp_dbus_DbusConnection_objectProxy.h"

com_jci_cpp_dbus_DbusConnection_objectProxy::com_jci_cpp_dbus_DbusConnection_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                                                         std::string dest,
                                                                                         std::string path)
    : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_cpp_dbus_DbusConnectionProxy =
      com_jci_cpp_dbus_DbusConnectionProxy::create("com.jci.cpp.dbus.DbusConnection");
  this->add_interface(m_com_jci_cpp_dbus_DbusConnectionProxy);

}
std::shared_ptr <com_jci_cpp_dbus_DbusConnection_objectProxy> com_jci_cpp_dbus_DbusConnection_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                                                  std::string dest,
                                                                                                                  std::string path,
                                                                                                                  DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_cpp_dbus_DbusConnection_objectProxy> created =
      std::shared_ptr<com_jci_cpp_dbus_DbusConnection_objectProxy>(new com_jci_cpp_dbus_DbusConnection_objectProxy(conn,
                                                                                                                   dest,
                                                                                                                   path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_cpp_dbus_DbusConnectionProxy> com_jci_cpp_dbus_DbusConnection_objectProxy::getcom_jci_cpp_dbus_DbusConnectionInterface() {
  return m_com_jci_cpp_dbus_DbusConnectionProxy;

}
