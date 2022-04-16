#include "com_jci_bds_objectAdapter.h"

com_jci_bds_objectAdapter::com_jci_bds_objectAdapter(std::shared_ptr <com_jci_bdsInterface> _com_jci_bdsInterface,
                                                     std::string path) : DBus::Object(path) {
  this->add_interface(_com_jci_bdsInterface);

}
std::shared_ptr <com_jci_bds_objectAdapter> com_jci_bds_objectAdapter::create(std::shared_ptr <DBus::Connection> connection,
                                                                              std::shared_ptr <com_jci_bdsInterface> _com_jci_bdsInterface,
                                                                              std::string path,
                                                                              DBus::ThreadForCalling calling_thread) {
  std::shared_ptr <com_jci_bds_objectAdapter>
      adapter = std::shared_ptr<com_jci_bds_objectAdapter>(new com_jci_bds_objectAdapter(
      _com_jci_bdsInterface, path));
  if (connection) {
    if (connection->register_object(adapter, calling_thread) != DBus::RegistrationStatus::Success) {
      return std::shared_ptr<com_jci_bds_objectAdapter>();
    }
  }
  return adapter;

}
