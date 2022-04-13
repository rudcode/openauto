#include "com_jci_usbms_objectProxy.h"

com_jci_usbms_objectProxy::com_jci_usbms_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                     std::string dest,
                                                     std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_usbmsProxy = com_jci_usbmsProxy::create("com.jci.usbms");
  this->add_interface(m_com_jci_usbmsProxy);

}
std::shared_ptr <com_jci_usbms_objectProxy> com_jci_usbms_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                              std::string dest,
                                                                              std::string path,
                                                                              DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_usbms_objectProxy>
      created = std::shared_ptr<com_jci_usbms_objectProxy>(new com_jci_usbms_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_usbmsProxy> com_jci_usbms_objectProxy::getcom_jci_usbmsInterface() {
  return m_com_jci_usbmsProxy;

}
