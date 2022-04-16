#ifndef COM_JCI_VBS_NAVI_TMCINTERFACE_H
#define COM_JCI_VBS_NAVI_TMCINTERFACE_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include <tuple>
#include "com_jci_vbs_navi_tmc.h"
class com_jci_vbs_navi_tmcInterface
    : public DBus::Interface {
 private:
  com_jci_vbs_navi_tmcInterface(com_jci_vbs_navi_tmc *adaptee, std::string name);
 public:
  static std::shared_ptr<com_jci_vbs_navi_tmcInterface> create(com_jci_vbs_navi_tmc *adaptee,
                                                               std::string name = "com.jci.vbs.navi.tmc");
  std::shared_ptr<DBus::Signal<void(std::tuple<uint8_t,
                                               std::vector<uint8_t>,
                                               std::vector<uint8_t>,
                                               std::vector<uint8_t>,
                                               std::vector<uint8_t>,
                                               std::vector<uint8_t>>)>> signal_ServiceListResponse();
  void ServiceListResponse(std::tuple<uint8_t,
                                      std::vector<uint8_t>,
                                      std::vector<uint8_t>,
                                      std::vector<uint8_t>,
                                      std::vector<uint8_t>,
                                      std::vector<uint8_t>> providerList);
  std::shared_ptr<DBus::Signal<void(uint8_t,
                                    uint8_t,
                                    uint8_t,
                                    uint8_t,
                                    uint8_t,
                                    uint8_t,
                                    uint8_t)>> signal_ResponseToTMCSelection();
  void ResponseToTMCSelection(uint8_t rdstmcOperation,
                              uint8_t tmcSearchMode,
                              uint8_t countryCode,
                              uint8_t locationTableNumber,
                              uint8_t serviceIdentifier,
                              uint8_t quality,
                              uint8_t receptionStatus);
 protected:
  std::shared_ptr<DBus::Signal<void(std::tuple<uint8_t,
                                               std::vector<uint8_t>,
                                               std::vector<uint8_t>,
                                               std::vector<uint8_t>,
                                               std::vector<uint8_t>,
                                               std::vector<uint8_t>>)>> m_signal_ServiceListResponse;
  std::shared_ptr<DBus::Signal<void(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t)>>
      m_signal_ResponseToTMCSelection;
};
#endif /* COM_JCI_VBS_NAVI_TMCINTERFACE_H */
