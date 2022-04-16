#include "com_jci_navi2IHU_HUDSettings_objectAdapter.h"

com_jci_navi2IHU_HUDSettings_objectAdapter::com_jci_navi2IHU_HUDSettings_objectAdapter(std::shared_ptr<
    com_jci_navi2IHU_HUDSettingsInterface> _com_jci_navi2IHU_HUDSettingsInterface, std::string path)
    : DBus::Object(path) {
  this->add_interface(_com_jci_navi2IHU_HUDSettingsInterface);

}
std::shared_ptr<com_jci_navi2IHU_HUDSettings_objectAdapter> com_jci_navi2IHU_HUDSettings_objectAdapter::create(std::shared_ptr<
    DBus::Connection> connection,
                                                                                                               std::shared_ptr<
                                                                                                                   com_jci_navi2IHU_HUDSettingsInterface> _com_jci_navi2IHU_HUDSettingsInterface,
                                                                                                               std::string path,
                                                                                                               DBus::ThreadForCalling calling_thread) {
  std::shared_ptr<com_jci_navi2IHU_HUDSettings_objectAdapter> adapter =
      std::shared_ptr<com_jci_navi2IHU_HUDSettings_objectAdapter>(new com_jci_navi2IHU_HUDSettings_objectAdapter(
          _com_jci_navi2IHU_HUDSettingsInterface, path));
  if (connection) {
    if (connection->register_object(adapter, calling_thread) != DBus::RegistrationStatus::Success) {
      return std::shared_ptr<com_jci_navi2IHU_HUDSettings_objectAdapter>();
    }
  }
  return adapter;

}
