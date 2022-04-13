#ifndef COM_JCI_CPP_SERVICE_SERVICE_OBJECTPROXY_H
#define COM_JCI_CPP_SERVICE_SERVICE_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_cpp_service_ServiceProxy.h"
class com_jci_cpp_service_Service_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_cpp_service_Service_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_cpp_service_Service_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                                         std::string dest,
                                                                         std::string path,
                                                                         DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_cpp_service_ServiceProxy> getcom_jci_cpp_service_ServiceInterface();
 protected:
  std::shared_ptr<com_jci_cpp_service_ServiceProxy> m_com_jci_cpp_service_ServiceProxy;
};
#endif /* COM_JCI_CPP_SERVICE_SERVICE_OBJECTPROXY_H */
