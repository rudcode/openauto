#include <f1x/openauto/autoapp/Projection/AlsaAudio.hpp>
#include <f1x/openauto/Common/Log.hpp>


namespace f1x {
    namespace openauto {
        namespace autoapp {
            namespace projection {

                AlsaAudioOutput::AlsaAudioOutput(unsigned int channels, unsigned int rate, const char *outDev) {
                    _channels = channels;
                    _rate = rate;
                    OPENAUTO_LOG(info) << "snd_asoundlib_version: " << snd_asoundlib_version();
                    OPENAUTO_LOG(info) << "Device name " << outDev;
                    int err = 0;
                    if ((err = snd_pcm_open(&aud_handle, outDev, SND_PCM_STREAM_PLAYBACK, 0)) < 0) {
                        OPENAUTO_LOG(error) << "Playback open error: " << snd_strerror(err);
                    }
                }


                bool AlsaAudioOutput::open() {
                    int err = 0;
                    if ((err = snd_pcm_set_params(aud_handle, SND_PCM_FORMAT_S16_LE, SND_PCM_ACCESS_RW_INTERLEAVED,
                                                  _channels, _rate, 1, 1000000)) < 0) {   /* 1.0sec */
                        OPENAUTO_LOG(error) << "Playback open error: " << snd_strerror(err);
                        return false;
                    }
                    if ((err = snd_pcm_prepare(aud_handle)) < 0) {
                        OPENAUTO_LOG(error) << "snd_pcm_prepare error: " << snd_strerror(err);
                        return false;
                    }
                    return true;
                }

                void AlsaAudioOutput::stop() {

                }

                void AlsaAudioOutput::write(f1x::aasdk::messenger::Timestamp::ValueType timestamp,
                                            const f1x::aasdk::common::DataConstBuffer &buffer) {
                    snd_pcm_sframes_t framecount = snd_pcm_bytes_to_frames(aud_handle, buffer.size);
                    snd_pcm_sframes_t frames = snd_pcm_writei(aud_handle, buffer.cdata, framecount);
                    if (frames < 0) {
                        frames = snd_pcm_recover(aud_handle, frames, 1);
                        if (frames < 0) {
                            OPENAUTO_LOG(error) << "snd_pcm_recover failed: " << snd_strerror(frames);
                        } else {
                            frames = snd_pcm_writei(aud_handle, buffer.cdata, framecount);
                        }
                    }
                    if (frames >= 0 && frames < framecount) {
                        OPENAUTO_LOG(error) << "Short write (expected " << (int) framecount
                                            << ", wrote " << (int) frames;
                    }
                }

                AlsaAudioOutput::~AlsaAudioOutput() {
                    snd_pcm_close(aud_handle);
                }
            }
        }
    }
}