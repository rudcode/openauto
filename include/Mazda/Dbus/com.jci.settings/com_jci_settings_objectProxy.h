#ifndef COM_JCI_SETTINGS_OBJECTPROXY_H
#define COM_JCI_SETTINGS_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_settingsProxy.h"
class com_jci_settings_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_settings_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_settings_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                              std::string dest,
                                                              std::string path,
                                                              DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_settingsProxy> getcom_jci_settingsInterface();
 protected:
  std::shared_ptr<com_jci_settingsProxy> m_com_jci_settingsProxy;
};
#endif /* COM_JCI_SETTINGS_OBJECTPROXY_H */
