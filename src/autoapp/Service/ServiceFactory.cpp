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

#include <f1x/aasdk/Channel/AV/MediaAudioServiceChannel.hpp>
#include <f1x/openauto/autoapp/Service/ServiceFactory.hpp>
#include <f1x/openauto/autoapp/Service/VideoService.hpp>
#include <f1x/openauto/autoapp/Service/MediaAudioService.hpp>
#include <f1x/openauto/autoapp/Service/SpeechAudioService.hpp>
#include <f1x/openauto/autoapp/Service/AudioInputService.hpp>
#include <f1x/openauto/autoapp/Service/SensorService.hpp>
#include <f1x/openauto/autoapp/Service/BluetoothService.hpp>
#include <f1x/openauto/autoapp/Service/InputService.hpp>
#include <f1x/openauto/autoapp/Projection/GSTVideoOutput.hpp>
#include <f1x/openauto/autoapp/Projection/AlsaAudio.hpp>
#include <f1x/openauto/autoapp/Projection/AlsaAudioInput.hpp>
#include <f1x/openauto/autoapp/Projection/InputDevice.hpp>
#include <f1x/openauto/autoapp/Projection/MazdaBluetooth.hpp>
#include <f1x/openauto/autoapp/Service/SystemAudioService.hpp>


namespace f1x
{
namespace openauto
{
namespace autoapp
{
namespace service
{

ServiceFactory::ServiceFactory(asio::io_service& ioService, configuration::IConfiguration::Pointer configuration, Signals::Pointer signals)
    : ioService_(ioService)
    , configuration_(std::move(configuration))
    , signals_(std::move(signals))
{

}

ServiceList ServiceFactory::create(aasdk::messenger::IMessenger::Pointer messenger)
{
    ServiceList serviceList;

    projection::IAudioInput::Pointer audioInput(new projection::AlsaAudioInput());
    serviceList.emplace_back(std::make_shared<AudioInputService>(ioService_, messenger, std::move(audioInput)));
    this->createAudioServices(serviceList, messenger);
    serviceList.emplace_back(std::make_shared<SensorService>(ioService_, messenger));
    serviceList.emplace_back(this->createVideoService(messenger));
    serviceList.emplace_back(this->createBluetoothService(messenger));
    serviceList.emplace_back(this->createInputService(messenger));
//    serviceList.emplace_back(std::make_shared<WifiService>(configuration_));

    return serviceList;
}

IService::Pointer ServiceFactory::createVideoService(aasdk::messenger::IMessenger::Pointer messenger)
{
    projection::IVideoOutput::Pointer videoOutput(new projection::GSTVideoOutput());
    return std::make_shared<VideoService>(ioService_, messenger, std::move(videoOutput), signals_->videoSignals);
}

IService::Pointer ServiceFactory::createBluetoothService(aasdk::messenger::IMessenger::Pointer messenger)
{
    projection::IBluetoothDevice::Pointer bluetoothDevice;
    bluetoothDevice = std::make_shared<projection::MazdaBluetooth>();

    return std::make_shared<BluetoothService>(ioService_, messenger, std::move(bluetoothDevice));
}

IService::Pointer ServiceFactory::createInputService(aasdk::messenger::IMessenger::Pointer messenger)
{

    projection::IInputDevice::Pointer inputDevice(std::make_shared<projection::InputDevice>());

    return std::make_shared<InputService>(ioService_, messenger, std::move(inputDevice));
}

void ServiceFactory::createAudioServices(ServiceList& serviceList, aasdk::messenger::IMessenger::Pointer messenger)
{
    auto mediaAudioOutput = std::make_shared<projection::AlsaAudioOutput>(2, 48000, "entertainmentMl");
    serviceList.emplace_back(std::make_shared<MediaAudioService>(ioService_, messenger, std::move(mediaAudioOutput)));

    auto speechAudioOutput = std::make_shared<projection::AlsaAudioOutput>(1, 16000, "entertainmentMl");
    serviceList.emplace_back(std::make_shared<SpeechAudioService>(ioService_, messenger, std::move(speechAudioOutput)));


    auto systemAudioOutput = std::make_shared<projection::AlsaAudioOutput>(1, 16000, "entertainmentMl");
    serviceList.emplace_back(std::make_shared<SystemAudioService>(ioService_, messenger, std::move(systemAudioOutput)));
}

}
}
}
}
