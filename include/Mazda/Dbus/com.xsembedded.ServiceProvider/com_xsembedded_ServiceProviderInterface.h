#ifndef COM_XSEMBEDDED_SERVICEPROVIDERINTERFACE_H
#define COM_XSEMBEDDED_SERVICEPROVIDERINTERFACE_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include <tuple>
#include <vector>
#include "com_xsembedded_ServiceProvider.h"
class com_xsembedded_ServiceProviderInterface
    : public DBus::Interface {
 private:
  com_xsembedded_ServiceProviderInterface(com_xsembedded_ServiceProvider *adaptee, std::string name);
 public:
  static std::shared_ptr<com_xsembedded_ServiceProviderInterface> create(com_xsembedded_ServiceProvider *adaptee,
                                                                         std::string name = "com.xsembedded.ServiceProvider");
  std::shared_ptr<DBus::Signal<void(std::string, std::string)>> signal_Notify();
  void Notify(std::string signalName, std::string payload);
 protected:
  std::shared_ptr<DBus::Signal<void(std::string, std::string)>> m_signal_Notify;
};
#endif /* COM_XSEMBEDDED_SERVICEPROVIDERINTERFACE_H */
