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

#include <linux/input.h>
#include <linux/uinput.h>

#define EVENT_DEVICE_TS    "/dev/input/filtered-touchscreen0"
#define EVENT_DEVICE_KBD "/dev/input/filtered-keyboard0"
#define EVENT_DEVICE_UI "/dev/uinput"


#include <easylogging++.h>
#include <f1x/openauto/autoapp/Projection/IInputDeviceEventHandler.hpp>
#include <f1x/openauto/autoapp/Projection/InputDevice.hpp>

struct TouchScreenState {
    int x;
    int y;
    f1x::aasdk::proto::enums::TouchAction::Enum action;
    int action_recvd;
};


namespace f1x {
    namespace openauto {
        namespace autoapp {
            namespace projection {
                InputDevice::InputDevice() : eventHandler_(nullptr) {
                }
                static uint64_t get_timestamp(struct input_event &ii) {
                    return ii.time.tv_sec * 1000000 + ii.time.tv_usec;
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
                    struct uinput_user_dev uidev;
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

                    int quitpiperw[2];
                    if (pipe(quitpiperw) < 0) {
                        LOG(ERROR) << "Pipe failed";
                    }
                    input_thread_quit_pipe_read = quitpiperw[0];
                    input_thread_quit_pipe_write = quitpiperw[1];


                    input_thread = std::thread([this]() { input_thread_func(); });
                }

                void InputDevice::stop() {
                    std::lock_guard<decltype(mutex_)> lock(mutex_);

                    LOG(INFO) << "[InputDevice] stop.";
                    eventHandler_ = nullptr;


                    //data we write doesn't matter, wake up touch polling thread
                    write(input_thread_quit_pipe_write, &input_thread_quit_pipe_write,
                          sizeof(input_thread_quit_pipe_write));

                    printf("waiting for input_thread\n");
                    input_thread.join();

                    ioctl(ui_fd, UI_DEV_DESTROY);
                    close(ui_fd);
                    close(touch_fd);
                    close(kbd_fd);
                    close(input_thread_quit_pipe_write);
                    close(input_thread_quit_pipe_read);

                }


                bool InputDevice::hasTouchscreen() const {
                    return true;
                }

                IInputDevice::ButtonCodes InputDevice::getSupportedButtonCodes() const {
                    std::vector<f1x::aasdk::proto::enums::ButtonCode::Enum> buttons;
                    buttons.push_back(f1x::aasdk::proto::enums::ButtonCode_Enum_MENU);
                    buttons.push_back(f1x::aasdk::proto::enums::ButtonCode_Enum_MICROPHONE_2);
                    buttons.push_back(f1x::aasdk::proto::enums::ButtonCode_Enum_HOME);
                    buttons.push_back(f1x::aasdk::proto::enums::ButtonCode_Enum_BACK);
                    buttons.push_back(f1x::aasdk::proto::enums::ButtonCode_Enum_PHONE);
                    buttons.push_back(f1x::aasdk::proto::enums::ButtonCode_Enum_CALL_END);
                    buttons.push_back(f1x::aasdk::proto::enums::ButtonCode_Enum_UP);
                    buttons.push_back(f1x::aasdk::proto::enums::ButtonCode_Enum_DOWN);
                    buttons.push_back(f1x::aasdk::proto::enums::ButtonCode_Enum_LEFT);
                    buttons.push_back(f1x::aasdk::proto::enums::ButtonCode_Enum_RIGHT);
                    buttons.push_back(f1x::aasdk::proto::enums::ButtonCode_Enum_ENTER);
                    buttons.push_back(f1x::aasdk::proto::enums::ButtonCode_Enum_MICROPHONE_1);
                    buttons.push_back(f1x::aasdk::proto::enums::ButtonCode_Enum_TOGGLE_PLAY);
                    buttons.push_back(f1x::aasdk::proto::enums::ButtonCode_Enum_NEXT);
                    buttons.push_back(f1x::aasdk::proto::enums::ButtonCode_Enum_PREV);
                    buttons.push_back(f1x::aasdk::proto::enums::ButtonCode_Enum_MUSIC);
                    buttons.push_back(f1x::aasdk::proto::enums::ButtonCode_Enum_SCROLL_WHEEL);
                    buttons.push_back(f1x::aasdk::proto::enums::ButtonCode_Enum_TEL);
                    buttons.push_back(f1x::aasdk::proto::enums::ButtonCode_Enum_NAVIGATION);
                    return buttons;
                }


                struct TouchScreenState {
                    int x;
                    int y;
                    f1x::aasdk::proto::enums::TouchAction::Enum action;
                    int action_recvd;
                };




