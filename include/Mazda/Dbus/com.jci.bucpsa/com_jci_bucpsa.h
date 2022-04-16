#ifndef COM_JCI_BUCPSA_H
#define COM_JCI_BUCPSA_H

#include <stdint.h>
#include <dbus-cxx.h>
class com_jci_bucpsa {
 public:
  virtual int32_t GetReverseStatus() = 0;
  virtual int32_t DisplayCommand(uint32_t command) = 0;
  virtual DBus::MultipleReturn<uint32_t, int32_t> GetDisplayMode_async() = 0;
  virtual DBus::MultipleReturn<uint32_t, int32_t> GetDisplayMode() = 0;
  virtual int32_t SetPSMEnabled(uint8_t psmEnabled) = 0;
  virtual uint8_t GetPSMInstalledStatus() = 0;
  virtual uint32_t GetSteeringWheelLocation() = 0;
};
#endif /* COM_JCI_BUCPSA_H */
