#ifndef COM_JCI_TESTDIAGPROXY_H
#define COM_JCI_TESTDIAGPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_testdiagProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_testdiagProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_testdiagProxy> create(std::string name = "com.jci.testdiag");
  int32_t StartRoutine(uint8_t test_id);
  int32_t ActivateTestMode();
  int32_t DeactivateTestMode();
  int32_t CommanderInput(int16_t buttont_id, int16_t buttont_value);
  int32_t StopCommanderRoutine();
  std::tuple<uint32_t, std::vector<std::tuple<uint32_t, std::vector<uint8_t>>>> GetTestInfo();
  int32_t ActivateJCITestMode();
  int32_t DeactivateJCITestModeMode();
  int32_t NotifyDiagLostFocus();
  uint32_t GetDiagStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::string,
                                         std::tuple<uint32_t, std::vector<uint8_t>>,
                                         std::tuple<int32_t, std::vector<uint8_t>>,
                                         Invalid,
                                         bool,
                                         bool)>> signal_TestRoutineStatus_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_NotifyTestMode_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> signal_SystemError_Response();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_DVD_SpeedRestriction_Enable();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t(uint8_t)>> m_method_StartRoutine;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_ActivateTestMode;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_DeactivateTestMode;
  std::shared_ptr<DBus::MethodProxy<int32_t(int16_t, int16_t)>> m_method_CommanderInput;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_StopCommanderRoutine;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t, std::vector<std::tuple<uint32_t, std::vector<uint8_t>>>>()>>
      m_method_GetTestInfo;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_ActivateJCITestMode;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_DeactivateJCITestModeMode;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_NotifyDiagLostFocus;
  std::shared_ptr<DBus::MethodProxy<uint32_t()>> m_method_GetDiagStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::string,
                                         std::tuple<uint32_t, std::vector<uint8_t>>,
                                         std::tuple<int32_t, std::vector<uint8_t>>,
                                         Invalid,
                                         bool,
                                         bool)>> m_signalproxy_TestRoutineStatus_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_NotifyTestMode_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> m_signalproxy_SystemError_Response;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_DVD_SpeedRestriction_Enable;
};
#endif /* COM_JCI_TESTDIAGPROXY_H */
