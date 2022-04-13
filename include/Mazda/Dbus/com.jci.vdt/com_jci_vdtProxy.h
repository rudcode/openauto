#ifndef COM_JCI_VDTPROXY_H
#define COM_JCI_VDTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_vdtProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_vdtProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_vdtProxy> create(std::string name = "com.jci.vdt");
  int32_t MMUI_Startup_Initiated(bool vdt_mmui_init);
  int32_t DriveLogRecordingStatus(uint32_t record_status);
  void One_HrLog_File_Protect_Delete(std::tuple<uint8_t, uint8_t> one_hrlog_info);
  void File_List_Req();
  int32_t DiagnosticsMode_Request(uint16_t testscreen_ID);
  int32_t UserMode_Setting(uint16_t setting_type, bool value);
  int32_t UserMode_Request(uint16_t request_type);
  int32_t PIN_Request(uint16_t pin_req_type, uint16_t value);
  int32_t Screen_Req(uint32_t vDTScreen);
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    std::vector<std::tuple<std::string,
                                                                           uint8_t,
                                                                           uint32_t,
                                                                           bool>>>)>> signal_Drv_File_List();
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> signal_UMASS_Device_Status();
  std::shared_ptr<DBus::SignalProxy<void(uint16_t, bool)>> signal_MD_Device_Status();
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> signal_ClearDataStatus();
  std::shared_ptr<DBus::SignalProxy<void(uint16_t, uint16_t)>> signal_UmassTransferProgress();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_ActivateDeactivateRecordingStatus();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_Send_Pin_Validation_Result();
  std::shared_ptr<DBus::SignalProxy<void(bool, uint16_t)>> signal_Send_Pin_Updation_Result();
  std::shared_ptr<DBus::SignalProxy<void(uint16_t, bool)>> signal_Send_EOLConfig_Status();
  std::shared_ptr<DBus::SignalProxy<void(uint16_t, bool)>> signal_Send_HVD_Setting();
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> signal_Delete_DriveRecord_DataStatus();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t(bool)>> m_method_MMUI_Startup_Initiated;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_DriveLogRecordingStatus;
  std::shared_ptr<DBus::MethodProxy<void(std::tuple<uint8_t, uint8_t>)>> m_method_One_HrLog_File_Protect_Delete;
  std::shared_ptr<DBus::MethodProxy<void()>> m_method_File_List_Req;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint16_t)>> m_method_DiagnosticsMode_Request;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint16_t, bool)>> m_method_UserMode_Setting;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint16_t)>> m_method_UserMode_Request;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint16_t, uint16_t)>> m_method_PIN_Request;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_Screen_Req;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint8_t,
                                                    std::vector<std::tuple<std::string, uint8_t, uint32_t, bool>>>)>>
      m_signalproxy_Drv_File_List;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> m_signalproxy_UMASS_Device_Status;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t, bool)>> m_signalproxy_MD_Device_Status;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> m_signalproxy_ClearDataStatus;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t, uint16_t)>> m_signalproxy_UmassTransferProgress;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_ActivateDeactivateRecordingStatus;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_Send_Pin_Validation_Result;
  std::shared_ptr<DBus::SignalProxy<void(bool, uint16_t)>> m_signalproxy_Send_Pin_Updation_Result;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t, bool)>> m_signalproxy_Send_EOLConfig_Status;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t, bool)>> m_signalproxy_Send_HVD_Setting;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> m_signalproxy_Delete_DriveRecord_DataStatus;
};
#endif /* COM_JCI_VDTPROXY_H */
