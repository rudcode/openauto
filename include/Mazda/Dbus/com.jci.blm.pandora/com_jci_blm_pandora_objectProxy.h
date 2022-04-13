#ifndef COM_JCI_BLM_PANDORA_OBJECTPROXY_H
#define COM_JCI_BLM_PANDORA_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_blm_pandoraProxy.h"
class com_jci_blm_pandora_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_blm_pandora_objectProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path);
 public:
  static std::shared_ptr<com_jci_blm_pandora_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                                 std::string dest,
                                                                 std::string path,
                                                                 DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_blm_pandoraProxy> getcom_jci_blm_pandoraInterface();
 protected:
  std::shared_ptr<com_jci_blm_pandoraProxy> m_com_jci_blm_pandoraProxy;
};
#endif /* COM_JCI_BLM_PANDORA_OBJECTPROXY_H */
