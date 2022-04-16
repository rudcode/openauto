#ifndef COM_JCI_BUCPSAINTERFACE_H
#define COM_JCI_BUCPSAINTERFACE_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_bucpsa.h"
class com_jci_bucpsaInterface
    : public DBus::Interface {
 private:
  com_jci_bucpsaInterface(com_jci_bucpsa *adaptee, std::string name);
 public:
  static std::shared_ptr<com_jci_bucpsaInterface> create(com_jci_bucpsa *adaptee, std::string name = "com.jci.bucpsa");
  std::shared_ptr<DBus::Signal<void(uint32_t)>> signal_CommandResponse();
  void CommandResponse(uint32_t cmdResponse);
  std::shared_ptr<DBus::Signal<void(uint32_t)>> signal_DisplayMode();
  void DisplayMode(uint32_t currentDisplayMode);
  std::shared_ptr<DBus::Signal<void(int32_t)>> signal_ReverseStatusChanged();
  void ReverseStatusChanged(int32_t reverseStatus);
  std::shared_ptr<DBus::Signal<void(uint8_t)>> signal_PSMInstallStatusChanged();
  void PSMInstallStatusChanged(uint8_t psmInstalled);
  std::shared_ptr<DBus::Signal<void(uint32_t)>> signal_CameraType();
  void CameraType(uint32_t currentCameraType);
  std::shared_ptr<DBus::Signal<void(uint32_t)>> signal_SteeringWheelLocation();
  void SteeringWheelLocation(uint32_t currentSteeringWheelLocation);
 protected:
  std::shared_ptr<DBus::Signal<void(uint32_t)>> m_signal_CommandResponse;
  std::shared_ptr<DBus::Signal<void(uint32_t)>> m_signal_DisplayMode;
  std::shared_ptr<DBus::Signal<void(int32_t)>> m_signal_ReverseStatusChanged;
  std::shared_ptr<DBus::Signal<void(uint8_t)>> m_signal_PSMInstallStatusChanged;
  std::shared_ptr<DBus::Signal<void(uint32_t)>> m_signal_CameraType;
  std::shared_ptr<DBus::Signal<void(uint32_t)>> m_signal_SteeringWheelLocation;
};
#endif /* COM_JCI_BUCPSAINTERFACE_H */
