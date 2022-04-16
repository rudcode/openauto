#ifndef COM_JCI_LDS_DATA_OBJECTADAPTER_H
#define COM_JCI_LDS_DATA_OBJECTADAPTER_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_lds_dataInterface.h"
class com_jci_lds_data_objectAdapter
    : public DBus::Object {
 public:
  com_jci_lds_data_objectAdapter(std::shared_ptr<com_jci_lds_dataInterface> _com_jci_lds_dataInterface,
                                 std::string path);
 public:
  static std::shared_ptr<com_jci_lds_data_objectAdapter> create(std::shared_ptr<DBus::Connection> connection,
                                                                std::shared_ptr<com_jci_lds_dataInterface> _com_jci_lds_dataInterface,
                                                                std::string path,
                                                                DBus::ThreadForCalling calling_thread = DBus::ThreadForCalling::DispatcherThread);
};
#endif /* COM_JCI_LDS_DATA_OBJECTADAPTER_H */
