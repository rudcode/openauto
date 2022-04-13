#ifndef COM_JCI_BTMUSICPROXY_H
#define COM_JCI_BTMUSICPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_btmusicProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_btmusicProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_btmusicProxy> create(std::string name = "com.jci.btmusic");
  int32_t StartStreaming();
  int32_t StopStreaming();
  int32_t StreamingAudioCmd(uint32_t commandType);
  int32_t GetTrackInfo();
  int32_t BrowseFolderUp(uint32_t folderType);
  int32_t BrowseFolderDown(uint32_t index);
  int32_t GetBrowseItemTitleForFolder(uint32_t itemStartIndex, uint32_t itemEndIndex, uint32_t requestedPage);
  int32_t GetNowPlayListTitleForFile(uint32_t itemStartIndex, uint32_t itemEndIndex, uint32_t requestedPage);
  int32_t PlayBrowseItem(uint32_t playScope, uint32_t playItemId);
  int32_t SetLanguage(int32_t sys_lang);
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_StreamingStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> signal_StreamingAudioCmdStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> signal_StreamingPlayerStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> signal_TrackInformation();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_DeviceBatteryIndicator();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_BusyReason();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_TrackChangeIndicator();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_TrackPositionIndicator();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_NowPlayingChangeIndicator();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t, uint32_t)>> signal_SettingsStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> signal_PlayerSettingsInfo();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> signal_FolderBrowseItemTitleResponse();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> signal_BrowseNowPlayingTitleResponse();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> signal_BrowseFolderResponse();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_BrowseStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_BrowseConnStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> signal_NowPlayingInfo();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_MusicProfileSupported();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_StartStreaming;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_StopStreaming;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_StreamingAudioCmd;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetTrackInfo;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_BrowseFolderUp;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_BrowseFolderDown;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t, uint32_t)>> m_method_GetBrowseItemTitleForFolder;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t, uint32_t)>> m_method_GetNowPlayListTitleForFile;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t)>> m_method_PlayBrowseItem;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_SetLanguage;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_StreamingStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> m_signalproxy_StreamingAudioCmdStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> m_signalproxy_StreamingPlayerStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> m_signalproxy_TrackInformation;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_DeviceBatteryIndicator;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_BusyReason;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_TrackChangeIndicator;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_TrackPositionIndicator;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_NowPlayingChangeIndicator;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t, uint32_t)>> m_signalproxy_SettingsStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> m_signalproxy_PlayerSettingsInfo;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_FolderBrowseItemTitleResponse;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>>
      m_signalproxy_BrowseNowPlayingTitleResponse;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint8_t>>)>> m_signalproxy_BrowseFolderResponse;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_BrowseStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_BrowseConnStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> m_signalproxy_NowPlayingInfo;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_MusicProfileSupported;
};
#endif /* COM_JCI_BTMUSICPROXY_H */
