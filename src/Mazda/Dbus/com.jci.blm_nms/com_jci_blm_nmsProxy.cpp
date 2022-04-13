#include "com_jci_blm_nmsProxy.h"

com_jci_blm_nmsProxy::com_jci_blm_nmsProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_GetConnectionState = this->create_method<DBus::MultipleReturn<int32_t, int32_t>()>("GetConnectionState");
  m_method_GetConnectionState_Async =
      this->create_method<DBus::MultipleReturn<int32_t, int32_t>()>("GetConnectionState_Async");
  m_method_Connect = this->create_method<DBus::MultipleReturn<int32_t, int32_t>(int32_t)>("Connect");
  m_method_Connect_Async = this->create_method<DBus::MultipleReturn<int32_t, int32_t>(int32_t)>("Connect_Async");
  m_method_Disconnect = this->create_method<int32_t(int32_t)>("Disconnect");
  m_method_Disconnect_Async = this->create_method<int32_t(int32_t)>("Disconnect_Async");
  m_method_Abort = this->create_method<int32_t(int32_t)>("Abort");
  m_method_Abort_Async = this->create_method<int32_t(int32_t)>("Abort_Async");
  m_method_SetWiFiAutoconnect = this->create_method<int32_t(bool)>("SetWiFiAutoconnect");
  m_method_SetWiFiAutoconnect_Async = this->create_method<int32_t(bool)>("SetWiFiAutoconnect_Async");
  m_method_GetWiFiAutoconnect = this->create_method<DBus::MultipleReturn<int32_t, bool>()>("GetWiFiAutoconnect");
  m_method_GetWiFiAutoconnect_Async =
      this->create_method<DBus::MultipleReturn<int32_t, bool>()>("GetWiFiAutoconnect_Async");
  m_method_SetModemAutoconnect = this->create_method<int32_t(bool)>("SetModemAutoconnect");
  m_method_SetModemAutoconnect_Async = this->create_method<int32_t(bool)>("SetModemAutoconnect_Async");
  m_method_GetModemAutoconnect = this->create_method<DBus::MultipleReturn<int32_t, bool>()>("GetModemAutoconnect");
  m_method_GetModemAutoconnect_Async =
      this->create_method<DBus::MultipleReturn<int32_t, bool>()>("GetModemAutoconnect_Async");
  m_method_GetInterfaceList = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector
      < int32_t>>>() > ("GetInterfaceList");
  m_method_GetInterfaceList_Async = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector
      < int32_t>>>() > ("GetInterfaceList_Async");
  m_method_GetInterfaceParams = this->create_method < DBus::MultipleReturn < int32_t, std::tuple
      < int32_t, int32_t, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, int32_t, int32_t, int32_t,
      int32_t >> (int32_t) > ("GetInterfaceParams");
  m_method_GetInterfaceParams_Async = this->create_method < DBus::MultipleReturn < int32_t, std::tuple
      < int32_t, int32_t, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, int32_t, int32_t, int32_t,
      int32_t >> (int32_t) > ("GetInterfaceParams_Async");
  m_method_SetInterfaceParams = this->create_method<int32_t(int32_t,
                                                            std::tuple < std::string,
                                                            std::string,
                                                            std::string,
                                                            std::string,
                                                            std::string,
                                                            std::string,
                                                            int32_t,
                                                            int32_t > ,
                                                            int32_t)>("SetInterfaceParams");
  m_method_SetInterfaceParams_Async = this->create_method<int32_t(int32_t,
                                                                  std::tuple < std::string,
                                                                  std::string,
                                                                  std::string,
                                                                  std::string,
                                                                  std::string,
                                                                  std::string,
                                                                  int32_t,
                                                                  int32_t > ,
                                                                  int32_t)>("SetInterfaceParams_Async");
  m_method_DHCP_ServerSetConfig =
      this->create_method<int32_t(int32_t, std::tuple < std::string, std::string > )>("DHCP_ServerSetConfig");
  m_method_DHCP_ServerSetConfig_Async =
      this->create_method<int32_t(int32_t, std::tuple < std::string, std::string > )>("DHCP_ServerSetConfig_Async");
  m_method_DHCP_ServerGetConfig = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::string,
      std::string >> (int32_t) > ("DHCP_ServerGetConfig");
  m_method_DHCP_ServerGetConfig_Async = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::string,
      std::string >> (int32_t) > ("DHCP_ServerGetConfig_Async");
  m_method_DHCP_ServerStart = this->create_method<int32_t(int32_t)>("DHCP_ServerStart");
  m_method_DHCP_ServerStart_Async = this->create_method<int32_t(int32_t)>("DHCP_ServerStart_Async");
  m_method_DHCP_ServerStop = this->create_method<int32_t(int32_t)>("DHCP_ServerStop");
  m_method_DHCP_ServerStop_Async = this->create_method<int32_t(int32_t)>("DHCP_ServerStop_Async");
  m_method_DHCP_ServerGetClients = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector
      < std::tuple < std::string, std::string, std::string, std::string >> >> (int32_t) > ("DHCP_ServerGetClients");
  m_method_DHCP_ServerGetClients_Async = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector
      < std::tuple < std::string, std::string, std::string, std::string >> >> (int32_t)
      > ("DHCP_ServerGetClients_Async");
  m_method_ActivateNAT = this->create_method<int32_t(bool)>("ActivateNAT");
  m_method_ActivateNAT_Async = this->create_method<int32_t(bool)>("ActivateNAT_Async");
  m_method_AdvancedRouting = this->create_method<int32_t(bool)>("AdvancedRouting");
  m_method_AdvancedRouting_Async = this->create_method<int32_t(bool)>("AdvancedRouting_Async");
  m_method_SetHostname = this->create_method<int32_t(std::string)>("SetHostname");
  m_method_SetHostname_Async = this->create_method<int32_t(std::string)>("SetHostname_Async");
  m_method_GetHostname = this->create_method<DBus::MultipleReturn<int32_t, std::string>()>("GetHostname");
  m_method_GetHostname_Async = this->create_method<DBus::MultipleReturn<int32_t, std::string>()>("GetHostname_Async");
  m_method_MonitorInterface = this->create_method<int32_t(int32_t, bool)>("MonitorInterface");
  m_method_MonitorInterface_Async = this->create_method<int32_t(int32_t, bool)>("MonitorInterface_Async");
  m_method_WIFI_SetMode = this->create_method<int32_t(int32_t, int32_t)>("WIFI_SetMode");
  m_method_WIFI_SetMode_Async = this->create_method<int32_t(int32_t, int32_t)>("WIFI_SetMode_Async");
  m_method_WIFI_GetMode = this->create_method<DBus::MultipleReturn<int32_t, int32_t>(int32_t)>("WIFI_GetMode");
  m_method_WIFI_GetMode_Async =
      this->create_method<DBus::MultipleReturn<int32_t, int32_t>(int32_t)>("WIFI_GetMode_Async");
  m_method_WIFI_SelectNetwork = this->create_method<int32_t(int32_t, int32_t)>("WIFI_SelectNetwork");
  m_method_WIFI_SelectNetwork_Async = this->create_method<int32_t(int32_t, int32_t)>("WIFI_SelectNetwork_Async");
  m_method_WIFI_GetSelectNetwork =
      this->create_method<DBus::MultipleReturn<int32_t, int32_t>(int32_t)>("WIFI_GetSelectNetwork");
  m_method_WIFI_GetSelectNetwork_Async =
      this->create_method<DBus::MultipleReturn<int32_t, int32_t>(int32_t)>("WIFI_GetSelectNetwork_Async");
  m_method_WIFI_AddNetwork = this->create_method<DBus::MultipleReturn<int32_t, int32_t>(int32_t,
                                                                                        std::tuple < std::string,
                                                                                        std::string,
                                                                                        int32_t,
                                                                                        bool,
                                                                                        std::string > )>(
      "WIFI_AddNetwork");
  m_method_WIFI_AddNetwork_Async = this->create_method<DBus::MultipleReturn<int32_t, int32_t>(int32_t,
                                                                                              std::tuple < std::string,
                                                                                              std::string,
                                                                                              int32_t,
                                                                                              bool,
                                                                                              std::string > )>(
      "WIFI_AddNetwork_Async");
  m_method_WIFI_AddNetwork_Ex =
      this->create_method<DBus::MultipleReturn<int32_t, int32_t>(int32_t, Invalid)>("WIFI_AddNetwork_Ex");
  m_method_WIFI_AddNetwork_Ex_Async =
      this->create_method<DBus::MultipleReturn<int32_t, int32_t>(int32_t, Invalid)>("WIFI_AddNetwork_Ex_Async");
  m_method_WIFI_RemoveConfiguredNetwork =
      this->create_method<int32_t(int32_t, int32_t)>("WIFI_RemoveConfiguredNetwork");
  m_method_WIFI_RemoveConfiguredNetwork_Async =
      this->create_method<int32_t(int32_t, int32_t)>("WIFI_RemoveConfiguredNetwork_Async");
  m_method_WIFI_UpdateNetworkPass =
      this->create_method<int32_t(int32_t, uint32_t, std::string)>("WIFI_UpdateNetworkPass");
  m_method_WIFI_UpdateNetworkPass_Async =
      this->create_method<int32_t(int32_t, uint32_t, std::string)>("WIFI_UpdateNetworkPass_Async");
  m_method_WIFI_UpdateConfiguredNetwork =
      this->create_method<int32_t(int32_t, int32_t, Invalid)>("WIFI_UpdateConfiguredNetwork");
  m_method_WIFI_UpdateNetwork_Async =
      this->create_method<int32_t(int32_t, int32_t, Invalid)>("WIFI_UpdateNetwork_Async");
  m_method_WIFI_SaveConfiguredNetworks = this->create_method<int32_t(int32_t)>("WIFI_SaveConfiguredNetworks");
  m_method_WIFI_SaveConfiguredNetworks_Async =
      this->create_method<int32_t(int32_t)>("WIFI_SaveConfiguredNetworks_Async");
  m_method_WIFI_StartScan = this->create_method<int32_t(int32_t, int32_t)>("WIFI_StartScan");
  m_method_WIFI_StartScan_Async = this->create_method<int32_t(int32_t, int32_t)>("WIFI_StartScan_Async");
  m_method_WIFI_StopScan = this->create_method<int32_t(int32_t)>("WIFI_StopScan");
  m_method_WIFI_StopScan_Async = this->create_method<int32_t(int32_t)>("WIFI_StopScan_Async");
  m_method_WIFI_GetScanResults = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector
      < std::tuple < std::string, std::string, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t,
      int32_t >> >> (int32_t) > ("WIFI_GetScanResults");
  m_method_WIFI_GetScanResults_Async = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector
      < std::tuple < std::string, std::string, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t,
      int32_t >> >> (int32_t) > ("WIFI_GetScanResults_Async");
  m_method_WIFI_GetConfiguredNetworks = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector
      < std::tuple < uint32_t, std::string, std::string, int32_t, bool, std::string, int32_t >> >> (int32_t)
      > ("WIFI_GetConfiguredNetworks");
  m_method_WIFI_GetConfiguredNetworks_Async = this->create_method < DBus::MultipleReturn < int32_t, std::tuple
      < std::vector < std::tuple < uint32_t, std::string, std::string, int32_t, bool, std::string,
      int32_t >> >> (int32_t) > ("WIFI_GetConfiguredNetworks_Async");
  m_method_WIFI_GetConfiguredNetworks_Ex =
      this->create_method<DBus::MultipleReturn<int32_t, Invalid>(int32_t)>("WIFI_GetConfiguredNetworks_Ex");
  m_method_WIFI_GetConfiguredNetworks_Ex_Async =
      this->create_method<DBus::MultipleReturn<int32_t, Invalid>(int32_t)>("WIFI_GetConfiguredNetworks_Ex_Async");
  m_method_WIFI_GetNetCount =
      this->create_method<DBus::MultipleReturn<int32_t, int32_t, int32_t>(int32_t)>("WIFI_GetNetCount");
  m_method_WIFI_GetNetCount_Async =
      this->create_method<DBus::MultipleReturn<int32_t, int32_t, int32_t>(int32_t)>("WIFI_GetNetCount_Async");
  m_method_WIFI_GetConnectionInfo = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < uint32_t,
      std::tuple
          < std::string, std::string, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, int32_t>>>
  (int32_t) > ("WIFI_GetConnectionInfo");
  m_method_WIFI_GetConnectionInfo_Async = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < uint32_t,
      std::tuple
          < std::string, std::string, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, int32_t>>>
  (int32_t) > ("WIFI_GetConnectionInfo_Async");
  m_method_WIFI_GetCombinedNetworksList = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector
      < std::tuple < uint32_t, std::string, std::string, int32_t, int32_t, int32_t, int32_t >> >> (int32_t)
      > ("WIFI_GetCombinedNetworksList");
  m_method_WIFI_GetCombinedNetworksList_Async = this->create_method < DBus::MultipleReturn < int32_t, std::tuple
      < std::vector < std::tuple < uint32_t, std::string, std::string, int32_t, int32_t, int32_t,
      int32_t >> >> (int32_t) > ("WIFI_GetCombinedNetworksList_Async");
  m_method_AP_SelectConfiguration = this->create_method<int32_t(int32_t)>("AP_SelectConfiguration");
  m_method_AP_SelectConfiguration_Async = this->create_method<int32_t(int32_t)>("AP_SelectConfiguration_Async");
  m_method_AP_GetSelectedConfiguration =
      this->create_method<DBus::MultipleReturn<int32_t, int32_t>()>("AP_GetSelectedConfiguration");
  m_method_AP_GetSelectedConfiguration_Async =
      this->create_method<DBus::MultipleReturn<int32_t, int32_t>()>("AP_GetSelectedConfiguration_Async");
  m_method_AP_SetHostConfig =
      this->create_method<int32_t(std::tuple < std::string, std::string, int32_t, bool > )>("AP_SetHostConfig");
  m_method_AP_SetHostConfig_Async =
      this->create_method<int32_t(std::tuple < std::string, std::string, int32_t, bool > )>("AP_SetHostConfig_Async");
  m_method_AP_GetHostConfig = this->create_method < DBus::MultipleReturn < int32_t, std::tuple
      < std::string, std::string, int32_t, bool >> (int32_t) > ("AP_GetHostConfig");
  m_method_AP_GetHostConfig_Async = this->create_method < DBus::MultipleReturn < int32_t, std::tuple
      < std::string, std::string, int32_t, bool >> (int32_t) > ("AP_GetHostConfig_Async");
  m_method_AP_GetClients = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector < std::tuple
      < std::string, std::string, std::string, std::string >> >> (int32_t) > ("AP_GetClients");
  m_method_AP_GetClients_Async = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector
      < std::tuple < std::string, std::string, std::string, std::string >> >> (int32_t) > ("AP_GetClients_Async");
  m_method_AP_AddToBlacklist = this->create_method<int32_t(int32_t, std::string)>("AP_AddToBlacklist");
  m_method_AP_AddToBlacklist_Async = this->create_method<int32_t(int32_t, std::string)>("AP_AddToBlacklist_Async");
  m_method_AP_RemoveFromBlacklist = this->create_method<int32_t(int32_t, std::string)>("AP_RemoveFromBlacklist");
  m_method_AP_RemoveFromBlacklist_Async =
      this->create_method<int32_t(int32_t, std::string)>("AP_RemoveFromBlacklist_Async");
  m_method_AP_GetBlacklist = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector
      < std::string>>>(int32_t) > ("AP_GetBlacklist");
  m_method_AP_GetBlacklist_Async = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector
      < std::string>>>(int32_t) > ("AP_GetBlacklist_Async");
  m_method_AP_ClearBlacklist = this->create_method<int32_t(int32_t)>("AP_ClearBlacklist");
  m_method_AP_ClearBlacklist_Async = this->create_method<int32_t(int32_t)>("AP_ClearBlacklist_Async");
  m_method_Get_ModemList = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector < std::tuple
      < int32_t, int32_t, std::string, std::string, std::string, std::string, std::string, std::string, std::string, int32_t, bool,
      std::vector < std::string >>>>>() > ("Get_ModemList");
  m_method_Get_ModemList_Async = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector
      < std::tuple
      < int32_t, int32_t, std::string, std::string, std::string, std::string, std::string, std::string, std::string, int32_t, bool,
      std::vector < std::string >>>>>() > ("Get_ModemList_Async");
  m_method_Get_ModemParams = this->create_method < DBus::MultipleReturn < int32_t, std::tuple
      < int32_t, int32_t, std::string, std::string, std::string, std::string, std::string, std::string, std::string, int32_t, bool,
      std::vector < std::string>>>(int32_t) > ("Get_ModemParams");
  m_method_Get_ModemParams_Async = this->create_method < DBus::MultipleReturn < int32_t, std::tuple
      < int32_t, int32_t, std::string, std::string, std::string, std::string, std::string, std::string, std::string, int32_t, bool,
      std::vector < std::string>>>(int32_t) > ("Get_ModemParams_Async");
  m_method_Set_ModemParams = this->create_method<int32_t(int32_t,
                                                         std::tuple < std::string,
                                                         std::string,
                                                         std::string,
                                                         std::string,
                                                         std::string > ,
                                                         int32_t)>("Set_ModemParams");
  m_method_Set_ModemParams_Async = this->create_method<int32_t(int32_t,
                                                               std::tuple < std::string,
                                                               std::string,
                                                               std::string,
                                                               std::string,
                                                               std::string > ,
                                                               int32_t)>("Set_ModemParams_Async");
  m_method_AddModem =
      this->create_method<int32_t(std::string, std::string, std::tuple < std::vector < std::string >> )>("AddModem");
  m_method_RemoveModem = this->create_method<int32_t(std::string, std::string)>("RemoveModem");
  m_method_Debug_ModemDump = this->create_method<int32_t()>("Debug_ModemDump");
  m_signalproxy_ConnectResult = this->create_signal<void(int32_t, int32_t, int32_t)>("ConnectResult");
  m_signalproxy_InterfaceArrive = this->create_signal<void(int32_t)>("InterfaceArrive");
  m_signalproxy_InterfaceDeparture = this->create_signal<void(int32_t)>("InterfaceDeparture");
  m_signalproxy_InterfaceChanged = this->create_signal<void(int32_t, int32_t)>("InterfaceChanged");
  m_signalproxy_InterfaceConnecting = this->create_signal<void(int32_t)>("InterfaceConnecting");
  m_signalproxy_InterfaceDisconnecting = this->create_signal<void(int32_t)>("InterfaceDisconnecting");
  m_signalproxy_InterfaceConnected = this->create_signal<void(int32_t)>("InterfaceConnected");
  m_signalproxy_InterfaceDisconnected = this->create_signal<void(int32_t, int32_t)>("InterfaceDisconnected");
  m_signalproxy_WIFI_ScanResultsReady = this->create_signal<void(int32_t)>("WIFI_ScanResultsReady");
  m_signalproxy_InterfaceWiFiModeChanged = this->create_signal<void(int32_t, int32_t)>("InterfaceWiFiModeChanged");
  m_signalproxy_WIFI_ApClientConnected = this->create_signal<void(int32_t, std::string)>("WIFI_ApClientConnected");
  m_signalproxy_WIFI_ApClientDisconnected =
      this->create_signal<void(int32_t, std::string)>("WIFI_ApClientDisconnected");
  m_signalproxy_ConnectionStateChanged = this->create_signal<void(int32_t)>("ConnectionStateChanged");
  m_signalproxy_WifiStatus =
      this->create_signal<void(std::tuple < int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t > )>("WifiStatus");
  m_signalproxy_BLMStatus = this->create_signal<void(std::tuple < int32_t > )>("BLMStatus");
  m_signalproxy_ConnectionStatus =
      this->create_signal<void(std::tuple < int32_t, int32_t, int32_t, uint64_t, uint64_t > )>("ConnectionStatus");

}
std::shared_ptr <com_jci_blm_nmsProxy> com_jci_blm_nmsProxy::create(std::string name) {
  return std::shared_ptr<com_jci_blm_nmsProxy>(new com_jci_blm_nmsProxy(name));

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_blm_nmsProxy::GetConnectionState() {
  return (*m_method_GetConnectionState)();

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_blm_nmsProxy::GetConnectionState_Async() {
  return (*m_method_GetConnectionState_Async)();

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_blm_nmsProxy::Connect(int32_t ifcId) {
  return (*m_method_Connect)(ifcId);

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_blm_nmsProxy::Connect_Async(int32_t ifcId) {
  return (*m_method_Connect_Async)(ifcId);

}
int32_t com_jci_blm_nmsProxy::Disconnect(int32_t ifcId) {
  return (*m_method_Disconnect)(ifcId);

}
int32_t com_jci_blm_nmsProxy::Disconnect_Async(int32_t ifcId) {
  return (*m_method_Disconnect_Async)(ifcId);

}
int32_t com_jci_blm_nmsProxy::Abort(int32_t reqId) {
  return (*m_method_Abort)(reqId);

}
int32_t com_jci_blm_nmsProxy::Abort_Async(int32_t reqId) {
  return (*m_method_Abort_Async)(reqId);

}
int32_t com_jci_blm_nmsProxy::SetWiFiAutoconnect(bool state) {
  return (*m_method_SetWiFiAutoconnect)(state);

}
int32_t com_jci_blm_nmsProxy::SetWiFiAutoconnect_Async(bool state) {
  return (*m_method_SetWiFiAutoconnect_Async)(state);

}
DBus::MultipleReturn<int32_t, bool> com_jci_blm_nmsProxy::GetWiFiAutoconnect() {
  return (*m_method_GetWiFiAutoconnect)();

}
DBus::MultipleReturn<int32_t, bool> com_jci_blm_nmsProxy::GetWiFiAutoconnect_Async() {
  return (*m_method_GetWiFiAutoconnect_Async)();

}
int32_t com_jci_blm_nmsProxy::SetModemAutoconnect(bool state) {
  return (*m_method_SetModemAutoconnect)(state);

}
int32_t com_jci_blm_nmsProxy::SetModemAutoconnect_Async(bool state) {
  return (*m_method_SetModemAutoconnect_Async)(state);

}
DBus::MultipleReturn<int32_t, bool> com_jci_blm_nmsProxy::GetModemAutoconnect() {
  return (*m_method_GetModemAutoconnect)();

}
DBus::MultipleReturn<int32_t, bool> com_jci_blm_nmsProxy::GetModemAutoconnect_Async() {
  return (*m_method_GetModemAutoconnect_Async)();

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < int32_t>>>
com_jci_blm_nmsProxy::GetInterfaceList() {
  return (*m_method_GetInterfaceList)();

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < int32_t>>>
com_jci_blm_nmsProxy::GetInterfaceList_Async() {
  return (*m_method_GetInterfaceList_Async)();

}
DBus::MultipleReturn <int32_t, std::tuple<int32_t,
                                          int32_t,
                                          std::string,
                                          std::string,
                                          std::string,
                                          std::string,
                                          std::string,
                                          std::string,
                                          std::string,
                                          std::string,
                                          int32_t,
                                          int32_t,
                                          int32_t,
                                          int32_t>> com_jci_blm_nmsProxy::GetInterfaceParams(int32_t ifcId) {
  return (*m_method_GetInterfaceParams)(ifcId);

}
DBus::MultipleReturn <int32_t, std::tuple<int32_t,
                                          int32_t,
                                          std::string,
                                          std::string,
                                          std::string,
                                          std::string,
                                          std::string,
                                          std::string,
                                          std::string,
                                          std::string,
                                          int32_t,
                                          int32_t,
                                          int32_t,
                                          int32_t>> com_jci_blm_nmsProxy::GetInterfaceParams_Async(int32_t ifcId) {
  return (*m_method_GetInterfaceParams_Async)(ifcId);

}
int32_t com_jci_blm_nmsProxy::SetInterfaceParams(int32_t ifcId,
                                                 std::tuple <std::string, std::string, std::string, std::string, std::string, std::string, int32_t, int32_t> ifcParams,
                                                 int32_t setMask) {
  return (*m_method_SetInterfaceParams)(ifcId, ifcParams, setMask);

}
int32_t com_jci_blm_nmsProxy::SetInterfaceParams_Async(int32_t ifcId,
                                                       std::tuple <std::string, std::string, std::string, std::string, std::string, std::string, int32_t, int32_t> ifcParams,
                                                       int32_t setMask) {
  return (*m_method_SetInterfaceParams_Async)(ifcId, ifcParams, setMask);

}
int32_t com_jci_blm_nmsProxy::DHCP_ServerSetConfig(int32_t ifcId, std::tuple <std::string, std::string> dhcpConf) {
  return (*m_method_DHCP_ServerSetConfig)(ifcId, dhcpConf);

}
int32_t com_jci_blm_nmsProxy::DHCP_ServerSetConfig_Async(int32_t ifcId,
                                                         std::tuple <std::string, std::string> dhcpConf) {
  return (*m_method_DHCP_ServerSetConfig_Async)(ifcId, dhcpConf);

}
DBus::MultipleReturn <int32_t, std::tuple<std::string,
                                          std::string>> com_jci_blm_nmsProxy::DHCP_ServerGetConfig(int32_t ifcId) {
  return (*m_method_DHCP_ServerGetConfig)(ifcId);

}
DBus::MultipleReturn <int32_t, std::tuple<std::string, std::string>> com_jci_blm_nmsProxy::DHCP_ServerGetConfig_Async(
    int32_t ifcId) {
  return (*m_method_DHCP_ServerGetConfig_Async)(ifcId);

}
int32_t com_jci_blm_nmsProxy::DHCP_ServerStart(int32_t ifcId) {
  return (*m_method_DHCP_ServerStart)(ifcId);

}
int32_t com_jci_blm_nmsProxy::DHCP_ServerStart_Async(int32_t ifcId) {
  return (*m_method_DHCP_ServerStart_Async)(ifcId);

}
int32_t com_jci_blm_nmsProxy::DHCP_ServerStop(int32_t ifcId) {
  return (*m_method_DHCP_ServerStop)(ifcId);

}
int32_t com_jci_blm_nmsProxy::DHCP_ServerStop_Async(int32_t ifcId) {
  return (*m_method_DHCP_ServerStop_Async)(ifcId);

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < std::tuple < std::string,
                                          std::string,
                                          std::string,
                                          std::string>>>>
com_jci_blm_nmsProxy::DHCP_ServerGetClients(int32_t
ifcId ){
return (*m_method_DHCP_ServerGetClients)(ifcId);

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < std::tuple < std::string,
                                          std::string,
                                          std::string,
                                          std::string>>>>
com_jci_blm_nmsProxy::DHCP_ServerGetClients_Async(int32_t
ifcId ){
return (*m_method_DHCP_ServerGetClients_Async)(ifcId);

}
int32_t com_jci_blm_nmsProxy::ActivateNAT(bool enable) {
  return (*m_method_ActivateNAT)(enable);

}
int32_t com_jci_blm_nmsProxy::ActivateNAT_Async(bool enable) {
  return (*m_method_ActivateNAT_Async)(enable);

}
int32_t com_jci_blm_nmsProxy::AdvancedRouting(bool enable) {
  return (*m_method_AdvancedRouting)(enable);

}
int32_t com_jci_blm_nmsProxy::AdvancedRouting_Async(bool enable) {
  return (*m_method_AdvancedRouting_Async)(enable);

}
int32_t com_jci_blm_nmsProxy::SetHostname(std::string hostname) {
  return (*m_method_SetHostname)(hostname);

}
int32_t com_jci_blm_nmsProxy::SetHostname_Async(std::string hostname) {
  return (*m_method_SetHostname_Async)(hostname);

}
DBus::MultipleReturn <int32_t, std::string> com_jci_blm_nmsProxy::GetHostname() {
  return (*m_method_GetHostname)();

}
DBus::MultipleReturn <int32_t, std::string> com_jci_blm_nmsProxy::GetHostname_Async() {
  return (*m_method_GetHostname_Async)();

}
int32_t com_jci_blm_nmsProxy::MonitorInterface(int32_t
ifcId,
bool turn
){
return (*m_method_MonitorInterface)(ifcId,turn);

}
int32_t com_jci_blm_nmsProxy::MonitorInterface_Async(int32_t
ifcId,
bool turn
){
return (*m_method_MonitorInterface_Async)(ifcId,turn);

}
int32_t com_jci_blm_nmsProxy::WIFI_SetMode(int32_t
ifcId,
int32_t mode
){
return (*m_method_WIFI_SetMode)(ifcId,mode);

}
int32_t com_jci_blm_nmsProxy::WIFI_SetMode_Async(int32_t
ifcId,
int32_t mode
){
return (*m_method_WIFI_SetMode_Async)(ifcId,mode);

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_blm_nmsProxy::WIFI_GetMode(int32_t
ifcId ){
return (*m_method_WIFI_GetMode)(ifcId);

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_blm_nmsProxy::WIFI_GetMode_Async(int32_t
ifcId ){
return (*m_method_WIFI_GetMode_Async)(ifcId);

}
int32_t com_jci_blm_nmsProxy::WIFI_SelectNetwork(int32_t
ifcId,
int32_t networkId
){
return (*m_method_WIFI_SelectNetwork)(ifcId,networkId);

}
int32_t com_jci_blm_nmsProxy::WIFI_SelectNetwork_Async(int32_t
ifcId,
int32_t networkId
){
return (*m_method_WIFI_SelectNetwork_Async)(ifcId,networkId);

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_blm_nmsProxy::WIFI_GetSelectNetwork(int32_t
ifcId ){
return (*m_method_WIFI_GetSelectNetwork)(ifcId);

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_blm_nmsProxy::WIFI_GetSelectNetwork_Async(int32_t
ifcId ){
return (*m_method_WIFI_GetSelectNetwork_Async)(ifcId);

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_blm_nmsProxy::WIFI_AddNetwork(int32_t
ifcId,
std::tuple<std::string, std::string, int32_t, bool, std::string> network
){
return (*m_method_WIFI_AddNetwork)(ifcId,network);

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_blm_nmsProxy::WIFI_AddNetwork_Async(int32_t
ifcId,
std::tuple<std::string, std::string, int32_t, bool, std::string> network
){
return (*m_method_WIFI_AddNetwork_Async)(ifcId,network);

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_blm_nmsProxy::WIFI_AddNetwork_Ex(int32_t
ifcId,
Invalid network
){
return (*m_method_WIFI_AddNetwork_Ex)(ifcId,network);

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_blm_nmsProxy::WIFI_AddNetwork_Ex_Async(int32_t
ifcId,
Invalid network
){
return (*m_method_WIFI_AddNetwork_Ex_Async)(ifcId,network);

}
int32_t com_jci_blm_nmsProxy::WIFI_RemoveConfiguredNetwork(int32_t
ifcId,
int32_t networkId
){
return (*m_method_WIFI_RemoveConfiguredNetwork)(ifcId,networkId);

}
int32_t com_jci_blm_nmsProxy::WIFI_RemoveConfiguredNetwork_Async(int32_t
ifcId,
int32_t networkId
){
return (*m_method_WIFI_RemoveConfiguredNetwork_Async)(ifcId,networkId);

}
int32_t com_jci_blm_nmsProxy::WIFI_UpdateNetworkPass(int32_t
ifcId,
uint32_t networkId, std::string
password ){
return (*m_method_WIFI_UpdateNetworkPass)(ifcId,networkId,password);

}
int32_t com_jci_blm_nmsProxy::WIFI_UpdateNetworkPass_Async(int32_t
ifcId,
uint32_t networkId, std::string
password ){
return (*m_method_WIFI_UpdateNetworkPass_Async)(ifcId,networkId,password);

}
int32_t com_jci_blm_nmsProxy::WIFI_UpdateConfiguredNetwork(int32_t
ifcId,
int32_t networkId, Invalid
network ){
return (*m_method_WIFI_UpdateConfiguredNetwork)(ifcId,networkId,network);

}
int32_t com_jci_blm_nmsProxy::WIFI_UpdateNetwork_Async(int32_t
ifcId,
int32_t networkId, Invalid
network ){
return (*m_method_WIFI_UpdateNetwork_Async)(ifcId,networkId,network);

}
int32_t com_jci_blm_nmsProxy::WIFI_SaveConfiguredNetworks(int32_t
ifcId ){
return (*m_method_WIFI_SaveConfiguredNetworks)(ifcId);

}
int32_t com_jci_blm_nmsProxy::WIFI_SaveConfiguredNetworks_Async(int32_t
ifcId ){
return (*m_method_WIFI_SaveConfiguredNetworks_Async)(ifcId);

}
int32_t com_jci_blm_nmsProxy::WIFI_StartScan(int32_t
ifcId,
int32_t refreshTime
){
return (*m_method_WIFI_StartScan)(ifcId,refreshTime);

}
int32_t com_jci_blm_nmsProxy::WIFI_StartScan_Async(int32_t
ifcId,
int32_t refreshTime
){
return (*m_method_WIFI_StartScan_Async)(ifcId,refreshTime);

}
int32_t com_jci_blm_nmsProxy::WIFI_StopScan(int32_t
ifcId ){
return (*m_method_WIFI_StopScan)(ifcId);

}
int32_t com_jci_blm_nmsProxy::WIFI_StopScan_Async(int32_t
ifcId ){
return (*m_method_WIFI_StopScan_Async)(ifcId);

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < std::tuple < std::string,
                                          std::string,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          int32_t>>>>
com_jci_blm_nmsProxy::WIFI_GetScanResults(int32_t
ifcId ){
return (*m_method_WIFI_GetScanResults)(ifcId);

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < std::tuple < std::string,
                                          std::string,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          int32_t>>>>
com_jci_blm_nmsProxy::WIFI_GetScanResults_Async(int32_t
ifcId ){
return (*m_method_WIFI_GetScanResults_Async)(ifcId);

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < std::tuple < uint32_t,
                                          std::string,
                                          std::string,
                                          int32_t,
                                          bool,
                                          std::string,
                                          int32_t>>>>
com_jci_blm_nmsProxy::WIFI_GetConfiguredNetworks(int32_t
ifcId ){
return (*m_method_WIFI_GetConfiguredNetworks)(ifcId);

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < std::tuple < uint32_t,
                                          std::string,
                                          std::string,
                                          int32_t,
                                          bool,
                                          std::string,
                                          int32_t>>>>
com_jci_blm_nmsProxy::WIFI_GetConfiguredNetworks_Async(int32_t
ifcId ){
return (*m_method_WIFI_GetConfiguredNetworks_Async)(ifcId);

}
DBus::MultipleReturn <int32_t, Invalid> com_jci_blm_nmsProxy::WIFI_GetConfiguredNetworks_Ex(int32_t
ifcId ){
return (*m_method_WIFI_GetConfiguredNetworks_Ex)(ifcId);

}
DBus::MultipleReturn <int32_t, Invalid> com_jci_blm_nmsProxy::WIFI_GetConfiguredNetworks_Ex_Async(int32_t
ifcId ){
return (*m_method_WIFI_GetConfiguredNetworks_Ex_Async)(ifcId);

}
DBus::MultipleReturn <int32_t, int32_t, int32_t> com_jci_blm_nmsProxy::WIFI_GetNetCount(int32_t
ifcId ){
return (*m_method_WIFI_GetNetCount)(ifcId);

}
DBus::MultipleReturn <int32_t, int32_t, int32_t> com_jci_blm_nmsProxy::WIFI_GetNetCount_Async(int32_t
ifcId ){
return (*m_method_WIFI_GetNetCount_Async)(ifcId);

}
DBus::MultipleReturn <int32_t, std::tuple<uint32_t,
                                          std::tuple < std::string,
                                          std::string,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          int32_t>>>
com_jci_blm_nmsProxy::WIFI_GetConnectionInfo(int32_t
ifcId ){
return (*m_method_WIFI_GetConnectionInfo)(ifcId);

}
DBus::MultipleReturn <int32_t, std::tuple<uint32_t,
                                          std::tuple < std::string,
                                          std::string,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          int32_t>>>
com_jci_blm_nmsProxy::WIFI_GetConnectionInfo_Async(int32_t
ifcId ){
return (*m_method_WIFI_GetConnectionInfo_Async)(ifcId);

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < std::tuple < uint32_t,
                                          std::string,
                                          std::string,
                                          int32_t,
                                          int32_t,
                                          int32_t,
                                          int32_t>>>>
com_jci_blm_nmsProxy::WIFI_GetCombinedNetworksList(int32_t
ifcId ){
return (*m_method_WIFI_GetCombinedNetworksList)(ifcId);

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < std::tuple < uint32_t,
                                          std::string,
                                          std::string,
                                          int32_t,
                                          int32_t,
                                          int32_t,
                                          int32_t>>>>
com_jci_blm_nmsProxy::WIFI_GetCombinedNetworksList_Async(int32_t
ifcId ){
return (*m_method_WIFI_GetCombinedNetworksList_Async)(ifcId);

}
int32_t com_jci_blm_nmsProxy::AP_SelectConfiguration(int32_t
secType ){
return (*m_method_AP_SelectConfiguration)(secType);

}
int32_t com_jci_blm_nmsProxy::AP_SelectConfiguration_Async(int32_t
secType ){
return (*m_method_AP_SelectConfiguration_Async)(secType);

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_blm_nmsProxy::AP_GetSelectedConfiguration() {
  return (*m_method_AP_GetSelectedConfiguration)();

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_blm_nmsProxy::AP_GetSelectedConfiguration_Async() {
  return (*m_method_AP_GetSelectedConfiguration_Async)();

}
int32_t com_jci_blm_nmsProxy::AP_SetHostConfig(std::tuple<std::string, std::string, int32_t, bool> config) {
  return (*m_method_AP_SetHostConfig)(config);

}
int32_t com_jci_blm_nmsProxy::AP_SetHostConfig_Async(std::tuple<std::string, std::string, int32_t, bool> config) {
  return (*m_method_AP_SetHostConfig_Async)(config);

}
DBus::MultipleReturn <int32_t, std::tuple<std::string, std::string, int32_t, bool>>
    com_jci_blm_nmsProxy::AP_GetHostConfig(int32_t
secSettings ){
return (*m_method_AP_GetHostConfig)(secSettings);

}
DBus::MultipleReturn <int32_t, std::tuple<std::string, std::string, int32_t, bool>>
    com_jci_blm_nmsProxy::AP_GetHostConfig_Async(int32_t
secSettings ){
return (*m_method_AP_GetHostConfig_Async)(secSettings);

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < std::tuple < std::string,
                                          std::string,
                                          std::string,
                                          std::string>>>>
com_jci_blm_nmsProxy::AP_GetClients(int32_t
ifcId ){
return (*m_method_AP_GetClients)(ifcId);

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < std::tuple < std::string,
                                          std::string,
                                          std::string,
                                          std::string>>>>
com_jci_blm_nmsProxy::AP_GetClients_Async(int32_t
ifcId ){
return (*m_method_AP_GetClients_Async)(ifcId);

}
int32_t com_jci_blm_nmsProxy::AP_AddToBlacklist(int32_t
ifcId,
std::string mac
){
return (*m_method_AP_AddToBlacklist)(ifcId,mac);

}
int32_t com_jci_blm_nmsProxy::AP_AddToBlacklist_Async(int32_t
ifcId,
std::string mac
){
return (*m_method_AP_AddToBlacklist_Async)(ifcId,mac);

}
int32_t com_jci_blm_nmsProxy::AP_RemoveFromBlacklist(int32_t
ifcId,
std::string mac
){
return (*m_method_AP_RemoveFromBlacklist)(ifcId,mac);

}
int32_t com_jci_blm_nmsProxy::AP_RemoveFromBlacklist_Async(int32_t
ifcId,
std::string mac
){
return (*m_method_AP_RemoveFromBlacklist_Async)(ifcId,mac);

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < std::string>>>
com_jci_blm_nmsProxy::AP_GetBlacklist(int32_t
ifcId ){
return (*m_method_AP_GetBlacklist)(ifcId);

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < std::string>>>
com_jci_blm_nmsProxy::AP_GetBlacklist_Async(int32_t
ifcId ){
return (*m_method_AP_GetBlacklist_Async)(ifcId);

}
int32_t com_jci_blm_nmsProxy::AP_ClearBlacklist(int32_t
ifcId ){
return (*m_method_AP_ClearBlacklist)(ifcId);

}
int32_t com_jci_blm_nmsProxy::AP_ClearBlacklist_Async(int32_t
ifcId ){
return (*m_method_AP_ClearBlacklist_Async)(ifcId);

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < std::tuple < int32_t,
                                          int32_t,
                                          std::string,
                                          std::string,
                                          std::string,
                                          std::string,
                                          std::string,
                                          std::string,
                                          std::string,
                                          int32_t,
                                          bool,
                                          std::vector < std::string>>>>>
com_jci_blm_nmsProxy::Get_ModemList() {
  return (*m_method_Get_ModemList)();

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < std::tuple < int32_t,
                                          int32_t,
                                          std::string,
                                          std::string,
                                          std::string,
                                          std::string,
                                          std::string,
                                          std::string,
                                          std::string,
                                          int32_t,
                                          bool,
                                          std::vector < std::string>>>>>
com_jci_blm_nmsProxy::Get_ModemList_Async() {
  return (*m_method_Get_ModemList_Async)();

}
DBus::MultipleReturn <int32_t, std::tuple<int32_t,
                                          int32_t,
                                          std::string,
                                          std::string,
                                          std::string,
                                          std::string,
                                          std::string,
                                          std::string,
                                          std::string,
                                          int32_t,
                                          bool,
                                          std::vector < std::string>>>
com_jci_blm_nmsProxy::Get_ModemParams(int32_t
mId ){
return (*m_method_Get_ModemParams)(mId);

}
DBus::MultipleReturn <int32_t, std::tuple<int32_t,
                                          int32_t,
                                          std::string,
                                          std::string,
                                          std::string,
                                          std::string,
                                          std::string,
                                          std::string,
                                          std::string,
                                          int32_t,
                                          bool,
                                          std::vector < std::string>>>
com_jci_blm_nmsProxy::Get_ModemParams_Async(int32_t
mId ){
return (*m_method_Get_ModemParams_Async)(mId);

}
int32_t com_jci_blm_nmsProxy::Set_ModemParams(int32_t
mId,
std::tuple <std::string, std::string, std::string, std::string, std::string> params, int32_t
updateMask ){
return (*m_method_Set_ModemParams)(mId,params,updateMask);

}
int32_t com_jci_blm_nmsProxy::Set_ModemParams_Async(int32_t
mId,
std::tuple <std::string, std::string, std::string, std::string, std::string> params, int32_t
updateMask ){
return (*m_method_Set_ModemParams_Async)(mId,params,updateMask);

}
int32_t com_jci_blm_nmsProxy::AddModem(std::string modemId,
                                       std::string vendor,
                                       std::tuple <std::vector<std::string>> ports) {
  return (*m_method_AddModem)(modemId, vendor, ports);

}
int32_t com_jci_blm_nmsProxy::RemoveModem(std::string modemId, std::string vendor) {
  return (*m_method_RemoveModem)(modemId, vendor);

}
int32_t com_jci_blm_nmsProxy::Debug_ModemDump() {
  return (*m_method_Debug_ModemDump)();

}
std::shared_ptr <DBus::SignalProxy<void(int32_t, int32_t, int32_t)>> com_jci_blm_nmsProxy::signal_ConnectResult() {
  return m_signalproxy_ConnectResult;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_blm_nmsProxy::signal_InterfaceArrive() {
  return m_signalproxy_InterfaceArrive;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_blm_nmsProxy::signal_InterfaceDeparture() {
  return m_signalproxy_InterfaceDeparture;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t, int32_t)>> com_jci_blm_nmsProxy::signal_InterfaceChanged() {
  return m_signalproxy_InterfaceChanged;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_blm_nmsProxy::signal_InterfaceConnecting() {
  return m_signalproxy_InterfaceConnecting;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_blm_nmsProxy::signal_InterfaceDisconnecting() {
  return m_signalproxy_InterfaceDisconnecting;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_blm_nmsProxy::signal_InterfaceConnected() {
  return m_signalproxy_InterfaceConnected;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t, int32_t)>> com_jci_blm_nmsProxy::signal_InterfaceDisconnected() {
  return m_signalproxy_InterfaceDisconnected;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_blm_nmsProxy::signal_WIFI_ScanResultsReady() {
  return m_signalproxy_WIFI_ScanResultsReady;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t, int32_t)>> com_jci_blm_nmsProxy::signal_InterfaceWiFiModeChanged() {
  return m_signalproxy_InterfaceWiFiModeChanged;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t, std::string)>> com_jci_blm_nmsProxy::signal_WIFI_ApClientConnected() {
  return m_signalproxy_WIFI_ApClientConnected;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t,
                                        std::string)>> com_jci_blm_nmsProxy::signal_WIFI_ApClientDisconnected() {
  return m_signalproxy_WIFI_ApClientDisconnected;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_blm_nmsProxy::signal_ConnectionStateChanged() {
  return m_signalproxy_ConnectionStateChanged;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < int32_t,
                                        int32_t,
                                        int32_t,
                                        int32_t,
                                        int32_t,
                                        uint32_t > )>> com_jci_blm_nmsProxy::signal_WifiStatus() {
  return m_signalproxy_WifiStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < int32_t > )>> com_jci_blm_nmsProxy::signal_BLMStatus() {
  return m_signalproxy_BLMStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < int32_t,
                                        int32_t,
                                        int32_t,
                                        uint64_t,
                                        uint64_t > )>> com_jci_blm_nmsProxy::signal_ConnectionStatus() {
  return m_signalproxy_ConnectionStatus;

}
