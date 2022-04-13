#ifndef COM_JCI_VBS_NAVI_TMCPROXY_H
#define COM_JCI_VBS_NAVI_TMCPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_vbs_navi_tmcProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_vbs_navi_tmcProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_vbs_navi_tmcProxy> create(std::string name = "com.jci.vbs.navi.tmc");
  uint8_t NaviCompassVal(uint8_t compass);
  uint8_t NaviSignal(uint8_t navi);
  uint8_t SetHUD_Display_Msg2(std::tuple<std::string, uint8_t> guidancePointData);
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>>)>> signal_ServiceListResponse();
  std::shared_ptr<DBus::SignalProxy<void(uint8_t,
                                         uint8_t,
                                         uint8_t,
                                         uint8_t,
                                         uint8_t,
                                         uint8_t,
                                         uint8_t)>> signal_ResponseToTMCSelection();
 protected:
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_NaviCompassVal;
  std::shared_ptr<DBus::MethodProxy<uint8_t(uint8_t)>> m_method_NaviSignal;
  std::shared_ptr<DBus::MethodProxy<uint8_t(std::tuple<std::string, uint8_t>)>> m_method_SetHUD_Display_Msg2;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>,
                                                    std::vector<uint8_t>>)>> m_signalproxy_ServiceListResponse;
  std::shared_ptr<DBus::SignalProxy<void(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t)>>
      m_signalproxy_ResponseToTMCSelection;
};
#endif /* COM_JCI_VBS_NAVI_TMCPROXY_H */
