#include "com_jci_nativeguictrlInterface.h"

com_jci_nativeguictrlInterface::com_jci_nativeguictrlInterface(com_jci_nativeguictrl *adaptee, std::string name)
    : DBus::Interface(name) {
  this->create_method<void(std::string, int16_t)>("SetRequiredSurfaces",
                                                  sigc::mem_fun(*adaptee, &com_jci_nativeguictrl::SetRequiredSurfaces));

}
std::shared_ptr<com_jci_nativeguictrlInterface> com_jci_nativeguictrlInterface::create(com_jci_nativeguictrl *adaptee,
                                                                                       std::string name) {
  return std::shared_ptr<com_jci_nativeguictrlInterface>(new com_jci_nativeguictrlInterface(adaptee, name));

}
