#include "com_jci_nativeguictrlProxy.h"

com_jci_nativeguictrlProxy::com_jci_nativeguictrlProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_SetRequiredSurfaces = this->create_method<void(std::string, int16_t)>("SetRequiredSurfaces");

}
std::shared_ptr<com_jci_nativeguictrlProxy> com_jci_nativeguictrlProxy::create(std::string name) {
  return std::shared_ptr<com_jci_nativeguictrlProxy>(new com_jci_nativeguictrlProxy(name));

}
void com_jci_nativeguictrlProxy::SetRequiredSurfaces(std::string surfaces, int16_t bFadeOpera) {
  (*m_method_SetRequiredSurfaces)(surfaces, bFadeOpera);

}
