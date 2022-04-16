#ifndef COM_XSEMBEDDED_SERVICEPROVIDER_H
#define COM_XSEMBEDDED_SERVICEPROVIDER_H

#include <stdint.h>
#include <string>
#include <tuple>
#include <vector>
#include <dbus-cxx.h>
class com_xsembedded_ServiceProvider {
 public:
  virtual std::string Request(std::string methodName, std::string arguments) = 0;
  virtual DBus::MultipleReturn<int32_t, std::tuple<int32_t, std::string, std::string>> openSession(std::string busName,
                                                                                                   std::string objectPath,
                                                                                                   std::string destination) = 0;
  virtual std::tuple<int32_t, std::string, std::string> closeSession(int32_t sessionId) = 0;
  virtual std::tuple<int32_t, std::string, std::string> registerAudioStream(int32_t sessionId,
                                                                            std::string streamName,
                                                                            std::string streamModeName,
                                                                            std::string streamType,
                                                                            int32_t focusType) = 0;
  virtual std::tuple<int32_t, std::string, std::string> requestAudioFocus(int32_t sessionId, int32_t requestType) = 0;
  virtual std::tuple<int32_t, std::string, std::string> abandonAudioFocus(int32_t sessionId, std::string reason) = 0;
  virtual std::tuple<int32_t, std::string, std::string> audioActive(int32_t sessionId, int32_t playing) = 0;
  virtual std::tuple<int32_t, std::string, std::string> setMode(int32_t sessionId,
                                                                std::string newMode,
                                                                std::string destination) = 0;
  virtual DBus::MultipleReturn<std::string, std::tuple<int32_t, std::string, std::string>> getMode(int32_t sessionId,
                                                                                                   std::string destination) = 0;
  virtual DBus::MultipleReturn<std::tuple<std::vector<std::string>, int32_t>,
                               std::tuple<int32_t, std::string, std::string>> getModeList(int32_t sessionId,
                                                                                          std::string destination) = 0;
  virtual DBus::MultipleReturn<int32_t, std::tuple<int32_t, std::string, std::string>> enableStatus() = 0;
  virtual std::tuple<int32_t, std::string, std::string> enable(int32_t setAudioStatus) = 0;
};
#endif /* COM_XSEMBEDDED_SERVICEPROVIDER_H */
