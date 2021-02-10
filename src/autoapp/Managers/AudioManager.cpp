#include <autoapp/Managers/AudioManager.hpp>
#include <nlohmann/json.hpp>
#include <easylogging++.h>
#include <thread>

using json = nlohmann::json;

void AudioManagerClient::print_dbus(sdbus::MethodCall call) {
  std::string func;
  std::string args;
  call >> func;
  call >> args;
  LOG(DEBUG) << func << " " << args;
  auto result = json::parse(args);
  if (streamsByID.count(result["sessionId"].get<int>())) {
    auto stream = streamsByID[result["sessionId"].get<int>()];
    if (func == "onRequestAudioFocusResult") {
      if (result["newFocus"].get<std::string>() == "granted") {
        stream->focus = true;
        switch (stream->channelId) {
          case aasdk::messenger::ChannelId::MEDIA_AUDIO:
            audiosignals_->focusChanged.emit(stream->channelId,
                                             aasdk::proto::enums::AudioFocusState::GAIN_MEDIA_ONLY);
            break;
          case aasdk::messenger::ChannelId::SPEECH_AUDIO:
            audiosignals_->focusChanged.emit(stream->channelId,
                                             aasdk::proto::enums::AudioFocusState::GAIN_TRANSIENT_GUIDANCE_ONLY);
            break;
          case aasdk::messenger::ChannelId::SYSTEM_AUDIO:
            audiosignals_->focusChanged.emit(stream->channelId,
                                             aasdk::proto::enums::AudioFocusState::GAIN_TRANSIENT);
            break;
          default:break;
        }
      } else {
        stream->focus = false;
        audiosignals_->focusChanged.emit(stream->channelId,
                                         aasdk::proto::enums::AudioFocusState::NONE);
      }
    } else if (func == "onAudioFocusChange") {
      auto focus = result["newFocus"].get<std::string>();
      if (focus == "lost") {
        stream->focus = false;
        audiosignals_->focusChanged.emit(stream->channelId,
                                         aasdk::proto::enums::AudioFocusState::LOSS);
      } else if (focus == "temporarilyLost") {
        stream->focus = false;
        audiosignals_->focusChanged.emit(stream->channelId,
                                         aasdk::proto::enums::AudioFocusState::LOSS_TRANSIENT);
      }
    }
  }
}

void AudioManagerClient::listen_thread() {
  // Create D-Bus connection to the system bus and requests name on it.
  const char *serviceName = "com.androidauto.audio";
  connection = sdbus::createSystemBusConnection(serviceName);

  // Create concatenator D-Bus object.
  const char *objectPath = "/com/androidauto/audio";
  auto audio_callback = sdbus::createObject(*connection, objectPath);

  // Register D-Bus methods and signals on the concatenator object, and exports the object.
  const char *interfaceName = "com.xsembedded.ServiceProvider";
  audio_callback->registerMethod(interfaceName, "Request", "ss", "",
                                 [&](sdbus::MethodCall call) { print_dbus(std::move(call)); });
  audio_callback->finishRegistration();

  // Run the I/O event loop on the bus connection.
  connection->enterEventLoop();
}

void AudioManagerClient::RegisterStream(std::string StreamName,
                                        aasdk::messenger::ChannelId ChannelId,
                                        std::string StreamMode,
                                        std::string StreamType) {
  if (!(StreamMode == "permanent" || StreamMode == "transient")) {
    return;
  }
  if (std::find(MazdaDestinations.begin(), MazdaDestinations.end(), StreamType) == MazdaDestinations.end()) {
    return;
  }
//  if (ExistingStreams.count(StreamName)) {
//    auto stream = new Stream;
//    stream->name.assign(StreamName);
//    stream->id = ExistingStreams[StreamName];
//    stream->mode = StreamMode;
//    stream->type = StreamType;
//    streams.insert(std::pair<aasdk::messenger::ChannelId, Stream>(ChannelId, *stream));
//    return;
//  }
  // First open a new Stream
  json sessArgs = {
      {"busName", "com.androidauto.audio"},
      {"objectPath", "/com/androidauto/audio"},
      {"destination", "Cabin"}
  };
  try {
    std::string sessString = Request("openSession", sessArgs.dump());
    LOG(DEBUG) << "openSession(" << sessArgs.dump().c_str() << ")\n" << sessString.c_str() << "\n";
    int SessionID = json::parse(sessString)["sessionId"];

    // Register the stream
    json regArgs = {
        {"sessionId", SessionID},
        {"streamName", StreamName},
        // { "streamModeName", aaStreamName },
        {"focusType", StreamMode},
        {"streamType", StreamType}
    };
    std::string regString = Request("registerAudioStream", regArgs.dump());
    LOG(DEBUG) << "registerAudioStream(" << regArgs.dump().c_str() << ")\n" << regString.c_str() << "\n";
    // Stream is registered add it to the array
    auto stream = new Stream;
    stream->name.assign(StreamName);
    stream->id = SessionID;
    stream->mode = StreamMode;
    stream->type = StreamType;
    stream->channelId = ChannelId;
    streams.insert(std::pair<aasdk::messenger::ChannelId, Stream *>(ChannelId, stream));
    streamsByID.insert(std::pair<int, Stream *>(SessionID, stream));
  }
  catch (const std::domain_error &ex) {
    LOG(ERROR) << "Failed to parse state json: " << ex.what();
  }
  catch (const std::invalid_argument &ex) {
    LOG(ERROR) << "Failed to parse state json: " << ex.what();
  }

}

