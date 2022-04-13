#ifndef COM_JCI_AUDIOSETTINGS_OBJECTPROXY_H
#define COM_JCI_AUDIOSETTINGS_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_audiosettingsProxy.h"
class com_jci_audiosettings_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_audiosettings_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_audiosettings_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                                   std::string dest,
                                                                   std::string path,
                                                                   DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_audiosettingsProxy> getcom_jci_audiosettingsInterface();
 protected:
  std::shared_ptr<com_jci_audiosettingsProxy> m_com_jci_audiosettingsProxy;
};
#endif /* COM_JCI_AUDIOSETTINGS_OBJECTPROXY_H */
