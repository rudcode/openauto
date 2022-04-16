#include "com_jci_lds_controlInterface.h"

com_jci_lds_controlInterface::com_jci_lds_controlInterface(com_jci_lds_control *adaptee, std::string name)
    : DBus::Interface(name) {
  this->create_method<void(int32_t)>("ReadControl", sigc::mem_fun(*adaptee, &com_jci_lds_control::ReadControl));
  this->create_method<void(int32_t)>("DRTestScreenRequest",
                                     sigc::mem_fun(*adaptee, &com_jci_lds_control::DRTestScreenRequest));
  this->create_method<DBus::MultipleReturn<bool, bool, int32_t>()>("GetDRUnitStatus_sync",
                                                                   sigc::mem_fun(*adaptee,
                                                                                 &com_jci_lds_control::GetDRUnitStatus_sync));
  this->create_method<DBus::MultipleReturn<int32_t,
                                           uint64_t,
                                           double,
                                           double,
                                           int32_t,
                                           double,
                                           double,
                                           double,
                                           double,
                                           int32_t>()>("GetLastKnownPosition_sync",
                                                       sigc::mem_fun(*adaptee,
                                                                     &com_jci_lds_control::GetLastKnownPosition_sync));
  this->create_method<int32_t(int32_t, uint64_t, double, double, int32_t, double, double, double, double)>(
      "SetLastKnownPosition_sync",
      sigc::mem_fun(*adaptee, &com_jci_lds_control::SetLastKnownPosition_sync));
  this->create_method<void()>("DRReloadRequest", sigc::mem_fun(*adaptee, &com_jci_lds_control::DRReloadRequest));
  m_signal_ReadStatus = create_signal<void(int32_t, int32_t)>("ReadStatus");

}
std::shared_ptr<com_jci_lds_controlInterface> com_jci_lds_controlInterface::create(com_jci_lds_control *adaptee,
                                                                                   std::string name) {
  return std::shared_ptr<com_jci_lds_controlInterface>(new com_jci_lds_controlInterface(adaptee, name));

}
std::shared_ptr<DBus::Signal<void(int32_t, int32_t)>> com_jci_lds_controlInterface::signal_ReadStatus() {
  return m_signal_ReadStatus;

}
void com_jci_lds_controlInterface::ReadStatus(int32_t commandReply, int32_t status) {
  (*m_signal_ReadStatus)(commandReply, status);

}
