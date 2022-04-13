#ifndef COM_JCI_VWMPROXY_H
#define COM_JCI_VWMPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_vwmProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_vwmProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_vwmProxy> create(std::string name = "com.jci.vwm");
  int32_t getWGuideSettings();
  int32_t getActiveAlertList(uint32_t warningScreen);
  int32_t Maintenance_Req(uint32_t maintenanceScreen);
  int32_t Sched_Maintenance_Req(uint32_t schedMaintenanceScreen);
  int32_t Tire_Maintenance_Req(uint32_t tireMaintenanceScreen);
  int32_t Oil_Deterioration_Maintenance_Req(uint32_t oilDeteriorationMaintenanceScreen);
  int32_t GetScdMntSettingData();
  int32_t SetSchdMaintUpdateEnable(int32_t vWM_SchMaintUpdateModule, bool status);
  int32_t setOilChangeSetting(int32_t vWM_OilChangeSettingStatus);
  void setSchedMaintSetting(int32_t vWM_ScdMaintSettingStatus);
  void setTireRotMaintSetting(int32_t vWM_TireRotMaintSettingStatus);
  void SchMntResetRq(int32_t resetProperty);
  void setSchedMaintSetDist(int32_t schMaintDistRem);
  void setSchedMaintSetTime(int32_t schMaintTimeRem);
  void setTireRotMaintSetDist(int32_t tireRotMaintDistRem);
  void setOilMaintSetDist(int32_t oiltMaintDistRem);
  int32_t GetVWMData();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_wGuideSettings();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t, std::vector<uint8_t>>)>> signal_wGuideActiveAlerts();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t, std::vector<uint8_t>>)>> signal_wGuideNewHighAlerts();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<bool,
                                                    uint32_t,
                                                    int32_t,
                                                    int32_t,
                                                    int32_t,
                                                    int16_t,
                                                    int16_t,
                                                    int16_t,
                                                    int16_t,
                                                    int16_t,
                                                    int16_t,
                                                    int16_t,
                                                    uint32_t,
                                                    uint32_t,
                                                    uint32_t,
                                                    uint32_t>)>> signal_ScdMntSettingDataAsyncResp();
  std::shared_ptr<DBus::SignalProxy<void(int32_t, uint32_t)>> signal_SchedMaintRemainingDist();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_SchedMaintRemainingTime();
  std::shared_ptr<DBus::SignalProxy<void(int32_t, uint32_t)>> signal_TireRotationRemainingDist();
  std::shared_ptr<DBus::SignalProxy<void(int32_t, int32_t)>> signal_OilLife();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_VehicleStatusMonitor();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_OilLevelStatus();
  std::shared_ptr<DBus::SignalProxy<void(int32_t, bool, int32_t)>> signal_schdMntDue();
  std::shared_ptr<DBus::SignalProxy<void(int32_t, uint32_t)>> signal_OilChangeRemainingDist();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_SchMntSettingChangeStatus();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_Dismiss_High_Alert();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t,
                                                    int32_t,
                                                    int32_t,
                                                    int32_t,
                                                    uint32_t,
                                                    bool,
                                                    bool,
                                                    bool,
                                                    bool,
                                                    uint8_t>)>> signal_Curr_VWMData();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_FSC_Types();
  std::shared_ptr<DBus::SignalProxy<void(uint16_t, uint8_t)>> signal_VehicleModelType();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_getWGuideSettings;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_getActiveAlertList;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_Maintenance_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_Sched_Maintenance_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_Tire_Maintenance_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_Oil_Deterioration_Maintenance_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetScdMntSettingData;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t, bool)>> m_method_SetSchdMaintUpdateEnable;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_setOilChangeSetting;
  std::shared_ptr<DBus::MethodProxy<void(int32_t)>> m_method_setSchedMaintSetting;
  std::shared_ptr<DBus::MethodProxy<void(int32_t)>> m_method_setTireRotMaintSetting;
  std::shared_ptr<DBus::MethodProxy<void(int32_t)>> m_method_SchMntResetRq;
  std::shared_ptr<DBus::MethodProxy<void(int32_t)>> m_method_setSchedMaintSetDist;
  std::shared_ptr<DBus::MethodProxy<void(int32_t)>> m_method_setSchedMaintSetTime;
  std::shared_ptr<DBus::MethodProxy<void(int32_t)>> m_method_setTireRotMaintSetDist;
  std::shared_ptr<DBus::MethodProxy<void(int32_t)>> m_method_setOilMaintSetDist;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetVWMData;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_wGuideSettings;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t, std::vector<uint8_t>>)>> m_signalproxy_wGuideActiveAlerts;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t, std::vector<uint8_t>>)>> m_signalproxy_wGuideNewHighAlerts;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<bool,
                                                    uint32_t,
                                                    int32_t,
                                                    int32_t,
                                                    int32_t,
                                                    int16_t,
                                                    int16_t,
                                                    int16_t,
                                                    int16_t,
                                                    int16_t,
                                                    int16_t,
                                                    int16_t,
                                                    uint32_t,
                                                    uint32_t,
                                                    uint32_t,
                                                    uint32_t>)>> m_signalproxy_ScdMntSettingDataAsyncResp;
  std::shared_ptr<DBus::SignalProxy<void(int32_t, uint32_t)>> m_signalproxy_SchedMaintRemainingDist;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_SchedMaintRemainingTime;
  std::shared_ptr<DBus::SignalProxy<void(int32_t, uint32_t)>> m_signalproxy_TireRotationRemainingDist;
  std::shared_ptr<DBus::SignalProxy<void(int32_t, int32_t)>> m_signalproxy_OilLife;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_VehicleStatusMonitor;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_OilLevelStatus;
  std::shared_ptr<DBus::SignalProxy<void(int32_t, bool, int32_t)>> m_signalproxy_schdMntDue;
  std::shared_ptr<DBus::SignalProxy<void(int32_t, uint32_t)>> m_signalproxy_OilChangeRemainingDist;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_SchMntSettingChangeStatus;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_Dismiss_High_Alert;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t,
                                                    int32_t,
                                                    int32_t,
                                                    int32_t,
                                                    uint32_t,
                                                    bool,
                                                    bool,
                                                    bool,
                                                    bool,
                                                    uint8_t>)>> m_signalproxy_Curr_VWMData;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_FSC_Types;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t, uint8_t)>> m_signalproxy_VehicleModelType;
};
#endif /* COM_JCI_VWMPROXY_H */
