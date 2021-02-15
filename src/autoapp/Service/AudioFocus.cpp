#include <autoapp/Service/AudioFocus.hpp>

namespace autoapp::service {

AudioFocusRequest::AudioFocusRequest(asio::io_service &ioService) :
    strand_(ioService), timer_(ioService), cancelled_(false) {

}

void AudioFocusRequest::onTimerExceeded(const asio::error_code &error) {
  if (promise_ == nullptr) {
    return;
  } else if (error == asio::error::operation_aborted || cancelled_) {
    promise_->resolve();
  } else {
    promise_->reject(aasdk::error::Error(aasdk::error::ErrorCode::NONE));
  }

  promise_.reset();
}

void AudioFocusRequest::request(Promise::Pointer promise) {
  strand_.dispatch([this, self = this->shared_from_this(), promise = std::move(promise)]() mutable {
    cancelled_ = false;

    if (promise_ != nullptr) {
      promise_->reject(aasdk::error::Error(aasdk::error::ErrorCode::OPERATION_IN_PROGRESS));
    } else {

      promise_ = std::move(promise);
      timer_.expires_from_now(std::chrono::seconds(1));
      timer_.async_wait(strand_.wrap([this](const asio::error_code &error) { onTimerExceeded(error); }));
    }
  });
}

void AudioFocusRequest::cancel() {
  strand_.dispatch([this, self = this->shared_from_this()]() {
    cancelled_ = true;
    timer_.cancel();
  });
}

}
