#include <set>
#include <dbus-cxx.h>

#include <autoapp/Signals/AudioSignals.hpp>

#include <com_xsembedded_ServiceProvider_objectProxy.h>

#include <thread>

struct Stream {
  std::string name;
  int id;
  aasdk::messenger::ChannelId channelId;
  bool focus = false;
  std::string mode;
  std::string type;
};

//class AudioReciever
//: public DBus::ObjectProxy {
//public:
//    AudioProxy(std::shared_ptr<DBus::Connection> conn, std::string dest = "com.xsembedded.ServiceProvider", std::string path = "/com/xse/service/AudioManagement/AudioApplication" ) : DBus::ObjectProxy( conn, dest, path ){
//m_com_xsembedded_ServiceProviderProxy = com_xsembedded_ServiceProviderProxy::create( "com.xsembedded.ServiceProvider" );
//this->add_interface( m_com_xsembedded_ServiceProviderProxy );
//
//}
//public:
//{
//std::shared_ptr<NONAMEProxy> created = std::shared_ptr<NONAMEProxy>( new NONAMEProxy( conn, dest, path ) );
//conn->register_object_proxy( created, signalCallingThread );
//return created;
//
//}
//{
//return m_com_xsembedded_ServiceProviderProxy;
//
//}
//protected:
//std::shared_ptr<com_xsembedded_ServiceProviderProxy> m_com_xsembedded_ServiceProviderProxy;
//};


class AudioManagerClient {
 private:
  AudioSignals::Pointer audiosignals_;
  bool inCall = false;
  std::vector<std::string> MazdaDestinations;
  std::map<aasdk::messenger::ChannelId, Stream *> streams;
  std::map<std::string, int> ExistingStreams;
  std::map<int, Stream *> streamsByID;

  std::shared_ptr<com_xsembedded_ServiceProvider_objectProxy> AudioInterface;
  std::shared_ptr<com_xsembedded_ServiceProviderProxy> AudioProxy;
  std::shared_ptr<DBus::Object> AudioObject;

//  std::thread dbus_thread;
//  std::shared_ptr<DBus::Connection> connection;


  std::shared_ptr<DBus::Connection> connection;

  std::shared_ptr<DBus::ObjectProxy> object;

  void RegisterStream(std::string StreamName,
                      aasdk::messenger::ChannelId ChannelId,
                      std::string StreamMode,
                      std::string StreamType);

  void populateData();

  void populateStreamTable();

  std::string RequestHandler(std::string methodName, std::string arguments);
//  void listen_thread();

 public:
  AudioManagerClient(AudioSignals::Pointer audiosignals, const std::shared_ptr<DBus::Connection> &);

  ~AudioManagerClient();

  //calling requestAudioFocus directly doesn't work on the audio mgr
  void audioMgrRequestAudioFocus(aasdk::messenger::ChannelId, aasdk::proto::enums::AudioFocusType_Enum aa_type);

  void audioMgrReleaseAudioFocus(aasdk::messenger::ChannelId);

  void onNotify(const std::string &signalName, const std::string &payload);

};