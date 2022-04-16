#ifndef COM_JCI_VBS_NAVI_TMC_OBJECTADAPTER_H
#define COM_JCI_VBS_NAVI_TMC_OBJECTADAPTER_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_vbs_navi_tmcInterface.h"
class com_jci_vbs_navi_tmc_objectAdapter
    : public DBus::Object {
 public:
  com_jci_vbs_navi_tmc_objectAdapter(std::shared_ptr<com_jci_vbs_navi_tmcInterface> _com_jci_vbs_navi_tmcInterface,
                                     std::string path);
 public:
  static std::shared_ptr<com_jci_vbs_navi_tmc_objectAdapter> create(std::shared_ptr<DBus::Connection> connection,
                                                                    std::shared_ptr<com_jci_vbs_navi_tmcInterface> _com_jci_vbs_navi_tmcInterface,
                                                                    std::string path,
                                                                    DBus::ThreadForCalling calling_thread = DBus::ThreadForCalling::DispatcherThread);
};
#endif /* COM_JCI_VBS_NAVI_TMC_OBJECTADAPTER_H */
