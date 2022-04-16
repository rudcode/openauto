#include "com_jci_lds_data_objectAdapter.h"

com_jci_lds_data_objectAdapter::com_jci_lds_data_objectAdapter(std::shared_ptr<com_jci_lds_dataInterface> _com_jci_lds_dataInterface,
                                                               std::string path) : DBus::Object(path) {
  this->add_interface(_com_jci_lds_dataInterface);

}
std::shared_ptr<com_jci_lds_data_objectAdapter> com_jci_lds_data_objectAdapter::create(std::shared_ptr<DBus::Connection> connection,
                                                                                       std::shared_ptr<
                                                                                           com_jci_lds_dataInterface> _com_jci_lds_dataInterface,
                                                                                       std::string path,
                                                                                       DBus::ThreadForCalling calling_thread) {
  std::shared_ptr<com_jci_lds_data_objectAdapter>
      adapter = std::shared_ptr<com_jci_lds_data_objectAdapter>(new com_jci_lds_data_objectAdapter(
      _com_jci_lds_dataInterface, path));
  if (connection) {
    if (connection->register_object(adapter, calling_thread) != DBus::RegistrationStatus::Success) {
      return std::shared_ptr<com_jci_lds_data_objectAdapter>();
    }
  }
  return adapter;

}
