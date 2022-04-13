#ifndef COM_JCI_BTECAPROXY_H
#define COM_JCI_BTECAPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_btecaProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_btecaProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_btecaProxy> create(std::string name = "com.jci.bteca");
  int32_t AbortCall();
  int32_t TransferToHandset();
  int32_t TransferFromHandset();
  int32_t BargeIntoCall();
  uint8_t GetBTECAEnabledValue();
  int32_t SetBTECAEnabledValue(uint8_t isBTECAenabled);
  uint8_t IsBTECASupported();
  int32_t RetryEcall();
  int32_t ResetEnableSetting();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_EnabledChange();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_CollisionDetected();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_PhoneFoundStatus();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_CollisionDetectedTimerStart();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_CollisionDetectedTimerExpired();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_CallSuccess();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_CallNotSuccess();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_AudioTransferredToPhone();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_AudioTransferredToCar();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_EndCall();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_EmergencyCallFailure();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_MP911EmergencyCallStatus();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_PhoneBTConnectionLost();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_TransferredToHandset();
  std::shared_ptr<DBus::SignalProxy<void(bool, bool)>> signal_TransferredFromHandset();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_ConnectedTimerStart();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_ShowPSAPInfoInscription();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_SetTransferredValid();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_NotifyCarPlaySession();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_AbortCall;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_TransferToHandset;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_TransferFromHandset;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_BargeIntoCall;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetBTECAEnabledValue;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint8_t)>> m_method_SetBTECAEnabledValue;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_IsBTECASupported;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_RetryEcall;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_ResetEnableSetting;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_EnabledChange;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_CollisionDetected;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_PhoneFoundStatus;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_CollisionDetectedTimerStart;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_CollisionDetectedTimerExpired;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_CallSuccess;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_CallNotSuccess;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_AudioTransferredToPhone;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_AudioTransferredToCar;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_EndCall;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_EmergencyCallFailure;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_MP911EmergencyCallStatus;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_PhoneBTConnectionLost;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_TransferredToHandset;
  std::shared_ptr<DBus::SignalProxy<void(bool, bool)>> m_signalproxy_TransferredFromHandset;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_ConnectedTimerStart;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_ShowPSAPInfoInscription;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_SetTransferredValid;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_NotifyCarPlaySession;
};
#endif /* COM_JCI_BTECAPROXY_H */
