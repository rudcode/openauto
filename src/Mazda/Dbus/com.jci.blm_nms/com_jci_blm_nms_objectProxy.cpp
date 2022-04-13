#include "com_jci_blm_nms_objectProxy.h"

com_jci_blm_nms_objectProxy::com_jci_blm_nms_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                         std::string dest,
                                                         std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_blm_nmsProxy = com_jci_blm_nmsProxy::create("com.jci.blm_nms");
  this->add_interface(m_com_jci_blm_nmsProxy);

}
std::shared_ptr <com_jci_blm_nms_objectProxy> com_jci_blm_nms_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                  std::string dest,
                                                                                  std::string path,
                                                                                  DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_blm_nms_objectProxy>
      created = std::shared_ptr<com_jci_blm_nms_objectProxy>(new com_jci_blm_nms_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_blm_nmsProxy> com_jci_blm_nms_objectProxy::getcom_jci_blm_nmsInterface() {
  return m_com_jci_blm_nmsProxy;

}
