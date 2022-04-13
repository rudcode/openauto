#include "com_jci_navi2IHU_VRProxy.h"

com_jci_navi2IHU_VRProxy::com_jci_navi2IHU_VRProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_VREvent = this->create_method<void(std::string)>("VREvent");
  m_method_SelectedListItem = this->create_method<void(int32_t)>("SelectedListItem");
  m_method_JpjIntermediateHypothesis =
      this->create_method<void(std::tuple < uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t > )>(
          "JpjIntermediateHypothesis");
  m_method_JpjVDEHypothesisList = this->create_method < void(std::tuple < int32_t,
                                                             std::vector < std::tuple < uint32_t,
                                                             uint32_t,
                                                             uint32_t,
                                                             uint32_t,
                                                             uint32_t,
                                                             uint32_t>>>)>("JpjVDEHypothesisList");
  m_method_VDEHypothesisList = this->create_method < void(std::tuple < int32_t,
                                                          std::vector < std::tuple < uint32_t,
                                                          uint32_t,
                                                          uint32_t,
                                                          uint32_t>>>)>("VDEHypothesisList");
  m_method_NavigateToPOI =
      this->create_method < void(std::tuple < int32_t, std::vector < std::tuple < std::string>>>)>("NavigateToPOI");
  m_method_AddWaypointPOI =
      this->create_method < void(std::tuple < int32_t, std::vector < std::tuple < std::string>>>)>("AddWaypointPOI");
  m_method_SimpleHypothesisList =
      this->create_method < void(std::tuple < int32_t, std::vector < std::tuple < uint32_t>>>)>("SimpleHypothesisList");
  m_method_ModeChanged = this->create_method<void(int32_t)>("ModeChanged");
  m_method_UniVDEHypothesisList = this->create_method
      < void(std::tuple < int32_t, std::vector < std::tuple < std::string>>>)>("UniVDEHypothesisList");
  m_method_UniSimpleHypothesisList = this->create_method
      < void(std::tuple < int32_t, std::vector < std::tuple < std::string>>>)>("UniSimpleHypothesisList");

}
std::shared_ptr <com_jci_navi2IHU_VRProxy> com_jci_navi2IHU_VRProxy::create(std::string name) {
  return std::shared_ptr<com_jci_navi2IHU_VRProxy>(new com_jci_navi2IHU_VRProxy(name));

}
void com_jci_navi2IHU_VRProxy::VREvent(std::string eventId) {
  (*m_method_VREvent)(eventId);

}
void com_jci_navi2IHU_VRProxy::SelectedListItem(int32_t seletedItem) {
  (*m_method_SelectedListItem)(seletedItem);

}
void com_jci_navi2IHU_VRProxy::JpjIntermediateHypothesis(std::tuple <uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t> jpjHypothesis) {
  (*m_method_JpjIntermediateHypothesis)(jpjHypothesis);

}
voidcom_jci_navi2IHU_VRProxy::JpjVDEHypothesisList
    (std::tuple < int32_t, std::vector < std::tuple < uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t
>>> jpjHypothesisList ){
(*m_method_JpjVDEHypothesisList)(jpjHypothesisList);

}
voidcom_jci_navi2IHU_VRProxy::VDEHypothesisList
    (std::tuple < int32_t, std::vector < std::tuple < uint32_t, uint32_t, uint32_t, uint32_t
>>> vDEList ){
(*m_method_VDEHypothesisList)(vDEList);

}
void com_jci_navi2IHU_VRProxy::NavigateToPOI(std::tuple < int32_t, std::vector < std::tuple < std::string
>>> poiCategoryName ){
(*m_method_NavigateToPOI)(poiCategoryName);

}
void com_jci_navi2IHU_VRProxy::AddWaypointPOI(std::tuple < int32_t, std::vector < std::tuple < std::string
>>> poiCategoryName ){
(*m_method_AddWaypointPOI)(poiCategoryName);

}
void com_jci_navi2IHU_VRProxy::SimpleHypothesisList(std::tuple < int32_t, std::vector < std::tuple < uint32_t
>>> idList ){
(*m_method_SimpleHypothesisList)(idList);

}
void com_jci_navi2IHU_VRProxy::ModeChanged(int32_t modality) {
  (*m_method_ModeChanged)(modality);

}
void com_jci_navi2IHU_VRProxy::UniVDEHypothesisList(std::tuple < int32_t, std::vector < std::tuple < std::string
>>> uniHypothesisList ){
(*m_method_UniVDEHypothesisList)(uniHypothesisList);

}
void com_jci_navi2IHU_VRProxy::UniSimpleHypothesisList(std::tuple < int32_t, std::vector < std::tuple < std::string
>>> uniHypothesisList ){
(*m_method_UniSimpleHypothesisList)(uniHypothesisList);

}
