#ifndef COM_JCI_VBS_NAVI_H
#define COM_JCI_VBS_NAVI_H

#include <stdint.h>
#include <string>
#include <tuple>
#include <vector>
class com_jci_vbs_navi {
 public:
  virtual uint8_t GetFuelType() = 0;
  virtual uint8_t GetHUDStatus() = 0;
  virtual uint8_t GetTSRStatus() = 0;
  virtual uint8_t GetTSRMode() = 0;
  virtual uint8_t TMCServiceListReq(uint8_t tmcSrvceLstReq) = 0;
  virtual uint8_t TMCSelectReq(std::tuple<uint8_t, uint8_t, uint8_t, uint8_t, uint8_t> tmcSelectReq) = 0;
  virtual uint8_t SetHUDDisplayMsgReq(std::tuple<uint32_t,
                                                 uint16_t,
                                                 uint8_t,
                                                 uint16_t,
                                                 uint8_t,
                                                 uint8_t> hudDisplayMsg) = 0;
  virtual uint8_t SetRecommLaneReq(std::tuple<std::vector<uint8_t>> hudRecommLaneInfo) = 0;
  virtual uint8_t SetTSRNavigationSignal(std::tuple<uint8_t, bool, bool, uint8_t> tsrNavigation) = 0;
  virtual std::string GetVINData() = 0;
};
#endif /* COM_JCI_VBS_NAVI_H */
