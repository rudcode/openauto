#include <autoapp/Managers/AudioManager.hpp>
#include <nlohmann/json.hpp>
#include <easylogging++.h>

using json = nlohmann::json;

void AudioManagerClient::aaRegisterStream() {
  // First open a new Stream
  json sessArgs = {
      {"busName", "com.jci.usbm_am_client"},
      {"objectPath", "/com/jci/usbm_am_client"},
      {"destination", "Cabin"}
  };
  if (aaSessionID < 0) {
    try {
      std::string sessString = Request("openSession", sessArgs.dump());
      LOG(DEBUG) << "openSession(" << sessArgs.dump().c_str() << ")\n" << sessString.c_str() << "\n";
      aaSessionID = json::parse(sessString)["sessionId"];

      // Register the stream
      json regArgs = {
          {"sessionId", aaSessionID},
          {"streamName", aaStreamName},
          // { "streamModeName", aaStreamName },
          {"focusType", "permanent"},
          {"streamType", "Media"}
      };
      std::string regString = Request("registerAudioStream", regArgs.dump());
      LOG(DEBUG) << "registerAudioStream(" << regArgs.dump().c_str() << ")\n" << regString.c_str() << "\n";
    }
    catch (const std::domain_error &ex) {
      LOG(ERROR) << "Failed to parse state json: " << ex.what();
    }
    catch (const std::invalid_argument &ex) {
      LOG(ERROR) << "Failed to parse state json: " << ex.what();
    }

    // Stream is registered add it to the array
    streamToSessionIds[aaStreamName] = aaSessionID;
  }

  if (aaTransientSessionID < 0) {
    try {
      std::string sessString = Request("openSession", sessArgs.dump());
      LOG(DEBUG) << "openSession(" << sessArgs.dump().c_str() << ")\n" << sessString.c_str() << "\n";
      aaTransientSessionID = json::parse(sessString)["sessionId"];

      // Register the stream
      json regArgs = {
          {"sessionId", aaTransientSessionID},
          {"streamName", aaStreamName},
          // { "streamModeName", aaStreamName },
          {"focusType", "transient"},
          {"streamType", "InfoUser"}
      };
      std::string regString = Request("registerAudioStream", regArgs.dump());
      LOG(DEBUG) << "registerAudioStream(" << regArgs.dump().c_str() << ")\n" << regString.c_str() << "\n";
    }
    catch (const std::domain_error &ex) {
      LOG(ERROR) << "Failed to parse state json: " << ex.what();
    }
    catch (const std::invalid_argument &ex) {
      LOG(ERROR) << "Failed to parse state json: " << ex.what();
    }

    // Stream is registered add it to the array
    streamToSessionIds[aaStreamName] = aaTransientSessionID;
  }
}

void AudioManagerClient::populateStreamTable() {
  streamToSessionIds.clear();
  json requestArgs = {
      {"svc", "SRCS"},
      {"pretty", false}
  };
  std::string resultString = Request("dumpState", requestArgs.dump());
  LOG(DEBUG) << "dumpState(" << requestArgs.dump().c_str() << ")\n" << resultString.c_str() << "\n";
  /*
       * An example resonse:
       *
      {
        "HMI": {
        },
        "APP": [
          "1.Media.Pandora.granted.NotPlaying",
          "2.Media.AM..NotPlaying"
        ]
      }
      */
  //Row format:
  //"%d.%s.%s.%s.%s", obj.sessionId, obj.stream.streamType, obj.stream.streamName, obj.focus, obj.stream.playing and "playing" or "NotPlaying")

  try {
    auto result = json::parse(resultString);
    for (auto &sessionRecord : result["APP"].get_ref<json::array_t &>()) {
      auto sessionStr = sessionRecord.get<std::string>();
      //Stream names have no spaces so it's safe to do this
      std::replace(sessionStr.begin(), sessionStr.end(), '.', ' ');
      std::istringstream sessionIStr(sessionStr);

      int sessionId;
      std::string streamName, streamType;

      if (!(sessionIStr >> sessionId >> streamType >> streamName)) {
        LOG(WARNING) << "Can't parse line \"" << sessionRecord.get<std::string>().c_str() << "\"";
        continue;
      }

      printf("Found stream %s session id %i\n", streamName.c_str(), sessionId);
      if (streamName == aaStreamName) {
        if (aaSessionID < 0)
          aaSessionID = sessionId;
        else
          aaTransientSessionID = sessionId;
      } else {
        //We have two so this doesn't work
        streamToSessionIds[streamName] = sessionId;
      }
    }
    // Create and register stream (only if we need to)
    if (aaSessionID < 0 || aaTransientSessionID < 0) {
      aaRegisterStream();
    }
  }
  catch (const std::domain_error &ex) {
    LOG(ERROR) << "Failed to parse state json: " << ex.what();
    LOG(ERROR) << resultString.c_str();
  }
  catch (const std::invalid_argument &ex) {
    LOG(ERROR) << "Failed to parse state json: " << ex.what();
    LOG(ERROR) << resultString.c_str();
  }
}

