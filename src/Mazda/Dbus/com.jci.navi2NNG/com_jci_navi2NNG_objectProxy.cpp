#include "com_jci_navi2NNG_objectProxy.h"

com_jci_navi2NNG_objectProxy::com_jci_navi2NNG_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                           std::string dest,
                                                           std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_navi2NNGProxy = com_jci_navi2NNGProxy::create("com.jci.navi2NNG");
  this->add_interface(m_com_jci_navi2NNGProxy);

}
std::shared_ptr <com_jci_navi2NNG_objectProxy> com_jci_navi2NNG_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                    std::string dest,
                                                                                    std::string path,
                                                                                    DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_navi2NNG_objectProxy>
      created = std::shared_ptr<com_jci_navi2NNG_objectProxy>(new com_jci_navi2NNG_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_navi2NNGProxy> com_jci_navi2NNG_objectProxy::getcom_jci_navi2NNGInterface() {
  return m_com_jci_navi2NNGProxy;

}
