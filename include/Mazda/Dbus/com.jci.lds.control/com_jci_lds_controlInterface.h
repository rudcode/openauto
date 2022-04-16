#ifndef COM_JCI_LDS_CONTROLINTERFACE_H
#define COM_JCI_LDS_CONTROLINTERFACE_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_lds_control.h"
class com_jci_lds_controlInterface
    : public DBus::Interface {
 private:
  com_jci_lds_controlInterface(com_jci_lds_control *adaptee, std::string name);
 public:
  static std::shared_ptr<com_jci_lds_controlInterface> create(com_jci_lds_control *adaptee,
                                                              std::string name = "com.jci.lds.control");
  std::shared_ptr<DBus::Signal<void(int32_t, int32_t)>> signal_ReadStatus();
  void ReadStatus(int32_t commandReply, int32_t status);
 protected:
  std::shared_ptr<DBus::Signal<void(int32_t, int32_t)>> m_signal_ReadStatus;
};
#endif /* COM_JCI_LDS_CONTROLINTERFACE_H */
