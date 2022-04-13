#include "com_jci_VIDEOCTRLProxy.h"

com_jci_VIDEOCTRLProxy::com_jci_VIDEOCTRLProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_SelectVideoDevice = this->create_method<int32_t(int32_t)>("SelectVideoDevice");
  m_method_GetCapability = this->create_method<Invalid()>("GetCapability");
  m_method_TestVideoStatus = this->create_method<DBus::MultipleReturn<int32_t, int32_t>(int32_t)>("TestVideoStatus");
  m_method_GetVideoStatus = this->create_method<DBus::MultipleReturn<int32_t, int32_t>(int32_t)>("GetVideoStatus");
  m_method_GetAdjustments = this->create_method<std::tuple<int32_t, int32_t, int32_t, int32_t>()>("GetAdjustments");
  m_method_SetDeviceInstalled = this->create_method<void(int32_t, int32_t)>("SetDeviceInstalled");
  m_method_SetContrast = this->create_method<int32_t(int32_t)>("SetContrast");
  m_method_SetBrightness = this->create_method<int32_t(int32_t)>("SetBrightness");
  m_method_SetTint = this->create_method<int32_t(int32_t)>("SetTint");
  m_method_SetColor = this->create_method<int32_t(int32_t)>("SetColor");
  m_method_DeselectDevice = this->create_method<int32_t(int32_t)>("DeselectDevice");
  m_method_SetOutputViewport =
      this->create_method<int32_t(int32_t, int32_t, int32_t, int32_t, int32_t)>("SetOutputViewport");
  m_method_ResetAdjustments = this->create_method<int32_t()>("ResetAdjustments");
  m_signalproxy_VideoSignalChanged = this->create_signal<void(int32_t, int32_t)>("VideoSignalChanged");
  m_signalproxy_onSettingsChanged = this->create_signal
      < void(std::tuple < std::vector < std::tuple < int32_t, int32_t, int32_t, int32_t>>>)>("onSettingsChanged");
  m_signalproxy_CameraOffSignal =
      this->create_signal<void(int32_t, int32_t, int32_t, int32_t, int32_t)>("CameraOffSignal");

}
std::shared_ptr <com_jci_VIDEOCTRLProxy> com_jci_VIDEOCTRLProxy::create(std::string name) {
  return std::shared_ptr<com_jci_VIDEOCTRLProxy>(new com_jci_VIDEOCTRLProxy(name));

}
int32_t com_jci_VIDEOCTRLProxy::SelectVideoDevice(int32_t device) {
  return (*m_method_SelectVideoDevice)(device);

}
Invalid com_jci_VIDEOCTRLProxy::GetCapability() {
  return (*m_method_GetCapability)();

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_VIDEOCTRLProxy::TestVideoStatus(int32_t device) {
  return (*m_method_TestVideoStatus)(device);

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_VIDEOCTRLProxy::GetVideoStatus(int32_t device) {
  return (*m_method_GetVideoStatus)(device);

}
std::tuple <int32_t, int32_t, int32_t, int32_t> com_jci_VIDEOCTRLProxy::GetAdjustments() {
  return (*m_method_GetAdjustments)();

}
void com_jci_VIDEOCTRLProxy::SetDeviceInstalled(int32_t device, int32_t installed) {
  (*m_method_SetDeviceInstalled)(device, installed);

}
int32_t com_jci_VIDEOCTRLProxy::SetContrast(int32_t contrast) {
  return (*m_method_SetContrast)(contrast);

}
int32_t com_jci_VIDEOCTRLProxy::SetBrightness(int32_t brightness) {
  return (*m_method_SetBrightness)(brightness);

}
int32_t com_jci_VIDEOCTRLProxy::SetTint(int32_t tint) {
  return (*m_method_SetTint)(tint);

}
int32_t com_jci_VIDEOCTRLProxy::SetColor(int32_t color) {
  return (*m_method_SetColor)(color);

}
int32_t com_jci_VIDEOCTRLProxy::DeselectDevice(int32_t device) {
  return (*m_method_DeselectDevice)(device);

}
int32_t com_jci_VIDEOCTRLProxy::SetOutputViewport(int32_t device, int32_t x, int32_t y, int32_t width, int32_t height) {
  return (*m_method_SetOutputViewport)(device, x, y, width, height);

}
int32_t com_jci_VIDEOCTRLProxy::ResetAdjustments() {
  return (*m_method_ResetAdjustments)();

}
std::shared_ptr <DBus::SignalProxy<void(int32_t, int32_t)>> com_jci_VIDEOCTRLProxy::signal_VideoSignalChanged() {
  return m_signalproxy_VideoSignalChanged;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < std::vector < std::tuple < int32_t, int32_t, int32_t, int32_t>>>)>>
com_jci_VIDEOCTRLProxy::signal_onSettingsChanged() {
  return m_signalproxy_onSettingsChanged;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t,
                                        int32_t,
                                        int32_t,
                                        int32_t,
                                        int32_t)>> com_jci_VIDEOCTRLProxy::signal_CameraOffSignal() {
  return m_signalproxy_CameraOffSignal;

}
