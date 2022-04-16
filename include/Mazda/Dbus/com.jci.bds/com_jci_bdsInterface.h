#ifndef COM_JCI_BDSINTERFACE_H
#define COM_JCI_BDSINTERFACE_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include <tuple>
#include <vector>
#include "com_jci_bds.h"
class com_jci_bdsInterface
    : public DBus::Interface {
 private:
  com_jci_bdsInterface(com_jci_bds *adaptee, std::string name);
 public:
  static std::shared_ptr<com_jci_bdsInterface> create(com_jci_bds *adaptee, std::string name = "com.jci.bds");
  std::shared_ptr<DBus::Signal<void(uint32_t)>> signal_Signaltest_cb();
  void Signaltest_cb(uint32_t type);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalReady_cb();
  void SignalReady_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalNotReady_cb();
  void SignalNotReady_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceDeleteInProgress_cb();
  void SignalDeviceDeleteInProgress_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceDeleted_cb();
  void SignalDeviceDeleted_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceDeleteAllInProgress_cb();
  void SignalDeviceDeleteAllInProgress_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceDeleteAll_cb();
  void SignalDeviceDeleteAll_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceDisconnectedAll_cb();
  void SignalDeviceDisconnectedAll_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceDisconnectionProgress_cb();
  void SignalDeviceDisconnectionProgress_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceInquiryResult_cb();
  void SignalDeviceInquiryResult_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceNameStarted_cb();
  void SignalDeviceNameStarted_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceNameSet_cb();
  void SignalDeviceNameSet_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceNameGet_cb();
  void SignalDeviceNameGet_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceAccessibilityGet_cb();
  void SignalDeviceAccessibilityGet_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalDevicePair_cb();
  void SignalDevicePair_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceServiceDiscovery_cb();
  void SignalDeviceServiceDiscovery_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceWrittenAll_cb();
  void SignalDeviceWrittenAll_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceAuthenticate_cb();
  void SignalDeviceAuthenticate_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalRemoteSupportedFeatures_cb();
  void SignalRemoteSupportedFeatures_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceGetConnectedDevices_cb();
  void SignalDeviceGetConnectedDevices_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceLocalOobData_cb();
  void SignalDeviceLocalOobData_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceExtendedSearchResult_cb();
  void SignalDeviceExtendedSearchResult_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalServiceEnableStatus_cb();
  void SignalServiceEnableStatus_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalServiceDisableStatus_cb();
  void SignalServiceDisableStatus_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalConnected_cb();
  void SignalConnected_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalDisconnected_cb();
  void SignalDisconnected_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalServiceFeatures_cb();
  void SignalServiceFeatures_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalServiceConfiguration_cb();
  void SignalServiceConfiguration_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkAppChange_cb();
  void SignalAudioSinkAppChange_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkBatteryStatusChange_cb();
  void SignalAudioSinkBatteryStatusChange_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkBiased_cb();
  void SignalAudioSinkBiased_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkBrowseConnect_cb();
  void SignalAudioSinkBrowseConnect_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkBrowseDisonnect_cb();
  void SignalAudioSinkBrowseDisonnect_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkBrowseFolderChange_cb();
  void SignalAudioSinkBrowseFolderChange_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkBrowseFolderContent_cb();
  void SignalAudioSinkBrowseFolderContent_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkBrowseFolderContents_cb();
  void SignalAudioSinkBrowseFolderContents_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkBrowseSearch_cb();
  void SignalAudioSinkBrowseSearch_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkBrowseUidsChange_cb();
  void SignalAudioSinkBrowseUidsChange_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkContentAddToNowPlaying_cb();
  void SignalAudioSinkContentAddToNowPlaying_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkContentAttributes_cb();
  void SignalAudioSinkContentAttributes_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkContentPlay_cb();
  void SignalAudioSinkContentPlay_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkMediaPosition_cb();
  void SignalAudioSinkMediaPosition_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkPanelOperation_cb();
  void SignalAudioSinkPanelOperation_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkPlaybackStatusChange_cb();
  void SignalAudioSinkPlaybackStatusChange_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkPlayerAddressedChange_cb();
  void SignalAudioSinkPlayerAddressedChange_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkPlayerBrowsedChange_cb();
  void SignalAudioSinkPlayerBrowsedChange_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkPlayerItem_cb();
  void SignalAudioSinkPlayerItem_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkPlayerItems_cb();
  void SignalAudioSinkPlayerItems_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkPlayerItemsChange_cb();
  void SignalAudioSinkPlayerItemsChange_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkPlayerNowContentChange_cb();
  void SignalAudioSinkPlayerNowContentChange_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkPlayerVolumeChange_cb();
  void SignalAudioSinkPlayerVolumeChange_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkStreamClosed_cb();
  void SignalAudioSinkStreamClosed_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkStreamConfigured_cb();
  void SignalAudioSinkStreamConfigured_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkStreamLine_cb();
  void SignalAudioSinkStreamLine_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkStreamMuted_cb();
  void SignalAudioSinkStreamMuted_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkStreamOpened_cb();
  void SignalAudioSinkStreamOpened_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkSupportedChanges_cb();
  void SignalAudioSinkSupportedChanges_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkSupportedPlayerSetting_cb();
  void SignalAudioSinkSupportedPlayerSetting_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkSystemStatusChange_cb();
  void SignalAudioSinkSystemStatusChange_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkTrackChange_cb();
  void SignalAudioSinkTrackChange_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkTrackEnd_cb();
  void SignalAudioSinkTrackEnd_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkTrackMetaData_cb();
  void SignalAudioSinkTrackMetaData_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkTrackStart_cb();
  void SignalAudioSinkTrackStart_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientCallList_cb();
  void SignalCallClientCallList_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientStatus_cb();
  void SignalCallClientStatus_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientAudioConnect_cb();
  void SignalCallClientAudioConnect_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientAudioDisconnect_cb();
  void SignalCallClientAudioDisconnect_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientIndicator_cb();
  void SignalCallClientIndicator_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientOperator_cb();
  void SignalCallClientOperator_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientSubscriber_cb();
  void SignalCallClientSubscriber_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientMicVolumeChange_cb();
  void SignalCallClientMicVolumeChange_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientSpeakerVolumeChange_cb();
  void SignalCallClientSpeakerVolumeChange_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientActivateVoiceDial_cb();
  void SignalCallClientActivateVoiceDial_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientDeActivateVoiceDial_cb();
  void SignalCallClientDeActivateVoiceDial_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientSiriSupportStatus_cb();
  void SignalCallClientSiriSupportStatus_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientSiriEyesFreeMode_cb();
  void SignalCallClientSiriEyesFreeMode_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientSiriDisableNoiseReduction_cb();
  void SignalCallClientSiriDisableNoiseReduction_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalPhoneStatus_cb();
  void SignalPhoneStatus_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientCmdError_cb();
  void SignalCallClientCmdError_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientScoCodecId_cb();
  void SignalCallClientScoCodecId_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalMessageClientConfigured_cb();
  void SignalMessageClientConfigured_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalMessageClientFolderListing_cb();
  void SignalMessageClientFolderListing_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalMessageClientMessageDeleted_cb();
  void SignalMessageClientMessageDeleted_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalMessageClientMessageGotten_cb();
  void SignalMessageClientMessageGotten_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalMessageClientMessageListing_cb();
  void SignalMessageClientMessageListing_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalMessageClientMessageNotification_cb();
  void SignalMessageClientMessageNotification_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalMessageClientMessagePushed_cb();
  void SignalMessageClientMessagePushed_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalMessageClientMessageSetStatus_cb();
  void SignalMessageClientMessageSetStatus_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalNetworkClientConnected_cb();
  void SignalNetworkClientConnected_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalNetworkClientDisconnected_cb();
  void SignalNetworkClientDisconnected_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalPimClientImportStatus_cb();
  void SignalPimClientImportStatus_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalFileServerInfoEvent_cb();
  void SignalFileServerInfoEvent_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalFileServerFileAcceptanceStatus_cb();
  void SignalFileServerFileAcceptanceStatus_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalFileServerDataFileInProgressStatus_cb();
  void SignalFileServerDataFileInProgressStatus_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalServiceLessAudioConnectStatus_cb();
  void SignalServiceLessAudioConnectStatus_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalServiceLessAudioDisconnectStatus_cb();
  void SignalServiceLessAudioDisconnectStatus_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalServiceLessAclConnectStatus_cb();
  void SignalServiceLessAclConnectStatus_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t,
                                    std::tuple<std::vector<uint8_t>>)>> signal_SignalServiceLessAclDisconnectStatus_cb();
  void SignalServiceLessAclDisconnectStatus_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalBTChipFailure_cb();
  void SignalBTChipFailure_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceAddressGet_cb();
  void SignalDeviceAddressGet_cb(uint32_t type, std::tuple<std::vector<uint8_t>> data);
 protected:
  std::shared_ptr<DBus::Signal<void(uint32_t)>> m_signal_Signaltest_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalReady_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalNotReady_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalDeviceDeleteInProgress_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalDeviceDeleted_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalDeviceDeleteAllInProgress_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalDeviceDeleteAll_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalDeviceDisconnectedAll_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalDeviceDisconnectionProgress_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalDeviceInquiryResult_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalDeviceNameStarted_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalDeviceNameSet_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalDeviceNameGet_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalDeviceAccessibilityGet_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalDevicePair_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalDeviceServiceDiscovery_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalDeviceWrittenAll_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalDeviceAuthenticate_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalRemoteSupportedFeatures_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalDeviceGetConnectedDevices_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalDeviceLocalOobData_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalDeviceExtendedSearchResult_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalServiceEnableStatus_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalServiceDisableStatus_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalConnected_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalDisconnected_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalServiceFeatures_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalServiceConfiguration_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalAudioSinkAppChange_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkBatteryStatusChange_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalAudioSinkBiased_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkBrowseConnect_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkBrowseDisonnect_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkBrowseFolderChange_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkBrowseFolderContent_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkBrowseFolderContents_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkBrowseSearch_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkBrowseUidsChange_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkContentAddToNowPlaying_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkContentAttributes_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkContentPlay_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkMediaPosition_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkPanelOperation_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkPlaybackStatusChange_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkPlayerAddressedChange_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkPlayerBrowsedChange_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalAudioSinkPlayerItem_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkPlayerItems_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkPlayerItemsChange_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkPlayerNowContentChange_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkPlayerVolumeChange_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkStreamClosed_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkStreamConfigured_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalAudioSinkStreamLine_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkStreamMuted_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkStreamOpened_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkSupportedChanges_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkSupportedPlayerSetting_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkSystemStatusChange_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkTrackChange_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalAudioSinkTrackEnd_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalAudioSinkTrackMetaData_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalAudioSinkTrackStart_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalCallClientCallList_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalCallClientStatus_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalCallClientAudioConnect_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalCallClientAudioDisconnect_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalCallClientIndicator_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalCallClientOperator_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalCallClientSubscriber_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalCallClientMicVolumeChange_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalCallClientSpeakerVolumeChange_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalCallClientActivateVoiceDial_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalCallClientDeActivateVoiceDial_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalCallClientSiriSupportStatus_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalCallClientSiriEyesFreeMode_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalCallClientSiriDisableNoiseReduction_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalPhoneStatus_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalCallClientCmdError_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalCallClientScoCodecId_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalMessageClientConfigured_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalMessageClientFolderListing_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalMessageClientMessageDeleted_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalMessageClientMessageGotten_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalMessageClientMessageListing_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalMessageClientMessageNotification_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalMessageClientMessagePushed_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalMessageClientMessageSetStatus_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalNetworkClientConnected_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalNetworkClientDisconnected_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalPimClientImportStatus_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalFileServerInfoEvent_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalFileServerFileAcceptanceStatus_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalFileServerDataFileInProgressStatus_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalServiceLessAudioConnectStatus_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalServiceLessAudioDisconnectStatus_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalServiceLessAclConnectStatus_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signal_SignalServiceLessAclDisconnectStatus_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalBTChipFailure_cb;
  std::shared_ptr<DBus::Signal<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signal_SignalDeviceAddressGet_cb;
};
#endif /* COM_JCI_BDSINTERFACE_H */
