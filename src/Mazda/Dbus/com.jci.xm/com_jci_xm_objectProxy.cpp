#include "com_jci_xm_objectProxy.h"

com_jci_xm_objectProxy::com_jci_xm_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                               std::string dest,
                                               std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_xmProxy = com_jci_xmProxy::create("com.jci.xm");
  this->add_interface(m_com_jci_xmProxy);

}
std::shared_ptr <com_jci_xm_objectProxy> com_jci_xm_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                        std::string dest,
                                                                        std::string path,
                                                                        DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_xm_objectProxy>
      created = std::shared_ptr<com_jci_xm_objectProxy>(new com_jci_xm_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_xmProxy> com_jci_xm_objectProxy::getcom_jci_xmInterface() {
  return m_com_jci_xmProxy;

}
