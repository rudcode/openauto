#pragma once

#include <memory>
#include <sigc++/sigc++.h>

#include <aasdk_proto/NavigationChannelData.pb.h>
#include <aasdk_proto/NavigationChannelMessageIdsEnum.pb.h>
#include <aasdk_proto/NavigationDistanceMessage.pb.h>
#include <aasdk_proto/NavigationDistanceUnitEnum.pb.h>
#include <aasdk_proto/NavigationImageOptionsData.pb.h>
#include <aasdk_proto/NavigationRequestMessage.pb.h>
#include <aasdk_proto/NavigationRequestStateEnum.pb.h>
#include <aasdk_proto/NavigationTurnEventEnum.pb.h>
#include <aasdk_proto/NavigationTurnMessage.pb.h>
#include <aasdk_proto/NavigationTurnSideEnum.pb.h>

class NavigationSignals : public sigc::trackable {
 public:
  typedef std::shared_ptr<NavigationSignals> Pointer;
  sigc::signal<void(int, std::string, aasdk::proto::enums::NavigationTurnSide_Enum, aasdk::proto::enums::NavigationTurnEvent_Enum, int)> onNavigationTurn;
  sigc::signal<void(int, int, int, aasdk::proto::enums::NavigationDistanceUnit_Enum)> onNavigationDistance;
  sigc::signal<void()> onNavigationStart;
  sigc::signal<void()> onNavigationStop;
};
