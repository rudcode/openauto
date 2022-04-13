#include "com_jci_audioPlayerProxy.h"

com_jci_audioPlayerProxy::com_jci_audioPlayerProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_Open = this->create_method<DBus::MultipleReturn<int32_t, int32_t>()>("Open");
  m_method_OpenByName = this->create_method<DBus::MultipleReturn<int32_t, int32_t>(std::string)>("OpenByName");
  m_method_Close = this->create_method<int32_t(int32_t)>("Close");
  m_method_PlaySync = this->create_method<int32_t(int32_t, std::string, int32_t)>("PlaySync");
  m_method_PlayASync = this->create_method<int32_t(int32_t, std::string, int32_t)>("PlayASync");
  m_method_AbortSync = this->create_method<int32_t(int32_t, std::string, int32_t)>("AbortSync");
  m_method_AbortASync = this->create_method<int32_t(int32_t, std::string, int32_t)>("AbortASync");
  m_signalproxy_Exception = this->create_signal<void(int16_t, std::string)>("Exception");

}
std::shared_ptr <com_jci_audioPlayerProxy> com_jci_audioPlayerProxy::create(std::string name) {
  return std::shared_ptr<com_jci_audioPlayerProxy>(new com_jci_audioPlayerProxy(name));

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_audioPlayerProxy::Open() {
  return (*m_method_Open)();

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_audioPlayerProxy::OpenByName(std::string device) {
  return (*m_method_OpenByName)(device);

}
int32_t com_jci_audioPlayerProxy::Close(int32_t client_id) {
  return (*m_method_Close)(client_id);

}
int32_t com_jci_audioPlayerProxy::PlaySync(int32_t client_id, std::string fileName, int32_t mode) {
  return (*m_method_PlaySync)(client_id, fileName, mode);

}
int32_t com_jci_audioPlayerProxy::PlayASync(int32_t client_id, std::string fileName, int32_t mode) {
  return (*m_method_PlayASync)(client_id, fileName, mode);

}
int32_t com_jci_audioPlayerProxy::AbortSync(int32_t client_id, std::string fileName, int32_t abort_type) {
  return (*m_method_AbortSync)(client_id, fileName, abort_type);

}
int32_t com_jci_audioPlayerProxy::AbortASync(int32_t client_id, std::string fileName, int32_t abort_type) {
  return (*m_method_AbortASync)(client_id, fileName, abort_type);

}
std::shared_ptr <DBus::SignalProxy<void(int16_t, std::string)>> com_jci_audioPlayerProxy::signal_Exception() {
  return m_signalproxy_Exception;

}
