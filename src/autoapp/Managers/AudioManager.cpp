#include <f1x/openauto/autoapp/Managers/AudioManager.hpp>
#include <json.hpp>
#include <easylogging++.h>

using json = nlohmann::json;

//void MazdaEventCallbacks::AudioFocusRequest(int chan, const HU::AudioFocusRequest &request)  {
//
//    run_on_main_thread([this, request](){
//        //The chan passed here is always AA_CH_CTR but internally we pass the channel AA means
//        if (request.focus_type() == HU::AudioFocusRequest::AUDIO_FOCUS_RELEASE) {
//            audioMgrClient->audioMgrReleaseAudioFocus();
//        } else {
//            if (!inCall) {
//                if (request.focus_type() == HU::AudioFocusRequest::AUDIO_FOCUS_GAIN_TRANSIENT) { // || request.focus_type() == HU::AudioFocusRequest::AUDIO_FOCUS_GAIN_NAVI) {
//                    audioMgrClient->audioMgrRequestAudioFocus(AudioManagerClient::FocusType::TRANSIENT); //assume media
//                } else if (request.focus_type() == HU::AudioFocusRequest::AUDIO_FOCUS_GAIN) {
//                    audioMgrClient->audioMgrRequestAudioFocus(AudioManagerClient::FocusType::PERMANENT); //assume media
//                }
//            } else {
//                logw("Tried to request focus %i but was in a call", (int)request.focus_type());
//            }
//        }
//
//        return false;
//    });
//}
//
//void MazdaEventCallbacks::AudioFocusHappend(AudioManagerClient::FocusType type) {
//    printf("AudioFocusHappend(%i)\n", int(type));
//    audioFocus = type;
//    HU::AudioFocusResponse response;
//    switch(type) {
//        case AudioManagerClient::FocusType::NONE:
//            response.set_focus_type(HU::AudioFocusResponse::AUDIO_FOCUS_STATE_LOSS);
//            break;
//        case AudioManagerClient::FocusType::PERMANENT:
//            response.set_focus_type(HU::AudioFocusResponse::AUDIO_FOCUS_STATE_GAIN);
//            break;
//        case AudioManagerClient::FocusType::TRANSIENT:
//            response.set_focus_type(HU::AudioFocusResponse::AUDIO_FOCUS_STATE_GAIN_TRANSIENT);
//            break;
//    }
//    g_hu->hu_queue_command([response](IHUConnectionThreadInterface & s) {
//        s.hu_aap_enc_send_message(0, AA_CH_CTR, HU_PROTOCOL_MESSAGE::AudioFocusResponse, response);
//    });
//    logd("Sent channel %i HU_PROTOCOL_MESSAGE::AudioFocusResponse %s\n", AA_CH_CTR,  HU::AudioFocusResponse::AUDIO_FOCUS_STATE_Name(response.focus_type()).c_str());
//}

