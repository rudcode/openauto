#include "com_jci_cpp_vbi_Bcm_objectProxy.h"

com_jci_cpp_vbi_Bcm_objectProxy::com_jci_cpp_vbi_Bcm_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                                 std::string dest,
                                                                 std::string path) : DBus::ObjectProxy(conn,
                                                                                                       dest,
                                                                                                       path) {
  m_com_jci_cpp_vbi_BcmProxy = com_jci_cpp_vbi_BcmProxy::create("com.jci.cpp.vbi.Bcm");
  this->add_interface(m_com_jci_cpp_vbi_BcmProxy);

}
std::shared_ptr <com_jci_cpp_vbi_Bcm_objectProxy> com_jci_cpp_vbi_Bcm_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                          std::string dest,
                                                                                          std::string path,
                                                                                          DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_cpp_vbi_Bcm_objectProxy>
      created = std::shared_ptr<com_jci_cpp_vbi_Bcm_objectProxy>(new com_jci_cpp_vbi_Bcm_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_cpp_vbi_BcmProxy> com_jci_cpp_vbi_Bcm_objectProxy::getcom_jci_cpp_vbi_BcmInterface() {
  return m_com_jci_cpp_vbi_BcmProxy;

}
