#ifndef COM_JCI_SXMS_NNGPROXY_H
#define COM_JCI_SXMS_NNGPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_sxms_nngProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_sxms_nngProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_sxms_nngProxy> create(std::string name = "com.jci.sxms_nng");
  uint32_t GetDataServiceSubscriptions();
  DBus::MultipleReturn<uint32_t, uint32_t> Apogee_CreateCollectionReq(Invalid mbr, uint32_t types);
  uint32_t Apogee_ModifyCollectionReq(uint32_t collectionID, Invalid mbr);
  uint32_t Apogee_RemoveCollectionReq(uint32_t collectionID);
  DBus::MultipleReturn<std::tuple<std::vector<std::tuple<uint32_t>>>, uint32_t> Apogee_GetBSAList(Invalid mbr);
  uint32_t Apogee_SetExtractionFilter(uint32_t collectionID,
                                      Invalid mbr,
                                      std::tuple<std::vector<std::tuple<uint32_t>>> bsaList);
  uint32_t Apogee_ExtractData(uint32_t collectionID, uint32_t type);
  uint32_t AGWeather_GetData(uint32_t type);
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> signal_Apogee_DataAvailable();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, Invalid)>> signal_Apogee_RealTimeFlowData();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, Invalid)>> signal_Apogee_P1FlowData();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, Invalid)>> signal_Apogee_P2FlowData();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, Invalid)>> signal_Apogee_P3FlowData();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, Invalid)>> signal_Apogee_P4FlowData();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, Invalid)>> signal_Apogee_RampData();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, Invalid)>> signal_Apogee_ConstructionIncidentData();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<std::tuple<uint32_t,
                                                                           uint32_t>>>)>> signal_DataServiceSubscription();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_AGweather_DatasetStart();
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> signal_AGweather_NowRadData();
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> signal_AGweather_FrontData();
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> signal_AGweather_SurfaceIsobar();
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> signal_AGweather_PressureCenter();
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> signal_AGweather_StormAttributes();
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> signal_AGweather_StormPosition();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_AGweather_DatasetStop();
 protected:
  std::shared_ptr<DBus::MethodProxy<uint32_t()>> m_method_GetDataServiceSubscriptions;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t>(Invalid, uint32_t)>>
      m_method_Apogee_CreateCollectionReq;
  std::shared_ptr<DBus::MethodProxy<uint32_t(uint32_t, Invalid)>> m_method_Apogee_ModifyCollectionReq;
  std::shared_ptr<DBus::MethodProxy<uint32_t(uint32_t)>> m_method_Apogee_RemoveCollectionReq;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::tuple<std::vector<std::tuple<uint32_t>>>, uint32_t>(
      Invalid)>> m_method_Apogee_GetBSAList;
  std::shared_ptr<DBus::MethodProxy<uint32_t(uint32_t, Invalid, std::tuple<std::vector<std::tuple<uint32_t>>>)>>
      m_method_Apogee_SetExtractionFilter;
  std::shared_ptr<DBus::MethodProxy<uint32_t(uint32_t, uint32_t)>> m_method_Apogee_ExtractData;
  std::shared_ptr<DBus::MethodProxy<uint32_t(uint32_t)>> m_method_AGWeather_GetData;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, uint32_t)>> m_signalproxy_Apogee_DataAvailable;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, Invalid)>> m_signalproxy_Apogee_RealTimeFlowData;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, Invalid)>> m_signalproxy_Apogee_P1FlowData;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, Invalid)>> m_signalproxy_Apogee_P2FlowData;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, Invalid)>> m_signalproxy_Apogee_P3FlowData;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, Invalid)>> m_signalproxy_Apogee_P4FlowData;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, Invalid)>> m_signalproxy_Apogee_RampData;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, Invalid)>> m_signalproxy_Apogee_ConstructionIncidentData;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<std::tuple<uint32_t, uint32_t>>>)>>
      m_signalproxy_DataServiceSubscription;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_AGweather_DatasetStart;
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> m_signalproxy_AGweather_NowRadData;
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> m_signalproxy_AGweather_FrontData;
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> m_signalproxy_AGweather_SurfaceIsobar;
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> m_signalproxy_AGweather_PressureCenter;
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> m_signalproxy_AGweather_StormAttributes;
  std::shared_ptr<DBus::SignalProxy<void(Invalid)>> m_signalproxy_AGweather_StormPosition;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_AGweather_DatasetStop;
};
#endif /* COM_JCI_SXMS_NNGPROXY_H */
