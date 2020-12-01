#include <set>

#include <f1x/openauto/autoapp/Signals/AudioSignals.hpp>


#include <Mazda/Dbus/com.xsembedded.ServiceProvider.h>

class AudioManagerClient : public com::xsembedded::ServiceProvider_proxy,
                           public DBus::ObjectProxy {
private:
    std::map<std::string, int> streamToSessionIds;
    std::string aaStreamName = "MLENT";
    int aaSessionID = -1;
    int aaTransientSessionID = -1;
    int previousSessionID = -1;
    bool waitingForFocusLostEvent = false;
    FocusType currentFocus = FocusType::NONE;
    AudioSignals::Pointer as;

    //These IDs are usually the same, but they depend on the startup order of the services on the car so we can't assume them 100% reliably
    void populateStreamTable();

    void aaRegisterStream();

public:
    AudioManagerClient(DBus::Connection &connection, AudioSignals::Pointer audioSignals);

    ~AudioManagerClient();

    bool canSwitchAudio();

    //calling requestAudioFocus directly doesn't work on the audio mgr
    void audioMgrRequestAudioFocus(aasdk::proto::enums::AudioFocusType_Enum aa_type);

    void audioMgrReleaseAudioFocus();

    void Notify(const std::string &signalName, const std::string &payload) override;
};