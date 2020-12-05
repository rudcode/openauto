#include <fstream>
#include <unistd.h>
#include <f1x/openauto/autoapp/Projection/GSTVideoOutput.hpp>

namespace f1x {
    namespace openauto {
        namespace autoapp {
            namespace projection {

                GSTVideoOutput::GSTVideoOutput() = default;


                bool GSTVideoOutput::open() {

                    //Drop caches before staing new video
                    sync();
                    std::ofstream ofs("/proc/sys/vm/drop_caches");
                    ofs << "3" << std::endl;

                     gst_file = popen("gst-launch fdsrc fd=0 timeout=1000 do-timestamp=true " \
                            "! queue ! h264parse " \
                            "! vpudec low-latency=true framedrop=true framedrop-level-mask=0x200 frame-plus=1 "\
                            "! mfw_isink name=mysink axis-left=0  axis-top=0 disp-width=800 disp-height=480 " \
                            "max-lateness=1000000000 sync=false async=false", "w");
                    return true;
                }

                bool GSTVideoOutput::init() {
                    return true;
                }

                void GSTVideoOutput::write(__attribute__((unused)) uint64_t timestamp, const aasdk::common::DataConstBuffer &buf) {
                    fwrite(buf.cdata, sizeof(buf.cdata[0]), buf.size, gst_file);
                }

                void GSTVideoOutput::stop() {
                    pclose(gst_file);
                }

                GSTVideoOutput::~GSTVideoOutput() = default;

                VideoMargins GSTVideoOutput::getVideoMargins() const {
                    VideoMargins margins(0, 0);
                    return  margins;
                }
        }
        }
    }
}