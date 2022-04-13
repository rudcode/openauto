#ifndef COM_JCI_BLMSYSTEM_INTERFACEPROXY_H
#define COM_JCI_BLMSYSTEM_INTERFACEPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_blmsystem_InterfaceProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_blmsystem_InterfaceProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_blmsystem_InterfaceProxy> create(std::string name = "com.jci.blmsystem.Interface");
  DBus::MultipleReturn<int32_t, uint32_t> OpenConnection();
  int32_t CloseConnection();
  int32_t SafeShutDown();
  int32_t SafeReboot();
  int32_t GenericReboot(int32_t mode_flags);
  int32_t FactoryReset();
  DBus::MultipleReturn<int32_t, int32_t> GetCurrentAccStatus();
  DBus::MultipleReturn<uint32_t, int32_t> GetCurrentSystemState();
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t> RegisterForStateTransitionAck(uint32_t from_state,
                                                                                  uint32_t to_state);
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t> AcknowledgeStateTransition(uint32_t from_state, uint32_t to_state);
  DBus::MultipleReturn<uint32_t, uint32_t, int32_t> UnregisterFromStateTransitionAck(uint32_t from_state,
                                                                                     uint32_t to_state);
  int32_t RegisterForShutdownAck();
  int32_t AcknowledgeShutdown();
  int32_t UnregisterFromShutdownAck();
  DBus::MultipleReturn<int32_t, int32_t, int32_t> SignalSystemStateEvent(int32_t event, int32_t event_info);
  int32_t ReportTestDiagEntering();
  int32_t ReportTestDiagExiting();
  int32_t ReportGuiAvailable();
  int32_t GetFactoryResetNum();
  void ReportXMInstalled(int32_t value);
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> signal_NotifyStateTransition();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_NotifyShutdown();
  std::shared_ptr<DBus::SignalProxy<void(int32_t, uint32_t)>> signal_NotifyAccChange();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> signal_NotifySystemStateChange();
 protected:
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t>()>> m_method_OpenConnection;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_CloseConnection;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_SafeShutDown;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_SafeReboot;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_GenericReboot;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_FactoryReset;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, int32_t>()>> m_method_GetCurrentAccStatus;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, int32_t>()>> m_method_GetCurrentSystemState;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t, uint32_t)>>
      m_method_RegisterForStateTransitionAck;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t, uint32_t)>>
      m_method_AcknowledgeStateTransition;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t, int32_t>(uint32_t, uint32_t)>>
      m_method_UnregisterFromStateTransitionAck;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_RegisterForShutdownAck;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_AcknowledgeShutdown;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_UnregisterFromShutdownAck;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, int32_t, int32_t>(int32_t, int32_t)>>
      m_method_SignalSystemStateEvent;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_ReportTestDiagEntering;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_ReportTestDiagExiting;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_ReportGuiAvailable;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetFactoryResetNum;
  std::shared_ptr<DBus::MethodProxy<void(int32_t)>> m_method_ReportXMInstalled;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> m_signalproxy_NotifyStateTransition;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_NotifyShutdown;
  std::shared_ptr<DBus::SignalProxy<void(int32_t, uint32_t)>> m_signalproxy_NotifyAccChange;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> m_signalproxy_NotifySystemStateChange;
};
#endif /* COM_JCI_BLMSYSTEM_INTERFACEPROXY_H */
