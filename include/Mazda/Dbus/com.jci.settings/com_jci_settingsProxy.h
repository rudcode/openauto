#ifndef COM_JCI_SETTINGSPROXY_H
#define COM_JCI_SETTINGSPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_settingsProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_settingsProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_settingsProxy> create(std::string name = "com.jci.settings");
  int32_t Connect(std::string client_name);
  int32_t Disconnect(std::string client_name);
  DBus::MultipleReturn<uint8_t, uint32_t, uint32_t> Get_Settings_U8(std::string key_path,
                                                                    std::string key_group,
                                                                    std::string key_name,
                                                                    uint32_t user_fun,
                                                                    uint32_t key_actions);
  DBus::MultipleReturn<uint8_t, uint32_t, uint32_t> Set_Settings_U8(std::string key_path,
                                                                    std::string key_group,
                                                                    std::string key_name,
                                                                    uint8_t val,
                                                                    uint32_t user_fun,
                                                                    uint32_t key_actions);
  DBus::MultipleReturn<uint32_t, uint32_t> OnChange_Settings_U8(std::string client_name,
                                                                std::string key_path,
                                                                std::string key_group,
                                                                std::string key_name,
                                                                uint32_t user_signalcb_fun,
                                                                uint32_t user_fun,
                                                                uint32_t key_actions);
  DBus::MultipleReturn<uint32_t, uint32_t> Reset_Settings_U8(std::string key_path,
                                                             std::string key_group,
                                                             std::string key_name,
                                                             uint32_t user_fun,
                                                             uint32_t key_actions);
  DBus::MultipleReturn<int16_t, uint32_t, uint32_t> Get_Settings_S16(std::string key_path,
                                                                     std::string key_group,
                                                                     std::string key_name,
                                                                     uint32_t user_fun,
                                                                     uint32_t key_actions);
  DBus::MultipleReturn<int16_t, uint32_t, uint32_t> Set_Settings_S16(std::string key_path,
                                                                     std::string key_group,
                                                                     std::string key_name,
                                                                     int16_t val,
                                                                     uint32_t user_fun,
                                                                     uint32_t key_actions);
  DBus::MultipleReturn<uint32_t, uint32_t> OnChange_Settings_S16(std::string client_name,
                                                                 std::string key_path,
                                                                 std::string key_group,
                                                                 std::string key_name,
                                                                 uint32_t user_signalcb_fun,
                                                                 uint32_t user_fun,
                                                                 uint32_t key_actions);
  DBus::MultipleReturn<uint32_t, uint32_t> Reset_Settings_S16(std::string key_path,
                                                              std::string key_group,
                                                              std::string key_name,
                                                              uint32_t user_fun,
                                                              uint32_t key_actions);
  DBus::MultipleReturn<uint32_t, uint32_t, uint32_t> Get_Settings_U32(std::string key_path,
                                                                      std::string key_group,
                                                                      std::string key_name,
                                                                      uint32_t user_fun,
                                                                      uint32_t key_actions);
  DBus::MultipleReturn<uint32_t, uint32_t, uint32_t> Set_Settings_U32(std::string key_path,
                                                                      std::string key_group,
                                                                      std::string key_name,
                                                                      uint32_t val,
                                                                      uint32_t user_fun,
                                                                      uint32_t key_actions);
  DBus::MultipleReturn<uint32_t, uint32_t> OnChange_Settings_U32(std::string client_name,
                                                                 std::string key_path,
                                                                 std::string key_group,
                                                                 std::string key_name,
                                                                 uint32_t user_signalcb_fun,
                                                                 uint32_t user_fun,
                                                                 uint32_t key_actions);
  DBus::MultipleReturn<uint32_t, uint32_t> Reset_Settings_U32(std::string key_path,
                                                              std::string key_group,
                                                              std::string key_name,
                                                              uint32_t user_fun,
                                                              uint32_t key_actions);
  DBus::MultipleReturn<std::string, uint32_t, uint32_t> Get_Settings_BLM_Settings_pChar(std::string key_path,
                                                                                        std::string key_group,
                                                                                        std::string key_name,
                                                                                        uint32_t user_fun,
                                                                                        uint32_t key_actions);
  DBus::MultipleReturn<std::string, uint32_t, uint32_t> Set_Settings_BLM_Settings_pChar(std::string key_path,
                                                                                        std::string key_group,
                                                                                        std::string key_name,
                                                                                        std::string val,
                                                                                        uint32_t user_fun,
                                                                                        uint32_t key_actions);
  DBus::MultipleReturn<uint32_t, uint32_t> OnChange_Settings_BLM_Settings_pChar(std::string client_name,
                                                                                std::string key_path,
                                                                                std::string key_group,
                                                                                std::string key_name,
                                                                                uint32_t user_signalcb_fun,
                                                                                uint32_t user_fun,
                                                                                uint32_t key_actions);
  DBus::MultipleReturn<uint32_t, uint32_t> Reset_Settings_BLM_Settings_pChar(std::string key_path,
                                                                             std::string key_group,
                                                                             std::string key_name,
                                                                             uint32_t user_fun,
                                                                             uint32_t key_actions);
  DBus::MultipleReturn<uint32_t, uint32_t> Reset_SettingsGroup(int16_t key_group, uint32_t user_fun);
  DBus::MultipleReturn<uint32_t, uint32_t> Settings_RPC(uint32_t settings_cmd, uint32_t user_fun);
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint32_t, uint32_t)>> signal_OnChangeSignal_Settings_U8();
  std::shared_ptr<DBus::SignalProxy<void(int16_t, uint32_t, uint32_t)>> signal_OnChangeSignal_Settings_S16();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t, uint32_t)>> signal_OnChangeSignal_Settings_U32();
  std::shared_ptr<DBus::SignalProxy<void(std::string,
                                         uint32_t,
                                         uint32_t)>> signal_OnChangeSignal_Settings_BLM_Settings_pChar();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t(std::string)>> m_method_Connect;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::string)>> m_method_Disconnect;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint8_t, uint32_t, uint32_t>(std::string,
                                                                                      std::string,
                                                                                      std::string,
                                                                                      uint32_t,
                                                                                      uint32_t)>>
      m_method_Get_Settings_U8;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint8_t, uint32_t, uint32_t>(std::string,
                                                                                      std::string,
                                                                                      std::string,
                                                                                      uint8_t,
                                                                                      uint32_t,
                                                                                      uint32_t)>>
      m_method_Set_Settings_U8;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t>(std::string,
                                                                             std::string,
                                                                             std::string,
                                                                             std::string,
                                                                             uint32_t,
                                                                             uint32_t,
                                                                             uint32_t)>> m_method_OnChange_Settings_U8;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t>(std::string,
                                                                             std::string,
                                                                             std::string,
                                                                             uint32_t,
                                                                             uint32_t)>> m_method_Reset_Settings_U8;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int16_t, uint32_t, uint32_t>(std::string,
                                                                                      std::string,
                                                                                      std::string,
                                                                                      uint32_t,
                                                                                      uint32_t)>>
      m_method_Get_Settings_S16;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int16_t, uint32_t, uint32_t>(std::string,
                                                                                      std::string,
                                                                                      std::string,
                                                                                      int16_t,
                                                                                      uint32_t,
                                                                                      uint32_t)>>
      m_method_Set_Settings_S16;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t>(std::string,
                                                                             std::string,
                                                                             std::string,
                                                                             std::string,
                                                                             uint32_t,
                                                                             uint32_t,
                                                                             uint32_t)>> m_method_OnChange_Settings_S16;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t>(std::string,
                                                                             std::string,
                                                                             std::string,
                                                                             uint32_t,
                                                                             uint32_t)>> m_method_Reset_Settings_S16;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, uint32_t>(std::string,
                                                                                       std::string,
                                                                                       std::string,
                                                                                       uint32_t,
                                                                                       uint32_t)>>
      m_method_Get_Settings_U32;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, uint32_t>(std::string,
                                                                                       std::string,
                                                                                       std::string,
                                                                                       uint32_t,
                                                                                       uint32_t,
                                                                                       uint32_t)>>
      m_method_Set_Settings_U32;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t>(std::string,
                                                                             std::string,
                                                                             std::string,
                                                                             std::string,
                                                                             uint32_t,
                                                                             uint32_t,
                                                                             uint32_t)>> m_method_OnChange_Settings_U32;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t>(std::string,
                                                                             std::string,
                                                                             std::string,
                                                                             uint32_t,
                                                                             uint32_t)>> m_method_Reset_Settings_U32;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::string, uint32_t, uint32_t>(std::string,
                                                                                          std::string,
                                                                                          std::string,
                                                                                          uint32_t,
                                                                                          uint32_t)>>
      m_method_Get_Settings_BLM_Settings_pChar;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::string, uint32_t, uint32_t>(std::string,
                                                                                          std::string,
                                                                                          std::string,
                                                                                          std::string,
                                                                                          uint32_t,
                                                                                          uint32_t)>>
      m_method_Set_Settings_BLM_Settings_pChar;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t>(std::string,
                                                                             std::string,
                                                                             std::string,
                                                                             std::string,
                                                                             uint32_t,
                                                                             uint32_t,
                                                                             uint32_t)>>
      m_method_OnChange_Settings_BLM_Settings_pChar;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t>(std::string,
                                                                             std::string,
                                                                             std::string,
                                                                             uint32_t,
                                                                             uint32_t)>>
      m_method_Reset_Settings_BLM_Settings_pChar;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t>(int16_t, uint32_t)>>
      m_method_Reset_SettingsGroup;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t>(uint32_t, uint32_t)>>
      m_method_Settings_RPC;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint32_t, uint32_t)>> m_signalproxy_OnChangeSignal_Settings_U8;
  std::shared_ptr<DBus::SignalProxy<void(int16_t, uint32_t, uint32_t)>> m_signalproxy_OnChangeSignal_Settings_S16;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t, uint32_t)>> m_signalproxy_OnChangeSignal_Settings_U32;
  std::shared_ptr<DBus::SignalProxy<void(std::string, uint32_t, uint32_t)>>
      m_signalproxy_OnChangeSignal_Settings_BLM_Settings_pChar;
};
#endif /* COM_JCI_SETTINGSPROXY_H */
