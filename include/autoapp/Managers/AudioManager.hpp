#include <set>
#include <sdbus-c++/sdbus-c++.h>

#include <autoapp/Signals/AudioSignals.hpp>

#include <Mazda/Dbus/com.xsembedded.ServiceProvider.h>

class AudioManagerClient final : public sdbus::ProxyInterfaces<com::xsembedded::ServiceProvider_proxy> {
 private:
  std::map<std::string, int> streamToSessionIds;
  std::string aaStreamName = "MLENT";
  int aaSessionID = -1;
  int aaTransientSessionID = -1;
  int previousSessionID = -1;
  bool waitingForFocusLostEvent = false;
  FocusType currentFocus = FocusType::NONE;
  AudioSignals::Pointer audiosignals_;
  bool inCall = false;

  //These IDs are usually the same, but they depend on the startup order of the services on the car so we can't assume them 100% reliably
  void populateStreamTable();

  void aaRegisterStream();

 public:
  AudioManagerClient(std::string destination, std::string objectPath, AudioSignals::Pointer audiosignals);

  ~AudioManagerClient();

  bool canSwitchAudio() const;

  //calling requestAudioFocus directly doesn't work on the audio mgr
  void audioMgrRequestAudioFocus(aasdk::proto::enums::AudioFocusType_Enum aa_type);

  void audioMgrReleaseAudioFocus();

  void onNotify(const std::string &signalName, const std::string &payload) override;
};