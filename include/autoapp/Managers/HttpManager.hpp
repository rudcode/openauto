#pragma once

#include "server_http.hpp"
#include <future>

// Added for the default_resource example
#include <algorithm>
#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>

#include <autoapp/Signals/Signals.hpp>

using HttpServer = SimpleWeb::Server<SimpleWeb::HTTP>;

class HttpManager {
 public:
  HttpManager(asio::io_service &ioService,
              VideoSignals::Pointer videosignals,
              AudioSignals::Pointer audiosignals,
              AASignals::Pointer aasignals);
  ~HttpManager();
  void stop();
 private:
  bool has_video_focus = false;
  bool has_audio_focus = false;
  bool aa_connected = false;
  VideoSignals::Pointer videosignals_;
  AudioSignals::Pointer audiosignals_;
  AASignals::Pointer aasignals_;
  HttpServer server;

  void handle_video_focus(bool state);
//    void handle_audio_focus();
  void handle_aa_connect(bool state);
};