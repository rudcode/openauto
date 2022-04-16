#include "com_xsembedded_ServiceProviderInterface.h"

com_xsembedded_ServiceProviderInterface::com_xsembedded_ServiceProviderInterface(com_xsembedded_ServiceProvider *adaptee,
                                                                                 std::string name) : DBus::Interface(
    name) {
  this->create_method<std::string(std::string, std::string)>("Request",
                                                             sigc::mem_fun(*adaptee,
                                                                           &com_xsembedded_ServiceProvider::Request));
  this->create_method<DBus::MultipleReturn<int32_t, std::tuple<int32_t, std::string, std::string>>(std::string,
                                                                                                   std::string,
                                                                                                   std::string)>(
      "openSession",
      sigc::mem_fun(*adaptee, &com_xsembedded_ServiceProvider::openSession));
  this->create_method<std::tuple<int32_t, std::string, std::string>(int32_t)>("closeSession",
                                                                              sigc::mem_fun(*adaptee,
                                                                                            &com_xsembedded_ServiceProvider::closeSession));
  this->create_method<std::tuple<int32_t, std::string, std::string>(int32_t,
                                                                    std::string,
                                                                    std::string,
                                                                    std::string,
                                                                    int32_t)>("registerAudioStream",
                                                                              sigc::mem_fun(*adaptee,
                                                                                            &com_xsembedded_ServiceProvider::registerAudioStream));
  this->create_method<std::tuple<int32_t, std::string, std::string>(int32_t, int32_t)>("requestAudioFocus",
                                                                                       sigc::mem_fun(*adaptee,
                                                                                                     &com_xsembedded_ServiceProvider::requestAudioFocus));
  this->create_method<std::tuple<int32_t, std::string, std::string>(int32_t, std::string)>("abandonAudioFocus",
                                                                                           sigc::mem_fun(*adaptee,
                                                                                                         &com_xsembedded_ServiceProvider::abandonAudioFocus));
  this->create_method<std::tuple<int32_t, std::string, std::string>(int32_t, int32_t)>("audioActive",
                                                                                       sigc::mem_fun(*adaptee,
                                                                                                     &com_xsembedded_ServiceProvider::audioActive));
  this->create_method<std::tuple<int32_t, std::string, std::string>(int32_t, std::string, std::string)>("setMode",
                                                                                                        sigc::mem_fun(*adaptee,
                                                                                                                      &com_xsembedded_ServiceProvider::setMode));
  this->create_method<DBus::MultipleReturn<std::string, std::tuple<int32_t, std::string, std::string>>(int32_t,
                                                                                                       std::string)>(
      "getMode",
      sigc::mem_fun(*adaptee, &com_xsembedded_ServiceProvider::getMode));
  this->create_method<DBus::MultipleReturn<std::tuple<std::vector<std::string>, int32_t>,
                                           std::tuple<int32_t, std::string, std::string>>(int32_t, std::string)>(
      "getModeList",
      sigc::mem_fun(*adaptee, &com_xsembedded_ServiceProvider::getModeList));
  this->create_method<DBus::MultipleReturn<int32_t, std::tuple<int32_t, std::string, std::string>>()>("enableStatus",
                                                                                                      sigc::mem_fun(*adaptee,
                                                                                                                    &com_xsembedded_ServiceProvider::enableStatus));
  this->create_method<std::tuple<int32_t, std::string, std::string>(int32_t)>("enable",
                                                                              sigc::mem_fun(*adaptee,
                                                                                            &com_xsembedded_ServiceProvider::enable));
  m_signal_Notify = create_signal<void(std::string, std::string)>("Notify");

}
std::shared_ptr<com_xsembedded_ServiceProviderInterface> com_xsembedded_ServiceProviderInterface::create(
    com_xsembedded_ServiceProvider *adaptee,
    std::string name) {
  return std::shared_ptr<com_xsembedded_ServiceProviderInterface>(new com_xsembedded_ServiceProviderInterface(adaptee,
                                                                                                              name));

}
std::shared_ptr<DBus::Signal<void(std::string, std::string)>> com_xsembedded_ServiceProviderInterface::signal_Notify() {
  return m_signal_Notify;

}
void com_xsembedded_ServiceProviderInterface::Notify(std::string signalName, std::string payload) {
  (*m_signal_Notify)(signalName, payload);

}
