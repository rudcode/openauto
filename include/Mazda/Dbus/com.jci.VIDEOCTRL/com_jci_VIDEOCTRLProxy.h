#ifndef COM_JCI_VIDEOCTRLPROXY_H
#define COM_JCI_VIDEOCTRLPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_VIDEOCTRLProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_VIDEOCTRLProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_VIDEOCTRLProxy> create(std::string name = "com.jci.VIDEOCTRL");
  int32_t SelectVideoDevice(int32_t device);
  Invalid GetCapability();
  DBus::MultipleReturn<int32_t, int32_t> TestVideoStatus(int32_t device);
  DBus::MultipleReturn<int32_t, int32_t> GetVideoStatus(int32_t device);
  std::tuple<int32_t, int32_t, int32_t, int32_t> GetAdjustments();
  void SetDeviceInstalled(int32_t device, int32_t installed);
  int32_t SetContrast(int32_t contrast);
  int32_t SetBrightness(int32_t brightness);
  int32_t SetTint(int32_t tint);
  int32_t SetColor(int32_t color);
  int32_t DeselectDevice(int32_t device);
  int32_t SetOutputViewport(int32_t device, int32_t x, int32_t y, int32_t width, int32_t height);
  int32_t ResetAdjustments();
  std::shared_ptr<DBus::SignalProxy<void(int32_t, int32_t)>> signal_VideoSignalChanged();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<std::tuple<int32_t,
                                                                           int32_t,
                                                                           int32_t,
                                                                           int32_t>>>)>> signal_onSettingsChanged();
  std::shared_ptr<DBus::SignalProxy<void(int32_t, int32_t, int32_t, int32_t, int32_t)>> signal_CameraOffSignal();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_SelectVideoDevice;
  std::shared_ptr<DBus::MethodProxy<Invalid()>> m_method_GetCapability;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, int32_t>(int32_t)>> m_method_TestVideoStatus;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, int32_t>(int32_t)>> m_method_GetVideoStatus;
  std::shared_ptr<DBus::MethodProxy<std::tuple<int32_t, int32_t, int32_t, int32_t>()>> m_method_GetAdjustments;
  std::shared_ptr<DBus::MethodProxy<void(int32_t, int32_t)>> m_method_SetDeviceInstalled;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_SetContrast;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_SetBrightness;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_SetTint;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_SetColor;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_DeselectDevice;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t, int32_t, int32_t, int32_t, int32_t)>> m_method_SetOutputViewport;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_ResetAdjustments;
  std::shared_ptr<DBus::SignalProxy<void(int32_t, int32_t)>> m_signalproxy_VideoSignalChanged;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<std::tuple<int32_t, int32_t, int32_t, int32_t>>>)>>
      m_signalproxy_onSettingsChanged;
  std::shared_ptr<DBus::SignalProxy<void(int32_t, int32_t, int32_t, int32_t, int32_t)>> m_signalproxy_CameraOffSignal;
};
#endif /* COM_JCI_VIDEOCTRLPROXY_H */
