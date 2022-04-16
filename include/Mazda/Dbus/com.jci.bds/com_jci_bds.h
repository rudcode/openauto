#ifndef COM_JCI_BDS_H
#define COM_JCI_BDS_H

#include <stdint.h>
#include <tuple>
#include <vector>
class com_jci_bds {
 public:
  virtual uint32_t SendCommand(uint32_t type, std::tuple<std::vector<uint8_t>> data) = 0;
  virtual void TestMethod(uint32_t type) = 0;
};
#endif /* COM_JCI_BDS_H */
