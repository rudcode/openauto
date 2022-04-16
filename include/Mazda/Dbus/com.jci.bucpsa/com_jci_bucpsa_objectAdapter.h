#ifndef COM_JCI_BUCPSA_OBJECTADAPTER_H
#define COM_JCI_BUCPSA_OBJECTADAPTER_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_bucpsaInterface.h"
class com_jci_bucpsa_objectAdapter
    : public DBus::Object {
 public:
  com_jci_bucpsa_objectAdapter(std::shared_ptr<com_jci_bucpsaInterface> _com_jci_bucpsaInterface, std::string path);
 public:
  static std::shared_ptr<com_jci_bucpsa_objectAdapter> create(std::shared_ptr<DBus::Connection> connection,
                                                              std::shared_ptr<com_jci_bucpsaInterface> _com_jci_bucpsaInterface,
                                                              std::string path,
                                                              DBus::ThreadForCalling calling_thread = DBus::ThreadForCalling::DispatcherThread);
};
#endif /* COM_JCI_BUCPSA_OBJECTADAPTER_H */
