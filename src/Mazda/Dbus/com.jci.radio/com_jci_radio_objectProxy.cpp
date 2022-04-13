#include "com_jci_radio_objectProxy.h"

com_jci_radio_objectProxy::com_jci_radio_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                     std::string dest,
                                                     std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_radioProxy = com_jci_radioProxy::create("com.jci.radio");
  this->add_interface(m_com_jci_radioProxy);

}
std::shared_ptr <com_jci_radio_objectProxy> com_jci_radio_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                              std::string dest,
                                                                              std::string path,
                                                                              DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_radio_objectProxy>
      created = std::shared_ptr<com_jci_radio_objectProxy>(new com_jci_radio_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_radioProxy> com_jci_radio_objectProxy::getcom_jci_radioInterface() {
  return m_com_jci_radioProxy;

}
