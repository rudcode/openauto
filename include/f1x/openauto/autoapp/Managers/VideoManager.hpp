#pragma once

#include <dbus-c++/dbus.h>
#include <atomic>
#include <set>
#include <f1x/openauto/autoapp/Service/VideoService.hpp>
#include <f1x/openauto/autoapp/Signals/VideoSignals.hpp>

#include <Mazda/Dbus/com.jci.nativeguictrl.h>
#include <Mazda/Dbus/com.jci.bucpsa.h>


class NativeGUICtrlClient : public com::jci::nativeguictrl_proxy,
                            public DBus::ObjectProxy {
public:
    explicit NativeGUICtrlClient(DBus::Connection &connection)
            : DBus::ObjectProxy(connection, "/com/jci/nativeguictrl", "com.jci.nativeguictrl") {
    }

    enum SURFACES
    {
        NNG_NAVI_ID = 0,
        TV_TOUCH_SURFACE = 1,
        NATGUI_SURFACE = 2,
        LOOPLOGO_SURFACE = 3,
        TRANLOGOEND_SURFACE = 4,
        TRANLOGO_SURFACE = 5,
        QUICKTRANLOGO_SURFACE = 6,
        EXITLOGO_SURFACE = 8,
        JCI_OPERA_PRIMARY = 9,
        JCI_OPERA_SECONDARY = 10,
        lvdsSurface = 11,
        SCREENREP_IVI_NAME = 12,
        NNG_NAVI_MAP1 = 13,
        NNG_NAVI_MAP2 = 14,
        NNG_NAVI_HMI = 15,
        NNG_NAVI_TWN = 16,
    };

    void SetRequiredSurfacesByEnum(const int surface, bool fadeOpera)
    {
        SetRequiredSurfaces(std::to_string(surface), static_cast<int16_t>(fadeOpera ? 1 : 0));
    }
};

class BucpsaClient : public com::jci::bucpsa_proxy,
                           public DBus::ObjectProxy {

public:
    bool currentDisplayMode;
    VideoSignals::Pointer _videosignals;

    BucpsaClient(DBus::Connection &hmiBus, VideoSignals::Pointer videosignals);

    ~BucpsaClient() override;

    void CommandResponse(const uint32_t &cmdResponse) override {}

    void DisplayMode(const uint32_t &currentDisplayMode) override;

    void ReverseStatusChanged(const int32_t &reverseStatus) override {}

    void PSMInstallStatusChanged(const uint8_t &psmInstalled) override {}

    void CameraType(const uint32_t &currentCameraType) override {}

    void SteeringWheelLocation(const uint32_t &currentSteeringWheelLocation) override {}
};

class VideoManager{
private:
    BucpsaClient bucpsa;
    NativeGUICtrlClient gui;
    VideoSignals::Pointer vs;
    bool waitsForFocus;

public:
    VideoManager(DBus::Connection &hmiBus,  VideoSignals::Pointer videosignals);
    ~VideoManager();

    void requestFocus(VIDEO_FOCUS_REQUESTOR requestor);
    void releaseFocus(VIDEO_FOCUS_REQUESTOR requestor);

};