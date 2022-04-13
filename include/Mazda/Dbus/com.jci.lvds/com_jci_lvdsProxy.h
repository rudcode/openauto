#ifndef COM_JCI_LVDSPROXY_H
#define COM_JCI_LVDSPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_lvdsProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_lvdsProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_lvdsProxy> create(std::string name = "com.jci.lvds");
  int16_t SetBrightness(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t> brightnessLevel);
  std::string GetSoftwareTPVersion(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t> softwareTPVersion);
  std::string GetSoftwareDispVersion(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t> softwareDispVersion);
  std::string SetNormalMode(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t> normalMode);
  std::string SetSleepMode(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t> sleepMode);
  std::string SetDiagMode(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t> diagMode);
  std::string SetExtendMode(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t> extendMode);
  int16_t SetACCOff(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t> aCCOff);
  int16_t SetDispOn(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t> dispOn);
  int16_t SetDispOff(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t> dispOff);
  std::string EnablePRBS(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t> enablePRBSAutoTest);
  std::string DisablePRBS(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t> disablePRBSAutoTest);
  std::string PRBSReport(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t> pRBSAutoTestReport);
  uint32_t SystemACCMonitoring(uint32_t requestId);
  uint32_t SpeedRestriction(uint32_t requestId);
  uint32_t SetHdcpMode(uint32_t mode);
  uint32_t GetErrorEncounteredStatus();
  uint32_t BlmLvdsReady(uint32_t requestId);
  uint32_t FaultStatusResponse(uint32_t faultId, uint32_t status);
  uint32_t GetDisplayStatus(uint32_t requestId);
  uint32_t GetHdcpState();
  uint32_t SetVideoTuning(std::tuple<uint32_t, uint32_t, uint32_t, uint32_t> videoTuning);
  uint32_t GetTunedValues(uint32_t requestId);
  uint32_t GetRegisterDump(uint32_t regType, bool all, uint8_t start, uint8_t stop);
  uint32_t TouchSimulation(Invalid touchEvents);
  int16_t BrightnessRamp(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t> brightnessLevel);
  uint32_t SetSpreadSpectrum(uint32_t spreadLevel);
  uint32_t SetCMLLevel(uint32_t cMLLevel);
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> signal_brightNessLevelResp();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, std::string>)>> signal_TPVersionResp();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, std::string>)>> signal_displayVersion();
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> signal_NormalModeResp();
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> signal_SleepModeResp();
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> signal_DiagModeResp();
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> signal_ExtendModeResp();
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> signal_EnablePRBSResp();
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> signal_DisablePRBSResp();
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> signal_PRBSReportResp();
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> signal_ACCOffResp();
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> signal_DispOnResp();
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> signal_DispOffResp();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t>)>> signal_CurrentStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t>)>> signal_FaultStatus();
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> signal_ErrorStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_TouchIgnoreStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_ErrorEncounteredAlert();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> signal_DisplayStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_HdcpState();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_HdcpModeStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_VideoTuning();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t, uint32_t, uint32_t>)>> signal_TunedValues();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_RegisterDumpStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_TouchSimulationStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_SpreadSpectrumStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_CMLLevelStatus();
 protected:
  std::shared_ptr<DBus::MethodProxy<int16_t(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t>)>> m_method_SetBrightness;
  std::shared_ptr<DBus::MethodProxy<std::string(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t>)>>
      m_method_GetSoftwareTPVersion;
  std::shared_ptr<DBus::MethodProxy<std::string(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t>)>>
      m_method_GetSoftwareDispVersion;
  std::shared_ptr<DBus::MethodProxy<std::string(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t>)>>
      m_method_SetNormalMode;
  std::shared_ptr<DBus::MethodProxy<std::string(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t>)>>
      m_method_SetSleepMode;
  std::shared_ptr<DBus::MethodProxy<std::string(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t>)>>
      m_method_SetDiagMode;
  std::shared_ptr<DBus::MethodProxy<std::string(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t>)>>
      m_method_SetExtendMode;
  std::shared_ptr<DBus::MethodProxy<int16_t(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t>)>> m_method_SetACCOff;
  std::shared_ptr<DBus::MethodProxy<int16_t(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t>)>> m_method_SetDispOn;
  std::shared_ptr<DBus::MethodProxy<int16_t(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t>)>> m_method_SetDispOff;
  std::shared_ptr<DBus::MethodProxy<std::string(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t>)>> m_method_EnablePRBS;
  std::shared_ptr<DBus::MethodProxy<std::string(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t>)>>
      m_method_DisablePRBS;
  std::shared_ptr<DBus::MethodProxy<std::string(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t>)>> m_method_PRBSReport;
  std::shared_ptr<DBus::MethodProxy<uint32_t(uint32_t)>> m_method_SystemACCMonitoring;
  std::shared_ptr<DBus::MethodProxy<uint32_t(uint32_t)>> m_method_SpeedRestriction;
  std::shared_ptr<DBus::MethodProxy<uint32_t(uint32_t)>> m_method_SetHdcpMode;
  std::shared_ptr<DBus::MethodProxy<uint32_t()>> m_method_GetErrorEncounteredStatus;
  std::shared_ptr<DBus::MethodProxy<uint32_t(uint32_t)>> m_method_BlmLvdsReady;
  std::shared_ptr<DBus::MethodProxy<uint32_t(uint32_t, uint32_t)>> m_method_FaultStatusResponse;
  std::shared_ptr<DBus::MethodProxy<uint32_t(uint32_t)>> m_method_GetDisplayStatus;
  std::shared_ptr<DBus::MethodProxy<uint32_t()>> m_method_GetHdcpState;
  std::shared_ptr<DBus::MethodProxy<uint32_t(std::tuple<uint32_t, uint32_t, uint32_t, uint32_t>)>>
      m_method_SetVideoTuning;
  std::shared_ptr<DBus::MethodProxy<uint32_t(uint32_t)>> m_method_GetTunedValues;
  std::shared_ptr<DBus::MethodProxy<uint32_t(uint32_t, bool, uint8_t, uint8_t)>> m_method_GetRegisterDump;
  std::shared_ptr<DBus::MethodProxy<uint32_t(Invalid)>> m_method_TouchSimulation;
  std::shared_ptr<DBus::MethodProxy<int16_t(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t>)>> m_method_BrightnessRamp;
  std::shared_ptr<DBus::MethodProxy<uint32_t(uint32_t)>> m_method_SetSpreadSpectrum;
  std::shared_ptr<DBus::MethodProxy<uint32_t(uint32_t)>> m_method_SetCMLLevel;
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> m_signalproxy_brightNessLevelResp;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, std::string>)>> m_signalproxy_TPVersionResp;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, std::string>)>> m_signalproxy_displayVersion;
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> m_signalproxy_NormalModeResp;
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> m_signalproxy_SleepModeResp;
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> m_signalproxy_DiagModeResp;
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> m_signalproxy_ExtendModeResp;
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> m_signalproxy_EnablePRBSResp;
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> m_signalproxy_DisablePRBSResp;
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> m_signalproxy_PRBSReportResp;
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> m_signalproxy_ACCOffResp;
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> m_signalproxy_DispOnResp;
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> m_signalproxy_DispOffResp;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t>)>>
      m_signalproxy_CurrentStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t, uint8_t, uint8_t>)>> m_signalproxy_FaultStatus;
  std::shared_ptr<DBus::SignalProxy<void(int16_t)>> m_signalproxy_ErrorStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_TouchIgnoreStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_ErrorEncounteredAlert;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> m_signalproxy_DisplayStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_HdcpState;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_HdcpModeStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_VideoTuning;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t, uint32_t, uint32_t>)>>
      m_signalproxy_TunedValues;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_RegisterDumpStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_TouchSimulationStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_SpreadSpectrumStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_CMLLevelStatus;
};
#endif /* COM_JCI_LVDSPROXY_H */
