#include "com_jci_sxms_nng_objectProxy.h"

com_jci_sxms_nng_objectProxy::com_jci_sxms_nng_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                           std::string dest,
                                                           std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_sxms_nngProxy = com_jci_sxms_nngProxy::create("com.jci.sxms_nng");
  this->add_interface(m_com_jci_sxms_nngProxy);

}
std::shared_ptr <com_jci_sxms_nng_objectProxy> com_jci_sxms_nng_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                    std::string dest,
                                                                                    std::string path,
                                                                                    DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_sxms_nng_objectProxy>
      created = std::shared_ptr<com_jci_sxms_nng_objectProxy>(new com_jci_sxms_nng_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_sxms_nngProxy> com_jci_sxms_nng_objectProxy::getcom_jci_sxms_nngInterface() {
  return m_com_jci_sxms_nngProxy;

}
