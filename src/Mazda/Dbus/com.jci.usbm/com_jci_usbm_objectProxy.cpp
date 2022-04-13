#include "com_jci_usbm_objectProxy.h"

com_jci_usbm_objectProxy::com_jci_usbm_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                   std::string dest,
                                                   std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_usbmProxy = com_jci_usbmProxy::create("com.jci.usbm");
  this->add_interface(m_com_jci_usbmProxy);

}
std::shared_ptr <com_jci_usbm_objectProxy> com_jci_usbm_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                            std::string dest,
                                                                            std::string path,
                                                                            DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_usbm_objectProxy>
      created = std::shared_ptr<com_jci_usbm_objectProxy>(new com_jci_usbm_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_usbmProxy> com_jci_usbm_objectProxy::getcom_jci_usbmInterface() {
  return m_com_jci_usbmProxy;

}
