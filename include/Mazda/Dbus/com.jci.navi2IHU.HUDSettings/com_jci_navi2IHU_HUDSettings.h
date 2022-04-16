#ifndef COM_JCI_NAVI_IHU_HUDSETTINGS_H
#define COM_JCI_NAVI_IHU_HUDSETTINGS_H

#include <stdint.h>
class com_jci_navi2IHU_HUDSettings {
 public:
  virtual bool GetHUDIsInstalled() = 0;
  virtual bool GetHUDIsInstalled_async() = 0;
  virtual void SetHUDSetting(int32_t hUDSettingType, int32_t hUDSettingValue) = 0;
  virtual void SetHUDSetting_Async(int32_t hUDSettingType, int32_t hUDSettingValue) = 0;
  virtual int32_t GetHUDSetting(int32_t hUDSettingType) = 0;
  virtual void ResetHUDSettings() = 0;
  virtual int32_t GetHUDControlAllowed() = 0;
};
#endif /* COM_JCI_NAVI_IHU_HUDSETTINGS_H */
