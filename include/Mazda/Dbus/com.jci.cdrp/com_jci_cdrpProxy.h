#ifndef COM_JCI_CDRPPROXY_H
#define COM_JCI_CDRPPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_cdrpProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_cdrpProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_cdrpProxy> create(std::string name = "com.jci.cdrp");
  void SetConfirmationDialogResult(uint32_t index, std::string serialId, uint32_t size);
  void SetDeviceSettings(uint32_t index, std::string serialId, uint32_t size);
  void GetConfirmationDialogRequest(uint32_t index);
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::string, uint32_t)>> signal_ConnectedDeviceSignal();
  std::shared_ptr<DBus::SignalProxy<void(std::string,
                                         uint32_t,
                                         std::string,
                                         uint32_t)>> signal_ConfirmationDialogSignal();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_ErrorNotificationSignal();
 protected:
  std::shared_ptr<DBus::MethodProxy<void(uint32_t, std::string, uint32_t)>> m_method_SetConfirmationDialogResult;
  std::shared_ptr<DBus::MethodProxy<void(uint32_t, std::string, uint32_t)>> m_method_SetDeviceSettings;
  std::shared_ptr<DBus::MethodProxy<void(uint32_t)>> m_method_GetConfirmationDialogRequest;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, std::string, uint32_t)>> m_signalproxy_ConnectedDeviceSignal;
  std::shared_ptr<DBus::SignalProxy<void(std::string, uint32_t, std::string, uint32_t)>>
      m_signalproxy_ConfirmationDialogSignal;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_ErrorNotificationSignal;
};
#endif /* COM_JCI_CDRPPROXY_H */
