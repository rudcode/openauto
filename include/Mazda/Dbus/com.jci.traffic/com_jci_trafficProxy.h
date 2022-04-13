#ifndef COM_JCI_TRAFFICPROXY_H
#define COM_JCI_TRAFFICPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_trafficProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_trafficProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_trafficProxy> create(std::string name = "com.jci.traffic");
  int32_t SetNewMapUpdateEnable_async(uint32_t enable);
  int32_t SetMapInFocus_async(uint32_t focus);
  int32_t GetGpsInfo_async();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t, uint32_t)>> signal_BGColorInfo();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_NewTrafficMap();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<std::tuple<uint32_t,
                                                                           std::string>>>)>> signal_MapUpdate();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t, int32_t, uint32_t>)>> signal_GpsInfoUpdate();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_LockedToStation();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_ApplicationStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_LastTileUpdatedTime();
  std::shared_ptr<DBus::SignalProxy<void(std::string)>> signal_TestModeText();
  std::shared_ptr<DBus::SignalProxy<void(double, int32_t)>> signal_VICSFrequencyChangeAck();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_SetNewMapUpdateEnable_async;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_SetMapInFocus_async;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetGpsInfo_async;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t, uint32_t)>> m_signalproxy_BGColorInfo;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_NewTrafficMap;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<std::tuple<uint32_t, std::string>>>)>>
      m_signalproxy_MapUpdate;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t, int32_t, uint32_t>)>> m_signalproxy_GpsInfoUpdate;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_LockedToStation;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_ApplicationStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_LastTileUpdatedTime;
  std::shared_ptr<DBus::SignalProxy<void(std::string)>> m_signalproxy_TestModeText;
  std::shared_ptr<DBus::SignalProxy<void(double, int32_t)>> m_signalproxy_VICSFrequencyChangeAck;
};
#endif /* COM_JCI_TRAFFICPROXY_H */