void AudioManagerClient::populateData() {
  json requestArgs = {
      {"svc", "DEST"},
      {"pretty", false}
  };
  std::string resultString = Request("dumpState", requestArgs.dump());
  LOG(DEBUG) << "dumpState(" << requestArgs.dump().c_str() << ")\n" << resultString.c_str() << "\n";
  try {
    auto result = json::parse(resultString);
    for (json::iterator it = result["Cabin"]["reqMatrixIdx"].begin(); it != result["Cabin"]["reqMatrixIdx"].end();
         ++it) {
      MazdaDestinations.emplace_back(it.key());
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
  for (auto &Dest : MazdaDestinations)
    LOG(DEBUG) << Dest;
}

void AudioManagerClient::populateStreamTable() {
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

      LOG(DEBUG) << "Found stream " << streamName.c_str() << " session id " << sessionId;
      ExistingStreams.insert(std::pair<std::string, int>(streamName, sessionId));
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

AudioManagerClient::AudioManagerClient(std::string destination,
                                       std::string objectPath,
                                       AudioSignals::Pointer audiosignals)
    : sdbus::ProxyInterfaces<com::xsembedded::ServiceProvider_proxy>(std::move(destination), std::move(objectPath)),
      audiosignals_(std::move(audiosignals)) {
  registerProxy();
  populateData();
  populateStreamTable();
  RegisterStream("MLENT", aasdk::messenger::ChannelId::MEDIA_AUDIO, "permanent", "Media");
  RegisterStream("SYSVR", aasdk::messenger::ChannelId::SYSTEM_AUDIO, "transient", "VR");
  RegisterStream("Navi", aasdk::messenger::ChannelId::SPEECH_AUDIO, "transient", "InfoMix");
  for (auto &stream : streams)
    LOG(DEBUG) << aasdk::messenger::channelIdToString(stream.first) << " " << stream.second->id << ": "
               << stream.second->name;

  audiosignals_->focusRelease.connect(sigc::mem_fun(*this, &AudioManagerClient::audioMgrReleaseAudioFocus));
  audiosignals_->focusRequest.connect(sigc::mem_fun(*this, &AudioManagerClient::audioMgrRequestAudioFocus));
  dbus_thread = std::thread(&AudioManagerClient::listen_thread, this);

}

AudioManagerClient::~AudioManagerClient() {
  for (auto &stream : streams) {
    if (stream.second->id >= 0) {
      audioMgrReleaseAudioFocus(stream.first);
      json args = {{"sessionId", stream.second->id}};
      std::string result = Request("closeSession", args.dump());
      LOG(DEBUG) << "closeSession(" << args.dump().c_str() << ")\n" << result.c_str() << "\n";
    }
    stream.second->id = -1;
  }
  connection->leaveEventLoop();
  dbus_thread.join();
  unregisterProxy();
}

void AudioManagerClient::audioMgrRequestAudioFocus(aasdk::messenger::ChannelId channel_id,
                                                   aasdk::proto::enums::AudioFocusType_Enum aa_type) {
  if (streams.count(channel_id)) {
    if (!streams[channel_id]->focus) {
      json args = {{"sessionId", streams[channel_id]->id}};
      LOG(DEBUG) << args;
      try {
        std::string result = Request("requestAudioFocus", args.dump());
        LOG(DEBUG) << "requestAudioFocus(" << args.dump().c_str() << ")\n" << result.c_str();
      }
      catch (sdbus::Error &e) {
        LOG(ERROR) << e.what();
      }
    } else {
      switch (channel_id) {
        case aasdk::messenger::ChannelId::MEDIA_AUDIO:
          audiosignals_->focusChanged.emit(channel_id,
                                           aasdk::proto::enums::AudioFocusState::GAIN_MEDIA_ONLY);
          break;
        case aasdk::messenger::ChannelId::SPEECH_AUDIO:
          audiosignals_->focusChanged.emit(channel_id,
                                           aasdk::proto::enums::AudioFocusState::GAIN_TRANSIENT_GUIDANCE_ONLY);
          break;
        case aasdk::messenger::ChannelId::SYSTEM_AUDIO:
          audiosignals_->focusChanged.emit(channel_id,
                                           aasdk::proto::enums::AudioFocusState::GAIN_TRANSIENT);
          break;
        default:break;
      }
    }
  }
}

void AudioManagerClient::audioMgrReleaseAudioFocus(aasdk::messenger::ChannelId channel_id) {
  LOG(INFO) << "audioMgrReleaseAudioFocus()";
  if (streams.count(channel_id)) {
    if (streams[channel_id]->focus) {
      json args = {{"sessionId", streams[channel_id]->id}};
      LOG(DEBUG) << args;
      try {
        std::string result = Request("abandonAudioFocus", args.dump());
        LOG(DEBUG) << "abandonAudioFocus(" << args.dump().c_str() << ")\n" << result.c_str();
      }
      catch (sdbus::Error &e) {
        LOG(ERROR) << e.what();
      }
    }
  }
}