AudioManagerClient::AudioManagerClient(DBus::Connection &connection, AudioSignals::Pointer audiosignals)
    : DBus::ObjectProxy(connection,
                        "/com/xse/service/AudioManagement/AudioApplication",
                        "com.xsembedded.service.AudioManagement"), audiosignals_(std::move(audiosignals)) {
  populateStreamTable();
  if (aaSessionID < 0 || aaTransientSessionID < 0) {
    LOG(ERROR) << "Can't find audio stream. Audio will not work";
  } else {
    audiosignals_->focusRelease.connect(sigc::mem_fun(*this, &AudioManagerClient::audioMgrReleaseAudioFocus));
    audiosignals_->focusRequest.connect(sigc::mem_fun(*this, &AudioManagerClient::audioMgrRequestAudioFocus));
  }
}

AudioManagerClient::~AudioManagerClient() {
  if (currentFocus != FocusType::NONE && previousSessionID >= 0) {
    json args = {{"sessionId", previousSessionID}};
    std::string result = Request("requestAudioFocus", args.dump());
    LOG(DEBUG) << "requestAudioFocus(" << args.dump().c_str() << ")\n" << result.c_str() << "\n";
  }

  for (int session : {aaSessionID, aaTransientSessionID}) {
    if (session >= 0) {
      json args = {{"sessionId", session}};
      std::string result = Request("closeSession", args.dump());
      LOG(DEBUG) << "closeSession(" << args.dump().c_str() << ")\n" << result.c_str() << "\n";
    }
  }
}

bool AudioManagerClient::canSwitchAudio() const { return aaSessionID >= 0 && aaTransientSessionID >= 0; }

std::map<aasdk::proto::enums::AudioFocusType_Enum, FocusType> AAFocusToFocusType = {
    {aasdk::proto::enums::AudioFocusType_Enum_NONE, FocusType::NONE},
    {aasdk::proto::enums::AudioFocusType_Enum_GAIN_TRANSIENT, FocusType::TRANSIENT},
    {aasdk::proto::enums::AudioFocusType_Enum_GAIN, FocusType::PERMANENT}
};

std::map<aasdk::proto::enums::AudioFocusType_Enum, aasdk::proto::enums::AudioFocusState_Enum> TypeToState = {
    {aasdk::proto::enums::AudioFocusType_Enum_NONE, aasdk::proto::enums::AudioFocusState_Enum_NONE},
    {aasdk::proto::enums::AudioFocusType_Enum_GAIN_TRANSIENT, aasdk::proto::enums::AudioFocusState_Enum_GAIN_TRANSIENT},
    {aasdk::proto::enums::AudioFocusType_Enum_GAIN, aasdk::proto::enums::AudioFocusState_Enum_GAIN}
};

void AudioManagerClient::audioMgrRequestAudioFocus(aasdk::proto::enums::AudioFocusType_Enum aa_type) {
  FocusType type = AAFocusToFocusType[aa_type];
  if (type == FocusType::NONE) {
    audioMgrReleaseAudioFocus();
    return;
  }
  LOG(INFO) << "audioMgrRequestAudioFocus(" << int(type) << ")";
  if (currentFocus == type) {
    audiosignals_->focusChanged.emit(TypeToState[aa_type]);
    return;
  }
  if (!inCall) {
    if (currentFocus == FocusType::NONE && type == FocusType::PERMANENT) {
      waitingForFocusLostEvent = true;
      previousSessionID = -1;
    }
    json args = {{"sessionId", type == FocusType::TRANSIENT ? aaTransientSessionID : aaSessionID}};
    try {
      std::string result = Request("requestAudioFocus", args.dump());
      LOG(DEBUG) << "requestAudioFocus(" << args.dump().c_str() << ")\n" << result.c_str();
    }
    catch (DBus::Error &e) {
      LOG(ERROR) << e.what();
    }
  }
}

