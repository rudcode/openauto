#ifndef COM_JCI_LDS_CONTROL_OBJECTADAPTER_H
#define COM_JCI_LDS_CONTROL_OBJECTADAPTER_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_lds_controlInterface.h"
class com_jci_lds_control_objectAdapter
    : public DBus::Object {
 public:
  com_jci_lds_control_objectAdapter(std::shared_ptr<com_jci_lds_controlInterface> _com_jci_lds_controlInterface,
                                    std::string path);
 public:
  static std::shared_ptr<com_jci_lds_control_objectAdapter> create(std::shared_ptr<DBus::Connection> connection,
                                                                   std::shared_ptr<com_jci_lds_controlInterface> _com_jci_lds_controlInterface,
                                                                   std::string path,
                                                                   DBus::ThreadForCalling calling_thread = DBus::ThreadForCalling::DispatcherThread);
};
#endif /* COM_JCI_LDS_CONTROL_OBJECTADAPTER_H */
