#include <set>
#include <sdbus-c++/sdbus-c++.h>

#include <autoapp/Signals/AudioSignals.hpp>

#include <Mazda/Dbus/com.xsembedded.ServiceProvider.h>

#include <thread>

struct Stream {
  std::string name;
  int id;
  aasdk::messenger::ChannelId channelId;
  bool focus = false;
  std::string mode;
  std::string type;
};

class AudioManagerClient final : public sdbus::ProxyInterfaces<com::xsembedded::ServiceProvider_proxy> {
 private:
  AudioSignals::Pointer audiosignals_;
  bool inCall = false;
  std::vector<std::string> MazdaDestinations;
  std::map<aasdk::messenger::ChannelId, Stream *> streams;
  std::map<std::string, int> ExistingStreams;
  std::map<int, Stream *> streamsByID;

  std::thread dbus_thread;
  std::unique_ptr<sdbus::IConnection> connection;

  void RegisterStream(std::string StreamName,
                      aasdk::messenger::ChannelId ChannelId,
                      std::string StreamMode,
                      std::string StreamType);

  void populateData();

  void populateStreamTable();

  void print_dbus(sdbus::MethodCall call);
  void listen_thread();

 public:
  AudioManagerClient(std::string destination, std::string objectPath, AudioSignals::Pointer audiosignals);

  ~AudioManagerClient();

  //calling requestAudioFocus directly doesn't work on the audio mgr
  void audioMgrRequestAudioFocus(aasdk::messenger::ChannelId, aasdk::proto::enums::AudioFocusType_Enum aa_type);

  void audioMgrReleaseAudioFocus(aasdk::messenger::ChannelId);

  void onNotify(const std::string &signalName, const std::string &payload) override {};

};