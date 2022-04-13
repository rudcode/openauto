#ifndef COM_XSEMBEDDED_SERVICEPROVIDERPROXY_H
#define COM_XSEMBEDDED_SERVICEPROVIDERPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_xsembedded_ServiceProviderProxy
    : public DBus::InterfaceProxy {
 protected:
  com_xsembedded_ServiceProviderProxy(std::string name);
 public:
  static std::shared_ptr<com_xsembedded_ServiceProviderProxy> create(std::string name = "com.xsembedded.ServiceProvider");
  std::string Request(std::string methodName, std::string arguments);
  DBus::MultipleReturn<int32_t, std::tuple<int32_t, std::string, std::string>> openSession(std::string busName,
                                                                                           std::string objectPath,
                                                                                           std::string destination);
  std::tuple<int32_t, std::string, std::string> closeSession(int32_t sessionId);
  std::tuple<int32_t, std::string, std::string> registerAudioStream(int32_t sessionId,
                                                                    std::string streamName,
                                                                    std::string streamModeName,
                                                                    std::string streamType,
                                                                    int32_t focusType);
  std::tuple<int32_t, std::string, std::string> requestAudioFocus(int32_t sessionId, int32_t requestType);
  std::tuple<int32_t, std::string, std::string> abandonAudioFocus(int32_t sessionId, std::string reason);
  std::tuple<int32_t, std::string, std::string> audioActive(int32_t sessionId, int32_t playing);
  std::tuple<int32_t, std::string, std::string> setMode(int32_t sessionId,
                                                        std::string newMode,
                                                        std::string destination);
  DBus::MultipleReturn<std::string, std::tuple<int32_t, std::string, std::string>> getMode(int32_t sessionId,
                                                                                           std::string destination);
  DBus::MultipleReturn<std::tuple<std::vector<std::string>, int32_t>,
                       std::tuple<int32_t, std::string, std::string>> getModeList(int32_t sessionId,
                                                                                  std::string destination);
  DBus::MultipleReturn<int32_t, std::tuple<int32_t, std::string, std::string>> enableStatus();
  std::tuple<int32_t, std::string, std::string> enable(int32_t setAudioStatus);
  std::shared_ptr<DBus::SignalProxy<void(std::string, std::string)>> signal_Notify();
 protected:
  std::shared_ptr<DBus::MethodProxy<std::string(std::string, std::string)>> m_method_Request;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t,
                                                         std::tuple<int32_t, std::string, std::string>>(std::string,
                                                                                                        std::string,
                                                                                                        std::string)>>
      m_method_openSession;
  std::shared_ptr<DBus::MethodProxy<std::tuple<int32_t, std::string, std::string>(int32_t)>> m_method_closeSession;
  std::shared_ptr<DBus::MethodProxy<std::tuple<int32_t, std::string, std::string>(int32_t,
                                                                                  std::string,
                                                                                  std::string,
                                                                                  std::string,
                                                                                  int32_t)>>
      m_method_registerAudioStream;
  std::shared_ptr<DBus::MethodProxy<std::tuple<int32_t, std::string, std::string>(int32_t, int32_t)>>
      m_method_requestAudioFocus;
  std::shared_ptr<DBus::MethodProxy<std::tuple<int32_t, std::string, std::string>(int32_t, std::string)>>
      m_method_abandonAudioFocus;
  std::shared_ptr<DBus::MethodProxy<std::tuple<int32_t, std::string, std::string>(int32_t, int32_t)>>
      m_method_audioActive;
  std::shared_ptr<DBus::MethodProxy<std::tuple<int32_t, std::string, std::string>(int32_t, std::string, std::string)>>
      m_method_setMode;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::string, std::tuple<int32_t, std::string, std::string>>(
      int32_t,
      std::string)>> m_method_getMode;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<std::tuple<std::vector<std::string>, int32_t>,
                                                         std::tuple<int32_t, std::string, std::string>>(int32_t,
                                                                                                        std::string)>>
      m_method_getModeList;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, std::tuple<int32_t, std::string, std::string>>()>>
      m_method_enableStatus;
  std::shared_ptr<DBus::MethodProxy<std::tuple<int32_t, std::string, std::string>(int32_t)>> m_method_enable;
  std::shared_ptr<DBus::SignalProxy<void(std::string, std::string)>> m_signalproxy_Notify;
};
#endif /* COM_XSEMBEDDED_SERVICEPROVIDERPROXY_H */