void AudioManagerClient::aaRegisterStream() {
    // First open a new Stream
    json sessArgs = {
            {"busName",     "com.jci.usbm_am_client"},
            {"objectPath",  "/com/jci/usbm_am_client"},
            {"destination", "Cabin"}
    };
    if (aaSessionID < 0) {
        try {
            std::string sessString = Request("openSession", sessArgs.dump());
            LOG(DEBUG) << "openSession(" <<  sessArgs.dump().c_str() << ")\n" << sessString.c_str() << "\n";
            aaSessionID = json::parse(sessString)["sessionId"];

            // Register the stream
            json regArgs = {
                    {"sessionId",  aaSessionID},
                    {"streamName", aaStreamName},
                    // { "streamModeName", aaStreamName },
                    {"focusType",  "permanent"},
                    {"streamType", "Media"}
            };
            std::string regString = Request("registerAudioStream", regArgs.dump());
            LOG(DEBUG) << "registerAudioStream(" << regArgs.dump().c_str() << ")\n" << regString.c_str() << "\n";
        }
        catch (const std::domain_error &ex) {
            LOG(ERROR) << "Failed to parse state json: " << ex.what();
        }
        catch (const std::invalid_argument &ex) {
            LOG(ERROR)  << "Failed to parse state json: " << ex.what();
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
                    {"sessionId",  aaTransientSessionID},
                    {"streamName", aaStreamName},
                    // { "streamModeName", aaStreamName },
                    {"focusType",  "transient"},
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

void AudioManagerClient::populateStreamTable()
{
    streamToSessionIds.clear();
    json requestArgs = {
            { "svc", "SRCS" },
            { "pretty", false }
    };
    std::string resultString = Request("dumpState", requestArgs.dump());
    LOG(DEBUG) << "dumpState("<< requestArgs.dump().c_str() << ")\n" << resultString.c_str() << "\n";
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

    try
    {
        auto result = json::parse(resultString);
        for (auto& sessionRecord : result["APP"].get_ref<json::array_t&>())
        {
            std::string sessionStr = sessionRecord.get<std::string>();
            //Stream names have no spaces so it's safe to do this
            std::replace(sessionStr.begin(), sessionStr.end(), '.', ' ');
            std::istringstream sessionIStr(sessionStr);

            int sessionId;
            std::string streamName, streamType;

            if (!(sessionIStr >> sessionId >> streamType >> streamName))
            {
                LOG(WARNING) << "Can't parse line \"" << sessionRecord.get<std::string>().c_str() <<"\"";
                continue;
            }

            printf("Found stream %s session id %i\n", streamName.c_str(), sessionId);
            if(streamName == aaStreamName)
            {
                if (aaSessionID < 0)
                    aaSessionID = sessionId;
                else
                    aaTransientSessionID = sessionId;
            }
            else
            {
                //We have two so this doesn't work
                streamToSessionIds[streamName] = sessionId;
            }
        }
        // Create and register stream (only if we need to)
        if (aaSessionID < 0 || aaTransientSessionID < 0)
        {
            aaRegisterStream();
        }
    }
    catch (const std::domain_error& ex)
    {
        LOG(ERROR) << "Failed to parse state json: " << ex.what();
        LOG(ERROR) << resultString.c_str();
    }
    catch (const std::invalid_argument& ex)
    {
        LOG(ERROR) << "Failed to parse state json: " << ex.what();
        LOG(ERROR) << resultString.c_str();
    }
}

AudioManagerClient::AudioManagerClient(DBus::Connection &connection, AudioSignals::Pointer audioSignals)
        : DBus::ObjectProxy(connection, "/com/xse/service/AudioManagement/AudioApplication", "com.xsembedded.service.AudioManagement")
        , as(std::move(audioSignals))
{
    populateStreamTable();
    if (aaSessionID < 0 || aaTransientSessionID < 0)
    {
        LOG(ERROR) << "Can't find audio stream. Audio will not work";
    }
}

AudioManagerClient::~AudioManagerClient()
{
    if (currentFocus != FocusType::NONE && previousSessionID >= 0)
    {
        json args = { { "sessionId", previousSessionID } };
        std::string result = Request("requestAudioFocus", args.dump());
        LOG(DEBUG) << "requestAudioFocus(" << args.dump().c_str() << ")\n" << result.c_str() << "\n";
    }

    for (int session : {aaSessionID, aaTransientSessionID })
    {
        if (session >= 0)
        {
            json args = { { "sessionId", session } };
            std::string result = Request("closeSession", args.dump());
            LOG(DEBUG) << "closeSession(" << args.dump().c_str() <<")\n" << result.c_str() << "\n";
        }
    }
}

bool AudioManagerClient::canSwitchAudio() { return aaSessionID >= 0 && aaTransientSessionID >= 0; }

void AudioManagerClient::audioMgrRequestAudioFocus(FocusType type)
{
    if (type == FocusType::NONE)
    {
        audioMgrReleaseAudioFocus();
        return;
    }
    printf("audioMgrRequestAudioFocus(%i)\n", int(type));
    if (currentFocus == type)
    {
        as->focusChanged.emit(currentFocus);
        return;
    }

    if (currentFocus == FocusType::NONE && type == FocusType::PERMANENT)
    {
        waitingForFocusLostEvent = true;
        previousSessionID = -1;
    }
    json args = { { "sessionId", type == FocusType::TRANSIENT ? aaTransientSessionID : aaSessionID } };
    std::string result = Request("requestAudioFocus", args.dump());
    LOG(DEBUG) << "requestAudioFocus(" << args.dump().c_str() << ")\n" << result.c_str() << "\n";
}

void AudioManagerClient::audioMgrReleaseAudioFocus()
{
    printf("audioMgrReleaseAudioFocus()\n");
    if (currentFocus == FocusType::NONE)
    {
        //nothing to do
        as->focusChanged.emit(currentFocus);
    }
    else if (currentFocus == FocusType::PERMANENT && previousSessionID >= 0)
    {
        //We released the last one, give up audio focus for real
        json args = { { "sessionId", previousSessionID } };
        std::string result = Request("requestAudioFocus", args.dump());
        LOG(DEBUG) << "requestAudioFocus(" << args.dump().c_str() << ")\n" << result.c_str() << "\n";
        previousSessionID = -1;
    }
    else if (currentFocus == FocusType::TRANSIENT)
    {
        json args = { { "sessionId", aaTransientSessionID } };
        std::string result = Request("abandonAudioFocus", args.dump());
        LOG(DEBUG) << "abandonAudioFocus(" << args.dump().c_str() << ")\n" << result.c_str() << "\n";
        previousSessionID = -1;
    }
    else
    {
        currentFocus = FocusType::NONE;
        as->focusChanged.emit(currentFocus);
    }
}

void AudioManagerClient::Notify(const std::string &signalName, const std::string &payload)
{
    printf("AudioManagerClient::Notify signalName=%s payload=%s\n", signalName.c_str(), payload.c_str());
    if (signalName == "audioFocusChangeEvent")
    {
        try
        {
            auto result = json::parse(payload);
            std::string streamName = result["streamName"].get<std::string>();
            std::string newFocus = result["newFocus"].get<std::string>();
            std::string focusType = result["focusType"].get<std::string>();

            int eventSessionID = -1;
            if (streamName == aaStreamName)
            {
                if (focusType == "permanent")
                {
                    eventSessionID = aaSessionID;
                }
                else
                {
                    eventSessionID = aaTransientSessionID;
                }
                LOG(DEBUG) << "Found audio sessionId "<< eventSessionID << " for stream " << streamName.c_str();
            }
            else
            {
                auto findIt = streamToSessionIds.find(streamName);
                if (findIt != streamToSessionIds.end())
                {
                    eventSessionID = findIt->second;
                    LOG(DEBUG) << "Found audio sessionId " << eventSessionID \
                    << " for stream " << streamName.c_str() << " with focusType " << focusType.c_str() \
                    << " & newFocus " << newFocus.c_str();
                }
                else
                {
                    LOG(ERROR)  << "Can't find audio sessionId for stream " << streamName.c_str();
                }
            }

            if (eventSessionID >= 0)
            {
                if (waitingForFocusLostEvent && newFocus == "lost")
                {
                    previousSessionID = eventSessionID;
                    waitingForFocusLostEvent = false;
                }

                FocusType newFocusType = currentFocus;
                if (newFocus != "gained")
                {
                    if (eventSessionID == aaSessionID || eventSessionID == aaTransientSessionID)
                    {
                        newFocusType = FocusType::NONE;
                    }
                }
                else
                {
                    if (eventSessionID == aaTransientSessionID)
                    {
                        newFocusType = FocusType::TRANSIENT;
                    }
                    else if (eventSessionID == aaSessionID)
                    {
                        newFocusType = FocusType::PERMANENT;
                    }
                }

                if (currentFocus != newFocusType)
                {
                    currentFocus = newFocusType;
                    as->focusChanged.emit(currentFocus);
                }
            }
        }
        catch (const std::domain_error& ex)
        {
            LOG(ERROR) << "Failed to parse state json: " << ex.what();
        }
        catch (const std::invalid_argument& ex)
        {
            LOG(ERROR) << "Failed to parse state json: " << ex.what();
        }
    }
}