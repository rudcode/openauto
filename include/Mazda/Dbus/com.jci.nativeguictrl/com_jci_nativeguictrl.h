#ifndef COM_JCI_NATIVEGUICTRL_H
#define COM_JCI_NATIVEGUICTRL_H

#include <stdint.h>
#include <string>
class com_jci_nativeguictrl {
 public:
  virtual void SetRequiredSurfaces(std::string surfaces, int16_t bFadeOpera) = 0;
};
#endif /* COM_JCI_NATIVEGUICTRL_H */
