#ifndef COM_JCI_USBMPROXY_H
#define COM_JCI_USBMPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_usbmProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_usbmProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_usbmProxy> create(std::string name = "com.jci.usbm");
  std::tuple<std::string, uint32_t, uint32_t> GetAlbumArt(std::tuple<uint32_t, uint32_t> album_art);
  std::tuple<uint32_t, uint32_t> SelectDevice(std::tuple<uint32_t> select_device);
  int32_t PlaybackCommand(std::tuple<uint32_t, uint32_t, uint32_t> playback_command);
  Invalid PlayResume(std::tuple<uint32_t, uint32_t> play_resume);
  std::tuple<uint32_t, uint32_t, uint32_t> PlayContext(Invalid play_context);
  int32_t SetRepeatMode(uint32_t dev_id, uint32_t repeat_mode);
  int32_t SetShuffleMode(uint32_t dev_id, uint32_t shuffle_mode);
  DBus::MultipleReturn<std::tuple<std::vector<std::tuple<uint32_t,
                                                         uint32_t,
                                                         std::string,
                                                         uint32_t,
                                                         uint32_t,
                                                         bool,
                                                         bool,
                                                         bool,
                                                         uint32_t,
                                                         uint32_t,
                                                         std::string,
                                                         std::string>>>, int32_t> GetDeviceList();
  DBus::MultipleReturn<std::tuple<uint32_t, std::string, std::string, std::string, std::string>,
                       int32_t> GetCurrentObjectInfo();
  int32_t StartSeeking(uint32_t dev_id, uint32_t sec_step, uint32_t seek_dir);
  int32_t PlaybackJumpToPosition(uint32_t dev_id, uint32_t new_pb_position);
  std::tuple<std::string, uint32_t> MoreLikeThis(uint32_t device_id);
  int32_t SetLanguage(int32_t sys_lang);
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t,
                                                    uint32_t,
                                                    std::string,
                                                    uint32_t,
                                                    uint32_t,
                                                    bool,
                                                    bool,
                                                    bool,
                                                    uint32_t,
                                                    uint32_t,
                                                    std::string,
                                                    std::string>)>> signal_DeviceConnected();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, int32_t)>> signal_DeviceDisconnected();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t,
                                                    uint32_t,
                                                    std::string,
                                                    uint32_t,
                                                    uint32_t,
                                                    bool,
                                                    bool,
                                                    bool,
                                                    uint32_t,
                                                    uint32_t,
                                                    std::string,
                                                    std::string>)>> signal_UpdateDeviceInfo();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_PlayComplete();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, int32_t)>> signal_DeviceSelected();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t,
                                                    uint32_t,
                                                    std::string,
                                                    uint32_t,
                                                    bool,
                                                    bool>)>> signal_MetadataBrowsingPossible();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t, std::string, uint32_t>)>> signal_MltPossible();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t,
                                                    uint32_t,
                                                    std::string,
                                                    uint32_t,
                                                    bool,
                                                    bool>)>> signal_PlaybackPossible();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t,
                                                    uint32_t,
                                                    std::string,
                                                    uint32_t>)>> signal_FolderBrowsingPossible();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> signal_DeviceError();
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> signal_PlaybackInfo();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t, uint32_t>)>> signal_DbUpdate();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t>)>> signal_AlbumArtReady();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t,
                                                    std::string,
                                                    std::string,
                                                    std::string,
                                                    std::string>)>> signal_CurrentObjectInfo();
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> signal_PlaybackInterrupted();
 protected:
  std::shared_ptr<DBus::MethodProxy<std::tuple<std::string, uint32_t, uint32_t>(std::tuple<uint32_t, uint32_t>)>>
      m_method_GetAlbumArt;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t, uint32_t>(std::tuple<uint32_t>)>> m_method_SelectDevice;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::tuple<uint32_t, uint32_t, uint32_t>)>> m_method_PlaybackCommand;
  std::shared_ptr<DBus::MethodProxy<Invalid(std::tuple<uint32_t, uint32_t>)>> m_method_PlayResume;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t, uint32_t, uint32_t>(Invalid)>> m_method_PlayContext;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t)>> m_method_SetRepeatMode;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t)>> m_method_SetShuffleMode;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::tuple<std::vector<std::tuple<uint32_t,
                                                                                           uint32_t,
                                                                                           std::string,
                                                                                           uint32_t,
                                                                                           uint32_t,
                                                                                           bool,
                                                                                           bool,
                                                                                           bool,
                                                                                           uint32_t,
                                                                                           uint32_t,
                                                                                           std::string,
                                                                                           std::string>>>, int32_t>()>>
      m_method_GetDeviceList;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::tuple<uint32_t,
                                                                    std::string,
                                                                    std::string,
                                                                    std::string,
                                                                    std::string>, int32_t>()>>
      m_method_GetCurrentObjectInfo;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t, uint32_t)>> m_method_StartSeeking;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t)>> m_method_PlaybackJumpToPosition;
  std::shared_ptr<DBus::MethodProxy<std::tuple<std::string, uint32_t>(uint32_t)>> m_method_MoreLikeThis;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_SetLanguage;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t,
                                                    uint32_t,
                                                    std::string,
                                                    uint32_t,
                                                    uint32_t,
                                                    bool,
                                                    bool,
                                                    bool,
                                                    uint32_t,
                                                    uint32_t,
                                                    std::string,
                                                    std::string>)>> m_signalproxy_DeviceConnected;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, int32_t)>> m_signalproxy_DeviceDisconnected;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t,
                                                    uint32_t,
                                                    std::string,
                                                    uint32_t,
                                                    uint32_t,
                                                    bool,
                                                    bool,
                                                    bool,
                                                    uint32_t,
                                                    uint32_t,
                                                    std::string,
                                                    std::string>)>> m_signalproxy_UpdateDeviceInfo;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_PlayComplete;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, int32_t)>> m_signalproxy_DeviceSelected;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t, std::string, uint32_t, bool, bool>)>>
      m_signalproxy_MetadataBrowsingPossible;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t, std::string, uint32_t>)>>
      m_signalproxy_MltPossible;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t, std::string, uint32_t, bool, bool>)>>
      m_signalproxy_PlaybackPossible;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t, std::string, uint32_t>)>>
      m_signalproxy_FolderBrowsingPossible;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t>)>> m_signalproxy_DeviceError;
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> m_signalproxy_PlaybackInfo;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint32_t, uint32_t>)>> m_signalproxy_DbUpdate;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t>)>> m_signalproxy_AlbumArtReady;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, std::string, std::string, std::string, std::string>)>>
      m_signalproxy_CurrentObjectInfo;
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> m_signalproxy_PlaybackInterrupted;
};
#endif /* COM_JCI_USBMPROXY_H */
