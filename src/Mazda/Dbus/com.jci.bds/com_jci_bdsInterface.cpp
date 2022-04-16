#include "com_jci_bdsInterface.h"

com_jci_bdsInterface::com_jci_bdsInterface(com_jci_bds *adaptee, std::string name) : DBus::Interface(name) {
  this->create_method<uint32_t(uint32_t, std::tuple < std::vector < uint8_t >> )>("SendCommand",
                                                                                  sigc::mem_fun(*adaptee,
                                                                                                &com_jci_bds::SendCommand));
  this->create_method<void(uint32_t)>("TestMethod", sigc::mem_fun(*adaptee, &com_jci_bds::TestMethod));
  m_signal_Signaltest_cb = create_signal<void(uint32_t)>("Signaltest_cb");
  m_signal_SignalReady_cb = create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalReady_cb");
  m_signal_SignalNotReady_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalNotReady_cb");
  m_signal_SignalDeviceDeleteInProgress_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceDeleteInProgress_cb");
  m_signal_SignalDeviceDeleted_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceDeleted_cb");
  m_signal_SignalDeviceDeleteAllInProgress_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceDeleteAllInProgress_cb");
  m_signal_SignalDeviceDeleteAll_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceDeleteAll_cb");
  m_signal_SignalDeviceDisconnectedAll_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceDisconnectedAll_cb");
  m_signal_SignalDeviceDisconnectionProgress_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceDisconnectionProgress_cb");
  m_signal_SignalDeviceInquiryResult_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceInquiryResult_cb");
  m_signal_SignalDeviceNameStarted_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceNameStarted_cb");
  m_signal_SignalDeviceNameSet_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceNameSet_cb");
  m_signal_SignalDeviceNameGet_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceNameGet_cb");
  m_signal_SignalDeviceAccessibilityGet_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceAccessibilityGet_cb");
  m_signal_SignalDevicePair_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDevicePair_cb");
  m_signal_SignalDeviceServiceDiscovery_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceServiceDiscovery_cb");
  m_signal_SignalDeviceWrittenAll_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceWrittenAll_cb");
  m_signal_SignalDeviceAuthenticate_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceAuthenticate_cb");
  m_signal_SignalRemoteSupportedFeatures_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalRemoteSupportedFeatures_cb");
  m_signal_SignalDeviceGetConnectedDevices_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceGetConnectedDevices_cb");
  m_signal_SignalDeviceLocalOobData_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceLocalOobData_cb");
  m_signal_SignalDeviceExtendedSearchResult_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceExtendedSearchResult_cb");
  m_signal_SignalServiceEnableStatus_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalServiceEnableStatus_cb");
  m_signal_SignalServiceDisableStatus_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalServiceDisableStatus_cb");
  m_signal_SignalConnected_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalConnected_cb");
  m_signal_SignalDisconnected_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDisconnected_cb");
  m_signal_SignalServiceFeatures_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalServiceFeatures_cb");
  m_signal_SignalServiceConfiguration_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalServiceConfiguration_cb");
  m_signal_SignalAudioSinkAppChange_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkAppChange_cb");
  m_signal_SignalAudioSinkBatteryStatusChange_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkBatteryStatusChange_cb");
  m_signal_SignalAudioSinkBiased_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkBiased_cb");
  m_signal_SignalAudioSinkBrowseConnect_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkBrowseConnect_cb");
  m_signal_SignalAudioSinkBrowseDisonnect_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkBrowseDisonnect_cb");
  m_signal_SignalAudioSinkBrowseFolderChange_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkBrowseFolderChange_cb");
  m_signal_SignalAudioSinkBrowseFolderContent_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkBrowseFolderContent_cb");
  m_signal_SignalAudioSinkBrowseFolderContents_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkBrowseFolderContents_cb");
  m_signal_SignalAudioSinkBrowseSearch_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkBrowseSearch_cb");
  m_signal_SignalAudioSinkBrowseUidsChange_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkBrowseUidsChange_cb");
  m_signal_SignalAudioSinkContentAddToNowPlaying_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkContentAddToNowPlaying_cb");
  m_signal_SignalAudioSinkContentAttributes_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkContentAttributes_cb");
  m_signal_SignalAudioSinkContentPlay_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkContentPlay_cb");
  m_signal_SignalAudioSinkMediaPosition_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkMediaPosition_cb");
  m_signal_SignalAudioSinkPanelOperation_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkPanelOperation_cb");
  m_signal_SignalAudioSinkPlaybackStatusChange_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkPlaybackStatusChange_cb");
  m_signal_SignalAudioSinkPlayerAddressedChange_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkPlayerAddressedChange_cb");
  m_signal_SignalAudioSinkPlayerBrowsedChange_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkPlayerBrowsedChange_cb");
  m_signal_SignalAudioSinkPlayerItem_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkPlayerItem_cb");
  m_signal_SignalAudioSinkPlayerItems_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkPlayerItems_cb");
  m_signal_SignalAudioSinkPlayerItemsChange_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkPlayerItemsChange_cb");
  m_signal_SignalAudioSinkPlayerNowContentChange_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkPlayerNowContentChange_cb");
  m_signal_SignalAudioSinkPlayerVolumeChange_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkPlayerVolumeChange_cb");
  m_signal_SignalAudioSinkStreamClosed_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkStreamClosed_cb");
  m_signal_SignalAudioSinkStreamConfigured_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkStreamConfigured_cb");
  m_signal_SignalAudioSinkStreamLine_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkStreamLine_cb");
  m_signal_SignalAudioSinkStreamMuted_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkStreamMuted_cb");
  m_signal_SignalAudioSinkStreamOpened_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkStreamOpened_cb");
  m_signal_SignalAudioSinkSupportedChanges_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkSupportedChanges_cb");
  m_signal_SignalAudioSinkSupportedPlayerSetting_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkSupportedPlayerSetting_cb");
  m_signal_SignalAudioSinkSystemStatusChange_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkSystemStatusChange_cb");
  m_signal_SignalAudioSinkTrackChange_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkTrackChange_cb");
  m_signal_SignalAudioSinkTrackEnd_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkTrackEnd_cb");
  m_signal_SignalAudioSinkTrackMetaData_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkTrackMetaData_cb");
  m_signal_SignalAudioSinkTrackStart_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalAudioSinkTrackStart_cb");
  m_signal_SignalCallClientCallList_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalCallClientCallList_cb");
  m_signal_SignalCallClientStatus_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalCallClientStatus_cb");
  m_signal_SignalCallClientAudioConnect_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalCallClientAudioConnect_cb");
  m_signal_SignalCallClientAudioDisconnect_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalCallClientAudioDisconnect_cb");
  m_signal_SignalCallClientIndicator_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalCallClientIndicator_cb");
  m_signal_SignalCallClientOperator_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalCallClientOperator_cb");
  m_signal_SignalCallClientSubscriber_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalCallClientSubscriber_cb");
  m_signal_SignalCallClientMicVolumeChange_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalCallClientMicVolumeChange_cb");
  m_signal_SignalCallClientSpeakerVolumeChange_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalCallClientSpeakerVolumeChange_cb");
  m_signal_SignalCallClientActivateVoiceDial_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalCallClientActivateVoiceDial_cb");
  m_signal_SignalCallClientDeActivateVoiceDial_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalCallClientDeActivateVoiceDial_cb");
  m_signal_SignalCallClientSiriSupportStatus_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalCallClientSiriSupportStatus_cb");
  m_signal_SignalCallClientSiriEyesFreeMode_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalCallClientSiriEyesFreeMode_cb");
  m_signal_SignalCallClientSiriDisableNoiseReduction_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>(
          "SignalCallClientSiriDisableNoiseReduction_cb");
  m_signal_SignalPhoneStatus_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalPhoneStatus_cb");
  m_signal_SignalCallClientCmdError_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalCallClientCmdError_cb");
  m_signal_SignalCallClientScoCodecId_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalCallClientScoCodecId_cb");
  m_signal_SignalMessageClientConfigured_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalMessageClientConfigured_cb");
  m_signal_SignalMessageClientFolderListing_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalMessageClientFolderListing_cb");
  m_signal_SignalMessageClientMessageDeleted_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalMessageClientMessageDeleted_cb");
  m_signal_SignalMessageClientMessageGotten_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalMessageClientMessageGotten_cb");
  m_signal_SignalMessageClientMessageListing_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalMessageClientMessageListing_cb");
  m_signal_SignalMessageClientMessageNotification_cb = create_signal<void(uint32_t,
                                                                          std::tuple < std::vector < uint8_t >> )>(
      "SignalMessageClientMessageNotification_cb");
  m_signal_SignalMessageClientMessagePushed_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalMessageClientMessagePushed_cb");
  m_signal_SignalMessageClientMessageSetStatus_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalMessageClientMessageSetStatus_cb");
  m_signal_SignalNetworkClientConnected_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalNetworkClientConnected_cb");
  m_signal_SignalNetworkClientDisconnected_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalNetworkClientDisconnected_cb");
  m_signal_SignalPimClientImportStatus_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalPimClientImportStatus_cb");
  m_signal_SignalFileServerInfoEvent_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalFileServerInfoEvent_cb");
  m_signal_SignalFileServerFileAcceptanceStatus_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalFileServerFileAcceptanceStatus_cb");
  m_signal_SignalFileServerDataFileInProgressStatus_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>(
          "SignalFileServerDataFileInProgressStatus_cb");
  m_signal_SignalServiceLessAudioConnectStatus_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalServiceLessAudioConnectStatus_cb");
  m_signal_SignalServiceLessAudioDisconnectStatus_cb = create_signal<void(uint32_t,
                                                                          std::tuple < std::vector < uint8_t >> )>(
      "SignalServiceLessAudioDisconnectStatus_cb");
  m_signal_SignalServiceLessAclConnectStatus_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalServiceLessAclConnectStatus_cb");
  m_signal_SignalServiceLessAclDisconnectStatus_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalServiceLessAclDisconnectStatus_cb");
  m_signal_SignalBTChipFailure_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalBTChipFailure_cb");
  m_signal_SignalDeviceAddressGet_cb =
      create_signal<void(uint32_t, std::tuple < std::vector < uint8_t >> )>("SignalDeviceAddressGet_cb");

}
std::shared_ptr <com_jci_bdsInterface> com_jci_bdsInterface::create(com_jci_bds *adaptee, std::string name) {
  return std::shared_ptr<com_jci_bdsInterface>(new com_jci_bdsInterface(adaptee, name));

}
std::shared_ptr <DBus::Signal<void(uint32_t)>> com_jci_bdsInterface::signal_Signaltest_cb() {
  return m_signal_Signaltest_cb;

}
void com_jci_bdsInterface::Signaltest_cb(uint32_t type) {
  (*m_signal_Signaltest_cb)(type);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalReady_cb() {
  return m_signal_SignalReady_cb;

}
void com_jci_bdsInterface::SignalReady_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalReady_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalNotReady_cb() {
  return m_signal_SignalNotReady_cb;

}
void com_jci_bdsInterface::SignalNotReady_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalNotReady_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalDeviceDeleteInProgress_cb() {
  return m_signal_SignalDeviceDeleteInProgress_cb;

}
void com_jci_bdsInterface::SignalDeviceDeleteInProgress_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalDeviceDeleteInProgress_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalDeviceDeleted_cb() {
  return m_signal_SignalDeviceDeleted_cb;

}
void com_jci_bdsInterface::SignalDeviceDeleted_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalDeviceDeleted_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalDeviceDeleteAllInProgress_cb() {
  return m_signal_SignalDeviceDeleteAllInProgress_cb;

}
void com_jci_bdsInterface::SignalDeviceDeleteAllInProgress_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalDeviceDeleteAllInProgress_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalDeviceDeleteAll_cb() {
  return m_signal_SignalDeviceDeleteAll_cb;

}
void com_jci_bdsInterface::SignalDeviceDeleteAll_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalDeviceDeleteAll_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalDeviceDisconnectedAll_cb() {
  return m_signal_SignalDeviceDisconnectedAll_cb;

}
void com_jci_bdsInterface::SignalDeviceDisconnectedAll_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalDeviceDisconnectedAll_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalDeviceDisconnectionProgress_cb() {
  return m_signal_SignalDeviceDisconnectionProgress_cb;

}
void com_jci_bdsInterface::SignalDeviceDisconnectionProgress_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalDeviceDisconnectionProgress_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalDeviceInquiryResult_cb() {
  return m_signal_SignalDeviceInquiryResult_cb;

}
void com_jci_bdsInterface::SignalDeviceInquiryResult_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalDeviceInquiryResult_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalDeviceNameStarted_cb() {
  return m_signal_SignalDeviceNameStarted_cb;

}
void com_jci_bdsInterface::SignalDeviceNameStarted_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalDeviceNameStarted_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalDeviceNameSet_cb() {
  return m_signal_SignalDeviceNameSet_cb;

}
void com_jci_bdsInterface::SignalDeviceNameSet_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalDeviceNameSet_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalDeviceNameGet_cb() {
  return m_signal_SignalDeviceNameGet_cb;

}
void com_jci_bdsInterface::SignalDeviceNameGet_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalDeviceNameGet_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalDeviceAccessibilityGet_cb() {
  return m_signal_SignalDeviceAccessibilityGet_cb;

}
void com_jci_bdsInterface::SignalDeviceAccessibilityGet_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalDeviceAccessibilityGet_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalDevicePair_cb() {
  return m_signal_SignalDevicePair_cb;

}
void com_jci_bdsInterface::SignalDevicePair_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalDevicePair_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalDeviceServiceDiscovery_cb() {
  return m_signal_SignalDeviceServiceDiscovery_cb;

}
void com_jci_bdsInterface::SignalDeviceServiceDiscovery_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalDeviceServiceDiscovery_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalDeviceWrittenAll_cb() {
  return m_signal_SignalDeviceWrittenAll_cb;

}
void com_jci_bdsInterface::SignalDeviceWrittenAll_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalDeviceWrittenAll_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalDeviceAuthenticate_cb() {
  return m_signal_SignalDeviceAuthenticate_cb;

}
void com_jci_bdsInterface::SignalDeviceAuthenticate_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalDeviceAuthenticate_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalRemoteSupportedFeatures_cb() {
  return m_signal_SignalRemoteSupportedFeatures_cb;

}
void com_jci_bdsInterface::SignalRemoteSupportedFeatures_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalRemoteSupportedFeatures_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalDeviceGetConnectedDevices_cb() {
  return m_signal_SignalDeviceGetConnectedDevices_cb;

}
void com_jci_bdsInterface::SignalDeviceGetConnectedDevices_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalDeviceGetConnectedDevices_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalDeviceLocalOobData_cb() {
  return m_signal_SignalDeviceLocalOobData_cb;

}
void com_jci_bdsInterface::SignalDeviceLocalOobData_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalDeviceLocalOobData_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalDeviceExtendedSearchResult_cb() {
  return m_signal_SignalDeviceExtendedSearchResult_cb;

}
void com_jci_bdsInterface::SignalDeviceExtendedSearchResult_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalDeviceExtendedSearchResult_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalServiceEnableStatus_cb() {
  return m_signal_SignalServiceEnableStatus_cb;

}
void com_jci_bdsInterface::SignalServiceEnableStatus_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalServiceEnableStatus_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalServiceDisableStatus_cb() {
  return m_signal_SignalServiceDisableStatus_cb;

}
void com_jci_bdsInterface::SignalServiceDisableStatus_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalServiceDisableStatus_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalConnected_cb() {
  return m_signal_SignalConnected_cb;

}
void com_jci_bdsInterface::SignalConnected_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalConnected_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalDisconnected_cb() {
  return m_signal_SignalDisconnected_cb;

}
void com_jci_bdsInterface::SignalDisconnected_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalDisconnected_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalServiceFeatures_cb() {
  return m_signal_SignalServiceFeatures_cb;

}
void com_jci_bdsInterface::SignalServiceFeatures_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalServiceFeatures_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalServiceConfiguration_cb() {
  return m_signal_SignalServiceConfiguration_cb;

}
void com_jci_bdsInterface::SignalServiceConfiguration_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalServiceConfiguration_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalAudioSinkAppChange_cb() {
  return m_signal_SignalAudioSinkAppChange_cb;

}
void com_jci_bdsInterface::SignalAudioSinkAppChange_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkAppChange_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalAudioSinkBatteryStatusChange_cb() {
  return m_signal_SignalAudioSinkBatteryStatusChange_cb;

}
void com_jci_bdsInterface::SignalAudioSinkBatteryStatusChange_cb(uint32_t type,
                                                                 std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkBatteryStatusChange_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalAudioSinkBiased_cb() {
  return m_signal_SignalAudioSinkBiased_cb;

}
void com_jci_bdsInterface::SignalAudioSinkBiased_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkBiased_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalAudioSinkBrowseConnect_cb() {
  return m_signal_SignalAudioSinkBrowseConnect_cb;

}
void com_jci_bdsInterface::SignalAudioSinkBrowseConnect_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkBrowseConnect_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalAudioSinkBrowseDisonnect_cb() {
  return m_signal_SignalAudioSinkBrowseDisonnect_cb;

}
void com_jci_bdsInterface::SignalAudioSinkBrowseDisonnect_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkBrowseDisonnect_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalAudioSinkBrowseFolderChange_cb() {
  return m_signal_SignalAudioSinkBrowseFolderChange_cb;

}
void com_jci_bdsInterface::SignalAudioSinkBrowseFolderChange_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkBrowseFolderChange_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalAudioSinkBrowseFolderContent_cb() {
  return m_signal_SignalAudioSinkBrowseFolderContent_cb;

}
void com_jci_bdsInterface::SignalAudioSinkBrowseFolderContent_cb(uint32_t type,
                                                                 std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkBrowseFolderContent_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalAudioSinkBrowseFolderContents_cb() {
  return m_signal_SignalAudioSinkBrowseFolderContents_cb;

}
void com_jci_bdsInterface::SignalAudioSinkBrowseFolderContents_cb(uint32_t type,
                                                                  std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkBrowseFolderContents_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalAudioSinkBrowseSearch_cb() {
  return m_signal_SignalAudioSinkBrowseSearch_cb;

}
void com_jci_bdsInterface::SignalAudioSinkBrowseSearch_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkBrowseSearch_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalAudioSinkBrowseUidsChange_cb() {
  return m_signal_SignalAudioSinkBrowseUidsChange_cb;

}
void com_jci_bdsInterface::SignalAudioSinkBrowseUidsChange_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkBrowseUidsChange_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalAudioSinkContentAddToNowPlaying_cb() {
  return m_signal_SignalAudioSinkContentAddToNowPlaying_cb;

}
void com_jci_bdsInterface::SignalAudioSinkContentAddToNowPlaying_cb(uint32_t type,
                                                                    std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkContentAddToNowPlaying_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalAudioSinkContentAttributes_cb() {
  return m_signal_SignalAudioSinkContentAttributes_cb;

}
void com_jci_bdsInterface::SignalAudioSinkContentAttributes_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkContentAttributes_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalAudioSinkContentPlay_cb() {
  return m_signal_SignalAudioSinkContentPlay_cb;

}
void com_jci_bdsInterface::SignalAudioSinkContentPlay_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkContentPlay_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalAudioSinkMediaPosition_cb() {
  return m_signal_SignalAudioSinkMediaPosition_cb;

}
void com_jci_bdsInterface::SignalAudioSinkMediaPosition_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkMediaPosition_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalAudioSinkPanelOperation_cb() {
  return m_signal_SignalAudioSinkPanelOperation_cb;

}
void com_jci_bdsInterface::SignalAudioSinkPanelOperation_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkPanelOperation_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalAudioSinkPlaybackStatusChange_cb() {
  return m_signal_SignalAudioSinkPlaybackStatusChange_cb;

}
void com_jci_bdsInterface::SignalAudioSinkPlaybackStatusChange_cb(uint32_t type,
                                                                  std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkPlaybackStatusChange_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalAudioSinkPlayerAddressedChange_cb() {
  return m_signal_SignalAudioSinkPlayerAddressedChange_cb;

}
void com_jci_bdsInterface::SignalAudioSinkPlayerAddressedChange_cb(uint32_t type,
                                                                   std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkPlayerAddressedChange_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalAudioSinkPlayerBrowsedChange_cb() {
  return m_signal_SignalAudioSinkPlayerBrowsedChange_cb;

}
void com_jci_bdsInterface::SignalAudioSinkPlayerBrowsedChange_cb(uint32_t type,
                                                                 std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkPlayerBrowsedChange_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalAudioSinkPlayerItem_cb() {
  return m_signal_SignalAudioSinkPlayerItem_cb;

}
void com_jci_bdsInterface::SignalAudioSinkPlayerItem_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkPlayerItem_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalAudioSinkPlayerItems_cb() {
  return m_signal_SignalAudioSinkPlayerItems_cb;

}
void com_jci_bdsInterface::SignalAudioSinkPlayerItems_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkPlayerItems_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalAudioSinkPlayerItemsChange_cb() {
  return m_signal_SignalAudioSinkPlayerItemsChange_cb;

}
void com_jci_bdsInterface::SignalAudioSinkPlayerItemsChange_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkPlayerItemsChange_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalAudioSinkPlayerNowContentChange_cb() {
  return m_signal_SignalAudioSinkPlayerNowContentChange_cb;

}
void com_jci_bdsInterface::SignalAudioSinkPlayerNowContentChange_cb(uint32_t type,
                                                                    std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkPlayerNowContentChange_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalAudioSinkPlayerVolumeChange_cb() {
  return m_signal_SignalAudioSinkPlayerVolumeChange_cb;

}
void com_jci_bdsInterface::SignalAudioSinkPlayerVolumeChange_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkPlayerVolumeChange_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalAudioSinkStreamClosed_cb() {
  return m_signal_SignalAudioSinkStreamClosed_cb;

}
void com_jci_bdsInterface::SignalAudioSinkStreamClosed_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkStreamClosed_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalAudioSinkStreamConfigured_cb() {
  return m_signal_SignalAudioSinkStreamConfigured_cb;

}
void com_jci_bdsInterface::SignalAudioSinkStreamConfigured_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkStreamConfigured_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalAudioSinkStreamLine_cb() {
  return m_signal_SignalAudioSinkStreamLine_cb;

}
void com_jci_bdsInterface::SignalAudioSinkStreamLine_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkStreamLine_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalAudioSinkStreamMuted_cb() {
  return m_signal_SignalAudioSinkStreamMuted_cb;

}
void com_jci_bdsInterface::SignalAudioSinkStreamMuted_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkStreamMuted_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalAudioSinkStreamOpened_cb() {
  return m_signal_SignalAudioSinkStreamOpened_cb;

}
void com_jci_bdsInterface::SignalAudioSinkStreamOpened_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkStreamOpened_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalAudioSinkSupportedChanges_cb() {
  return m_signal_SignalAudioSinkSupportedChanges_cb;

}
void com_jci_bdsInterface::SignalAudioSinkSupportedChanges_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkSupportedChanges_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalAudioSinkSupportedPlayerSetting_cb() {
  return m_signal_SignalAudioSinkSupportedPlayerSetting_cb;

}
void com_jci_bdsInterface::SignalAudioSinkSupportedPlayerSetting_cb(uint32_t type,
                                                                    std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkSupportedPlayerSetting_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalAudioSinkSystemStatusChange_cb() {
  return m_signal_SignalAudioSinkSystemStatusChange_cb;

}
void com_jci_bdsInterface::SignalAudioSinkSystemStatusChange_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkSystemStatusChange_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalAudioSinkTrackChange_cb() {
  return m_signal_SignalAudioSinkTrackChange_cb;

}
void com_jci_bdsInterface::SignalAudioSinkTrackChange_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkTrackChange_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalAudioSinkTrackEnd_cb() {
  return m_signal_SignalAudioSinkTrackEnd_cb;

}
void com_jci_bdsInterface::SignalAudioSinkTrackEnd_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkTrackEnd_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalAudioSinkTrackMetaData_cb() {
  return m_signal_SignalAudioSinkTrackMetaData_cb;

}
void com_jci_bdsInterface::SignalAudioSinkTrackMetaData_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkTrackMetaData_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalAudioSinkTrackStart_cb() {
  return m_signal_SignalAudioSinkTrackStart_cb;

}
void com_jci_bdsInterface::SignalAudioSinkTrackStart_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalAudioSinkTrackStart_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalCallClientCallList_cb() {
  return m_signal_SignalCallClientCallList_cb;

}
void com_jci_bdsInterface::SignalCallClientCallList_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalCallClientCallList_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalCallClientStatus_cb() {
  return m_signal_SignalCallClientStatus_cb;

}
void com_jci_bdsInterface::SignalCallClientStatus_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalCallClientStatus_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalCallClientAudioConnect_cb() {
  return m_signal_SignalCallClientAudioConnect_cb;

}
void com_jci_bdsInterface::SignalCallClientAudioConnect_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalCallClientAudioConnect_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalCallClientAudioDisconnect_cb() {
  return m_signal_SignalCallClientAudioDisconnect_cb;

}
void com_jci_bdsInterface::SignalCallClientAudioDisconnect_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalCallClientAudioDisconnect_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalCallClientIndicator_cb() {
  return m_signal_SignalCallClientIndicator_cb;

}
void com_jci_bdsInterface::SignalCallClientIndicator_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalCallClientIndicator_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalCallClientOperator_cb() {
  return m_signal_SignalCallClientOperator_cb;

}
void com_jci_bdsInterface::SignalCallClientOperator_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalCallClientOperator_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalCallClientSubscriber_cb() {
  return m_signal_SignalCallClientSubscriber_cb;

}
void com_jci_bdsInterface::SignalCallClientSubscriber_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalCallClientSubscriber_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalCallClientMicVolumeChange_cb() {
  return m_signal_SignalCallClientMicVolumeChange_cb;

}
void com_jci_bdsInterface::SignalCallClientMicVolumeChange_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalCallClientMicVolumeChange_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalCallClientSpeakerVolumeChange_cb() {
  return m_signal_SignalCallClientSpeakerVolumeChange_cb;

}
void com_jci_bdsInterface::SignalCallClientSpeakerVolumeChange_cb(uint32_t type,
                                                                  std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalCallClientSpeakerVolumeChange_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalCallClientActivateVoiceDial_cb() {
  return m_signal_SignalCallClientActivateVoiceDial_cb;

}
void com_jci_bdsInterface::SignalCallClientActivateVoiceDial_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalCallClientActivateVoiceDial_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalCallClientDeActivateVoiceDial_cb() {
  return m_signal_SignalCallClientDeActivateVoiceDial_cb;

}
void com_jci_bdsInterface::SignalCallClientDeActivateVoiceDial_cb(uint32_t type,
                                                                  std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalCallClientDeActivateVoiceDial_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalCallClientSiriSupportStatus_cb() {
  return m_signal_SignalCallClientSiriSupportStatus_cb;

}
void com_jci_bdsInterface::SignalCallClientSiriSupportStatus_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalCallClientSiriSupportStatus_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalCallClientSiriEyesFreeMode_cb() {
  return m_signal_SignalCallClientSiriEyesFreeMode_cb;

}
void com_jci_bdsInterface::SignalCallClientSiriEyesFreeMode_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalCallClientSiriEyesFreeMode_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalCallClientSiriDisableNoiseReduction_cb() {
  return m_signal_SignalCallClientSiriDisableNoiseReduction_cb;

}
void com_jci_bdsInterface::SignalCallClientSiriDisableNoiseReduction_cb(uint32_t type,
                                                                        std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalCallClientSiriDisableNoiseReduction_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalPhoneStatus_cb() {
  return m_signal_SignalPhoneStatus_cb;

}
void com_jci_bdsInterface::SignalPhoneStatus_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalPhoneStatus_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalCallClientCmdError_cb() {
  return m_signal_SignalCallClientCmdError_cb;

}
void com_jci_bdsInterface::SignalCallClientCmdError_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalCallClientCmdError_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalCallClientScoCodecId_cb() {
  return m_signal_SignalCallClientScoCodecId_cb;

}
void com_jci_bdsInterface::SignalCallClientScoCodecId_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalCallClientScoCodecId_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalMessageClientConfigured_cb() {
  return m_signal_SignalMessageClientConfigured_cb;

}
void com_jci_bdsInterface::SignalMessageClientConfigured_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalMessageClientConfigured_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalMessageClientFolderListing_cb() {
  return m_signal_SignalMessageClientFolderListing_cb;

}
void com_jci_bdsInterface::SignalMessageClientFolderListing_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalMessageClientFolderListing_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalMessageClientMessageDeleted_cb() {
  return m_signal_SignalMessageClientMessageDeleted_cb;

}
void com_jci_bdsInterface::SignalMessageClientMessageDeleted_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalMessageClientMessageDeleted_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalMessageClientMessageGotten_cb() {
  return m_signal_SignalMessageClientMessageGotten_cb;

}
void com_jci_bdsInterface::SignalMessageClientMessageGotten_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalMessageClientMessageGotten_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalMessageClientMessageListing_cb() {
  return m_signal_SignalMessageClientMessageListing_cb;

}
void com_jci_bdsInterface::SignalMessageClientMessageListing_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalMessageClientMessageListing_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalMessageClientMessageNotification_cb() {
  return m_signal_SignalMessageClientMessageNotification_cb;

}
void com_jci_bdsInterface::SignalMessageClientMessageNotification_cb(uint32_t type,
                                                                     std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalMessageClientMessageNotification_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalMessageClientMessagePushed_cb() {
  return m_signal_SignalMessageClientMessagePushed_cb;

}
void com_jci_bdsInterface::SignalMessageClientMessagePushed_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalMessageClientMessagePushed_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalMessageClientMessageSetStatus_cb() {
  return m_signal_SignalMessageClientMessageSetStatus_cb;

}
void com_jci_bdsInterface::SignalMessageClientMessageSetStatus_cb(uint32_t type,
                                                                  std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalMessageClientMessageSetStatus_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalNetworkClientConnected_cb() {
  return m_signal_SignalNetworkClientConnected_cb;

}
void com_jci_bdsInterface::SignalNetworkClientConnected_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalNetworkClientConnected_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalNetworkClientDisconnected_cb() {
  return m_signal_SignalNetworkClientDisconnected_cb;

}
void com_jci_bdsInterface::SignalNetworkClientDisconnected_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalNetworkClientDisconnected_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalPimClientImportStatus_cb() {
  return m_signal_SignalPimClientImportStatus_cb;

}
void com_jci_bdsInterface::SignalPimClientImportStatus_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalPimClientImportStatus_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalFileServerInfoEvent_cb() {
  return m_signal_SignalFileServerInfoEvent_cb;

}
void com_jci_bdsInterface::SignalFileServerInfoEvent_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalFileServerInfoEvent_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalFileServerFileAcceptanceStatus_cb() {
  return m_signal_SignalFileServerFileAcceptanceStatus_cb;

}
void com_jci_bdsInterface::SignalFileServerFileAcceptanceStatus_cb(uint32_t type,
                                                                   std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalFileServerFileAcceptanceStatus_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalFileServerDataFileInProgressStatus_cb() {
  return m_signal_SignalFileServerDataFileInProgressStatus_cb;

}
void com_jci_bdsInterface::SignalFileServerDataFileInProgressStatus_cb(uint32_t type,
                                                                       std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalFileServerDataFileInProgressStatus_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalServiceLessAudioConnectStatus_cb() {
  return m_signal_SignalServiceLessAudioConnectStatus_cb;

}
void com_jci_bdsInterface::SignalServiceLessAudioConnectStatus_cb(uint32_t type,
                                                                  std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalServiceLessAudioConnectStatus_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalServiceLessAudioDisconnectStatus_cb() {
  return m_signal_SignalServiceLessAudioDisconnectStatus_cb;

}
void com_jci_bdsInterface::SignalServiceLessAudioDisconnectStatus_cb(uint32_t type,
                                                                     std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalServiceLessAudioDisconnectStatus_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalServiceLessAclConnectStatus_cb() {
  return m_signal_SignalServiceLessAclConnectStatus_cb;

}
void com_jci_bdsInterface::SignalServiceLessAclConnectStatus_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalServiceLessAclConnectStatus_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector < uint8_t
                                       >> )>> com_jci_bdsInterface::signal_SignalServiceLessAclDisconnectStatus_cb() {
  return m_signal_SignalServiceLessAclDisconnectStatus_cb;

}
void com_jci_bdsInterface::SignalServiceLessAclDisconnectStatus_cb(uint32_t type,
                                                                   std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalServiceLessAclDisconnectStatus_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalBTChipFailure_cb() {
  return m_signal_SignalBTChipFailure_cb;

}
void com_jci_bdsInterface::SignalBTChipFailure_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalBTChipFailure_cb)(type, data);

}
std::shared_ptr <DBus::Signal<void(uint32_t,
                                   std::tuple < std::vector
                                       < uint8_t >> )>> com_jci_bdsInterface::signal_SignalDeviceAddressGet_cb() {
  return m_signal_SignalDeviceAddressGet_cb;

}
void com_jci_bdsInterface::SignalDeviceAddressGet_cb(uint32_t type, std::tuple <std::vector<uint8_t>> data) {
  (*m_signal_SignalDeviceAddressGet_cb)(type, data);

}
