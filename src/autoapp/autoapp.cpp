/*
*  This file is part of openauto project.
*  Copyright (C) 2018 f1x.studio (Michal Szwaj)
*
*  openauto is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 3 of the License, or
*  (at your option) any later version.

*  openauto is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with openauto. If not, see <http://www.gnu.org/licenses/>.
*/

#include <thread>

#include <sdbus-c++/sdbus-c++.h>

#include <aasdk/USB/USBHub.hpp>
#include <aasdk/USB/ConnectedAccessoriesEnumerator.hpp>
#include <aasdk/USB/AccessoryModeQueryChain.hpp>
#include <aasdk/USB/AccessoryModeQueryChainFactory.hpp>
#include <aasdk/USB/AccessoryModeQueryFactory.hpp>
#include <aasdk/TCP/TCPWrapper.hpp>
#include <autoapp/App.hpp>
#include <autoapp/Configuration/IConfiguration.hpp>
#include <autoapp/Service/AndroidAutoEntityFactory.hpp>
#include <autoapp/Service/ServiceFactory.hpp>
#include <easylogging++.h>
#include <autoapp/Managers/VideoManager.hpp>
#include <autoapp/Managers/AudioManager.hpp>
//#include <autoapp/Managers/GPSManager.hpp>
#include <autoapp/Managers/HttpManager.hpp>
#include <autoapp/Managers/BluetoothManager.hpp>
#include <autoapp/Configuration/Configuration.hpp>

using ThreadPool = std::vector<std::thread>;

void startUSBWorkers(asio::io_service &ioService, libusb_context *usbContext, ThreadPool &threadPool) {
  auto usbWorker = [&ioService, usbContext]() {
    timeval libusbEventTimeout{10, 0};

    while (!ioService.stopped()) {
      libusb_handle_events_timeout_completed(usbContext, &libusbEventTimeout, nullptr);
    }
  };

  threadPool.emplace_back(usbWorker);
  threadPool.emplace_back(usbWorker);
  threadPool.emplace_back(usbWorker);
  threadPool.emplace_back(usbWorker);
}

void startIOServiceWorkers(asio::io_service &ioService, ThreadPool &threadPool) {
  auto ioServiceWorker = [&ioService]() {
    ioService.run();
  };

  threadPool.emplace_back(ioServiceWorker);
  threadPool.emplace_back(ioServiceWorker);
  threadPool.emplace_back(ioServiceWorker);
  threadPool.emplace_back(ioServiceWorker);
  threadPool.emplace_back(ioServiceWorker);
  threadPool.emplace_back(ioServiceWorker);
  threadPool.emplace_back(ioServiceWorker);
  threadPool.emplace_back(ioServiceWorker);
}

INITIALIZE_EASYLOGGINGPP

bool running = true;

void signalHandler(int signum) {
  if (signum == SIGINT) {
    running = false;
  }
}

