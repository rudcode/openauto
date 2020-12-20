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
#include <autoapp/Projection/IInputDevice.hpp>
#include <autoapp/Configuration/IConfiguration.hpp>
#include <autoapp/Signals/Signals.hpp>

struct TouchScreenState {
  uint32_t x;
  uint32_t y;
  aasdk::proto::enums::TouchAction::Enum action;
  int action_recvd;
};

namespace autoapp::projection {
class InputDevice : public IInputDevice {

 public:
  InputDevice(asio::io_service &ioService, AudioSignals::Pointer audiosignals, VideoSignals::Pointer videosignals);

  void start(IInputDeviceEventHandler &eventHandler) override;

  void stop() override;

  [[nodiscard]] ButtonCodes getSupportedButtonCodes() const override;

  [[nodiscard]] bool hasTouchscreen() const override;

  [[nodiscard]] TouchscreenSize getTouchscreenGeometry() const override;

 private:
  asio::io_service &ioService_;
  AudioSignals::Pointer audiosignals_;
  VideoSignals::Pointer videosignals_;
  asio::posix::stream_descriptor *touchscreen = nullptr;
  asio::posix::stream_descriptor *keyboard = nullptr;
  std::vector<input_event> touch_events;
  std::vector<input_event> key_events;
  IInputDeviceEventHandler *eventHandler_;
  std::mutex mutex_;
  int touch_fd = -1, kbd_fd = -1, ui_fd = -1;
  uint32_t pressScanCode = 0;
  time_t pressedSince = 0;
  aasdk::proto::enums::AudioFocusState_Enum audiofocus = aasdk::proto::enums::AudioFocusState_Enum_NONE;
  TouchScreenState mTouch{0, 0, (aasdk::proto::enums::TouchAction::Enum) 0, 0};

  void pass_key_to_mzd(int type, int code, int val) const;

  void handle_key(asio::error_code ec, size_t bytes_transferred);

  void handle_touch(asio::error_code ec, size_t bytes_transferred);

  void audio_focus(aasdk::proto::enums::AudioFocusState_Enum state);
};
}