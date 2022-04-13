#ifndef COM_JCI_ITTPROXY_H
#define COM_JCI_ITTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_ittProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_ittProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_ittProxy> create(std::string name = "com.jci.itt");
  std::tuple<std::vector<std::tuple<int32_t, uint32_t, std::string>>, uint32_t> RequestMemoryInfo();
  DBus::MultipleReturn<int32_t,
                       std::tuple<std::vector<std::tuple<int32_t, uint32_t, std::string>>, uint32_t>> ProcessTag();
  int32_t GetTaggingAvailability();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_TaggingAvailable();
  std::shared_ptr<DBus::SignalProxy<void(int32_t,
                                         std::tuple<std::vector<std::tuple<int32_t, uint32_t, std::string>>,
                                                    uint32_t>)>> signal_TagTransfer();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_TaggingErrorDevice();
 protected:
  std::shared_ptr<DBus::MethodProxy<std::tuple<std::vector<std::tuple<int32_t, uint32_t, std::string>>, uint32_t>()>>
      m_method_RequestMemoryInfo;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t,
                                                         std::tuple<std::vector<std::tuple<int32_t,
                                                                                           uint32_t,
                                                                                           std::string>>, uint32_t>>()>>
      m_method_ProcessTag;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetTaggingAvailability;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_TaggingAvailable;
  std::shared_ptr<DBus::SignalProxy<void(int32_t,
                                         std::tuple<std::vector<std::tuple<int32_t, uint32_t, std::string>>,
                                                    uint32_t>)>> m_signalproxy_TagTransfer;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_TaggingErrorDevice;
};
#endif /* COM_JCI_ITTPROXY_H */
