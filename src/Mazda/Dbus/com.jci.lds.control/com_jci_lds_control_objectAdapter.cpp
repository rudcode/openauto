#include "com_jci_lds_control_objectAdapter.h"

com_jci_lds_control_objectAdapter::com_jci_lds_control_objectAdapter(std::shared_ptr<com_jci_lds_controlInterface> _com_jci_lds_controlInterface,
                                                                     std::string path) : DBus::Object(path) {
  this->add_interface(_com_jci_lds_controlInterface);

}
std::shared_ptr<com_jci_lds_control_objectAdapter> com_jci_lds_control_objectAdapter::create(std::shared_ptr<DBus::Connection> connection,
                                                                                             std::shared_ptr<
                                                                                                 com_jci_lds_controlInterface> _com_jci_lds_controlInterface,
                                                                                             std::string path,
                                                                                             DBus::ThreadForCalling calling_thread) {
  std::shared_ptr<com_jci_lds_control_objectAdapter>
      adapter = std::shared_ptr<com_jci_lds_control_objectAdapter>(new com_jci_lds_control_objectAdapter(
      _com_jci_lds_controlInterface, path));
  if (connection) {
    if (connection->register_object(adapter, calling_thread) != DBus::RegistrationStatus::Success) {
      return std::shared_ptr<com_jci_lds_control_objectAdapter>();
    }
  }
  return adapter;

}
