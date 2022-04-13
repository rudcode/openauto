#ifndef COM_JCI_TDSPROXY_H
#define COM_JCI_TDSPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_tdsProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_tdsProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_tdsProxy> create(std::string name = "com.jci.tds");
  int32_t STM_Set_ProcessMode_async(uint32_t processMode);
  DBus::MultipleReturn<std::tuple<std::vector<std::tuple<int32_t, std::string>>>,
                       int32_t> STM_GetTMIFile(int32_t mapID);
  int32_t ARTEXP_HDStationExit_async(double oldFrequency);
  int32_t ARTEXP_HDStationEnter_async(double newFrequency);
  int32_t ARTEXP_HDSubStationExit_async();
  int32_t ARTEXP_GetStationLogo_async(uint32_t serviceNumber, double frequency);
  int32_t ARTEXP_GetAlbumArt_async(uint32_t serviceNumber, double frequency, uint32_t lotId);
  int32_t ExecuteTestCase(uint32_t testCaseID);
  std::shared_ptr<DBus::SignalProxy<void(uint16_t, uint16_t, uint16_t, uint16_t)>> signal_TMC8A();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_STM_TrafficEvent();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_STM_StationId();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_STM_RemoveTmt();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, double, bool)>> signal_ARTEXP_StationLogo();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, double, uint32_t, bool)>> signal_ARTEXP_AlbumArt();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_STM_TileElapseTimeUpdate();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_STM_Set_ProcessMode_async;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::tuple<std::vector<std::tuple<int32_t, std::string>>>,
                                                         int32_t>(int32_t)>> m_method_STM_GetTMIFile;
  std::shared_ptr<DBus::MethodProxy<int32_t(double)>> m_method_ARTEXP_HDStationExit_async;
  std::shared_ptr<DBus::MethodProxy<int32_t(double)>> m_method_ARTEXP_HDStationEnter_async;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_ARTEXP_HDSubStationExit_async;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, double)>> m_method_ARTEXP_GetStationLogo_async;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, double, uint32_t)>> m_method_ARTEXP_GetAlbumArt_async;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_ExecuteTestCase;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t, uint16_t, uint16_t, uint16_t)>> m_signalproxy_TMC8A;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_STM_TrafficEvent;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_STM_StationId;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_STM_RemoveTmt;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, double, bool)>> m_signalproxy_ARTEXP_StationLogo;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, double, uint32_t, bool)>> m_signalproxy_ARTEXP_AlbumArt;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_STM_TileElapseTimeUpdate;
};
#endif /* COM_JCI_TDSPROXY_H */
