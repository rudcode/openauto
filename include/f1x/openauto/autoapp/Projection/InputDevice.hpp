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

#pragma once

#include <linux/input.h>
#include <linux/uinput.h>

#include <aasdk_proto/ButtonCodeEnum.pb.h>
#include <aasdk_proto/TouchActionEnum.pb.h>
#include <aasdk/IO/Promise.hpp>
#include <f1x/openauto/autoapp/Projection/IInputDevice.hpp>
#include <f1x/openauto/autoapp/Configuration/IConfiguration.hpp>

struct TouchScreenState {
    int x;
    int y;
    aasdk::proto::enums::TouchAction::Enum action;
    int action_recvd;
};

class input_device {
private:
    f1x::openauto::autoapp::projection::IInputDeviceEventHandler *eventHandler_;
    asio::posix::stream_descriptor sd;
    std::vector<input_event> events;
    TouchScreenState mTouch{0, 0, (aasdk::proto::enums::TouchAction::Enum) 0, 0};
    uint32_t pressScanCode;
    time_t pressedSince;

public:
    input_device(int fd, asio::io_service& ioService, f1x::openauto::autoapp::projection::IInputDeviceEventHandler &eventHandler);
    void handle_key(input_event &event);
    void handle_touch(input_event &event);
    void handle_input(asio::error_code ec, size_t bytes_transferred);

    void readloop();
};

namespace f1x
{
    namespace openauto
    {
        namespace autoapp
        {
            namespace projection {
                class InputDevice: public IInputDevice {

                public:
                    InputDevice(asio::io_service& ioService);

                    void start(IInputDeviceEventHandler &eventHandler) override;

                    void stop() override;

                    ButtonCodes getSupportedButtonCodes() const override;

                    bool hasTouchscreen() const override;

                    TouchscreenSize getTouchscreenGeometry() const override;

                private:
                    asio::io_service& ioService_;
                    input_device *touchscreen;
                    input_device *keyboard;
                    IInputDeviceEventHandler *eventHandler_;
                    std::mutex mutex_;
                    std::thread input_thread;
                    int input_thread_quit_pipe_read = -1;
                    int input_thread_quit_pipe_write = -1;
                    int touch_fd = -1, kbd_fd = -1, ui_fd = -1;
                    void input_thread_func();
                    uint32_t pressScanCode;
                    time_t pressedSince;
                    void pass_key_to_mzd(int type, int code, int val);

                };
            }
        }
    }
}