#include "com_jci_BLM_TIME_objectProxy.h"

com_jci_BLM_TIME_objectProxy::com_jci_BLM_TIME_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                           std::string dest,
                                                           std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_BLM_TIMEProxy = com_jci_BLM_TIMEProxy::create("com.jci.BLM_TIME");
  this->add_interface(m_com_jci_BLM_TIMEProxy);

}
std::shared_ptr <com_jci_BLM_TIME_objectProxy> com_jci_BLM_TIME_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                    std::string dest,
                                                                                    std::string path,
                                                                                    DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_BLM_TIME_objectProxy>
      created = std::shared_ptr<com_jci_BLM_TIME_objectProxy>(new com_jci_BLM_TIME_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_BLM_TIMEProxy> com_jci_BLM_TIME_objectProxy::getcom_jci_BLM_TIMEInterface() {
  return m_com_jci_BLM_TIMEProxy;

}
