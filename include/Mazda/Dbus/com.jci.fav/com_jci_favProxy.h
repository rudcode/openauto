#ifndef COM_JCI_FAVPROXY_H
#define COM_JCI_FAVPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_favProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_favProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_favProxy> create(std::string name = "com.jci.fav");
  DBus::MultipleReturn<int32_t, uint32_t, int32_t, int32_t, bool, uint32_t> GetFavoriteMax(int32_t requestId,
                                                                                           uint32_t category,
                                                                                           uint32_t deviceId);
  DBus::MultipleReturn<int32_t, uint32_t, int32_t, bool> AddFavoriteRadio(int32_t requestId,
                                                                          std::string displayText,
                                                                          int32_t replaceFavId,
                                                                          uint32_t stationType,
                                                                          double frequency,
                                                                          std::string stationName,
                                                                          uint16_t piCode,
                                                                          uint32_t hdSPS,
                                                                          uint8_t xM_step,
                                                                          uint8_t xM_category,
                                                                          uint8_t xM_channel,
                                                                          uint8_t xM_SID,
                                                                          std::string relayName,
                                                                          std::tuple<std::string,
                                                                                     uint16_t,
                                                                                     uint16_t,
                                                                                     uint8_t,
                                                                                     std::string> fav_dab_data);
  DBus::MultipleReturn<int32_t, uint32_t> DeleteFavorite(int32_t requestId,
                                                         uint32_t category,
                                                         int32_t favId,
                                                         uint32_t deviceId);
  DBus::MultipleReturn<int32_t, uint32_t> MoveFavorite(int32_t requestId,
                                                       uint32_t category,
                                                       int32_t favId,
                                                       uint32_t deviceId,
                                                       int32_t oldIndex,
                                                       int32_t newIndex);
  DBus::MultipleReturn<int32_t, uint32_t> RenameFavorite(int32_t requestId,
                                                         uint32_t category,
                                                         int32_t favId,
                                                         uint32_t deviceId,
                                                         std::string displayText);
  DBus::MultipleReturn<int32_t,
                       int32_t,
                       uint32_t,
                       double,
                       std::string,
                       uint16_t,
                       uint32_t,
                       uint8_t,
                       uint8_t,
                       uint8_t,
                       uint8_t,
                       uint32_t,
                       std::tuple<std::string,
                                  uint16_t,
                                  uint16_t,
                                  uint8_t,
                                  std::string>> GetFavoriteRadio(int32_t requestId, int32_t favId);
  DBus::MultipleReturn<int32_t,
                       uint32_t,
                       int32_t,
                       int32_t,
                       int32_t,
                       std::tuple<std::vector<std::tuple<uint32_t,
                                                         std::string,
                                                         uint32_t,
                                                         std::string,
                                                         bool,
                                                         std::string,
                                                         std::string>>>> GetFavoriteList(int32_t requestId,
                                                                                         uint32_t category,
                                                                                         uint32_t deviceId,
                                                                                         int32_t startIndex,
                                                                                         int32_t maxItems);
  DBus::MultipleReturn<int32_t, uint32_t> RenameTuneMixFavorite(int32_t requestId,
                                                                uint32_t tuneMixID,
                                                                std::string displayText);
  DBus::MultipleReturn<int32_t, uint32_t, int32_t, bool> AddFavoriteComm(int32_t requestId,
                                                                         std::string displayText,
                                                                         int32_t replaceFavId,
                                                                         uint32_t deviceId,
                                                                         uint32_t contactId,
                                                                         uint32_t contactType,
                                                                         std::string contactName,
                                                                         std::string phoneNumber);
  DBus::MultipleReturn<int32_t,
                       int32_t,
                       uint32_t,
                       std::string,
                       std::string,
                       std::string,
                       std::tuple<std::vector<std::tuple<uint32_t, std::string>>>,
                       std::tuple<uint32_t,
                                  std::string,
                                  std::string,
                                  std::string,
                                  std::string,
                                  std::string>> GetFavoriteContactDetail(int32_t requestId,
                                                                         int32_t favId,
                                                                         uint32_t deviceId);
  DBus::MultipleReturn<int32_t,
                       int32_t,
                       uint32_t,
                       uint32_t,
                       std::string,
                       std::string,
                       uint32_t> GetFavoriteComm(int32_t requestId, int32_t favId, uint32_t deviceId);
  DBus::MultipleReturn<int32_t,
                       int32_t,
                       uint32_t,
                       double,
                       std::string,
                       uint16_t,
                       uint32_t,
                       uint8_t,
                       uint8_t,
                       uint8_t,
                       uint8_t,
                       uint32_t,
                       std::tuple<std::string, uint16_t, uint16_t, uint8_t>> RadioFavoriteSeek(int32_t requestId,
                                                                                               uint32_t radioType,
                                                                                               double frequency,
                                                                                               uint32_t hdSPS,
                                                                                               uint8_t xM_channel,
                                                                                               int32_t button,
                                                                                               std::tuple<std::string,
                                                                                                          uint16_t,
                                                                                                          uint16_t,
                                                                                                          uint8_t,
                                                                                                          std::string> fav_dab_data);
  DBus::MultipleReturn<int32_t, uint32_t> ReplaceFavoriteXMChannel(int32_t requestId,
                                                                   std::string stationName,
                                                                   uint8_t xM_channel,
                                                                   uint8_t xM_SID);
  DBus::MultipleReturn<int32_t, uint16_t, uint32_t> ReplaceFavoriteSXMChannel(int32_t requestId,
                                                                              std::string stationName,
                                                                              uint16_t xM_channel,
                                                                              uint32_t xM_SID);
  uint32_t UpdateFromTunerStatus(std::tuple<uint8_t,
                                            uint8_t,
                                            uint8_t,
                                            uint8_t,
                                            uint8_t,
                                            bool,
                                            std::vector<uint8_t>> tuner_status);
  void CurrentTunedChannelInfo(uint32_t radioType,
                               bool tuneStatus,
                               double frequency,
                               uint16_t piCode,
                               uint32_t hdSPS,
                               uint8_t xM_channel,
                               std::tuple<std::string, uint16_t, uint16_t, uint8_t> fav_dab_data);
  DBus::MultipleReturn<int32_t, uint32_t> RadioFastFavoriteSeek(int32_t requestId,
                                                                int32_t button,
                                                                uint32_t fimGroupAtKeyPressed);
  DBus::MultipleReturn<int32_t, int32_t, std::tuple<std::vector<uint32_t>>> GetFavoriteXMADAudio(int32_t requestId);
  DBus::MultipleReturn<uint32_t, uint32_t> DelXMADChannelFavID(uint32_t xmChannelId);
  DBus::MultipleReturn<uint32_t, uint32_t> ShowSXMSFav(uint32_t requestID, uint32_t sXMSFavStatus);
  uint32_t SmartFavoritesImpactList(std::tuple<std::vector<uint32_t>> chId_Arry);
  DBus::MultipleReturn<uint32_t, uint32_t> GetXMChipType(uint32_t requestID);
  DBus::MultipleReturn<uint32_t, uint32_t> GetTunemixactiveStatus(uint32_t requestID);
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> signal_SeekStatusResp();
  std::shared_ptr<DBus::SignalProxy<void(int32_t,
                                         uint32_t,
                                         double,
                                         std::string,
                                         uint16_t,
                                         uint32_t,
                                         uint8_t,
                                         uint8_t,
                                         uint8_t,
                                         uint8_t,
                                         uint32_t,
                                         std::tuple<std::string,
                                                    uint16_t,
                                                    uint16_t,
                                                    uint8_t,
                                                    std::string>)>> signal_FavRadioChangeEvent();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, bool)>> signal_SendActiveFavIdEvent();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_SendFavInitStatusEvent();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_XMADFavAddedEvent();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_XMADFavDeletedEvent();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint32_t>>)>> signal_SetSmartFavoritesImpactList();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_XMChiptype();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_TuneMixActiveStatus();
 protected:
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t, int32_t, int32_t, bool, uint32_t>(int32_t,
                                                                                                              uint32_t,
                                                                                                              uint32_t)>>
      m_method_GetFavoriteMax;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t, int32_t, bool>(int32_t,
                                                                                           std::string,
                                                                                           int32_t,
                                                                                           uint32_t,
                                                                                           double,
                                                                                           std::string,
                                                                                           uint16_t,
                                                                                           uint32_t,
                                                                                           uint8_t,
                                                                                           uint8_t,
                                                                                           uint8_t,
                                                                                           uint8_t,
                                                                                           std::string,
                                                                                           std::tuple<std::string,
                                                                                                      uint16_t,
                                                                                                      uint16_t,
                                                                                                      uint8_t,
                                                                                                      std::string>)>>
      m_method_AddFavoriteRadio;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t>(int32_t, uint32_t, int32_t, uint32_t)>>
      m_method_DeleteFavorite;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t>(int32_t,
                                                                            uint32_t,
                                                                            int32_t,
                                                                            uint32_t,
                                                                            int32_t,
                                                                            int32_t)>> m_method_MoveFavorite;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t>(int32_t,
                                                                            uint32_t,
                                                                            int32_t,
                                                                            uint32_t,
                                                                            std::string)>> m_method_RenameFavorite;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t,
                                                         int32_t,
                                                         uint32_t,
                                                         double,
                                                         std::string,
                                                         uint16_t,
                                                         uint32_t,
                                                         uint8_t,
                                                         uint8_t,
                                                         uint8_t,
                                                         uint8_t,
                                                         uint32_t,
                                                         std::tuple<std::string,
                                                                    uint16_t,
                                                                    uint16_t,
                                                                    uint8_t,
                                                                    std::string>>(int32_t, int32_t)>>
      m_method_GetFavoriteRadio;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t,
                                                         uint32_t,
                                                         int32_t,
                                                         int32_t,
                                                         int32_t,
                                                         std::tuple<std::vector<std::tuple<uint32_t,
                                                                                           std::string,
                                                                                           uint32_t,
                                                                                           std::string,
                                                                                           bool,
                                                                                           std::string,
                                                                                           std::string>>>>(int32_t,
                                                                                                           uint32_t,
                                                                                                           uint32_t,
                                                                                                           int32_t,
                                                                                                           int32_t)>>
      m_method_GetFavoriteList;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t>(int32_t, uint32_t, std::string)>>
      m_method_RenameTuneMixFavorite;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t, int32_t, bool>(int32_t,
                                                                                           std::string,
                                                                                           int32_t,
                                                                                           uint32_t,
                                                                                           uint32_t,
                                                                                           uint32_t,
                                                                                           std::string,
                                                                                           std::string)>>
      m_method_AddFavoriteComm;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t,
                                                         int32_t,
                                                         uint32_t,
                                                         std::string,
                                                         std::string,
                                                         std::string,
                                                         std::tuple<std::vector<std::tuple<uint32_t, std::string>>>,
                                                         std::tuple<uint32_t,
                                                                    std::string,
                                                                    std::string,
                                                                    std::string,
                                                                    std::string,
                                                                    std::string>>(int32_t, int32_t, uint32_t)>>
      m_method_GetFavoriteContactDetail;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t,
                                                         int32_t,
                                                         uint32_t,
                                                         uint32_t,
                                                         std::string,
                                                         std::string,
                                                         uint32_t>(int32_t, int32_t, uint32_t)>>
      m_method_GetFavoriteComm;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t,
                                                         int32_t,
                                                         uint32_t,
                                                         double,
                                                         std::string,
                                                         uint16_t,
                                                         uint32_t,
                                                         uint8_t,
                                                         uint8_t,
                                                         uint8_t,
                                                         uint8_t,
                                                         uint32_t,
                                                         std::tuple<std::string, uint16_t, uint16_t, uint8_t>>(int32_t,
                                                                                                               uint32_t,
                                                                                                               double,
                                                                                                               uint32_t,
                                                                                                               uint8_t,
                                                                                                               int32_t,
                                                                                                               std::tuple<
                                                                                                                   std::string,
                                                                                                                   uint16_t,
                                                                                                                   uint16_t,
                                                                                                                   uint8_t,
                                                                                                                   std::string>)>>
      m_method_RadioFavoriteSeek;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t>(int32_t, std::string, uint8_t, uint8_t)>>
      m_method_ReplaceFavoriteXMChannel;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint16_t, uint32_t>(int32_t,
                                                                                      std::string,
                                                                                      uint16_t,
                                                                                      uint32_t)>>
      m_method_ReplaceFavoriteSXMChannel;
  std::shared_ptr<DBus::MethodProxy<uint32_t(std::tuple<uint8_t,
                                                        uint8_t,
                                                        uint8_t,
                                                        uint8_t,
                                                        uint8_t,
                                                        bool,
                                                        std::vector<uint8_t>>)>> m_method_UpdateFromTunerStatus;
  std::shared_ptr<DBus::MethodProxy<void(uint32_t,
                                         bool,
                                         double,
                                         uint16_t,
                                         uint32_t,
                                         uint8_t,
                                         std::tuple<std::string, uint16_t, uint16_t, uint8_t>)>>
      m_method_CurrentTunedChannelInfo;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t>(int32_t, int32_t, uint32_t)>>
      m_method_RadioFastFavoriteSeek;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, int32_t, std::tuple<std::vector<uint32_t>>>(int32_t)>>
      m_method_GetFavoriteXMADAudio;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t>(uint32_t)>> m_method_DelXMADChannelFavID;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t>(uint32_t, uint32_t)>> m_method_ShowSXMSFav;
  std::shared_ptr<DBus::MethodProxy<uint32_t(std::tuple<std::vector<uint32_t>>)>> m_method_SmartFavoritesImpactList;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t>(uint32_t)>> m_method_GetXMChipType;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t>(uint32_t)>>
      m_method_GetTunemixactiveStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> m_signalproxy_SeekStatusResp;
  std::shared_ptr<DBus::SignalProxy<void(int32_t,
                                         uint32_t,
                                         double,
                                         std::string,
                                         uint16_t,
                                         uint32_t,
                                         uint8_t,
                                         uint8_t,
                                         uint8_t,
                                         uint8_t,
                                         uint32_t,
                                         std::tuple<std::string, uint16_t, uint16_t, uint8_t, std::string>)>>
      m_signalproxy_FavRadioChangeEvent;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, bool)>> m_signalproxy_SendActiveFavIdEvent;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_SendFavInitStatusEvent;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_XMADFavAddedEvent;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_XMADFavDeletedEvent;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<uint32_t>>)>> m_signalproxy_SetSmartFavoritesImpactList;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_XMChiptype;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_TuneMixActiveStatus;
};
#endif /* COM_JCI_FAVPROXY_H */
