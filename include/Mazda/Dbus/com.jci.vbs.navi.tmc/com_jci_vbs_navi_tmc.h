#ifndef COM_JCI_VBS_NAVI_TMC_H
#define COM_JCI_VBS_NAVI_TMC_H

#include <stdint.h>
#include <string>
#include <tuple>
class com_jci_vbs_navi_tmc {
 public:
  virtual uint8_t NaviCompassVal(uint8_t compass) = 0;
  virtual uint8_t NaviSignal(uint8_t navi) = 0;
  virtual uint8_t SetHUD_Display_Msg2(std::tuple<std::string, uint8_t> guidancePointData) = 0;
};
#endif /* COM_JCI_VBS_NAVI_TMC_H */