void AudioManagerClient::audioMgrReleaseAudioFocus() {
  LOG(INFO) << "audioMgrReleaseAudioFocus()";
  std::string method;
  json args;
  if (currentFocus == FocusType::NONE) {
    //nothing to do
    audiosignals_->focusChanged.emit(aasdk::proto::enums::AudioFocusState_Enum_LOSS);
  } else if (currentFocus == FocusType::PERMANENT && previousSessionID >= 0) {
    //We released the last one, give up audio focus for real
    args = {{"sessionId", previousSessionID}};
    method = "requestAudioFocus";
    previousSessionID = -1;
  } else if (currentFocus == FocusType::TRANSIENT) {
    args = {{"sessionId", aaTransientSessionID}};
    method = "abandonAudioFocus";
    previousSessionID = -1;
  } else {
    currentFocus = FocusType::NONE;
    audiosignals_->focusChanged.emit(aasdk::proto::enums::AudioFocusState_Enum_LOSS);
  }
  if (!method.empty()) {
    try {
      std::string result = Request(method, args.dump());
      LOG(DEBUG) << method << "(" << args.dump() << ")\n" << result;

    }
    catch (DBus::Error &e) {
      LOG(ERROR) << e.what();
    }
  }
}

void AudioManagerClient::Notify(const std::string &signalName, const std::string &payload) {
  LOG(INFO) << "AudioManagerClient::Notify signalName=" << signalName.c_str() << " payload=" << payload.c_str();
  if (signalName == "audioFocusChangeEvent") {
    try {
      auto result = json::parse(payload);
      auto streamName = result["streamName"].get<std::string>();
      auto newFocus = result["newFocus"].get<std::string>();
      auto focusType = result["focusType"].get<std::string>();
      auto streamType = result["streamType"].get<std::string>();

      if (streamType == "Telephony") {
        if (newFocus == "gained") {
          inCall = true;
          LOG(DEBUG) << "In Call";
        } else if (newFocus == "lost") {
          inCall = false;
          LOG(DEBUG) << "Left Call";
        }
      }

      int eventSessionID = -1;
      if (streamName == aaStreamName) {
        if (focusType == "permanent") {
          eventSessionID = aaSessionID;
        } else {
          eventSessionID = aaTransientSessionID;
        }
        LOG(DEBUG) << "Found audio sessionId " << eventSessionID << " for stream " << streamName.c_str();
      } else {
        auto findIt = streamToSessionIds.find(streamName);
        if (findIt != streamToSessionIds.end()) {
          eventSessionID = findIt->second;
          LOG(DEBUG) << "Found audio sessionId " << eventSessionID \
 << " for stream " << streamName.c_str() << " with focusType " << focusType.c_str() \
 << " & newFocus " << newFocus.c_str();
        } else {
          LOG(ERROR) << "Can't find audio sessionId for stream " << streamName.c_str();
        }
      }

      if (eventSessionID >= 0) {
        if (waitingForFocusLostEvent && newFocus == "lost") {
          previousSessionID = eventSessionID;
          waitingForFocusLostEvent = false;
        }

        FocusType newFocusType = currentFocus;
        if (newFocus != "gained") {
          if (eventSessionID == aaSessionID || eventSessionID == aaTransientSessionID) {
            newFocusType = FocusType::NONE;
          }
        } else {
          if (eventSessionID == aaTransientSessionID) {
            newFocusType = FocusType::TRANSIENT;
          } else if (eventSessionID == aaSessionID) {
            newFocusType = FocusType::PERMANENT;
          }
        }

        if (currentFocus != newFocusType) {
          currentFocus = newFocusType;
          aasdk::proto::enums::AudioFocusState_Enum currentstate;
          switch (currentFocus) {
            case FocusType::NONE:currentstate = aasdk::proto::enums::AudioFocusState_Enum_LOSS;
              break;
            case FocusType::PERMANENT:currentstate = aasdk::proto::enums::AudioFocusState_Enum_GAIN;
              break;
            case FocusType::TRANSIENT:currentstate = aasdk::proto::enums::AudioFocusState_Enum_GAIN_TRANSIENT;
              break;
          }
          audiosignals_->focusChanged.emit(currentstate);
        }
      }
    }
    catch (const std::domain_error &ex) {
      LOG(ERROR) << "Failed to parse state json: " << ex.what();
    }
    catch (const std::invalid_argument &ex) {
      LOG(ERROR) << "Failed to parse state json: " << ex.what();
    }
  }
}