                void InputDevice::input_thread_func() {
                    TouchScreenState mTouch{0, 0, (f1x::aasdk::proto::enums::TouchAction::Enum) 0, 0};
                    int maxfdPlus1 = std::max(std::max(touch_fd, kbd_fd), input_thread_quit_pipe_read) + 1;
                    while (true) {
                        fd_set set;
                        int unblocked;

                        FD_ZERO(&set);
                        FD_SET(touch_fd, &set);
                        FD_SET(kbd_fd, &set);
                        FD_SET(input_thread_quit_pipe_read, &set);

                        unblocked = select(maxfdPlus1, &set, NULL, NULL, NULL);

                        if (unblocked == -1) {
                            LOG(ERROR) << "Error in read...";
                            break;
                        } else if (unblocked > 0 && FD_ISSET(input_thread_quit_pipe_read, &set)) {
                            break;
                        }

                        struct input_event events[64];
                        const size_t buffer_size = sizeof(events);

                        if (FD_ISSET(touch_fd, &set)) {
                            ssize_t size = read(touch_fd, &events, buffer_size);

                            if (size == 0 || size == -1)
                                break;

                            if (size < sizeof(input_event)) {
                                LOG(ERROR) << "Error size when reading";
                                break;
                            }

                            int num_chars = size / sizeof(input_event);
                            for (int i = 0; i < num_chars; i++) {
                                auto &event = events[i];
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
                                                mTouch.action = f1x::aasdk::proto::enums::TouchAction::PRESS;
                                            } else {
                                                mTouch.action = f1x::aasdk::proto::enums::TouchAction::RELEASE;
                                            }
                                        }
                                        break;
                                    case EV_SYN:
                                        if (mTouch.action_recvd == 0) {
                                            mTouch.action = f1x::aasdk::proto::enums::TouchAction::DRAG;
                                        } else {
                                            mTouch.action_recvd = 0;
                                        }
                                        break;
                                    default:
                                        break;
                                }
                                eventHandler_->onTouchEvent({mTouch.action, static_cast<uint32_t>(mTouch.x), static_cast<uint32_t>(mTouch.y), static_cast<uint32_t>(get_timestamp(event))});
                                LOG(DEBUG) << "Touch Event x:" << mTouch.x << " y:" << mTouch.y << " Action: " << mTouch.action;
                            }
                        }

