#ifndef COM_JCI_CPP_VBI_BCM_OBJECTPROXY_H
#define COM_JCI_CPP_VBI_BCM_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_cpp_vbi_BcmProxy.h"
class com_jci_cpp_vbi_Bcm_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_cpp_vbi_Bcm_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_cpp_vbi_Bcm_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                                 std::string dest,
                                                                 std::string path,
                                                                 DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_cpp_vbi_BcmProxy> getcom_jci_cpp_vbi_BcmInterface();
 protected:
  std::shared_ptr<com_jci_cpp_vbi_BcmProxy> m_com_jci_cpp_vbi_BcmProxy;
};
#endif /* COM_JCI_CPP_VBI_BCM_OBJECTPROXY_H */
