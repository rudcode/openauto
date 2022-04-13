#ifndef COM_JCI_DVDPROXY_H
#define COM_JCI_DVDPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_dvdProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_dvdProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_dvdProxy> create(std::string name = "com.jci.dvd");
  int32_t SwitchState(uint32_t state);
  int32_t ChangeSetting(uint32_t setting, int32_t value);
  int32_t GetSetting(uint32_t setting);
  int32_t PinOperation(uint32_t cmd, uint32_t pin);
  int32_t DeviceCommand(uint32_t cmd);
  int32_t ScrubberBarControl(uint32_t percentage);
  std::tuple<uint32_t,
             uint32_t,
             uint32_t,
             uint32_t,
             uint32_t,
             uint32_t,
             uint32_t,
             int32_t,
             int32_t,
             uint32_t,
             uint8_t> GetDvdStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_DeviceStatusEvent();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint16_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t>)>> signal_PlayingStatusEvent();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_SwitchState;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, int32_t)>> m_method_ChangeSetting;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_GetSetting;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t, uint32_t)>> m_method_PinOperation;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_DeviceCommand;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_ScrubberBarControl;
  std::shared_ptr<DBus::MethodProxy<std::tuple<uint32_t,
                                               uint32_t,
                                               uint32_t,
                                               uint32_t,
                                               uint32_t,
                                               uint32_t,
                                               uint32_t,
                                               int32_t,
                                               int32_t,
                                               uint32_t,
                                               uint8_t>()>> m_method_GetDvdStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_DeviceStatusEvent;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint16_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t,
                                                    uint8_t>)>> m_signalproxy_PlayingStatusEvent;
};
#endif /* COM_JCI_DVDPROXY_H */
