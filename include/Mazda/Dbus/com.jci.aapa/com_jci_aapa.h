#ifndef COM_JCI_AAPA_H
#define COM_JCI_AAPA_H

#include <stdint.h>
#include <string>
#include <tuple>
#include <dbus-cxx.h>
class com_jci_aapa {
 public:
  virtual void MDSettingModeData(uint32_t selectMode) = 0;
  virtual void VideoProjectionEventToMD(uint32_t videoProjectionEvent) = 0;
  virtual void InputKey(uint32_t keyCode, bool absolute, int32_t step) = 0;
  virtual void SetRouteState(uint32_t state) = 0;
  virtual DBus::MultipleReturn<std::tuple<uint8_t, std::string, std::string, std::string, std::string>,
                               int32_t> GetNowPlayingInfo() = 0;
  virtual void BTPairingResult(bool result) = 0;
  virtual void BTReadyToPair(bool alreadyPaired) = 0;
  virtual void SendBTAuthenticationData(std::string btdata, uint32_t len) = 0;
  virtual void SetVehicleBtMacAddress(std::string macaddr, uint32_t maclen) = 0;
  virtual void NotifyBTHFCallStatus(bool status, std::string macaddr) = 0;
  virtual void IntentPhoneCall(std::string phonenumber) = 0;
  virtual void DialogWinkStatus(bool status) = 0;
  virtual void ClearLastFocus(std::tuple<bool, bool> focusInfo) = 0;
  virtual void SbnStatus(bool status) = 0;
  virtual DBus::MultipleReturn<bool, std::string, uint32_t> GetAOASessionStatus() = 0;
  virtual uint8_t GetAvailable() = 0;
  virtual std::tuple<int32_t> SetNativeTurnByTurnStatus(std::tuple<bool> setNativeTurnByTurnStatus) = 0;
  virtual int32_t SetMP911EmergencyCallStatus(uint32_t status) = 0;
};
#endif /* COM_JCI_AAPA_H */
