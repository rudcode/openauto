#ifndef COM_JCI_DABPROXY_H
#define COM_JCI_DABPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_dabProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_dabProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_dabProxy> create(std::string name = "com.jci.dab");
  int32_t Get_Dab_Mode_Status();
  int32_t Get_Tuner_Mode_Status();
  int32_t Get_Install_Status();
  int32_t Get_Channel_Status();
  int32_t Get_Signal_Strength_Status();
  int32_t Get_TAU_List_Status();
  int32_t Tuner_Mode_Change(int32_t tuner_mode);
  int32_t Scan_Req(int32_t request);
  int32_t Compo_Seek_Req(int32_t request);
  int32_t Ens_Seek_Req(int32_t request);
  int32_t Direct_Control_Req(std::tuple<std::vector<uint8_t>, uint16_t, uint16_t, uint8_t> channel_info);
  int32_t Update_TAU_List_Req();
  int32_t Link_Setting_Change_Req(std::tuple<int32_t, int32_t> link_setting);
  int32_t Band_Setting_Change_Req(int32_t band_mode);
  int32_t TA_Setting_Change_Req(int32_t ta_mode);
  int32_t Radio_Text_Setting_Change_Req(int32_t radio_text_mode);
  int32_t Get_DAB_DAB_Setting_Req();
  int32_t Get_DAB_FM_Setting_Req();
  int32_t Get_Band_Setting_Req();
  int32_t Get_TA_Setting_Req();
  int32_t Get_Radio_Text_Setting_Status();
  int32_t Get_TAU_Connection_Status();
  int32_t Fav_Seek_Req(int32_t fav_seek_dir,
                       std::tuple<std::vector<uint8_t>, uint16_t, uint16_t, uint8_t> channel_info);
  int32_t Factory_Reset_Setting();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_TAU_Connection_Status();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_Signal_Strength_Status();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t, int32_t>)>> signal_Link_Setting_Status();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_Band_Setting_Status();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_TA_Setting_Status();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_Radio_Text_Setting_Status();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_Full_List_Update_Status();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_Tuner_Mode_Status();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t, int32_t>)>> signal_Dab_Mode_Status();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_TAU_List_Status();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>,
                                                    uint16_t,
                                                    uint16_t,
                                                    uint8_t>)>> signal_Channel_Status();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<bool,
                                                    bool,
                                                    bool,
                                                    bool,
                                                    int32_t,
                                                    std::vector<uint8_t>>)>> signal_Info_Change_Status();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<bool, bool, bool, bool>)>> signal_Clear_Label_Field_Status();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_Install_Status();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_Ens_List_Status();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint16_t, bool>)>> signal_Compo_List_Status();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_New_List_Available();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Get_Dab_Mode_Status;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Get_Tuner_Mode_Status;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Get_Install_Status;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Get_Channel_Status;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Get_Signal_Strength_Status;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Get_TAU_List_Status;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_Tuner_Mode_Change;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_Scan_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_Compo_Seek_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_Ens_Seek_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::tuple<std::vector<uint8_t>, uint16_t, uint16_t, uint8_t>)>>
      m_method_Direct_Control_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Update_TAU_List_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::tuple<int32_t, int32_t>)>> m_method_Link_Setting_Change_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_Band_Setting_Change_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_TA_Setting_Change_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_Radio_Text_Setting_Change_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Get_DAB_DAB_Setting_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Get_DAB_FM_Setting_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Get_Band_Setting_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Get_TA_Setting_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Get_Radio_Text_Setting_Status;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Get_TAU_Connection_Status;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t, std::tuple<std::vector<uint8_t>, uint16_t, uint16_t, uint8_t>)>>
      m_method_Fav_Seek_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Factory_Reset_Setting;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_TAU_Connection_Status;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_Signal_Strength_Status;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t, int32_t>)>> m_signalproxy_Link_Setting_Status;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_Band_Setting_Status;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_TA_Setting_Status;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_Radio_Text_Setting_Status;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_Full_List_Update_Status;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_Tuner_Mode_Status;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t, int32_t>)>> m_signalproxy_Dab_Mode_Status;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_TAU_List_Status;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>, uint16_t, uint16_t, uint8_t>)>>
      m_signalproxy_Channel_Status;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<bool, bool, bool, bool, int32_t, std::vector<uint8_t>>)>>
      m_signalproxy_Info_Change_Status;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<bool, bool, bool, bool>)>> m_signalproxy_Clear_Label_Field_Status;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_Install_Status;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_Ens_List_Status;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint16_t, bool>)>> m_signalproxy_Compo_List_Status;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_New_List_Available;
};
#endif /* COM_JCI_DABPROXY_H */
