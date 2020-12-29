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
    toml::table config = toml::parse_file("/mnt/data_persist/dev/bin/autoapp_configuration.toml");
    if (config.contains("lefthandDrive"))
      lefthandDrive_ = config["lefthandDrive"].as_boolean();
    if (config.contains("hideClock"))
      hideClock_ = config["hideClock"].as_boolean();
    if (config.contains("enableTouchscreen"))
      enableTouchscreen_ = config["enableTouchscreen"].as_boolean();
    if (config.contains("wifiPort"))
      wifiPort_ = static_cast<uint32_t>(static_cast<long long>(*config["wifiPort"].as_integer()));
    if (config.contains("logLevel")) {
      std::optional<std::string> level = config["logLevel"].value<std::string>();
      if (level == "debug") {
        logLevel_ = el::Level::Debug;
      } else {
        logLevel_ = el::Level::Fatal;
      }
    }
    if (config.contains("logFile")) {
      std::optional<std::string> logfile = config["logFile"].value<std::string>();
      logFile_.assign(*logfile);
    }
  }
  catch (const toml::parse_error &err) {
    LOG(ERROR) << err;
  }
}

void Configuration::reset() {
  lefthandDrive_ = true;
  hideClock_ = false;
  enableTouchscreen_ = true;
  wifiPort_ = 30515;
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
uint32_t Configuration::wifiPort() {
  return wifiPort_;
}
void Configuration::wifiPort(uint32_t port) {
  wifiPort_ = port;
}

el::Level Configuration::logLevel() {
  return logLevel_;
}

std::string Configuration::logFile() {
  return std::string(logFile_);
}

}
