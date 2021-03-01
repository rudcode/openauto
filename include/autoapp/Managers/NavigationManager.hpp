#include <set>
#include <sdbus-c++/sdbus-c++.h>

#include <autoapp/Signals/NavigationSignals.hpp>

#include <Mazda/Dbus/com.jci.navi2IHU.HUDSettings.h>
#include <Mazda/Dbus/com.jci.vbs.navi.tmc.h>
#include <Mazda/Dbus/com.jci.vbs.navi.h>

struct NaviData {
  std::string turn_name;
  aasdk::proto::enums::NavigationTurnSide_Enum turn_side;
  aasdk::proto::enums::NavigationTurnEvent_Enum turn_event;
  int turn_number;
  int turn_angle;
  int distance; // distance * 10, encoded like that to store one digit after decimal dot in int type
  aasdk::proto::enums::NavigationDistanceUnit_Enum distance_unit;
  int time_until;
  int msg;
  uint8_t changed;
};

enum MazdaIcons {
  NONE = 0,
  STRAIGHT = 1,
  LEFT = 2,
  RIGHT = 3,
  SLIGHT_LEFT = 4,
  SLIGHT_RIGHT = 5,
  DESTINATION = 8,
  DESTINATION_LEFT = 33,
  DESTINATION_RIGHT = 34,
  SHARP_LEFT = 11,
  SHARP_RIGHT = 9,
  U_TURN_LEFT = 13,
  U_TURN_RIGHT = 10,
  FLAG = 12,
  FLAG_LEFT = 35,
  FLAG_RIGHT = 36,
  FORK_LEFT = 15,
  FORK_RIGHT = 14,
  MERGE_LEFT = 16,
  MERGE_RIGHT = 17,
  OFF_RAMP_LEFT = 7,
  OFF_RAMP_RIGHT = 30
};

enum MazdaDistanceUnits : uint8_t {
  METERS = 1,
  MILES = 2,
  KILOMETERS = 3,
  YARDS = 4,
  FEET = 5
};

class HUDSettingsCLient final : public sdbus::ProxyInterfaces<com::jci::navi2IHU::HUDSettings_proxy> {
 public:
  HUDSettingsCLient(std::unique_ptr<sdbus::IConnection> &connection, std::string destination, std::string objectPath)
      : sdbus::ProxyInterfaces<com::jci::navi2IHU::HUDSettings_proxy>(std::move(connection),
                                                                      std::move(destination),
                                                                      std::move(objectPath)) {
  }
 private:
  void onHUDInstalledChanged(const bool &hUDInstalled) override {}
  void onSetHUDSettingFailed(const int32_t &hUDSettingType, const int32_t &err) override {}
  void onHUDControlAllowed(const bool &bAllowed) override {}
  void onHUDSettingChanged(const int32_t &hUDSettingType, const int32_t &value) override {}
};

class TMCCLient final : public sdbus::ProxyInterfaces<com::jci::vbs::navi::tmc_proxy> {
 public:
  TMCCLient(std::string destination, std::string objectPath)
      : sdbus::ProxyInterfaces<com::jci::vbs::navi::tmc_proxy>(std::move(destination), std::move(objectPath)) {
  }
 private:
  void onServiceListResponse(const sdbus::Struct<uint8_t,
                                                 std::vector<uint8_t>,
                                                 std::vector<uint8_t>,
                                                 std::vector<uint8_t>,
                                                 std::vector<uint8_t>,
                                                 std::vector<uint8_t>> &providerList) override {}
  void onResponseToTMCSelection(const uint8_t &rdstmcOperation,
                                const uint8_t &tmcSearchMode,
                                const uint8_t &countryCode,
                                const uint8_t &locationTableNumber,
                                const uint8_t &serviceIdentifier,
                                const uint8_t &quality,
                                const uint8_t &receptionStatus) override {}

};

class NaviCLient final : public sdbus::ProxyInterfaces<com::jci::vbs::navi_proxy> {
 public:
  NaviCLient(std::string destination, std::string objectPath)
      : sdbus::ProxyInterfaces<com::jci::vbs::navi_proxy>(std::move(destination), std::move(objectPath)) {
  }
 private:
  void onFuelTypeResp(const uint8_t &fuelType) override {}
  void onHUDResp(const uint8_t &hudStatus) override {}
  void onTSRResp(const uint8_t &tsrStatus) override {}
  void onGccConfigMgmtResp(const sdbus::Struct<std::vector<uint8_t>> &vin_Character) override {}
  void onTSRFeatureMode(const uint8_t &tsrMode) override {}
};

class NavigationManager {
 public:
  NavigationManager(NavigationSignals::Pointer navSignals);
  ~NavigationManager();

 private:
  void onNavigationStart();
  void onNavigationStop();
  void onNavigationTurn(int,
                        std::string,
                        aasdk::proto::enums::NavigationTurnSide_Enum,
                        aasdk::proto::enums::NavigationTurnEvent_Enum,
                        int);
  void onNavigationDistance([[maybe_unused]] int,
                            [[maybe_unused]] int, int, aasdk::proto::enums::NavigationDistanceUnit_Enum);
  static uint32_t roundabout(int, aasdk::proto::enums::NavigationTurnSide_Enum side);

  HUDSettingsCLient *hudSettings_;
  TMCCLient *tmcClient_;
  NaviCLient *naviClient_;
  NaviData *navi_data;
  NavigationSignals::Pointer navSignals_;

  typedef std::array<MazdaIcons, 3> TurnIcon;
  typedef sdbus::Struct<uint32_t, uint16_t, uint8_t, uint16_t, uint8_t, uint8_t> hudDisplayMsg;
  typedef sdbus::Struct<std::string, uint8_t> guidancePointData;

  std::map<aasdk::proto::enums::NavigationTurnEvent_Enum, TurnIcon> AA2MAZ;

};