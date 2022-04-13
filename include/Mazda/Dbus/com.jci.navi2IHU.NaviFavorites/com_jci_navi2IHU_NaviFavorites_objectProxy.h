#ifndef COM_JCI_NAVI_IHU_NAVIFAVORITES_OBJECTPROXY_H
#define COM_JCI_NAVI_IHU_NAVIFAVORITES_OBJECTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_navi2IHU_NaviFavoritesProxy.h"
class com_jci_navi2IHU_NaviFavorites_objectProxy
    : public DBus::ObjectProxy {
 public:
  com_jci_navi2IHU_NaviFavorites_objectProxy(std::shared_ptr<DBus::Connection> conn,
                                             std::string dest,
                                             std::string path);
 public:
  static std::shared_ptr<com_jci_navi2IHU_NaviFavorites_objectProxy> create(std::shared_ptr<DBus::Connection> conn,
                                                                            std::string dest,
                                                                            std::string path,
                                                                            DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);
  std::shared_ptr<com_jci_navi2IHU_NaviFavoritesProxy> getcom_jci_navi2IHU_NaviFavoritesInterface();
 protected:
  std::shared_ptr<com_jci_navi2IHU_NaviFavoritesProxy> m_com_jci_navi2IHU_NaviFavoritesProxy;
};
#endif /* COM_JCI_NAVI_IHU_NAVIFAVORITES_OBJECTPROXY_H */
