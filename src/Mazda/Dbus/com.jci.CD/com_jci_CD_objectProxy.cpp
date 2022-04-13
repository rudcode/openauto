#include "com_jci_CD_objectProxy.h"

com_jci_CD_objectProxy::com_jci_CD_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                               std::string dest,
                                               std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_CDProxy = com_jci_CDProxy::create("com.jci.CD");
  this->add_interface(m_com_jci_CDProxy);

}
std::shared_ptr <com_jci_CD_objectProxy> com_jci_CD_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                        std::string dest,
                                                                        std::string path,
                                                                        DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_CD_objectProxy>
      created = std::shared_ptr<com_jci_CD_objectProxy>(new com_jci_CD_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_CDProxy> com_jci_CD_objectProxy::getcom_jci_CDInterface() {
  return m_com_jci_CDProxy;

}
