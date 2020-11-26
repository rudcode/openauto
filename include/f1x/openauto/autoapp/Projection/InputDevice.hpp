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

#include <aasdk_proto/ButtonCodeEnum.pb.h>
#include <aasdk_proto/TouchActionEnum.pb.h>
#include <f1x/aasdk/IO/Promise.hpp>
#include <f1x/openauto/autoapp/Projection/IInputDevice.hpp>
#include <f1x/openauto/autoapp/Configuration/IConfiguration.hpp>

namespace f1x
{
    namespace openauto
    {
        namespace autoapp
        {
            namespace projection {
                class InputDevice: public IInputDevice {

                public:
                    InputDevice();

                    void start(IInputDeviceEventHandler &eventHandler) override;

                    void stop() override;

                    ButtonCodes getSupportedButtonCodes() const override;

                    bool hasTouchscreen() const override;

                    TouchscreenSize getTouchscreenGeometry() const override;

                private:
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