#ifndef COM_JCI_BCAPROXY_H
#define COM_JCI_BCAPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_bcaProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_bcaProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_bcaProxy> create(std::string name = "com.jci.bca");
  int32_t ConnectRequest(uint32_t serviceId, uint32_t btDeviceId);
  int32_t ConnectRequestHfpAndAvp(uint32_t btDeviceId);
  int32_t DisconnectRequest(uint32_t serviceId, uint32_t btDeviceId);
  int32_t DisconnectRequestHfpAndAvp(uint32_t btHfpDeviceId, uint32_t btAvpDeviceId);
  int32_t CancelConnect(bool cancelConnect);
  int32_t GetConnectStatus(uint32_t serviceId);
  std::tuple<int32_t,
             int32_t,
             int32_t,
             int32_t,
             std::tuple<std::vector<uint8_t>>> QueryConnectStatus(uint32_t serviceId);
  int32_t UnbarDevice(uint32_t btDeviceId);
  int32_t BluetoothOn(bool isInfoToBeUpdatedToFlash);
  int32_t BluetoothOff(bool isInfoToBeUpdatedToFlash);
  int32_t StartAdd(uint32_t addServiceId);
  int32_t ConnectAll(uint32_t btDeviceId);
  int32_t DisconnectAll();
  int32_t GetServiceId(uint32_t serviceType);
  int32_t ReadBluetoothSetting();
  int32_t AvailablePairedDeviceList();
  DBus::MultipleReturn<int32_t, int32_t> GetFeatureStatus();
  int32_t SupportedProfiles(uint32_t btDeviceId);
  int32_t SetDontShowOnConnectionSetting(uint32_t btDeviceId, bool setting);
  int32_t GetDontShowOnConnectionSetting(uint32_t btDeviceId);
  int32_t AAutoEnableBtResponse(uint32_t select);
  int32_t AAutoNoEntryAvailableResponse(uint32_t select);
  int32_t PairingStatus(uint32_t status, uint32_t error);
  int32_t DeviceDeleteStatus(uint32_t deleteStatus);
  int32_t CallStatus(uint32_t bthfstate, uint32_t call1status, uint32_t call2status);
  int32_t SetCommSettingsResetStatus(uint32_t status);
  int32_t SetMP911EmergencyCallStatus(uint32_t status);
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, bool)>> signal_DontShowOnConnectionSettingStatusResp();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         uint32_t,
                                         uint32_t,
                                         uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_ConnectionStatusResp();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t, uint32_t)>> signal_HftReadyStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> signal_ReadyStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> signal_AddStatusResp();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> signal_DeviceUnbarringStatusResp();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_DeviceBluetoothSettingResp();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_AvailablePairedListResp();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> signal_SupportedProfilesResp();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_FirstHfpSupportedInfo();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> signal_CarPlayConnectionStatus();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_AAutoEnableBt();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_AAutoNoEntryAvailable();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_ReqStartAndroidAutoPairing();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_ReqStopAndroidAutoPairing();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_ReqDeleteDevice();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_AAPairingSeqResult();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_AndroidAutoPairingTimeout();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_RequestStartAutoDownload();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_DisableBluetoothRsp();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_ConnectingCarPlayError();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t)>> m_method_ConnectRequest;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_ConnectRequestHfpAndAvp;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t)>> m_method_DisconnectRequest;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t)>> m_method_DisconnectRequestHfpAndAvp;
  std::shared_ptr<DBus::MethodProxy<int32_t(bool)>> m_method_CancelConnect;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_GetConnectStatus;
  std::shared_ptr<DBus::MethodProxy<std::tuple<int32_t, int32_t, int32_t, int32_t, std::tuple<std::vector<uint8_t>>>(
      uint32_t)>> m_method_QueryConnectStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_UnbarDevice;
  std::shared_ptr<DBus::MethodProxy<int32_t(bool)>> m_method_BluetoothOn;
  std::shared_ptr<DBus::MethodProxy<int32_t(bool)>> m_method_BluetoothOff;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_StartAdd;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_ConnectAll;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_DisconnectAll;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_GetServiceId;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_ReadBluetoothSetting;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_AvailablePairedDeviceList;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, int32_t>()>> m_method_GetFeatureStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_SupportedProfiles;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, bool)>> m_method_SetDontShowOnConnectionSetting;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_GetDontShowOnConnectionSetting;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_AAutoEnableBtResponse;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_AAutoNoEntryAvailableResponse;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t)>> m_method_PairingStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_DeviceDeleteStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t, uint32_t)>> m_method_CallStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_SetCommSettingsResetStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_SetMP911EmergencyCallStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, bool)>> m_signalproxy_DontShowOnConnectionSettingStatusResp;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t, uint32_t, uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_ConnectionStatusResp;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t, uint32_t)>> m_signalproxy_HftReadyStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> m_signalproxy_ReadyStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> m_signalproxy_AddStatusResp;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> m_signalproxy_DeviceUnbarringStatusResp;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_DeviceBluetoothSettingResp;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_AvailablePairedListResp;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> m_signalproxy_SupportedProfilesResp;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_FirstHfpSupportedInfo;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> m_signalproxy_CarPlayConnectionStatus;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_AAutoEnableBt;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_AAutoNoEntryAvailable;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_ReqStartAndroidAutoPairing;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_ReqStopAndroidAutoPairing;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_ReqDeleteDevice;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_AAPairingSeqResult;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_AndroidAutoPairingTimeout;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_RequestStartAutoDownload;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_DisableBluetoothRsp;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_ConnectingCarPlayError;
};
#endif /* COM_JCI_BCAPROXY_H */
