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

#define EVENT_DEVICE_TS    "/dev/input/filtered-touchscreen0"
#define EVENT_DEVICE_KBD "/dev/input/filtered-keyboard0"
#define EVENT_DEVICE_UI "/dev/uinput"


#include <easylogging++.h>
#include <f1x/openauto/autoapp/Projection/IInputDeviceEventHandler.hpp>
#include <f1x/openauto/autoapp/Projection/InputDevice.hpp>
#include <map>

input_device::input_device(int fd, asio::io_service &ioService,
                           f1x::openauto::autoapp::projection::IInputDeviceEventHandler &eventHandler) : eventHandler_(
        nullptr), sd(ioService, fd) {
    eventHandler_ = &eventHandler;
    readloop();
}

std::map<uint16_t, aasdk::proto::enums::ButtonCode_Enum> keymap = {
        {KEY_G,          aasdk::proto::enums::ButtonCode_Enum_MICROPHONE_1},
        {KEY_BACKSPACE,  aasdk::proto::enums::ButtonCode_Enum_BACK},
        {KEY_ENTER,      aasdk::proto::enums::ButtonCode_Enum_ENTER},
        {KEY_LEFT,       aasdk::proto::enums::ButtonCode_Enum_LEFT},
        {KEY_RIGHT,      aasdk::proto::enums::ButtonCode_Enum_RIGHT},
        {KEY_UP,         aasdk::proto::enums::ButtonCode_Enum_UP},
        {KEY_DOWN,       aasdk::proto::enums::ButtonCode_Enum_DOWN},
        {KEY_HOME,       aasdk::proto::enums::ButtonCode_Enum_HOME},
        {KEY_R,          aasdk::proto::enums::ButtonCode_Enum_NAVIGATION},
        {KEY_Z,          aasdk::proto::enums::ButtonCode_Enum_PHONE},
        {KEY_X,          aasdk::proto::enums::ButtonCode_Enum_CALL_END},
        {KEY_T,          aasdk::proto::enums::ButtonCode_Enum_TOGGLE_PLAY},
        {KEY_LEFTBRACE,  aasdk::proto::enums::ButtonCode_Enum_NEXT},
        {KEY_RIGHTBRACE, aasdk::proto::enums::ButtonCode_Enum_PREV},
        {KEY_N,          aasdk::proto::enums::ButtonCode::SCROLL_WHEEL},
        {KEY_M,          aasdk::proto::enums::ButtonCode::SCROLL_WHEEL},
        {KEY_E,          aasdk::proto::enums::ButtonCode_Enum_NONE}
};

void input_device::handle_key(input_event &event) {
    if (event.type == EV_KEY && (event.value == 1 || event.value == 0)) {
        aasdk::proto::enums::ButtonCode::Enum scanCode;
        f1x::openauto::autoapp::projection::WheelDirection direction = f1x::openauto::autoapp::projection::WheelDirection::NONE;
        f1x::openauto::autoapp::projection::ButtonEventType eventType = (event.value == 1)
                                                                        ? f1x::openauto::autoapp::projection::ButtonEventType::PRESS
                                                                        : f1x::openauto::autoapp::projection::ButtonEventType::RELEASE;
        bool isPressed = (event.value == 1);
        bool longPress = false;
        //AudioManagerClient::FocusType audioFocus = callbacks->audioFocus;
        bool hasMediaAudioFocus = true; // = audioFocus == AudioManagerClient::FocusType::PERMANENT;
        bool hasAudioFocus = true; // audioFocus != AudioManagerClient::FocusType::NONE;

        scanCode = keymap[event.code];
        if (scanCode == aasdk::proto::enums::ButtonCode_Enum_NEXT ||
            scanCode == aasdk::proto::enums::ButtonCode_Enum_PREV) {
            if (!hasMediaAudioFocus) {
                scanCode = aasdk::proto::enums::ButtonCode_Enum_NONE;
                //pass_key_to_mzd(event.type, event.code, event.value);
            }
        }
        if (scanCode == aasdk::proto::enums::ButtonCode::SCROLL_WHEEL) {
            eventType = f1x::openauto::autoapp::projection::ButtonEventType::NONE;
            if (event.code == KEY_M) {
                direction = f1x::openauto::autoapp::projection::WheelDirection::RIGHT;
            } else if (event.code == KEY_N) {
                direction = f1x::openauto::autoapp::projection::WheelDirection::LEFT;
            }
        }

        if (isPressed) {
            pressScanCode = scanCode;
            time(&pressedSince);
        } else {
            //TODO: Implement this
            time_t now = time(nullptr);
            if (now - pressedSince >= 2) {
                if (pressScanCode == aasdk::proto::enums::ButtonCode_Enum_TOGGLE_PLAY) {
                    //callbacks->releaseAudioFocus();
                } else if (
                        pressScanCode == aasdk::proto::enums::ButtonCode_Enum_BACK ||
                        pressScanCode == aasdk::proto::enums::ButtonCode_Enum_CALL_END) {
                    //callbacks->releaseVideoFocus();
                } else if (pressScanCode == aasdk::proto::enums::ButtonCode_Enum_HOME) {
                    //callbacks->takeVideoFocus();
                }
            }
            pressScanCode = 0;
        }

        if (scanCode != 0 || direction != f1x::openauto::autoapp::projection::WheelDirection::NONE) {
            eventHandler_->onButtonEvent({eventType, direction, scanCode});
        }
    }
}

