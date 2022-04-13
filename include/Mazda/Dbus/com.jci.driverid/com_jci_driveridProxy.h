#ifndef COM_JCI_DRIVERIDPROXY_H
#define COM_JCI_DRIVERIDPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_driveridProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_driveridProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_driveridProxy> create(std::string name = "com.jci.driverid");
  int32_t Get_DriveridConfig();
  int32_t Set_DriveridSetting(uint32_t setting_type);
  int32_t GetDriverIdData();
  int32_t Get_DriverList();
  int32_t Change_DriverId(uint8_t drv_id);
  int32_t Change_DriverNickname(std::tuple<std::vector<uint8_t>> nickname);
  int32_t SynUp_Ack_Rcvd();
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> signal_EOLConfig();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_Setting();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    std::vector<uint8_t>,
                                                    bool,
                                                    uint8_t>)>> signal_Curr_DriverData();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    std::vector<uint8_t>,
                                                    bool,
                                                    uint8_t>)>> signal_Curr_DriverDataAsync();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<std::tuple<uint8_t,
                                                                           std::vector<uint8_t>,
                                                                           bool,
                                                                           uint8_t>>>)>> signal_Driver_List();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_Duplicate_Nickname();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_SpeedRest_Flg();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_ACC_OFF();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Get_DriveridConfig;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_Set_DriveridSetting;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetDriverIdData;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Get_DriverList;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint8_t)>> m_method_Change_DriverId;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::tuple<std::vector<uint8_t>>)>> m_method_Change_DriverNickname;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_SynUp_Ack_Rcvd;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> m_signalproxy_EOLConfig;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_Setting;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, std::vector<uint8_t>, bool, uint8_t>)>>
      m_signalproxy_Curr_DriverData;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, std::vector<uint8_t>, bool, uint8_t>)>>
      m_signalproxy_Curr_DriverDataAsync;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<std::tuple<uint8_t,
                                                                           std::vector<uint8_t>,
                                                                           bool,
                                                                           uint8_t>>>)>> m_signalproxy_Driver_List;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_Duplicate_Nickname;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_SpeedRest_Flg;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_ACC_OFF;
};
#endif /* COM_JCI_DRIVERIDPROXY_H */
