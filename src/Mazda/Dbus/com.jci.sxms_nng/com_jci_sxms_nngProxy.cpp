#include "com_jci_sxms_nngProxy.h"

com_jci_sxms_nngProxy::com_jci_sxms_nngProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_GetDataServiceSubscriptions = this->create_method<uint32_t()>("GetDataServiceSubscriptions");
  m_method_Apogee_CreateCollectionReq =
      this->create_method<DBus::MultipleReturn<uint32_t, uint32_t>(Invalid, uint32_t)>("Apogee_CreateCollectionReq");
  m_method_Apogee_ModifyCollectionReq = this->create_method<uint32_t(uint32_t, Invalid)>("Apogee_ModifyCollectionReq");
  m_method_Apogee_RemoveCollectionReq = this->create_method<uint32_t(uint32_t)>("Apogee_RemoveCollectionReq");
  m_method_Apogee_GetBSAList =
      this->create_method < DBus::MultipleReturn < std::tuple < std::vector < std::tuple < uint32_t>>>,uint32_t
      > (Invalid) > ("Apogee_GetBSAList");
  m_method_Apogee_SetExtractionFilter = this->create_method
      < uint32_t(uint32_t, Invalid, std::tuple < std::vector < std::tuple < uint32_t>>>)>("Apogee_SetExtractionFilter");
  m_method_Apogee_ExtractData = this->create_method<uint32_t(uint32_t, uint32_t)>("Apogee_ExtractData");
  m_method_AGWeather_GetData = this->create_method<uint32_t(uint32_t)>("AGWeather_GetData");
  m_signalproxy_Apogee_DataAvailable = this->create_signal<void(uint32_t, uint32_t)>("Apogee_DataAvailable");
  m_signalproxy_Apogee_RealTimeFlowData = this->create_signal<void(uint32_t, Invalid)>("Apogee_RealTimeFlowData");
  m_signalproxy_Apogee_P1FlowData = this->create_signal<void(uint32_t, Invalid)>("Apogee_P1FlowData");
  m_signalproxy_Apogee_P2FlowData = this->create_signal<void(uint32_t, Invalid)>("Apogee_P2FlowData");
  m_signalproxy_Apogee_P3FlowData = this->create_signal<void(uint32_t, Invalid)>("Apogee_P3FlowData");
  m_signalproxy_Apogee_P4FlowData = this->create_signal<void(uint32_t, Invalid)>("Apogee_P4FlowData");
  m_signalproxy_Apogee_RampData = this->create_signal<void(uint32_t, Invalid)>("Apogee_RampData");
  m_signalproxy_Apogee_ConstructionIncidentData =
      this->create_signal<void(uint32_t, Invalid)>("Apogee_ConstructionIncidentData");
  m_signalproxy_DataServiceSubscription = this->create_signal
      < void(std::tuple < std::vector < std::tuple < uint32_t, uint32_t>>>)>("DataServiceSubscription");
  m_signalproxy_AGweather_DatasetStart = this->create_signal<void(uint32_t)>("AGweather_DatasetStart");
  m_signalproxy_AGweather_NowRadData = this->create_signal<void(Invalid)>("AGweather_NowRadData");
  m_signalproxy_AGweather_FrontData = this->create_signal<void(Invalid)>("AGweather_FrontData");
  m_signalproxy_AGweather_SurfaceIsobar = this->create_signal<void(Invalid)>("AGweather_SurfaceIsobar");
  m_signalproxy_AGweather_PressureCenter = this->create_signal<void(Invalid)>("AGweather_PressureCenter");
  m_signalproxy_AGweather_StormAttributes = this->create_signal<void(Invalid)>("AGweather_StormAttributes");
  m_signalproxy_AGweather_StormPosition = this->create_signal<void(Invalid)>("AGweather_StormPosition");
  m_signalproxy_AGweather_DatasetStop = this->create_signal<void(uint32_t)>("AGweather_DatasetStop");

}
std::shared_ptr <com_jci_sxms_nngProxy> com_jci_sxms_nngProxy::create(std::string name) {
  return std::shared_ptr<com_jci_sxms_nngProxy>(new com_jci_sxms_nngProxy(name));

}
uint32_t com_jci_sxms_nngProxy::GetDataServiceSubscriptions() {
  return (*m_method_GetDataServiceSubscriptions)();

}
DBus::MultipleReturn <uint32_t, uint32_t> com_jci_sxms_nngProxy::Apogee_CreateCollectionReq(Invalid mbr,
                                                                                            uint32_t types) {
  return (*m_method_Apogee_CreateCollectionReq)(mbr, types);

}
uint32_t com_jci_sxms_nngProxy::Apogee_ModifyCollectionReq(uint32_t collectionID, Invalid mbr) {
  return (*m_method_Apogee_ModifyCollectionReq)(collectionID, mbr);

}
uint32_t com_jci_sxms_nngProxy::Apogee_RemoveCollectionReq(uint32_t collectionID) {
  return (*m_method_Apogee_RemoveCollectionReq)(collectionID);

}
DBus::MultipleReturn <std::tuple<std::vector < std::tuple < uint32_t>>>,uint32_t>
com_jci_sxms_nngProxy::Apogee_GetBSAList(Invalid
mbr ){
return (*m_method_Apogee_GetBSAList)(mbr);

}
uint32_t com_jci_sxms_nngProxy::Apogee_SetExtractionFilter(uint32_t collectionID,
                                                           Invalid mbr,
                                                           std::tuple <std::vector<std::tuple < uint32_t>>
> bsaList ){
return (*m_method_Apogee_SetExtractionFilter)(collectionID,mbr,bsaList);

}
uint32_t com_jci_sxms_nngProxy::Apogee_ExtractData(uint32_t collectionID, uint32_t type) {
  return (*m_method_Apogee_ExtractData)(collectionID, type);

}
uint32_t com_jci_sxms_nngProxy::AGWeather_GetData(uint32_t type) {
  return (*m_method_AGWeather_GetData)(type);

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, uint32_t)>> com_jci_sxms_nngProxy::signal_Apogee_DataAvailable() {
  return m_signalproxy_Apogee_DataAvailable;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, Invalid)>> com_jci_sxms_nngProxy::signal_Apogee_RealTimeFlowData() {
  return m_signalproxy_Apogee_RealTimeFlowData;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, Invalid)>> com_jci_sxms_nngProxy::signal_Apogee_P1FlowData() {
  return m_signalproxy_Apogee_P1FlowData;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, Invalid)>> com_jci_sxms_nngProxy::signal_Apogee_P2FlowData() {
  return m_signalproxy_Apogee_P2FlowData;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, Invalid)>> com_jci_sxms_nngProxy::signal_Apogee_P3FlowData() {
  return m_signalproxy_Apogee_P3FlowData;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, Invalid)>> com_jci_sxms_nngProxy::signal_Apogee_P4FlowData() {
  return m_signalproxy_Apogee_P4FlowData;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, Invalid)>> com_jci_sxms_nngProxy::signal_Apogee_RampData() {
  return m_signalproxy_Apogee_RampData;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t,
                                        Invalid)>> com_jci_sxms_nngProxy::signal_Apogee_ConstructionIncidentData() {
  return m_signalproxy_Apogee_ConstructionIncidentData;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < std::vector < std::tuple < uint32_t, uint32_t>>>)>>
