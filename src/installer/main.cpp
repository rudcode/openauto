#include <string>
#include <filesystem>
#include "installer/main.hpp"
#include "easylogging++.h"

#define MINI_CASE_SENSITIVE
#include <ini.h>

INITIALIZE_EASYLOGGINGPP

namespace fs = std::filesystem;


//TODO: Check if backup already exists and skip if it does.

int mkdir(const fs::path &path) {
  fs::directory_entry dir_path{path};
  if (!dir_path.exists()) {
    if (!fs::create_directories(dir_path)) {
      LOG(ERROR) << "Couldn't create " << dir_path;
      return -1;
    }
  }
  LOG(INFO) << path << " Created";
  return 0;
}

void install_bds(const fs::path &backup_dir) {
  const auto path = backup_dir / "jci" / "bds";
  if (mkdir(path) != 0) {
    LOG(ERROR) << "Failed install_bds";
    return;
  }
  fs::copy("/jci/bds/BdsConfiguration.xml", path / "BdsConfiguration.xml", fs::copy_options::update_existing);

  tinyxml2::XMLDocument doc;
  doc.LoadFile("/jci/bds/BdsConfiguration.xml");

  tinyxml2::XMLNode *docRoot = doc.FirstChild();

  tinyxml2::XMLElement *serviceconfig = docRoot->FirstChildElement("serviceConfiguration");

  if (serviceconfig == nullptr) {
    LOG(DEBUG) << "Couldn't find serviceConfiguration in /jci/bds/BdsConfiguration.xml";
  } else {
    int lastId = 0;
    bool bdsconfigured = false;
    for (tinyxml2::XMLElement *e = serviceconfig->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
      lastId = e->IntAttribute("id", lastId);
      if (std::string(e->Attribute("name")) == "AndroidAuto") {
        bdsconfigured = true;
        LOG(INFO) << "/jci/bds/BdsConfiguration.xml already configured";
      }
    }
    if (!bdsconfigured) {
      tinyxml2::XMLElement *e = serviceconfig->InsertNewChildElement("serialPort");
      e->SetAttribute("id", lastId + 1);
      e->SetAttribute("name", "AndroidAuto");
      e->SetAttribute("noOfInstances", 1);
      e->SetAttribute("critical", false);
      e->SetAttribute("enabled", true);
      e->SetAttribute("uuidServer", "4DE17A0052CB11E6BDF40800200C9A66");
      e->SetAttribute("uuidClient", "4DE17A0052CB11E6BDF40800200C9A66");
      e->SetAttribute("writeDelay", 3);
      doc.SaveFile("/jci/bds/BdsConfiguration.xml");
      LOG(INFO) << "/jci/bds/BdsConfiguration.xml configured";
    }
  }
}

void setup_sm(const fs::path &backup_dir) {
  const auto path = backup_dir / "jci" / "sm";
  if (mkdir(path) != 0) {
    LOG(ERROR) << "Failed install_bds";
    return;
  }
  fs::copy("/jci/sm/sm.conf", path / "sm.conf", fs::copy_options::update_existing);

  tinyxml2::XMLDocument doc;
  doc.LoadFile("/jci/sm/sm.conf");

  tinyxml2::XMLNode *docRoot = doc.FirstChild()->NextSibling();

  LOG(DEBUG) << docRoot->GetLineNum();

  tinyxml2::XMLElement *serviceconfig = docRoot->FirstChildElement("services");

  if (serviceconfig == nullptr) {
    LOG(DEBUG) << "Couldn't find services in /jci/sm/sm.conf";
  } else {
    bool serviceconfigured = false;
    for (tinyxml2::XMLElement *e = serviceconfig->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
      if (std::string(e->Attribute("name")) == "autoapp") {
        serviceconfigured = true;
        LOG(INFO) << "/jci/sm/sm.conf already configured";
      }
    }
    if (!serviceconfigured) {
      tinyxml2::XMLElement *e = serviceconfig->InsertNewChildElement("service");
      e->SetAttribute("type", "process");
      e->SetAttribute("name", "autoapp");
      e->SetAttribute("path", "/mnt/data_persist/dev/bin/autoapp");
      e->SetAttribute("autorun", "yes");
      e->SetAttribute("reset_board", "no");
      e->SetAttribute("retry_count", 6);
      e->SetAttribute("args", "");
      tinyxml2::XMLElement *dependancy = e->InsertNewChildElement("dependency");
      dependancy->SetAttribute("type", "service");
      dependancy->SetAttribute("value", "bds");
      dependancy = e->InsertNewChildElement("dependency");
      dependancy->SetAttribute("type", "service");
      dependancy->SetAttribute("value", "audio_manager");

      doc.SaveFile("/jci/sm/sm.conf");
      LOG(INFO) << "/jci/sm/sm.conf configured";
    }
  }

}

void setup_mmui(const fs::path &backup_dir) {
  const char *file = "/jci/mmui/mmui_config.xml";
  const auto path = backup_dir / "jci" / "mmui";
  if (mkdir(path) != 0) {
    LOG(ERROR) << "Failed install_bds";
    return;
  }
  fs::copy(file, path / "mmui_config.xml", fs::copy_options::update_existing);

  tinyxml2::XMLDocument doc;
  doc.LoadFile(file);

  tinyxml2::XMLNode *docRoot = doc.FirstChild()->NextSibling();

  LOG(DEBUG) << docRoot->GetLineNum();

  for (tinyxml2::XMLElement *e = docRoot->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
    if (std::string(e->Attribute("name")) == "androidauto") {
      e->SetAttribute("priority", 30);
      LOG(DEBUG) << "Set androidauto priority to 30";
      doc.SaveFile(file);
      break;
    }
  }

}

void configure_opera(const fs::path &backup_dir) {
  auto path = backup_dir / "jci" / "opera" / "opera_home";
  if (mkdir(path) != 0) {
    LOG(ERROR) << "Failed configure_opera";
    return;
  }
  fs::copy("/jci/opera/opera_home/opera.ini", path / "opera.ini", fs::copy_options::update_existing);

  mINI::INIFile file("/jci/opera/opera_home/opera.ini");
  mINI::INIStructure ini;
  file.read(ini);

  std::string &user_javascript = ini["User Prefs"]["User JavaScript"];
  std::string &allow_xmlhttprequests = ini["User Prefs"]["Allow File XMLHttpRequest"];

  user_javascript.assign("1");
  allow_xmlhttprequests.assign("1");
  file.write(ini, false);

  if (fs::exists("/jci/opera/opera_dir/userjs/fps.js")) {
    path = backup_dir / "jci" / "opera" / "opera_dir" / "userjs";
    if (mkdir(path) != 0) {
      LOG(ERROR) << "Failed configure_opera";
      return;
    }
    fs::copy("/jci/opera/opera_dir/userjs/fps.js", path / "fps.js", fs::copy_options::update_existing);
    fs::remove("/jci/opera/opera_dir/userjs/fps.js");
  }
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
  const auto path_backup = fs::absolute("/mnt/data_persist/dev/backup/");
  fs::directory_entry dir_backup{path_backup};
  if (!dir_backup.exists()) {
    if (!fs::create_directory(path_backup)) {
      LOG(ERROR) << "Couldn't create " << path_backup;
      return -1;
    }
  }

  install_bds(path_backup);
  setup_sm(path_backup);
  setup_mmui(path_backup);
  configure_opera(path_backup);
}