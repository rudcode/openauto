#include "com_jci_aapa_objectAdapter.h"

com_jci_aapa_objectAdapter::com_jci_aapa_objectAdapter(std::shared_ptr<com_jci_aapaInterface> _com_jci_aapaInterface,
                                                       std::string path) : DBus::Object(path) {
  this->add_interface(_com_jci_aapaInterface);

}
std::shared_ptr<com_jci_aapa_objectAdapter> com_jci_aapa_objectAdapter::create(std::shared_ptr<DBus::Connection> connection,
                                                                               std::shared_ptr<com_jci_aapaInterface> _com_jci_aapaInterface,
                                                                               std::string path,
                                                                               DBus::ThreadForCalling calling_thread) {
  std::shared_ptr<com_jci_aapa_objectAdapter>
      adapter = std::shared_ptr<com_jci_aapa_objectAdapter>(new com_jci_aapa_objectAdapter(
      _com_jci_aapaInterface, path));
  if (connection) {
    if (connection->register_object(adapter, calling_thread) != DBus::RegistrationStatus::Success) {
      return std::shared_ptr<com_jci_aapa_objectAdapter>();
    }
  }
  return adapter;

}
