#include "com_jci_CDProxy.h"

com_jci_CDProxy::com_jci_CDProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_SourceChange_Req = this->create_method<int32_t()>("SourceChange_Req");
  m_method_Eject_Req = this->create_method<int32_t()>("Eject_Req");
  m_method_Play_Req = this->create_method<int32_t()>("Play_Req");
  m_method_Pause_Req = this->create_method<int32_t()>("Pause_Req");
  m_method_Previous_Req = this->create_method<int32_t()>("Previous_Req");
  m_method_Next_Req = this->create_method<int32_t()>("Next_Req");
  m_method_SetRepeat_Req = this->create_method<int32_t(uint8_t)>("SetRepeat_Req");
  m_method_SetRandom_Req = this->create_method<int32_t(uint8_t)>("SetRandom_Req");
  m_method_Scan_Req = this->create_method<int32_t()>("Scan_Req");
  m_method_FastForward_Req = this->create_method<int32_t()>("FastForward_Req");
  m_method_FastRewind_Req = this->create_method<int32_t()>("FastRewind_Req");
  m_method_GetCDReadyStatus_Req = this->create_method<DBus::MultipleReturn<uint8_t, int32_t>()>("GetCDReadyStatus_Req");
  m_method_GetCDStatus_Req = this->create_method<std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>()>("GetCDStatus_Req");
  m_method_Get_Availability_Req = this->create_method<DBus::MultipleReturn<uint8_t, int32_t>()>("Get_Availability_Req");
  m_method_UserSelection_Req = this->create_method<std::tuple<uint8_t, std::string, uint8_t, bool, bool>(uint8_t,
                                                                                                         uint16_t)>(
      "UserSelection_Req");
  m_method_UserSelection_VR_Req =
      this->create_method<std::tuple<uint8_t, std::string, uint8_t, bool, bool>(uint8_t, uint16_t)>(
          "UserSelection_VR_Req");
  m_method_GetFolderContents_Req = this->create_method < DBus::MultipleReturn < std::tuple < std::vector < std::tuple
      < uint16_t, uint8_t, std::string>>>,int16_t, int16_t > (uint16_t, uint16_t) > ("GetFolderContents_Req");
  m_signalproxy_Status = this->create_signal<void(std::tuple < uint8_t, uint8_t, uint8_t, uint8_t > )>("Status");
  m_signalproxy_Ready_Status = this->create_signal<void(uint8_t)>("Ready_Status");
  m_signalproxy_Repeat_Settings_Status = this->create_signal<void(uint8_t)>("Repeat_Settings_Status");
  m_signalproxy_Random_Settings_Status = this->create_signal<void(uint8_t)>("Random_Settings_Status");
  m_signalproxy_Track_Play_Status =
      this->create_signal<void(std::tuple < uint16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t > )>(
          "Track_Play_Status");
  m_signalproxy_Metadata_Response = this->create_signal<void(std::tuple < std::string,
                                                             std::string,
                                                             std::string,
                                                             std::string,
                                                             std::string,
                                                             std::string > )>("Metadata_Response");
  m_signalproxy_SourceChange_Response = this->create_signal<void(uint8_t)>("SourceChange_Response");
  m_signalproxy_RoutineTest_Response = this->create_signal<void(uint8_t)>("RoutineTest_Response");
  m_signalproxy_Total_Track_Number = this->create_signal<void(uint16_t)>("Total_Track_Number");

}
std::shared_ptr <com_jci_CDProxy> com_jci_CDProxy::create(std::string name) {
  return std::shared_ptr<com_jci_CDProxy>(new com_jci_CDProxy(name));

}
int32_t com_jci_CDProxy::SourceChange_Req() {
  return (*m_method_SourceChange_Req)();

}
int32_t com_jci_CDProxy::Eject_Req() {
  return (*m_method_Eject_Req)();

}
int32_t com_jci_CDProxy::Play_Req() {
  return (*m_method_Play_Req)();

}
int32_t com_jci_CDProxy::Pause_Req() {
  return (*m_method_Pause_Req)();

}
int32_t com_jci_CDProxy::Previous_Req() {
  return (*m_method_Previous_Req)();

}
int32_t com_jci_CDProxy::Next_Req() {
  return (*m_method_Next_Req)();

}
int32_t com_jci_CDProxy::SetRepeat_Req(uint8_t repeat) {
  return (*m_method_SetRepeat_Req)(repeat);

}
int32_t com_jci_CDProxy::SetRandom_Req(uint8_t random) {
  return (*m_method_SetRandom_Req)(random);

}
int32_t com_jci_CDProxy::Scan_Req() {
  return (*m_method_Scan_Req)();

}
int32_t com_jci_CDProxy::FastForward_Req() {
  return (*m_method_FastForward_Req)();

}
int32_t com_jci_CDProxy::FastRewind_Req() {
  return (*m_method_FastRewind_Req)();

}
DBus::MultipleReturn <uint8_t, int32_t> com_jci_CDProxy::GetCDReadyStatus_Req() {
  return (*m_method_GetCDReadyStatus_Req)();

}
std::tuple <uint8_t, uint8_t, uint8_t, uint8_t> com_jci_CDProxy::GetCDStatus_Req() {
  return (*m_method_GetCDStatus_Req)();

}
DBus::MultipleReturn <uint8_t, int32_t> com_jci_CDProxy::Get_Availability_Req() {
  return (*m_method_Get_Availability_Req)();

}
std::tuple<uint8_t, std::string, uint8_t, bool, bool> com_jci_CDProxy::UserSelection_Req(uint8_t itemType,
                                                                                         uint16_t index) {
  return (*m_method_UserSelection_Req)(itemType, index);

}
std::tuple<uint8_t, std::string, uint8_t, bool, bool> com_jci_CDProxy::UserSelection_VR_Req(uint8_t itemType,
                                                                                            uint16_t index) {
  return (*m_method_UserSelection_VR_Req)(itemType, index);

}
DBus::MultipleReturn <std::tuple<std::vector < std::tuple < uint16_t, uint8_t, std::string>>>,int16_t,int16_t>
com_jci_CDProxy::GetFolderContents_Req(uint16_t
index,
uint16_t itemsCount
){
return (*m_method_GetFolderContents_Req)(index,itemsCount);

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t > )>> com_jci_CDProxy::signal_Status() {
  return m_signalproxy_Status;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_CDProxy::signal_Ready_Status() {
  return m_signalproxy_Ready_Status;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_CDProxy::signal_Repeat_Settings_Status() {
  return m_signalproxy_Repeat_Settings_Status;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_CDProxy::signal_Random_Settings_Status() {
  return m_signalproxy_Random_Settings_Status;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint16_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t > )>> com_jci_CDProxy::signal_Track_Play_Status() {
  return m_signalproxy_Track_Play_Status;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < std::string,
                                        std::string,
                                        std::string,
                                        std::string,
                                        std::string,
                                        std::string > )>> com_jci_CDProxy::signal_Metadata_Response() {
  return m_signalproxy_Metadata_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_CDProxy::signal_SourceChange_Response() {
  return m_signalproxy_SourceChange_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t)>> com_jci_CDProxy::signal_RoutineTest_Response() {
  return m_signalproxy_RoutineTest_Response;

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t)>> com_jci_CDProxy::signal_Total_Track_Number() {
  return m_signalproxy_Total_Track_Number;

}
