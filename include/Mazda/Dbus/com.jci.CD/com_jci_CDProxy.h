#ifndef COM_JCI_CDPROXY_H
#define COM_JCI_CDPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_CDProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_CDProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_CDProxy> create(std::string name = "com.jci.CD");
  int32_t SourceChange_Req();
  int32_t Eject_Req();
  int32_t Play_Req();
  int32_t Pause_Req();
  int32_t Previous_Req();
  int32_t Next_Req();
  int32_t SetRepeat_Req(uint8_t repeat);
  int32_t SetRandom_Req(uint8_t random);
  int32_t Scan_Req();
  int32_t FastForward_Req();
  int32_t FastRewind_Req();
  DBus::MultipleReturn<uint8_t, int32_t> GetCDReadyStatus_Req();
  std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> GetCDStatus_Req();
  DBus::MultipleReturn<uint8_t, int32_t> Get_Availability_Req();
  std::tuple<uint8_t, std::string, uint8_t, bool, bool> UserSelection_Req(uint8_t itemType, uint16_t index);
  std::tuple<uint8_t, std::string, uint8_t, bool, bool> UserSelection_VR_Req(uint8_t itemType, uint16_t index);
  DBus::MultipleReturn<std::tuple<std::vector<std::tuple<uint16_t, uint8_t, std::string>>>,
                       int16_t,
                       int16_t> GetFolderContents_Req(uint16_t index, uint16_t itemsCount);
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>)>> signal_Status();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_Ready_Status();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_Repeat_Settings_Status();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_Random_Settings_Status();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint16_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t>)>> signal_Track_Play_Status();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::string,
                                                    std::string,
                                                    std::string,
                                                    std::string,
                                                    std::string,
                                                    std::string>)>> signal_Metadata_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_SourceChange_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> signal_RoutineTest_Response();
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> signal_Total_Track_Number();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_SourceChange_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Eject_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Play_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Pause_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Previous_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Next_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint8_t)>> m_method_SetRepeat_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint8_t)>> m_method_SetRandom_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_Scan_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_FastForward_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_FastRewind_Req;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint8_t, int32_t>()>> m_method_GetCDReadyStatus_Req;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>()>> m_method_GetCDStatus_Req;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint8_t, int32_t>()>> m_method_Get_Availability_Req;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint8_t, std::string, uint8_t, bool, bool>(uint8_t, uint16_t)>>
      m_method_UserSelection_Req;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint8_t, std::string, uint8_t, bool, bool>(uint8_t, uint16_t)>>
      m_method_UserSelection_VR_Req;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::tuple<std::vector<std::tuple<uint16_t,
                                                                                           uint8_t,
                                                                                           std::string>>>,
                                                         int16_t,
                                                         int16_t>(uint16_t, uint16_t)>> m_method_GetFolderContents_Req;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>)>> m_signalproxy_Status;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_Ready_Status;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_Repeat_Settings_Status;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_Random_Settings_Status;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t>)>>
      m_signalproxy_Track_Play_Status;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::string,
                                                    std::string,
                                                    std::string,
                                                    std::string,
                                                    std::string,
                                                    std::string>)>> m_signalproxy_Metadata_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_SourceChange_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t)>> m_signalproxy_RoutineTest_Response;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> m_signalproxy_Total_Track_Number;
};
#endif /* COM_JCI_CDPROXY_H */