com_jci_sxms_nngProxy::signal_DataServiceSubscription() {
  return m_signalproxy_DataServiceSubscription;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_sxms_nngProxy::signal_AGweather_DatasetStart() {
  return m_signalproxy_AGweather_DatasetStart;

}
std::shared_ptr <DBus::SignalProxy<void(Invalid)>> com_jci_sxms_nngProxy::signal_AGweather_NowRadData() {
  return m_signalproxy_AGweather_NowRadData;

}
std::shared_ptr <DBus::SignalProxy<void(Invalid)>> com_jci_sxms_nngProxy::signal_AGweather_FrontData() {
  return m_signalproxy_AGweather_FrontData;

}
std::shared_ptr <DBus::SignalProxy<void(Invalid)>> com_jci_sxms_nngProxy::signal_AGweather_SurfaceIsobar() {
  return m_signalproxy_AGweather_SurfaceIsobar;

}
std::shared_ptr <DBus::SignalProxy<void(Invalid)>> com_jci_sxms_nngProxy::signal_AGweather_PressureCenter() {
  return m_signalproxy_AGweather_PressureCenter;

}
std::shared_ptr <DBus::SignalProxy<void(Invalid)>> com_jci_sxms_nngProxy::signal_AGweather_StormAttributes() {
  return m_signalproxy_AGweather_StormAttributes;

}
std::shared_ptr <DBus::SignalProxy<void(Invalid)>> com_jci_sxms_nngProxy::signal_AGweather_StormPosition() {
  return m_signalproxy_AGweather_StormPosition;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_sxms_nngProxy::signal_AGweather_DatasetStop() {
  return m_signalproxy_AGweather_DatasetStop;

}
