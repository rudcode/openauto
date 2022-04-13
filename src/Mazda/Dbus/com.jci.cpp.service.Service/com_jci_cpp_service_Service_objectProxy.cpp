#include "com_jci_cpp_service_Service_objectProxy.h"

com_jci_cpp_service_Service_objectProxy::com_jci_cpp_service_Service_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                                                 std::string dest,
                                                                                 std::string path) : DBus::ObjectProxy(
    conn,
    dest,
    path) {
  m_com_jci_cpp_service_ServiceProxy = com_jci_cpp_service_ServiceProxy::create("com.jci.cpp.service.Service");
  this->add_interface(m_com_jci_cpp_service_ServiceProxy);

}
std::shared_ptr <com_jci_cpp_service_Service_objectProxy> com_jci_cpp_service_Service_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                                          std::string dest,
                                                                                                          std::string path,
                                                                                                          DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_cpp_service_Service_objectProxy> created =
      std::shared_ptr<com_jci_cpp_service_Service_objectProxy>(new com_jci_cpp_service_Service_objectProxy(conn,
                                                                                                           dest,
                                                                                                           path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_cpp_service_ServiceProxy> com_jci_cpp_service_Service_objectProxy::getcom_jci_cpp_service_ServiceInterface() {
  return m_com_jci_cpp_service_ServiceProxy;

}
