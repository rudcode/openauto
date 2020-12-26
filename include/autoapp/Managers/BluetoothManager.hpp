#pragma once

#include <sdbus-c++/sdbus-c++.h>
#include <atomic>
#include <set>

#include <string>
#include <future>

#include <tinyxml2.h>

#include <aasdk_proto/WifiInfoRequestMessage.pb.h>
#include <aasdk_proto/WifiInfoResponseMessage.pb.h>
#include <aasdk_proto/WifiSecurityResponseMessage.pb.h>

#include <autoapp/Configuration/IConfiguration.hpp>

#include <Mazda/Dbus/com.jci.pa.h>
#include <Mazda/Dbus/com.jci.bds.h>
#include <Mazda/Dbus/com.jci.bca.h>


class BDSClient : public sdbus::ProxyInterfaces<com::jci::bds_proxy> {
 public:
  BDSClient(std::string destination, std::string objectPath)
      : sdbus::ProxyInterfaces<com::jci::bds_proxy>(std::move(destination), std::move(objectPath)) {
    registerProxy();
  }

  ~BDSClient() {
    unregisterProxy();
  }

  void onSignaltest_cb(const uint32_t &type) override {}
  void onSignalReady_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalNotReady_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalDeviceDeleteInProgress_cb(const uint32_t &type,
                                         const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalDeviceDeleted_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalDeviceDeleteAllInProgress_cb(const uint32_t &type,
                                            const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalDeviceDeleteAll_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalDeviceDisconnectedAll_cb(const uint32_t &type,
                                        const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalDeviceDisconnectionProgress_cb(const uint32_t &type,
                                              const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalDeviceInquiryResult_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalDeviceNameStarted_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalDeviceNameSet_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalDeviceNameGet_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalDeviceAccessibilityGet_cb(const uint32_t &type,
                                         const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalDevicePair_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalDeviceServiceDiscovery_cb(const uint32_t &type,
                                         const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalDeviceWrittenAll_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalDeviceAuthenticate_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalRemoteSupportedFeatures_cb(const uint32_t &type,
                                          const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalDeviceGetConnectedDevices_cb(const uint32_t &type,
                                            const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalDeviceLocalOobData_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalDeviceExtendedSearchResult_cb(const uint32_t &type,
                                             const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalServiceEnableStatus_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalServiceDisableStatus_cb(const uint32_t &type,
                                       const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalConnected_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override;
  void onSignalDisconnected_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalServiceFeatures_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalServiceConfiguration_cb(const uint32_t &type,
                                       const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkAppChange_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkBatteryStatusChange_cb(const uint32_t &type,
                                               const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkBiased_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkBrowseConnect_cb(const uint32_t &type,
                                         const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkBrowseDisonnect_cb(const uint32_t &type,
                                           const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkBrowseFolderChange_cb(const uint32_t &type,
                                              const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkBrowseFolderContent_cb(const uint32_t &type,
                                               const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkBrowseFolderContents_cb(const uint32_t &type,
                                                const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkBrowseSearch_cb(const uint32_t &type,
                                        const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkBrowseUidsChange_cb(const uint32_t &type,
                                            const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkContentAddToNowPlaying_cb(const uint32_t &type,
                                                  const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkContentAttributes_cb(const uint32_t &type,
                                             const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkContentPlay_cb(const uint32_t &type,
                                       const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkMediaPosition_cb(const uint32_t &type,
                                         const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkPanelOperation_cb(const uint32_t &type,
                                          const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkPlaybackStatusChange_cb(const uint32_t &type,
                                                const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkPlayerAddressedChange_cb(const uint32_t &type,
                                                 const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkPlayerBrowsedChange_cb(const uint32_t &type,
                                               const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkPlayerItem_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkPlayerItems_cb(const uint32_t &type,
                                       const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkPlayerItemsChange_cb(const uint32_t &type,
                                             const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkPlayerNowContentChange_cb(const uint32_t &type,
                                                  const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkPlayerVolumeChange_cb(const uint32_t &type,
                                              const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkStreamClosed_cb(const uint32_t &type,
                                        const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkStreamConfigured_cb(const uint32_t &type,
                                            const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkStreamLine_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkStreamMuted_cb(const uint32_t &type,
                                       const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkStreamOpened_cb(const uint32_t &type,
                                        const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkSupportedChanges_cb(const uint32_t &type,
                                            const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkSupportedPlayerSetting_cb(const uint32_t &type,
                                                  const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkSystemStatusChange_cb(const uint32_t &type,
                                              const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkTrackChange_cb(const uint32_t &type,
                                       const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkTrackEnd_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkTrackMetaData_cb(const uint32_t &type,
                                         const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalAudioSinkTrackStart_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalCallClientCallList_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalCallClientStatus_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalCallClientAudioConnect_cb(const uint32_t &type,
                                         const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalCallClientAudioDisconnect_cb(const uint32_t &type,
                                            const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalCallClientIndicator_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalCallClientOperator_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalCallClientSubscriber_cb(const uint32_t &type,
                                       const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalCallClientMicVolumeChange_cb(const uint32_t &type,
                                            const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalCallClientSpeakerVolumeChange_cb(const uint32_t &type,
                                                const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalCallClientActivateVoiceDial_cb(const uint32_t &type,
                                              const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalCallClientDeActivateVoiceDial_cb(const uint32_t &type,
                                                const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalCallClientSiriSupportStatus_cb(const uint32_t &type,
                                              const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalCallClientSiriEyesFreeMode_cb(const uint32_t &type,
                                             const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalCallClientSiriDisableNoiseReduction_cb(const uint32_t &type,
                                                      const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalPhoneStatus_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalCallClientCmdError_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalCallClientScoCodecId_cb(const uint32_t &type,
                                       const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalMessageClientConfigured_cb(const uint32_t &type,
                                          const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalMessageClientFolderListing_cb(const uint32_t &type,
                                             const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalMessageClientMessageDeleted_cb(const uint32_t &type,
                                              const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalMessageClientMessageGotten_cb(const uint32_t &type,
                                             const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalMessageClientMessageListing_cb(const uint32_t &type,
                                              const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalMessageClientMessageNotification_cb(const uint32_t &type,
                                                   const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalMessageClientMessagePushed_cb(const uint32_t &type,
                                             const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalMessageClientMessageSetStatus_cb(const uint32_t &type,
                                                const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalNetworkClientConnected_cb(const uint32_t &type,
                                         const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalNetworkClientDisconnected_cb(const uint32_t &type,
                                            const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalPimClientImportStatus_cb(const uint32_t &type,
                                        const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalFileServerInfoEvent_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalFileServerFileAcceptanceStatus_cb(const uint32_t &type,
                                                 const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalFileServerDataFileInProgressStatus_cb(const uint32_t &type,
                                                     const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalServiceLessAudioConnectStatus_cb(const uint32_t &type,
                                                const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalServiceLessAudioDisconnectStatus_cb(const uint32_t &type,
                                                   const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalServiceLessAclConnectStatus_cb(const uint32_t &type,
                                              const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalServiceLessAclDisconnectStatus_cb(const uint32_t &type,
                                                 const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalBTChipFailure_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  void onSignalDeviceAddressGet_cb(const uint32_t &type, const sdbus::Struct<std::vector<uint8_t>> &data) override {}
  uint32_t serviceID = 0;
  uint32_t wifiPort = 0;
};

// DBus::ObjectProxy(connection, "/com/jci/bca", "com.jci.bca")

class BCAClient : public sdbus::ProxyInterfaces<com::jci::bca_proxy> {
 public:
  BCAClient(std::unique_ptr<sdbus::IConnection> &connection, std::string destination, std::string objectPath)
      : sdbus::ProxyInterfaces<com::jci::bca_proxy>(std::move(connection),
                                                    std::move(destination),
                                                    std::move(objectPath)) {
    registerProxy();
  }

  ~BCAClient() {
    unregisterProxy();
  }

  void onDontShowOnConnectionSettingStatusResp(const uint32_t &btDeviceId, const bool &setting) override {}
  void onConnectionStatusResp(const uint32_t &serviceId,
                              const uint32_t &connStatus,
                              const uint32_t &btDeviceId,
                              const uint32_t &status,
                              const sdbus::Struct<std::vector<uint8_t>> &terminalPath) override;
  void onHftReadyStatus(const uint32_t &hftReady, const uint32_t &reasonCode, const uint32_t &appId) override {}
  void onReadyStatus(const uint32_t &isReady, const uint32_t &reasonCode) override {}
  void onAddStatusResp(const uint32_t &addServiceId, const uint32_t &status) override {}
  void onDeviceUnbarringStatusResp(const uint32_t &btDeviceId, const uint32_t &status) override {}
  void onDeviceBluetoothSettingResp(const bool &btSetting) override {}
  void onAvailablePairedListResp(const uint32_t &totalPairedDevices,
                                 const sdbus::Struct<std::vector<uint8_t>> &pairedDeviceList) override {}
  void onSupportedProfilesResp(const sdbus::Struct<std::vector<uint8_t>> &supportedProfiles) override {}
  void onFirstHfpSupportedInfo(const bool &isHfpSupportedDevicePresent) override {}
  void onCarPlayConnectionStatus(const uint32_t &connStatus, const uint32_t &carPlayDeviceId) override {}
  void onAAutoEnableBt() override {}
  void onAAutoNoEntryAvailable(const uint32_t &deleteDeviceId) override {}
  void onReqStartAndroidAutoPairing() override {}
  void onReqStopAndroidAutoPairing() override {}
  void onReqDeleteDevice(const uint32_t &deleteDeviceId) override {}
  void onAAPairingSeqResult(const bool &result) override {}
  void onAndroidAutoPairingTimeout() override {}
  void onRequestStartAutoDownload(const uint32_t &btDeviceId) override {}
  void onDisableBluetoothRsp(const uint32_t &activeCallStatus) override {}
  void onConnectingCarPlayError() override {}

  uint32_t serviceID = 0;
  uint32_t wifiPort = 0;
};

class BluetoothManager {
 public:
  explicit BluetoothManager(autoapp::configuration::IConfiguration::Pointer configuration);
  void stop();
 private:
  autoapp::configuration::IConfiguration::Pointer configuration_;
  bool bdsconfigured = false;
  uint32_t serviceId = 0;
  BDSClient *bdsClient;
  BCAClient *bcaClient;

};

struct connectionInfo {
  std::string ipAddress;
  std::string macAddress;
};

int update_connection_info(connectionInfo &info);
std::string hostapd_config(const std::string &key);

class BluetoothConnection {
 public:
  explicit BluetoothConnection(uint32_t port);
  void handle_connect(const std::string &pty);

 private:
  int fd = 0;
  connectionInfo info;
  uint32_t port_;

  void handleWifiInfoRequest(uint8_t *buffer, uint16_t length);
  void handleWifiSecurityRequest(__attribute__((unused)) uint8_t *buffer, __attribute__((unused)) uint16_t length);
  static int handleWifiInfoRequestResponse(uint8_t *buffer, uint16_t length);
  void sendMessage(google::protobuf::MessageLite &message, uint16_t type) const;
};