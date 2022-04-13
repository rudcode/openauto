#ifndef COM_JCI_RADIOPROXY_H
#define COM_JCI_RADIOPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_radioProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_radioProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_radioProxy> create(std::string name = "com.jci.radio");
  int32_t Mode_Req(int32_t mode, int32_t band);
  int32_t Japan_Region_specific_Tau_type_info_Req();
  int32_t Tune_Req(int32_t direction, int32_t steps);
  int32_t Scan_Req(int32_t request);
  int32_t Seek_Req(int32_t request, int32_t direction, bool genreseek_screen);
  int32_t ForceSeek_Req(int32_t forceSeek_Type, int32_t direction);
  int32_t Tune_Direct_Req(std::tuple<double, uint16_t, int32_t> tune_direct);
  int32_t Favorite_Mode_Req(int32_t mode, int32_t band, std::tuple<double, uint16_t, int32_t> tune_direct);
  int32_t Station_List_Req(int32_t list_req_type);
  int32_t Auto_M_Req(int32_t auto_M_req_type);
  int32_t Area_Preset_Req();
  int32_t Get_HDsetting_Req();
  int32_t Get_TAsetting_Req();
  int32_t Get_AFsetting_Req();
  int32_t Get_RegionLockSetting_Req();
  int32_t Get_HARfreqSetting_Req();
  int32_t Get_CurrentGenre_Req();
  int32_t Pty_Req(int32_t pty_req_type);
  int32_t Setting_Change_Req(int32_t setting_type, int32_t setting_mode);
  int32_t HD_ChUp_Req(int32_t hd_ChUp_req);
  int32_t HAR_Freq_change(int32_t frequency);
  int32_t Cancel_Traffic_alert();
  int32_t Get_TAU_Connection_status();
  int32_t Fav_Seek_Req(int32_t fav_seek_dir, double current_freq);
  int32_t Get_Tuner_status();
  int32_t Get_HDTuner_status();
  int32_t Get_Mode_status();
  int32_t Region_specific_info_Req();
  uint8_t Get_Bose_Status();
  int32_t Factory_Reset_Setting();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_Bose_Status();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_TAU_Connection_status();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t, int32_t>)>> signal_Tuner_mode_status();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t,
                                                    int32_t,
                                                    double,
                                                    std::vector<uint8_t>,
                                                    int32_t,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>>)>> signal_Tuner_status();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_Station_list_status();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_Auto_M_status();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_Area_Preset_status();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_HD_setting_status();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_TA_setting_status();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_HAR_setting_status();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_AF_setting_status();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_RegionLock_setting_status();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_Current_genre_status();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_Metadata_status();
  std::shared_ptr<DBus::SignalProxy<void(int32_t, int32_t)>> signal_Setting_status();
  std::shared_ptr<DBus::SignalProxy<void(int32_t, int32_t)>> signal_Pty_response();
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> signal_HD_tuner_status();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t, int32_t>)>> signal_HAR_status();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_Traffic_alert();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_Metadata_Artisticinfo();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<bool,
                                                    bool,
                                                    bool,
                                                    bool,
                                                    bool,
                                                    bool,
                                                    bool>)>> signal_Metadata_change_notification();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_Japan_Region_specific_notification();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_Region_specific_notification();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t, int32_t)>> m_method_Mode_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Japan_Region_specific_Tau_type_info_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t, int32_t)>> m_method_Tune_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_Scan_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t, int32_t, bool)>> m_method_Seek_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t, int32_t)>> m_method_ForceSeek_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::tuple<double, uint16_t, int32_t>)>> m_method_Tune_Direct_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t, int32_t, std::tuple<double, uint16_t, int32_t>)>>
      m_method_Favorite_Mode_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_Station_List_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_Auto_M_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Area_Preset_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Get_HDsetting_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Get_TAsetting_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Get_AFsetting_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Get_RegionLockSetting_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Get_HARfreqSetting_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Get_CurrentGenre_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_Pty_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t, int32_t)>> m_method_Setting_Change_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_HD_ChUp_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_HAR_Freq_change;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Cancel_Traffic_alert;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Get_TAU_Connection_status;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t, double)>> m_method_Fav_Seek_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Get_Tuner_status;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Get_HDTuner_status;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Get_Mode_status;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Region_specific_info_Req;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_Get_Bose_Status;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Factory_Reset_Setting;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_Bose_Status;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_TAU_Connection_status;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t, int32_t>)>> m_signalproxy_Tuner_mode_status;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t,
                                                    int32_t,
                                                    double,
                                                    std::vector<uint8_t>,
                                                    int32_t,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>>)>> m_signalproxy_Tuner_status;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_Station_list_status;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_Auto_M_status;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_Area_Preset_status;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_HD_setting_status;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_TA_setting_status;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_HAR_setting_status;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_AF_setting_status;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_RegionLock_setting_status;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_Current_genre_status;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_Metadata_status;
  std::shared_ptr<DBus::SignalProxy<void(int32_t, int32_t)>> m_signalproxy_Setting_status;
  std::shared_ptr<DBus::SignalProxy<void(int32_t, int32_t)>> m_signalproxy_Pty_response;
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> m_signalproxy_HD_tuner_status;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t, int32_t>)>> m_signalproxy_HAR_status;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_Traffic_alert;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_Metadata_Artisticinfo;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<bool, bool, bool, bool, bool, bool, bool>)>>
      m_signalproxy_Metadata_change_notification;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_Japan_Region_specific_notification;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_Region_specific_notification;
};
#endif /* COM_JCI_RADIOPROXY_H */
