#include "com_jci_cpp_vbi_Amplifier_objectProxy.h"

com_jci_cpp_vbi_Amplifier_objectProxy::com_jci_cpp_vbi_Amplifier_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                                             std::string dest,
                                                                             std::string path) : DBus::ObjectProxy(conn,
                                                                                                                   dest,
                                                                                                                   path) {
  m_com_jci_cpp_vbi_AmplifierProxy = com_jci_cpp_vbi_AmplifierProxy::create("com.jci.cpp.vbi.Amplifier");
  this->add_interface(m_com_jci_cpp_vbi_AmplifierProxy);

}
std::shared_ptr <com_jci_cpp_vbi_Amplifier_objectProxy> com_jci_cpp_vbi_Amplifier_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                                      std::string dest,
                                                                                                      std::string path,
                                                                                                      DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_cpp_vbi_Amplifier_objectProxy> created =
      std::shared_ptr<com_jci_cpp_vbi_Amplifier_objectProxy>(new com_jci_cpp_vbi_Amplifier_objectProxy(conn,
                                                                                                       dest,
                                                                                                       path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_cpp_vbi_AmplifierProxy> com_jci_cpp_vbi_Amplifier_objectProxy::getcom_jci_cpp_vbi_AmplifierInterface() {
  return m_com_jci_cpp_vbi_AmplifierProxy;

}
