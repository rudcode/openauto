#ifndef COM_JCI_XMPROXY_H
#define COM_JCI_XMPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_xmProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_xmProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_xmProxy> create(std::string name = "com.jci.xm");
  int32_t GetModeStatus();
  int32_t ModeChange(int32_t xm_mode);
  int32_t FavoriteModeChange(int32_t xm_mode, uint8_t tune_value_sid, uint8_t tune_value_ch);
  int32_t TuneRelative(int32_t tune_direction, uint8_t tune_steps);
  int32_t TuneAbsolute(uint8_t tune_value_sid, uint8_t tune_value_ch);
  int32_t MuteReq(int32_t mute_direction);
  int32_t IsParentalLockEnabled();
  int32_t IsParentalLockPINSet();
  int32_t IsChannelLocked(uint8_t channel_id);
  int32_t GetParentalLockPIN();
  int32_t GetDefaultParentalLockPIN();
  int32_t SetParentalLockPIN(std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> parental_lock_pin);
  int32_t SetParentalLockStatus(int32_t parental_lock_status);
  int32_t SetChannelLock(int32_t channel_lock_status, uint8_t channel_id);
  int32_t DisplayXMSettings();
  int32_t ScanReq(int32_t scan_req_type);
  int32_t GetConfigStatus();
  int32_t Fav_Seek_Req(int32_t fav_seek_dir, uint8_t current_ch);
  int32_t GetInstallStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    bool,
                                                    std::vector<uint8_t>,
                                                    int32_t>)>> signal_TunerStatus();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_MuteStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_ChannelListUpdated();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t>)>> signal_AntennaStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>)>> signal_ParentalLockPin();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t>)>> signal_DefaultParentalLockPin();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_MetadataAvailable();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<bool, bool, bool, bool>)>> signal_MetadataChange();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_ModeStatus();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_ConfigStatus();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_InstallStatus();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetModeStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_ModeChange;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t, uint8_t, uint8_t)>> m_method_FavoriteModeChange;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t, uint8_t)>> m_method_TuneRelative;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint8_t, uint8_t)>> m_method_TuneAbsolute;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_MuteReq;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_IsParentalLockEnabled;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_IsParentalLockPINSet;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint8_t)>> m_method_IsChannelLocked;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetParentalLockPIN;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetDefaultParentalLockPIN;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>)>>
      m_method_SetParentalLockPIN;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_SetParentalLockStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t, uint8_t)>> m_method_SetChannelLock;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_DisplayXMSettings;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_ScanReq;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetConfigStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t, uint8_t)>> m_method_Fav_Seek_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetInstallStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    bool,
                                                    std::vector<uint8_t>,
                                                    int32_t>)>> m_signalproxy_TunerStatus;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_MuteStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_ChannelListUpdated;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t>)>> m_signalproxy_AntennaStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>)>>
      m_signalproxy_ParentalLockPin;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>)>>
      m_signalproxy_DefaultParentalLockPin;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_MetadataAvailable;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<bool, bool, bool, bool>)>> m_signalproxy_MetadataChange;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_ModeStatus;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_ConfigStatus;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_InstallStatus;
};
#endif /* COM_JCI_XMPROXY_H */
