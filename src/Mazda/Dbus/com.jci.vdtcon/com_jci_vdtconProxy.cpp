#include "com_jci_vdtconProxy.h"

com_jci_vdtconProxy::com_jci_vdtconProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_SelectMedia = this->create_method<int32_t(int32_t)>("SelectMedia");
  m_method_SelectMedia_Async = this->create_method<int32_t(int32_t)>("SelectMedia_Async");
  m_method_Send = this->create_method<int32_t(std::string, std::string, Invalid)>("Send");
  m_method_Send_Async = this->create_method<int32_t(std::string, std::string, Invalid)>("Send_Async");
  m_method_Delete = this->create_method<int32_t(std::string, std::tuple < int32_t, int32_t > )>("Delete");
  m_method_Delete_Async = this->create_method<int32_t(std::string, std::tuple < int32_t, int32_t > )>("Delete_Async");
  m_signalproxy_MediaStatus = this->create_signal<void(std::tuple < int32_t, int32_t, int32_t > )>("MediaStatus");
  m_signalproxy_TransferRequest = this->create_signal<void(std::string, std::tuple < int32_t > )>("TransferRequest");
  m_signalproxy_DeleteRequest = this->create_signal<void(std::string, std::tuple < int32_t > )>("DeleteRequest");
  m_signalproxy_TransferResult =
      this->create_signal<void(std::string, std::tuple < int32_t, int32_t > )>("TransferResult");
  m_signalproxy_DeleteResult = this->create_signal<void(std::string, std::tuple < int32_t, int32_t > )>("DeleteResult");

}
std::shared_ptr <com_jci_vdtconProxy> com_jci_vdtconProxy::create(std::string name) {
  return std::shared_ptr<com_jci_vdtconProxy>(new com_jci_vdtconProxy(name));

}
int32_t com_jci_vdtconProxy::SelectMedia(int32_t mediaType) {
  return (*m_method_SelectMedia)(mediaType);

}
int32_t com_jci_vdtconProxy::SelectMedia_Async(int32_t mediaType) {
  return (*m_method_SelectMedia_Async)(mediaType);

}
int32_t com_jci_vdtconProxy::Send(std::string srcFileName, std::string destFileName, Invalid sendParams) {
  return (*m_method_Send)(srcFileName, destFileName, sendParams);

}
int32_t com_jci_vdtconProxy::Send_Async(std::string srcFileName, std::string destFileName, Invalid sendParams) {
  return (*m_method_Send_Async)(srcFileName, destFileName, sendParams);

}
int32_t com_jci_vdtconProxy::Delete(std::string fileName, std::tuple <int32_t, int32_t> deleteParams) {
  return (*m_method_Delete)(fileName, deleteParams);

}
int32_t com_jci_vdtconProxy::Delete_Async(std::string fileName, std::tuple <int32_t, int32_t> deleteParams) {
  return (*m_method_Delete_Async)(fileName, deleteParams);

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < int32_t,
                                        int32_t,
                                        int32_t > )>> com_jci_vdtconProxy::signal_MediaStatus() {
  return m_signalproxy_MediaStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::string,
                                        std::tuple < int32_t > )>> com_jci_vdtconProxy::signal_TransferRequest() {
  return m_signalproxy_TransferRequest;

}
std::shared_ptr <DBus::SignalProxy<void(std::string,
                                        std::tuple < int32_t > )>> com_jci_vdtconProxy::signal_DeleteRequest() {
  return m_signalproxy_DeleteRequest;

}
std::shared_ptr <DBus::SignalProxy<void(std::string,
                                        std::tuple < int32_t,
                                        int32_t > )>> com_jci_vdtconProxy::signal_TransferResult() {
  return m_signalproxy_TransferResult;

}
std::shared_ptr <DBus::SignalProxy<void(std::string,
                                        std::tuple < int32_t,
                                        int32_t > )>> com_jci_vdtconProxy::signal_DeleteResult() {
  return m_signalproxy_DeleteResult;

}
