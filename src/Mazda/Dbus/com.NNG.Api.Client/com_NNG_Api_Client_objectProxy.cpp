#include "com_NNG_Api_Client_objectProxy.h"

com_NNG_Api_Client_objectProxy::com_NNG_Api_Client_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                               std::string dest,
                                                               std::string path) : DBus::ObjectProxy(conn, dest, path) {
  m_com_NNG_Api_ClientProxy = com_NNG_Api_ClientProxy::create("com.NNG.Api.Client");
  this->add_interface(m_com_NNG_Api_ClientProxy);

}
std::shared_ptr <com_NNG_Api_Client_objectProxy> com_NNG_Api_Client_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                        std::string dest,
                                                                                        std::string path,
                                                                                        DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_NNG_Api_Client_objectProxy>
      created = std::shared_ptr<com_NNG_Api_Client_objectProxy>(new com_NNG_Api_Client_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_NNG_Api_ClientProxy> com_NNG_Api_Client_objectProxy::getcom_NNG_Api_ClientInterface() {
  return m_com_NNG_Api_ClientProxy;

}
