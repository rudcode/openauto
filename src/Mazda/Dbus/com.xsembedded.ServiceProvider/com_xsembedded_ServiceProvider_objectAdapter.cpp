#include "com_xsembedded_ServiceProvider_objectAdapter.h"

com_xsembedded_ServiceProvider_objectAdapter::com_xsembedded_ServiceProvider_objectAdapter(std::shared_ptr<
    com_xsembedded_ServiceProviderInterface> _com_xsembedded_ServiceProviderInterface, std::string path) : DBus::Object(
    path) {
  this->add_interface(_com_xsembedded_ServiceProviderInterface);

}
std::shared_ptr<com_xsembedded_ServiceProvider_objectAdapter> com_xsembedded_ServiceProvider_objectAdapter::create(std::shared_ptr<
    DBus::Connection> connection,
                                                                                                                   std::shared_ptr<
                                                                                                                       com_xsembedded_ServiceProviderInterface> _com_xsembedded_ServiceProviderInterface,
                                                                                                                   std::string path,
                                                                                                                   DBus::ThreadForCalling calling_thread) {
  std::shared_ptr<com_xsembedded_ServiceProvider_objectAdapter> adapter =
      std::shared_ptr<com_xsembedded_ServiceProvider_objectAdapter>(new com_xsembedded_ServiceProvider_objectAdapter(
          _com_xsembedded_ServiceProviderInterface, path));
  if (connection) {
    if (connection->register_object(adapter, calling_thread) != DBus::RegistrationStatus::Success) {
      return std::shared_ptr<com_xsembedded_ServiceProvider_objectAdapter>();
    }
  }
  return adapter;

}
