#include "com_jci_pb_objectProxy.h"

com_jci_pb_objectProxy::com_jci_pb_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                               std::string dest,
                                               std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_pbProxy = com_jci_pbProxy::create("com.jci.pb");
  this->add_interface(m_com_jci_pbProxy);

}
std::shared_ptr <com_jci_pb_objectProxy> com_jci_pb_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                        std::string dest,
                                                                        std::string path,
                                                                        DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_pb_objectProxy>
      created = std::shared_ptr<com_jci_pb_objectProxy>(new com_jci_pb_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_pbProxy> com_jci_pb_objectProxy::getcom_jci_pbInterface() {
  return m_com_jci_pbProxy;

}
