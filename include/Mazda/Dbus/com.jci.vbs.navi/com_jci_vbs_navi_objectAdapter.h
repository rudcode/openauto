#ifndef COM_JCI_VBS_NAVI_OBJECTADAPTER_H
#define COM_JCI_VBS_NAVI_OBJECTADAPTER_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_vbs_naviInterface.h"
class com_jci_vbs_navi_objectAdapter
    : public DBus::Object {
 public:
  com_jci_vbs_navi_objectAdapter(std::shared_ptr<com_jci_vbs_naviInterface> _com_jci_vbs_naviInterface,
                                 std::string path);
 public:
  static std::shared_ptr<com_jci_vbs_navi_objectAdapter> create(std::shared_ptr<DBus::Connection> connection,
                                                                std::shared_ptr<com_jci_vbs_naviInterface> _com_jci_vbs_naviInterface,
                                                                std::string path,
                                                                DBus::ThreadForCalling calling_thread = DBus::ThreadForCalling::DispatcherThread);
};
#endif /* COM_JCI_VBS_NAVI_OBJECTADAPTER_H */
