#ifndef COM_XSEMBEDDED_SERVICEPROVIDER_OBJECTPROXY_H
#define COM_XSEMBEDDED_SERVICEPROVIDER_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_xsembedded_ServiceProviderProxy.h"
class com_xsembedded_ServiceProvider_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_xsembedded_ServiceProvider_objectProxy(std::shared_ptr<DBus::Connection> conn,
                                             std::string dest,
                                             std::string path);
 public:
  static std::shared_ptr<com_xsembedded_ServiceProvider_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                                            std::string dest,
                                                                            std::string path,
                                                                            DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_xsembedded_ServiceProviderProxy> getcom_xsembedded_ServiceProviderInterface();
 protected:
  std::shared_ptr<com_xsembedded_ServiceProviderProxy> m_com_xsembedded_ServiceProviderProxy;
};
#endif /* COM_XSEMBEDDED_SERVICEPROVIDER_OBJECTPROXY_H */
