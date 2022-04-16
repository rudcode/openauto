#include "com_jci_vbs_navi_tmc_objectAdapter.h"

com_jci_vbs_navi_tmc_objectAdapter::com_jci_vbs_navi_tmc_objectAdapter(std::shared_ptr<com_jci_vbs_navi_tmcInterface> _com_jci_vbs_navi_tmcInterface,
                                                                       std::string path) : DBus::Object(path) {
  this->add_interface(_com_jci_vbs_navi_tmcInterface);

}
std::shared_ptr<com_jci_vbs_navi_tmc_objectAdapter> com_jci_vbs_navi_tmc_objectAdapter::create(std::shared_ptr<DBus::Connection> connection,
                                                                                               std::shared_ptr<
                                                                                                   com_jci_vbs_navi_tmcInterface> _com_jci_vbs_navi_tmcInterface,
                                                                                               std::string path,
                                                                                               DBus::ThreadForCalling calling_thread) {
  std::shared_ptr<com_jci_vbs_navi_tmc_objectAdapter>
      adapter = std::shared_ptr<com_jci_vbs_navi_tmc_objectAdapter>(new com_jci_vbs_navi_tmc_objectAdapter(
      _com_jci_vbs_navi_tmcInterface, path));
  if (connection) {
    if (connection->register_object(adapter, calling_thread) != DBus::RegistrationStatus::Success) {
      return std::shared_ptr<com_jci_vbs_navi_tmc_objectAdapter>();
    }
  }
  return adapter;

}
