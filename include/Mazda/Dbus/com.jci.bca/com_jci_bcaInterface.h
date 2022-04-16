#ifndef COM_JCI_BCAINTERFACE_H
#define COM_JCI_BCAINTERFACE_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include <tuple>
#include <vector>
#include "com_jci_bca.h"
class com_jci_bcaInterface
    : public DBus::Interface {
 private:
  com_jci_bcaInterface(com_jci_bca *adaptee, std::string name);
 public:
  static std::shared_ptr<com_jci_bcaInterface> create(com_jci_bca *adaptee, std::string name = "com.jci.bca");
  std::shared_ptr<DBus::Signal<void(uint32_t, bool)>> signal_DontShowOnConnectionSettingStatusResp();
  void DontShowOnConnectionSettingStatusResp(uint32_t btDeviceId, bool setting);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    uint32_t,
                                    uint32_t,
                                    uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_ConnectionStatusResp();
  void ConnectionStatusResp(uint32_t serviceId,
                            uint32_t connStatus,
                            uint32_t btDeviceId,
                            uint32_t status,
                            std::tuple<std::vector<uint8_t>> terminalPath);
  std::shared_ptr<DBus::Signal<void(uint32_t, uint32_t, uint32_t)>> signal_HftReadyStatus();
  void HftReadyStatus(uint32_t hftReady, uint32_t reasonCode, uint32_t appId);
  std::shared_ptr<DBus::Signal<void(uint32_t, uint32_t)>> signal_ReadyStatus();
  void ReadyStatus(uint32_t isReady, uint32_t reasonCode);
  std::shared_ptr<DBus::Signal<void(uint32_t, uint32_t)>> signal_AddStatusResp();
  void AddStatusResp(uint32_t addServiceId, uint32_t status);
  std::shared_ptr<DBus::Signal<void(uint32_t, uint32_t)>> signal_DeviceUnbarringStatusResp();
  void DeviceUnbarringStatusResp(uint32_t btDeviceId, uint32_t status);
  std::shared_ptr<DBus::Signal<void(bool)>> signal_DeviceBluetoothSettingResp();
  void DeviceBluetoothSettingResp(bool btSetting);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_AvailablePairedListResp();
  void AvailablePairedListResp(uint32_t totalPairedDevices, std::tuple<std::vector<uint8_t>> pairedDeviceList);
  std::shared_ptr<DBus::Signal<void(std::tuple<std::vector<uint8_t>>)>> signal_SupportedProfilesResp();
  void SupportedProfilesResp(std::tuple<std::vector<uint8_t>> supportedProfiles);
  std::shared_ptr<DBus::Signal<void(bool)>> signal_FirstHfpSupportedInfo();
  void FirstHfpSupportedInfo(bool isHfpSupportedDevicePresent);
  std::shared_ptr<DBus::Signal<void(uint32_t, uint32_t)>> signal_CarPlayConnectionStatus();
  void CarPlayConnectionStatus(uint32_t connStatus, uint32_t carPlayDeviceId);
  std::shared_ptr<DBus::Signal<void()>> signal_AAutoEnableBt();
  void AAutoEnableBt();
  std::shared_ptr<DBus::Signal<void(uint32_t)>> signal_AAutoNoEntryAvailable();
  void AAutoNoEntryAvailable(uint32_t deleteDeviceId);
  std::shared_ptr<DBus::Signal<void()>> signal_ReqStartAndroidAutoPairing();
  void ReqStartAndroidAutoPairing();
  std::shared_ptr<DBus::Signal<void()>> signal_ReqStopAndroidAutoPairing();
  void ReqStopAndroidAutoPairing();
  std::shared_ptr<DBus::Signal<void(uint32_t)>> signal_ReqDeleteDevice();
  void ReqDeleteDevice(uint32_t deleteDeviceId);
  std::shared_ptr<DBus::Signal<void(bool)>> signal_AAPairingSeqResult();
  void AAPairingSeqResult(bool result);
  std::shared_ptr<DBus::Signal<void()>> signal_AndroidAutoPairingTimeout();
  void AndroidAutoPairingTimeout();
  std::shared_ptr<DBus::Signal<void(uint32_t)>> signal_RequestStartAutoDownload();
  void RequestStartAutoDownload(uint32_t btDeviceId);
  std::shared_ptr<DBus::Signal<void(uint32_t)>> signal_DisableBluetoothRsp();
  void DisableBluetoothRsp(uint32_t activeCallStatus);
  std::shared_ptr<DBus::Signal<void()>> signal_ConnectingCarPlayError();
  void ConnectingCarPlayError();
 protected:
  std::shared_ptr<DBus::Signal<void(uint32_t, bool)>> m_signal_DontShowOnConnectionSettingStatusResp;
  std::shared_ptr<DBus::Signal<void(uint32_t, uint32_t, uint32_t, uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_ConnectionStatusResp;
  std::shared_ptr<DBus::Signal<void(uint32_t, uint32_t, uint32_t)>> m_signal_HftReadyStatus;
  std::shared_ptr<DBus::Signal<void(uint32_t, uint32_t)>> m_signal_ReadyStatus;
  std::shared_ptr<DBus::Signal<void(uint32_t, uint32_t)>> m_signal_AddStatusResp;
  std::shared_ptr<DBus::Signal<void(uint32_t, uint32_t)>> m_signal_DeviceUnbarringStatusResp;
  std::shared_ptr<DBus::Signal<void(bool)>> m_signal_DeviceBluetoothSettingResp;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_AvailablePairedListResp;
  std::shared_ptr<DBus::Signal<void(std::tuple<std::vector<uint8_t>>)>> m_signal_SupportedProfilesResp;
  std::shared_ptr<DBus::Signal<void(bool)>> m_signal_FirstHfpSupportedInfo;
  std::shared_ptr<DBus::Signal<void(uint32_t, uint32_t)>> m_signal_CarPlayConnectionStatus;
  std::shared_ptr<DBus::Signal<void()>> m_signal_AAutoEnableBt;
  std::shared_ptr<DBus::Signal<void(uint32_t)>> m_signal_AAutoNoEntryAvailable;
  std::shared_ptr<DBus::Signal<void()>> m_signal_ReqStartAndroidAutoPairing;
  std::shared_ptr<DBus::Signal<void()>> m_signal_ReqStopAndroidAutoPairing;
  std::shared_ptr<DBus::Signal<void(uint32_t)>> m_signal_ReqDeleteDevice;
  std::shared_ptr<DBus::Signal<void(bool)>> m_signal_AAPairingSeqResult;
  std::shared_ptr<DBus::Signal<void()>> m_signal_AndroidAutoPairingTimeout;
  std::shared_ptr<DBus::Signal<void(uint32_t)>> m_signal_RequestStartAutoDownload;
  std::shared_ptr<DBus::Signal<void(uint32_t)>> m_signal_DisableBluetoothRsp;
  std::shared_ptr<DBus::Signal<void()>> m_signal_ConnectingCarPlayError;
};
#endif /* COM_JCI_BCAINTERFACE_H */
