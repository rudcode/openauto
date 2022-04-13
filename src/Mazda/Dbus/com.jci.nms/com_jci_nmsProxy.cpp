#include "com_jci_nmsProxy.h"

com_jci_nmsProxy::com_jci_nmsProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_GetInterfaceList = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector
      < int32_t>>>() > ("GetInterfaceList");
  m_method_GetInterfaceList_Async = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector
      < int32_t>>>() > ("GetInterfaceList_Async");
  m_method_Connect = this->create_method<DBus::MultipleReturn<int32_t, int32_t>(int32_t)>("Connect");
  m_method_Connect_Async = this->create_method<DBus::MultipleReturn<int32_t, int32_t>(int32_t)>("Connect_Async");
  m_method_Disconnect = this->create_method<int32_t(int32_t)>("Disconnect");
  m_method_Disconnect_Async = this->create_method<int32_t(int32_t)>("Disconnect_Async");
  m_method_Abort = this->create_method<int32_t(int32_t)>("Abort");
  m_method_Abort_Async = this->create_method<int32_t(int32_t)>("Abort_Async");
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
  m_method_WIFI_AddNetwork =
      this->create_method<DBus::MultipleReturn<int32_t, int32_t>(int32_t, Invalid)>("WIFI_AddNetwork");
  m_method_WIFI_AddNetwork_Async =
      this->create_method<DBus::MultipleReturn<int32_t, int32_t>(int32_t, Invalid)>("WIFI_AddNetwork_Async");
  m_method_WIFI_RemoveConfiguredNetwork =
      this->create_method<int32_t(int32_t, int32_t)>("WIFI_RemoveConfiguredNetwork");
  m_method_WIFI_RemoveConfiguredNetwork_Async =
      this->create_method<int32_t(int32_t, int32_t)>("WIFI_RemoveConfiguredNetwork_Async");
  m_method_WIFI_UpdateConfiguredNetwork =
      this->create_method<int32_t(int32_t, Invalid)>("WIFI_UpdateConfiguredNetwork");
  m_method_WIFI_UpdateConfiguredNetwork_Async =
      this->create_method<int32_t(int32_t, Invalid)>("WIFI_UpdateConfiguredNetwork_Async");
  m_method_WIFI_StartScan = this->create_method<int32_t(int32_t, int32_t)>("WIFI_StartScan");
  m_method_WIFI_StartScan_Async = this->create_method<int32_t(int32_t, int32_t)>("WIFI_StartScan_Async");
  m_method_WIFI_StopScan = this->create_method<int32_t(int32_t)>("WIFI_StopScan");
  m_method_WIFI_StopScan_Async = this->create_method<int32_t(int32_t)>("WIFI_StopScan_Async");
  m_method_WIFI_GetConfiguredNetworks =
      this->create_method<DBus::MultipleReturn<int32_t, Invalid>(int32_t)>("WIFI_GetConfiguredNetworks");
  m_method_WIFI_GetConfiguredNetworks_Async =
      this->create_method<DBus::MultipleReturn<int32_t, Invalid>(int32_t)>("WIFI_GetConfiguredNetworks_Async");
  m_method_WIFI_GetScanResults = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector
      < std::tuple < std::string, std::string, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t,
      std::tuple < int32_t, int32_t, int32_t, int32_t, int32_t >>>>>(int32_t) > ("WIFI_GetScanResults");
  m_method_WIFI_GetScanResults_Async = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector
      < std::tuple < std::string, std::string, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t,
      std::tuple < int32_t, int32_t, int32_t, int32_t, int32_t >>>>>(int32_t) > ("WIFI_GetScanResults_Async");
  m_method_WIFI_GetConnectionInfo = this->create_method < DBus::MultipleReturn < int32_t, std::tuple
      < uint32_t, int32_t, std::tuple
      < std::string, std::string, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, std::tuple
      < int32_t, int32_t, int32_t, int32_t, int32_t >> >> (int32_t) > ("WIFI_GetConnectionInfo");
  m_method_WIFI_GetConnectionInfo_Async = this->create_method < DBus::MultipleReturn < int32_t, std::tuple
      < uint32_t, int32_t, std::tuple
      < std::string, std::string, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, std::tuple
      < int32_t, int32_t, int32_t, int32_t, int32_t >> >> (int32_t) > ("WIFI_GetConnectionInfo_Async");
  m_method_WIFI_SaveConfiguredNetworks = this->create_method<int32_t(int32_t)>("WIFI_SaveConfiguredNetworks");
  m_method_WIFI_SaveConfiguredNetworks_Async =
      this->create_method<int32_t(int32_t)>("WIFI_SaveConfiguredNetworks_Async");
  m_method_AP_SelectProfile = this->create_method<int32_t(int32_t)>("AP_SelectProfile");
  m_method_AP_SelectProfile_Async = this->create_method<int32_t(int32_t)>("AP_SelectProfile_Async");
  m_method_AP_GetInfo = this->create_method<int32_t(int32_t)>("AP_GetInfo");
  m_method_AP_GetInfo_Async = this->create_method<int32_t(int32_t)>("AP_GetInfo_Async");
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
  m_method_MonitorInterface = this->create_method<int32_t(int32_t, bool)>("MonitorInterface");
  m_method_MonitorInterface_Async = this->create_method<int32_t(int32_t, bool)>("MonitorInterface_Async");
  m_method_SOCKET_NewConnection =
      this->create_method<int32_t(std::tuple < int32_t, std::string, int32_t, int32_t > )>("SOCKET_NewConnection");
  m_method_SOCKET_NewConnection_Async = this->create_method<int32_t(std::tuple < int32_t,
                                                                    std::string,
                                                                    int32_t,
                                                                    int32_t > )>("SOCKET_NewConnection_Async");
  m_method_AdvancedRouting = this->create_method<int32_t(int32_t)>("AdvancedRouting");
  m_method_AdvancedRouting_Async = this->create_method<int32_t(int32_t)>("AdvancedRouting_Async");
  m_method_ActivateNAT = this->create_method<int32_t(int32_t)>("ActivateNAT");
  m_method_ActivateNAT_Async = this->create_method<int32_t(int32_t)>("ActivateNAT_Async");
  m_method_DHCP_ServerGetClients = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector
      < std::tuple < std::string, std::string, std::string, std::string >> >> (int32_t) > ("DHCP_ServerGetClients");
  m_method_DHCP_ServerGetClients_Async = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector
      < std::tuple < std::string, std::string, std::string, std::string >> >> (int32_t)
      > ("DHCP_ServerGetClients_Async");
  m_method_SetHostname = this->create_method<int32_t(std::string)>("SetHostname");
  m_method_SetHostname_Async = this->create_method<int32_t(std::string)>("SetHostname_Async");
  m_method_GetHostname = this->create_method<DBus::MultipleReturn<std::string, int32_t>()>("GetHostname");
  m_method_GetHostname_Async = this->create_method<DBus::MultipleReturn<std::string, int32_t>()>("GetHostname_Async");
  m_method_AP_GetClients = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector < std::tuple
      < std::string, std::string, std::string, std::string >> >> (int32_t) > ("AP_GetClients");
  m_method_AP_GetClients_Async = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector
      < std::tuple < std::string, std::string, std::string, std::string >> >> (int32_t) > ("AP_GetClients_Async");
  m_method_AP_AddToBlacklist = this->create_method<int32_t(int32_t, std::string)>("AP_AddToBlacklist");
  m_method_AP_AddToBlacklist_Async = this->create_method<int32_t(int32_t, std::string)>("AP_AddToBlacklist_Async");
  m_method_AP_RemoveFromBlacklist = this->create_method<int32_t(int32_t, std::string)>("AP_RemoveFromBlacklist");
  m_method_AP_RemoveFromBlacklist_Async =
      this->create_method<int32_t(int32_t, std::string)>("AP_RemoveFromBlacklist_Async");
  m_method_AP_ClearBlacklist = this->create_method<int32_t(int32_t)>("AP_ClearBlacklist");
  m_method_AP_ClearBlacklist_Async = this->create_method<int32_t(int32_t)>("AP_ClearBlacklist_Async");
  m_method_AP_SetOpenProfile =
      this->create_method<int32_t(std::tuple < std::string, uint32_t, int32_t, int32_t > )>("AP_SetOpenProfile");
  m_method_AP_SetOpenProfile_Async =
      this->create_method<int32_t(std::tuple < std::string, uint32_t, int32_t, int32_t > )>("AP_SetOpenProfile_Async");
  m_method_AP_SetWepProfile = this->create_method<int32_t(Invalid)>("AP_SetWepProfile");
  m_method_AP_SetWepProfile_Async = this->create_method<int32_t(Invalid)>("AP_SetWepProfile_Async");
  m_method_AP_SetWpaProfile = this->create_method<int32_t(Invalid)>("AP_SetWpaProfile");
  m_method_AP_SetWpaProfile_Async = this->create_method<int32_t(Invalid)>("AP_SetWpaProfile_Async");
  m_method_AP_GetOpenProfile = this->create_method < DBus::MultipleReturn < std::tuple < std::string, uint32_t, int32_t,
      int32_t >, int32_t > () > ("AP_GetOpenProfile");
  m_method_AP_GetOpenProfile_Async =
      this->create_method < DBus::MultipleReturn < std::tuple < std::string, uint32_t, int32_t, int32_t >, int32_t > ()
      > ("AP_GetOpenProfile_Async");
  m_method_AP_GetWepProfile = this->create_method<DBus::MultipleReturn<Invalid, int32_t>()>("AP_GetWepProfile");
  m_method_AP_GetWepProfile_Async =
      this->create_method<DBus::MultipleReturn<Invalid, int32_t>()>("AP_GetWepProfile_Async");
  m_method_AP_GetWpaProfile = this->create_method<DBus::MultipleReturn<Invalid, int32_t>()>("AP_GetWpaProfile");
  m_method_AP_GetWpaProfile_Async =
      this->create_method<DBus::MultipleReturn<Invalid, int32_t>()>("AP_GetWpaProfile_Async");
  m_method_AP_GetSelectedProfile =
      this->create_method<DBus::MultipleReturn<int32_t, int32_t>()>("AP_GetSelectedProfile");
  m_method_AP_GetSelectedProfile_Async =
      this->create_method<DBus::MultipleReturn<int32_t, int32_t>()>("AP_GetSelectedProfile_Async");
  m_method_AP_SetHiddenNetwork = this->create_method<int32_t(int32_t)>("AP_SetHiddenNetwork");
  m_method_AP_SetHiddenNetwork_Async = this->create_method<int32_t(int32_t)>("AP_SetHiddenNetwork_Async");
  m_method_AP_GetHiddenNetwork = this->create_method<DBus::MultipleReturn<int32_t, int32_t>()>("AP_GetHiddenNetwork");
  m_method_AP_GetHiddenNetwork_Async =
      this->create_method<DBus::MultipleReturn<int32_t, int32_t>()>("AP_GetHiddenNetwork_Async");
  m_method_WIFI_GetScanResultsByMatch =
      this->create_method < DBus::MultipleReturn < std::tuple < std::vector < std::tuple
          < std::string, std::string, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, std::tuple
      < int32_t, int32_t, int32_t, int32_t, int32_t >> >>, int32_t > (int32_t, int32_t, std::string)
      > ("WIFI_GetScanResultsByMatch");
  m_method_WIFI_GetScanResultsByMatch_Async =
      this->create_method < DBus::MultipleReturn < std::tuple < std::vector < std::tuple
          < std::string, std::string, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, std::tuple
      < int32_t, int32_t, int32_t, int32_t, int32_t >> >>, int32_t > (int32_t, int32_t, std::string)
      > ("WIFI_GetScanResultsByMatch_Async");
  m_method_WIFI_EnableNetwork = this->create_method<int32_t(int32_t, int32_t)>("WIFI_EnableNetwork");
  m_method_WIFI_EnableNetwork_Async = this->create_method<int32_t(int32_t, int32_t)>("WIFI_EnableNetwork_Async");
  m_method_WIFI_DisableNetwork = this->create_method<int32_t(int32_t, int32_t)>("WIFI_DisableNetwork");
  m_method_WIFI_DisableNetwork_Async = this->create_method<int32_t(int32_t, int32_t)>("WIFI_DisableNetwork_Async");
  m_method_WIFI_MonitorStrength = this->create_method<int32_t(int32_t, bool, uint32_t)>("WIFI_MonitorStrength");
  m_method_WIFI_MonitorStrength_Async =
      this->create_method<int32_t(int32_t, bool, uint32_t)>("WIFI_MonitorStrength_Async");
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
  m_method_Debug_ListDump = this->create_method<void()>("Debug_ListDump");
  m_method_AP_GetBlacklist = this->create_method < DBus::MultipleReturn < int32_t, std::tuple < std::vector
      < std::string>>>(int32_t) > ("AP_GetBlacklist");
  m_signalproxy_InterfaceArrive = this->create_signal<void(int32_t)>("InterfaceArrive");
  m_signalproxy_InterfaceDeparture = this->create_signal<void(int32_t)>("InterfaceDeparture");
  m_signalproxy_InterfaceChanged = this->create_signal<void(int32_t, int32_t)>("InterfaceChanged");
  m_signalproxy_InterfaceConnecting = this->create_signal<void(int32_t)>("InterfaceConnecting");
  m_signalproxy_InterfaceDisconnecting = this->create_signal<void(int32_t)>("InterfaceDisconnecting");
  m_signalproxy_InterfaceConnected = this->create_signal<void(int32_t)>("InterfaceConnected");
  m_signalproxy_InterfaceDisconnected = this->create_signal<void(int32_t, int32_t)>("InterfaceDisconnected");
  m_signalproxy_WifiScanResultsReady = this->create_signal<void(int32_t)>("WifiScanResultsReady");
  m_signalproxy_ConnectResult = this->create_signal<void(int32_t, int32_t, int32_t)>("ConnectResult");
  m_signalproxy_InterfaceWiFiModeChanged = this->create_signal<void(int32_t, int32_t)>("InterfaceWiFiModeChanged");
  m_signalproxy_WiFiAPClientConnected = this->create_signal<void(int32_t, std::string)>("WiFiAPClientConnected");
  m_signalproxy_WiFiAPClientDisconnected = this->create_signal<void(int32_t, std::string)>("WiFiAPClientDisconnected");
  m_signalproxy_APOpenInfo =
      this->create_signal<void(int32_t, std::tuple < std::string, uint32_t, int32_t, int32_t > )>("APOpenInfo");
  m_signalproxy_APWepInfo = this->create_signal<void(int32_t, Invalid)>("APWepInfo");
  m_signalproxy_APWpaInfo = this->create_signal<void(int32_t, Invalid)>("APWpaInfo");
  m_signalproxy_InterfaceMonitorData =
      this->create_signal<void(int32_t, std::tuple < uint64_t, uint64_t > )>("InterfaceMonitorData");
  m_signalproxy_WifiSignalStrength = this->create_signal<void(int32_t, uint32_t)>("WifiSignalStrength");

}
std::shared_ptr <com_jci_nmsProxy> com_jci_nmsProxy::create(std::string name) {
  return std::shared_ptr<com_jci_nmsProxy>(new com_jci_nmsProxy(name));

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < int32_t>>>
com_jci_nmsProxy::GetInterfaceList() {
  return (*m_method_GetInterfaceList)();

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < int32_t>>>
com_jci_nmsProxy::GetInterfaceList_Async() {
  return (*m_method_GetInterfaceList_Async)();

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_nmsProxy::Connect(int32_t ifcId) {
  return (*m_method_Connect)(ifcId);

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_nmsProxy::Connect_Async(int32_t ifcId) {
  return (*m_method_Connect_Async)(ifcId);

}
int32_t com_jci_nmsProxy::Disconnect(int32_t ifcId) {
  return (*m_method_Disconnect)(ifcId);

}
int32_t com_jci_nmsProxy::Disconnect_Async(int32_t ifcId) {
  return (*m_method_Disconnect_Async)(ifcId);

}
int32_t com_jci_nmsProxy::Abort(int32_t reqId) {
  return (*m_method_Abort)(reqId);

}
int32_t com_jci_nmsProxy::Abort_Async(int32_t reqId) {
  return (*m_method_Abort_Async)(reqId);

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
                                          int32_t>> com_jci_nmsProxy::GetInterfaceParams(int32_t ifcId) {
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
                                          int32_t>> com_jci_nmsProxy::GetInterfaceParams_Async(int32_t ifcId) {
  return (*m_method_GetInterfaceParams_Async)(ifcId);

}
int32_t com_jci_nmsProxy::SetInterfaceParams(int32_t ifcId,
                                             std::tuple <std::string, std::string, std::string, std::string, std::string, std::string, int32_t, int32_t> ifcParams,
                                             int32_t setMask) {
  return (*m_method_SetInterfaceParams)(ifcId, ifcParams, setMask);

}
int32_t com_jci_nmsProxy::SetInterfaceParams_Async(int32_t ifcId,
                                                   std::tuple <std::string, std::string, std::string, std::string, std::string, std::string, int32_t, int32_t> ifcParams,
                                                   int32_t setMask) {
  return (*m_method_SetInterfaceParams_Async)(ifcId, ifcParams, setMask);

}
int32_t com_jci_nmsProxy::WIFI_SetMode(int32_t ifcId, int32_t mode) {
  return (*m_method_WIFI_SetMode)(ifcId, mode);

}
int32_t com_jci_nmsProxy::WIFI_SetMode_Async(int32_t ifcId, int32_t mode) {
  return (*m_method_WIFI_SetMode_Async)(ifcId, mode);

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_nmsProxy::WIFI_GetMode(int32_t ifcId) {
  return (*m_method_WIFI_GetMode)(ifcId);

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_nmsProxy::WIFI_GetMode_Async(int32_t ifcId) {
  return (*m_method_WIFI_GetMode_Async)(ifcId);

}
int32_t com_jci_nmsProxy::WIFI_SelectNetwork(int32_t ifcId, int32_t networkId) {
  return (*m_method_WIFI_SelectNetwork)(ifcId, networkId);

}
int32_t com_jci_nmsProxy::WIFI_SelectNetwork_Async(int32_t ifcId, int32_t networkId) {
  return (*m_method_WIFI_SelectNetwork_Async)(ifcId, networkId);

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_nmsProxy::WIFI_GetSelectNetwork(int32_t ifcId) {
  return (*m_method_WIFI_GetSelectNetwork)(ifcId);

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_nmsProxy::WIFI_GetSelectNetwork_Async(int32_t ifcId) {
  return (*m_method_WIFI_GetSelectNetwork_Async)(ifcId);

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_nmsProxy::WIFI_AddNetwork(int32_t ifcId, Invalid network) {
  return (*m_method_WIFI_AddNetwork)(ifcId, network);

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_nmsProxy::WIFI_AddNetwork_Async(int32_t ifcId, Invalid network) {
  return (*m_method_WIFI_AddNetwork_Async)(ifcId, network);

}
int32_t com_jci_nmsProxy::WIFI_RemoveConfiguredNetwork(int32_t ifcId, int32_t networkId) {
  return (*m_method_WIFI_RemoveConfiguredNetwork)(ifcId, networkId);

}
int32_t com_jci_nmsProxy::WIFI_RemoveConfiguredNetwork_Async(int32_t ifcId, int32_t networkId) {
  return (*m_method_WIFI_RemoveConfiguredNetwork_Async)(ifcId, networkId);

}
int32_t com_jci_nmsProxy::WIFI_UpdateConfiguredNetwork(int32_t ifcId, Invalid network) {
  return (*m_method_WIFI_UpdateConfiguredNetwork)(ifcId, network);

}
int32_t com_jci_nmsProxy::WIFI_UpdateConfiguredNetwork_Async(int32_t ifcId, Invalid network) {
  return (*m_method_WIFI_UpdateConfiguredNetwork_Async)(ifcId, network);

}
int32_t com_jci_nmsProxy::WIFI_StartScan(int32_t ifcId, int32_t refreshTime) {
  return (*m_method_WIFI_StartScan)(ifcId, refreshTime);

}
int32_t com_jci_nmsProxy::WIFI_StartScan_Async(int32_t ifcId, int32_t refreshTime) {
  return (*m_method_WIFI_StartScan_Async)(ifcId, refreshTime);

}
int32_t com_jci_nmsProxy::WIFI_StopScan(int32_t ifcId) {
  return (*m_method_WIFI_StopScan)(ifcId);

}
int32_t com_jci_nmsProxy::WIFI_StopScan_Async(int32_t ifcId) {
  return (*m_method_WIFI_StopScan_Async)(ifcId);

}
DBus::MultipleReturn <int32_t, Invalid> com_jci_nmsProxy::WIFI_GetConfiguredNetworks(int32_t ifcId) {
  return (*m_method_WIFI_GetConfiguredNetworks)(ifcId);

}
DBus::MultipleReturn <int32_t, Invalid> com_jci_nmsProxy::WIFI_GetConfiguredNetworks_Async(int32_t ifcId) {
  return (*m_method_WIFI_GetConfiguredNetworks_Async)(ifcId);

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
                                          std::tuple < int32_t,
                                          int32_t,
                                          int32_t,
                                          int32_t,
                                          int32_t>>>>>
com_jci_nmsProxy::WIFI_GetScanResults(int32_t
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
                                          std::tuple < int32_t,
                                          int32_t,
                                          int32_t,
                                          int32_t,
                                          int32_t>>>>>
com_jci_nmsProxy::WIFI_GetScanResults_Async(int32_t
ifcId ){
return (*m_method_WIFI_GetScanResults_Async)(ifcId);

}
DBus::MultipleReturn <int32_t, std::tuple<uint32_t,
                                          int32_t,
                                          std::tuple < std::string,
                                          std::string,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          std::tuple < int32_t,
                                          int32_t,
                                          int32_t,
                                          int32_t,
                                          int32_t>>>>
com_jci_nmsProxy::WIFI_GetConnectionInfo(int32_t
ifcId ){
return (*m_method_WIFI_GetConnectionInfo)(ifcId);

}
DBus::MultipleReturn <int32_t, std::tuple<uint32_t,
                                          int32_t,
                                          std::tuple < std::string,
                                          std::string,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          std::tuple < int32_t,
                                          int32_t,
                                          int32_t,
                                          int32_t,
                                          int32_t>>>>
com_jci_nmsProxy::WIFI_GetConnectionInfo_Async(int32_t
ifcId ){
return (*m_method_WIFI_GetConnectionInfo_Async)(ifcId);

}
int32_t com_jci_nmsProxy::WIFI_SaveConfiguredNetworks(int32_t
ifcId ){
return (*m_method_WIFI_SaveConfiguredNetworks)(ifcId);

}
int32_t com_jci_nmsProxy::WIFI_SaveConfiguredNetworks_Async(int32_t
ifcId ){
return (*m_method_WIFI_SaveConfiguredNetworks_Async)(ifcId);

}
int32_t com_jci_nmsProxy::AP_SelectProfile(int32_t
profile ){
return (*m_method_AP_SelectProfile)(profile);

}
int32_t com_jci_nmsProxy::AP_SelectProfile_Async(int32_t
profile ){
return (*m_method_AP_SelectProfile_Async)(profile);

}
int32_t com_jci_nmsProxy::AP_GetInfo(int32_t
ifcId ){
return (*m_method_AP_GetInfo)(ifcId);

}
int32_t com_jci_nmsProxy::AP_GetInfo_Async(int32_t
ifcId ){
return (*m_method_AP_GetInfo_Async)(ifcId);

}
int32_t com_jci_nmsProxy::DHCP_ServerSetConfig(int32_t
ifcId,
std::tuple <std::string, std::string> dhcpConf
){
return (*m_method_DHCP_ServerSetConfig)(ifcId,dhcpConf);

}
int32_t com_jci_nmsProxy::DHCP_ServerSetConfig_Async(int32_t
ifcId,
std::tuple <std::string, std::string> dhcpConf
){
return (*m_method_DHCP_ServerSetConfig_Async)(ifcId,dhcpConf);

}
DBus::MultipleReturn <int32_t, std::tuple<std::string, std::string>> com_jci_nmsProxy::DHCP_ServerGetConfig(int32_t
ifcId ){
return (*m_method_DHCP_ServerGetConfig)(ifcId);

}
DBus::MultipleReturn <int32_t, std::tuple<std::string, std::string>>
    com_jci_nmsProxy::DHCP_ServerGetConfig_Async(int32_t
ifcId ){
return (*m_method_DHCP_ServerGetConfig_Async)(ifcId);

}
int32_t com_jci_nmsProxy::DHCP_ServerStart(int32_t
ifcId ){
return (*m_method_DHCP_ServerStart)(ifcId);

}
int32_t com_jci_nmsProxy::DHCP_ServerStart_Async(int32_t
ifcId ){
return (*m_method_DHCP_ServerStart_Async)(ifcId);

}
int32_t com_jci_nmsProxy::DHCP_ServerStop(int32_t
ifcId ){
return (*m_method_DHCP_ServerStop)(ifcId);

}
int32_t com_jci_nmsProxy::DHCP_ServerStop_Async(int32_t
ifcId ){
return (*m_method_DHCP_ServerStop_Async)(ifcId);

}
int32_t com_jci_nmsProxy::MonitorInterface(int32_t
ifcId,
bool turn
){
return (*m_method_MonitorInterface)(ifcId,turn);

}
int32_t com_jci_nmsProxy::MonitorInterface_Async(int32_t
ifcId,
bool turn
){
return (*m_method_MonitorInterface_Async)(ifcId,turn);

}
int32_t com_jci_nmsProxy::SOCKET_NewConnection(std::tuple <int32_t, std::string, int32_t, int32_t> settings) {
  return (*m_method_SOCKET_NewConnection)(settings);

}
int32_t com_jci_nmsProxy::SOCKET_NewConnection_Async(std::tuple <int32_t, std::string, int32_t, int32_t> settings) {
  return (*m_method_SOCKET_NewConnection_Async)(settings);

}
int32_t com_jci_nmsProxy::AdvancedRouting(int32_t
flag ){
return (*m_method_AdvancedRouting)(flag);

}
int32_t com_jci_nmsProxy::AdvancedRouting_Async(int32_t
flag ){
return (*m_method_AdvancedRouting_Async)(flag);

}
int32_t com_jci_nmsProxy::ActivateNAT(int32_t
flag ){
return (*m_method_ActivateNAT)(flag);

}
int32_t com_jci_nmsProxy::ActivateNAT_Async(int32_t
flag ){
return (*m_method_ActivateNAT_Async)(flag);

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < std::tuple < std::string,
                                          std::string,
                                          std::string,
                                          std::string>>>>
com_jci_nmsProxy::DHCP_ServerGetClients(int32_t
ifcId ){
return (*m_method_DHCP_ServerGetClients)(ifcId);

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < std::tuple < std::string,
                                          std::string,
                                          std::string,
                                          std::string>>>>
com_jci_nmsProxy::DHCP_ServerGetClients_Async(int32_t
ifcId ){
return (*m_method_DHCP_ServerGetClients_Async)(ifcId);

}
int32_t com_jci_nmsProxy::SetHostname(std::string hostname) {
  return (*m_method_SetHostname)(hostname);

}
int32_t com_jci_nmsProxy::SetHostname_Async(std::string hostname) {
  return (*m_method_SetHostname_Async)(hostname);

}
DBus::MultipleReturn <std::string, int32_t> com_jci_nmsProxy::GetHostname() {
  return (*m_method_GetHostname)();

}
DBus::MultipleReturn <std::string, int32_t> com_jci_nmsProxy::GetHostname_Async() {
  return (*m_method_GetHostname_Async)();

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < std::tuple < std::string,
                                          std::string,
                                          std::string,
                                          std::string>>>>
com_jci_nmsProxy::AP_GetClients(int32_t
ifcId ){
return (*m_method_AP_GetClients)(ifcId);

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < std::tuple < std::string,
                                          std::string,
                                          std::string,
                                          std::string>>>>
com_jci_nmsProxy::AP_GetClients_Async(int32_t
ifcId ){
return (*m_method_AP_GetClients_Async)(ifcId);

}
int32_t com_jci_nmsProxy::AP_AddToBlacklist(int32_t
ifcId,
std::string mac
){
return (*m_method_AP_AddToBlacklist)(ifcId,mac);

}
int32_t com_jci_nmsProxy::AP_AddToBlacklist_Async(int32_t
ifcId,
std::string mac
){
return (*m_method_AP_AddToBlacklist_Async)(ifcId,mac);

}
int32_t com_jci_nmsProxy::AP_RemoveFromBlacklist(int32_t
ifcId,
std::string mac
){
return (*m_method_AP_RemoveFromBlacklist)(ifcId,mac);

}
int32_t com_jci_nmsProxy::AP_RemoveFromBlacklist_Async(int32_t
ifcId,
std::string mac
){
return (*m_method_AP_RemoveFromBlacklist_Async)(ifcId,mac);

}
int32_t com_jci_nmsProxy::AP_ClearBlacklist(int32_t
ifcId ){
return (*m_method_AP_ClearBlacklist)(ifcId);

}
int32_t com_jci_nmsProxy::AP_ClearBlacklist_Async(int32_t
ifcId ){
return (*m_method_AP_ClearBlacklist_Async)(ifcId);

}
int32_t com_jci_nmsProxy::AP_SetOpenProfile(std::tuple <std::string, uint32_t, int32_t, int32_t> confAp) {
  return (*m_method_AP_SetOpenProfile)(confAp);

}
int32_t com_jci_nmsProxy::AP_SetOpenProfile_Async(std::tuple <std::string, uint32_t, int32_t, int32_t> confAp) {
  return (*m_method_AP_SetOpenProfile_Async)(confAp);

}
int32_t com_jci_nmsProxy::AP_SetWepProfile(Invalid profile) {
  return (*m_method_AP_SetWepProfile)(profile);

}
int32_t com_jci_nmsProxy::AP_SetWepProfile_Async(Invalid profile) {
  return (*m_method_AP_SetWepProfile_Async)(profile);

}
int32_t com_jci_nmsProxy::AP_SetWpaProfile(Invalid profile) {
  return (*m_method_AP_SetWpaProfile)(profile);

}
int32_t com_jci_nmsProxy::AP_SetWpaProfile_Async(Invalid profile) {
  return (*m_method_AP_SetWpaProfile_Async)(profile);

}
DBus::MultipleReturn <std::tuple<std::string,
                                 uint32_t,
                                 int32_t,
                                 int32_t>, int32_t> com_jci_nmsProxy::AP_GetOpenProfile() {
  return (*m_method_AP_GetOpenProfile)();

}
DBus::MultipleReturn <std::tuple<std::string,
                                 uint32_t,
                                 int32_t,
                                 int32_t>, int32_t> com_jci_nmsProxy::AP_GetOpenProfile_Async() {
  return (*m_method_AP_GetOpenProfile_Async)();

}
DBus::MultipleReturn <Invalid, int32_t> com_jci_nmsProxy::AP_GetWepProfile() {
  return (*m_method_AP_GetWepProfile)();

}
DBus::MultipleReturn <Invalid, int32_t> com_jci_nmsProxy::AP_GetWepProfile_Async() {
  return (*m_method_AP_GetWepProfile_Async)();

}
DBus::MultipleReturn <Invalid, int32_t> com_jci_nmsProxy::AP_GetWpaProfile() {
  return (*m_method_AP_GetWpaProfile)();

}
DBus::MultipleReturn <Invalid, int32_t> com_jci_nmsProxy::AP_GetWpaProfile_Async() {
  return (*m_method_AP_GetWpaProfile_Async)();

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_nmsProxy::AP_GetSelectedProfile() {
  return (*m_method_AP_GetSelectedProfile)();

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_nmsProxy::AP_GetSelectedProfile_Async() {
  return (*m_method_AP_GetSelectedProfile_Async)();

}
int32_t com_jci_nmsProxy::AP_SetHiddenNetwork(int32_t
flag ){
return (*m_method_AP_SetHiddenNetwork)(flag);

}
int32_t com_jci_nmsProxy::AP_SetHiddenNetwork_Async(int32_t
flag ){
return (*m_method_AP_SetHiddenNetwork_Async)(flag);

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_nmsProxy::AP_GetHiddenNetwork() {
  return (*m_method_AP_GetHiddenNetwork)();

}
DBus::MultipleReturn <int32_t, int32_t> com_jci_nmsProxy::AP_GetHiddenNetwork_Async() {
  return (*m_method_AP_GetHiddenNetwork_Async)();

}
DBus::MultipleReturn <std::tuple<std::vector < std::tuple < std::string,
                                 std::string,
                                 uint32_t,
                                 uint32_t,
                                 uint32_t,
                                 uint32_t,
                                 uint32_t,
                                 uint32_t,
                                 uint32_t,
                                 std::tuple < int32_t,
                                 int32_t,
                                 int32_t,
                                 int32_t,
                                 int32_t>>>>,int32_t>
com_jci_nmsProxy::WIFI_GetScanResultsByMatch(int32_t
ifcId,
int32_t matchType, std::string
matchValue ){
return (*m_method_WIFI_GetScanResultsByMatch)(ifcId,matchType,matchValue);

}
DBus::MultipleReturn <std::tuple<std::vector < std::tuple < std::string,
                                 std::string,
                                 uint32_t,
                                 uint32_t,
                                 uint32_t,
                                 uint32_t,
                                 uint32_t,
                                 uint32_t,
                                 uint32_t,
                                 std::tuple < int32_t,
                                 int32_t,
                                 int32_t,
                                 int32_t,
                                 int32_t>>>>,int32_t>
com_jci_nmsProxy::WIFI_GetScanResultsByMatch_Async(int32_t
ifcId,
int32_t matchType, std::string
matchValue ){
return (*m_method_WIFI_GetScanResultsByMatch_Async)(ifcId,matchType,matchValue);

}
int32_t com_jci_nmsProxy::WIFI_EnableNetwork(int32_t
ifcId,
int32_t networkId
){
return (*m_method_WIFI_EnableNetwork)(ifcId,networkId);

}
int32_t com_jci_nmsProxy::WIFI_EnableNetwork_Async(int32_t
ifcId,
int32_t networkId
){
return (*m_method_WIFI_EnableNetwork_Async)(ifcId,networkId);

}
int32_t com_jci_nmsProxy::WIFI_DisableNetwork(int32_t
ifcId,
int32_t networkId
){
return (*m_method_WIFI_DisableNetwork)(ifcId,networkId);

}
int32_t com_jci_nmsProxy::WIFI_DisableNetwork_Async(int32_t
ifcId,
int32_t networkId
){
return (*m_method_WIFI_DisableNetwork_Async)(ifcId,networkId);

}
int32_t com_jci_nmsProxy::WIFI_MonitorStrength(int32_t
ifcId,
bool turn, uint32_t
rate ){
return (*m_method_WIFI_MonitorStrength)(ifcId,turn,rate);

}
int32_t com_jci_nmsProxy::WIFI_MonitorStrength_Async(int32_t
ifcId,
bool turn, uint32_t
rate ){
return (*m_method_WIFI_MonitorStrength_Async)(ifcId,turn,rate);

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
com_jci_nmsProxy::Get_ModemParams(int32_t
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
com_jci_nmsProxy::Get_ModemParams_Async(int32_t
mId ){
return (*m_method_Get_ModemParams_Async)(mId);

}
int32_t com_jci_nmsProxy::Set_ModemParams(int32_t
mId,
std::tuple <std::string, std::string, std::string, std::string, std::string> params, int32_t
updateMask ){
return (*m_method_Set_ModemParams)(mId,params,updateMask);

}
int32_t com_jci_nmsProxy::Set_ModemParams_Async(int32_t
mId,
std::tuple <std::string, std::string, std::string, std::string, std::string> params, int32_t
updateMask ){
return (*m_method_Set_ModemParams_Async)(mId,params,updateMask);

}
int32_t com_jci_nmsProxy::AddModem(std::string modemId,
                                   std::string vendor,
                                   std::tuple <std::vector<std::string>> ports) {
  return (*m_method_AddModem)(modemId, vendor, ports);

}
int32_t com_jci_nmsProxy::RemoveModem(std::string modemId, std::string vendor) {
  return (*m_method_RemoveModem)(modemId, vendor);

}
int32_t com_jci_nmsProxy::Debug_ModemDump() {
  return (*m_method_Debug_ModemDump)();

}
void com_jci_nmsProxy::Debug_ListDump() {
  (*m_method_Debug_ListDump)();

}
DBus::MultipleReturn <int32_t, std::tuple<std::vector < std::string>>>
com_jci_nmsProxy::AP_GetBlacklist(int32_t
ifcId ){
return (*m_method_AP_GetBlacklist)(ifcId);

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_nmsProxy::signal_InterfaceArrive() {
  return m_signalproxy_InterfaceArrive;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_nmsProxy::signal_InterfaceDeparture() {
  return m_signalproxy_InterfaceDeparture;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t, int32_t)>> com_jci_nmsProxy::signal_InterfaceChanged() {
  return m_signalproxy_InterfaceChanged;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_nmsProxy::signal_InterfaceConnecting() {
  return m_signalproxy_InterfaceConnecting;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_nmsProxy::signal_InterfaceDisconnecting() {
  return m_signalproxy_InterfaceDisconnecting;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_nmsProxy::signal_InterfaceConnected() {
  return m_signalproxy_InterfaceConnected;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t, int32_t)>> com_jci_nmsProxy::signal_InterfaceDisconnected() {
  return m_signalproxy_InterfaceDisconnected;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_nmsProxy::signal_WifiScanResultsReady() {
  return m_signalproxy_WifiScanResultsReady;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t, int32_t, int32_t)>> com_jci_nmsProxy::signal_ConnectResult() {
  return m_signalproxy_ConnectResult;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t, int32_t)>> com_jci_nmsProxy::signal_InterfaceWiFiModeChanged() {
  return m_signalproxy_InterfaceWiFiModeChanged;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t, std::string)>> com_jci_nmsProxy::signal_WiFiAPClientConnected() {
  return m_signalproxy_WiFiAPClientConnected;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t, std::string)>> com_jci_nmsProxy::signal_WiFiAPClientDisconnected() {
  return m_signalproxy_WiFiAPClientDisconnected;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t,
                                        std::tuple < std::string,
                                        uint32_t,
                                        int32_t,
                                        int32_t > )>> com_jci_nmsProxy::signal_APOpenInfo() {
  return m_signalproxy_APOpenInfo;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t, Invalid)>> com_jci_nmsProxy::signal_APWepInfo() {
  return m_signalproxy_APWepInfo;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t, Invalid)>> com_jci_nmsProxy::signal_APWpaInfo() {
  return m_signalproxy_APWpaInfo;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t,
                                        std::tuple < uint64_t,
                                        uint64_t > )>> com_jci_nmsProxy::signal_InterfaceMonitorData() {
  return m_signalproxy_InterfaceMonitorData;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t, uint32_t)>> com_jci_nmsProxy::signal_WifiSignalStrength() {
  return m_signalproxy_WifiSignalStrength;

}
