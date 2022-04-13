#include "com_jci_blm_msg_InterfaceProxy.h"

com_jci_blm_msg_InterfaceProxy::com_jci_blm_msg_InterfaceProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_Connect = this->create_method<DBus::MultipleReturn<uint32_t, int32_t, uint32_t, int32_t, uint32_t>(uint32_t,
                                                                                                              int32_t,
                                                                                                              uint32_t)>(
      "Connect");
  m_method_Disconnect =
      this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t, uint32_t)>("Disconnect");
  m_method_GetInstanceList = this->create_method < DBus::MultipleReturn < uint32_t, uint32_t, int32_t, std::tuple
      < uint32_t, std::vector < std::tuple < uint16_t, std::string >> >> (uint32_t, uint32_t) > ("GetInstanceList");
  m_method_GetMessageList = this->create_method < DBus::MultipleReturn < uint32_t, uint32_t, int32_t, std::tuple
      < bool, bool, bool, uint32_t, uint32_t, std::vector < std::tuple
      < int32_t, uint64_t, int32_t, uint32_t, std::string, std::string, std::string >>
                                                                                    >> (uint32_t, uint32_t, std::tuple
                                                                                        < uint16_t, std::tuple
                                                                                        < uint32_t, uint32_t, std::tuple
                                                                                        < uint32_t, std::vector
                                                                                        < std::tuple
                                                                                        < int32_t, uint32_t, std::string
                                                                                        >>>>>,int32_t)>("GetMessageList");
  m_method_GetNewMessagesList = this->create_method < DBus::MultipleReturn < uint32_t, uint32_t, int32_t, std::tuple
      < uint32_t, std::vector < std::tuple < int32_t, uint64_t, int32_t, uint32_t, std::string, std::string,
      std::string >> >> (uint32_t, uint32_t, int32_t) > ("GetNewMessagesList");
  m_method_GetNewMessagesInfo = this->create_method < DBus::MultipleReturn < uint32_t, uint32_t, int32_t, std::tuple
      < std::tuple < uint32_t, std::vector < std::tuple < int32_t, uint32_t, bool >>>>>(uint32_t, uint32_t)
      > ("GetNewMessagesInfo");
  m_method_GetMessage =
      this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t, Invalid>(uint32_t, uint32_t, uint64_t)>(
          "GetMessage");
  m_method_SetMessageStatus =
      this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t, uint32_t, uint64_t, int32_t)>(
          "SetMessageStatus");
  m_method_DeleteMessage =
      this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t, uint64_t>(uint32_t, uint32_t, uint64_t)>(
          "DeleteMessage");
  m_method_DeleteSavedMessage =
      this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t, uint32_t)>("DeleteSavedMessage");
  m_method_GetOutgoingMessage = this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t, Invalid>(uint32_t,
                                                                                                               uint32_t,
                                                                                                               uint64_t,
                                                                                                               int32_t)>(
      "GetOutgoingMessage");
  m_method_GetSavedMessage =
      this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t, Invalid>(uint32_t, uint32_t)>(
          "GetSavedMessage");
  m_method_SendMessage = this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t,
                                                                                               uint32_t,
                                                                                               Invalid)>("SendMessage");
  m_method_SaveMessage = this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t,
                                                                                               uint32_t,
                                                                                               Invalid)>("SaveMessage");
  m_method_GetAutoDownload = this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t, int32_t, bool>(
      uint32_t,
      uint32_t,
      int32_t,
      int32_t)>("GetAutoDownload");
  m_method_SetAutoDownload = this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t, int32_t>(uint32_t,
                                                                                                            uint32_t,
                                                                                                            int32_t,
                                                                                                            bool)>(
      "SetAutoDownload");
  m_method_GetNotify = this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t, int32_t, bool>(uint32_t,
                                                                                                            uint32_t,
                                                                                                            int32_t,
                                                                                                            int32_t)>(
      "GetNotify");
  m_method_SetNotify = this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t, int32_t>(uint32_t,
                                                                                                      uint32_t,
                                                                                                      int32_t,
                                                                                                      bool)>("SetNotify");
  m_method_StartMessagePlayback =
      this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t, uint32_t, uint64_t)>(
          "StartMessagePlayback");
  m_method_StartOutgoingMessagePlayback =
      this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t, uint32_t, Invalid)>(
          "StartOutgoingMessagePlayback");
  m_method_PauseMessagePlayback = this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t,
                                                                                                        uint32_t)>(
      "PauseMessagePlayback");
  m_method_ResumeMessagePlayback = this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t,
                                                                                                         uint32_t)>(
      "ResumeMessagePlayback");
  m_method_StopMessagePlayback =
      this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t, uint32_t)>("StopMessagePlayback");
  m_method_CancelPendingMessagePlayback =
      this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t, uint32_t)>(
          "CancelPendingMessagePlayback");
  m_method_AddPresetMessage =
      this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t, uint32_t, std::string, uint32_t)>(
          "AddPresetMessage");
  m_method_DeletePresetMessage =
      this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t, uint32_t, uint32_t, uint32_t)>(
          "DeletePresetMessage");
  m_method_MovePresetMessage = this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t,
                                                                                                     uint32_t,
                                                                                                     uint32_t,
                                                                                                     uint32_t,
                                                                                                     uint32_t)>(
      "MovePresetMessage");
  m_method_EditPresetMessage = this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t,
                                                                                                     uint32_t,
                                                                                                     uint32_t,
                                                                                                     std::string,
                                                                                                     uint32_t)>(
      "EditPresetMessage");
  m_method_GetPresetMessageList = this->create_method < DBus::MultipleReturn < uint32_t, uint32_t, int32_t, std::tuple
      < uint32_t, std::vector < std::string>>>(uint32_t, uint32_t, uint32_t) > ("GetPresetMessageList");
  m_method_ApplySettings =
      this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t, uint32_t)>("ApplySettings");
  m_method_ResetSettings =
      this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, int32_t, uint32_t>(uint32_t, uint32_t, uint32_t)>(
          "ResetSettings");
  m_signalproxy_AutoDownloadChanged = this->create_signal<void(int32_t, bool)>("AutoDownloadChanged");
  m_signalproxy_NotifyChanged = this->create_signal<void(int32_t, bool)>("NotifyChanged");
  m_signalproxy_PresetMessageListChanged = this->create_signal<void()>("PresetMessageListChanged");
  m_signalproxy_NewMessage =
      this->create_signal<void(uint32_t, std::tuple < int32_t, uint64_t, std::string, std::string > )>("NewMessage");
  m_signalproxy_NewMessagesInfo = this->create_signal<void(uint32_t,
                                                           std::tuple < std::tuple < uint32_t,
                                                           std::vector < std::tuple < int32_t,
                                                           uint32_t,
                                                           bool >> >> )>("NewMessagesInfo");
  m_signalproxy_Notification = this->create_signal<void(uint32_t, int32_t)>("Notification");
  m_signalproxy_DownloadCompleted = this->create_signal < void(uint32_t,
                                                               int32_t,
                                                               std::tuple < bool,
                                                               bool,
                                                               bool,
                                                               uint32_t,
                                                               uint32_t,
                                                               std::vector < std::tuple < int32_t,
                                                               uint64_t,
                                                               int32_t,
                                                               uint32_t,
                                                               std::string,
                                                               std::string,
                                                               std::string>>>)>("DownloadCompleted");
  m_signalproxy_MessagePlaybackStatusChanged =
      this->create_signal<void(uint32_t, int32_t, uint64_t)>("MessagePlaybackStatusChanged");
  m_signalproxy_InstancesDisconnected = this->create_signal < void(uint32_t,
                                                                   std::tuple < uint32_t,
                                                                   std::vector < std::tuple < uint16_t,
                                                                   std::string>>>)>("InstancesDisconnected");

}
std::shared_ptr <com_jci_blm_msg_InterfaceProxy> com_jci_blm_msg_InterfaceProxy::create(std::string name) {
  return std::shared_ptr<com_jci_blm_msg_InterfaceProxy>(new com_jci_blm_msg_InterfaceProxy(name));

}
DBus::MultipleReturn <uint32_t, int32_t, uint32_t, int32_t, uint32_t> com_jci_blm_msg_InterfaceProxy::Connect(uint32_t context_in,
                                                                                                              int32_t client_type_in,
                                                                                                              uint32_t callbacks_in) {
  return (*m_method_Connect)(context_in, client_type_in, callbacks_in);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t> com_jci_blm_msg_InterfaceProxy::Disconnect(uint32_t context_in,
                                                                                              uint32_t connection_in) {
  return (*m_method_Disconnect)(context_in, connection_in);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t, std::tuple<uint32_t,
                                                              std::vector < std::tuple < uint16_t,
                                                              std::string>>>>
com_jci_blm_msg_InterfaceProxy::GetInstanceList(uint32_t
connection_in,
uint32_t context_in
){
return (*m_method_GetInstanceList)(connection_in,context_in);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t, std::tuple<bool,
                                                              bool,
                                                              bool,
                                                              uint32_t,
                                                              uint32_t,
                                                              std::vector < std::tuple < int32_t,
                                                              uint64_t,
                                                              int32_t,
                                                              uint32_t,
                                                              std::string,
                                                              std::string,
                                                              std::string>>>>
com_jci_blm_msg_InterfaceProxy::GetMessageList(uint32_t
connection_in,
uint32_t context_in, std::tuple<uint16_t,
                                std::tuple < uint32_t,
                                uint32_t,
                                std::tuple < uint32_t,
                                std::vector < std::tuple < int32_t,
                                uint32_t,
                                std::string>>
>>> filter,
int32_t request_type
){
return (*m_method_GetMessageList)(connection_in,context_in,filter,request_type);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t, std::tuple<uint32_t,
                                                              std::vector < std::tuple < int32_t,
                                                              uint64_t,
                                                              int32_t,
                                                              uint32_t,
                                                              std::string,
                                                              std::string,
                                                              std::string>>>>
com_jci_blm_msg_InterfaceProxy::GetNewMessagesList(uint32_t
connection_in,
uint32_t context_in, int32_t
request_type ){
return (*m_method_GetNewMessagesList)(connection_in,context_in,request_type);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t, std::tuple<std::tuple < uint32_t,
                                                              std::vector < std::tuple < int32_t,
                                                              uint32_t,
                                                              bool>>>>>
com_jci_blm_msg_InterfaceProxy::GetNewMessagesInfo(uint32_t
connection_in,
uint32_t context_in
){
return (*m_method_GetNewMessagesInfo)(connection_in,context_in);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t, Invalid> com_jci_blm_msg_InterfaceProxy::GetMessage(uint32_t
connection_in,
uint32_t context_in, uint64_t
message_id ){
return (*m_method_GetMessage)(connection_in,context_in,message_id);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t> com_jci_blm_msg_InterfaceProxy::SetMessageStatus(uint32_t
connection_in,
uint32_t context_in, uint64_t
message_id,
int32_t message_status
){
return (*m_method_SetMessageStatus)(connection_in,context_in,message_id,message_status);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t, uint64_t> com_jci_blm_msg_InterfaceProxy::DeleteMessage(uint32_t
connection_in,
uint32_t context_in, uint64_t
message_id_in ){
return (*m_method_DeleteMessage)(connection_in,context_in,message_id_in);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t> com_jci_blm_msg_InterfaceProxy::DeleteSavedMessage(uint32_t
connection_in,
uint32_t context_in
){
return (*m_method_DeleteSavedMessage)(connection_in,context_in);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t, Invalid> com_jci_blm_msg_InterfaceProxy::GetOutgoingMessage(uint32_t
connection_in,
uint32_t context_in, uint64_t
message_id,
int32_t send_type
){
return (*m_method_GetOutgoingMessage)(connection_in,context_in,message_id,send_type);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t, Invalid> com_jci_blm_msg_InterfaceProxy::GetSavedMessage(uint32_t
connection_in,
uint32_t context_in
){
return (*m_method_GetSavedMessage)(connection_in,context_in);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t> com_jci_blm_msg_InterfaceProxy::SendMessage(uint32_t
connection_in,
uint32_t context_in, Invalid
message ){
return (*m_method_SendMessage)(connection_in,context_in,message);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t> com_jci_blm_msg_InterfaceProxy::SaveMessage(uint32_t
connection_in,
uint32_t context_in, Invalid
message ){
return (*m_method_SaveMessage)(connection_in,context_in,message);

}
DBus::MultipleReturn<uint32_t, uint32_t, int32_t, int32_t, bool>
    com_jci_blm_msg_InterfaceProxy::GetAutoDownload(uint32_t
connection_in,
uint32_t context_in, int32_t
client_type_in,
int32_t type
){
return (*m_method_GetAutoDownload)(connection_in,context_in,client_type_in,type);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t, int32_t> com_jci_blm_msg_InterfaceProxy::SetAutoDownload(uint32_t
connection_in,
uint32_t context_in, int32_t
client_type_in,
bool enabled
){
return (*m_method_SetAutoDownload)(connection_in,context_in,client_type_in,enabled);

}
DBus::MultipleReturn<uint32_t, uint32_t, int32_t, int32_t, bool> com_jci_blm_msg_InterfaceProxy::GetNotify(uint32_t
connection_in,
uint32_t context_in, int32_t
client_type_in,
int32_t type
){
return (*m_method_GetNotify)(connection_in,context_in,client_type_in,type);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t, int32_t> com_jci_blm_msg_InterfaceProxy::SetNotify(uint32_t
connection_in,
uint32_t context_in, int32_t
client_type_in,
bool enabled
){
return (*m_method_SetNotify)(connection_in,context_in,client_type_in,enabled);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t> com_jci_blm_msg_InterfaceProxy::StartMessagePlayback(uint32_t
connection_in,
uint32_t context_in, uint64_t
message_id ){
return (*m_method_StartMessagePlayback)(connection_in,context_in,message_id);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t> com_jci_blm_msg_InterfaceProxy::StartOutgoingMessagePlayback(uint32_t
connection_in,
uint32_t context_in, Invalid
message ){
return (*m_method_StartOutgoingMessagePlayback)(connection_in,context_in,message);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t> com_jci_blm_msg_InterfaceProxy::PauseMessagePlayback(uint32_t
connection_in,
uint32_t context_in
){
return (*m_method_PauseMessagePlayback)(connection_in,context_in);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t> com_jci_blm_msg_InterfaceProxy::ResumeMessagePlayback(uint32_t
connection_in,
uint32_t context_in
){
return (*m_method_ResumeMessagePlayback)(connection_in,context_in);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t> com_jci_blm_msg_InterfaceProxy::StopMessagePlayback(uint32_t
connection_in,
uint32_t context_in
){
return (*m_method_StopMessagePlayback)(connection_in,context_in);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t> com_jci_blm_msg_InterfaceProxy::CancelPendingMessagePlayback(uint32_t
connection_in,
uint32_t context_in
){
return (*m_method_CancelPendingMessagePlayback)(connection_in,context_in);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t> com_jci_blm_msg_InterfaceProxy::AddPresetMessage(uint32_t
connection_in,
uint32_t context_in, std::string
message,
uint32_t type
){
return (*m_method_AddPresetMessage)(connection_in,context_in,message,type);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t> com_jci_blm_msg_InterfaceProxy::DeletePresetMessage(uint32_t
connection_in,
uint32_t context_in, uint32_t
message_id,
uint32_t type
){
return (*m_method_DeletePresetMessage)(connection_in,context_in,message_id,type);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t> com_jci_blm_msg_InterfaceProxy::MovePresetMessage(uint32_t
connection_in,
uint32_t context_in, uint32_t
message_id_from,
uint32_t message_id_to, uint32_t
type ){
return (*m_method_MovePresetMessage)(connection_in,context_in,message_id_from,message_id_to,type);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t> com_jci_blm_msg_InterfaceProxy::EditPresetMessage(uint32_t
connection_in,
uint32_t context_in, uint32_t
message_id,
std::string message, uint32_t
type ){
return (*m_method_EditPresetMessage)(connection_in,context_in,message_id,message,type);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t, std::tuple<uint32_t, std::vector < std::string>>>
com_jci_blm_msg_InterfaceProxy::GetPresetMessageList(uint32_t
connection_in,
uint32_t context_in, uint32_t
type ){
return (*m_method_GetPresetMessageList)(connection_in,context_in,type);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t> com_jci_blm_msg_InterfaceProxy::ApplySettings(uint32_t
connection_in,
uint32_t context_in
){
return (*m_method_ApplySettings)(connection_in,context_in);

}
DBus::MultipleReturn <uint32_t, uint32_t, int32_t, uint32_t> com_jci_blm_msg_InterfaceProxy::ResetSettings(uint32_t
connection_in,
uint32_t context_in, uint32_t
settings_in ){
return (*m_method_ResetSettings)(connection_in,context_in,settings_in);

}
std::shared_ptr <DBus::SignalProxy<void(int32_t, bool)>> com_jci_blm_msg_InterfaceProxy::signal_AutoDownloadChanged() {
  return m_signalproxy_AutoDownloadChanged;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t, bool)>> com_jci_blm_msg_InterfaceProxy::signal_NotifyChanged() {
  return m_signalproxy_NotifyChanged;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_blm_msg_InterfaceProxy::signal_PresetMessageListChanged() {
  return m_signalproxy_PresetMessageListChanged;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < int32_t,
                                        uint64_t,
                                        std::string,
                                        std::string > )>> com_jci_blm_msg_InterfaceProxy::signal_NewMessage() {
  return m_signalproxy_NewMessage;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::tuple < uint32_t,
                                        std::vector < std::tuple < int32_t,
                                        uint32_t,
                                        bool >> >> )>> com_jci_blm_msg_InterfaceProxy::signal_NewMessagesInfo() {
  return m_signalproxy_NewMessagesInfo;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, int32_t)>> com_jci_blm_msg_InterfaceProxy::signal_Notification() {
  return m_signalproxy_Notification;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        int32_t,
                                        std::tuple < bool,
                                        bool,
                                        bool,
                                        uint32_t,
                                        uint32_t,
                                        std::vector < std::tuple < int32_t,
                                        uint64_t,
                                        int32_t,
                                        uint32_t,
                                        std::string,
                                        std::string,
                                        std::string>>>)>>
com_jci_blm_msg_InterfaceProxy::signal_DownloadCompleted() {
  return m_signalproxy_DownloadCompleted;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        int32_t,
                                        uint64_t)>> com_jci_blm_msg_InterfaceProxy::signal_MessagePlaybackStatusChanged() {
  return m_signalproxy_MessagePlaybackStatusChanged;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < uint32_t,
                                        std::vector < std::tuple < uint16_t,
                                        std::string>>>)>>
com_jci_blm_msg_InterfaceProxy::signal_InstancesDisconnected() {
  return m_signalproxy_InstancesDisconnected;

}
