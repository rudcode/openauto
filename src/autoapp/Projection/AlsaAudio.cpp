#include <autoapp/Projection/AlsaAudio.hpp>
#include <easylogging++.h>

namespace autoapp::projection {

AlsaAudioOutput::AlsaAudioOutput(unsigned int channels, unsigned int rate, const char *outDev) {
  _channels = channels;
  _rate = rate;
  LOG(INFO) << "snd_asoundlib_version: " << snd_asoundlib_version();
  LOG(INFO) << "Device name " << outDev;
  int err;
  if ((err = snd_pcm_open(&aud_handle, outDev, SND_PCM_STREAM_PLAYBACK, 0)) < 0) {
    LOG(ERROR) << "Playback open error: " << snd_strerror(err);
  }
}

bool AlsaAudioOutput::open() {
  int err;
  if ((err = snd_pcm_set_params(aud_handle, SND_PCM_FORMAT_S16_LE, SND_PCM_ACCESS_RW_INTERLEAVED,
                                _channels, _rate, 1, 500000)) < 0) {   /* 1.0sec */
    LOG(ERROR) << "Playback open error: " << snd_strerror(err);
    return false;
  }
  if ((err = snd_pcm_prepare(aud_handle)) < 0) {
    LOG(ERROR) << "snd_pcm_prepare error: " << snd_strerror(err);
    return false;
  }
  return true;
}

void AlsaAudioOutput::stop() {

}

void AlsaAudioOutput::write(__attribute__((unused)) aasdk::messenger::Timestamp::ValueType timestamp,
                            const aasdk::common::DataConstBuffer &buffer) {
  int offset = 0;
  snd_pcm_sframes_t frames = 0;
  snd_pcm_sframes_t framecount = snd_pcm_bytes_to_frames(aud_handle, buffer.size);
  while (framecount > 0) {
    frames = snd_pcm_writei(aud_handle, buffer.cdata + offset,
                                            static_cast<snd_pcm_uframes_t>(framecount));
    if (frames < 0) {
      LOG(ERROR) << "snd_pcm_writei:  " << snd_strerror(frames);
      frames = snd_pcm_recover(aud_handle, frames, 1);
      if (frames < 0) {
        LOG(ERROR) << "snd_pcm_recover failed: " << snd_strerror(frames);
        return;
      }
    }
    offset += snd_pcm_frames_to_bytes(aud_handle, frames);
    framecount -= frames;
  }
}

AlsaAudioOutput::~AlsaAudioOutput() {
  snd_pcm_close(aud_handle);
}
}