#include "com_jci_vwmProxy.h"

com_jci_vwmProxy::com_jci_vwmProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_getWGuideSettings = this->create_method<int32_t()>("getWGuideSettings");
  m_method_getActiveAlertList = this->create_method<int32_t(uint32_t)>("getActiveAlertList");
  m_method_Maintenance_Req = this->create_method<int32_t(uint32_t)>("Maintenance_Req");
  m_method_Sched_Maintenance_Req = this->create_method<int32_t(uint32_t)>("Sched_Maintenance_Req");
  m_method_Tire_Maintenance_Req = this->create_method<int32_t(uint32_t)>("Tire_Maintenance_Req");
  m_method_Oil_Deterioration_Maintenance_Req =
      this->create_method<int32_t(uint32_t)>("Oil_Deterioration_Maintenance_Req");
  m_method_GetScdMntSettingData = this->create_method<int32_t()>("GetScdMntSettingData");
  m_method_SetSchdMaintUpdateEnable = this->create_method<int32_t(int32_t, bool)>("SetSchdMaintUpdateEnable");
  m_method_setOilChangeSetting = this->create_method<int32_t(int32_t)>("setOilChangeSetting");
  m_method_setSchedMaintSetting = this->create_method<void(int32_t)>("setSchedMaintSetting");
  m_method_setTireRotMaintSetting = this->create_method<void(int32_t)>("setTireRotMaintSetting");
  m_method_SchMntResetRq = this->create_method<void(int32_t)>("SchMntResetRq");
  m_method_setSchedMaintSetDist = this->create_method<void(int32_t)>("setSchedMaintSetDist");
  m_method_setSchedMaintSetTime = this->create_method<void(int32_t)>("setSchedMaintSetTime");
  m_method_setTireRotMaintSetDist = this->create_method<void(int32_t)>("setTireRotMaintSetDist");
  m_method_setOilMaintSetDist = this->create_method<void(int32_t)>("setOilMaintSetDist");
  m_method_GetVWMData = this->create_method<int32_t()>("GetVWMData");
  m_signalproxy_wGuideSettings = this->create_signal<void(int32_t)>("wGuideSettings");
  m_signalproxy_wGuideActiveAlerts =
      this->create_signal<void(std::tuple < int32_t, std::vector < uint8_t >> )>("wGuideActiveAlerts");
  m_signalproxy_wGuideNewHighAlerts =
      this->create_signal<void(std::tuple < int32_t, std::vector < uint8_t >> )>("wGuideNewHighAlerts");
  m_signalproxy_ScdMntSettingDataAsyncResp = this->create_signal<void(std::tuple < bool,
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
                                                                      uint32_t > )>("ScdMntSettingDataAsyncResp");
  m_signalproxy_SchedMaintRemainingDist = this->create_signal<void(int32_t, uint32_t)>("SchedMaintRemainingDist");
  m_signalproxy_SchedMaintRemainingTime = this->create_signal<void(int32_t)>("SchedMaintRemainingTime");
  m_signalproxy_TireRotationRemainingDist = this->create_signal<void(int32_t, uint32_t)>("TireRotationRemainingDist");
  m_signalproxy_OilLife = this->create_signal<void(int32_t, int32_t)>("OilLife");
  m_signalproxy_VehicleStatusMonitor = this->create_signal<void(bool)>("VehicleStatusMonitor");
  m_signalproxy_OilLevelStatus = this->create_signal<void(int32_t)>("OilLevelStatus");
  m_signalproxy_schdMntDue = this->create_signal<void(int32_t, bool, int32_t)>("schdMntDue");
  m_signalproxy_OilChangeRemainingDist = this->create_signal<void(int32_t, uint32_t)>("OilChangeRemainingDist");
  m_signalproxy_SchMntSettingChangeStatus = this->create_signal<void(int32_t)>("SchMntSettingChangeStatus");
  m_signalproxy_Dismiss_High_Alert = this->create_signal<void(int32_t)>("Dismiss_High_Alert");
  m_signalproxy_Curr_VWMData = this->create_signal<void(std::tuple < int32_t,
                                                        int32_t,
                                                        int32_t,
                                                        int32_t,
                                                        uint32_t,
                                                        bool,
                                                        bool,
                                                        bool,
                                                        bool,
                                                        uint8_t > )>("Curr_VWMData");
  m_signalproxy_FSC_Types = this->create_signal<void(int32_t)>("FSC_Types");
  m_signalproxy_VehicleModelType = this->create_signal<void(uint16_t, uint8_t)>("VehicleModelType");

}
std::shared_ptr <com_jci_vwmProxy> com_jci_vwmProxy::create(std::string name) {
  return std::shared_ptr<com_jci_vwmProxy>(new com_jci_vwmProxy(name));

}
int32_t com_jci_vwmProxy::getWGuideSettings() {
  return (*m_method_getWGuideSettings)();

}
int32_t com_jci_vwmProxy::getActiveAlertList(uint32_t warningScreen) {
  return (*m_method_getActiveAlertList)(warningScreen);

}
int32_t com_jci_vwmProxy::Maintenance_Req(uint32_t maintenanceScreen) {
  return (*m_method_Maintenance_Req)(maintenanceScreen);

}
int32_t com_jci_vwmProxy::Sched_Maintenance_Req(uint32_t schedMaintenanceScreen) {
  return (*m_method_Sched_Maintenance_Req)(schedMaintenanceScreen);

}
int32_t com_jci_vwmProxy::Tire_Maintenance_Req(uint32_t tireMaintenanceScreen) {
  return (*m_method_Tire_Maintenance_Req)(tireMaintenanceScreen);

}
int32_t com_jci_vwmProxy::Oil_Deterioration_Maintenance_Req(uint32_t oilDeteriorationMaintenanceScreen) {
  return (*m_method_Oil_Deterioration_Maintenance_Req)(oilDeteriorationMaintenanceScreen);

}
int32_t com_jci_vwmProxy::GetScdMntSettingData() {
  return (*m_method_GetScdMntSettingData)();

}
int32_t com_jci_vwmProxy::SetSchdMaintUpdateEnable(int32_t vWM_SchMaintUpdateModule, bool status) {
  return (*m_method_SetSchdMaintUpdateEnable)(vWM_SchMaintUpdateModule, status);

}
int32_t com_jci_vwmProxy::setOilChangeSetting(int32_t vWM_OilChangeSettingStatus) {
  return (*m_method_setOilChangeSetting)(vWM_OilChangeSettingStatus);

}
void com_jci_vwmProxy::setSchedMaintSetting(int32_t vWM_ScdMaintSettingStatus) {
  (*m_method_setSchedMaintSetting)(vWM_ScdMaintSettingStatus);

}
void com_jci_vwmProxy::setTireRotMaintSetting(int32_t vWM_TireRotMaintSettingStatus) {
  (*m_method_setTireRotMaintSetting)(vWM_TireRotMaintSettingStatus);

}
void com_jci_vwmProxy::SchMntResetRq(int32_t resetProperty) {
  (*m_method_SchMntResetRq)(resetProperty);

}
void com_jci_vwmProxy::setSchedMaintSetDist(int32_t schMaintDistRem) {
  (*m_method_setSchedMaintSetDist)(schMaintDistRem);

}
void com_jci_vwmProxy::setSchedMaintSetTime(int32_t schMaintTimeRem) {
  (*m_method_setSchedMaintSetTime)(schMaintTimeRem);

}
void com_jci_vwmProxy::setTireRotMaintSetDist(int32_t tireRotMaintDistRem) {
  (*m_method_setTireRotMaintSetDist)(tireRotMaintDistRem);

}
void com_jci_vwmProxy::setOilMaintSetDist(int32_t oiltMaintDistRem) {
  (*m_method_setOilMaintSetDist)(oiltMaintDistRem);

}
int32_t com_jci_vwmProxy::GetVWMData() {
  return (*m_method_GetVWMData)();

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_vwmProxy::signal_wGuideSettings() {
  return m_signalproxy_wGuideSettings;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < int32_t,
                                        std::vector < uint8_t >> )>> com_jci_vwmProxy::signal_wGuideActiveAlerts() {
  return m_signalproxy_wGuideActiveAlerts;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < int32_t,
                                        std::vector < uint8_t >> )>> com_jci_vwmProxy::signal_wGuideNewHighAlerts() {
  return m_signalproxy_wGuideNewHighAlerts;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < bool,
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
                                        uint32_t > )>> com_jci_vwmProxy::signal_ScdMntSettingDataAsyncResp() {
  return m_signalproxy_ScdMntSettingDataAsyncResp;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t, uint32_t)>> com_jci_vwmProxy::signal_SchedMaintRemainingDist() {
  return m_signalproxy_SchedMaintRemainingDist;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_vwmProxy::signal_SchedMaintRemainingTime() {
  return m_signalproxy_SchedMaintRemainingTime;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t, uint32_t)>> com_jci_vwmProxy::signal_TireRotationRemainingDist() {
  return m_signalproxy_TireRotationRemainingDist;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t, int32_t)>> com_jci_vwmProxy::signal_OilLife() {
  return m_signalproxy_OilLife;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_vwmProxy::signal_VehicleStatusMonitor() {
  return m_signalproxy_VehicleStatusMonitor;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_vwmProxy::signal_OilLevelStatus() {
  return m_signalproxy_OilLevelStatus;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t, bool, int32_t)>> com_jci_vwmProxy::signal_schdMntDue() {
  return m_signalproxy_schdMntDue;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t, uint32_t)>> com_jci_vwmProxy::signal_OilChangeRemainingDist() {
  return m_signalproxy_OilChangeRemainingDist;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_vwmProxy::signal_SchMntSettingChangeStatus() {
  return m_signalproxy_SchMntSettingChangeStatus;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_vwmProxy::signal_Dismiss_High_Alert() {
  return m_signalproxy_Dismiss_High_Alert;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < int32_t,
                                        int32_t,
                                        int32_t,
                                        int32_t,
                                        uint32_t,
                                        bool,
                                        bool,
                                        bool,
                                        bool,
                                        uint8_t > )>> com_jci_vwmProxy::signal_Curr_VWMData() {
  return m_signalproxy_Curr_VWMData;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_vwmProxy::signal_FSC_Types() {
  return m_signalproxy_FSC_Types;

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t, uint8_t)>> com_jci_vwmProxy::signal_VehicleModelType() {
  return m_signalproxy_VehicleModelType;

}
