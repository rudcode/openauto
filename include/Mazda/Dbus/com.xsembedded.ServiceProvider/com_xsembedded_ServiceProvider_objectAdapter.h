#ifndef COM_XSEMBEDDED_SERVICEPROVIDER_OBJECTADAPTER_H
#define COM_XSEMBEDDED_SERVICEPROVIDER_OBJECTADAPTER_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_xsembedded_ServiceProviderInterface.h"
class com_xsembedded_ServiceProvider_objectAdapter
    : public DBus::Object {
 public:
  com_xsembedded_ServiceProvider_objectAdapter(std::shared_ptr<com_xsembedded_ServiceProviderInterface> _com_xsembedded_ServiceProviderInterface,
                                               std::string path);
 public:
  static std::shared_ptr<com_xsembedded_ServiceProvider_objectAdapter> create(std::shared_ptr<DBus::Connection> connection,
                                                                              std::shared_ptr<
                                                                                  com_xsembedded_ServiceProviderInterface> _com_xsembedded_ServiceProviderInterface,
                                                                              std::string path,
                                                                              DBus::ThreadForCalling calling_thread = DBus::ThreadForCalling::DispatcherThread);
};
#endif /* COM_XSEMBEDDED_SERVICEPROVIDER_OBJECTADAPTER_H */
