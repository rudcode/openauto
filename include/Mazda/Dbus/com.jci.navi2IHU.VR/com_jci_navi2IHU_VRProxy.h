#ifndef COM_JCI_NAVI_IHU_VRPROXY_H
#define COM_JCI_NAVI_IHU_VRPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_navi2IHU_VRProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_navi2IHU_VRProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_navi2IHU_VRProxy> create(std::string name = "com.jci.navi2IHU.VR");
  void VREvent(std::string eventId);
  void SelectedListItem(int32_t seletedItem);
  void JpjIntermediateHypothesis(std::tuple<uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t> jpjHypothesis);
  void JpjVDEHypothesisList(std::tuple<int32_t,
                                       std::vector<std::tuple<uint32_t,
                                                              uint32_t,
                                                              uint32_t,
                                                              uint32_t,
                                                              uint32_t,
                                                              uint32_t>>> jpjHypothesisList);
  void VDEHypothesisList(std::tuple<int32_t, std::vector<std::tuple<uint32_t, uint32_t, uint32_t, uint32_t>>> vDEList);
  void NavigateToPOI(std::tuple<int32_t, std::vector<std::tuple<std::string>>> poiCategoryName);
  void AddWaypointPOI(std::tuple<int32_t, std::vector<std::tuple<std::string>>> poiCategoryName);
  void SimpleHypothesisList(std::tuple<int32_t, std::vector<std::tuple<uint32_t>>> idList);
  void ModeChanged(int32_t modality);
  void UniVDEHypothesisList(std::tuple<int32_t, std::vector<std::tuple<std::string>>> uniHypothesisList);
  void UniSimpleHypothesisList(std::tuple<int32_t, std::vector<std::tuple<std::string>>> uniHypothesisList);
 protected:
  std::shared_ptr<DBus::MethodProxy<void(std::string)>> m_method_VREvent;
  std::shared_ptr<DBus::MethodProxy<void(int32_t)>> m_method_SelectedListItem;
  std::shared_ptr<DBus::MethodProxy<void(std::tuple<uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t>)>>
      m_method_JpjIntermediateHypothesis;
  std::shared_ptr<DBus::MethodProxy<void(std::tuple<int32_t,
                                                    std::vector<std::tuple<uint32_t,
                                                                           uint32_t,
                                                                           uint32_t,
                                                                           uint32_t,
                                                                           uint32_t,
                                                                           uint32_t>>>)>> m_method_JpjVDEHypothesisList;
  std::shared_ptr<DBus::MethodProxy<void(std::tuple<int32_t,
                                                    std::vector<std::tuple<uint32_t, uint32_t, uint32_t, uint32_t>>>)>>
      m_method_VDEHypothesisList;
  std::shared_ptr<DBus::MethodProxy<void(std::tuple<int32_t, std::vector<std::tuple<std::string>>>)>>
      m_method_NavigateToPOI;
  std::shared_ptr<DBus::MethodProxy<void(std::tuple<int32_t, std::vector<std::tuple<std::string>>>)>>
      m_method_AddWaypointPOI;
  std::shared_ptr<DBus::MethodProxy<void(std::tuple<int32_t, std::vector<std::tuple<uint32_t>>>)>>
      m_method_SimpleHypothesisList;
  std::shared_ptr<DBus::MethodProxy<void(int32_t)>> m_method_ModeChanged;
  std::shared_ptr<DBus::MethodProxy<void(std::tuple<int32_t, std::vector<std::tuple<std::string>>>)>>
      m_method_UniVDEHypothesisList;
  std::shared_ptr<DBus::MethodProxy<void(std::tuple<int32_t, std::vector<std::tuple<std::string>>>)>>
      m_method_UniSimpleHypothesisList;
};
#endif /* COM_JCI_NAVI_IHU_VRPROXY_H */
