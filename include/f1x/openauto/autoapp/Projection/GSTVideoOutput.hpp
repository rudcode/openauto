//This gets defined by SDL and breaks the protobuf headers
#undef Status

#include <glib.h>
#include <gst/gst.h>
#include <gst/app/gstappsrc.h>

#include <aasdk_proto/VideoFPSEnum.pb.h>
#include <aasdk_proto/VideoResolutionEnum.pb.h>
#include <aasdk/Common/Data.hpp>
#include <f1x/openauto/autoapp/Projection/IVideoOutput.hpp>
#include <thread>

#ifndef ASPECT_RATIO_FIX
#define ASPECT_RATIO_FIX 1
#endif

namespace f1x {
    namespace openauto {
        namespace autoapp {
            namespace projection {

                class GSTVideoOutput : public IVideoOutput {
                    GstElement *vid_pipeline = nullptr;
                    GstAppSrc *vid_src = nullptr;
                    GstElement *vid_sink = nullptr;
                    std::thread *gloop;

                public:
                    explicit GSTVideoOutput();

                    ~GSTVideoOutput() override;

                    //AASDK stuff
                    bool open() override;

                    bool init() override;

                    void write(uint64_t timestamp, const aasdk::common::DataConstBuffer &buffer) override;

                    void stop() override;

                    aasdk::proto::enums::VideoFPS::Enum getVideoFPS() const override { return aasdk::proto::enums::VideoFPS::Enum::VideoFPS_Enum__30; }

                    aasdk::proto::enums::VideoResolution::Enum getVideoResolution() const override { return aasdk::proto::enums::VideoResolution::Enum::VideoResolution_Enum__480p; }

                    size_t getScreenDPI() const override { return 140; }

                    VideoMargins getVideoMargins() const override;
                };
            }
        }
    }
}