#ifndef COM_JCI_RM_IPC_CONS_INTERFACEPROXY_H
#define COM_JCI_RM_IPC_CONS_INTERFACEPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_RM_Ipc_Cons_InterfaceProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_RM_Ipc_Cons_InterfaceProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_RM_Ipc_Cons_InterfaceProxy> create(std::string name = "com.jci.RM_Ipc_Cons.Interface");
  DBus::MultipleReturn<int32_t, uint32_t, std::string, uint32_t, uint32_t, uint32_t> Connect(uint32_t in_consPID,
                                                                                             std::string in_consName,
                                                                                             uint32_t in_consConn,
                                                                                             uint32_t in_consContext,
                                                                                             uint32_t in_seqId);
  DBus::MultipleReturn<int32_t, uint32_t, std::string, uint32_t, uint32_t, uint32_t> Disconnect(uint32_t in_consPID,
                                                                                                std::string in_consName,
                                                                                                uint32_t in_consConn,
                                                                                                uint32_t in_consContext,
                                                                                                uint32_t in_seqId);
  DBus::MultipleReturn<std::string,
                       int32_t,
                       int32_t,
                       std::string,
                       uint32_t,
                       uint32_t,
                       uint32_t> AcquireResource(std::string in_resName,
                                                 int32_t in_action,
                                                 std::string in_consName,
                                                 uint32_t in_consConn,
                                                 uint32_t in_consContext,
                                                 uint32_t in_seqId);
  DBus::MultipleReturn<std::string,
                       int32_t,
                       int32_t,
                       std::string,
                       uint32_t,
                       uint32_t,
                       uint32_t> ReleaseResource(std::string in_resName,
                                                 int32_t in_action,
                                                 std::string in_consName,
                                                 uint32_t in_consConn,
                                                 uint32_t in_consContext,
                                                 uint32_t in_seqId);
  DBus::MultipleReturn<std::string,
                       std::tuple<std::vector<std::tuple<std::string, int32_t, std::vector<uint8_t>>>>,
                       int32_t,
                       int32_t,
                       std::string,
                       uint32_t,
                       uint32_t,
                       uint32_t> GetResourceInfo(std::string in_resName,
                                                 std::string in_consName,
                                                 uint32_t in_consConn,
                                                 uint32_t in_consContext,
                                                 uint32_t in_seqId);
  DBus::MultipleReturn<std::string,
                       int32_t,
                       int32_t,
                       int32_t,
                       std::string,
                       uint32_t,
                       uint32_t,
                       uint32_t> SubscribeForEvent(std::string in_resName,
                                                   int32_t in_status,
                                                   std::string in_consName,
                                                   uint32_t in_consConn,
                                                   uint32_t in_consContext,
                                                   uint32_t in_seqId);
  DBus::MultipleReturn<std::string, int32_t, int32_t, std::string, uint32_t, uint32_t, uint32_t> UnsubscribeFromEvent(
      std::string in_resName,
      int32_t in_status,
      std::string in_consName,
      uint32_t in_consConn,
      uint32_t in_consContext,
      uint32_t in_seqId);
  std::shared_ptr<DBus::SignalProxy<void(std::string,
                                         int32_t,
                                         int32_t,
                                         std::string,
                                         uint32_t,
                                         uint32_t,
                                         uint32_t)>> signal_acquire_resource_cb();
  std::shared_ptr<DBus::SignalProxy<void(std::string, std::string, uint32_t, uint32_t)>> signal_release_command_cb();
  std::shared_ptr<DBus::SignalProxy<void(std::string,
                                         std::tuple<std::vector<std::tuple<std::string,
                                                                           int32_t,
                                                                           std::vector<uint8_t>>>>,
                                         int32_t,
                                         std::string,
                                         uint32_t,
                                         uint32_t)>> signal_resource_event_cb();
 protected:
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t, std::string, uint32_t, uint32_t, uint32_t>(
      uint32_t,
      std::string,
      uint32_t,
      uint32_t,
      uint32_t)>> m_method_Connect;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t, std::string, uint32_t, uint32_t, uint32_t>(
      uint32_t,
      std::string,
      uint32_t,
      uint32_t,
      uint32_t)>> m_method_Disconnect;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::string,
                                                         int32_t,
                                                         int32_t,
                                                         std::string,
                                                         uint32_t,
                                                         uint32_t,
                                                         uint32_t>(std::string,
                                                                   int32_t,
                                                                   std::string,
                                                                   uint32_t,
                                                                   uint32_t,
                                                                   uint32_t)>> m_method_AcquireResource;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::string,
                                                         int32_t,
                                                         int32_t,
                                                         std::string,
                                                         uint32_t,
                                                         uint32_t,
                                                         uint32_t>(std::string,
                                                                   int32_t,
                                                                   std::string,
                                                                   uint32_t,
                                                                   uint32_t,
                                                                   uint32_t)>> m_method_ReleaseResource;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::string,
                                                         std::tuple<std::vector<std::tuple<std::string,
                                                                                           int32_t,
                                                                                           std::vector<uint8_t>>>>,
                                                         int32_t,
                                                         int32_t,
                                                         std::string,
                                                         uint32_t,
                                                         uint32_t,
                                                         uint32_t>(std::string,
                                                                   std::string,
                                                                   uint32_t,
                                                                   uint32_t,
                                                                   uint32_t)>> m_method_GetResourceInfo;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::string,
                                                         int32_t,
                                                         int32_t,
                                                         int32_t,
                                                         std::string,
                                                         uint32_t,
                                                         uint32_t,
                                                         uint32_t>(std::string,
                                                                   int32_t,
                                                                   std::string,
                                                                   uint32_t,
                                                                   uint32_t,
                                                                   uint32_t)>> m_method_SubscribeForEvent;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::string,
                                                         int32_t,
                                                         int32_t,
                                                         std::string,
                                                         uint32_t,
                                                         uint32_t,
                                                         uint32_t>(std::string,
                                                                   int32_t,
                                                                   std::string,
                                                                   uint32_t,
                                                                   uint32_t,
                                                                   uint32_t)>> m_method_UnsubscribeFromEvent;
  std::shared_ptr<DBus::SignalProxy<void(std::string, int32_t, int32_t, std::string, uint32_t, uint32_t, uint32_t)>>
      m_signalproxy_acquire_resource_cb;
  std::shared_ptr<DBus::SignalProxy<void(std::string, std::string, uint32_t, uint32_t)>>
      m_signalproxy_release_command_cb;
  std::shared_ptr<DBus::SignalProxy<void(std::string,
                                         std::tuple<std::vector<std::tuple<std::string,
                                                                           int32_t,
                                                                           std::vector<uint8_t>>>>,
                                         int32_t,
                                         std::string,
                                         uint32_t,
                                         uint32_t)>> m_signalproxy_resource_event_cb;
};
#endif /* COM_JCI_RM_IPC_CONS_INTERFACEPROXY_H */
