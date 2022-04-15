#ifndef COM_JCI_AAPA_OBJECTADAPTER_H
#define COM_JCI_AAPA_OBJECTADAPTER_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_aapaInterface.h"
class com_jci_aapa_objectAdapter
    : public DBus::Object {
 public:
  com_jci_aapa_objectAdapter(std::shared_ptr<com_jci_aapaInterface> _com_jci_aapaInterface, std::string path);
 public:
  static std::shared_ptr<com_jci_aapa_objectAdapter> create(std::shared_ptr<DBus::Connection> connection,
                                                            std::shared_ptr<com_jci_aapaInterface> _com_jci_aapaInterface,
                                                            std::string path,
                                                            DBus::ThreadForCalling calling_thread = DBus::ThreadForCalling::DispatcherThread);
};
#endif /* COM_JCI_AAPA_OBJECTADAPTER_H */
