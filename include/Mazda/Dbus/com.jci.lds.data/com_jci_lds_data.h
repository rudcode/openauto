#ifndef COM_JCI_LDS_DATA_H
#define COM_JCI_LDS_DATA_H

#include <stdint.h>
#include <string>
#include <dbus-cxx.h>
class com_jci_lds_data {
 public:
  virtual DBus::MultipleReturn<int32_t,
                               uint64_t,
                               double,
                               double,
                               int32_t,
                               double,
                               double,
                               double,
                               double> GetPosition() = 0;
  virtual DBus::MultipleReturn<uint64_t, double, double> GetLastKnownPosition() = 0;
  virtual std::string GetGPSFirmwareVersion() = 0;
  virtual int32_t GetSatelliteInfo() = 0;
};
#endif /* COM_JCI_LDS_DATA_H */
