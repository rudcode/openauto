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

#define EVENT_DEVICE_TS  "/dev/input/filtered-touchscreen0"
#define EVENT_DEVICE_KBD "/dev/input/filtered-keyboard0"

#include <easylogging++.h>
#include <autoapp/Projection/IInputDeviceEventHandler.hpp>
#include <autoapp/Projection/InputDevice.hpp>

namespace autoapp::projection {

InputDevice::InputDevice(asio::io_service &ioService,
                         AudioSignals::Pointer audiosignals,
                         VideoSignals::Pointer videosignals) :
    timer_(ioService),
    strand_(ioService),
    audiosignals_(std::move(audiosignals)),
    videosignals_(std::move(videosignals)),
    eventHandler_(nullptr) {
  keymap = {
      {KEY_G, aasdk::proto::enums::ButtonCode_Enum_MICROPHONE_1},
      {KEY_BACKSPACE, aasdk::proto::enums::ButtonCode_Enum_BACK},
      {KEY_ENTER, aasdk::proto::enums::ButtonCode_Enum_ENTER},
      {KEY_LEFT, aasdk::proto::enums::ButtonCode_Enum_LEFT},
      {KEY_RIGHT, aasdk::proto::enums::ButtonCode_Enum_RIGHT},
      {KEY_UP, aasdk::proto::enums::ButtonCode_Enum_UP},
      {KEY_DOWN, aasdk::proto::enums::ButtonCode_Enum_DOWN},
      {KEY_HOME, aasdk::proto::enums::ButtonCode_Enum_HOME},
      {KEY_R, aasdk::proto::enums::ButtonCode_Enum_NAVIGATION},
      {KEY_Z, aasdk::proto::enums::ButtonCode_Enum_PHONE},
      {KEY_X, aasdk::proto::enums::ButtonCode_Enum_CALL_END},
      {KEY_T, aasdk::proto::enums::ButtonCode_Enum_TOGGLE_PLAY},
      {KEY_LEFTBRACE, aasdk::proto::enums::ButtonCode_Enum_NEXT},
      {KEY_RIGHTBRACE, aasdk::proto::enums::ButtonCode_Enum_PREV},
      {KEY_N, aasdk::proto::enums::ButtonCode_Enum_SCROLL_WHEEL},
      {KEY_M, aasdk::proto::enums::ButtonCode_Enum_SCROLL_WHEEL},
      {KEY_E, aasdk::proto::enums::ButtonCode_Enum_MEDIA}
  };
  audiosignals_->focusChanged.connect(sigc::mem_fun(*this, &InputDevice::audio_focus));
  videosignals_->focusChanged.connect(sigc::mem_fun(*this, &InputDevice::video_focus));
}

void InputDevice::audio_focus(aasdk::proto::enums::AudioFocusState_Enum state) {
  audiofocus = state;
}

void InputDevice::video_focus(bool state) {
  videoFocus_ = state;
  if (videoFocus_) {
    if (keyboard_dev != nullptr) {
      libevdev_grab(keyboard_dev, LIBEVDEV_GRAB);
    }
  } else {
    if (keyboard_dev != nullptr) {
      libevdev_grab(keyboard_dev, LIBEVDEV_UNGRAB);
    }
  }
}

void InputDevice::start(IInputDeviceEventHandler &eventHandler) {
  std::lock_guard<decltype(mutex_)> lock(mutex_);
  int rc;

  LOG(INFO) << "[InputDevice] start.";
  eventHandler_ = &eventHandler;

  /* Open Touchscreen Device */
  touch_fd = open(EVENT_DEVICE_TS, O_RDONLY | O_NONBLOCK);

  if (touch_fd < 0) {
    LOG(ERROR) << EVENT_DEVICE_TS << " is not a vaild device";
  }

  rc = libevdev_new_from_fd(touch_fd, &touch_dev);
  if (rc < 0) {
    LOG(ERROR) << "Failed to init libevdev " << strerror(-rc);
  }

  if (libevdev_grab(touch_dev, LIBEVDEV_GRAB) < 0) {
    LOG(ERROR) << "Failed to grab " << EVENT_DEVICE_TS;
  }

  kbd_fd = open(EVENT_DEVICE_KBD, O_RDONLY | O_NONBLOCK);

  if (kbd_fd < 0) {
    LOG(ERROR) << EVENT_DEVICE_KBD << " is not a vaild device";
  }

  rc = libevdev_new_from_fd(kbd_fd, &keyboard_dev);
  if (rc < 0) {
    LOG(ERROR) << "Failed to init libevdev " << strerror(-rc);
  }

  if (libevdev_grab(keyboard_dev, LIBEVDEV_GRAB) < 0) {
    LOG(ERROR) << "Failed to grab " << EVENT_DEVICE_KBD;
  }

  struct libevdev *dev;
  dev = libevdev_new();
  libevdev_set_name(dev, "mzd-uinput");
  libevdev_set_id_bustype(dev, BUS_USB);
  libevdev_set_id_vendor(dev, 0x1);
  libevdev_set_id_product(dev, 0x1);
  libevdev_set_id_version(dev, 1);
  libevdev_enable_event_type(dev, EV_KEY);
  for (const auto &value: keymap) {
    libevdev_enable_event_code(dev, EV_KEY, value.first, nullptr);
  }
  rc = libevdev_uinput_create_from_device(dev, LIBEVDEV_UINPUT_OPEN_MANAGED, &ui_dev);

  if (rc < 0) {
    LOG(ERROR) << "Failed to init libevdev " << strerror(-rc);
  }

  timer_.expires_from_now(std::chrono::milliseconds(50));
  timer_.async_wait(strand_.wrap([this](asio::error_code ec) { this->poll(ec); }));

}

void print_ev(input_event *ev) {
  printf("Event: time %ld.%06ld, type %d (%s), code %d (%s), value %d\n",
         ev->time.tv_sec,
         ev->time.tv_usec,
         ev->type,
         libevdev_event_type_get_name(ev->type),
         ev->code,
         libevdev_event_code_get_name(ev->type, ev->code),
         ev->value);
}

void InputDevice::poll(asio::error_code ec) {
  if (ec == asio::error::operation_aborted) {
    return;
  }
  int rc = 0;
  while (rc != -EAGAIN) {
    input_event ev{};
    rc = libevdev_next_event(touch_dev, LIBEVDEV_READ_FLAG_NORMAL, &ev);
    if (rc == LIBEVDEV_READ_STATUS_SYNC) {
      LOG(ERROR) << "Input dropped";
      while (rc == LIBEVDEV_READ_STATUS_SYNC) {
        rc = libevdev_next_event(touch_dev, LIBEVDEV_READ_FLAG_SYNC, &ev);
      }
      LOG(DEBUG) << "Input resynced";
    } else if (rc == LIBEVDEV_READ_STATUS_SUCCESS)
      handle_touch(&ev);
  }

  rc = 0;
  while (rc != -EAGAIN) {
    input_event ev{};
    rc = libevdev_next_event(keyboard_dev, LIBEVDEV_READ_FLAG_NORMAL, &ev);
    if (rc == LIBEVDEV_READ_STATUS_SYNC) {
      LOG(ERROR) << "Input dropped";
      while (rc == LIBEVDEV_READ_STATUS_SYNC) {
        rc = libevdev_next_event(keyboard_dev, LIBEVDEV_READ_FLAG_SYNC, &ev);
      }
      LOG(DEBUG) << "Input resynced";
    } else if (rc == LIBEVDEV_READ_STATUS_SUCCESS) {
      print_ev(&ev);
      handle_key(&ev);
    }
  }

  timer_.expires_from_now(std::chrono::milliseconds(50));
  timer_.async_wait(strand_.wrap([this](asio::error_code ec) { this->poll(ec); }));
}

void InputDevice::stop() {
  std::lock_guard<decltype(mutex_)> lock(mutex_);

  timer_.cancel();

  LOG(INFO) << "[InputDevice] stop.";
  eventHandler_ = nullptr;

  libevdev_uinput_destroy(ui_dev);
  libevdev_grab(touch_dev, LIBEVDEV_UNGRAB);
  libevdev_free(touch_dev);
  libevdev_grab(keyboard_dev, LIBEVDEV_UNGRAB);
  libevdev_free(keyboard_dev);
  close(touch_fd);
  close(kbd_fd);

}

bool InputDevice::hasTouchscreen() const {
  return true;
}

IInputDevice::ButtonCodes InputDevice::getSupportedButtonCodes() const {
  std::vector<aasdk::proto::enums::ButtonCode::Enum> buttons;
  buttons.push_back(aasdk::proto::enums::ButtonCode_Enum_MENU);
  buttons.push_back(aasdk::proto::enums::ButtonCode_Enum_MICROPHONE_2);
  buttons.push_back(aasdk::proto::enums::ButtonCode_Enum_HOME);
  buttons.push_back(aasdk::proto::enums::ButtonCode_Enum_BACK);
  buttons.push_back(aasdk::proto::enums::ButtonCode_Enum_PHONE);
  buttons.push_back(aasdk::proto::enums::ButtonCode_Enum_CALL_END);
  buttons.push_back(aasdk::proto::enums::ButtonCode_Enum_UP);
  buttons.push_back(aasdk::proto::enums::ButtonCode_Enum_DOWN);
  buttons.push_back(aasdk::proto::enums::ButtonCode_Enum_LEFT);
  buttons.push_back(aasdk::proto::enums::ButtonCode_Enum_RIGHT);
  buttons.push_back(aasdk::proto::enums::ButtonCode_Enum_ENTER);
  buttons.push_back(aasdk::proto::enums::ButtonCode_Enum_MICROPHONE_1);
  buttons.push_back(aasdk::proto::enums::ButtonCode_Enum_TOGGLE_PLAY);
  buttons.push_back(aasdk::proto::enums::ButtonCode_Enum_NEXT);
  buttons.push_back(aasdk::proto::enums::ButtonCode_Enum_PREV);
  buttons.push_back(aasdk::proto::enums::ButtonCode_Enum_MUSIC);
  buttons.push_back(aasdk::proto::enums::ButtonCode_Enum_SCROLL_WHEEL);
  buttons.push_back(aasdk::proto::enums::ButtonCode_Enum_TEL);
  buttons.push_back(aasdk::proto::enums::ButtonCode_Enum_NAVIGATION);
  return buttons;
}

TouchscreenSize InputDevice::getTouchscreenGeometry() const {
  return TouchscreenSize{480, 800};
}

void InputDevice::handle_key(input_event *ev) {
  std::chrono::steady_clock::time_point tpNow = std::chrono::steady_clock::now();

  if (ev->type == EV_KEY && (ev->value == 1 || ev->value == 0)) {
    aasdk::proto::enums::ButtonCode::Enum scanCode;
    WheelDirection direction = WheelDirection::NONE;
    ButtonEventType eventType = (ev->value == 1) ? ButtonEventType::PRESS
                                                 : ButtonEventType::RELEASE;
    bool isPressed = (ev->value == 1);
    bool hasMediaAudioFocus = audiofocus == aasdk::proto::enums::AudioFocusState_Enum_GAIN;

    scanCode = keymap[ev->code];
    if (scanCode == aasdk::proto::enums::ButtonCode_Enum_NEXT ||
        scanCode == aasdk::proto::enums::ButtonCode_Enum_PREV ||
        scanCode == aasdk::proto::enums::ButtonCode_Enum_MEDIA) {
      if (!hasMediaAudioFocus && videoFocus_) {
        if (std::chrono::duration_cast<std::chrono::milliseconds>(tpNow - mediaDebounce).count() > 200
            && ev->value == 1) {
          libevdev_grab(keyboard_dev, LIBEVDEV_UNGRAB);
          libevdev_uinput_write_event(ui_dev, ev->type, ev->code, 1);
          libevdev_uinput_write_event(ui_dev, EV_SYN, SYN_REPORT, 0);
          libevdev_uinput_write_event(ui_dev, ev->type, ev->code, 0);
          libevdev_uinput_write_event(ui_dev, EV_SYN, SYN_REPORT, 0);
          mediaDebounce = tpNow;
          libevdev_grab(keyboard_dev, LIBEVDEV_GRAB);
        }
        return;
      }
    }
    if (scanCode == aasdk::proto::enums::ButtonCode::SCROLL_WHEEL) {
      if (ev->value == 0) {
        eventType = ButtonEventType::NONE;
        if (ev->code == KEY_M) {
          direction = WheelDirection::RIGHT;
        } else if (ev->code == KEY_N) {
          direction = WheelDirection::LEFT;
        }
      } else {
        scanCode = aasdk::proto::enums::ButtonCode::NONE;
      }
    }

    if (isPressed) {
      pressScanCode = keymap[ev->code];
      time(&pressedSince);
    } else {
      time_t now = time(nullptr);
      if (now - pressedSince >= 2) {
        if (pressScanCode == aasdk::proto::enums::ButtonCode_Enum_TOGGLE_PLAY) {
          audiosignals_->focusRelease.emit();
        } else if (
            pressScanCode == aasdk::proto::enums::ButtonCode_Enum_BACK ||
                pressScanCode == aasdk::proto::enums::ButtonCode_Enum_CALL_END) {
          videosignals_->focusRelease.emit(VIDEO_FOCUS_REQUESTOR::HEADUNIT);
        } else if (pressScanCode == aasdk::proto::enums::ButtonCode_Enum_HOME) {
          videosignals_->focusRequest.emit(VIDEO_FOCUS_REQUESTOR::HEADUNIT);
        }
      }
      pressScanCode = 0;
    }
    if (videoFocus_) {
      if (scanCode != 0) {
        eventHandler_->onButtonEvent({eventType, direction, scanCode});
      }
    }
  }
}

void InputDevice::handle_touch(input_event *ev) {
  switch (ev->type) {
    case EV_ABS:
      switch (ev->code) {
        case ABS_MT_POSITION_X:mTouch.x = static_cast<uint32_t>(ev->value * 800 / 4095);
          break;
        case ABS_MT_POSITION_Y:mTouch.y = static_cast<uint32_t>(ev->value * 480 / 4095);
          break;
        default:break;
      }
      break;
    case EV_KEY:
      if (ev->code == BTN_TOUCH) {
        mTouch.action_recvd = 1;
        if (ev->value == 1) {
          mTouch.action = aasdk::proto::enums::TouchAction::PRESS;
        } else {
          mTouch.action = aasdk::proto::enums::TouchAction::RELEASE;
        }
      }
      break;
    case EV_SYN:
      if (mTouch.action_recvd == 0) {
        mTouch.action = aasdk::proto::enums::TouchAction::DRAG;
      } else {
        mTouch.action_recvd = 0;
      }
      if (videoFocus_) {
        eventHandler_->onTouchEvent({mTouch.action, mTouch.x, mTouch.y, 0});
      }
      break;
    default:break;
  }
}

}
