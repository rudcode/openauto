#ifndef COM_JCI_LDS_CONTROL_H
#define COM_JCI_LDS_CONTROL_H

#include <stdint.h>
#include <dbus-cxx.h>
class com_jci_lds_control {
 public:
  virtual void ReadControl(int32_t command) = 0;
  virtual void DRTestScreenRequest(int32_t dRUnitTestScreenRequest) = 0;
  virtual DBus::MultipleReturn<bool, bool, int32_t> GetDRUnitStatus_sync() = 0;
  virtual DBus::MultipleReturn<int32_t,
                               uint64_t,
                               double,
                               double,
                               int32_t,
                               double,
                               double,
                               double,
                               double,
                               int32_t> GetLastKnownPosition_sync() = 0;
  virtual int32_t SetLastKnownPosition_sync(int32_t positionAccuracy,
                                            uint64_t uTCtime,
                                            double latitude,
                                            double longitude,
                                            int32_t altitude,
                                            double heading,
                                            double velocity,
                                            double horizontalAccuracy,
                                            double verticalAccuracy) = 0;
  virtual void DRReloadRequest() = 0;
};
#endif /* COM_JCI_LDS_CONTROL_H */
