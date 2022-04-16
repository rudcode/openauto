#include "com_jci_nativeguictrl_objectAdapter.h"

com_jci_nativeguictrl_objectAdapter::com_jci_nativeguictrl_objectAdapter(std::shared_ptr<com_jci_nativeguictrlInterface> _com_jci_nativeguictrlInterface,
                                                                         std::string path) : DBus::Object(path) {
  this->add_interface(_com_jci_nativeguictrlInterface);

}
std::shared_ptr<com_jci_nativeguictrl_objectAdapter> com_jci_nativeguictrl_objectAdapter::create(std::shared_ptr<DBus::Connection> connection,
                                                                                                 std::shared_ptr<
                                                                                                     com_jci_nativeguictrlInterface> _com_jci_nativeguictrlInterface,
                                                                                                 std::string path,
                                                                                                 DBus::ThreadForCalling calling_thread) {
  std::shared_ptr<com_jci_nativeguictrl_objectAdapter>
      adapter = std::shared_ptr<com_jci_nativeguictrl_objectAdapter>(new com_jci_nativeguictrl_objectAdapter(
      _com_jci_nativeguictrlInterface, path));
  if (connection) {
    if (connection->register_object(adapter, calling_thread) != DBus::RegistrationStatus::Success) {
      return std::shared_ptr<com_jci_nativeguictrl_objectAdapter>();
    }
  }
  return adapter;

}
