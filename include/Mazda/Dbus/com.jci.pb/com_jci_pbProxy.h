#ifndef COM_JCI_PBPROXY_H
#define COM_JCI_PBPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_pbProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_pbProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_pbProxy> create(std::string name = "com.jci.pb");
  DBus::MultipleReturn<uint32_t, int32_t> Import(uint32_t import_request,
                                                 int32_t import_type,
                                                 uint32_t filter_type,
                                                 uint32_t device_id);
  DBus::MultipleReturn<int32_t, bool> AutoDownloadSetting(uint32_t device_id,
                                                          int32_t import_type,
                                                          int32_t setting_type);
  DBus::MultipleReturn<int32_t, int32_t> ContactNameOrderSetting(int32_t setting_type);
  int32_t AllSettingsToFactoryDefault();
  int32_t GetStringVoiced(int32_t audio_focus_behaviour, std::string text_string);
  int32_t StopStringVoiced(int32_t audio_focus_behaviour);
  int32_t TalkEvent(int32_t audio_focus_behaviour);
  DBus::MultipleReturn<int32_t, uint32_t> RecentMissedCallsCounterGet(uint32_t device_id);
  int32_t RecentMissedCallsCounterReset(uint32_t device_id);
  std::string Debug(bool debug_info_out_to_file,
                    bool debug_info_out_to_log,
                    std::string cfg_param_name,
                    std::string cfg_param_valstring,
                    bool cfg_param_valbool,
                    int32_t cfg_param_valint);
  int32_t ContactDelete(uint32_t contact_order_id, uint32_t contact_id, std::string display_name);
  int32_t CallHistoryDelete(int32_t call_history_type);
  int32_t DeletePhonebookData(uint32_t device_id,
                              int32_t phonebook_data_type,
                              uint32_t entry_order_id,
                              uint32_t entry_id,
                              std::string display_name);
  int32_t GetPhonebookDatabaseInfo(int32_t phonebook_database_type, uint32_t device_id);
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, int32_t, bool)>> signal_AutoDownloadSettingChanged();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_ContactNameOrderSettingChanged();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_StringVoicedCompleted();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> signal_RecentMissedCallsCounterSignal();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         int32_t,
                                         uint32_t,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string)>> signal_PhonebookDataDeleted();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         int32_t,
                                         uint32_t,
                                         uint32_t,
                                         std::string,
                                         uint32_t,
                                         int32_t,
                                         int32_t,
                                         uint32_t,
                                         uint32_t)>> signal_ImportStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::string)>> signal_ContactDeleted();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_CallHistoryDeleted();
  std::shared_ptr<DBus::SignalProxy<void(int32_t,
                                         uint32_t,
                                         std::string,
                                         int32_t,
                                         int32_t,
                                         uint32_t,
                                         uint32_t,
                                         uint32_t,
                                         uint64_t)>> signal_PhonebookDatabaseInfo();
 protected:
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, int32_t>(uint32_t, int32_t, uint32_t, uint32_t)>>
      m_method_Import;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, bool>(uint32_t, int32_t, int32_t)>>
      m_method_AutoDownloadSetting;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, int32_t>(int32_t)>> m_method_ContactNameOrderSetting;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_AllSettingsToFactoryDefault;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t, std::string)>> m_method_GetStringVoiced;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_StopStringVoiced;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_TalkEvent;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t>(uint32_t)>>
      m_method_RecentMissedCallsCounterGet;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_RecentMissedCallsCounterReset;
  std::shared_ptr<DBus::MethodProxy<std::string(bool, bool, std::string, std::string, bool, int32_t)>> m_method_Debug;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t, std::string)>> m_method_ContactDelete;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_CallHistoryDelete;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, int32_t, uint32_t, uint32_t, std::string)>>
      m_method_DeletePhonebookData;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t, uint32_t)>> m_method_GetPhonebookDatabaseInfo;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, int32_t, bool)>> m_signalproxy_AutoDownloadSettingChanged;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_ContactNameOrderSettingChanged;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_StringVoicedCompleted;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> m_signalproxy_RecentMissedCallsCounterSignal;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         int32_t,
                                         uint32_t,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string,
                                         std::string)>> m_signalproxy_PhonebookDataDeleted;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         int32_t,
                                         uint32_t,
                                         uint32_t,
                                         std::string,
                                         uint32_t,
                                         int32_t,
                                         int32_t,
                                         uint32_t,
                                         uint32_t)>> m_signalproxy_ImportStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::string)>> m_signalproxy_ContactDeleted;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_CallHistoryDeleted;
  std::shared_ptr<DBus::SignalProxy<void(int32_t,
                                         uint32_t,
                                         std::string,
                                         int32_t,
                                         int32_t,
                                         uint32_t,
                                         uint32_t,
                                         uint32_t,
                                         uint64_t)>> m_signalproxy_PhonebookDatabaseInfo;
};
#endif /* COM_JCI_PBPROXY_H */
