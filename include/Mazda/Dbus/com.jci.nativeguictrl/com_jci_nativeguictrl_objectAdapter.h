#ifndef COM_JCI_NATIVEGUICTRL_OBJECTADAPTER_H
#define COM_JCI_NATIVEGUICTRL_OBJECTADAPTER_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_nativeguictrlInterface.h"
class com_jci_nativeguictrl_objectAdapter
    : public DBus::Object {
 public:
  com_jci_nativeguictrl_objectAdapter(std::shared_ptr<com_jci_nativeguictrlInterface> _com_jci_nativeguictrlInterface,
                                      std::string path);
 public:
  static std::shared_ptr<com_jci_nativeguictrl_objectAdapter> create(std::shared_ptr<DBus::Connection> connection,
                                                                     std::shared_ptr<com_jci_nativeguictrlInterface> _com_jci_nativeguictrlInterface,
                                                                     std::string path,
                                                                     DBus::ThreadForCalling calling_thread = DBus::ThreadForCalling::DispatcherThread);
};
#endif /* COM_JCI_NATIVEGUICTRL_OBJECTADAPTER_H */
