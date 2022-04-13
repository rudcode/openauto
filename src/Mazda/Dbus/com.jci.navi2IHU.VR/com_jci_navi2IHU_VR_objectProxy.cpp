#include "com_jci_navi2IHU_VR_objectProxy.h"

com_jci_navi2IHU_VR_objectProxy::com_jci_navi2IHU_VR_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                                 std::string dest,
                                                                 std::string path) : DBus::ObjectProxy(conn,
                                                                                                       dest,
                                                                                                       path) {
  m_com_jci_navi2IHU_VRProxy = com_jci_navi2IHU_VRProxy::create("com.jci.navi2IHU.VR");
  this->add_interface(m_com_jci_navi2IHU_VRProxy);

}
std::shared_ptr <com_jci_navi2IHU_VR_objectProxy> com_jci_navi2IHU_VR_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                          std::string dest,
                                                                                          std::string path,
                                                                                          DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_navi2IHU_VR_objectProxy>
      created = std::shared_ptr<com_jci_navi2IHU_VR_objectProxy>(new com_jci_navi2IHU_VR_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_navi2IHU_VRProxy> com_jci_navi2IHU_VR_objectProxy::getcom_jci_navi2IHU_VRInterface() {
  return m_com_jci_navi2IHU_VRProxy;

}
