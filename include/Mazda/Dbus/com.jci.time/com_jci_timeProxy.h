#ifndef COM_JCI_TIMEPROXY_H
#define COM_JCI_TIMEPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_timeProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_timeProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_timeProxy> create(std::string name = "com.jci.time");
  int32_t Connect(std::string client_name);
  int32_t Disconnect(std::string client_name);
  DBus::MultipleReturn<uint32_t, int16_t, uint8_t, uint32_t> GetDatetime(int16_t field_in);
  DBus::MultipleReturn<std::tuple<int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t>,
                       int16_t,
                       uint8_t,
                       uint32_t> GetDatetimeComposite(int16_t field_in);
  DBus::MultipleReturn<std::tuple<int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t>,
                       std::tuple<int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t>,
                       std::tuple<int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t>,
                       std::tuple<int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t>,
                       uint8_t,
                       uint32_t> GetDatetimeComponents();
  DBus::MultipleReturn<uint8_t,
                       std::tuple<int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t>,
                       uint32_t> RegisterForDatetimeChangeEvent(uint8_t time_req,
                                                                std::tuple<int16_t,
                                                                           uint8_t,
                                                                           uint8_t,
                                                                           uint8_t,
                                                                           uint8_t,
                                                                           uint8_t> event_time,
                                                                std::string client_name);
  DBus::MultipleReturn<uint8_t,
                       std::tuple<int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t>,
                       uint32_t> UnregisterFromDatetimeChangeEvent(uint8_t time_req,
                                                                   std::tuple<int16_t,
                                                                              uint8_t,
                                                                              uint8_t,
                                                                              uint8_t,
                                                                              uint8_t,
                                                                              uint8_t> event_time,
                                                                   std::string client_name);
  DBus::MultipleReturn<uint8_t, uint32_t> RegisterForOffsetChangeEvent(uint8_t offset_change_type);
  DBus::MultipleReturn<uint8_t, uint32_t> UnregisterFromOffsetChangeEvent(uint8_t offset_change_type);
  uint32_t SetDatetimeComponents(std::tuple<int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t> base_datetime,
                                 std::tuple<int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t> timezone_offset,
                                 std::tuple<int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t> daylightsaving_offset,
                                 std::tuple<int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t> user_offset);
  DBus::MultipleReturn<int16_t, uint8_t, uint32_t> SetDatetimeComposite(int16_t field_in,
                                                                        std::tuple<int16_t,
                                                                                   uint8_t,
                                                                                   uint8_t,
                                                                                   uint8_t,
                                                                                   uint8_t,
                                                                                   uint8_t> datetime_in);
  DBus::MultipleReturn<int16_t, uint8_t, uint32_t> SetDatetime(int16_t field_in, uint32_t datetime_in);
  DBus::MultipleReturn<uint32_t, uint32_t> GetWeekDay(std::tuple<int16_t,
                                                                 uint8_t,
                                                                 uint8_t,
                                                                 uint8_t,
                                                                 uint8_t,
                                                                 uint8_t> event_time);
  DBus::MultipleReturn<uint32_t, uint32_t> GetMonthDaysCount(std::tuple<int16_t,
                                                                        uint8_t,
                                                                        uint8_t,
                                                                        uint8_t,
                                                                        uint8_t,
                                                                        uint8_t> event_time);
  DBus::MultipleReturn<uint32_t, uint32_t> GetYearWeekNumber(std::tuple<int16_t,
                                                                        uint8_t,
                                                                        uint8_t,
                                                                        uint8_t,
                                                                        uint8_t,
                                                                        uint8_t> event_time);
  DBus::MultipleReturn<std::tuple<int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t>,
                       uint32_t> CalculateDateDiff(std::tuple<int16_t,
                                                              uint8_t,
                                                              uint8_t,
                                                              uint8_t,
                                                              uint8_t,
                                                              uint8_t> event_time_from,
                                                   std::tuple<int16_t,
                                                              uint8_t,
                                                              uint8_t,
                                                              uint8_t,
                                                              uint8_t,
                                                              uint8_t> event_time_to);
  DBus::MultipleReturn<std::tuple<int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t>,
                       uint32_t> CalculateTimeDiff(std::tuple<int16_t,
                                                              uint8_t,
                                                              uint8_t,
                                                              uint8_t,
                                                              uint8_t,
                                                              uint8_t> event_time_from,
                                                   std::tuple<int16_t,
                                                              uint8_t,
                                                              uint8_t,
                                                              uint8_t,
                                                              uint8_t,
                                                              uint8_t> event_time_to);
  DBus::MultipleReturn<std::tuple<int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t>,
                       uint32_t> CalculateDatetimeDiff(std::tuple<int16_t,
                                                                  uint8_t,
                                                                  uint8_t,
                                                                  uint8_t,
                                                                  uint8_t,
                                                                  uint8_t> event_time_from,
                                                       std::tuple<int16_t,
                                                                  uint8_t,
                                                                  uint8_t,
                                                                  uint8_t,
                                                                  uint8_t,
                                                                  uint8_t> event_time_to);
  std::shared_ptr<DBus::SignalProxy<void(uint8_t,
                                         std::tuple<int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t>,
                                         std::tuple<int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t>,
                                         int32_t)>> signal_FireEventMsg();
  std::shared_ptr<DBus::SignalProxy<void(int16_t, uint8_t, int16_t)>> signal_OffsetChangeMsg();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t(std::string)>> m_method_Connect;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::string)>> m_method_Disconnect;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, int16_t, uint8_t, uint32_t>(int16_t)>>
      m_method_GetDatetime;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::tuple<int16_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t>, int16_t, uint8_t, uint32_t>(int16_t)>>
      m_method_GetDatetimeComposite;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::tuple<int16_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t>,
                                                         std::tuple<int16_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t>,
                                                         std::tuple<int16_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t>,
                                                         std::tuple<int16_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t>,
                                                         uint8_t,
                                                         uint32_t>()>> m_method_GetDatetimeComponents;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint8_t,
                                                         std::tuple<int16_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t>,
                                                         uint32_t>(uint8_t,
                                                                   std::tuple<int16_t,
                                                                              uint8_t,
                                                                              uint8_t,
                                                                              uint8_t,
                                                                              uint8_t,
                                                                              uint8_t>,
                                                                   std::string)>>
      m_method_RegisterForDatetimeChangeEvent;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint8_t,
                                                         std::tuple<int16_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t>,
                                                         uint32_t>(uint8_t,
                                                                   std::tuple<int16_t,
                                                                              uint8_t,
                                                                              uint8_t,
                                                                              uint8_t,
                                                                              uint8_t,
                                                                              uint8_t>,
                                                                   std::string)>>
      m_method_UnregisterFromDatetimeChangeEvent;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint8_t, uint32_t>(uint8_t)>>
      m_method_RegisterForOffsetChangeEvent;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint8_t, uint32_t>(uint8_t)>>
      m_method_UnregisterFromOffsetChangeEvent;
  std::shared_ptr<DBus::MethodProxy<uint32_t(std::tuple<int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t>,
                                             std::tuple<int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t>,
                                             std::tuple<int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t>,
                                             std::tuple<int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t>)>>
      m_method_SetDatetimeComponents;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int16_t, uint8_t, uint32_t>(int16_t,
                                                                                     std::tuple<int16_t,
                                                                                                uint8_t,
                                                                                                uint8_t,
                                                                                                uint8_t,
                                                                                                uint8_t,
                                                                                                uint8_t>)>>
      m_method_SetDatetimeComposite;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int16_t, uint8_t, uint32_t>(int16_t, uint32_t)>>
      m_method_SetDatetime;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t>(std::tuple<int16_t,
                                                                                        uint8_t,
                                                                                        uint8_t,
                                                                                        uint8_t,
                                                                                        uint8_t,
                                                                                        uint8_t>)>> m_method_GetWeekDay;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t>(std::tuple<int16_t,
                                                                                        uint8_t,
                                                                                        uint8_t,
                                                                                        uint8_t,
                                                                                        uint8_t,
                                                                                        uint8_t>)>>
      m_method_GetMonthDaysCount;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t>(std::tuple<int16_t,
                                                                                        uint8_t,
                                                                                        uint8_t,
                                                                                        uint8_t,
                                                                                        uint8_t,
                                                                                        uint8_t>)>>
      m_method_GetYearWeekNumber;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::tuple<int16_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t>, uint32_t>(std::tuple<int16_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t>,
                                                                                        std::tuple<int16_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t>)>>
      m_method_CalculateDateDiff;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::tuple<int16_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t>, uint32_t>(std::tuple<int16_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t>,
                                                                                        std::tuple<int16_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t>)>>
      m_method_CalculateTimeDiff;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::tuple<int16_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t,
                                                                    uint8_t>, uint32_t>(std::tuple<int16_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t>,
                                                                                        std::tuple<int16_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t>)>>
      m_method_CalculateDatetimeDiff;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t,
                                         std::tuple<int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t>,
                                         std::tuple<int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t>,
                                         int32_t)>> m_signalproxy_FireEventMsg;
  std::shared_ptr<DBus::SignalProxy<void(int16_t, uint8_t, int16_t)>> m_signalproxy_OffsetChangeMsg;
};
#endif /* COM_JCI_TIMEPROXY_H */
