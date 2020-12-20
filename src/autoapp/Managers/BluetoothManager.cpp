#include <autoapp/Managers/BluetoothManager.hpp>

#include <easylogging++.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

BluetoothManager::BluetoothManager(autoapp::configuration::IConfiguration::Pointer configuration,
                                   DBus::Connection &serviceBus,
                                   DBus::Connection &hmiBus) : configuration_(std::move(configuration)) {
  LOG(DEBUG) << "Reading BdsConfiguration.xml";

  tinyxml2::XMLDocument doc;
  doc.LoadFile("/jci/bds/BdsConfiguration.xml");

  tinyxml2::XMLNode *docRoot = doc.FirstChild();

  tinyxml2::XMLElement *serviceconfig = docRoot->FirstChildElement("serviceConfiguration");

  if (serviceconfig == nullptr) {
    LOG(DEBUG) << "Couldn't find serviceConfiguration in /jci/bds/BdsConfiguration.xml";
  } else {
    for (tinyxml2::XMLElement *e = serviceconfig->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
      if (std::string(e->Attribute("name")) == "AndroidAuto") {
        LOG(INFO) << "BDSCONFIG: AndroidAuto Entry found";
        bdsconfigured = true;
        serviceId = e->IntAttribute("id");
      }
      LOG(DEBUG) << "BDSCONFIG: " << e->Attribute("name");
    }
  }

  if (bdsconfigured) {
    bdsClient = new BDSClient(serviceBus);
    bcaClient = new BCAClient(hmiBus);
    bdsClient->serviceID = serviceId;
    bdsClient->wifiPort = configuration_->wifiPort();
    bcaClient->serviceID = serviceId;
    bcaClient->wifiPort = configuration_->wifiPort();
    bcaClient->StartAdd(serviceId);
  }

}

void BluetoothConnection::sendMessage(google::protobuf::MessageLite &message, uint16_t type) const {
  auto byteSize = static_cast<size_t>(message.ByteSizeLong());
  auto sizeOut = static_cast<uint16_t>(htobe16(byteSize));
  auto typeOut = static_cast<uint16_t>(htobe16(type));
  auto *out = new char[byteSize + 4];
  memcpy(out, &sizeOut, 2);
  memcpy(out + 2, &typeOut, 2);

  message.SerializeToArray(out + 4, byteSize);

  auto written = write(fd, out, byteSize + 4);
  if (written > -1) {
    LOG(DEBUG) << "Bytes written: " << written;
  } else {
    LOG(DEBUG) << "Could not write data";
  }
  delete[] out;
}

void BluetoothConnection::handleWifiInfoRequest(uint8_t *buffer, uint16_t length) {
  aasdk::proto::messages::WifiInfoRequest msg;
  msg.ParseFromArray(buffer, length);
  LOG(DEBUG) << "WifiInfoRequest: " << msg.DebugString();

  aasdk::proto::messages::WifiInfoResponse response;
  response.set_ip_address(info.ipAddress.c_str());
  response.set_port(port_);
  response.set_status(aasdk::proto::messages::WifiInfoResponse_Status_STATUS_SUCCESS);

  sendMessage(response, 7);
}

void BluetoothConnection::handleWifiSecurityRequest(__attribute__((unused)) uint8_t *buffer,
                                                    __attribute__((unused)) uint16_t length) {
  aasdk::proto::messages::WifiSecurityReponse response;

  response.set_ssid(hostapd_config("ssid").c_str());
  response.set_bssid(info.macAddress.c_str());
  response.set_key(hostapd_config("wpa_passphrase").c_str());
  response.set_security_mode(aasdk::proto::messages::WifiSecurityReponse_SecurityMode_WPA2_PERSONAL);
  response.set_access_point_type(aasdk::proto::messages::WifiSecurityReponse_AccessPointType_DYNAMIC);

  sendMessage(response, 3);
}

int BluetoothConnection::handleWifiInfoRequestResponse(uint8_t *buffer, uint16_t length) {
  aasdk::proto::messages::WifiInfoResponse msg;
  msg.ParseFromArray(buffer, length);
  LOG(DEBUG) << "WifiInfoResponse: " << msg.DebugString();
  return msg.status();
}

