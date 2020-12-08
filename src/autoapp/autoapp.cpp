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

#include <dbus-c++/dbus.h>

#include <aasdk/USB/USBHub.hpp>
#include <aasdk/USB/ConnectedAccessoriesEnumerator.hpp>
#include <aasdk/USB/AccessoryModeQueryChain.hpp>
#include <aasdk/USB/AccessoryModeQueryChainFactory.hpp>
#include <aasdk/USB/AccessoryModeQueryFactory.hpp>
#include <aasdk/TCP/TCPWrapper.hpp>
#include <f1x/openauto/autoapp/App.hpp>
#include <f1x/openauto/autoapp/Configuration/IConfiguration.hpp>
#include <f1x/openauto/autoapp/Service/AndroidAutoEntityFactory.hpp>
#include <f1x/openauto/autoapp/Service/ServiceFactory.hpp>
#include <easylogging++.h>
#include <f1x/openauto/autoapp/Managers/VideoManager.hpp>
#include <f1x/openauto/autoapp/Managers/AudioManager.hpp>


namespace aasdk = aasdk;
namespace autoapp = f1x::openauto::autoapp;
using ThreadPool = std::vector<std::thread>;

void startUSBWorkers(asio::io_service& ioService, libusb_context* usbContext, ThreadPool& threadPool)
{
    auto usbWorker = [&ioService, usbContext]() {
        timeval libusbEventTimeout{180, 0};

        while(!ioService.stopped())
        {
            libusb_handle_events_timeout_completed(usbContext, &libusbEventTimeout, nullptr);
        }
    };

    threadPool.emplace_back(usbWorker);
    threadPool.emplace_back(usbWorker);
    threadPool.emplace_back(usbWorker);
    threadPool.emplace_back(usbWorker);
}

void startIOServiceWorkers(asio::io_service& ioService, ThreadPool& threadPool)
{
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

DBus::BusDispatcher dispatcher;

void dbus_dispatcher() {
    dispatcher.enter();
}

INITIALIZE_EASYLOGGINGPP

bool running = true;

void signalHandler( int signum ) {
    running = false;
}

int main(int argc, char* argv[])
{
    el::Configurations defaultConf;
    defaultConf.setToDefault();
    // Values are always std::string
    defaultConf.set(el::Level::Info,
                    el::ConfigurationType::Format, "%datetime %levshort [%fbase] %msg");
    defaultConf.set(el::Level::Debug,
                    el::ConfigurationType::Format, "%datetime %levshort [%fbase] [%func] %msg");
    defaultConf.set(el::Level::Error,
                    el::ConfigurationType::Format, "%datetime %levshort [%fbase] [%func] %msg");
    // default logger uses default configurations
    el::Loggers::reconfigureLogger("default", defaultConf);


    LOG(INFO) << "[OpenAuto] starting";
    signal(SIGINT, signalHandler);
    libusb_context* usbContext;
    if(libusb_init(&usbContext) != 0)
    {
        LOG(ERROR) << "[OpenAuto] libusb init failed.";
        return 1;
    }

#define HMI_BUS_ADDRESS "unix:path=/tmp/dbus_hmi_socket"
#define SERVICE_BUS_ADDRESS "unix:path=/tmp/dbus_service_socket"
    DBus::default_dispatcher = &dispatcher;
    DBus::Connection hmiBus(HMI_BUS_ADDRESS, true);
    hmiBus.register_bus();
    DBus::Connection serviceBus(SERVICE_BUS_ADDRESS, true);
    serviceBus.register_bus();


    asio::io_service ioService;
    asio::io_service::work work(ioService);
    std::vector<std::thread> threadPool;
    startUSBWorkers(ioService, usbContext, threadPool);
    startIOServiceWorkers(ioService, threadPool);

    auto configuration = nullptr;
    auto signals = std::make_shared<Signals>();

    AudioManagerClient audioManager(serviceBus, signals->audioSignals);
    VideoManager videoManager(hmiBus, signals->videoSignals);
    std::thread dbus_thread(dbus_dispatcher);

    aasdk::tcp::TCPWrapper tcpWrapper;

    aasdk::usb::USBWrapper usbWrapper(usbContext);
    aasdk::usb::AccessoryModeQueryFactory queryFactory(usbWrapper, ioService);
    aasdk::usb::AccessoryModeQueryChainFactory queryChainFactory(usbWrapper, ioService, queryFactory);
    autoapp::service::ServiceFactory serviceFactory(ioService, configuration, signals);
    autoapp::service::AndroidAutoEntityFactory androidAutoEntityFactory(ioService, configuration, serviceFactory, signals);
    auto usbHub(std::make_shared<aasdk::usb::USBHub>(usbWrapper, ioService, queryChainFactory));
    auto connectedAccessoriesEnumerator(std::make_shared<aasdk::usb::ConnectedAccessoriesEnumerator>(usbWrapper, ioService, queryChainFactory));
    auto app = std::make_shared<autoapp::App>(ioService, usbWrapper, tcpWrapper, androidAutoEntityFactory, std::move(usbHub), std::move(connectedAccessoriesEnumerator));

    app->waitForUSBDevice();

    while(running){
        sleep(1);
    }

    LOG(DEBUG) << "Calling app->stop()";
    app->stop();
    sleep(5);
    LOG(DEBUG) << "Calling dispatcher.leave()";
    dispatcher.leave();
    LOG(DEBUG) << "Calling dbus_thread.join()";
    dbus_thread.join();
    LOG(DEBUG) << "Joining threads";
    std::for_each(threadPool.begin(), threadPool.end(), [](std::thread &thread){thread.join();});
    LOG(DEBUG) << "libusb_exit(usbContext)";
    libusb_exit(usbContext);
    return 0;
}
