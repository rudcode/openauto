#ifndef COM_JCI_ITTSPROXY_H
#define COM_JCI_ITTSPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_ittsProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_ittsProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_ittsProxy> create(std::string name = "com.jci.itts");
  DBus::MultipleReturn<std::tuple<std::vector<std::tuple<uint32_t, uint32_t, int32_t>>, uint32_t>,
                       int32_t> RequestMemoryInfo(std::tuple<std::vector<uint32_t>> devIdList);
  DBus::MultipleReturn<int32_t, std::tuple<std::vector<std::tuple<uint32_t, uint32_t, int32_t>>, uint32_t>> StoreTag(
      uint32_t tagMaxCntFlash,
      std::tuple<std::vector<uint32_t>> devIdList);
  DBus::MultipleReturn<int32_t,
                       std::tuple<std::vector<std::tuple<uint32_t, uint32_t, uint32_t>>,
                                  uint32_t,
                                  uint32_t>> TransferTag(uint32_t tagMaxCntiPod,
                                                         std::tuple<std::vector<uint32_t>> devIdList);
  int32_t RadioConnectionStatus(uint8_t connectStandbyStat);
  int32_t RadioModeChange(int32_t modeChangeSrc);
  int32_t RadioOnOff(uint8_t radioOnOffStatus);
  int32_t RadioStationChange(uint16_t frequency);
  int32_t RadioTrackChange(uint8_t trackChange);
  int32_t UpdateMetadata(std::tuple<std::vector<uint8_t>> tagInfo);
  DBus::MultipleReturn<uint32_t, int32_t> ClearNVM(uint32_t tagsToClearCnt);
  int32_t CheckConnDev();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, std::string, int32_t, uint32_t>,
                                         bool)>> signal_AppleDevConnected();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_AppleDevDisconnected();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_TaggingAvailable();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_TaggingErrorDevice();
 protected:
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::tuple<std::vector<std::tuple<uint32_t,
                                                                                           uint32_t,
                                                                                           int32_t>>, uint32_t>,
                                                         int32_t>(std::tuple<std::vector<uint32_t>>)>>
      m_method_RequestMemoryInfo;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t,
                                                         std::tuple<std::vector<std::tuple<uint32_t,
                                                                                           uint32_t,
                                                                                           int32_t>>, uint32_t>>(
      uint32_t,
      std::tuple<std::vector<uint32_t>>)>> m_method_StoreTag;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t,
                                                         std::tuple<std::vector<std::tuple<uint32_t,
                                                                                           uint32_t,
                                                                                           uint32_t>>,
                                                                    uint32_t,
                                                                    uint32_t>>(uint32_t,
                                                                               std::tuple<std::vector<uint32_t>>)>>
      m_method_TransferTag;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint8_t)>> m_method_RadioConnectionStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_RadioModeChange;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint8_t)>> m_method_RadioOnOff;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint16_t)>> m_method_RadioStationChange;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint8_t)>> m_method_RadioTrackChange;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::tuple<std::vector<uint8_t>>)>> m_method_UpdateMetadata;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, int32_t>(uint32_t)>> m_method_ClearNVM;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_CheckConnDev;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, std::string, int32_t, uint32_t>, bool)>>
      m_signalproxy_AppleDevConnected;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_AppleDevDisconnected;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_TaggingAvailable;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_TaggingErrorDevice;
};
#endif /* COM_JCI_ITTSPROXY_H */
