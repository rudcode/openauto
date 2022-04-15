#ifndef COM_JCI_AAPAINTERFACE_H
#define COM_JCI_AAPAINTERFACE_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include <tuple>
#include "com_jci_aapa.h"
class com_jci_aapaInterface
    : public DBus::Interface {
 private:
  com_jci_aapaInterface(com_jci_aapa *adaptee, std::string name);
 public:
  static std::shared_ptr<com_jci_aapaInterface> create(com_jci_aapa *adaptee, std::string name = "com.jci.aapa");
  std::shared_ptr<DBus::Signal<void(bool)>> signal_AOASessionStatus();
  void AOASessionStatus(bool enable);
  std::shared_ptr<DBus::Signal<void(std::string)>> signal_SendSessionInfo();
  void SendSessionInfo(std::string deviceName);
  std::shared_ptr<DBus::Signal<void(uint32_t)>> signal_VideoProjectionRequestFromMD();
  void VideoProjectionRequestFromMD(uint32_t enable);
  std::shared_ptr<DBus::Signal<void(std::tuple<uint8_t,
                                               std::string,
                                               std::string,
                                               std::string,
                                               std::string>)>> signal_NowPlayingInfo();
  void NowPlayingInfo(std::tuple<uint8_t, std::string, std::string, std::string, std::string> nowPlayingInfo);
  std::shared_ptr<DBus::Signal<void(bool)>> signal_MDModeDisplayFirstDialog();
  void MDModeDisplayFirstDialog(bool displayFirstDialog);
  std::shared_ptr<DBus::Signal<void(bool)>> signal_DisplayReconnectingDialog();
  void DisplayReconnectingDialog(bool enable);
  std::shared_ptr<DBus::Signal<void()>> signal_StartBtConnection();
  void StartBtConnection();
  std::shared_ptr<DBus::Signal<void(std::string, uint32_t, bool)>> signal_BTPairingRequest();
  void BTPairingRequest(std::string macaddr, uint32_t maclen, bool method);
  std::shared_ptr<DBus::Signal<void()>> signal_GetVehicleBtMacAddress();
  void GetVehicleBtMacAddress();
  std::shared_ptr<DBus::Signal<void(bool)>> signal_NotifySpeedThreshold();
  void NotifySpeedThreshold(bool enable);
  std::shared_ptr<DBus::Signal<void(uint32_t)>> signal_DisplaySbnInfo();
  void DisplaySbnInfo(uint32_t info);
  std::shared_ptr<DBus::Signal<void(uint32_t)>> signal_NotifyAudioFocusStatus();
  void NotifyAudioFocusStatus(uint32_t status);
  std::shared_ptr<DBus::Signal<void(bool)>> signal_NotifyBTConnectionComplete();
  void NotifyBTConnectionComplete(bool enable);
  std::shared_ptr<DBus::Signal<void(uint8_t)>> signal_Available();
  void Available(uint8_t available);
  std::shared_ptr<DBus::Signal<void(uint32_t)>> signal_NotifyStopAndSetup();
  void NotifyStopAndSetup(uint32_t displaySASDialog);
  std::shared_ptr<DBus::Signal<void(bool)>> signal_NotifyNoVideoSinkSetup();
  void NotifyNoVideoSinkSetup(bool displayNVSSDialog);
  std::shared_ptr<DBus::Signal<void(bool)>> signal_NotifyDeviceNotResponding();
  void NotifyDeviceNotResponding(bool displayDNR);
  std::shared_ptr<DBus::Signal<void(bool)>> signal_NotifyASRStatus();
  void NotifyASRStatus(bool enable);
  std::shared_ptr<DBus::Signal<void(bool)>> signal_ProjectionStatusResult();
  void ProjectionStatusResult(bool enable);
  std::shared_ptr<DBus::Signal<void(bool)>> signal_DisplayStopForSetupDialog();
  void DisplayStopForSetupDialog(bool enable);
  std::shared_ptr<DBus::Signal<void(int32_t)>> signal_NotifyAANaviStatus();
  void NotifyAANaviStatus(int32_t status);
  std::shared_ptr<DBus::Signal<void()>> signal_GetNativeTurnByTurnStatusRequest();
  void GetNativeTurnByTurnStatusRequest();
  std::shared_ptr<DBus::Signal<void(bool)>> signal_NotifyDeviceConnection();
  void NotifyDeviceConnection(bool status);
 protected:
  std::shared_ptr<DBus::Signal<void(bool)>> m_signal_AOASessionStatus;
  std::shared_ptr<DBus::Signal<void(std::string)>> m_signal_SendSessionInfo;
  std::shared_ptr<DBus::Signal<void(uint32_t)>> m_signal_VideoProjectionRequestFromMD;
  std::shared_ptr<DBus::Signal<void(std::tuple<uint8_t, std::string, std::string, std::string, std::string>)>>
      m_signal_NowPlayingInfo;
  std::shared_ptr<DBus::Signal<void(bool)>> m_signal_MDModeDisplayFirstDialog;
  std::shared_ptr<DBus::Signal<void(bool)>> m_signal_DisplayReconnectingDialog;
  std::shared_ptr<DBus::Signal<void()>> m_signal_StartBtConnection;
  std::shared_ptr<DBus::Signal<void(std::string, uint32_t, bool)>> m_signal_BTPairingRequest;
  std::shared_ptr<DBus::Signal<void()>> m_signal_GetVehicleBtMacAddress;
  std::shared_ptr<DBus::Signal<void(bool)>> m_signal_NotifySpeedThreshold;
  std::shared_ptr<DBus::Signal<void(uint32_t)>> m_signal_DisplaySbnInfo;
  std::shared_ptr<DBus::Signal<void(uint32_t)>> m_signal_NotifyAudioFocusStatus;
  std::shared_ptr<DBus::Signal<void(bool)>> m_signal_NotifyBTConnectionComplete;
  std::shared_ptr<DBus::Signal<void(uint8_t)>> m_signal_Available;
  std::shared_ptr<DBus::Signal<void(uint32_t)>> m_signal_NotifyStopAndSetup;
  std::shared_ptr<DBus::Signal<void(bool)>> m_signal_NotifyNoVideoSinkSetup;
  std::shared_ptr<DBus::Signal<void(bool)>> m_signal_NotifyDeviceNotResponding;
  std::shared_ptr<DBus::Signal<void(bool)>> m_signal_NotifyASRStatus;
  std::shared_ptr<DBus::Signal<void(bool)>> m_signal_ProjectionStatusResult;
  std::shared_ptr<DBus::Signal<void(bool)>> m_signal_DisplayStopForSetupDialog;
  std::shared_ptr<DBus::Signal<void(int32_t)>> m_signal_NotifyAANaviStatus;
  std::shared_ptr<DBus::Signal<void()>> m_signal_GetNativeTurnByTurnStatusRequest;
  std::shared_ptr<DBus::Signal<void(bool)>> m_signal_NotifyDeviceConnection;
};
#endif /* COM_JCI_AAPAINTERFACE_H */
