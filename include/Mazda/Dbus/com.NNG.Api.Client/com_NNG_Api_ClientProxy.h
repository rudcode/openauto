#ifndef COM_NNG_API_CLIENTPROXY_H
#define COM_NNG_API_CLIENTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_NNG_Api_ClientProxy
    : public DBus::InterfaceProxy {
 protected:
  com_NNG_Api_ClientProxy(std::string name);
 public:
  static std::shared_ptr<com_NNG_Api_ClientProxy> create(std::string name = "com.NNG.Api.Client");
  std::shared_ptr<DBus::SignalProxy<void()>> signal_DBusClientStarted();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_DBusClientStopped();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_ReadyToDie();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_HeartBeat();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_SDCardSeemsOK();
  std::shared_ptr<DBus::SignalProxy<void(std::string, int32_t, int32_t)>> signal_SDCardProblem();
  std::shared_ptr<DBus::SignalProxy<void(std::string)>> signal_InternalFileError();
 protected:
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_DBusClientStarted;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_DBusClientStopped;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_ReadyToDie;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_HeartBeat;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_SDCardSeemsOK;
  std::shared_ptr<DBus::SignalProxy<void(std::string, int32_t, int32_t)>> m_signalproxy_SDCardProblem;
  std::shared_ptr<DBus::SignalProxy<void(std::string)>> m_signalproxy_InternalFileError;
};
#endif /* COM_NNG_API_CLIENTPROXY_H */
