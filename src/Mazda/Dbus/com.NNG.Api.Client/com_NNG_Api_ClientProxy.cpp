#include "com_NNG_Api_ClientProxy.h"

com_NNG_Api_ClientProxy::com_NNG_Api_ClientProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_signalproxy_DBusClientStarted = this->create_signal<void()>("DBusClientStarted");
  m_signalproxy_DBusClientStopped = this->create_signal<void()>("DBusClientStopped");
  m_signalproxy_ReadyToDie = this->create_signal<void()>("ReadyToDie");
  m_signalproxy_HeartBeat = this->create_signal<void()>("HeartBeat");
  m_signalproxy_SDCardSeemsOK = this->create_signal<void()>("SDCardSeemsOK");
  m_signalproxy_SDCardProblem = this->create_signal<void(std::string, int32_t, int32_t)>("SDCardProblem");
  m_signalproxy_InternalFileError = this->create_signal<void(std::string)>("InternalFileError");

}
std::shared_ptr <com_NNG_Api_ClientProxy> com_NNG_Api_ClientProxy::create(std::string name) {
  return std::shared_ptr<com_NNG_Api_ClientProxy>(new com_NNG_Api_ClientProxy(name));

}
std::shared_ptr <DBus::SignalProxy<void()>> com_NNG_Api_ClientProxy::signal_DBusClientStarted() {
  return m_signalproxy_DBusClientStarted;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_NNG_Api_ClientProxy::signal_DBusClientStopped() {
  return m_signalproxy_DBusClientStopped;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_NNG_Api_ClientProxy::signal_ReadyToDie() {
  return m_signalproxy_ReadyToDie;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_NNG_Api_ClientProxy::signal_HeartBeat() {
  return m_signalproxy_HeartBeat;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_NNG_Api_ClientProxy::signal_SDCardSeemsOK() {
  return m_signalproxy_SDCardSeemsOK;

}
std::shared_ptr <DBus::SignalProxy<void(std::string,
                                        int32_t,
                                        int32_t)>> com_NNG_Api_ClientProxy::signal_SDCardProblem() {
  return m_signalproxy_SDCardProblem;

}
std::shared_ptr <DBus::SignalProxy<void(std::string)>> com_NNG_Api_ClientProxy::signal_InternalFileError() {
  return m_signalproxy_InternalFileError;

}
