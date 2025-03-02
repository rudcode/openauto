#include <aasdk_proto/VideoFPSEnum.pb.h>
#include <aasdk_proto/VideoResolutionEnum.pb.h>
#include <aasdk/Common/Data.hpp>
#include <autoapp/Projection/IVideoOutput.hpp>
#include <thread>
#include <asio.hpp>

#ifndef ASPECT_RATIO_FIX
#define ASPECT_RATIO_FIX 1
#endif

namespace autoapp::projection {

class GSTVideoOutput : public IVideoOutput {
  FILE *gst_file = nullptr;

 public:
  explicit GSTVideoOutput(asio::io_service &ioService);

  ~GSTVideoOutput() override;

  //AASDK stuff
  bool open() override;

  bool init() override;

  void write(uint64_t timestamp, const aasdk::common::DataConstBuffer &buffer) override;

  void stop() override;

  [[nodiscard]] aasdk::proto::enums::VideoFPS::Enum
  getVideoFPS() const override { return aasdk::proto::enums::VideoFPS::Enum::VideoFPS_Enum__30; }

  [[nodiscard]] aasdk::proto::enums::VideoResolution::Enum
  getVideoResolution() const override { return aasdk::proto::enums::VideoResolution::Enum::VideoResolution_Enum__480p; }

  [[nodiscard]] size_t getScreenDPI() const override { return 141; }

  [[nodiscard]] VideoMargins getVideoMargins() const override;

 private:
  asio::io_service &ioService_;
  pid_t gstpid = -1;
  int p_stdin[2]{}, p_stdout[2]{};
  asio::streambuf buffer;
  asio::posix::stream_descriptor *sd = nullptr;
  bool running;

  void message_handler(asio::error_code ec, size_t bytes_transferred);

  void spawn_gst();
  static bool CheckReverse();
};
}
