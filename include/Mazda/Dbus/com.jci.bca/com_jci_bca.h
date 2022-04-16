#ifndef COM_JCI_BCA_H
#define COM_JCI_BCA_H

#include <stdint.h>
#include <tuple>
#include <vector>
#include <dbus-cxx.h>
class com_jci_bca {
 public:
  virtual int32_t ConnectRequest(uint32_t serviceId, uint32_t btDeviceId) = 0;
  virtual int32_t ConnectRequestHfpAndAvp(uint32_t btDeviceId) = 0;
  virtual int32_t DisconnectRequest(uint32_t serviceId, uint32_t btDeviceId) = 0;
  virtual int32_t DisconnectRequestHfpAndAvp(uint32_t btHfpDeviceId, uint32_t btAvpDeviceId) = 0;
  virtual int32_t CancelConnect(bool cancelConnect) = 0;
  virtual int32_t GetConnectStatus(uint32_t serviceId) = 0;
  virtual std::tuple<int32_t,
                     int32_t,
                     int32_t,
                     int32_t,
                     std::tuple<std::vector<uint8_t>>> QueryConnectStatus(uint32_t serviceId) = 0;
  virtual int32_t UnbarDevice(uint32_t btDeviceId) = 0;
  virtual int32_t BluetoothOn(bool isInfoToBeUpdatedToFlash) = 0;
  virtual int32_t BluetoothOff(bool isInfoToBeUpdatedToFlash) = 0;
  virtual int32_t StartAdd(uint32_t addServiceId) = 0;
  virtual int32_t ConnectAll(uint32_t btDeviceId) = 0;
  virtual int32_t DisconnectAll() = 0;
  virtual int32_t GetServiceId(uint32_t serviceType) = 0;
  virtual int32_t ReadBluetoothSetting() = 0;
  virtual int32_t AvailablePairedDeviceList() = 0;
  virtual DBus::MultipleReturn<int32_t, int32_t> GetFeatureStatus() = 0;
  virtual int32_t SupportedProfiles(uint32_t btDeviceId) = 0;
  virtual int32_t SetDontShowOnConnectionSetting(uint32_t btDeviceId, bool setting) = 0;
  virtual int32_t GetDontShowOnConnectionSetting(uint32_t btDeviceId) = 0;
  virtual int32_t AAutoEnableBtResponse(uint32_t select) = 0;
  virtual int32_t AAutoNoEntryAvailableResponse(uint32_t select) = 0;
  virtual int32_t PairingStatus(uint32_t status, uint32_t error) = 0;
  virtual int32_t DeviceDeleteStatus(uint32_t deleteStatus) = 0;
  virtual int32_t CallStatus(uint32_t bthfstate, uint32_t call1status, uint32_t call2status) = 0;
  virtual int32_t SetCommSettingsResetStatus(uint32_t status) = 0;
  virtual int32_t SetMP911EmergencyCallStatus(uint32_t status) = 0;
};
#endif /* COM_JCI_BCA_H */
