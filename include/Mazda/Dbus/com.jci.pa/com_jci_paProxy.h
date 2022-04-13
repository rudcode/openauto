#ifndef COM_JCI_PAPROXY_H
#define COM_JCI_PAPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_paProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_paProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_paProxy> create(std::string name = "com.jci.pa");
  int32_t StartPair(uint32_t pairMode);
  int32_t AbortPair(uint32_t abortMode);
  int32_t PairToSelectedDevice(std::tuple<std::vector<uint8_t>> btaddress);
  int32_t PairNumericCompResponse(bool isPassecodeMatched);
  int32_t DeleteDevice(uint32_t deviceId);
  int32_t DeleteAllDevices();
  int32_t RequestSearchDeviceList();
  int32_t GetPairingPinCode();
  int32_t SetPairingPinCode(std::tuple<std::vector<uint8_t>> pinCode);
  int32_t GetPairingModuleSettings();
  int32_t RetrieveVehicleBtInfo();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> signal_HftReadyStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> signal_PairingStatusResp();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> signal_DeleteStatusResp();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         uint32_t,
                                         uint32_t,
                                         std::tuple<std::vector<uint8_t>>,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SearchedDeviceListResp();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_RequestedSearchListResp();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_AuthenticationResp();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> signal_PairingPinCodeResp();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> signal_PairingModuleResp();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> signal_VehicleBtInformationResp();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_StartPair;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_AbortPair;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::tuple<std::vector<uint8_t>>)>> m_method_PairToSelectedDevice;
  std::shared_ptr<DBus::MethodProxy<int32_t(bool)>> m_method_PairNumericCompResponse;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_DeleteDevice;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_DeleteAllDevices;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_RequestSearchDeviceList;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetPairingPinCode;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::tuple<std::vector<uint8_t>>)>> m_method_SetPairingPinCode;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetPairingModuleSettings;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_RetrieveVehicleBtInfo;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> m_signalproxy_HftReadyStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> m_signalproxy_PairingStatusResp;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> m_signalproxy_DeleteStatusResp;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         uint32_t,
                                         uint32_t,
                                         std::tuple<std::vector<uint8_t>>,
                                         std::tuple<std::vector<uint8_t>>)>> m_signalproxy_SearchedDeviceListResp;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_RequestedSearchListResp;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_AuthenticationResp;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> m_signalproxy_PairingPinCodeResp;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> m_signalproxy_PairingModuleResp;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> m_signalproxy_VehicleBtInformationResp;
};
#endif /* COM_JCI_PAPROXY_H */
