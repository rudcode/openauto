#ifndef COM_JCI_NAVI_IHU_HUDSETTINGS_OBJECTADAPTER_H
#define COM_JCI_NAVI_IHU_HUDSETTINGS_OBJECTADAPTER_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_navi2IHU_HUDSettingsInterface.h"
class com_jci_navi2IHU_HUDSettings_objectAdapter
    : public DBus::Object {
 public:
  com_jci_navi2IHU_HUDSettings_objectAdapter(std::shared_ptr<com_jci_navi2IHU_HUDSettingsInterface> _com_jci_navi2IHU_HUDSettingsInterface,
                                             std::string path);
 public:
  static std::shared_ptr<com_jci_navi2IHU_HUDSettings_objectAdapter> create(std::shared_ptr<DBus::Connection> connection,
                                                                            std::shared_ptr<
                                                                                com_jci_navi2IHU_HUDSettingsInterface> _com_jci_navi2IHU_HUDSettingsInterface,
                                                                            std::string path,
                                                                            DBus::ThreadForCalling calling_thread = DBus::ThreadForCalling::DispatcherThread);
};
#endif /* COM_JCI_NAVI_IHU_HUDSETTINGS_OBJECTADAPTER_H */