void input_device::handle_touch(input_event &event) {
    switch (event.type) {
        case EV_ABS:
            switch (event.code) {
                case ABS_MT_POSITION_X:
                    mTouch.x = event.value * 800 / 4095;
                    break;
                case ABS_MT_POSITION_Y:
                    mTouch.y = event.value * 480 / 4095;
                    break;
            }
            break;
        case EV_KEY:
            if (event.code == BTN_TOUCH) {
                mTouch.action_recvd = 1;
                if (event.value == 1) {
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
            eventHandler_->onTouchEvent({
                mTouch.action,
                static_cast<uint32_t>(mTouch.x),
                static_cast<uint32_t>(mTouch.y),
                0
            });
            break;
        default:
            break;
    }
}

void input_device::handle_input(asio::error_code ec, size_t bytes_transferred) {
    if (!ec) {
        auto const n = bytes_transferred / sizeof(input_event);
        for (int i = 0; i < n; i++) {
            auto &event = events[i];
            switch (event.type) {
                case EV_ABS:
                    handle_touch(event);
                    break;
                case EV_KEY:
                    if (event.code == BTN_TOUCH) {
                        handle_touch(event);
                    } else {
                        handle_key(event);
                    }
                    break;
                case EV_SYN:
                    handle_touch(event);
                    break;
                default:
                    LOG(ERROR) << "No handler for event type " << event.type;
                    break;
            }
        }
        readloop();
    } else {
        LOG(ERROR) << ec.message();
    }
}

void input_device::readloop() {
    events.resize(32);
    sd.async_read_some(asio::buffer(events), [this](asio::error_code ec, size_t bytes_transferred) {
        this->handle_input(ec, bytes_transferred);
    });
}


namespace f1x {
    namespace openauto {
        namespace autoapp {
            namespace projection {
                InputDevice::InputDevice(asio::io_service &ioService) : ioService_(ioService), eventHandler_(nullptr) {
                }

                void InputDevice::start(IInputDeviceEventHandler &eventHandler) {
                    std::lock_guard<decltype(mutex_)> lock(mutex_);

                    LOG(INFO) << "[InputDevice] start.";
                    eventHandler_ = &eventHandler;

                    /* Open Touchscreen Device */
                    touch_fd = open(EVENT_DEVICE_TS, O_RDONLY);

                    if (touch_fd < 0) {
                        LOG(ERROR) << EVENT_DEVICE_TS << " is not a vaild device";
                    }

                    if (ioctl(touch_fd, EVIOCGRAB, 1) < 0) {
                        LOG(ERROR) << "EVIOCGRAB failed on " << EVENT_DEVICE_TS;
                    }

                    kbd_fd = open(EVENT_DEVICE_KBD, O_RDONLY);

                    if (kbd_fd < 0) {
                        LOG(ERROR) << EVENT_DEVICE_KBD << " is not a vaild device";
                    }

                    if (ioctl(kbd_fd, EVIOCGRAB, 1) < 0) {
                        LOG(ERROR) << "EVIOCGRAB failed on " << EVENT_DEVICE_KBD;
                    }

                    ui_fd = open(EVENT_DEVICE_UI, O_WRONLY | O_NONBLOCK);

                    if (ui_fd < 0) {
                        LOG(ERROR) << EVENT_DEVICE_UI << " is not a vaild device";
                    }

                    if (ioctl(ui_fd, UI_SET_EVBIT, EV_KEY) < 0) {
                        LOG(ERROR) << "UI_SET_EVBIT failed on " << EV_KEY;
                    }
                    if (ioctl(ui_fd, UI_SET_KEYBIT, KEY_LEFTBRACE) < 0) {
                        LOG(ERROR) << "UI_SET_KEYBIT failed on " << KEY_LEFTBRACE;
                    }
                    if (ioctl(ui_fd, UI_SET_KEYBIT, KEY_RIGHTBRACE) < 0) {
                        LOG(ERROR) << "UI_SET_KEYBIT failed on " << KEY_RIGHTBRACE;
                    }
                    if (ioctl(ui_fd, UI_SET_KEYBIT, KEY_E) < 0) {
                        LOG(ERROR) << "UI_SET_KEYBIT failed on " << KEY_E;
                    }
                    struct uinput_user_dev uidev{};
                    memset(&uidev, 0, sizeof(uidev));
                    snprintf(uidev.name, UINPUT_MAX_NAME_SIZE, "mzd-uinput");
                    uidev.id.bustype = BUS_USB;
                    uidev.id.vendor = 0x1;
                    uidev.id.product = 0x1;
                    uidev.id.version = 1;

                    if (write(ui_fd, &uidev, sizeof(uidev)) < 0) {
                        LOG(ERROR) << "Write uidev failed";
                    }

                    if (ioctl(ui_fd, UI_DEV_CREATE) < 0) {
                        LOG(ERROR) << "UI_DEV_CREATE failed on %s\n" << EVENT_DEVICE_UI;
                    }

                    touchscreen = new input_device(touch_fd, ioService_, eventHandler);
                    keyboard = new input_device(kbd_fd, ioService_, eventHandler);

                }

                void InputDevice::stop() {
                    std::lock_guard<decltype(mutex_)> lock(mutex_);

                    LOG(INFO) << "[InputDevice] stop.";
                    eventHandler_ = nullptr;

                    ioctl(ui_fd, UI_DEV_DESTROY);
                    close(ui_fd);
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
                    return TouchscreenSize{.width =  480, .height = 800};
                }

                static void emit(int fd, int type, int code, int val) {
                    struct input_event ie{};
                    ie.type = static_cast<__u16>(type);
                    ie.code = static_cast<__u16>(code);
                    ie.value = val;
                    ie.time.tv_sec = 0;
                    ie.time.tv_usec = 0;
                    write(fd, &ie, sizeof(ie));
                }

/**
* Passes the keystroke to MZD by "ungrabbing" the kbd on key-down, simulating the same keystroke with uinput,
* then "re-grabbing" the kbd on key-up.
*/
                void InputDevice::pass_key_to_mzd(int type, int code, int val) {
                    if (val && ioctl(kbd_fd, EVIOCGRAB, 0) < 0) {
                        fprintf(stderr, "EVIOCGRAB failed to release %s\n", EVENT_DEVICE_KBD);
                    }

                    emit(ui_fd, type, code, val);
                    emit(ui_fd, EV_SYN, SYN_REPORT, 0);

                    if (!val && ioctl(kbd_fd, EVIOCGRAB, 1) < 0) {
                        fprintf(stderr, "EVIOCGRAB failed to grab %s\n", EVENT_DEVICE_KBD);
                    }
                }

            }
        }
    }
}
