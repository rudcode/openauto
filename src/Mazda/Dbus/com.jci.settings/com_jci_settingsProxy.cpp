#include "com_jci_settingsProxy.h"

com_jci_settingsProxy::com_jci_settingsProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_Connect = this->create_method<int32_t(std::string)>("Connect");
  m_method_Disconnect = this->create_method<int32_t(std::string)>("Disconnect");
  m_method_Get_Settings_U8 = this->create_method<DBus::MultipleReturn<uint8_t, uint32_t, uint32_t>(std::string,
                                                                                                   std::string,
                                                                                                   std::string,
                                                                                                   uint32_t,
                                                                                                   uint32_t)>(
      "Get_Settings_U8");
  m_method_Set_Settings_U8 = this->create_method<DBus::MultipleReturn<uint8_t, uint32_t, uint32_t>(std::string,
                                                                                                   std::string,
                                                                                                   std::string,
                                                                                                   uint8_t,
                                                                                                   uint32_t,
                                                                                                   uint32_t)>(
      "Set_Settings_U8");
  m_method_OnChange_Settings_U8 = this->create_method<DBus::MultipleReturn<uint32_t, uint32_t>(std::string,
                                                                                               std::string,
                                                                                               std::string,
                                                                                               std::string,
                                                                                               uint32_t,
                                                                                               uint32_t,
                                                                                               uint32_t)>(
      "OnChange_Settings_U8");
  m_method_Reset_Settings_U8 = this->create_method<DBus::MultipleReturn<uint32_t, uint32_t>(std::string,
                                                                                            std::string,
                                                                                            std::string,
                                                                                            uint32_t,
                                                                                            uint32_t)>(
      "Reset_Settings_U8");
  m_method_Get_Settings_S16 = this->create_method<DBus::MultipleReturn<int16_t, uint32_t, uint32_t>(std::string,
                                                                                                    std::string,
                                                                                                    std::string,
                                                                                                    uint32_t,
                                                                                                    uint32_t)>(
      "Get_Settings_S16");
  m_method_Set_Settings_S16 = this->create_method<DBus::MultipleReturn<int16_t, uint32_t, uint32_t>(std::string,
                                                                                                    std::string,
                                                                                                    std::string,
                                                                                                    int16_t,
                                                                                                    uint32_t,
                                                                                                    uint32_t)>(
      "Set_Settings_S16");
  m_method_OnChange_Settings_S16 = this->create_method<DBus::MultipleReturn<uint32_t, uint32_t>(std::string,
                                                                                                std::string,
                                                                                                std::string,
                                                                                                std::string,
                                                                                                uint32_t,
                                                                                                uint32_t,
                                                                                                uint32_t)>(
      "OnChange_Settings_S16");
  m_method_Reset_Settings_S16 = this->create_method<DBus::MultipleReturn<uint32_t, uint32_t>(std::string,
                                                                                             std::string,
                                                                                             std::string,
                                                                                             uint32_t,
                                                                                             uint32_t)>(
      "Reset_Settings_S16");
  m_method_Get_Settings_U32 = this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, uint32_t>(std::string,
                                                                                                     std::string,
                                                                                                     std::string,
                                                                                                     uint32_t,
                                                                                                     uint32_t)>(
      "Get_Settings_U32");
  m_method_Set_Settings_U32 = this->create_method<DBus::MultipleReturn<uint32_t, uint32_t, uint32_t>(std::string,
                                                                                                     std::string,
                                                                                                     std::string,
                                                                                                     uint32_t,
                                                                                                     uint32_t,
                                                                                                     uint32_t)>(
      "Set_Settings_U32");
  m_method_OnChange_Settings_U32 = this->create_method<DBus::MultipleReturn<uint32_t, uint32_t>(std::string,
                                                                                                std::string,
                                                                                                std::string,
                                                                                                std::string,
                                                                                                uint32_t,
                                                                                                uint32_t,
                                                                                                uint32_t)>(
      "OnChange_Settings_U32");
  m_method_Reset_Settings_U32 = this->create_method<DBus::MultipleReturn<uint32_t, uint32_t>(std::string,
                                                                                             std::string,
                                                                                             std::string,
                                                                                             uint32_t,
                                                                                             uint32_t)>(
      "Reset_Settings_U32");
  m_method_Get_Settings_BLM_Settings_pChar = this->create_method<DBus::MultipleReturn<std::string, uint32_t, uint32_t>(
      std::string,
      std::string,
      std::string,
      uint32_t,
      uint32_t)>("Get_Settings_BLM_Settings_pChar");
  m_method_Set_Settings_BLM_Settings_pChar = this->create_method<DBus::MultipleReturn<std::string, uint32_t, uint32_t>(
      std::string,
      std::string,
      std::string,
      std::string,
      uint32_t,
      uint32_t)>("Set_Settings_BLM_Settings_pChar");
  m_method_OnChange_Settings_BLM_Settings_pChar =
      this->create_method<DBus::MultipleReturn<uint32_t, uint32_t>(std::string,
                                                                   std::string,
                                                                   std::string,
                                                                   std::string,
                                                                   uint32_t,
                                                                   uint32_t,
                                                                   uint32_t)>("OnChange_Settings_BLM_Settings_pChar");
  m_method_Reset_Settings_BLM_Settings_pChar = this->create_method<DBus::MultipleReturn<uint32_t, uint32_t>(std::string,
                                                                                                            std::string,
                                                                                                            std::string,
                                                                                                            uint32_t,
                                                                                                            uint32_t)>(
      "Reset_Settings_BLM_Settings_pChar");
  m_method_Reset_SettingsGroup =
      this->create_method<DBus::MultipleReturn<uint32_t, uint32_t>(int16_t, uint32_t)>("Reset_SettingsGroup");
  m_method_Settings_RPC =
      this->create_method<DBus::MultipleReturn<uint32_t, uint32_t>(uint32_t, uint32_t)>("Settings_RPC");
  m_signalproxy_OnChangeSignal_Settings_U8 =
      this->create_signal<void(uint8_t, uint32_t, uint32_t)>("OnChangeSignal_Settings_U8");
  m_signalproxy_OnChangeSignal_Settings_S16 =
      this->create_signal<void(int16_t, uint32_t, uint32_t)>("OnChangeSignal_Settings_S16");
  m_signalproxy_OnChangeSignal_Settings_U32 =
      this->create_signal<void(uint32_t, uint32_t, uint32_t)>("OnChangeSignal_Settings_U32");
  m_signalproxy_OnChangeSignal_Settings_BLM_Settings_pChar =
      this->create_signal<void(std::string, uint32_t, uint32_t)>("OnChangeSignal_Settings_BLM_Settings_pChar");

}
std::shared_ptr <com_jci_settingsProxy> com_jci_settingsProxy::create(std::string name) {
  return std::shared_ptr<com_jci_settingsProxy>(new com_jci_settingsProxy(name));

}
int32_t com_jci_settingsProxy::Connect(std::string client_name) {
  return (*m_method_Connect)(client_name);

}
int32_t com_jci_settingsProxy::Disconnect(std::string client_name) {
  return (*m_method_Disconnect)(client_name);

}
DBus::MultipleReturn <uint8_t, uint32_t, uint32_t> com_jci_settingsProxy::Get_Settings_U8(std::string key_path,
                                                                                          std::string key_group,
                                                                                          std::string key_name,
                                                                                          uint32_t user_fun,
                                                                                          uint32_t key_actions) {
  return (*m_method_Get_Settings_U8)(key_path, key_group, key_name, user_fun, key_actions);

}
DBus::MultipleReturn <uint8_t, uint32_t, uint32_t> com_jci_settingsProxy::Set_Settings_U8(std::string key_path,
                                                                                          std::string key_group,
                                                                                          std::string key_name,
                                                                                          uint8_t val,
                                                                                          uint32_t user_fun,
                                                                                          uint32_t key_actions) {
  return (*m_method_Set_Settings_U8)(key_path, key_group, key_name, val, user_fun, key_actions);

}
DBus::MultipleReturn <uint32_t, uint32_t> com_jci_settingsProxy::OnChange_Settings_U8(std::string client_name,
                                                                                      std::string key_path,
                                                                                      std::string key_group,
                                                                                      std::string key_name,
                                                                                      uint32_t user_signalcb_fun,
                                                                                      uint32_t user_fun,
                                                                                      uint32_t key_actions) {
  return (*m_method_OnChange_Settings_U8)(client_name,
                                          key_path,
                                          key_group,
                                          key_name,
                                          user_signalcb_fun,
                                          user_fun,
                                          key_actions);

}
DBus::MultipleReturn <uint32_t, uint32_t> com_jci_settingsProxy::Reset_Settings_U8(std::string key_path,
                                                                                   std::string key_group,
                                                                                   std::string key_name,
                                                                                   uint32_t user_fun,
                                                                                   uint32_t key_actions) {
  return (*m_method_Reset_Settings_U8)(key_path, key_group, key_name, user_fun, key_actions);

}
DBus::MultipleReturn <int16_t, uint32_t, uint32_t> com_jci_settingsProxy::Get_Settings_S16(std::string key_path,
                                                                                           std::string key_group,
                                                                                           std::string key_name,
                                                                                           uint32_t user_fun,
                                                                                           uint32_t key_actions) {
  return (*m_method_Get_Settings_S16)(key_path, key_group, key_name, user_fun, key_actions);

}
DBus::MultipleReturn <int16_t, uint32_t, uint32_t> com_jci_settingsProxy::Set_Settings_S16(std::string key_path,
                                                                                           std::string key_group,
                                                                                           std::string key_name,
                                                                                           int16_t val,
                                                                                           uint32_t user_fun,
                                                                                           uint32_t key_actions) {
  return (*m_method_Set_Settings_S16)(key_path, key_group, key_name, val, user_fun, key_actions);

}
DBus::MultipleReturn <uint32_t, uint32_t> com_jci_settingsProxy::OnChange_Settings_S16(std::string client_name,
                                                                                       std::string key_path,
                                                                                       std::string key_group,
                                                                                       std::string key_name,
                                                                                       uint32_t user_signalcb_fun,
                                                                                       uint32_t user_fun,
                                                                                       uint32_t key_actions) {
  return (*m_method_OnChange_Settings_S16)(client_name,
                                           key_path,
                                           key_group,
                                           key_name,
                                           user_signalcb_fun,
                                           user_fun,
                                           key_actions);

}
DBus::MultipleReturn <uint32_t, uint32_t> com_jci_settingsProxy::Reset_Settings_S16(std::string key_path,
                                                                                    std::string key_group,
                                                                                    std::string key_name,
                                                                                    uint32_t user_fun,
                                                                                    uint32_t key_actions) {
  return (*m_method_Reset_Settings_S16)(key_path, key_group, key_name, user_fun, key_actions);

}
DBus::MultipleReturn <uint32_t, uint32_t, uint32_t> com_jci_settingsProxy::Get_Settings_U32(std::string key_path,
                                                                                            std::string key_group,
                                                                                            std::string key_name,
                                                                                            uint32_t user_fun,
                                                                                            uint32_t key_actions) {
  return (*m_method_Get_Settings_U32)(key_path, key_group, key_name, user_fun, key_actions);

}
DBus::MultipleReturn <uint32_t, uint32_t, uint32_t> com_jci_settingsProxy::Set_Settings_U32(std::string key_path,
                                                                                            std::string key_group,
                                                                                            std::string key_name,
                                                                                            uint32_t val,
                                                                                            uint32_t user_fun,
                                                                                            uint32_t key_actions) {
  return (*m_method_Set_Settings_U32)(key_path, key_group, key_name, val, user_fun, key_actions);

}
DBus::MultipleReturn <uint32_t, uint32_t> com_jci_settingsProxy::OnChange_Settings_U32(std::string client_name,
                                                                                       std::string key_path,
                                                                                       std::string key_group,
                                                                                       std::string key_name,
                                                                                       uint32_t user_signalcb_fun,
                                                                                       uint32_t user_fun,
                                                                                       uint32_t key_actions) {
  return (*m_method_OnChange_Settings_U32)(client_name,
                                           key_path,
                                           key_group,
                                           key_name,
                                           user_signalcb_fun,
                                           user_fun,
                                           key_actions);

}
DBus::MultipleReturn <uint32_t, uint32_t> com_jci_settingsProxy::Reset_Settings_U32(std::string key_path,
                                                                                    std::string key_group,
                                                                                    std::string key_name,
                                                                                    uint32_t user_fun,
                                                                                    uint32_t key_actions) {
  return (*m_method_Reset_Settings_U32)(key_path, key_group, key_name, user_fun, key_actions);

}
DBus::MultipleReturn <std::string, uint32_t, uint32_t> com_jci_settingsProxy::Get_Settings_BLM_Settings_pChar(std::string key_path,
                                                                                                              std::string key_group,
                                                                                                              std::string key_name,
                                                                                                              uint32_t user_fun,
                                                                                                              uint32_t key_actions) {
  return (*m_method_Get_Settings_BLM_Settings_pChar)(key_path, key_group, key_name, user_fun, key_actions);

}
DBus::MultipleReturn <std::string, uint32_t, uint32_t> com_jci_settingsProxy::Set_Settings_BLM_Settings_pChar(std::string key_path,
                                                                                                              std::string key_group,
                                                                                                              std::string key_name,
                                                                                                              std::string val,
                                                                                                              uint32_t user_fun,
                                                                                                              uint32_t key_actions) {
  return (*m_method_Set_Settings_BLM_Settings_pChar)(key_path, key_group, key_name, val, user_fun, key_actions);

}
DBus::MultipleReturn <uint32_t, uint32_t> com_jci_settingsProxy::OnChange_Settings_BLM_Settings_pChar(std::string client_name,
                                                                                                      std::string key_path,
                                                                                                      std::string key_group,
                                                                                                      std::string key_name,
                                                                                                      uint32_t user_signalcb_fun,
                                                                                                      uint32_t user_fun,
                                                                                                      uint32_t key_actions) {
  return (*m_method_OnChange_Settings_BLM_Settings_pChar)(client_name,
                                                          key_path,
                                                          key_group,
                                                          key_name,
                                                          user_signalcb_fun,
                                                          user_fun,
                                                          key_actions);

}
DBus::MultipleReturn <uint32_t, uint32_t> com_jci_settingsProxy::Reset_Settings_BLM_Settings_pChar(std::string key_path,
                                                                                                   std::string key_group,
                                                                                                   std::string key_name,
                                                                                                   uint32_t user_fun,
                                                                                                   uint32_t key_actions) {
  return (*m_method_Reset_Settings_BLM_Settings_pChar)(key_path, key_group, key_name, user_fun, key_actions);

}
DBus::MultipleReturn <uint32_t, uint32_t> com_jci_settingsProxy::Reset_SettingsGroup(int16_t key_group,
                                                                                     uint32_t user_fun) {
  return (*m_method_Reset_SettingsGroup)(key_group, user_fun);

}
DBus::MultipleReturn <uint32_t, uint32_t> com_jci_settingsProxy::Settings_RPC(uint32_t settings_cmd,
                                                                              uint32_t user_fun) {
  return (*m_method_Settings_RPC)(settings_cmd, user_fun);

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t,
                                        uint32_t,
                                        uint32_t)>> com_jci_settingsProxy::signal_OnChangeSignal_Settings_U8() {
  return m_signalproxy_OnChangeSignal_Settings_U8;

}
std::shared_ptr <DBus::SignalProxy<void(int16_t,
                                        uint32_t,
                                        uint32_t)>> com_jci_settingsProxy::signal_OnChangeSignal_Settings_S16() {
  return m_signalproxy_OnChangeSignal_Settings_S16;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        uint32_t,
                                        uint32_t)>> com_jci_settingsProxy::signal_OnChangeSignal_Settings_U32() {
  return m_signalproxy_OnChangeSignal_Settings_U32;

}
std::shared_ptr <DBus::SignalProxy<void(std::string,
                                        uint32_t,
                                        uint32_t)>> com_jci_settingsProxy::signal_OnChangeSignal_Settings_BLM_Settings_pChar() {
  return m_signalproxy_OnChangeSignal_Settings_BLM_Settings_pChar;

}
