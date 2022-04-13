#include "com_jci_cdrpProxy.h"

com_jci_cdrpProxy::com_jci_cdrpProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_SetConfirmationDialogResult =
      this->create_method<void(uint32_t, std::string, uint32_t)>("SetConfirmationDialogResult");
  m_method_SetDeviceSettings = this->create_method<void(uint32_t, std::string, uint32_t)>("SetDeviceSettings");
  m_method_GetConfirmationDialogRequest = this->create_method<void(uint32_t)>("GetConfirmationDialogRequest");
  m_signalproxy_ConnectedDeviceSignal =
      this->create_signal<void(uint32_t, std::string, uint32_t)>("ConnectedDeviceSignal");
  m_signalproxy_ConfirmationDialogSignal =
      this->create_signal<void(std::string, uint32_t, std::string, uint32_t)>("ConfirmationDialogSignal");
  m_signalproxy_ErrorNotificationSignal = this->create_signal<void(uint32_t)>("ErrorNotificationSignal");

}
std::shared_ptr <com_jci_cdrpProxy> com_jci_cdrpProxy::create(std::string name) {
  return std::shared_ptr<com_jci_cdrpProxy>(new com_jci_cdrpProxy(name));

}
void com_jci_cdrpProxy::SetConfirmationDialogResult(uint32_t index, std::string serialId, uint32_t size) {
  (*m_method_SetConfirmationDialogResult)(index, serialId, size);

}
void com_jci_cdrpProxy::SetDeviceSettings(uint32_t index, std::string serialId, uint32_t size) {
  (*m_method_SetDeviceSettings)(index, serialId, size);

}
void com_jci_cdrpProxy::GetConfirmationDialogRequest(uint32_t index) {
  (*m_method_GetConfirmationDialogRequest)(index);

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::string,
                                        uint32_t)>> com_jci_cdrpProxy::signal_ConnectedDeviceSignal() {
  return m_signalproxy_ConnectedDeviceSignal;

}
std::shared_ptr <DBus::SignalProxy<void(std::string,
                                        uint32_t,
                                        std::string,
                                        uint32_t)>> com_jci_cdrpProxy::signal_ConfirmationDialogSignal() {
  return m_signalproxy_ConfirmationDialogSignal;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_cdrpProxy::signal_ErrorNotificationSignal() {
  return m_signalproxy_ErrorNotificationSignal;

}
