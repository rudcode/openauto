#ifndef COM_JCI_LDS_DATAPROXY_H
#define COM_JCI_LDS_DATAPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_lds_dataProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_lds_dataProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_lds_dataProxy> create(std::string name = "com.jci.lds.data");
  DBus::MultipleReturn<int32_t, uint64_t, double, double, int32_t, double, double, double, double> GetPosition();
  DBus::MultipleReturn<uint64_t, double, double> GetLastKnownPosition();
  std::string GetGPSFirmwareVersion();
  int32_t GetSatelliteInfo();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t)>> signal_GPSDiagnostics();
  std::shared_ptr<DBus::SignalProxy<void(std::string, int32_t, bool, bool, bool, bool)>> signal_OneTimeDRDiagnostics();
  std::shared_ptr<DBus::SignalProxy<void(int32_t,
                                         int32_t,
                                         bool,
                                         int32_t,
                                         int32_t,
                                         int32_t)>> signal_PeriodicDRDiagnostics();
 protected:
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t,
                                                         uint64_t,
                                                         double,
                                                         double,
                                                         int32_t,
                                                         double,
                                                         double,
                                                         double,
                                                         double>()>> m_method_GetPosition;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint64_t, double, double>()>> m_method_GetLastKnownPosition;
  std::shared_ptr<DBus::MethodProxy<std::string()>> m_method_GetGPSFirmwareVersion;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetSatelliteInfo;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t)>> m_signalproxy_GPSDiagnostics;
  std::shared_ptr<DBus::SignalProxy<void(std::string, int32_t, bool, bool, bool, bool)>>
      m_signalproxy_OneTimeDRDiagnostics;
  std::shared_ptr<DBus::SignalProxy<void(int32_t, int32_t, bool, int32_t, int32_t, int32_t)>>
      m_signalproxy_PeriodicDRDiagnostics;
};
#endif /* COM_JCI_LDS_DATAPROXY_H */
