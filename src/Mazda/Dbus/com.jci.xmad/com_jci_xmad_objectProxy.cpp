#include "com_jci_xmad_objectProxy.h"

com_jci_xmad_objectProxy::com_jci_xmad_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                   std::string dest,
                                                   std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_xmadProxy = com_jci_xmadProxy::create("com.jci.xmad");
  this->add_interface(m_com_jci_xmadProxy);

}
std::shared_ptr <com_jci_xmad_objectProxy> com_jci_xmad_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                            std::string dest,
                                                                            std::string path,
                                                                            DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_xmad_objectProxy>
      created = std::shared_ptr<com_jci_xmad_objectProxy>(new com_jci_xmad_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_xmadProxy> com_jci_xmad_objectProxy::getcom_jci_xmadInterface() {
  return m_com_jci_xmadProxy;

}
