#include "com_jci_natgui_objectProxy.h"

com_jci_natgui_objectProxy::com_jci_natgui_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                       std::string dest,
                                                       std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_natguiProxy = com_jci_natguiProxy::create("com.jci.natgui");
  this->add_interface(m_com_jci_natguiProxy);

}
std::shared_ptr <com_jci_natgui_objectProxy> com_jci_natgui_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                std::string dest,
                                                                                std::string path,
                                                                                DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_natgui_objectProxy>
      created = std::shared_ptr<com_jci_natgui_objectProxy>(new com_jci_natgui_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_natguiProxy> com_jci_natgui_objectProxy::getcom_jci_natguiInterface() {
  return m_com_jci_natguiProxy;

}
