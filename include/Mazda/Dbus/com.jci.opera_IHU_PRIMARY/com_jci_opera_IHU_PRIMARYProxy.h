#ifndef COM_JCI_OPERA_IHU_PRIMARYPROXY_H
#define COM_JCI_OPERA_IHU_PRIMARYPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_opera_IHU_PRIMARYProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_opera_IHU_PRIMARYProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_opera_IHU_PRIMARYProxy> create(std::string name = "com.jci.opera_IHU_PRIMARY");
  void TerminateOpera();
  void Navigate(std::string uRL);
  void GoBack();
  void GoForward();
  void Refresh();
  std::shared_ptr<DBus::SignalProxy<void(std::string)>> signal_ReportError();
 protected:
  std::shared_ptr<DBus::MethodProxy<void()>> m_method_TerminateOpera;
  std::shared_ptr<DBus::MethodProxy<void(std::string)>> m_method_Navigate;
  std::shared_ptr<DBus::MethodProxy<void()>> m_method_GoBack;
  std::shared_ptr<DBus::MethodProxy<void()>> m_method_GoForward;
  std::shared_ptr<DBus::MethodProxy<void()>> m_method_Refresh;
  std::shared_ptr<DBus::SignalProxy<void(std::string)>> m_signalproxy_ReportError;
};
#endif /* COM_JCI_OPERA_IHU_PRIMARYPROXY_H */
