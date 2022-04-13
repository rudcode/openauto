#include "com_jci_timeProxy.h"

com_jci_timeProxy::com_jci_timeProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_Connect = this->create_method<int32_t(std::string)>("Connect");
  m_method_Disconnect = this->create_method<int32_t(std::string)>("Disconnect");
  m_method_GetDatetime =
      this->create_method<DBus::MultipleReturn<uint32_t, int16_t, uint8_t, uint32_t>(int16_t)>("GetDatetime");
  m_method_GetDatetimeComposite =
      this->create_method < DBus::MultipleReturn < std::tuple < int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t
      >, int16_t, uint8_t, uint32_t > (int16_t) > ("GetDatetimeComposite");
  m_method_GetDatetimeComponents =
      this->create_method < DBus::MultipleReturn < std::tuple < int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t >,
      std::tuple < int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t >, std::tuple
      < int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t >, std::tuple
      < int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t >, uint8_t, uint32_t > () > ("GetDatetimeComponents");
  m_method_RegisterForDatetimeChangeEvent = this->create_method < DBus::MultipleReturn < uint8_t, std::tuple
      < int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t >, uint32_t
      > (uint8_t, std::tuple < int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t >, std::string)
      > ("RegisterForDatetimeChangeEvent");
  m_method_UnregisterFromDatetimeChangeEvent = this->create_method < DBus::MultipleReturn < uint8_t, std::tuple
      < int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t >, uint32_t
      > (uint8_t, std::tuple < int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t >, std::string)
      > ("UnregisterFromDatetimeChangeEvent");
  m_method_RegisterForOffsetChangeEvent =
      this->create_method<DBus::MultipleReturn<uint8_t, uint32_t>(uint8_t)>("RegisterForOffsetChangeEvent");
  m_method_UnregisterFromOffsetChangeEvent =
      this->create_method<DBus::MultipleReturn<uint8_t, uint32_t>(uint8_t)>("UnregisterFromOffsetChangeEvent");
  m_method_SetDatetimeComponents = this->create_method<uint32_t(std::tuple < int16_t,
                                                                uint8_t,
                                                                uint8_t,
                                                                uint8_t,
                                                                uint8_t,
                                                                uint8_t > ,
                                                                std::tuple < int16_t,
                                                                uint8_t,
                                                                uint8_t,
                                                                uint8_t,
                                                                uint8_t,
                                                                uint8_t > ,
                                                                std::tuple < int16_t,
                                                                uint8_t,
                                                                uint8_t,
                                                                uint8_t,
                                                                uint8_t,
                                                                uint8_t > ,
                                                                std::tuple < int16_t,
                                                                uint8_t,
                                                                uint8_t,
                                                                uint8_t,
                                                                uint8_t,
                                                                uint8_t > )>("SetDatetimeComponents");
  m_method_SetDatetimeComposite = this->create_method<DBus::MultipleReturn<int16_t, uint8_t, uint32_t>(int16_t,
                                                                                                       std::tuple
                                                                                                           < int16_t,
                                                                                                       uint8_t,
                                                                                                       uint8_t,
                                                                                                       uint8_t,
                                                                                                       uint8_t,
                                                                                                       uint8_t > )>(
      "SetDatetimeComposite");
  m_method_SetDatetime =
      this->create_method<DBus::MultipleReturn<int16_t, uint8_t, uint32_t>(int16_t, uint32_t)>("SetDatetime");
  m_method_GetWeekDay = this->create_method<DBus::MultipleReturn<uint32_t, uint32_t>(std::tuple < int16_t,
                                                                                     uint8_t,
                                                                                     uint8_t,
                                                                                     uint8_t,
                                                                                     uint8_t,
                                                                                     uint8_t > )>("GetWeekDay");
  m_method_GetMonthDaysCount = this->create_method<DBus::MultipleReturn<uint32_t, uint32_t>(std::tuple < int16_t,
                                                                                            uint8_t,
                                                                                            uint8_t,
                                                                                            uint8_t,
                                                                                            uint8_t,
                                                                                            uint8_t > )>(
      "GetMonthDaysCount");
  m_method_GetYearWeekNumber = this->create_method<DBus::MultipleReturn<uint32_t, uint32_t>(std::tuple < int16_t,
                                                                                            uint8_t,
                                                                                            uint8_t,
                                                                                            uint8_t,
                                                                                            uint8_t,
                                                                                            uint8_t > )>(
      "GetYearWeekNumber");
  m_method_CalculateDateDiff =
      this->create_method < DBus::MultipleReturn < std::tuple < int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t >,
      uint32_t > (std::tuple < int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t >, std::tuple
          < int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t >) > ("CalculateDateDiff");
  m_method_CalculateTimeDiff =
      this->create_method < DBus::MultipleReturn < std::tuple < int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t >,
      uint32_t > (std::tuple < int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t >, std::tuple
          < int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t >) > ("CalculateTimeDiff");
  m_method_CalculateDatetimeDiff =
      this->create_method < DBus::MultipleReturn < std::tuple < int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t >,
      uint32_t > (std::tuple < int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t >, std::tuple
          < int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t >) > ("CalculateDatetimeDiff");
  m_signalproxy_FireEventMsg = this->create_signal<void(uint8_t,
                                                        std::tuple < int16_t,
                                                        uint8_t,
                                                        uint8_t,
                                                        uint8_t,
                                                        uint8_t,
                                                        uint8_t > ,
                                                        std::tuple < int16_t,
                                                        uint8_t,
                                                        uint8_t,
                                                        uint8_t,
                                                        uint8_t,
                                                        uint8_t > ,
                                                        int32_t)>("FireEventMsg");
  m_signalproxy_OffsetChangeMsg = this->create_signal<void(int16_t, uint8_t, int16_t)>("OffsetChangeMsg");

}
std::shared_ptr <com_jci_timeProxy> com_jci_timeProxy::create(std::string name) {
  return std::shared_ptr<com_jci_timeProxy>(new com_jci_timeProxy(name));

}
int32_t com_jci_timeProxy::Connect(std::string client_name) {
  return (*m_method_Connect)(client_name);

}
int32_t com_jci_timeProxy::Disconnect(std::string client_name) {
  return (*m_method_Disconnect)(client_name);

}
DBus::MultipleReturn <uint32_t, int16_t, uint8_t, uint32_t> com_jci_timeProxy::GetDatetime(int16_t field_in) {
  return (*m_method_GetDatetime)(field_in);

}
DBus::MultipleReturn <std::tuple<int16_t,
                                 uint8_t,
                                 uint8_t,
                                 uint8_t,
                                 uint8_t,
                                 uint8_t>, int16_t, uint8_t, uint32_t> com_jci_timeProxy::GetDatetimeComposite(int16_t field_in) {
  return (*m_method_GetDatetimeComposite)(field_in);

}
DBus::MultipleReturn <std::tuple<int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t>, std::tuple<int16_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t,
                                                                                                   uint8_t>, std::tuple<
    int16_t,
    uint8_t,
    uint8_t,
    uint8_t,
    uint8_t,
    uint8_t>, std::tuple<int16_t,
                         uint8_t,
                         uint8_t,
                         uint8_t,
                         uint8_t,
                         uint8_t>, uint8_t, uint32_t> com_jci_timeProxy::GetDatetimeComponents() {
  return (*m_method_GetDatetimeComponents)();

}
DBus::MultipleReturn <uint8_t, std::tuple<int16_t,
                                          uint8_t,
                                          uint8_t,
                                          uint8_t,
                                          uint8_t,
                                          uint8_t>, uint32_t> com_jci_timeProxy::RegisterForDatetimeChangeEvent(uint8_t time_req,
                                                                                                                std::tuple <int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t> event_time,
                                                                                                                std::string client_name) {
  return (*m_method_RegisterForDatetimeChangeEvent)(time_req, event_time, client_name);

}
DBus::MultipleReturn <uint8_t, std::tuple<int16_t,
                                          uint8_t,
                                          uint8_t,
                                          uint8_t,
                                          uint8_t,
                                          uint8_t>, uint32_t> com_jci_timeProxy::UnregisterFromDatetimeChangeEvent(
    uint8_t time_req,
    std::tuple <int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t> event_time,
    std::string client_name) {
  return (*m_method_UnregisterFromDatetimeChangeEvent)(time_req, event_time, client_name);

}
DBus::MultipleReturn <uint8_t, uint32_t> com_jci_timeProxy::RegisterForOffsetChangeEvent(uint8_t offset_change_type) {
  return (*m_method_RegisterForOffsetChangeEvent)(offset_change_type);

}
DBus::MultipleReturn <uint8_t, uint32_t> com_jci_timeProxy::UnregisterFromOffsetChangeEvent(uint8_t offset_change_type) {
  return (*m_method_UnregisterFromOffsetChangeEvent)(offset_change_type);

}
uint32_t com_jci_timeProxy::SetDatetimeComponents(std::tuple <int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t> base_datetime,
                                                  std::tuple <int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t> timezone_offset,
                                                  std::tuple <int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t> daylightsaving_offset,
                                                  std::tuple <int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t> user_offset) {
  return (*m_method_SetDatetimeComponents)(base_datetime, timezone_offset, daylightsaving_offset, user_offset);

}
DBus::MultipleReturn <int16_t, uint8_t, uint32_t> com_jci_timeProxy::SetDatetimeComposite(int16_t field_in,
                                                                                          std::tuple <int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t> datetime_in) {
  return (*m_method_SetDatetimeComposite)(field_in, datetime_in);

}
DBus::MultipleReturn <int16_t, uint8_t, uint32_t> com_jci_timeProxy::SetDatetime(int16_t field_in,
                                                                                 uint32_t datetime_in) {
  return (*m_method_SetDatetime)(field_in, datetime_in);

}
DBus::MultipleReturn <uint32_t, uint32_t> com_jci_timeProxy::GetWeekDay(std::tuple <int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t> event_time) {
  return (*m_method_GetWeekDay)(event_time);

}
DBus::MultipleReturn <uint32_t, uint32_t> com_jci_timeProxy::GetMonthDaysCount(std::tuple <int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t> event_time) {
  return (*m_method_GetMonthDaysCount)(event_time);

}
DBus::MultipleReturn <uint32_t, uint32_t> com_jci_timeProxy::GetYearWeekNumber(std::tuple <int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t> event_time) {
  return (*m_method_GetYearWeekNumber)(event_time);

}
DBus::MultipleReturn <std::tuple<int16_t,
                                 uint8_t,
                                 uint8_t,
                                 uint8_t,
                                 uint8_t,
                                 uint8_t>, uint32_t> com_jci_timeProxy::CalculateDateDiff(std::tuple <int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t> event_time_from,
                                                                                          std::tuple <int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t> event_time_to) {
  return (*m_method_CalculateDateDiff)(event_time_from, event_time_to);

}
DBus::MultipleReturn <std::tuple<int16_t,
                                 uint8_t,
                                 uint8_t,
                                 uint8_t,
                                 uint8_t,
                                 uint8_t>, uint32_t> com_jci_timeProxy::CalculateTimeDiff(std::tuple <int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t> event_time_from,
                                                                                          std::tuple <int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t> event_time_to) {
  return (*m_method_CalculateTimeDiff)(event_time_from, event_time_to);

}
DBus::MultipleReturn <std::tuple<int16_t,
                                 uint8_t,
                                 uint8_t,
                                 uint8_t,
                                 uint8_t,
                                 uint8_t>, uint32_t> com_jci_timeProxy::CalculateDatetimeDiff(std::tuple <int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t> event_time_from,
                                                                                              std::tuple <int16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t> event_time_to) {
  return (*m_method_CalculateDatetimeDiff)(event_time_from, event_time_to);

}
std::shared_ptr <DBus::SignalProxy<void(uint8_t,
                                        std::tuple < int16_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t > ,
                                        std::tuple < int16_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t,
                                        uint8_t > ,
                                        int32_t)>> com_jci_timeProxy::signal_FireEventMsg() {
  return m_signalproxy_FireEventMsg;

}
std::shared_ptr <DBus::SignalProxy<void(int16_t, uint8_t, int16_t)>> com_jci_timeProxy::signal_OffsetChangeMsg() {
  return m_signalproxy_OffsetChangeMsg;

}
