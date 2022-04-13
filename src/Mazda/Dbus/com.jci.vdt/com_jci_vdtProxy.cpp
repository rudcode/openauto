#include "com_jci_vdtProxy.h"

com_jci_vdtProxy::com_jci_vdtProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_MMUI_Startup_Initiated = this->create_method<int32_t(bool)>("MMUI_Startup_Initiated");
  m_method_DriveLogRecordingStatus = this->create_method<int32_t(uint32_t)>("DriveLogRecordingStatus");
  m_method_One_HrLog_File_Protect_Delete =
      this->create_method<void(std::tuple < uint8_t, uint8_t > )>("One_HrLog_File_Protect_Delete");
  m_method_File_List_Req = this->create_method<void()>("File_List_Req");
  m_method_DiagnosticsMode_Request = this->create_method<int32_t(uint16_t)>("DiagnosticsMode_Request");
  m_method_UserMode_Setting = this->create_method<int32_t(uint16_t, bool)>("UserMode_Setting");
  m_method_UserMode_Request = this->create_method<int32_t(uint16_t)>("UserMode_Request");
  m_method_PIN_Request = this->create_method<int32_t(uint16_t, uint16_t)>("PIN_Request");
  m_method_Screen_Req = this->create_method<int32_t(uint32_t)>("Screen_Req");
  m_signalproxy_Drv_File_List = this->create_signal < void(std::tuple < uint8_t,
                                                           std::vector < std::tuple < std::string,
                                                           uint8_t,
                                                           uint32_t,
                                                           bool>>>)>("Drv_File_List");
  m_signalproxy_UMASS_Device_Status = this->create_signal<void(uint16_t)>("UMASS_Device_Status");
  m_signalproxy_MD_Device_Status = this->create_signal<void(uint16_t, bool)>("MD_Device_Status");
  m_signalproxy_ClearDataStatus = this->create_signal<void(uint16_t)>("ClearDataStatus");
  m_signalproxy_UmassTransferProgress = this->create_signal<void(uint16_t, uint16_t)>("UmassTransferProgress");
  m_signalproxy_ActivateDeactivateRecordingStatus =
      this->create_signal<void(uint32_t)>("ActivateDeactivateRecordingStatus");
  m_signalproxy_Send_Pin_Validation_Result = this->create_signal<void(bool)>("Send_Pin_Validation_Result");
  m_signalproxy_Send_Pin_Updation_Result = this->create_signal<void(bool, uint16_t)>("Send_Pin_Updation_Result");
  m_signalproxy_Send_EOLConfig_Status = this->create_signal<void(uint16_t, bool)>("Send_EOLConfig_Status");
  m_signalproxy_Send_HVD_Setting = this->create_signal<void(uint16_t, bool)>("Send_HVD_Setting");
  m_signalproxy_Delete_DriveRecord_DataStatus = this->create_signal<void(uint16_t)>("Delete_DriveRecord_DataStatus");

}
std::shared_ptr <com_jci_vdtProxy> com_jci_vdtProxy::create(std::string name) {
  return std::shared_ptr<com_jci_vdtProxy>(new com_jci_vdtProxy(name));

}
int32_t com_jci_vdtProxy::MMUI_Startup_Initiated(bool vdt_mmui_init) {
  return (*m_method_MMUI_Startup_Initiated)(vdt_mmui_init);

}
int32_t com_jci_vdtProxy::DriveLogRecordingStatus(uint32_t record_status) {
  return (*m_method_DriveLogRecordingStatus)(record_status);

}
void com_jci_vdtProxy::One_HrLog_File_Protect_Delete(std::tuple <uint8_t, uint8_t> one_hrlog_info) {
  (*m_method_One_HrLog_File_Protect_Delete)(one_hrlog_info);

}
void com_jci_vdtProxy::File_List_Req() {
  (*m_method_File_List_Req)();

}
int32_t com_jci_vdtProxy::DiagnosticsMode_Request(uint16_t testscreen_ID) {
  return (*m_method_DiagnosticsMode_Request)(testscreen_ID);

}
int32_t com_jci_vdtProxy::UserMode_Setting(uint16_t setting_type, bool value) {
  return (*m_method_UserMode_Setting)(setting_type, value);

}
int32_t com_jci_vdtProxy::UserMode_Request(uint16_t request_type) {
  return (*m_method_UserMode_Request)(request_type);

}
int32_t com_jci_vdtProxy::PIN_Request(uint16_t pin_req_type, uint16_t value) {
  return (*m_method_PIN_Request)(pin_req_type, value);

}
int32_t com_jci_vdtProxy::Screen_Req(uint32_t vDTScreen) {
  return (*m_method_Screen_Req)(vDTScreen);

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        std::vector < std::tuple < std::string,
                                        uint8_t,
                                        uint32_t,
                                        bool>>>)>>
com_jci_vdtProxy::signal_Drv_File_List() {
  return m_signalproxy_Drv_File_List;

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t)>> com_jci_vdtProxy::signal_UMASS_Device_Status() {
  return m_signalproxy_UMASS_Device_Status;

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t, bool)>> com_jci_vdtProxy::signal_MD_Device_Status() {
  return m_signalproxy_MD_Device_Status;

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t)>> com_jci_vdtProxy::signal_ClearDataStatus() {
  return m_signalproxy_ClearDataStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t, uint16_t)>> com_jci_vdtProxy::signal_UmassTransferProgress() {
  return m_signalproxy_UmassTransferProgress;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_vdtProxy::signal_ActivateDeactivateRecordingStatus() {
  return m_signalproxy_ActivateDeactivateRecordingStatus;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_vdtProxy::signal_Send_Pin_Validation_Result() {
  return m_signalproxy_Send_Pin_Validation_Result;

}
std::shared_ptr <DBus::SignalProxy<void(bool, uint16_t)>> com_jci_vdtProxy::signal_Send_Pin_Updation_Result() {
  return m_signalproxy_Send_Pin_Updation_Result;

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t, bool)>> com_jci_vdtProxy::signal_Send_EOLConfig_Status() {
  return m_signalproxy_Send_EOLConfig_Status;

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t, bool)>> com_jci_vdtProxy::signal_Send_HVD_Setting() {
  return m_signalproxy_Send_HVD_Setting;

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t)>> com_jci_vdtProxy::signal_Delete_DriveRecord_DataStatus() {
  return m_signalproxy_Delete_DriveRecord_DataStatus;

}
