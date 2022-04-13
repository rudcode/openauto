#ifndef COM_JCI_BLM_MSG_INTERFACEPROXY_H
#define COM_JCI_BLM_MSG_INTERFACEPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_blm_msg_InterfaceProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_blm_msg_InterfaceProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_blm_msg_InterfaceProxy> create(std::string name = "com.jci.blm.msg.Interface");
  DBus::MultipleReturn<uint32_t, int32_t, uint32_t, int32_t, uint32_t> Connect(uint32_t context_in,
                                                                               int32_t client_type_in,
                                                                               uint32_t callbacks_in);
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t> Disconnect(uint32_t context_in, uint32_t connection_in);
  DBus::MultipleReturn<uint32_t,
                       uint32_t,
                       int32_t,
                       std::tuple<uint32_t,
                                  std::vector<std::tuple<uint16_t,
                                                         std::string>>>> GetInstanceList(uint32_t connection_in,
                                                                                         uint32_t context_in);
  DBus::MultipleReturn<uint32_t,
                       uint32_t,
                       int32_t,
                       std::tuple<bool,
                                  bool,
                                  bool,
                                  uint32_t,
                                  uint32_t,
                                  std::vector<std::tuple<int32_t,
                                                         uint64_t,
                                                         int32_t,
                                                         uint32_t,
                                                         std::string,
                                                         std::string,
                                                         std::string>>>> GetMessageList(uint32_t connection_in,
                                                                                        uint32_t context_in,
                                                                                        std::tuple<uint16_t,
                                                                                                   std::tuple<uint32_t,
                                                                                                              uint32_t,
                                                                                                              std::tuple<
                                                                                                                  uint32_t,
                                                                                                                  std::vector<
                                                                                                                      std::tuple<
                                                                                                                          int32_t,
                                                                                                                          uint32_t,
                                                                                                                          std::string>>>>> filter,
                                                                                        int32_t request_type);
  DBus::MultipleReturn<uint32_t,
                       uint32_t,
                       int32_t,
                       std::tuple<uint32_t,
                                  std::vector<std::tuple<int32_t,
                                                         uint64_t,
                                                         int32_t,
                                                         uint32_t,
                                                         std::string,
                                                         std::string,
                                                         std::string>>>> GetNewMessagesList(uint32_t connection_in,
                                                                                            uint32_t context_in,
                                                                                            int32_t request_type);
  DBus::MultipleReturn<uint32_t,
                       uint32_t,
                       int32_t,
                       std::tuple<std::tuple<uint32_t,
                                             std::vector<std::tuple<int32_t, uint32_t, bool>>>>> GetNewMessagesInfo(
      uint32_t connection_in,
      uint32_t context_in);
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t, Invalid> GetMessage(uint32_t connection_in,
                                                                        uint32_t context_in,
                                                                        uint64_t message_id);
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t> SetMessageStatus(uint32_t connection_in,
                                                                     uint32_t context_in,
                                                                     uint64_t message_id,
                                                                     int32_t message_status);
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t, uint64_t> DeleteMessage(uint32_t connection_in,
                                                                            uint32_t context_in,
                                                                            uint64_t message_id_in);
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t> DeleteSavedMessage(uint32_t connection_in, uint32_t context_in);
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t, Invalid> GetOutgoingMessage(uint32_t connection_in,
                                                                                uint32_t context_in,
                                                                                uint64_t message_id,
                                                                                int32_t send_type);
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t, Invalid> GetSavedMessage(uint32_t connection_in,
                                                                             uint32_t context_in);
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t> SendMessage(uint32_t connection_in,
                                                                uint32_t context_in,
                                                                Invalid message);
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t> SaveMessage(uint32_t connection_in,
                                                                uint32_t context_in,
                                                                Invalid message);
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t, int32_t, bool> GetAutoDownload(uint32_t connection_in,
                                                                                   uint32_t context_in,
                                                                                   int32_t client_type_in,
                                                                                   int32_t type);
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t, int32_t> SetAutoDownload(uint32_t connection_in,
                                                                             uint32_t context_in,
                                                                             int32_t client_type_in,
                                                                             bool enabled);
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t, int32_t, bool> GetNotify(uint32_t connection_in,
                                                                             uint32_t context_in,
                                                                             int32_t client_type_in,
                                                                             int32_t type);
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t, int32_t> SetNotify(uint32_t connection_in,
                                                                       uint32_t context_in,
                                                                       int32_t client_type_in,
                                                                       bool enabled);
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t> StartMessagePlayback(uint32_t connection_in,
                                                                         uint32_t context_in,
                                                                         uint64_t message_id);
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t> StartOutgoingMessagePlayback(uint32_t connection_in,
                                                                                 uint32_t context_in,
                                                                                 Invalid message);
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t> PauseMessagePlayback(uint32_t connection_in, uint32_t context_in);
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t> ResumeMessagePlayback(uint32_t connection_in, uint32_t context_in);
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t> StopMessagePlayback(uint32_t connection_in, uint32_t context_in);
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t> CancelPendingMessagePlayback(uint32_t connection_in,
                                                                                 uint32_t context_in);
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t> AddPresetMessage(uint32_t connection_in,
                                                                     uint32_t context_in,
                                                                     std::string message,
                                                                     uint32_t type);
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t> DeletePresetMessage(uint32_t connection_in,
                                                                        uint32_t context_in,
                                                                        uint32_t message_id,
                                                                        uint32_t type);
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t> MovePresetMessage(uint32_t connection_in,
                                                                      uint32_t context_in,
                                                                      uint32_t message_id_from,
                                                                      uint32_t message_id_to,
                                                                      uint32_t type);
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t> EditPresetMessage(uint32_t connection_in,
                                                                      uint32_t context_in,
                                                                      uint32_t message_id,
                                                                      std::string message,
                                                                      uint32_t type);
  DBus::MultipleReturn<uint32_t,
                       uint32_t,
                       int32_t,
                       std::tuple<uint32_t, std::vector<std::string>>> GetPresetMessageList(uint32_t connection_in,
                                                                                            uint32_t context_in,
                                                                                            uint32_t type);
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t> ApplySettings(uint32_t connection_in, uint32_t context_in);
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t, uint32_t> ResetSettings(uint32_t connection_in,
                                                                            uint32_t context_in,
                                                                            uint32_t settings_in);
  std::shared_ptr<DBus::SignalProxy<void(int32_t, bool)>> signal_AutoDownloadChanged();
  std::shared_ptr<DBus::SignalProxy<void(int32_t, bool)>> signal_NotifyChanged();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_PresetMessageListChanged();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<int32_t, uint64_t, std::string, std::string>)>> signal_NewMessage();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::tuple<uint32_t,
                                                               std::vector<std::tuple<int32_t,
                                                                                      uint32_t,
                                                                                      bool>>>>)>> signal_NewMessagesInfo();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, int32_t)>> signal_Notification();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         int32_t,
                                         std::tuple<bool,
                                                    bool,
                                                    bool,
                                                    uint32_t,
                                                    uint32_t,
                                                    std::vector<std::tuple<int32_t,
                                                                           uint64_t,
                                                                           int32_t,
                                                                           uint32_t,
                                                                           std::string,
                                                                           std::string,
                                                                           std::string>>>)>> signal_DownloadCompleted();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, int32_t, uint64_t)>> signal_MessagePlaybackStatusChanged();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<uint32_t,
                                                    std::vector<std::tuple<uint16_t,
                                                                           std::string>>>)>> signal_InstancesDisconnected();
 protected:
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, int32_t, uint32_t, int32_t, uint32_t>(uint32_t,
                                                                                                         int32_t,
                                                                                                         uint32_t)>>
      m_method_Connect;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t, uint32_t)>>
      m_method_Disconnect;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t,
                                                         uint32_t,
                                                         int32_t,
                                                         std::tuple<uint32_t,
                                                                    std::vector<std::tuple<uint16_t, std::string>>>>(
      uint32_t,
      uint32_t)>> m_method_GetInstanceList;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t,
                                                         uint32_t,
                                                         int32_t,
                                                         std::tuple<bool,
                                                                    bool,
                                                                    bool,
                                                                    uint32_t,
                                                                    uint32_t,
                                                                    std::vector<std::tuple<int32_t,
                                                                                           uint64_t,
                                                                                           int32_t,
                                                                                           uint32_t,
                                                                                           std::string,
                                                                                           std::string,
                                                                                           std::string>>>>(uint32_t,
                                                                                                           uint32_t,
                                                                                                           std::tuple<
                                                                                                               uint16_t,
                                                                                                               std::tuple<
                                                                                                                   uint32_t,
                                                                                                                   uint32_t,
                                                                                                                   std::tuple<
                                                                                                                       uint32_t,
                                                                                                                       std::vector<
                                                                                                                           std::tuple<
                                                                                                                               int32_t,
                                                                                                                               uint32_t,
                                                                                                                               std::string>>>>>,
                                                                                                           int32_t)>>
      m_method_GetMessageList;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t,
                                                         uint32_t,
                                                         int32_t,
                                                         std::tuple<uint32_t,
                                                                    std::vector<std::tuple<int32_t,
                                                                                           uint64_t,
                                                                                           int32_t,
                                                                                           uint32_t,
                                                                                           std::string,
                                                                                           std::string,
                                                                                           std::string>>>>(uint32_t,
                                                                                                           uint32_t,
                                                                                                           int32_t)>>
      m_method_GetNewMessagesList;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t,
                                                         uint32_t,
                                                         int32_t,
                                                         std::tuple<std::tuple<uint32_t,
                                                                               std::vector<std::tuple<int32_t,
                                                                                                      uint32_t,
                                                                                                      bool>>>>>(uint32_t,
                                                                                                                uint32_t)>>
      m_method_GetNewMessagesInfo;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t, Invalid>(uint32_t,
                                                                                               uint32_t,
                                                                                               uint64_t)>>
      m_method_GetMessage;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t,
                                                                                      uint32_t,
                                                                                      uint64_t,
                                                                                      int32_t)>>
      m_method_SetMessageStatus;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t, uint64_t>(uint32_t,
                                                                                                uint32_t,
                                                                                                uint64_t)>>
      m_method_DeleteMessage;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t, uint32_t)>>
      m_method_DeleteSavedMessage;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t, Invalid>(uint32_t,
                                                                                               uint32_t,
                                                                                               uint64_t,
                                                                                               int32_t)>>
      m_method_GetOutgoingMessage;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t, Invalid>(uint32_t, uint32_t)>>
      m_method_GetSavedMessage;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t, uint32_t, Invalid)>>
      m_method_SendMessage;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t, uint32_t, Invalid)>>
      m_method_SaveMessage;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t, int32_t, bool>(uint32_t,
                                                                                                     uint32_t,
                                                                                                     int32_t,
                                                                                                     int32_t)>>
      m_method_GetAutoDownload;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t, int32_t>(uint32_t,
                                                                                               uint32_t,
                                                                                               int32_t,
                                                                                               bool)>>
      m_method_SetAutoDownload;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t, int32_t, bool>(uint32_t,
                                                                                                     uint32_t,
                                                                                                     int32_t,
                                                                                                     int32_t)>>
      m_method_GetNotify;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t, int32_t>(uint32_t,
                                                                                               uint32_t,
                                                                                               int32_t,
                                                                                               bool)>>
      m_method_SetNotify;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t, uint32_t, uint64_t)>>
      m_method_StartMessagePlayback;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t, uint32_t, Invalid)>>
      m_method_StartOutgoingMessagePlayback;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t, uint32_t)>>
      m_method_PauseMessagePlayback;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t, uint32_t)>>
      m_method_ResumeMessagePlayback;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t, uint32_t)>>
      m_method_StopMessagePlayback;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t, uint32_t)>>
      m_method_CancelPendingMessagePlayback;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t,
                                                                                      uint32_t,
                                                                                      std::string,
                                                                                      uint32_t)>>
      m_method_AddPresetMessage;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t,
                                                                                      uint32_t,
                                                                                      uint32_t,
                                                                                      uint32_t)>>
      m_method_DeletePresetMessage;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t,
                                                                                      uint32_t,
                                                                                      uint32_t,
                                                                                      uint32_t,
                                                                                      uint32_t)>>
      m_method_MovePresetMessage;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t,
                                                                                      uint32_t,
                                                                                      uint32_t,
                                                                                      std::string,
                                                                                      uint32_t)>>
      m_method_EditPresetMessage;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t,
                                                         uint32_t,
                                                         int32_t,
                                                         std::tuple<uint32_t, std::vector<std::string>>>(uint32_t,
                                                                                                         uint32_t,
                                                                                                         uint32_t)>>
      m_method_GetPresetMessageList;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t, uint32_t)>>
      m_method_ApplySettings;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t, uint32_t>(uint32_t,
                                                                                                uint32_t,
                                                                                                uint32_t)>>
      m_method_ResetSettings;
  std::shared_ptr<DBus::SignalProxy<void(int32_t, bool)>> m_signalproxy_AutoDownloadChanged;
  std::shared_ptr<DBus::SignalProxy<void(int32_t, bool)>> m_signalproxy_NotifyChanged;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_PresetMessageListChanged;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<int32_t, uint64_t, std::string, std::string>)>>
      m_signalproxy_NewMessage;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::tuple<uint32_t,
                                                               std::vector<std::tuple<int32_t, uint32_t, bool>>>>)>>
      m_signalproxy_NewMessagesInfo;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, int32_t)>> m_signalproxy_Notification;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         int32_t,
                                         std::tuple<bool,
                                                    bool,
                                                    bool,
                                                    uint32_t,
                                                    uint32_t,
                                                    std::vector<std::tuple<int32_t,
                                                                           uint64_t,
                                                                           int32_t,
                                                                           uint32_t,
                                                                           std::string,
                                                                           std::string,
                                                                           std::string>>>)>>
      m_signalproxy_DownloadCompleted;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, int32_t, uint64_t)>> m_signalproxy_MessagePlaybackStatusChanged;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<uint32_t, std::vector<std::tuple<uint16_t, std::string>>>)>>
      m_signalproxy_InstancesDisconnected;
};
#endif /* COM_JCI_BLM_MSG_INTERFACEPROXY_H */