BluetoothConnection::BluetoothConnection(int port) : port_(port) {
  update_connection_info(info);
  LOG(DEBUG) << "Got IP: " << info.ipAddress << " MAC: " << info.macAddress;

}

void BluetoothConnection::handle_connect(const std::string &pty) {
  char buf[100];
  LOG(DEBUG) << "PTY: " << pty;
  fd = open(pty.c_str(), O_RDWR | O_NOCTTY | O_SYNC);
  aasdk::proto::messages::WifiInfoRequest request;
  request.set_ip_address(info.ipAddress.c_str());
  request.set_port(port_);

  sendMessage(request, 1);

  ssize_t len = 0;
  int loop = 1;
  while (loop) {
    ssize_t i = read(fd, buf, 4);
    len += i;
    if (len >= 4) {
      auto size = static_cast<uint16_t>(be16toh(*(uint16_t *) buf));
      auto type = static_cast<uint16_t>(be16toh(*(uint16_t *) (buf + 2)));
      LOG(DEBUG) << "Size: " << size << " MessageID: " << type;
      if (len >= size + 4) {
        auto *buffer = new uint8_t[size];
        i = 0;
        while (i < size) {
          i += read(fd, buffer, size);
        }
        switch (type) {
          case 1:handleWifiInfoRequest(buffer, size);
            break;
          case 2:handleWifiSecurityRequest(buffer, size);
            break;
          case 7:
            if (handleWifiInfoRequestResponse(buffer, size) == 0) {
              loop = 0;
            }
            break;
          default:loop = 0;
            break;
        }
        delete[] buffer;
      }
    }
  }
}

void BCAClient::ConnectionStatusResp(
    const uint32_t &serviceId,
    const uint32_t &connStatus,
    const uint32_t &btDeviceId,
    const uint32_t &status,
    const ::DBus::Struct<std::vector<uint8_t>> &terminalPath) {
  LOG(DEBUG) << "Saw Service: " << serviceId;
  if (static_cast<int>(serviceId) == serviceID && connStatus == 3) {
    std::string pty(terminalPath._1.begin(), terminalPath._1.end());
    LOG(DEBUG) << "PTY: " << pty;
    BluetoothConnection connection(wifiPort);
    connection.handle_connect(pty);
  }
}

void BDSClient::SignalConnected_cb(const uint32_t &type, const ::DBus::Struct<std::vector<uint8_t>> &data) {
  printf("Saw Service: %u", data._1[36]);
  if (data._1[36] == serviceID) {
    std::string pty((char *) &data._1[48]);
    LOG(DEBUG) << "PTY: " << pty;
    BluetoothConnection connection(wifiPort);
    connection.handle_connect(pty);
  }
}

std::string hostapd_config(const std::string &key) {
  std::ifstream hostapd_file;
  hostapd_file.open("/tmp/current-session-hostapd.conf");

  if (hostapd_file) {
    std::string line;
    size_t pos;
    while (hostapd_file.good()) {
      getline(hostapd_file, line); // get line from file
      if (line[0] != '#') {
        pos = line.find(key); // search
        if (pos != std::string::npos) // string::npos is returned if string is not found
        {
          size_t equalPosition = line.find('=');
          std::string value = line.substr(equalPosition + 1);
          return value;
        }
      }
    }
    return "";
  } else {
    return "";
  }
}

int update_connection_info(connectionInfo &info) {
  int fd;
  struct ifreq ifr{};
  char iface[] = "wlan0";
  unsigned char *mac;

  fd = socket(AF_INET, SOCK_DGRAM, 0);

  ifr.ifr_addr.sa_family = AF_INET;
  strncpy(ifr.ifr_name, iface, IFNAMSIZ - 1);

  ioctl(fd, SIOCGIFHWADDR, &ifr);
  mac = (unsigned char *) ifr.ifr_hwaddr.sa_data;
  info.macAddress.resize(18);
  sprintf(&info.macAddress[0], "%.2x:%.2x:%.2x:%.2x:%.2x:%.2x", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
  ioctl(fd, SIOCGIFADDR, &ifr);
  info.ipAddress = inet_ntoa(((struct sockaddr_in *) &ifr.ifr_addr)->sin_addr);

  close(fd);

  return 0;
}