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

#include <easylogging++.h>
#include <autoapp/Service/BluetoothService.hpp>

namespace autoapp::service {

BluetoothService::BluetoothService(asio::io_service &ioService,
                                   aasdk::messenger::IMessenger::Pointer messenger,
                                   projection::IBluetoothDevice::Pointer bluetoothDevice)
    : strand_(ioService),
      channel_(std::make_shared<aasdk::channel::bluetooth::BluetoothServiceChannel>(strand_, std::move(messenger))),
      bluetoothDevice_(std::move(bluetoothDevice)) {

}

void BluetoothService::start() {
  strand_.dispatch([this, self = this->shared_from_this()]() {
    LOG(INFO) << "[BluetoothService] start.";
    channel_->receive(this->shared_from_this());
  });
}

void BluetoothService::stop() {
  strand_.dispatch([this, self = this->shared_from_this()]() {
    LOG(INFO) << "[BluetoothService] stop.";
    bluetoothDevice_->stop();
  });
}

void BluetoothService::pause() {
  strand_.dispatch([this, self = this->shared_from_this()]() {
    LOG(INFO) << "[BluetoothService] pause.";
  });
}

void BluetoothService::resume() {
  strand_.dispatch([this, self = this->shared_from_this()]() {
    LOG(INFO) << "[BluetoothService] resume.";
  });
}

void BluetoothService::fillFeatures(aasdk::proto::messages::ServiceDiscoveryResponse &response) {
  LOG(INFO) << "[BluetoothService] fill features";

  if (bluetoothDevice_->isAvailable()) {
    LOG(INFO) << "[BluetoothService] sending local adapter adress: " << bluetoothDevice_->getLocalAddress();

    auto *channelDescriptor = response.add_channels();
    channelDescriptor->set_channel_id(static_cast<uint32_t>(channel_->getId()));
    auto *bluetoothChannel = channelDescriptor->mutable_bluetooth_channel();
    bluetoothChannel->set_adapter_address(bluetoothDevice_->getLocalAddress());
    bluetoothChannel->add_supported_pairing_methods(aasdk::proto::enums::BluetoothPairingMethod_Enum_HFP);
    bluetoothChannel->add_supported_pairing_methods(aasdk::proto::enums::BluetoothPairingMethod_Enum_A2DP);
  }
}

void BluetoothService::onChannelOpenRequest(const aasdk::proto::messages::ChannelOpenRequest &request) {
  LOG(INFO) << "[BluetoothService] open request, priority: " << request.priority();
  const aasdk::proto::enums::Status::Enum status = aasdk::proto::enums::Status::OK;
  LOG(INFO) << "[BluetoothService] open status: " << status;

  aasdk::proto::messages::ChannelOpenResponse response;
  response.set_status(status);

  auto promise = aasdk::channel::SendPromise::defer(strand_);
  promise->then([]() {}, [&](const aasdk::error::Error &e) { onChannelError(e); });
  channel_->sendChannelOpenResponse(response, std::move(promise));

  channel_->receive(this->shared_from_this());
}

void BluetoothService::onBluetoothPairingRequest(const aasdk::proto::messages::BluetoothPairingRequest &request) {
  LOG(INFO) << "[BluetoothService] pairing request, address: " << request.phone_address();

  aasdk::proto::messages::BluetoothPairingResponse response;

  const auto isPaired = bluetoothDevice_->isPaired(request.phone_address());
  response.set_already_paired(isPaired);
  response.set_status(isPaired ? aasdk::proto::enums::BluetoothPairingStatus::OK
                               : aasdk::proto::enums::BluetoothPairingStatus::FAIL);

  auto promise = aasdk::channel::SendPromise::defer(strand_);
  promise->then([]() {}, [&](const aasdk::error::Error &e) { onChannelError(e); });
  channel_->sendBluetoothPairingResponse(response, std::move(promise));

  channel_->receive(this->shared_from_this());
}

void BluetoothService::onChannelError(const aasdk::error::Error &e) {
  LOG(ERROR) << "[BluetoothService] channel error: " << e.what();
}

}
