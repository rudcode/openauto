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

#include <aasdk_proto/DrivingStatusEnum.pb.h>
#include <easylogging++.h>
#include <autoapp/Service/SensorService.hpp>
#include <fstream>
#include <cmath>

namespace autoapp::service {

    SensorService::SensorService(asio::io_service &ioService, aasdk::messenger::IMessenger::Pointer messenger,
                                 GpsSignals::Pointer gpssignals)
            : timer_(ioService), strand_(ioService),
              channel_(std::make_shared<aasdk::channel::sensor::SensorServiceChannel>(strand_, std::move(messenger))),
              gpssignals_(std::move(gpssignals)) {

    }

    void SensorService::start() {
        signal_returnUpdate_ = gpssignals_->returnUpdate.connect(sigc::mem_fun(*this, &SensorService::sendGPSLocationData));
        strand_.dispatch([this, self = this->shared_from_this()]() {
            if (checkNight()) {
                this->isNight = true;
            }
            this->sensorPolling();

            LOG(INFO) << "[SensorService] start.";
            channel_->receive(this->shared_from_this());
        });

    }

    void SensorService::stop() {
        this->stopPolling = true;
        signal_returnUpdate_.disconnect();
        LOG(INFO) << "[SensorService] stop.";
    }

    void SensorService::pause() {
        strand_.dispatch([this, self = this->shared_from_this()]() {
            LOG(INFO) << "[SensorService] pause.";
        });
    }

    void SensorService::resume() {
        strand_.dispatch([this, self = this->shared_from_this()]() {
            LOG(INFO) << "[SensorService] resume.";
        });
    }

    void SensorService::fillFeatures(aasdk::proto::messages::ServiceDiscoveryResponse &response) {
        LOG(INFO) << "[SensorService] fill features.";

        auto *channelDescriptor = response.add_channels();
        channelDescriptor->set_channel_id(static_cast<uint32_t>(channel_->getId()));

        auto *sensorChannel = channelDescriptor->mutable_sensor_channel();
        sensorChannel->add_sensors()->set_type(aasdk::proto::enums::SensorType::DRIVING_STATUS);
        sensorChannel->add_sensors()->set_type(aasdk::proto::enums::SensorType::LOCATION);
        sensorChannel->add_sensors()->set_type(aasdk::proto::enums::SensorType::NIGHT_DATA);
    }

    void SensorService::onChannelOpenRequest(const aasdk::proto::messages::ChannelOpenRequest &request) {
        LOG(INFO) << "[SensorService] open request, priority: " << request.priority();
        const aasdk::proto::enums::Status::Enum status = aasdk::proto::enums::Status::OK;
        LOG(INFO) << "[SensorService] open status: " << status;

        aasdk::proto::messages::ChannelOpenResponse response;
        response.set_status(status);

        auto promise = aasdk::channel::SendPromise::defer(strand_);
        promise->then([]() {}, [&](const aasdk::error::Error &e) { onChannelError(e); });
        channel_->sendChannelOpenResponse(response, std::move(promise));

        channel_->receive(this->shared_from_this());
    }

    void SensorService::onSensorStartRequest(const aasdk::proto::messages::SensorStartRequestMessage &request) {
        LOG(INFO) << "[SensorService] sensor start request, type: " << request.sensor_type();

        aasdk::proto::messages::SensorStartResponseMessage response;
        response.set_status(aasdk::proto::enums::Status::OK);

        auto promise = aasdk::channel::SendPromise::defer(strand_);

        if (request.sensor_type() == aasdk::proto::enums::SensorType::DRIVING_STATUS) {
            promise->then([&]() { sendDrivingStatusUnrestricted(); },
                          [&](const aasdk::error::Error &e) { onChannelError(e); });
        } else if (request.sensor_type() == aasdk::proto::enums::SensorType::NIGHT_DATA) {
            promise->then([&]() { sendNightData(); },
                          [&](const aasdk::error::Error &e) { onChannelError(e); });
        } else {
            promise->then([]() {}, [&](const aasdk::error::Error &e) { onChannelError(e); });
        }

        channel_->sendSensorStartResponse(response, std::move(promise));
        channel_->receive(this->shared_from_this());
    }

    void SensorService::sendDrivingStatusUnrestricted() {
        aasdk::proto::messages::SensorEventIndication indication;
        indication.add_driving_status()->set_status(aasdk::proto::enums::DrivingStatus::UNRESTRICTED);

        auto promise = aasdk::channel::SendPromise::defer(strand_);
        promise->then([]() {}, [&](const aasdk::error::Error &e) { onChannelError(e); });
        channel_->sendSensorEventIndication(indication, std::move(promise));
    }

    void SensorService::sendNightData() {
        aasdk::proto::messages::SensorEventIndication indication;

        if (SensorService::isNight) {
            LOG(INFO) << "[SensorService] Mode night triggered";
            indication.add_night_mode()->set_is_night(true);
        } else {
            LOG(INFO) << "[SensorService] Mode day triggered";
            indication.add_night_mode()->set_is_night(false);
        }

        auto promise = aasdk::channel::SendPromise::defer(strand_);
        promise->then([]() {}, [&](const aasdk::error::Error &e) { onChannelError(e); });
        channel_->sendSensorEventIndication(indication, std::move(promise));
        if (this->firstRun) {
            this->firstRun = false;
            this->previous = this->isNight;
        }
    }

    void SensorService::sendGPSLocationData(uint64_t time, int32_t latitude, int32_t longitude, uint32_t accuracy,
                                            int32_t altitude, int32_t speed, int32_t bearing) {
        aasdk::proto::messages::SensorEventIndication indication;
        auto *locInd = indication.add_gps_location();
        locInd->set_timestamp(time);
        locInd->set_latitude(latitude);
        locInd->set_longitude(longitude);
        locInd->set_accuracy(accuracy);
        locInd->set_altitude(altitude);
        locInd->set_speed(speed);
        locInd->set_bearing(bearing);

        auto promise = aasdk::channel::SendPromise::defer(strand_);
        promise->then([]() {}, [&](const aasdk::error::Error &e) { onChannelError(e); });
        channel_->sendSensorEventIndication(indication, std::move(promise));
    }

    void SensorService::sensorPolling() {
        if (!this->stopPolling) {
            strand_.dispatch([this, self = this->shared_from_this()]() {
                this->isNight = checkNight();
                if (this->previous != this->isNight && !this->firstRun) {
                    this->previous = this->isNight;
                    this->sendNightData();
                }

                if (this->gpsEnabled_) {
                    gpssignals_->requestUpdate.emit();
                }
                timer_.expires_from_now(std::chrono::milliseconds(250));
                timer_.async_wait(strand_.wrap([this](asio::error_code ec) { this->sensorPolling(); }));
            });
        }
    }

    void SensorService::onChannelError(const aasdk::error::Error &e) {
        LOG(ERROR) << "[SensorService] channel error: " << e.what();
    }

}

bool checkNight() {
    bool nightmodenow;
    char gpio_value[3];
    FILE *fd = fopen("/sys/class/gpio/CAN_Day_Mode/value", "r");
    if (fd == nullptr) {
        LOG(ERROR) << "Failed to open CAN_Day_Mode gpio value for reading";
    } else {
        fread(gpio_value, 1, 2, fd);
        nightmodenow = (gpio_value[0] == '0');
    }
    fclose(fd);
    return nightmodenow;
}
