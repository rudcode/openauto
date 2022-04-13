#ifndef COM_JCI_USBMSPROXY_H
#define COM_JCI_USBMSPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_usbmsProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_usbmsProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_usbmsProxy> create(std::string name = "com.jci.usbms");
  std::tuple<uint32_t,
             std::vector<std::tuple<std::string, uint32_t, int32_t>>,
             uint32_t> BrowseContext(Invalid browseContext);
  std::tuple<uint32_t, std::string, std::string, uint32_t> GetBrowseFolderInfo(Invalid getBrowseFolderInfo);
  std::tuple<uint32_t> PauseResume(std::tuple<uint32_t> pauseResume);
  Invalid PlayResume(std::tuple<uint32_t, int32_t> playResume);
  Invalid PlayContext(Invalid playContext);
  std::tuple<uint32_t> StopPlayback(std::tuple<uint32_t> stopPlayback);
  std::tuple<std::string, uint32_t, uint32_t> GetAlbumArt(std::tuple<uint32_t, uint32_t> getAlbumArt);
  std::tuple<int32_t> PlayerSeek(std::tuple<uint32_t, int32_t, uint32_t> playerSeek);
  std::tuple<int32_t> PlayTrackControl(std::tuple<uint32_t, int32_t, uint32_t> playTrackCtrl);
  std::tuple<int32_t> SetPlayerSettings(std::tuple<uint32_t, int32_t, int32_t> setPlayerSettings);
  Invalid GetStorageDevicesList();
  Invalid GetPlayTrackInfo();
  Invalid MoreLikeThis(std::tuple<uint32_t> moreLikeThis);
  Invalid GetSongsInfoList(std::tuple<uint32_t, uint32_t, uint32_t> getSongsInfoList);
  std::tuple<int32_t> SetLanguage(std::tuple<uint32_t> setLanguage);
  std::tuple<std::vector<std::tuple<uint32_t, int32_t, std::string>>> GetAlphabet(std::tuple<uint32_t,
                                                                                             std::tuple<std::vector<std::tuple<
                                                                                                 int32_t,
                                                                                                 uint32_t,
                                                                                                 uint32_t,
                                                                                                 uint32_t,
                                                                                                 int32_t>>>> getAlphabet);
  std::tuple<uint64_t,
             uint64_t,
             uint32_t,
             uint16_t,
             uint8_t,
             uint8_t,
             uint32_t> GetTaggingInfo(std::tuple<uint32_t> getTaggingInfo);
  std::tuple<uint32_t> iPodSendTag(Invalid iPodSendTag);
  std::tuple<int32_t> SaveData();
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> signal_StorageAttached();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t>)>> signal_StorageDetached();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t,
                                                    int32_t,
                                                    int32_t,
                                                    uint32_t,
                                                    uint32_t>)>> signal_SyncEvent();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, int32_t, uint32_t>)>> signal_DbUpdate();
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> signal_TrackChanged();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t>)>> signal_PlayComplete();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> signal_PlaybackTime();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, int32_t>)>> signal_DeviceError();
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> signal_PlayerStateChanged();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, int32_t, int32_t>)>> signal_PlaybackSettingsChanged();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t>)>> signal_AlbumArtReady();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_Ping();
 protected:
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t,
                                               std::vector<std::tuple<std::string, uint32_t, int32_t>>,
                                               uint32_t>(Invalid)>> m_method_BrowseContext;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t, std::string, std::string, uint32_t>(Invalid)>>
      m_method_GetBrowseFolderInfo;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t>(std::tuple<uint32_t>)>> m_method_PauseResume;
  std::shared_ptr<DBus::MethodProxy<Invalid(std::tuple<uint32_t, int32_t>)>> m_method_PlayResume;
  std::shared_ptr<DBus::MethodProxy<Invalid(Invalid)>> m_method_PlayContext;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t>(std::tuple<uint32_t>)>> m_method_StopPlayback;
  std::shared_ptr<DBus::MethodProxy<std::tuple<std::string, uint32_t, uint32_t>(std::tuple<uint32_t, uint32_t>)>>
      m_method_GetAlbumArt;
  std::shared_ptr<DBus::MethodProxy<std::tuple<int32_t>(std::tuple<uint32_t, int32_t, uint32_t>)>> m_method_PlayerSeek;
  std::shared_ptr<DBus::MethodProxy<std::tuple<int32_t>(std::tuple<uint32_t, int32_t, uint32_t>)>>
      m_method_PlayTrackControl;
  std::shared_ptr<DBus::MethodProxy<std::tuple<int32_t>(std::tuple<uint32_t, int32_t, int32_t>)>>
      m_method_SetPlayerSettings;
  std::shared_ptr<DBus::MethodProxy<Invalid()>> m_method_GetStorageDevicesList;
  std::shared_ptr<DBus::MethodProxy<Invalid()>> m_method_GetPlayTrackInfo;
  std::shared_ptr<DBus::MethodProxy<Invalid(std::tuple<uint32_t>)>> m_method_MoreLikeThis;
  std::shared_ptr<DBus::MethodProxy<Invalid(std::tuple<uint32_t, uint32_t, uint32_t>)>> m_method_GetSongsInfoList;
  std::shared_ptr<DBus::MethodProxy<std::tuple<int32_t>(std::tuple<uint32_t>)>> m_method_SetLanguage;
  std::shared_ptr<DBus::MethodProxy<std::tuple<std::vector<std::tuple<uint32_t, int32_t, std::string>>>(std::tuple<
      uint32_t,
      std::tuple<std::vector<std::tuple<int32_t, uint32_t, uint32_t, uint32_t, int32_t>>>>)>> m_method_GetAlphabet;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint64_t,
                                               uint64_t,
                                               uint32_t,
                                               uint16_t,
                                               uint8_t,
                                               uint8_t,
                                               uint32_t>(std::tuple<uint32_t>)>> m_method_GetTaggingInfo;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t>(Invalid)>> m_method_iPodSendTag;
  std::shared_ptr<DBus::MethodProxy<std::tuple<int32_t>()>> m_method_SaveData;
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> m_signalproxy_StorageAttached;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t>)>> m_signalproxy_StorageDetached;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, int32_t, int32_t, uint32_t, uint32_t>)>>
      m_signalproxy_SyncEvent;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, int32_t, uint32_t>)>> m_signalproxy_DbUpdate;
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> m_signalproxy_TrackChanged;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t>)>> m_signalproxy_PlayComplete;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> m_signalproxy_PlaybackTime;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, int32_t>)>> m_signalproxy_DeviceError;
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> m_signalproxy_PlayerStateChanged;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, int32_t, int32_t>)>>
      m_signalproxy_PlaybackSettingsChanged;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t>)>> m_signalproxy_AlbumArtReady;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_Ping;
};
#endif /* COM_JCI_USBMSPROXY_H */
