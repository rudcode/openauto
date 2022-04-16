#include "com_jci_bca_objectAdapter.h"

com_jci_bca_objectAdapter::com_jci_bca_objectAdapter(std::shared_ptr<com_jci_bcaInterface> _com_jci_bcaInterface,
                                                     std::string path) : DBus::Object(path) {
  this->add_interface(_com_jci_bcaInterface);

}
std::shared_ptr<com_jci_bca_objectAdapter> com_jci_bca_objectAdapter::create(std::shared_ptr<DBus::Connection> connection,
                                                                             std::shared_ptr<com_jci_bcaInterface> _com_jci_bcaInterface,
                                                                             std::string path,
                                                                             DBus::ThreadForCalling calling_thread) {
  std::shared_ptr<com_jci_bca_objectAdapter>
      adapter = std::shared_ptr<com_jci_bca_objectAdapter>(new com_jci_bca_objectAdapter(
      _com_jci_bcaInterface, path));
  if (connection) {
    if (connection->register_object(adapter, calling_thread) != DBus::RegistrationStatus::Success) {
      return std::shared_ptr<com_jci_bca_objectAdapter>();
    }
  }
  return adapter;

}
