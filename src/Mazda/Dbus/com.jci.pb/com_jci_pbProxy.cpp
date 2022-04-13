#include "com_jci_pbProxy.h"

com_jci_pbProxy::com_jci_pbProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_Import =
      this->create_method<DBus::MultipleReturn<uint32_t, int32_t>(uint32_t, int32_t, uint32_t, uint32_t)>("Import");
  m_method_AutoDownloadSetting =
      this->create_method<DBus::MultipleReturn<int32_t, bool>(uint32_t, int32_t, int32_t)>("AutoDownloadSetting");
  m_method_ContactNameOrderSetting =
      this->create_method<DBus::MultipleReturn<int32_t, int32_t>(int32_t)>("ContactNameOrderSetting");
  m_method_AllSettingsToFactoryDefault = this->create_method<int32_t()>("AllSettingsToFactoryDefault");
  m_method_GetStringVoiced = this->create_method<int32_t(int32_t, std::string)>("GetStringVoiced");
  m_method_StopStringVoiced = this->create_method<int32_t(int32_t)>("StopStringVoiced");
  m_method_TalkEvent = this->create_method<int32_t(int32_t)>("TalkEvent");
  m_method_RecentMissedCallsCounterGet =
      this->create_method<DBus::MultipleReturn<int32_t, uint32_t>(uint32_t)>("RecentMissedCallsCounterGet");
  m_method_RecentMissedCallsCounterReset = this->create_method<int32_t(uint32_t)>("RecentMissedCallsCounterReset");
  m_method_Debug = this->create_method<std::string(bool, bool, std::string, std::string, bool, int32_t)>("Debug");
  m_method_ContactDelete = this->create_method<int32_t(uint32_t, uint32_t, std::string)>("ContactDelete");
  m_method_CallHistoryDelete = this->create_method<int32_t(int32_t)>("CallHistoryDelete");
  m_method_DeletePhonebookData =
      this->create_method<int32_t(uint32_t, int32_t, uint32_t, uint32_t, std::string)>("DeletePhonebookData");
  m_method_GetPhonebookDatabaseInfo = this->create_method<int32_t(int32_t, uint32_t)>("GetPhonebookDatabaseInfo");
  m_signalproxy_AutoDownloadSettingChanged =
      this->create_signal<void(uint32_t, int32_t, bool)>("AutoDownloadSettingChanged");
  m_signalproxy_ContactNameOrderSettingChanged = this->create_signal<void(int32_t)>("ContactNameOrderSettingChanged");
  m_signalproxy_StringVoicedCompleted = this->create_signal<void(int32_t)>("StringVoicedCompleted");
  m_signalproxy_RecentMissedCallsCounterSignal =
      this->create_signal<void(uint32_t, uint32_t)>("RecentMissedCallsCounterSignal");
  m_signalproxy_PhonebookDataDeleted = this->create_signal<void(uint32_t,
                                                                int32_t,
                                                                uint32_t,
                                                                std::string,
                                                                std::string,
                                                                std::string,
                                                                std::string,
                                                                std::string)>("PhonebookDataDeleted");
  m_signalproxy_ImportStatus = this->create_signal<void(uint32_t,
                                                        int32_t,
                                                        uint32_t,
                                                        uint32_t,
                                                        std::string,
                                                        uint32_t,
                                                        int32_t,
                                                        int32_t,
                                                        uint32_t,
                                                        uint32_t)>("ImportStatus");
  m_signalproxy_ContactDeleted = this->create_signal<void(uint32_t, std::string)>("ContactDeleted");
  m_signalproxy_CallHistoryDeleted = this->create_signal<void(int32_t)>("CallHistoryDeleted");
  m_signalproxy_PhonebookDatabaseInfo = this->create_signal<void(int32_t,
                                                                 uint32_t,
                                                                 std::string,
                                                                 int32_t,
                                                                 int32_t,
                                                                 uint32_t,
                                                                 uint32_t,
                                                                 uint32_t,
                                                                 uint64_t)>("PhonebookDatabaseInfo");

}
std::shared_ptr <com_jci_pbProxy> com_jci_pbProxy::create(std::string name) {
  return std::shared_ptr<com_jci_pbProxy>(new com_jci_pbProxy(name));

}
DBus::MultipleReturn <uint32_t, int32_t> com_jci_pbProxy::Import(uint32_t import_request,
                                                                 int32_t import_type,
                                                                 uint32_t filter_type,
                                                                 uint32_t device_id) {
  return (*m_method_Import)(import_request, import_type, filter_type, device_id);

}
DBus::MultipleReturn<int32_t, bool> com_jci_pbProxy::AutoDownloadSetting(uint32_t device_id,
                                                                         int32_t import_type,
                                                                         int32_t setting_type) {
  return (*m_method_AutoDownloadSetting)(device_id, import_type, setting_type);

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_pbProxy::ContactNameOrderSetting(int32_t setting_type) {
  return (*m_method_ContactNameOrderSetting)(setting_type);

}
int32_t com_jci_pbProxy::AllSettingsToFactoryDefault() {
  return (*m_method_AllSettingsToFactoryDefault)();

}
int32_t com_jci_pbProxy::GetStringVoiced(int32_t audio_focus_behaviour, std::string text_string) {
  return (*m_method_GetStringVoiced)(audio_focus_behaviour, text_string);

}
int32_t com_jci_pbProxy::StopStringVoiced(int32_t audio_focus_behaviour) {
  return (*m_method_StopStringVoiced)(audio_focus_behaviour);

}
int32_t com_jci_pbProxy::TalkEvent(int32_t audio_focus_behaviour) {
  return (*m_method_TalkEvent)(audio_focus_behaviour);

}
DBus::MultipleReturn <int32_t, uint32_t> com_jci_pbProxy::RecentMissedCallsCounterGet(uint32_t device_id) {
  return (*m_method_RecentMissedCallsCounterGet)(device_id);

}
int32_t com_jci_pbProxy::RecentMissedCallsCounterReset(uint32_t device_id) {
  return (*m_method_RecentMissedCallsCounterReset)(device_id);

}
std::string com_jci_pbProxy::Debug(bool debug_info_out_to_file,
                                   bool debug_info_out_to_log,
                                   std::string cfg_param_name,
                                   std::string cfg_param_valstring,
                                   bool cfg_param_valbool,
                                   int32_t cfg_param_valint) {
  return (*m_method_Debug)(debug_info_out_to_file,
                           debug_info_out_to_log,
                           cfg_param_name,
                           cfg_param_valstring,
                           cfg_param_valbool,
                           cfg_param_valint);

}
int32_t com_jci_pbProxy::ContactDelete(uint32_t contact_order_id, uint32_t contact_id, std::string display_name) {
  return (*m_method_ContactDelete)(contact_order_id, contact_id, display_name);

}
int32_t com_jci_pbProxy::CallHistoryDelete(int32_t call_history_type) {
  return (*m_method_CallHistoryDelete)(call_history_type);

}
int32_t com_jci_pbProxy::DeletePhonebookData(uint32_t device_id,
                                             int32_t phonebook_data_type,
                                             uint32_t entry_order_id,
                                             uint32_t entry_id,
                                             std::string display_name) {
  return (*m_method_DeletePhonebookData)(device_id, phonebook_data_type, entry_order_id, entry_id, display_name);

}
int32_t com_jci_pbProxy::GetPhonebookDatabaseInfo(int32_t phonebook_database_type, uint32_t device_id) {
  return (*m_method_GetPhonebookDatabaseInfo)(phonebook_database_type, device_id);

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        int32_t,
                                        bool)>> com_jci_pbProxy::signal_AutoDownloadSettingChanged() {
  return m_signalproxy_AutoDownloadSettingChanged;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_pbProxy::signal_ContactNameOrderSettingChanged() {
  return m_signalproxy_ContactNameOrderSettingChanged;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_pbProxy::signal_StringVoicedCompleted() {
  return m_signalproxy_StringVoicedCompleted;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, uint32_t)>> com_jci_pbProxy::signal_RecentMissedCallsCounterSignal() {
  return m_signalproxy_RecentMissedCallsCounterSignal;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        int32_t,
                                        uint32_t,
                                        std::string,
                                        std::string,
                                        std::string,
                                        std::string,
                                        std::string)>> com_jci_pbProxy::signal_PhonebookDataDeleted() {
  return m_signalproxy_PhonebookDataDeleted;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        int32_t,
                                        uint32_t,
                                        uint32_t,
                                        std::string,
                                        uint32_t,
                                        int32_t,
                                        int32_t,
                                        uint32_t,
                                        uint32_t)>> com_jci_pbProxy::signal_ImportStatus() {
  return m_signalproxy_ImportStatus;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, std::string)>> com_jci_pbProxy::signal_ContactDeleted() {
  return m_signalproxy_ContactDeleted;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_pbProxy::signal_CallHistoryDeleted() {
  return m_signalproxy_CallHistoryDeleted;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t,
                                        uint32_t,
                                        std::string,
                                        int32_t,
                                        int32_t,
                                        uint32_t,
                                        uint32_t,
                                        uint32_t,
                                        uint64_t)>> com_jci_pbProxy::signal_PhonebookDatabaseInfo() {
  return m_signalproxy_PhonebookDatabaseInfo;

}
