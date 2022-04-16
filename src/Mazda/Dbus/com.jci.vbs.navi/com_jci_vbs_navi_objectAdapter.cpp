#include "com_jci_vbs_navi_objectAdapter.h"

com_jci_vbs_navi_objectAdapter::com_jci_vbs_navi_objectAdapter(std::shared_ptr<com_jci_vbs_naviInterface> _com_jci_vbs_naviInterface,
                                                               std::string path) : DBus::Object(path) {
  this->add_interface(_com_jci_vbs_naviInterface);

}
std::shared_ptr<com_jci_vbs_navi_objectAdapter> com_jci_vbs_navi_objectAdapter::create(std::shared_ptr<DBus::Connection> connection,
                                                                                       std::shared_ptr<
                                                                                           com_jci_vbs_naviInterface> _com_jci_vbs_naviInterface,
                                                                                       std::string path,
                                                                                       DBus::ThreadForCalling calling_thread) {
  std::shared_ptr<com_jci_vbs_navi_objectAdapter>
      adapter = std::shared_ptr<com_jci_vbs_navi_objectAdapter>(new com_jci_vbs_navi_objectAdapter(
      _com_jci_vbs_naviInterface, path));
  if (connection) {
    if (connection->register_object(adapter, calling_thread) != DBus::RegistrationStatus::Success) {
      return std::shared_ptr<com_jci_vbs_navi_objectAdapter>();
    }
  }
  return adapter;

}
