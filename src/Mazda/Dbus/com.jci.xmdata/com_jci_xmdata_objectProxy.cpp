#include "com_jci_xmdata_objectProxy.h"

com_jci_xmdata_objectProxy::com_jci_xmdata_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                       std::string dest,
                                                       std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_xmdataProxy = com_jci_xmdataProxy::create("com.jci.xmdata");
  this->add_interface(m_com_jci_xmdataProxy);

}
std::shared_ptr <com_jci_xmdata_objectProxy> com_jci_xmdata_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                std::string dest,
                                                                                std::string path,
                                                                                DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_xmdata_objectProxy>
      created = std::shared_ptr<com_jci_xmdata_objectProxy>(new com_jci_xmdata_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_xmdataProxy> com_jci_xmdata_objectProxy::getcom_jci_xmdataInterface() {
  return m_com_jci_xmdataProxy;

}
