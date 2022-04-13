#ifndef COM_JCI_AUDIOPLAYERPROXY_H
#define COM_JCI_AUDIOPLAYERPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_audioPlayerProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_audioPlayerProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_audioPlayerProxy> create(std::string name = "com.jci.audioPlayer");
  DBus::MultipleReturn<int32_t, int32_t> Open();
  DBus::MultipleReturn<int32_t, int32_t> OpenByName(std::string device);
  int32_t Close(int32_t client_id);
  int32_t PlaySync(int32_t client_id, std::string fileName, int32_t mode);
  int32_t PlayASync(int32_t client_id, std::string fileName, int32_t mode);
  int32_t AbortSync(int32_t client_id, std::string fileName, int32_t abort_type);
  int32_t AbortASync(int32_t client_id, std::string fileName, int32_t abort_type);
  std::shared_ptr<DBus::SignalProxy<void(int16_t, std::string)>> signal_Exception();
 protected:
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, int32_t>()>> m_method_Open;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, int32_t>(std::string)>> m_method_OpenByName;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_Close;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t, std::string, int32_t)>> m_method_PlaySync;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t, std::string, int32_t)>> m_method_PlayASync;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t, std::string, int32_t)>> m_method_AbortSync;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t, std::string, int32_t)>> m_method_AbortASync;
  std::shared_ptr<DBus::SignalProxy<void(int16_t, std::string)>> m_signalproxy_Exception;
};
#endif /* COM_JCI_AUDIOPLAYERPROXY_H */
