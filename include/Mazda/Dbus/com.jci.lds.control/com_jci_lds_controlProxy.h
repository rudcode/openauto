#ifndef COM_JCI_LDS_CONTROLPROXY_H
#define COM_JCI_LDS_CONTROLPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_lds_controlProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_lds_controlProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_lds_controlProxy> create(std::string name = "com.jci.lds.control");
  void ReadControl(int32_t command);
  void DRTestScreenRequest(int32_t dRUnitTestScreenRequest);
  DBus::MultipleReturn<bool, bool, int32_t> GetDRUnitStatus_sync();
  DBus::MultipleReturn<int32_t,
                       uint64_t,
                       double,
                       double,
                       int32_t,
                       double,
                       double,
                       double,
                       double,
                       int32_t> GetLastKnownPosition_sync();
  int32_t SetLastKnownPosition_sync(int32_t positionAccuracy,
                                    uint64_t uTCtime,
                                    double latitude,
                                    double longitude,
                                    int32_t altitude,
                                    double heading,
                                    double velocity,
                                    double horizontalAccuracy,
                                    double verticalAccuracy);
  void DRReloadRequest();
  std::shared_ptr<DBus::SignalProxy<void(int32_t, int32_t)>> signal_ReadStatus();
 protected:
  std::shared_ptr<DBus::MethodProxy<void(int32_t)>> m_method_ReadControl;
  std::shared_ptr<DBus::MethodProxy<void(int32_t)>> m_method_DRTestScreenRequest;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<bool, bool, int32_t>()>> m_method_GetDRUnitStatus_sync;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t,
                                                         uint64_t,
                                                         double,
                                                         double,
                                                         int32_t,
                                                         double,
                                                         double,
                                                         double,
                                                         double,
                                                         int32_t>()>> m_method_GetLastKnownPosition_sync;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t,
                                            uint64_t,
                                            double,
                                            double,
                                            int32_t,
                                            double,
                                            double,
                                            double,
                                            double)>> m_method_SetLastKnownPosition_sync;
  std::shared_ptr<DBus::MethodProxy<void()>> m_method_DRReloadRequest;
  std::shared_ptr<DBus::SignalProxy<void(int32_t, int32_t)>> m_signalproxy_ReadStatus;
};
#endif /* COM_JCI_LDS_CONTROLPROXY_H */
