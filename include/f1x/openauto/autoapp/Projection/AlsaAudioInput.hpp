/*
*  This file is part of openauto project.
*  Copyright (C) 2018 f1x.studio (Michal Szwaj)
*
*  openauto is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 3 of the License, or
*  (at your option) any later version.
*  openauto is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with openauto. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <memory>
#include <f1x/aasdk/IO/Promise.hpp>
#include <f1x/aasdk/Common/Data.hpp>
#include <f1x/openauto/autoapp/Projection/IAudioInput.hpp>

#include <glib.h>
#include <cstdio>
#include <alsa/asoundlib.h>
#include <thread>

namespace f1x {
    namespace openauto {
        namespace autoapp {
            namespace projection {
                class AlsaAudioInput: public IAudioInput {
                    std::string micDevice;
                    std::thread mic_readthread;
                    int cancelPipeRead = -1, cancelPipeWrite = -1;

                    snd_pcm_sframes_t
                    read_mic_cancelable(snd_pcm_t *mic_handle, void *buffer, snd_pcm_uframes_t size, bool *canceled);

                    void MicThreadMain();

                public:
                    typedef f1x::aasdk::io::Promise<void, void> StartPromise;
                    typedef f1x::aasdk::io::Promise<f1x::aasdk::common::Data, void> ReadPromise;

                    explicit AlsaAudioInput(const std::string &micDevice = "default");

                    ~AlsaAudioInput() override;

                    bool open() override;

                    bool isActive() const override;

                    void read(ReadPromise::Pointer promise) override;

                    void start(StartPromise::Pointer promise) override;

                    void stop() override;

                    uint32_t getSampleSize() const override { return 16; };

                    uint32_t getChannelCount() const override { return 1; };

                    uint32_t getSampleRate() const override { return 16000; };

                private:
                    ReadPromise::Pointer readPromise_;
                    mutable std::mutex mutex_;
                };

            }
        }
    }
}