int main(int argc, char *argv[]) {
  /* Do some Mazda Specific Setup */
  setenv("DBUS_SYSTEM_BUS_ADDRESS", "unix:path=/tmp/dbus_service_socket", true);
  setenv("DBUS_SESSION_BUS_ADDRESS", "unix:path=/tmp/dbus_hmi_socket", true);

  int fd;
  fd = open("/sys/bus/usb/devices/usb1/authorized_default", O_WRONLY);
  write(fd, "1", 1);
  close(fd);
  fd = open("/sys/bus/usb/devices/usb2/authorized_default", O_WRONLY);
  write(fd, "1", 1);
  close(fd);

  /*                              */

  auto configuration = std::make_shared<autoapp::configuration::Configuration>();

  el::Configurations defaultConf;
  defaultConf.setToDefault();
  el::Loggers::addFlag(el::LoggingFlag::HierarchicalLogging);
  if (!configuration->logFile().empty()) {
    defaultConf.set(el::Level::Global, el::ConfigurationType::Filename, configuration->logFile());
    defaultConf.set(el::Level::Global, el::ConfigurationType::ToFile, "true");
    defaultConf.set(el::Level::Global, el::ConfigurationType::ToStandardOutput, "false");
  }
  // Values are always std::string
  defaultConf.set(el::Level::Info,
                  el::ConfigurationType::Format, "%datetime %levshort [%fbase] %msg");
  defaultConf.set(el::Level::Debug,
                  el::ConfigurationType::Format, "%datetime %levshort [%fbase] [%func] %msg");
  defaultConf.set(el::Level::Error,
                  el::ConfigurationType::Format, "%datetime %levshort [%fbase] [%func] %msg");
  // default logger uses default configurations
  el::Loggers::reconfigureLogger("default", defaultConf);
  el::Loggers::setLoggingLevel(configuration->logLevel());

  LOG(INFO) << "[OpenAuto] starting";
  signal(SIGINT, signalHandler);
  libusb_context *usbContext;
  if (libusb_init(&usbContext) != 0) {
    LOG(ERROR) << "[OpenAuto] libusb init failed.";
    return 1;
  }

  asio::io_service ioService;
  asio::io_service::work work(ioService);
  std::vector<std::thread> threadPool;
  startUSBWorkers(ioService, usbContext, threadPool);
  startIOServiceWorkers(ioService, threadPool);

  Signals signals = Signals();

  auto *audioManager = new AudioManagerClient("com.xsembedded.service.AudioManagement",
                                              "/com/xse/service/AudioManagement/AudioApplication",
                                              signals.audioSignals);
  VideoManager videoManager(signals.videoSignals);
//  GPSManager gpsManager(serviceBus, signals.gpsSignals);
  HttpManager httpManager(ioService, signals.videoSignals, signals.audioSignals, signals.aaSignals);

  aasdk::tcp::TCPWrapper tcpWrapper;

  aasdk::usb::USBWrapper usbWrapper(usbContext);
  aasdk::usb::AccessoryModeQueryFactory queryFactory(usbWrapper, ioService);
  aasdk::usb::AccessoryModeQueryChainFactory queryChainFactory(usbWrapper, ioService, queryFactory);
  autoapp::service::ServiceFactory serviceFactory(ioService, configuration, signals);
  autoapp::service::AndroidAutoEntityFactory
      androidAutoEntityFactory(ioService, configuration, serviceFactory, signals);
  auto usbHub(std::make_shared<aasdk::usb::USBHub>(usbWrapper, ioService, queryChainFactory));
  auto connectedAccessoriesEnumerator
      (std::make_shared<aasdk::usb::ConnectedAccessoriesEnumerator>(usbWrapper, ioService, queryChainFactory));
  auto app = std::make_shared<autoapp::App>(ioService,
                                            usbWrapper,
                                            tcpWrapper,
                                            androidAutoEntityFactory,
                                            std::move(usbHub),
                                            std::move(connectedAccessoriesEnumerator),
                                            configuration->wifiPort());

  app->waitForUSBDevice();

  // This needs to happen after the rest of openauto is setup, so it goes here.
  BluetoothManager bluetoothManager(configuration);

  while (running) {
    sleep(1);
  }

  LOG(DEBUG) << "Calling app->stop()";
  app->stop();
  LOG(DEBUG) << "Stopping BluetoothManager";
  bluetoothManager.stop();
  LOG(DEBUG) << "Stopping HttpManager";
  httpManager.stop();
//  LOG(DEBUG) << "Stopping GPSManager";
//  gpsManager.stop();
  LOG(DEBUG) << "Stopping AudioManager";
  delete audioManager;
  LOG(DEBUG) << "Stopping VideoManager";
  videoManager.stop();
  LOG(DEBUG) << "Stopping ioService";
  ioService.stop();
  LOG(DEBUG) << "Joining threads";
  std::for_each(threadPool.begin(), threadPool.end(), [](std::thread &thread) { thread.join(); });
  LOG(DEBUG) << "libusb_exit(usbContext)";
  libusb_exit(usbContext);
  return 0;
}
