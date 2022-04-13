#ifndef COM_JCI_CPP_VBI_AMPLIFIER_OBJECTPROXY_H
#define COM_JCI_CPP_VBI_AMPLIFIER_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_cpp_vbi_AmplifierProxy.h"
class com_jci_cpp_vbi_Amplifier_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_cpp_vbi_Amplifier_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_cpp_vbi_Amplifier_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                                       std::string dest,
                                                                       std::string path,
                                                                       DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_cpp_vbi_AmplifierProxy> getcom_jci_cpp_vbi_AmplifierInterface();
 protected:
  std::shared_ptr<com_jci_cpp_vbi_AmplifierProxy> m_com_jci_cpp_vbi_AmplifierProxy;
};
#endif /* COM_JCI_CPP_VBI_AMPLIFIER_OBJECTPROXY_H */
