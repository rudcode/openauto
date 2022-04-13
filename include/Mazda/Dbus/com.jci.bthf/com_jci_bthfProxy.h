#ifndef COM_JCI_BTHFPROXY_H
#define COM_JCI_BTHFPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_bthfProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_bthfProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_bthfProxy> create(std::string name = "com.jci.bthf");
  int32_t Dial(std::tuple<std::vector<uint8_t>> dialNumber, bool dialPrompt);
  int32_t EmergencyDial(std::tuple<std::vector<uint8_t>> dialNumber);
  int32_t Redial();
  int32_t HangupCall();
  int32_t RejectCall();
  int32_t AcceptCall();
  int32_t MuteCall();
  int32_t UnmuteCall();
  int32_t SwapCall();
  int32_t HeldCall();
  int32_t UnHeldCall();
  int32_t JoinCall();
  int32_t TransferCall(int32_t transferType);
  int32_t SendDtmf(std::tuple<std::vector<uint8_t>> dtmfDigits);
  int32_t StartPhoneVr();
  int32_t StopPhoneVr();
  int32_t StartBargein();
  int32_t StopBargein();
  int32_t CallSettings(uint32_t isIncallAutoXferEnabled,
                       uint32_t isOutCallAutoXferEnabled,
                       uint32_t isActiveCallAutoXferEnabled);
  int32_t RingToneSettings(uint32_t ringToneTypeSupported);
  int32_t AutoAnswerSettings(uint32_t autoAnswerValue);
  int32_t RampupRingToneSettings(uint32_t isRampUpRingToneSupported);
  int32_t DoNotDisturbSettings(uint32_t isDoNotDisturbEnabled);
  int32_t QueryCallStatus();
  int32_t EmergencyCallStart();
  int32_t EmergencyCallStop();
  int32_t GetBthfSettingData();
  int32_t ResetBthfCommunicationSettings();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         uint32_t,
                                         uint32_t,
                                         std::tuple<std::vector<uint8_t>>,
                                         std::tuple<std::vector<uint8_t>>)>> signal_CallStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t, uint32_t)>> signal_BatteryIndicator();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t, uint32_t)>> signal_SignalStrength();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_RoamIndicator();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_NewServiceIndicator();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_PhoneChargeIndicator();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_SmsPresentIndicator();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_VoiceMailIndicator();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_LowBatteryIndicator();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> signal_BthfReadyStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_BthfBusyReason();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_MicStatus();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_BargeinStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> signal_BthfSettingsResponse();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_FailureReasonCodes();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t(std::tuple<std::vector<uint8_t>>, bool)>> m_method_Dial;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::tuple<std::vector<uint8_t>>)>> m_method_EmergencyDial;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Redial;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_HangupCall;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_RejectCall;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_AcceptCall;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_MuteCall;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_UnmuteCall;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_SwapCall;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_HeldCall;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_UnHeldCall;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_JoinCall;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_TransferCall;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::tuple<std::vector<uint8_t>>)>> m_method_SendDtmf;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_StartPhoneVr;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_StopPhoneVr;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_StartBargein;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_StopBargein;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t, uint32_t)>> m_method_CallSettings;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_RingToneSettings;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_AutoAnswerSettings;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_RampupRingToneSettings;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_DoNotDisturbSettings;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_QueryCallStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_EmergencyCallStart;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_EmergencyCallStop;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetBthfSettingData;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_ResetBthfCommunicationSettings;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         uint32_t,
                                         uint32_t,
                                         std::tuple<std::vector<uint8_t>>,
                                         std::tuple<std::vector<uint8_t>>)>> m_signalproxy_CallStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t, uint32_t)>> m_signalproxy_BatteryIndicator;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t, uint32_t)>> m_signalproxy_SignalStrength;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_RoamIndicator;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_NewServiceIndicator;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_PhoneChargeIndicator;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_SmsPresentIndicator;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_VoiceMailIndicator;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_LowBatteryIndicator;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> m_signalproxy_BthfReadyStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_BthfBusyReason;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_MicStatus;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_BargeinStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> m_signalproxy_BthfSettingsResponse;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_FailureReasonCodes;
};
#endif /* COM_JCI_BTHFPROXY_H */
