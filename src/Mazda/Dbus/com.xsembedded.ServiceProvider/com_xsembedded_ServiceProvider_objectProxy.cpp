#include "com_xsembedded_ServiceProvider_objectProxy.h"

com_xsembedded_ServiceProvider_objectProxy::com_xsembedded_ServiceProvider_objectProxy(std::shared_ptr<DBus::Connection> conn,
                                                                                       std::string dest,
                                                                                       std::string path)
    : DBus::ObjectProxy(conn, dest, path) {
  m_com_xsembedded_ServiceProviderProxy = com_xsembedded_ServiceProviderProxy::create("com.xsembedded.ServiceProvider");
  this->add_interface(m_com_xsembedded_ServiceProviderProxy);

}
std::shared_ptr<com_xsembedded_ServiceProvider_objectProxy> com_xsembedded_ServiceProvider_objectProxy::create(std::shared_ptr<
    DBus::Connection> conn, std::string dest, std::string path, DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr<com_xsembedded_ServiceProvider_objectProxy> created =
      std::shared_ptr<com_xsembedded_ServiceProvider_objectProxy>(new com_xsembedded_ServiceProvider_objectProxy(conn,
                                                                                                                 dest,
                                                                                                                 path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr<com_xsembedded_ServiceProviderProxy> com_xsembedded_ServiceProvider_objectProxy::getcom_xsembedded_ServiceProviderInterface() {
  return m_com_xsembedded_ServiceProviderProxy;

}
