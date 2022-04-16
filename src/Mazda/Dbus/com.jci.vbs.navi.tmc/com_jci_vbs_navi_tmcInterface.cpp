#include "com_jci_vbs_navi_tmcInterface.h"

com_jci_vbs_navi_tmcInterface::com_jci_vbs_navi_tmcInterface(com_jci_vbs_navi_tmc *adaptee, std::string name)
    : DBus::Interface(name) {
  this->create_method<uint8_t(uint8_t)>("NaviCompassVal",
                                        sigc::mem_fun(*adaptee, &com_jci_vbs_navi_tmc::NaviCompassVal));
  this->create_method<uint8_t(uint8_t)>("NaviSignal", sigc::mem_fun(*adaptee, &com_jci_vbs_navi_tmc::NaviSignal));
  this->create_method<uint8_t(std::tuple<std::string, uint8_t>)>("SetHUD_Display_Msg2",
                                                                 sigc::mem_fun(*adaptee,
                                                                               &com_jci_vbs_navi_tmc::SetHUD_Display_Msg2));
  m_signal_ServiceListResponse = create_signal<void(std::tuple<uint8_t,
                                                               std::vector<uint8_t>,
                                                               std::vector<uint8_t>,
                                                               std::vector<uint8_t>,
                                                               std::vector<uint8_t>,
                                                               std::vector<uint8_t>>)>("ServiceListResponse");
  m_signal_ResponseToTMCSelection =
      create_signal<void(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t)>("ResponseToTMCSelection");

}
std::shared_ptr<com_jci_vbs_navi_tmcInterface> com_jci_vbs_navi_tmcInterface::create(com_jci_vbs_navi_tmc *adaptee,
                                                                                     std::string name) {
  return std::shared_ptr<com_jci_vbs_navi_tmcInterface>(new com_jci_vbs_navi_tmcInterface(adaptee, name));

}
std::shared_ptr<DBus::Signal<void(std::tuple<uint8_t,
                                             std::vector<uint8_t>,
                                             std::vector<uint8_t>,
                                             std::vector<uint8_t>,
                                             std::vector<uint8_t>,
                                             std::vector<uint8_t>>)>> com_jci_vbs_navi_tmcInterface::signal_ServiceListResponse() {
  return m_signal_ServiceListResponse;

}
void com_jci_vbs_navi_tmcInterface::ServiceListResponse(std::tuple<uint8_t,
                                                                   std::vector<uint8_t>,
                                                                   std::vector<uint8_t>,
                                                                   std::vector<uint8_t>,
                                                                   std::vector<uint8_t>,
                                                                   std::vector<uint8_t>> providerList) {
  (*m_signal_ServiceListResponse)(providerList);

}
std::shared_ptr<DBus::Signal<void(uint8_t,
                                  uint8_t,
                                  uint8_t,
                                  uint8_t,
                                  uint8_t,
                                  uint8_t,
                                  uint8_t)>> com_jci_vbs_navi_tmcInterface::signal_ResponseToTMCSelection() {
  return m_signal_ResponseToTMCSelection;

}
void com_jci_vbs_navi_tmcInterface::ResponseToTMCSelection(uint8_t rdstmcOperation,
                                                           uint8_t tmcSearchMode,
                                                           uint8_t countryCode,
                                                           uint8_t locationTableNumber,
                                                           uint8_t serviceIdentifier,
                                                           uint8_t quality,
                                                           uint8_t receptionStatus) {
  (*m_signal_ResponseToTMCSelection)(rdstmcOperation,
                                     tmcSearchMode,
                                     countryCode,
                                     locationTableNumber,
                                     serviceIdentifier,
                                     quality,
                                     receptionStatus);

}
