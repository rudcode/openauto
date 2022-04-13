#include "com_jci_VIDEOCTRL_objectProxy.h"

com_jci_VIDEOCTRL_objectProxy::com_jci_VIDEOCTRL_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                             std::string dest,
                                                             std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_jci_VIDEOCTRLProxy = com_jci_VIDEOCTRLProxy::create("com.jci.VIDEOCTRL");
  this->add_interface(m_com_jci_VIDEOCTRLProxy);

}
std::shared_ptr <com_jci_VIDEOCTRL_objectProxy> com_jci_VIDEOCTRL_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                      std::string dest,
                                                                                      std::string path,
                                                                                      DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_VIDEOCTRL_objectProxy>
      created = std::shared_ptr<com_jci_VIDEOCTRL_objectProxy>(new com_jci_VIDEOCTRL_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_VIDEOCTRLProxy> com_jci_VIDEOCTRL_objectProxy::getcom_jci_VIDEOCTRLInterface() {
  return m_com_jci_VIDEOCTRLProxy;

}
