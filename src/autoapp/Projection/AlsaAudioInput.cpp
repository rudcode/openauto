#include <f1x/openauto/Common/Log.hpp>
#include <f1x/openauto/autoapp/Projection/AlsaAudioInput.hpp>
#include <unistd.h>
#include <pthread.h>

namespace f1x {
    namespace openauto {
        namespace autoapp {
            namespace projection {
                void AlsaAudioInput::read(ReadPromise::Pointer promise) {
                    std::lock_guard<decltype(mutex_)> lock(mutex_);

                    if (readPromise_ != nullptr) {
                        promise->reject();
                    } else {
                        readPromise_ = std::move(promise);
                    }
                }

                snd_pcm_sframes_t
                AlsaAudioInput::read_mic_cancelable(snd_pcm_t *mic_handle, void *buffer, snd_pcm_uframes_t size,
                                                    bool *canceled) {
                    int pollfdAllocCount = snd_pcm_poll_descriptors_count(mic_handle);
                    auto *pfds = (struct pollfd *) alloca((pollfdAllocCount + 1) * sizeof(struct pollfd));
                    auto *revents = (unsigned short *) alloca(pollfdAllocCount * sizeof(unsigned short));

                    int polldescs = snd_pcm_poll_descriptors(mic_handle, pfds, pollfdAllocCount);
                    pfds[polldescs].fd = cancelPipeRead;
                    pfds[polldescs].events = POLLIN;
                    pfds[polldescs].revents = 0;

                    *canceled = false;
                    while (true) {
                        if (poll(pfds, polldescs + 1, -1) <= 0) {
                            OPENAUTO_LOG(error) << "poll failed";
                            break;
                        }

                        if (pfds[polldescs].revents & POLLIN) {
//            unsigned char bogusByte;
//            bogusByte << cancelPipeRead;
                            *canceled = true;
                            return 0;
                        }
                        unsigned short audioEvents = 0;
                        snd_pcm_poll_descriptors_revents(mic_handle, pfds, polldescs, &audioEvents);

                        if (audioEvents & POLLIN) {
                            //got it
                            break;
                        }
                    }
                    snd_pcm_sframes_t ret = snd_pcm_readi(mic_handle, buffer, size);
                    return ret;
                }

                void AlsaAudioInput::MicThreadMain() {
                    snd_pcm_t *mic_handle = nullptr;

                    int err = 0;
                    if ((err = snd_pcm_open(&mic_handle, micDevice.c_str(), SND_PCM_STREAM_CAPTURE, SND_PCM_NONBLOCK)) <
                        0) {
                        OPENAUTO_LOG(error) << "Playback open error: " << snd_strerror(err);
                        return;
                    }

                    if ((err = snd_pcm_set_params(mic_handle, SND_PCM_FORMAT_S16_LE, SND_PCM_ACCESS_RW_INTERLEAVED, 1,
                                                  16000, 1, 250000)) < 0) {   /* 0.25sec */
                        OPENAUTO_LOG(error) << "Playback open error: "<< snd_strerror(err);
                        snd_pcm_close(mic_handle);
                        return;
                    }
                    if ((err = snd_pcm_prepare(mic_handle)) < 0) {
                        OPENAUTO_LOG(error) << "snd_pcm_prepare: " << snd_strerror(err);
                        snd_pcm_close(mic_handle);
                        return;
                    }

                    if ((err = snd_pcm_start(mic_handle)) < 0) {
                        OPENAUTO_LOG(error) << "snd_pcm_start: " << snd_strerror(err);
                        snd_pcm_close(mic_handle);
                        return;
                    }

                    const size_t tempSize = 1024 * 1024;
                    const snd_pcm_sframes_t bufferFrameCount = snd_pcm_bytes_to_frames(mic_handle, tempSize);
                    bool canceled = false;
                    while (!canceled) {
                        auto *tempBuffer = new uint8_t[tempSize];
                        snd_pcm_sframes_t frames = read_mic_cancelable(mic_handle, tempBuffer, bufferFrameCount,
                                                                       &canceled);
                        if (frames < 0) {
                            if (frames == -ESTRPIPE) {
                                frames = snd_pcm_recover(mic_handle, frames, 0);
                                if (frames < 0) {
                                    OPENAUTO_LOG(error) << "recover failed";
                                } else {
                                    frames = read_mic_cancelable(mic_handle, tempBuffer, bufferFrameCount, &canceled);
                                }
                            }

                            if (frames < 0) {
                                delete[] tempBuffer;
                                canceled = true;
                            }
                        }
                        {
                            std::lock_guard<decltype(mutex_)> lock(mutex_);

                            if (readPromise_ == nullptr) {
                                continue;
                            }

                            f1x::aasdk::common::Data data(1048576, 0);
//            f1x::aasdk::common::DataBuffer buffer(data);
                            auto readSize = snd_pcm_frames_to_bytes(mic_handle, frames);
                            data.reserve(readSize);
                            data.insert(data.begin(), tempBuffer, tempBuffer + readSize);

                            if (readSize != -1) {
                                data.resize(readSize);
                                readPromise_->resolve(std::move(data));
                                readPromise_.reset();
                            } else {
                                readPromise_->reject();
                                readPromise_.reset();
                            }
                        }

                        delete[] tempBuffer;
                    }

                    if ((err = snd_pcm_drop(mic_handle)) < 0) {
                        OPENAUTO_LOG(error) << "snd_pcm_drop: " << snd_strerror(err);
                    }

                    snd_pcm_close(mic_handle);
                }

                AlsaAudioInput::AlsaAudioInput(const std::string &micDevice) : micDevice(micDevice) {
//                    int cancelPipe[2];
//                    if (pipe(cancelPipe) < 0) {
//                        OPENAUTO_LOG(error) << "pipe failed";
//                    }
//                    cancelPipeRead = cancelPipe[0];
//                    cancelPipeWrite = cancelPipe[1];
                }

                AlsaAudioInput::~AlsaAudioInput() {
                    close(cancelPipeRead);
                    close(cancelPipeWrite);
                }

                void AlsaAudioInput::start(StartPromise::Pointer promise) {
//                    if (!mic_readthread.joinable()) {
//                        mic_readthread = std::thread([this]() { MicThreadMain(); });
//                    }
                }

                void AlsaAudioInput::stop() {
//                    if (mic_readthread.joinable()) {
//                        //write single byte
//                        write(cancelPipeWrite, &cancelPipeWrite, 1);
//                        mic_readthread.join();
//                    }
                }

                bool AlsaAudioInput::open() {
                    return true;
                }

                bool AlsaAudioInput::isActive() const {
                    return true;
                }
            }
        }
    }
}