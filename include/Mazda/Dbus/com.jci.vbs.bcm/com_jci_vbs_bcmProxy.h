#ifndef COM_JCI_VBS_BCMPROXY_H
#define COM_JCI_VBS_BCMPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_vbs_bcmProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_vbs_bcmProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_vbs_bcmProxy> create(std::string name = "com.jci.vbs.bcm");
  uint32_t GetCarSpeed(uint32_t speedUnit);
  uint8_t GetCarSpeedThrshld(uint8_t speedUnit);
  uint8_t GetPSMInfo();
  std::tuple<bool, bool, uint8_t, uint8_t, uint8_t, bool, bool, bool, bool, bool, bool, uint8_t, uint8_t> GetBSMInfo();
  uint8_t getEngineTransmissionType();
  uint8_t GetIgnitionStatus();
  uint8_t GetPublicCanStatus();
  uint8_t GetPrivateCanStatus();
  uint8_t GetNoSpeedRestrict_TouchDisplay();
  uint8_t GetTouchDisplayCarSpeedThrshld(uint8_t speedUnit);
  uint8_t GetFuelCutOffStatus();
  uint8_t GetBrkPedalDepressedStatus();
  uint8_t GetGearPos();
  uint8_t GetTransmChangeLeverPosition();
  uint8_t GetPrkBrkActv();
  std::tuple<std::vector<uint8_t>> GetPASCD();
  std::tuple<uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint64_t> GetWheelSpeed();
  uint8_t GetVideoRestrict();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_CarSpeedResp();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_CarSpeedThresholdNotification();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_AccidentTriggerNotifiction();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t>)>> signal_PSM_Information1();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<bool,
                                                    bool,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    bool,
                                                    bool,
                                                    bool,
                                                    bool,
                                                    bool,
                                                    bool,
                                                    uint8_t,
                                                    uint8_t>)>> signal_BSM_Information();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_PublicCanStatusNotification();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_PrivateCanStatusNotification();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, std::tuple<uint8_t>)>> signal_engineConfigResp();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_IgnitionControl_Status();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_NoSpeedRestrict_TouchDisplay();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_BatteryVoltageFlag();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_BrakePedalDepressedStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_GearPosNotification();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_TransmChangeLeverPositionNotification();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_PrkBrkActvNotification();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> signal_PASCDNotification();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint16_t,
                                                    uint16_t,
                                                    uint16_t,
                                                    uint16_t,
                                                    uint16_t,
                                                    uint16_t,
                                                    uint64_t>)>> signal_WheelSpeedNotification();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_VideoRestrictNotification();
 protected:
  std::shared_ptr<DBus::MethodProxy<uint32_t(uint32_t)>> m_method_GetCarSpeed;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_GetCarSpeedThrshld;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetPSMInfo;
  std::shared_ptr<DBus::MethodProxy<std::tuple<bool,
                                               bool,
                                               uint8_t,
                                               uint8_t,
                                               uint8_t,
                                               bool,
                                               bool,
                                               bool,
                                               bool,
                                               bool,
                                               bool,
                                               uint8_t,
                                               uint8_t>()>> m_method_GetBSMInfo;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_getEngineTransmissionType;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetIgnitionStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetPublicCanStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetPrivateCanStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetNoSpeedRestrict_TouchDisplay;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_GetTouchDisplayCarSpeedThrshld;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetFuelCutOffStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetBrkPedalDepressedStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetGearPos;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetTransmChangeLeverPosition;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetPrkBrkActv;
  std::shared_ptr<DBus::MethodProxy<std::tuple<std::vector<uint8_t>>()>> m_method_GetPASCD;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint64_t>()>>
      m_method_GetWheelSpeed;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetVideoRestrict;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_CarSpeedResp;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_CarSpeedThresholdNotification;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_AccidentTriggerNotifiction;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t>)>> m_signalproxy_PSM_Information1;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<bool,
                                                    bool,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    bool,
                                                    bool,
                                                    bool,
                                                    bool,
                                                    bool,
                                                    bool,
                                                    uint8_t,
                                                    uint8_t>)>> m_signalproxy_BSM_Information;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_PublicCanStatusNotification;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_PrivateCanStatusNotification;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, std::tuple<uint8_t>)>> m_signalproxy_engineConfigResp;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_IgnitionControl_Status;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_NoSpeedRestrict_TouchDisplay;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_BatteryVoltageFlag;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_BrakePedalDepressedStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_GearPosNotification;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_TransmChangeLeverPositionNotification;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_PrkBrkActvNotification;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> m_signalproxy_PASCDNotification;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint16_t,
                                                    uint16_t,
                                                    uint16_t,
                                                    uint16_t,
                                                    uint16_t,
                                                    uint16_t,
                                                    uint64_t>)>> m_signalproxy_WheelSpeedNotification;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_VideoRestrictNotification;
};
#endif /* COM_JCI_VBS_BCMPROXY_H */
