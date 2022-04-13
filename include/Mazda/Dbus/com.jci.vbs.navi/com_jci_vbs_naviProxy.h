#ifndef COM_JCI_VBS_NAVIPROXY_H
#define COM_JCI_VBS_NAVIPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_vbs_naviProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_vbs_naviProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_vbs_naviProxy> create(std::string name = "com.jci.vbs.navi");
  uint8_t GetFuelType();
  uint8_t GetHUDStatus();
  uint8_t GetTSRStatus();
  uint8_t GetTSRMode();
  uint8_t TMCServiceListReq(uint8_t tmcSrvceLstReq);
  uint8_t TMCSelectReq(std::tuple<uint8_t, uint8_t, uint8_t, uint8_t, uint8_t> tmcSelectReq);
  uint8_t SetHUDDisplayMsgReq(std::tuple<uint32_t, uint16_t, uint8_t, uint16_t, uint8_t, uint8_t> hudDisplayMsg);
  uint8_t SetRecommLaneReq(std::tuple<std::vector<uint8_t>> hudRecommLaneInfo);
  uint8_t SetTSRNavigationSignal(std::tuple<uint8_t, bool, bool, uint8_t> tsrNavigation);
  std::string GetVINData();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_FuelTypeResp();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_HUDResp();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_TSRResp();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> signal_GccConfigMgmtResp();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_TSRFeatureMode();
 protected:
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetFuelType;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetHUDStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetTSRStatus;
  std::shared_ptr<DBus::MethodProxy<uint8_t()>> m_method_GetTSRMode;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_TMCServiceListReq;
  std::shared_ptr<DBus::MethodProxy<uint8_t(std::tuple<uint8_t, uint8_t, uint8_t, uint8_t, uint8_t>)>>
      m_method_TMCSelectReq;
  std::shared_ptr<DBus::MethodProxy<uint8_t(std::tuple<uint32_t, uint16_t, uint8_t, uint16_t, uint8_t, uint8_t>)>>
      m_method_SetHUDDisplayMsgReq;
  std::shared_ptr<DBus::MethodProxy<uint8_t(std::tuple<std::vector<uint8_t>>)>> m_method_SetRecommLaneReq;
  std::shared_ptr<DBus::MethodProxy<uint8_t(std::tuple<uint8_t, bool, bool, uint8_t>)>> m_method_SetTSRNavigationSignal;
  std::shared_ptr<DBus::MethodProxy<std::string()>> m_method_GetVINData;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_FuelTypeResp;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_HUDResp;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_TSRResp;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> m_signalproxy_GccConfigMgmtResp;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_TSRFeatureMode;
};
#endif /* COM_JCI_VBS_NAVIPROXY_H */
