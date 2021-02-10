#pragma once

#include <asio.hpp>
#include <aasdk/IO/Promise.hpp>

namespace autoapp::service {

class AudioFocusRequest : public std::enable_shared_from_this<AudioFocusRequest> {
 public:
  typedef std::shared_ptr<AudioFocusRequest> Pointer;
  typedef aasdk::io::Promise<void> Promise;

  explicit AudioFocusRequest(asio::io_service &ioService);
  void request(Promise::Pointer promise);
  void cancel();

 private:
  using std::enable_shared_from_this<AudioFocusRequest>::shared_from_this;

  void onTimerExceeded(const asio::error_code &error);

  asio::io_service::strand strand_;
  asio::basic_waitable_timer<std::chrono::steady_clock> timer_;
  bool cancelled_;
  Promise::Pointer promise_;
};

}
