#include "com_xsembedded_ServiceProviderProxy.h"

com_xsembedded_ServiceProviderProxy::com_xsembedded_ServiceProviderProxy(std::string name)
    : DBus::InterfaceProxy(name) {
  m_method_Request = this->create_method<std::string(std::string, std::string)>("Request");
  m_method_openSession =
      this->create_method<DBus::MultipleReturn<int32_t, std::tuple<int32_t, std::string, std::string>>(std::string,
                                                                                                       std::string,
                                                                                                       std::string)>(
          "openSession");
  m_method_closeSession = this->create_method<std::tuple<int32_t, std::string, std::string>(int32_t)>("closeSession");
  m_method_registerAudioStream = this->create_method<std::tuple<int32_t, std::string, std::string>(int32_t,
                                                                                                   std::string,
                                                                                                   std::string,
                                                                                                   std::string,
                                                                                                   int32_t)>(
      "registerAudioStream");
  m_method_requestAudioFocus =
      this->create_method<std::tuple<int32_t, std::string, std::string>(int32_t, int32_t)>("requestAudioFocus");
  m_method_abandonAudioFocus =
      this->create_method<std::tuple<int32_t, std::string, std::string>(int32_t, std::string)>("abandonAudioFocus");
  m_method_audioActive =
      this->create_method<std::tuple<int32_t, std::string, std::string>(int32_t, int32_t)>("audioActive");
  m_method_setMode =
      this->create_method<std::tuple<int32_t, std::string, std::string>(int32_t, std::string, std::string)>("setMode");
  m_method_getMode =
      this->create_method<DBus::MultipleReturn<std::string, std::tuple<int32_t, std::string, std::string>>(int32_t,
                                                                                                           std::string)>(
          "getMode");
  m_method_getModeList = this->create_method<DBus::MultipleReturn<std::tuple<std::vector<std::string>, int32_t>,
                                                                  std::tuple<int32_t,
                                                                             std::string,
                                                                             std::string>>(int32_t, std::string)>(
      "getModeList");
  m_method_enableStatus = this->create_method<DBus::MultipleReturn<int32_t,
                                                                   std::tuple<int32_t, std::string, std::string>>()>(
      "enableStatus");
  m_method_enable = this->create_method<std::tuple<int32_t, std::string, std::string>(int32_t)>("enable");
  m_signalproxy_Notify = this->create_signal<void(std::string, std::string)>("Notify");

}
std::shared_ptr<com_xsembedded_ServiceProviderProxy> com_xsembedded_ServiceProviderProxy::create(std::string name) {
  return std::shared_ptr<com_xsembedded_ServiceProviderProxy>(new com_xsembedded_ServiceProviderProxy(name));

}
std::string com_xsembedded_ServiceProviderProxy::Request(std::string methodName, std::string arguments) {
  return (*m_method_Request)(methodName, arguments);

}
DBus::MultipleReturn<int32_t,
                     std::tuple<int32_t,
                                std::string,
                                std::string>> com_xsembedded_ServiceProviderProxy::openSession(std::string busName,
                                                                                               std::string objectPath,
                                                                                               std::string destination) {
  return (*m_method_openSession)(busName, objectPath, destination);

}
std::tuple<int32_t, std::string, std::string> com_xsembedded_ServiceProviderProxy::closeSession(int32_t sessionId) {
  return (*m_method_closeSession)(sessionId);

}
std::tuple<int32_t,
           std::string,
           std::string> com_xsembedded_ServiceProviderProxy::registerAudioStream(int32_t sessionId,
                                                                                 std::string streamName,
                                                                                 std::string streamModeName,
                                                                                 std::string streamType,
                                                                                 int32_t focusType) {
  return (*m_method_registerAudioStream)(sessionId, streamName, streamModeName, streamType, focusType);

}
std::tuple<int32_t, std::string, std::string> com_xsembedded_ServiceProviderProxy::requestAudioFocus(int32_t sessionId,
                                                                                                     int32_t requestType) {
  return (*m_method_requestAudioFocus)(sessionId, requestType);

}
std::tuple<int32_t, std::string, std::string> com_xsembedded_ServiceProviderProxy::abandonAudioFocus(int32_t sessionId,
                                                                                                     std::string reason) {
  return (*m_method_abandonAudioFocus)(sessionId, reason);

}
std::tuple<int32_t, std::string, std::string> com_xsembedded_ServiceProviderProxy::audioActive(int32_t sessionId,
                                                                                               int32_t playing) {
  return (*m_method_audioActive)(sessionId, playing);

}
std::tuple<int32_t, std::string, std::string> com_xsembedded_ServiceProviderProxy::setMode(int32_t sessionId,
                                                                                           std::string newMode,
                                                                                           std::string destination) {
  return (*m_method_setMode)(sessionId, newMode, destination);

}
DBus::MultipleReturn<std::string,
                     std::tuple<int32_t,
                                std::string,
                                std::string>> com_xsembedded_ServiceProviderProxy::getMode(int32_t sessionId,
                                                                                           std::string destination) {
  return (*m_method_getMode)(sessionId, destination);

}
DBus::MultipleReturn<std::tuple<std::vector<std::string>, int32_t>,
                     std::tuple<int32_t, std::string, std::string>> com_xsembedded_ServiceProviderProxy::getModeList(
    int32_t sessionId,
    std::string destination) {
  return (*m_method_getModeList)(sessionId, destination);

}
DBus::MultipleReturn<int32_t,
                     std::tuple<int32_t,
                                std::string,
                                std::string>> com_xsembedded_ServiceProviderProxy::enableStatus() {
  return (*m_method_enableStatus)();

}
std::tuple<int32_t, std::string, std::string> com_xsembedded_ServiceProviderProxy::enable(int32_t setAudioStatus) {
  return (*m_method_enable)(setAudioStatus);

}
std::shared_ptr<DBus::SignalProxy<void(std::string,
                                       std::string)>> com_xsembedded_ServiceProviderProxy::signal_Notify() {
  return m_signalproxy_Notify;

}
