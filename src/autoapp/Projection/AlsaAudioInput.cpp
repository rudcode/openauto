#include <easylogging++.h>
#include <autoapp/Projection/AlsaAudioInput.hpp>

namespace autoapp::projection {
void AlsaAudioInput::read(ReadPromise::Pointer promise) {
  std::lock_guard<decltype(mutex_)> lock(mutex_);

  if (readPromise_ != nullptr) {
    promise->reject();
  } else {
    readPromise_ = std::move(promise);
    sd->async_wait(asio::posix::stream_descriptor::wait_read,
                   [this](asio::error_code ec) { this->handler(ec); });
  }
}

void AlsaAudioInput::handler(asio::error_code ec) {
  std::lock_guard<decltype(mutex_)> lock(mutex_);

  LOG(DEBUG) << "AlsaAudioInput::handler called";

  if (snd_pcm_state(pcm_handle) != SND_PCM_STATE_RUNNING || ec == asio::error::operation_aborted) {
    LOG(DEBUG) << "mic handler stopped";
    return;
  }

  snd_pcm_sframes_t avail = snd_pcm_avail_update(pcm_handle);
  LOG(DEBUG) << "Avail: " << avail;
  if (avail > 0) {
    auto readSize = snd_pcm_frames_to_bytes(pcm_handle, avail);
    LOG(DEBUG) << "Read:  " << readSize;
    auto tempBuffer = new uint8_t[readSize];
    snd_pcm_sframes_t frames = snd_pcm_readi(pcm_handle, tempBuffer, static_cast<snd_pcm_uframes_t>(avail));
    if (frames < 0) {
      LOG(ERROR) << "Mic read error: " << snd_strerror(frames);
    }
    avail = snd_pcm_avail_update(pcm_handle);
    aasdk::common::Data data(readSize, 0);
    data.reserve(static_cast<unsigned int>(readSize));
    data.insert(data.begin(), tempBuffer, tempBuffer + readSize);

    if (readSize != -1) {
      data.resize(static_cast<unsigned int>(readSize));
      readPromise_->resolve(std::move(data));
      readPromise_.reset();
    } else {
      readPromise_->reject();
      readPromise_.reset();
    }
    LOG(DEBUG) << "left: " << avail;

  } else if (avail < 0) {
    LOG(ERROR) << "Mic read error: " << snd_strerror(avail);
  } else {
    sd->async_wait(asio::posix::stream_descriptor::wait_read,
                   [this](asio::error_code ec) { this->handler(ec); });
  }
}

AlsaAudioInput::AlsaAudioInput(asio::io_service &ioService, const std::string &micDevice)
    : micDevice(micDevice), ioService_(ioService) {
}

AlsaAudioInput::~AlsaAudioInput() = default;

void AlsaAudioInput::start(StartPromise::Pointer promise) {
  int err;
  err = snd_pcm_prepare(pcm_handle);
  if (err < 0) {
    LOG(ERROR) << "snd_pcm_prepare err: " << snd_strerror(err);
    promise->reject();
  }
  err = snd_pcm_start(pcm_handle);
  if (err < 0) {
    LOG(ERROR) << "snd_pcm_start err: " << snd_strerror(err);
    promise->reject();
  }
  promise->resolve();
}

void AlsaAudioInput::stop() {
  snd_pcm_drop(pcm_handle);
  sd->cancel();
  if (readPromise_ != nullptr) {
    readPromise_->reject();
    readPromise_.reset();
  }
}

bool AlsaAudioInput::open() {
  snd_pcm_hw_params_t *hw_params;

  int err = snd_pcm_open(&pcm_handle, micDevice.c_str(), SND_PCM_STREAM_CAPTURE, 0);
  if (err < 0) {
    LOG(ERROR) << "Playback open error: " << snd_strerror(err);
    return false;
  }

  snd_pcm_hw_params_malloc(&hw_params);

  err = snd_pcm_hw_params_any(pcm_handle, hw_params);
  if (err < 0) {
    LOG(ERROR) << "Broken configuration for mic: no configurations available: "
               << snd_strerror(err);
    return false;
  }
  /* set the interleaved read/write format */
  err = snd_pcm_hw_params_set_access(pcm_handle, hw_params, SND_PCM_ACCESS_RW_INTERLEAVED);
  if (err < 0) {
    LOG(ERROR) << "Access type not available for mic: " << snd_strerror(err);
    return false;
  }
  /* set the sample format */
  err = snd_pcm_hw_params_set_format(pcm_handle, hw_params, SND_PCM_FORMAT_S16_LE);
  if (err < 0) {
    LOG(ERROR) << "Sample format not available for mic: " << snd_strerror(err);
    return false;
  }
  /* set the count of channels */
  err = snd_pcm_hw_params_set_channels(pcm_handle, hw_params, 1);
  if (err < 0) {
    LOG(ERROR) << "Channels count (1) not available for mic: " << snd_strerror(err);
    return false;
  }
  /* set the stream rate */
  unsigned int rrate = 16000;
  err = snd_pcm_hw_params_set_rate_near(pcm_handle, hw_params, &rrate, nullptr);
  if (err < 0) {
    LOG(ERROR) << "Rate " << rrate << "Hz not available for playback: " << snd_strerror(err);
    return false;
  }
  if (rrate != 16000) {
    LOG(ERROR) << "Rate doesn't match (requested 16000Hz, get " << rrate << "Hz";
    return false;
  }
  /* set the buffer time */
  err = snd_pcm_hw_params_set_buffer_size_near(pcm_handle, hw_params, &buffer_size);

  if (err < 0) {
    LOG(ERROR) << "Unable to set buffer size " << buffer_size << " for playback: "
               << snd_strerror(err);
    return false;
  }
  /* set the period time */
  err = snd_pcm_hw_params_set_period_size_near(pcm_handle, hw_params, &period_size, nullptr);
  if (err < 0) {
    LOG(ERROR) << "Unable to set period time " << period_size << " for playback: "
               << snd_strerror(err);
    return false;
  }
  /* write the parameters to device */
  if ((err = snd_pcm_hw_params(pcm_handle, hw_params)) < 0) {   /* 0.25sec */
    LOG(ERROR) << "Mic HW Config error: " << snd_strerror(err);
    snd_pcm_close(pcm_handle);
    return false;
  }

  snd_pcm_hw_params_free(hw_params);

  snd_pcm_sw_params_t *sw_params;

  snd_pcm_sw_params_malloc(&sw_params);
  snd_pcm_sw_params_current(pcm_handle, sw_params);

  snd_pcm_sw_params_set_start_threshold(pcm_handle, sw_params, buffer_size - period_size);
  snd_pcm_sw_params_set_avail_min(pcm_handle, sw_params, period_size);

  if ((err = snd_pcm_sw_params(pcm_handle, sw_params)) < 0) {   /* 0.25sec */
    LOG(ERROR) << "Mic SW config error: " << snd_strerror(err);
    snd_pcm_close(pcm_handle);
    return false;
  }

  snd_pcm_sw_params_free(sw_params);

  struct pollfd *ufds;
  int count;
  count = snd_pcm_poll_descriptors_count(pcm_handle);
  if (count <= 0) {
    printf("Invalid poll descriptors count\n");
    return false;
  }
  ufds = (pollfd *) malloc(sizeof(struct pollfd) * count);
  if (ufds == nullptr) {
    printf("No enough memory\n");
    return false;
  }

  if ((err = snd_pcm_poll_descriptors(pcm_handle, ufds, static_cast<unsigned int>(count))) < 0) {
    printf("Unable to obtain poll descriptors for playback: %s\n", snd_strerror(err));
    return false;
  }
  LOG(DEBUG) << "Pollfd count: " << count;
  sd = new asio::posix::stream_descriptor(ioService_, ufds[0].fd);
  free(ufds);

  return true;
}

bool AlsaAudioInput::isActive() const {
  return true;
}
}