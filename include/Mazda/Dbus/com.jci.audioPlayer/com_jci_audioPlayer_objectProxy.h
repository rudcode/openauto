#ifndef COM_JCI_AUDIOPLAYER_OBJECTPROXY_H
#define COM_JCI_AUDIOPLAYER_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_audioPlayerProxy.h"
class com_jci_audioPlayer_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_audioPlayer_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_audioPlayer_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                                 std::string dest,
                                                                 std::string path,
                                                                 DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_audioPlayerProxy> getcom_jci_audioPlayerInterface();
 protected:
  std::shared_ptr<com_jci_audioPlayerProxy> m_com_jci_audioPlayerProxy;
};
#endif /* COM_JCI_AUDIOPLAYER_OBJECTPROXY_H */
