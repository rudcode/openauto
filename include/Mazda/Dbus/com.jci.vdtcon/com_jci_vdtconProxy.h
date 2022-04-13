#ifndef COM_JCI_VDTCONPROXY_H
#define COM_JCI_VDTCONPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_vdtconProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_vdtconProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_vdtconProxy> create(std::string name = "com.jci.vdtcon");
  int32_t SelectMedia(int32_t mediaType);
  int32_t SelectMedia_Async(int32_t mediaType);
  int32_t Send(std::string srcFileName, std::string destFileName, Invalid sendParams);
  int32_t Send_Async(std::string srcFileName, std::string destFileName, Invalid sendParams);
  int32_t Delete(std::string fileName, std::tuple<int32_t, int32_t> deleteParams);
  int32_t Delete_Async(std::string fileName, std::tuple<int32_t, int32_t> deleteParams);
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t, int32_t, int32_t>)>> signal_MediaStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::string, std::tuple<int32_t>)>> signal_TransferRequest();
  std::shared_ptr<DBus::SignalProxy<void(std::string, std::tuple<int32_t>)>> signal_DeleteRequest();
  std::shared_ptr<DBus::SignalProxy<void(std::string, std::tuple<int32_t, int32_t>)>> signal_TransferResult();
  std::shared_ptr<DBus::SignalProxy<void(std::string, std::tuple<int32_t, int32_t>)>> signal_DeleteResult();
 protected:
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_SelectMedia;
  std::shared_ptr<DBus::MethodProxy<int32_t(int32_t)>> m_method_SelectMedia_Async;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::string, std::string, Invalid)>> m_method_Send;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::string, std::string, Invalid)>> m_method_Send_Async;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::string, std::tuple<int32_t, int32_t>)>> m_method_Delete;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::string, std::tuple<int32_t, int32_t>)>> m_method_Delete_Async;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<int32_t, int32_t, int32_t>)>> m_signalproxy_MediaStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::string, std::tuple<int32_t>)>> m_signalproxy_TransferRequest;
  std::shared_ptr<DBus::SignalProxy<void(std::string, std::tuple<int32_t>)>> m_signalproxy_DeleteRequest;
  std::shared_ptr<DBus::SignalProxy<void(std::string, std::tuple<int32_t, int32_t>)>> m_signalproxy_TransferResult;
  std::shared_ptr<DBus::SignalProxy<void(std::string, std::tuple<int32_t, int32_t>)>> m_signalproxy_DeleteResult;
};
#endif /* COM_JCI_VDTCONPROXY_H */
