#include "com_jci_bdsProxy.h"

com_jci_bdsProxy::com_jci_bdsProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_SendCommand = this->create_method<uint32_t(uint32_t, std::tuple < std::vector < uint8_t >> )>("SendCommand");
  m_method_TestMethod = this->create_method<void(uint32_t)>("TestMethod");
  m_signalproxy_Signaltest_cb = this->create_signal<void(uint32_t)>("Signaltest_cb");
  m_signalproxy_SignalReady_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalReady_cb");
  m_signalproxy_SignalNotReady_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalNotReady_cb");
  m_signalproxy_SignalDeviceDeleteInProgress_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceDeleteInProgress_cb");
  m_signalproxy_SignalDeviceDeleted_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceDeleted_cb");
  m_signalproxy_SignalDeviceDeleteAllInProgress_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceDeleteAllInProgress_cb");
  m_signalproxy_SignalDeviceDeleteAll_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceDeleteAll_cb");
  m_signalproxy_SignalDeviceDisconnectedAll_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceDisconnectedAll_cb");
  m_signalproxy_SignalDeviceDisconnectionProgress_cb = this->create_signal<void(uint32_t,
                                                                                std::tuple < std::vector
                                                                                    < uint8_t >> )>(
      "SignalDeviceDisconnectionProgress_cb");
  m_signalproxy_SignalDeviceInquiryResult_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceInquiryResult_cb");
  m_signalproxy_SignalDeviceNameStarted_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceNameStarted_cb");
  m_signalproxy_SignalDeviceNameSet_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceNameSet_cb");
  m_signalproxy_SignalDeviceNameGet_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceNameGet_cb");
  m_signalproxy_SignalDeviceAccessibilityGet_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceAccessibilityGet_cb");
  m_signalproxy_SignalDevicePair_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDevicePair_cb");
  m_signalproxy_SignalDeviceServiceDiscovery_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceServiceDiscovery_cb");
  m_signalproxy_SignalDeviceWrittenAll_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceWrittenAll_cb");
  m_signalproxy_SignalDeviceAuthenticate_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceAuthenticate_cb");
  m_signalproxy_SignalRemoteSupportedFeatures_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalRemoteSupportedFeatures_cb");
  m_signalproxy_SignalDeviceGetConnectedDevices_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceGetConnectedDevices_cb");
  m_signalproxy_SignalDeviceLocalOobData_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceLocalOobData_cb");
  m_signalproxy_SignalDeviceExtendedSearchResult_cb = this->create_signal<void(uint32_t,
                                                                               std::tuple < std::vector < uint8_t >> )>(
      "SignalDeviceExtendedSearchResult_cb");
  m_signalproxy_SignalServiceEnableStatus_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalServiceEnableStatus_cb");
  m_signalproxy_SignalServiceDisableStatus_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalServiceDisableStatus_cb");
  m_signalproxy_SignalConnected_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalConnected_cb");
  m_signalproxy_SignalDisconnected_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDisconnected_cb");
  m_signalproxy_SignalServiceFeatures_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalServiceFeatures_cb");
  m_signalproxy_SignalServiceConfiguration_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalServiceConfiguration_cb");
  m_signalproxy_SignalAudioSinkAppChange_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkAppChange_cb");
  m_signalproxy_SignalAudioSinkBatteryStatusChange_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>(
          "SignalAudioSinkBatteryStatusChange_cb");
  m_signalproxy_SignalAudioSinkBiased_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkBiased_cb");
  m_signalproxy_SignalAudioSinkBrowseConnect_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkBrowseConnect_cb");
  m_signalproxy_SignalAudioSinkBrowseDisonnect_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkBrowseDisonnect_cb");
  m_signalproxy_SignalAudioSinkBrowseFolderChange_cb = this->create_signal<void(uint32_t,
                                                                                std::tuple < std::vector
                                                                                    < uint8_t >> )>(
      "SignalAudioSinkBrowseFolderChange_cb");
  m_signalproxy_SignalAudioSinkBrowseFolderContent_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>(
          "SignalAudioSinkBrowseFolderContent_cb");
  m_signalproxy_SignalAudioSinkBrowseFolderContents_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>(
          "SignalAudioSinkBrowseFolderContents_cb");
  m_signalproxy_SignalAudioSinkBrowseSearch_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkBrowseSearch_cb");
  m_signalproxy_SignalAudioSinkBrowseUidsChange_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkBrowseUidsChange_cb");
  m_signalproxy_SignalAudioSinkContentAddToNowPlaying_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>(
          "SignalAudioSinkContentAddToNowPlaying_cb");
  m_signalproxy_SignalAudioSinkContentAttributes_cb = this->create_signal<void(uint32_t,
                                                                               std::tuple < std::vector < uint8_t >> )>(
      "SignalAudioSinkContentAttributes_cb");
  m_signalproxy_SignalAudioSinkContentPlay_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkContentPlay_cb");
  m_signalproxy_SignalAudioSinkMediaPosition_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkMediaPosition_cb");
  m_signalproxy_SignalAudioSinkPanelOperation_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkPanelOperation_cb");
  m_signalproxy_SignalAudioSinkPlaybackStatusChange_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>(
          "SignalAudioSinkPlaybackStatusChange_cb");
  m_signalproxy_SignalAudioSinkPlayerAddressedChange_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>(
          "SignalAudioSinkPlayerAddressedChange_cb");
  m_signalproxy_SignalAudioSinkPlayerBrowsedChange_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>(
          "SignalAudioSinkPlayerBrowsedChange_cb");
  m_signalproxy_SignalAudioSinkPlayerItem_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkPlayerItem_cb");
  m_signalproxy_SignalAudioSinkPlayerItems_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkPlayerItems_cb");
  m_signalproxy_SignalAudioSinkPlayerItemsChange_cb = this->create_signal<void(uint32_t,
                                                                               std::tuple < std::vector < uint8_t >> )>(
      "SignalAudioSinkPlayerItemsChange_cb");
  m_signalproxy_SignalAudioSinkPlayerNowContentChange_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>(
          "SignalAudioSinkPlayerNowContentChange_cb");
  m_signalproxy_SignalAudioSinkPlayerVolumeChange_cb = this->create_signal<void(uint32_t,
                                                                                std::tuple < std::vector
                                                                                    < uint8_t >> )>(
      "SignalAudioSinkPlayerVolumeChange_cb");
  m_signalproxy_SignalAudioSinkStreamClosed_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkStreamClosed_cb");
  m_signalproxy_SignalAudioSinkStreamConfigured_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkStreamConfigured_cb");
  m_signalproxy_SignalAudioSinkStreamLine_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkStreamLine_cb");
  m_signalproxy_SignalAudioSinkStreamMuted_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkStreamMuted_cb");
  m_signalproxy_SignalAudioSinkStreamOpened_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkStreamOpened_cb");
  m_signalproxy_SignalAudioSinkSupportedChanges_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkSupportedChanges_cb");
  m_signalproxy_SignalAudioSinkSupportedPlayerSetting_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>(
          "SignalAudioSinkSupportedPlayerSetting_cb");
  m_signalproxy_SignalAudioSinkSystemStatusChange_cb = this->create_signal<void(uint32_t,
                                                                                std::tuple < std::vector
                                                                                    < uint8_t >> )>(
      "SignalAudioSinkSystemStatusChange_cb");
  m_signalproxy_SignalAudioSinkTrackChange_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkTrackChange_cb");
  m_signalproxy_SignalAudioSinkTrackEnd_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkTrackEnd_cb");
  m_signalproxy_SignalAudioSinkTrackMetaData_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkTrackMetaData_cb");
  m_signalproxy_SignalAudioSinkTrackStart_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkTrackStart_cb");
  m_signalproxy_SignalCallClientCallList_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalCallClientCallList_cb");
  m_signalproxy_SignalCallClientStatus_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalCallClientStatus_cb");
  m_signalproxy_SignalCallClientAudioConnect_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalCallClientAudioConnect_cb");
  m_signalproxy_SignalCallClientAudioDisconnect_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalCallClientAudioDisconnect_cb");
  m_signalproxy_SignalCallClientIndicator_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalCallClientIndicator_cb");
  m_signalproxy_SignalCallClientOperator_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalCallClientOperator_cb");
  m_signalproxy_SignalCallClientSubscriber_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalCallClientSubscriber_cb");
  m_signalproxy_SignalCallClientMicVolumeChange_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalCallClientMicVolumeChange_cb");
  m_signalproxy_SignalCallClientSpeakerVolumeChange_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>(
          "SignalCallClientSpeakerVolumeChange_cb");
  m_signalproxy_SignalCallClientActivateVoiceDial_cb = this->create_signal<void(uint32_t,
                                                                                std::tuple < std::vector
                                                                                    < uint8_t >> )>(
      "SignalCallClientActivateVoiceDial_cb");
  m_signalproxy_SignalCallClientDeActivateVoiceDial_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>(
          "SignalCallClientDeActivateVoiceDial_cb");
  m_signalproxy_SignalCallClientSiriSupportStatus_cb = this->create_signal<void(uint32_t,
                                                                                std::tuple < std::vector
                                                                                    < uint8_t >> )>(
      "SignalCallClientSiriSupportStatus_cb");
  m_signalproxy_SignalCallClientSiriEyesFreeMode_cb = this->create_signal<void(uint32_t,
                                                                               std::tuple < std::vector < uint8_t >> )>(
      "SignalCallClientSiriEyesFreeMode_cb");
  m_signalproxy_SignalCallClientSiriDisableNoiseReduction_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>(
          "SignalCallClientSiriDisableNoiseReduction_cb");
  m_signalproxy_SignalPhoneStatus_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalPhoneStatus_cb");
  m_signalproxy_SignalCallClientCmdError_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalCallClientCmdError_cb");
  m_signalproxy_SignalCallClientScoCodecId_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalCallClientScoCodecId_cb");
  m_signalproxy_SignalMessageClientConfigured_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalMessageClientConfigured_cb");
  m_signalproxy_SignalMessageClientFolderListing_cb = this->create_signal<void(uint32_t,
                                                                               std::tuple < std::vector < uint8_t >> )>(
      "SignalMessageClientFolderListing_cb");
  m_signalproxy_SignalMessageClientMessageDeleted_cb = this->create_signal<void(uint32_t,
                                                                                std::tuple < std::vector
                                                                                    < uint8_t >> )>(
      "SignalMessageClientMessageDeleted_cb");
  m_signalproxy_SignalMessageClientMessageGotten_cb = this->create_signal<void(uint32_t,
                                                                               std::tuple < std::vector < uint8_t >> )>(
      "SignalMessageClientMessageGotten_cb");
  m_signalproxy_SignalMessageClientMessageListing_cb = this->create_signal<void(uint32_t,
                                                                                std::tuple < std::vector
                                                                                    < uint8_t >> )>(
      "SignalMessageClientMessageListing_cb");
  m_signalproxy_SignalMessageClientMessageNotification_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>(
          "SignalMessageClientMessageNotification_cb");
  m_signalproxy_SignalMessageClientMessagePushed_cb = this->create_signal<void(uint32_t,
                                                                               std::tuple < std::vector < uint8_t >> )>(
      "SignalMessageClientMessagePushed_cb");
  m_signalproxy_SignalMessageClientMessageSetStatus_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>(
          "SignalMessageClientMessageSetStatus_cb");
  m_signalproxy_SignalNetworkClientConnected_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalNetworkClientConnected_cb");
  m_signalproxy_SignalNetworkClientDisconnected_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalNetworkClientDisconnected_cb");
  m_signalproxy_SignalPimClientImportStatus_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalPimClientImportStatus_cb");
  m_signalproxy_SignalFileServerInfoEvent_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalFileServerInfoEvent_cb");
  m_signalproxy_SignalFileServerFileAcceptanceStatus_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>(
          "SignalFileServerFileAcceptanceStatus_cb");
  m_signalproxy_SignalFileServerDataFileInProgressStatus_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>(
          "SignalFileServerDataFileInProgressStatus_cb");
  m_signalproxy_SignalServiceLessAudioConnectStatus_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>(
          "SignalServiceLessAudioConnectStatus_cb");
  m_signalproxy_SignalServiceLessAudioDisconnectStatus_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>(
          "SignalServiceLessAudioDisconnectStatus_cb");
  m_signalproxy_SignalServiceLessAclConnectStatus_cb = this->create_signal<void(uint32_t,
                                                                                std::tuple < std::vector
                                                                                    < uint8_t >> )>(
      "SignalServiceLessAclConnectStatus_cb");
  m_signalproxy_SignalServiceLessAclDisconnectStatus_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>(
          "SignalServiceLessAclDisconnectStatus_cb");
  m_signalproxy_SignalBTChipFailure_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalBTChipFailure_cb");
  m_signalproxy_SignalDeviceAddressGet_cb =
      this->create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceAddressGet_cb");

}
std::shared_ptr <com_jci_bdsProxy> com_jci_bdsProxy::create(std::string name) {
  return std::shared_ptr<com_jci_bdsProxy>(new com_jci_bdsProxy(name));

}
uint32_t com_jci_bdsProxy::SendCommand(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  return (*m_method_SendCommand)(type, data);

}
void com_jci_bdsProxy::TestMethod(uint32_t type) {
  (*m_method_TestMethod)(type);

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_bdsProxy::signal_Signaltest_cb() {
  return m_signalproxy_Signaltest_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalReady_cb() {
  return m_signalproxy_SignalReady_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalNotReady_cb() {
  return m_signalproxy_SignalNotReady_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalDeviceDeleteInProgress_cb() {
  return m_signalproxy_SignalDeviceDeleteInProgress_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalDeviceDeleted_cb() {
  return m_signalproxy_SignalDeviceDeleted_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalDeviceDeleteAllInProgress_cb() {
  return m_signalproxy_SignalDeviceDeleteAllInProgress_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalDeviceDeleteAll_cb() {
  return m_signalproxy_SignalDeviceDeleteAll_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalDeviceDisconnectedAll_cb() {
  return m_signalproxy_SignalDeviceDisconnectedAll_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalDeviceDisconnectionProgress_cb() {
  return m_signalproxy_SignalDeviceDisconnectionProgress_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalDeviceInquiryResult_cb() {
  return m_signalproxy_SignalDeviceInquiryResult_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalDeviceNameStarted_cb() {
  return m_signalproxy_SignalDeviceNameStarted_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalDeviceNameSet_cb() {
  return m_signalproxy_SignalDeviceNameSet_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalDeviceNameGet_cb() {
  return m_signalproxy_SignalDeviceNameGet_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalDeviceAccessibilityGet_cb() {
  return m_signalproxy_SignalDeviceAccessibilityGet_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalDevicePair_cb() {
  return m_signalproxy_SignalDevicePair_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalDeviceServiceDiscovery_cb() {
  return m_signalproxy_SignalDeviceServiceDiscovery_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalDeviceWrittenAll_cb() {
  return m_signalproxy_SignalDeviceWrittenAll_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalDeviceAuthenticate_cb() {
  return m_signalproxy_SignalDeviceAuthenticate_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalRemoteSupportedFeatures_cb() {
  return m_signalproxy_SignalRemoteSupportedFeatures_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalDeviceGetConnectedDevices_cb() {
  return m_signalproxy_SignalDeviceGetConnectedDevices_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalDeviceLocalOobData_cb() {
  return m_signalproxy_SignalDeviceLocalOobData_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalDeviceExtendedSearchResult_cb() {
  return m_signalproxy_SignalDeviceExtendedSearchResult_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalServiceEnableStatus_cb() {
  return m_signalproxy_SignalServiceEnableStatus_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalServiceDisableStatus_cb() {
  return m_signalproxy_SignalServiceDisableStatus_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalConnected_cb() {
  return m_signalproxy_SignalConnected_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalDisconnected_cb() {
  return m_signalproxy_SignalDisconnected_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalServiceFeatures_cb() {
  return m_signalproxy_SignalServiceFeatures_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalServiceConfiguration_cb() {
  return m_signalproxy_SignalServiceConfiguration_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalAudioSinkAppChange_cb() {
  return m_signalproxy_SignalAudioSinkAppChange_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalAudioSinkBatteryStatusChange_cb() {
  return m_signalproxy_SignalAudioSinkBatteryStatusChange_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalAudioSinkBiased_cb() {
  return m_signalproxy_SignalAudioSinkBiased_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalAudioSinkBrowseConnect_cb() {
  return m_signalproxy_SignalAudioSinkBrowseConnect_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalAudioSinkBrowseDisonnect_cb() {
  return m_signalproxy_SignalAudioSinkBrowseDisonnect_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalAudioSinkBrowseFolderChange_cb() {
  return m_signalproxy_SignalAudioSinkBrowseFolderChange_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalAudioSinkBrowseFolderContent_cb() {
  return m_signalproxy_SignalAudioSinkBrowseFolderContent_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalAudioSinkBrowseFolderContents_cb() {
  return m_signalproxy_SignalAudioSinkBrowseFolderContents_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalAudioSinkBrowseSearch_cb() {
  return m_signalproxy_SignalAudioSinkBrowseSearch_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalAudioSinkBrowseUidsChange_cb() {
  return m_signalproxy_SignalAudioSinkBrowseUidsChange_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalAudioSinkContentAddToNowPlaying_cb() {
  return m_signalproxy_SignalAudioSinkContentAddToNowPlaying_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalAudioSinkContentAttributes_cb() {
  return m_signalproxy_SignalAudioSinkContentAttributes_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalAudioSinkContentPlay_cb() {
  return m_signalproxy_SignalAudioSinkContentPlay_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalAudioSinkMediaPosition_cb() {
  return m_signalproxy_SignalAudioSinkMediaPosition_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalAudioSinkPanelOperation_cb() {
  return m_signalproxy_SignalAudioSinkPanelOperation_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalAudioSinkPlaybackStatusChange_cb() {
  return m_signalproxy_SignalAudioSinkPlaybackStatusChange_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalAudioSinkPlayerAddressedChange_cb() {
  return m_signalproxy_SignalAudioSinkPlayerAddressedChange_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalAudioSinkPlayerBrowsedChange_cb() {
  return m_signalproxy_SignalAudioSinkPlayerBrowsedChange_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalAudioSinkPlayerItem_cb() {
  return m_signalproxy_SignalAudioSinkPlayerItem_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalAudioSinkPlayerItems_cb() {
  return m_signalproxy_SignalAudioSinkPlayerItems_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalAudioSinkPlayerItemsChange_cb() {
  return m_signalproxy_SignalAudioSinkPlayerItemsChange_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalAudioSinkPlayerNowContentChange_cb() {
  return m_signalproxy_SignalAudioSinkPlayerNowContentChange_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalAudioSinkPlayerVolumeChange_cb() {
  return m_signalproxy_SignalAudioSinkPlayerVolumeChange_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalAudioSinkStreamClosed_cb() {
  return m_signalproxy_SignalAudioSinkStreamClosed_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalAudioSinkStreamConfigured_cb() {
  return m_signalproxy_SignalAudioSinkStreamConfigured_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalAudioSinkStreamLine_cb() {
  return m_signalproxy_SignalAudioSinkStreamLine_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalAudioSinkStreamMuted_cb() {
  return m_signalproxy_SignalAudioSinkStreamMuted_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalAudioSinkStreamOpened_cb() {
  return m_signalproxy_SignalAudioSinkStreamOpened_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalAudioSinkSupportedChanges_cb() {
  return m_signalproxy_SignalAudioSinkSupportedChanges_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalAudioSinkSupportedPlayerSetting_cb() {
  return m_signalproxy_SignalAudioSinkSupportedPlayerSetting_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalAudioSinkSystemStatusChange_cb() {
  return m_signalproxy_SignalAudioSinkSystemStatusChange_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalAudioSinkTrackChange_cb() {
  return m_signalproxy_SignalAudioSinkTrackChange_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalAudioSinkTrackEnd_cb() {
  return m_signalproxy_SignalAudioSinkTrackEnd_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalAudioSinkTrackMetaData_cb() {
  return m_signalproxy_SignalAudioSinkTrackMetaData_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalAudioSinkTrackStart_cb() {
  return m_signalproxy_SignalAudioSinkTrackStart_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalCallClientCallList_cb() {
  return m_signalproxy_SignalCallClientCallList_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalCallClientStatus_cb() {
  return m_signalproxy_SignalCallClientStatus_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalCallClientAudioConnect_cb() {
  return m_signalproxy_SignalCallClientAudioConnect_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalCallClientAudioDisconnect_cb() {
  return m_signalproxy_SignalCallClientAudioDisconnect_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalCallClientIndicator_cb() {
  return m_signalproxy_SignalCallClientIndicator_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalCallClientOperator_cb() {
  return m_signalproxy_SignalCallClientOperator_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalCallClientSubscriber_cb() {
  return m_signalproxy_SignalCallClientSubscriber_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalCallClientMicVolumeChange_cb() {
  return m_signalproxy_SignalCallClientMicVolumeChange_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalCallClientSpeakerVolumeChange_cb() {
  return m_signalproxy_SignalCallClientSpeakerVolumeChange_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalCallClientActivateVoiceDial_cb() {
  return m_signalproxy_SignalCallClientActivateVoiceDial_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalCallClientDeActivateVoiceDial_cb() {
  return m_signalproxy_SignalCallClientDeActivateVoiceDial_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalCallClientSiriSupportStatus_cb() {
  return m_signalproxy_SignalCallClientSiriSupportStatus_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalCallClientSiriEyesFreeMode_cb() {
  return m_signalproxy_SignalCallClientSiriEyesFreeMode_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalCallClientSiriDisableNoiseReduction_cb() {
  return m_signalproxy_SignalCallClientSiriDisableNoiseReduction_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalPhoneStatus_cb() {
  return m_signalproxy_SignalPhoneStatus_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalCallClientCmdError_cb() {
  return m_signalproxy_SignalCallClientCmdError_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalCallClientScoCodecId_cb() {
  return m_signalproxy_SignalCallClientScoCodecId_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalMessageClientConfigured_cb() {
  return m_signalproxy_SignalMessageClientConfigured_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalMessageClientFolderListing_cb() {
  return m_signalproxy_SignalMessageClientFolderListing_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalMessageClientMessageDeleted_cb() {
  return m_signalproxy_SignalMessageClientMessageDeleted_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalMessageClientMessageGotten_cb() {
  return m_signalproxy_SignalMessageClientMessageGotten_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalMessageClientMessageListing_cb() {
  return m_signalproxy_SignalMessageClientMessageListing_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalMessageClientMessageNotification_cb() {
  return m_signalproxy_SignalMessageClientMessageNotification_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalMessageClientMessagePushed_cb() {
  return m_signalproxy_SignalMessageClientMessagePushed_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalMessageClientMessageSetStatus_cb() {
  return m_signalproxy_SignalMessageClientMessageSetStatus_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalNetworkClientConnected_cb() {
  return m_signalproxy_SignalNetworkClientConnected_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalNetworkClientDisconnected_cb() {
  return m_signalproxy_SignalNetworkClientDisconnected_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalPimClientImportStatus_cb() {
  return m_signalproxy_SignalPimClientImportStatus_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalFileServerInfoEvent_cb() {
  return m_signalproxy_SignalFileServerInfoEvent_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalFileServerFileAcceptanceStatus_cb() {
  return m_signalproxy_SignalFileServerFileAcceptanceStatus_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalFileServerDataFileInProgressStatus_cb() {
  return m_signalproxy_SignalFileServerDataFileInProgressStatus_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalServiceLessAudioConnectStatus_cb() {
  return m_signalproxy_SignalServiceLessAudioConnectStatus_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalServiceLessAudioDisconnectStatus_cb() {
  return m_signalproxy_SignalServiceLessAudioDisconnectStatus_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalServiceLessAclConnectStatus_cb() {
  return m_signalproxy_SignalServiceLessAclConnectStatus_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector < uint8_t
                                            >> )>> com_jci_bdsProxy::signal_SignalServiceLessAclDisconnectStatus_cb() {
  return m_signalproxy_SignalServiceLessAclDisconnectStatus_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalBTChipFailure_cb() {
  return m_signalproxy_SignalBTChipFailure_cb;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        std::tuple < std::vector
                                            < uint8_t >> )>> com_jci_bdsProxy::signal_SignalDeviceAddressGet_cb() {
  return m_signalproxy_SignalDeviceAddressGet_cb;

}
