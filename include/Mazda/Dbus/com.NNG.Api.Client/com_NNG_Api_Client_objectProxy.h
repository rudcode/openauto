#ifndef COM_NNG_API_CLIENT_OBJECTPROXY_H
#define COM_NNG_API_CLIENT_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_NNG_Api_ClientProxy.h"
class com_NNG_Api_Client_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_NNG_Api_Client_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_NNG_Api_Client_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                                std::string dest,
                                                                std::string path,
                                                                DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_NNG_Api_ClientProxy> getcom_NNG_Api_ClientInterface();
 protected:
  std::shared_ptr<com_NNG_Api_ClientProxy> m_com_NNG_Api_ClientProxy;
};
#endif /* COM_NNG_API_CLIENT_OBJECTPROXY_H */
