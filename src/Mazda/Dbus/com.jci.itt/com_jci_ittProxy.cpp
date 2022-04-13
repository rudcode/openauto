#include "com_jci_ittProxy.h"

com_jci_ittProxy::com_jci_ittProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_RequestMemoryInfo = this->create_method < std::tuple < std::vector < std::tuple < int32_t, uint32_t,
      std::string >>, uint32_t > () > ("RequestMemoryInfo");
  m_method_ProcessTag = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector < std::tuple
      < int32_t, uint32_t, std::string >>, uint32_t >> () > ("ProcessTag");
  m_method_GetTaggingAvailability = this->create_method<int32_t()>("GetTaggingAvailability");
  m_signalproxy_TaggingAvailable = this->create_signal<void(int32_t)>("TaggingAvailable");
  m_signalproxy_TagTransfer = this->create_signal<void(int32_t,
                                                       std::tuple < std::vector < std::tuple < int32_t,
                                                       uint32_t,
                                                       std::string >> ,
                                                       uint32_t > )>("TagTransfer");
  m_signalproxy_TaggingErrorDevice = this->create_signal<void(int32_t)>("TaggingErrorDevice");

}
std::shared_ptr <com_jci_ittProxy> com_jci_ittProxy::create(std::string name) {
  return std::shared_ptr<com_jci_ittProxy>(new com_jci_ittProxy(name));

}
std::tuple <std::vector<std::tuple < int32_t, uint32_t, std::string>>,uint32_t>
com_jci_ittProxy::RequestMemoryInfo() {
  return (*m_method_RequestMemoryInfo)();

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < std::tuple < int32_t, uint32_t, std::string>>,uint32_t>>
com_jci_ittProxy::ProcessTag() {
  return (*m_method_ProcessTag)();

}
int32_t com_jci_ittProxy::GetTaggingAvailability() {
  return (*m_method_GetTaggingAvailability)();

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_ittProxy::signal_TaggingAvailable() {
  return m_signalproxy_TaggingAvailable;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t,
                                        std::tuple < std::vector < std::tuple < int32_t,
                                        uint32_t,
                                        std::string >> ,
                                        uint32_t > )>> com_jci_ittProxy::signal_TagTransfer() {
  return m_signalproxy_TagTransfer;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_ittProxy::signal_TaggingErrorDevice() {
  return m_signalproxy_TaggingErrorDevice;

}
