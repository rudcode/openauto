#ifndef COM_JCI_VBS_NAVIINTERFACE_H
#define COM_JCI_VBS_NAVIINTERFACE_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include <tuple>
#include <vector>
#include "com_jci_vbs_navi.h"
class com_jci_vbs_naviInterface
    : public DBus::Interface {
 private:
  com_jci_vbs_naviInterface(com_jci_vbs_navi *adaptee, std::string name);
 public:
  static std::shared_ptr<com_jci_vbs_naviInterface> create(com_jci_vbs_navi *adaptee,
                                                           std::string name = "com.jci.vbs.navi");
  std::shared_ptr<DBus::Signal<void(uint8_t)>> signal_FuelTypeResp();
  void FuelTypeResp(uint8_t fuelType);
  std::shared_ptr<DBus::Signal<void(uint8_t)>> signal_HUDResp();
  void HUDResp(uint8_t hudStatus);
  std::shared_ptr<DBus::Signal<void(uint8_t)>> signal_TSRResp();
  void TSRResp(uint8_t tsrStatus);
  std::shared_ptr<DBus::Signal<void(std::tuple<std::vector<uint8_t>>)>> signal_GccConfigMgmtResp();
  void GccConfigMgmtResp(std::tuple<std::vector<uint8_t>> vin_Character);
  std::shared_ptr<DBus::Signal<void(uint8_t)>> signal_TSRFeatureMode();
  void TSRFeatureMode(uint8_t tsrMode);
 protected:
  std::shared_ptr<DBus::Signal<void(uint8_t)>> m_signal_FuelTypeResp;
  std::shared_ptr<DBus::Signal<void(uint8_t)>> m_signal_HUDResp;
  std::shared_ptr<DBus::Signal<void(uint8_t)>> m_signal_TSRResp;
  std::shared_ptr<DBus::Signal<void(std::tuple<std::vector<uint8_t>>)>> m_signal_GccConfigMgmtResp;
  std::shared_ptr<DBus::Signal<void(uint8_t)>> m_signal_TSRFeatureMode;
};
#endif /* COM_JCI_VBS_NAVIINTERFACE_H */