                        if (FD_ISSET(kbd_fd, &set)) {
                            ssize_t size = read(kbd_fd, &events, buffer_size);

                            if (size == 0 || size == -1)
                                break;

                            if (size < sizeof(input_event)) {
                                LOG(ERROR) << "Error size when reading";
                                break;
                            }

                            int num_chars = size / sizeof(input_event);
                            for (int i = 0; i < num_chars; i++) {
                                auto &event = events[i];
                                if (event.type == EV_KEY && (event.value == 1 || event.value == 0)) {
                                    uint64_t timeStamp = get_timestamp(event);
                                    f1x::aasdk::proto::enums::ButtonCode::Enum scanCode = f1x::aasdk::proto::enums::ButtonCode::NONE;
                                    WheelDirection direction = WheelDirection::NONE;
                                    ButtonEventType eventType = eventType = (event.value == 1) ? ButtonEventType::PRESS
                                                                                               : ButtonEventType::RELEASE;
                                    bool isPressed = (event.value == 1);
                                    bool longPress = false;
//                    AudioManagerClient::FocusType audioFocus = callbacks->audioFocus;
                                    bool hasMediaAudioFocus = true; // = audioFocus == AudioManagerClient::FocusType::PERMANENT;
                                    bool hasAudioFocus = true; // audioFocus != AudioManagerClient::FocusType::NONE;

                                    //printf("Key code %i value %i\n", (int)event.code, (int)event.value);
                                    switch (event.code) {
                                        case KEY_G:
                                            printf("KEY_G\n");
                                            scanCode = f1x::aasdk::proto::enums::ButtonCode_Enum_MICROPHONE_1;
                                            break;
                                            //Make the music button play/pause
//                        case KEY_E:
//                            # TODO: Add this to AASDK
//                            printf("KEY_E\n");
//                            scanCode = HUIB_MUSIC;
//                            break;
                                        case KEY_LEFTBRACE:
                                            LOG(INFO) << "KEY_LEFTBRACE (next track with media focus: "
                                                               << (hasMediaAudioFocus ? 1 : 0) << ")";
                                            if (hasMediaAudioFocus) {
                                                scanCode = f1x::aasdk::proto::enums::ButtonCode_Enum_NEXT;
                                            } else {
                                                pass_key_to_mzd(event.type, event.code, event.value);
                                            }
                                            break;
                                        case KEY_RIGHTBRACE:
                                            LOG(INFO) << "KEY_RIGHTBRACE (prev track with media focus: "
                                                               << (hasMediaAudioFocus ? 1 : 0) << ")";
                                            if (hasMediaAudioFocus) {
                                                scanCode = f1x::aasdk::proto::enums::ButtonCode_Enum_PREV;
                                            } else {
                                                pass_key_to_mzd(event.type, event.code, event.value);
                                            }
                                            break;
                                        case KEY_BACKSPACE:
                                            LOG(INFO) << "KEY_BACKSPACE";
                                            scanCode = f1x::aasdk::proto::enums::ButtonCode_Enum_BACK;
                                            break;
                                        case KEY_ENTER:
                                            LOG(INFO) << "KEY_ENTER";
                                            scanCode = f1x::aasdk::proto::enums::ButtonCode_Enum_ENTER;
                                            break;
                                        case KEY_LEFT:
                                            LOG(INFO) << "KEY_LEFT\n";
                                            scanCode = f1x::aasdk::proto::enums::ButtonCode_Enum_LEFT;
                                            break;
                                        case KEY_RIGHT:
                                            LOG(INFO) << "KEY_RIGHT";
                                            scanCode = f1x::aasdk::proto::enums::ButtonCode_Enum_RIGHT;
                                            break;
                                        case KEY_UP:
                                            LOG(INFO) << "KEY_UP";
                                            scanCode = f1x::aasdk::proto::enums::ButtonCode_Enum_UP;
                                            break;
                                        case KEY_DOWN:
                                            LOG(INFO) << "KEY_DOWN";
                                            scanCode = f1x::aasdk::proto::enums::ButtonCode_Enum_DOWN;
                                            break;
                                        case KEY_N:
                                            LOG(INFO) << "KEY_N";
                                            if (isPressed) {
                                                eventType = ButtonEventType::NONE;
                                                direction = WheelDirection::LEFT;
                                            }
                                            break;
                                        case KEY_M:
                                            LOG(INFO) << "KEY_M";
                                            if (isPressed) {
                                                eventType = ButtonEventType::NONE;
                                                direction = WheelDirection::RIGHT;
                                            }
                                            break;
                                        case KEY_HOME:
                                            LOG(INFO) << "KEY_HOME";
                                            scanCode = f1x::aasdk::proto::enums::ButtonCode_Enum_HOME;
                                            break;
                                        case KEY_R: // NAV
                                            LOG(INFO) << "KEY_R";
                                            scanCode = f1x::aasdk::proto::enums::ButtonCode_Enum_NAVIGATION;
                                            break;
                                        case KEY_Z: // CALL ANS
                                            LOG(INFO) << "KEY_Z";
                                            scanCode = f1x::aasdk::proto::enums::ButtonCode_Enum_PHONE;
                                            break;
                                        case KEY_X: // CALL END
                                        {    // we can do this since this button does nothing when not on a call
                                            scanCode = f1x::aasdk::proto::enums::ButtonCode_Enum_CALL_END;
                                        }
                                            break;
                                        case KEY_T: // FAV
                                            LOG(INFO) << "KEY_T";
                                            scanCode = f1x::aasdk::proto::enums::ButtonCode_Enum_TOGGLE_PLAY;
                                            break;
                                    }

                                    if (isPressed) {
                                        pressScanCode = scanCode;
                                        time(&pressedSince);
                                    } else {
//                        TODO: Implement this
                                        time_t now = time(NULL);
                                        if (now - pressedSince >= 2) {
                                            if (pressScanCode ==
                                                f1x::aasdk::proto::enums::ButtonCode_Enum_TOGGLE_PLAY) {
//                                callbacks->releaseAudioFocus();
                                            } else if (
                                                    pressScanCode == f1x::aasdk::proto::enums::ButtonCode_Enum_BACK ||
                                                    pressScanCode ==
                                                    f1x::aasdk::proto::enums::ButtonCode_Enum_CALL_END) {
//                                callbacks->releaseVideoFocus();
                                            } else if (pressScanCode ==
                                                       f1x::aasdk::proto::enums::ButtonCode_Enum_HOME) {
//                                callbacks->takeVideoFocus();
                                            }

                                        }
                                        pressScanCode = 0;
                                    }

                                    if (scanCode != 0 || direction != WheelDirection::NONE) {
                                        eventHandler_->onButtonEvent({eventType, direction, scanCode});
                                    }
                                }
                            }
                        }
                    }
                }

                TouchscreenSize InputDevice::getTouchscreenGeometry() const {
                    return TouchscreenSize{.width =  480, .height = 800};
                }

                static void emit(int fd, int type, int code, int val) {
                    struct input_event ie;
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
