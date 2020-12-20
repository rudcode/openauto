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

#include <autoapp/Configuration/Configuration.hpp>
#include <easylogging++.h>

namespace autoapp::configuration {

Configuration::Configuration() {
  try {
    config = toml::parse_file("/mnt/data_persist/dev/bin/autoapp_configuration.toml");
    lefthandDrive_ = config["lefthandDrive"].as_boolean();
    hideClock_ = config["hideClock"].as_boolean();
    enableTouchscreen_ = config["enableTouchscreen"].as_boolean();
    LOG(DEBUG) << config;
  }
  catch (const toml::parse_error &err) {
    LOG(ERROR) << err;
  }
}

void Configuration::reset() {
  lefthandDrive_ = true;
  hideClock_ = false;
  enableTouchscreen_ = true;
}

void Configuration::save() {

}

void Configuration::leftHandDrive(bool value) {
  lefthandDrive_ = value;
}

bool Configuration::leftHandDrive() const {
  return lefthandDrive_;
}

void Configuration::hideClock(bool value) {
  hideClock_ = value;
}

bool Configuration::hideClock() const {
  return hideClock_;
}

bool Configuration::getTouchscreenEnabled() const {
  return enableTouchscreen_;
}

void Configuration::setTouchscreenEnabled(bool value) {
  enableTouchscreen_ = value;
}

}
