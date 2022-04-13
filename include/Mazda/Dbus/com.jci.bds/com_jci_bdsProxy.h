#ifndef COM_JCI_BDSPROXY_H
#define COM_JCI_BDSPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_bdsProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_bdsProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_bdsProxy> create(std::string name = "com.jci.bds");
  uint32_t SendCommand(uint32_t type, std::tuple<std::vector<uint8_t>> data);
  void TestMethod(uint32_t type);
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_Signaltest_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalReady_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalNotReady_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceDeleteInProgress_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceDeleted_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceDeleteAllInProgress_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceDeleteAll_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceDisconnectedAll_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceDisconnectionProgress_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceInquiryResult_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceNameStarted_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceNameSet_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceNameGet_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceAccessibilityGet_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalDevicePair_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceServiceDiscovery_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceWrittenAll_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceAuthenticate_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalRemoteSupportedFeatures_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceGetConnectedDevices_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceLocalOobData_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceExtendedSearchResult_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalServiceEnableStatus_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalServiceDisableStatus_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalConnected_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalDisconnected_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalServiceFeatures_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalServiceConfiguration_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkAppChange_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkBatteryStatusChange_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkBiased_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkBrowseConnect_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkBrowseDisonnect_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkBrowseFolderChange_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkBrowseFolderContent_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkBrowseFolderContents_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkBrowseSearch_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkBrowseUidsChange_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkContentAddToNowPlaying_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkContentAttributes_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkContentPlay_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkMediaPosition_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkPanelOperation_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkPlaybackStatusChange_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkPlayerAddressedChange_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkPlayerBrowsedChange_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkPlayerItem_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkPlayerItems_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkPlayerItemsChange_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkPlayerNowContentChange_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkPlayerVolumeChange_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkStreamClosed_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkStreamConfigured_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkStreamLine_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkStreamMuted_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkStreamOpened_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkSupportedChanges_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkSupportedPlayerSetting_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkSystemStatusChange_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkTrackChange_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkTrackEnd_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkTrackMetaData_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalAudioSinkTrackStart_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientCallList_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientStatus_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientAudioConnect_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientAudioDisconnect_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientIndicator_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientOperator_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientSubscriber_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientMicVolumeChange_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientSpeakerVolumeChange_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientActivateVoiceDial_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientDeActivateVoiceDial_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientSiriSupportStatus_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientSiriEyesFreeMode_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientSiriDisableNoiseReduction_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalPhoneStatus_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientCmdError_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalCallClientScoCodecId_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalMessageClientConfigured_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalMessageClientFolderListing_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalMessageClientMessageDeleted_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalMessageClientMessageGotten_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalMessageClientMessageListing_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalMessageClientMessageNotification_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalMessageClientMessagePushed_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalMessageClientMessageSetStatus_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalNetworkClientConnected_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalNetworkClientDisconnected_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalPimClientImportStatus_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalFileServerInfoEvent_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalFileServerFileAcceptanceStatus_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalFileServerDataFileInProgressStatus_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalServiceLessAudioConnectStatus_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalServiceLessAudioDisconnectStatus_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalServiceLessAclConnectStatus_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalServiceLessAclDisconnectStatus_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> signal_SignalBTChipFailure_cb();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t,
                                         std::tuple<std::vector<uint8_t>>)>> signal_SignalDeviceAddressGet_cb();
 protected:
  std::shared_ptr<DBus::MethodProxy<uint32_t(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_method_SendCommand;
  std::shared_ptr<DBus::MethodProxy<void(uint32_t)>> m_method_TestMethod;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_Signaltest_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signalproxy_SignalReady_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signalproxy_SignalNotReady_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalDeviceDeleteInProgress_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalDeviceDeleted_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalDeviceDeleteAllInProgress_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalDeviceDeleteAll_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalDeviceDisconnectedAll_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalDeviceDisconnectionProgress_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalDeviceInquiryResult_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalDeviceNameStarted_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalDeviceNameSet_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalDeviceNameGet_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalDeviceAccessibilityGet_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalDevicePair_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalDeviceServiceDiscovery_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalDeviceWrittenAll_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalDeviceAuthenticate_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalRemoteSupportedFeatures_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalDeviceGetConnectedDevices_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalDeviceLocalOobData_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalDeviceExtendedSearchResult_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalServiceEnableStatus_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalServiceDisableStatus_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>> m_signalproxy_SignalConnected_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalDisconnected_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalServiceFeatures_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalServiceConfiguration_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkAppChange_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkBatteryStatusChange_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkBiased_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkBrowseConnect_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkBrowseDisonnect_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkBrowseFolderChange_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkBrowseFolderContent_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkBrowseFolderContents_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkBrowseSearch_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkBrowseUidsChange_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkContentAddToNowPlaying_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkContentAttributes_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkContentPlay_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkMediaPosition_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkPanelOperation_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkPlaybackStatusChange_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkPlayerAddressedChange_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkPlayerBrowsedChange_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkPlayerItem_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkPlayerItems_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkPlayerItemsChange_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkPlayerNowContentChange_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkPlayerVolumeChange_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkStreamClosed_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkStreamConfigured_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkStreamLine_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkStreamMuted_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkStreamOpened_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkSupportedChanges_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkSupportedPlayerSetting_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkSystemStatusChange_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkTrackChange_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkTrackEnd_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkTrackMetaData_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalAudioSinkTrackStart_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalCallClientCallList_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalCallClientStatus_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalCallClientAudioConnect_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalCallClientAudioDisconnect_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalCallClientIndicator_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalCallClientOperator_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalCallClientSubscriber_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalCallClientMicVolumeChange_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalCallClientSpeakerVolumeChange_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalCallClientActivateVoiceDial_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalCallClientDeActivateVoiceDial_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalCallClientSiriSupportStatus_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalCallClientSiriEyesFreeMode_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalCallClientSiriDisableNoiseReduction_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalPhoneStatus_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalCallClientCmdError_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalCallClientScoCodecId_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalMessageClientConfigured_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalMessageClientFolderListing_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalMessageClientMessageDeleted_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalMessageClientMessageGotten_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalMessageClientMessageListing_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalMessageClientMessageNotification_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalMessageClientMessagePushed_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalMessageClientMessageSetStatus_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalNetworkClientConnected_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalNetworkClientDisconnected_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalPimClientImportStatus_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalFileServerInfoEvent_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalFileServerFileAcceptanceStatus_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalFileServerDataFileInProgressStatus_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalServiceLessAudioConnectStatus_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalServiceLessAudioDisconnectStatus_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalServiceLessAclConnectStatus_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalServiceLessAclDisconnectStatus_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalBTChipFailure_cb;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_SignalDeviceAddressGet_cb;
};
#endif /* COM_JCI_BDSPROXY_H */
