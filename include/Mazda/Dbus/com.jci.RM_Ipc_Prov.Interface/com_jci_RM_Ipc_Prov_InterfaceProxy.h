#ifndef COM_JCI_RM_IPC_PROV_INTERFACEPROXY_H
#define COM_JCI_RM_IPC_PROV_INTERFACEPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_RM_Ipc_Prov_InterfaceProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_RM_Ipc_Prov_InterfaceProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_RM_Ipc_Prov_InterfaceProxy> create(std::string name = "com.jci.RM_Ipc_Prov.Interface");
  DBus::MultipleReturn<int32_t, uint32_t, std::string, uint32_t, uint32_t, uint32_t> Connect(uint32_t in_provPID,
                                                                                             std::string in_provName,
                                                                                             uint32_t in_provConn,
                                                                                             uint32_t in_provContext,
                                                                                             uint32_t in_seqId);
  DBus::MultipleReturn<int32_t, int32_t> PreConnect(uint32_t in_provPID, std::string in_provName);
  DBus::MultipleReturn<int32_t, uint32_t, std::string, uint32_t, uint32_t, uint32_t> Disconnect(bool in_force,
                                                                                                uint32_t in_provPID,
                                                                                                std::string in_provName,
                                                                                                uint32_t in_provConn,
                                                                                                uint32_t in_provContext,
                                                                                                uint32_t in_seqId);
  DBus::MultipleReturn<std::string,
                       int32_t,
                       std::string,
                       uint32_t,
                       uint32_t,
                       uint32_t> RegisterResource(std::string in_resName,
                                                  std::tuple<std::vector<std::tuple<std::string,
                                                                                    int32_t,
                                                                                    std::vector<uint8_t>>>> in_attributes,
                                                  bool in_supportActDeactLogic,
                                                  std::string in_provName,
                                                  uint32_t in_provConn,
                                                  uint32_t in_provContext,
                                                  uint32_t in_seqId);
  DBus::MultipleReturn<std::string,
                       int32_t,
                       std::string,
                       uint32_t,
                       uint32_t,
                       uint32_t> UnregisterResource(std::string in_resName,
                                                    std::tuple<std::vector<std::tuple<std::string,
                                                                                      int32_t,
                                                                                      std::vector<uint8_t>>>> in_attributes,
                                                    bool in_force,
                                                    std::string in_provName,
                                                    uint32_t in_provConn,
                                                    uint32_t in_provContext,
                                                    uint32_t in_seqId);
  int32_t ActivateResourceResponse(std::string in_resName,
                                   std::tuple<std::vector<std::tuple<std::string,
                                                                     int32_t,
                                                                     std::vector<uint8_t>>>> in_attributes,
                                   int32_t in_result,
                                   std::string in_provName,
                                   uint32_t in_provConn);
  int32_t DeactivateResourceResponse(std::string in_resName,
                                     std::tuple<std::vector<std::tuple<std::string,
                                                                       int32_t,
                                                                       std::vector<uint8_t>>>> in_attributes,
                                     int32_t in_result,
                                     std::string in_provName,
                                     uint32_t in_provConn);
  std::shared_ptr<DBus::SignalProxy<void(std::string, std::string, uint32_t, uint32_t)>> signal_activate_resource_cb();
  std::shared_ptr<DBus::SignalProxy<void(std::string,
                                         std::string,
                                         uint32_t,
                                         uint32_t)>> signal_deactivate_resource_cb();
 protected:
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t, std::string, uint32_t, uint32_t, uint32_t>(
      uint32_t,
      std::string,
      uint32_t,
      uint32_t,
      uint32_t)>> m_method_Connect;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, int32_t>(uint32_t, std::string)>> m_method_PreConnect;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t, std::string, uint32_t, uint32_t, uint32_t>(
      bool,
      uint32_t,
      std::string,
      uint32_t,
      uint32_t,
      uint32_t)>> m_method_Disconnect;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::string,
                                                         int32_t,
                                                         std::string,
                                                         uint32_t,
                                                         uint32_t,
                                                         uint32_t>(std::string,
                                                                   std::tuple<std::vector<std::tuple<std::string,
                                                                                                     int32_t,
                                                                                                     std::vector<uint8_t>>>>,
                                                                   bool,
                                                                   std::string,
                                                                   uint32_t,
                                                                   uint32_t,
                                                                   uint32_t)>> m_method_RegisterResource;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::string,
                                                         int32_t,
                                                         std::string,
                                                         uint32_t,
                                                         uint32_t,
                                                         uint32_t>(std::string,
                                                                   std::tuple<std::vector<std::tuple<std::string,
                                                                                                     int32_t,
                                                                                                     std::vector<uint8_t>>>>,
                                                                   bool,
                                                                   std::string,
                                                                   uint32_t,
                                                                   uint32_t,
                                                                   uint32_t)>> m_method_UnregisterResource;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::string,
                                            std::tuple<std::vector<std::tuple<std::string,
                                                                              int32_t,
                                                                              std::vector<uint8_t>>>>,
                                            int32_t,
                                            std::string,
                                            uint32_t)>> m_method_ActivateResourceResponse;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::string,
                                            std::tuple<std::vector<std::tuple<std::string,
                                                                              int32_t,
                                                                              std::vector<uint8_t>>>>,
                                            int32_t,
                                            std::string,
                                            uint32_t)>> m_method_DeactivateResourceResponse;
  std::shared_ptr<DBus::SignalProxy<void(std::string, std::string, uint32_t, uint32_t)>>
      m_signalproxy_activate_resource_cb;
  std::shared_ptr<DBus::SignalProxy<void(std::string, std::string, uint32_t, uint32_t)>>
      m_signalproxy_deactivate_resource_cb;
};
#endif /* COM_JCI_RM_IPC_PROV_INTERFACEPROXY_H */
