#include <fstream>
#include <unistd.h>
#include <f1x/openauto/autoapp/Projection/GSTVideoOutput.hpp>
#include <easylogging++.h>

void gst_thread(GstElement *vid_pipeline){
    GstBus *bus = gst_pipeline_get_bus(GST_PIPELINE(vid_pipeline));
    GstMessage *message;
    bool loop = true;
    while(loop){
        if(gst_bus_have_pending(bus)) {
            message = gst_bus_pop(bus);


            switch (GST_MESSAGE_TYPE(message)) {

                case GST_MESSAGE_ERROR: {
                    gchar *debug;
                    GError *err;

                    gst_message_parse_error(message, &err, &debug);
                    LOG(ERROR) << "Error " << err->message;
                    g_error_free(err);
                    g_free(debug);
                }
                    break;

                case GST_MESSAGE_WARNING: {
                    gchar *debug;
                    GError *err;
                    gchar *name;

                    gst_message_parse_warning(message, &err, &debug);
                    LOG(WARNING) << "Warning " << err->message << "Debug " << debug;

                    name = (gchar *) GST_MESSAGE_SRC_NAME(message);

                    LOG(WARNING) <<"Name of src " << ( name ? name : "nil");
                    g_error_free(err);
                    g_free(debug);
                }
                    break;

                case GST_MESSAGE_EOS:
                    LOG(INFO) <<"End of stream";
                    loop = false;
                    break;

                case GST_MESSAGE_STATE_CHANGED:
                    break;

                default:
                    break;
            }
            gst_message_unref(message);
        }
        sleep(1);
    }
}

namespace f1x {
    namespace openauto {
        namespace autoapp {
            namespace projection {

                GSTVideoOutput::GSTVideoOutput(): gloop(nullptr) {
                    gst_init(nullptr, nullptr);
                }


                bool GSTVideoOutput::open() {

                    //Drop caches before staing new video
                    sync();
                    std::ofstream ofs("/proc/sys/vm/drop_caches");
                    ofs << "3" << std::endl;
                    const char *vid_pipeline_launch = "appsrc name=mysrc is-live=true block=false max-latency=1000000 do-timestamp=true ! queue ! h264parse ! vpudec low-latency=true framedrop=true framedrop-level-mask=0x200 frame-plus=1 ! mfw_isink name=mysink "
                                                      "axis-left=0 axis-top=0 disp-width=800 disp-height=480"
                                                      " max-lateness=1000000000 sync=false async=false";
                    LOG(DEBUG) << vid_pipeline_launch;

                    GError *error = nullptr;
                    vid_pipeline = gst_parse_launch(vid_pipeline_launch, &error);

                    if (error != nullptr) {
                        LOG(ERROR) <<"could not construct pipeline: " << error->message;
                        g_clear_error(&error);
                        return false;
                    }

                    vid_src = GST_APP_SRC(gst_bin_get_by_name(GST_BIN(vid_pipeline), "mysrc"));
                    vid_sink = GST_ELEMENT(gst_bin_get_by_name(GST_BIN(vid_pipeline), "mysink"));

                    gst_app_src_set_stream_type(vid_src, GST_APP_STREAM_TYPE_STREAM);
                    gloop = new std::thread(gst_thread, vid_pipeline);
                    return true;
                }

                bool GSTVideoOutput::init() {
                    gst_element_set_state(vid_pipeline, GST_STATE_PLAYING);
                    return true;
                }

                void GSTVideoOutput::write(uint64_t timestamp, const aasdk::common::DataConstBuffer &buf) {
                    GstBuffer *buffer = gst_buffer_new_and_alloc(buf.size);
                    memcpy(GST_BUFFER_DATA(buffer), buf.cdata, buf.size);
                    int ret = gst_app_src_push_buffer(vid_src, buffer);
                    if (ret != GST_FLOW_OK) {
                        printf("push buffer returned %d for %d bytes \n", ret, buf.size);
                    }
                }

                void GSTVideoOutput::stop() {
                    gst_element_set_state(vid_pipeline, GST_STATE_NULL);
                    gloop->join();
                }

                GSTVideoOutput::~GSTVideoOutput() {
                    gst_object_unref(vid_pipeline);
                    gst_object_unref(vid_src);
                    gst_object_unref(vid_sink);
                }

                VideoMargins GSTVideoOutput::getVideoMargins() const {
                    VideoMargins margins(0, 0);
                    return  margins;
                }
        }
        }
    }
}