#pragma once

#include <sigc++/sigc++.h>
#include <memory>
#include <aasdk_proto/AudioFocusStateEnum.pb.h>
#include <aasdk_proto/AudioFocusTypeEnum.pb.h>
//#include <autoapp/Managers/AudioManager.hpp>

enum class FocusType {
  NONE,
  PERMANENT,
  TRANSIENT,
};

class AudioSignals : public sigc::trackable {
 public:
  typedef std::shared_ptr<AudioSignals> Pointer;
  sigc::signal<void(aasdk::proto::enums::AudioFocusType_Enum)> focusRequest;
  sigc::signal<void()> focusRelease;
  sigc::signal<void(aasdk::proto::enums::AudioFocusState_Enum)> focusChanged;

};