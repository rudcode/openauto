#include "com_jci_bucpsa_objectAdapter.h"

com_jci_bucpsa_objectAdapter::com_jci_bucpsa_objectAdapter(std::shared_ptr<com_jci_bucpsaInterface> _com_jci_bucpsaInterface,
                                                           std::string path) : DBus::Object(path) {
  this->add_interface(_com_jci_bucpsaInterface);

}
std::shared_ptr<com_jci_bucpsa_objectAdapter> com_jci_bucpsa_objectAdapter::create(std::shared_ptr<DBus::Connection> connection,
                                                                                   std::shared_ptr<
                                                                                       com_jci_bucpsaInterface> _com_jci_bucpsaInterface,
                                                                                   std::string path,
                                                                                   DBus::ThreadForCalling calling_thread) {
  std::shared_ptr<com_jci_bucpsa_objectAdapter>
      adapter = std::shared_ptr<com_jci_bucpsa_objectAdapter>(new com_jci_bucpsa_objectAdapter(
      _com_jci_bucpsaInterface, path));
  if (connection) {
    if (connection->register_object(adapter, calling_thread) != DBus::RegistrationStatus::Success) {
      return std::shared_ptr<com_jci_bucpsa_objectAdapter>();
    }
  }
  return adapter;

}
