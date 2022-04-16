#ifndef COM_JCI_NATIVEGUICTRLINTERFACE_H
#define COM_JCI_NATIVEGUICTRLINTERFACE_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_nativeguictrl.h"
class com_jci_nativeguictrlInterface
    : public DBus::Interface {
 private:
  com_jci_nativeguictrlInterface(com_jci_nativeguictrl *adaptee, std::string name);
 public:
  static std::shared_ptr<com_jci_nativeguictrlInterface> create(com_jci_nativeguictrl *adaptee,
                                                                std::string name = "com.jci.nativeguictrl");
};
#endif /* COM_JCI_NATIVEGUICTRLINTERFACE_H */
