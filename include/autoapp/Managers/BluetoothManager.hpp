#pragma once

#include <sdbus-c++/sdbus-c++.h>
#include <atomic>
#include <set>

#include <string>
#include <future>

#include <tinyxml2.h>

#include <aasdk_proto/WifiInfoRequestMessage.pb.h>
#include <aasdk_proto/WifiInfoResponseMessage.pb.h>
#include <aasdk_proto/WifiSecurityResponseMessage.pb.h>

#include <autoapp/Configuration/IConfiguration.hpp>

class BluetoothManager {
 public:
  explicit BluetoothManager(autoapp::configuration::IConfiguration::Pointer configuration);
  ~BluetoothManager();
 private:
  autoapp::configuration::IConfiguration::Pointer configuration_;
  bool bdsconfigured = false;
  uint32_t serviceId = 0;
  std::unique_ptr<sdbus::IProxy> bdsClient;
  std::unique_ptr<sdbus::IProxy> bcaClient;

};

struct connectionInfo {
  std::string ipAddress;
  std::string macAddress;
};

int update_connection_info(connectionInfo &info);

class BluetoothConnection {
 public:
  explicit BluetoothConnection(autoapp::configuration::IConfiguration::Pointer configuration);
  void handle_connect(const std::string &pty);

 private:
  int fd = 0;
  connectionInfo info;
  autoapp::configuration::IConfiguration::Pointer configuration_;

  void handleWifiInfoRequest(uint8_t *buffer, uint16_t length);
  void handleWifiSecurityRequest(__attribute__((unused)) uint8_t *buffer, __attribute__((unused)) uint16_t length);
  static int handleWifiInfoRequestResponse(uint8_t *buffer, uint16_t length);
  void sendMessage(google::protobuf::MessageLite &message, uint16_t type) const;
};