#ifndef COM_JCI_NAVI_IHU_HUDSETTINGSINTERFACE_H
#define COM_JCI_NAVI_IHU_HUDSETTINGSINTERFACE_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "com_jci_navi2IHU_HUDSettings.h"
class com_jci_navi2IHU_HUDSettingsInterface
    : public DBus::Interface {
 private:
  com_jci_navi2IHU_HUDSettingsInterface(com_jci_navi2IHU_HUDSettings *adaptee, std::string name);
 public:
  static std::shared_ptr<com_jci_navi2IHU_HUDSettingsInterface> create(com_jci_navi2IHU_HUDSettings *adaptee,
                                                                       std::string name = "com.jci.navi2IHU.HUDSettings");
  std::shared_ptr<DBus::Signal<void(bool)>> signal_HUDInstalledChanged();
  void HUDInstalledChanged(bool hUDInstalled);
  std::shared_ptr<DBus::Signal<void(int32_t, int32_t)>> signal_SetHUDSettingFailed();
  void SetHUDSettingFailed(int32_t hUDSettingType, int32_t err);
  std::shared_ptr<DBus::Signal<void(bool)>> signal_HUDControlAllowed();
  void HUDControlAllowed(bool bAllowed);
  std::shared_ptr<DBus::Signal<void(int32_t, int32_t)>> signal_HUDSettingChanged();
  void HUDSettingChanged(int32_t hUDSettingType, int32_t value);
 protected:
  std::shared_ptr<DBus::Signal<void(bool)>> m_signal_HUDInstalledChanged;
  std::shared_ptr<DBus::Signal<void(int32_t, int32_t)>> m_signal_SetHUDSettingFailed;
  std::shared_ptr<DBus::Signal<void(bool)>> m_signal_HUDControlAllowed;
  std::shared_ptr<DBus::Signal<void(int32_t, int32_t)>> m_signal_HUDSettingChanged;
};
#endif /* COM_JCI_NAVI_IHU_HUDSETTINGSINTERFACE_H */
