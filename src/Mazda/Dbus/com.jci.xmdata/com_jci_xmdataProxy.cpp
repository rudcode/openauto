#include "com_jci_xmdataProxy.h"

com_jci_xmdataProxy::com_jci_xmdataProxy(std::string name) : DBus::InterfaceProxy(name) {
  m_method_GetSubscriptionStatus = this->create_method<uint32_t()>("GetSubscriptionStatus");
  m_method_GetDataServiceSubscriptions = this->create_method<uint32_t()>("GetDataServiceSubscriptions");
  m_method_GetDataAvailable = this->create_method<uint32_t()>("GetDataAvailable");
  m_method_GetInstallStatus = this->create_method<int32_t()>("GetInstallStatus");
  m_method_GetESN = this->create_method<int32_t()>("GetESN");
  m_method_GetVehicleLocation = this->create_method<int32_t()>("GetVehicleLocation");
  m_method_AddStock = this->create_method<int32_t(std::string)>("AddStock");
  m_method_RemoveStock = this->create_method<int32_t(std::string)>("RemoveStock");
  m_method_GetStockCount = this->create_method<DBus::MultipleReturn<int32_t, uint32_t>()>("GetStockCount");
  m_method_GetWSAlertData = this->create_method<int32_t()>("GetWSAlertData");
  m_method_SaveWSAlertSetting = this->create_method<int32_t(bool)>("SaveWSAlertSetting");
  m_method_GetWSAlertSetting = this->create_method<DBus::MultipleReturn<int32_t, bool>()>("GetWSAlertSetting");
  m_method_WSHighAlertDataOverride = this->create_method<void(uint32_t)>("WSHighAlertDataOverride");
  m_method_GetWSHighAlertData =
      this->create_method<DBus::MultipleReturn<uint32_t, std::string, uint16_t, std::string, uint32_t>()>(
          "GetWSHighAlertData");
  m_method_SelectState = this->create_method<uint32_t(std::string)>("SelectState");
  m_method_SelectCity = this->create_method<uint32_t(std::string)>("SelectCity");
  m_method_GetRecentCities = this->create_method < DBus::MultipleReturn < uint32_t, std::tuple < std::vector
      < std::string>>>() > ("GetRecentCities");
  m_method_SetSelectedRate = this->create_method<uint32_t(uint32_t)>("SetSelectedRate");
  m_method_GetSelectedRate = this->create_method<DBus::MultipleReturn<uint32_t, uint32_t>()>("GetSelectedRate");
  m_method_SaveParkingCountrySetting = this->create_method<int32_t(uint32_t)>("SaveParkingCountrySetting");
  m_method_GetParkingCountrySetting = this->create_method<uint32_t()>("GetParkingCountrySetting");
  m_method_GetLastViewedSportTeamList = this->create_method < DBus::MultipleReturn < uint32_t, std::tuple < std::vector
      < std::string>>>() > ("GetLastViewedSportTeamList");
  m_method_SelectSportTeam = this->create_method<uint32_t(std::string)>("SelectSportTeam");
  m_method_DisplayNNGServices = this->create_method<uint32_t(uint32_t)>("DisplayNNGServices");
  m_method_SaveFuelSetting = this->create_method<int32_t(uint32_t)>("SaveFuelSetting");
  m_method_SaveFuelBrandSetting =
      this->create_method<int32_t(std::tuple < std::vector < std::string >> )>("SaveFuelBrandSetting");
  m_method_SaveFuelCountrySetting = this->create_method<int32_t(uint32_t)>("SaveFuelCountrySetting");
  m_method_GetFuelSetting = this->create_method<uint32_t()>("GetFuelSetting");
  m_method_GetFuelBrandSetting = this->create_method < DBus::MultipleReturn < uint32_t, std::tuple < std::vector
      < std::string>>>() > ("GetFuelBrandSetting");
  m_method_GetFuelCountrySetting = this->create_method<uint32_t()>("GetFuelCountrySetting");
  m_method_GetWeatherCitySelect =
      this->create_method<DBus::MultipleReturn<bool, std::string>()>("GetWeatherCitySelect");
  m_signalproxy_SubscriptionStatus =
      this->create_signal<void(std::tuple < uint32_t, uint8_t, uint32_t, std::string, std::string > )>(
          "SubscriptionStatus");
  m_signalproxy_DataServiceSubscription = this->create_signal
      < void(std::tuple < std::vector < std::tuple < uint32_t, uint32_t>>>)>("DataServiceSubscription");
  m_signalproxy_DataAvailable =
      this->create_signal < void(std::tuple < std::vector < std::tuple < uint32_t, uint32_t>>>)>("DataAvailable");
  m_signalproxy_InstallStatus = this->create_signal<void(int32_t)>("InstallStatus");
  m_signalproxy_ESNInfo = this->create_signal<void(std::string)>("ESNInfo");
  m_signalproxy_VehicleLocation = this->create_signal<void(double, double, double)>("VehicleLocation");
  m_signalproxy_FuelDataUpdated = this->create_signal<void(uint32_t)>("FuelDataUpdated");
  m_signalproxy_StockAdded = this->create_signal<void(uint32_t)>("StockAdded");
  m_signalproxy_StockRemoved = this->create_signal<void(bool)>("StockRemoved");
  m_signalproxy_StockDataUpdated = this->create_signal<void(uint32_t)>("StockDataUpdated");
  m_signalproxy_StockOTAUnAvailable = this->create_signal<void()>("StockOTAUnAvailable");
  m_signalproxy_MoviesDataUpdated = this->create_signal<void(uint32_t)>("MoviesDataUpdated");
  m_signalproxy_WeatherForecastDataUpdated = this->create_signal<void(uint32_t)>("WeatherForecastDataUpdated");
  m_signalproxy_WSAlertDataUpdated = this->create_signal < void(std::tuple < std::vector < std::tuple < uint32_t,
                                                                std::string,
                                                                uint16_t,
                                                                std::string>>>)>("WSAlertDataUpdated");
  m_signalproxy_WSHighAlertData = this->create_signal<void(uint16_t)>("WSHighAlertData");
  m_signalproxy_CityListAvailable = this->create_signal<void(uint32_t)>("CityListAvailable");
  m_signalproxy_ParkingDataUpdated = this->create_signal<void(uint32_t)>("ParkingDataUpdated");
  m_signalproxy_SportsDataUpdated = this->create_signal<void(uint32_t, bool)>("SportsDataUpdated");
  m_signalproxy_ShowSXMServices = this->create_signal<void()>("ShowSXMServices");

}
std::shared_ptr <com_jci_xmdataProxy> com_jci_xmdataProxy::create(std::string name) {
  return std::shared_ptr<com_jci_xmdataProxy>(new com_jci_xmdataProxy(name));

}
uint32_t com_jci_xmdataProxy::GetSubscriptionStatus() {
  return (*m_method_GetSubscriptionStatus)();

}
uint32_t com_jci_xmdataProxy::GetDataServiceSubscriptions() {
  return (*m_method_GetDataServiceSubscriptions)();

}
uint32_t com_jci_xmdataProxy::GetDataAvailable() {
  return (*m_method_GetDataAvailable)();

}
int32_t com_jci_xmdataProxy::GetInstallStatus() {
  return (*m_method_GetInstallStatus)();

}
int32_t com_jci_xmdataProxy::GetESN() {
  return (*m_method_GetESN)();

}
int32_t com_jci_xmdataProxy::GetVehicleLocation() {
  return (*m_method_GetVehicleLocation)();

}
int32_t com_jci_xmdataProxy::AddStock(std::string stockSymbol) {
  return (*m_method_AddStock)(stockSymbol);

}
int32_t com_jci_xmdataProxy::RemoveStock(std::string stockSymbol) {
  return (*m_method_RemoveStock)(stockSymbol);

}
DBus::MultipleReturn <int32_t, uint32_t> com_jci_xmdataProxy::GetStockCount() {
  return (*m_method_GetStockCount)();

}
int32_t com_jci_xmdataProxy::GetWSAlertData() {
  return (*m_method_GetWSAlertData)();

}
int32_t com_jci_xmdataProxy::SaveWSAlertSetting(bool popUpSetting) {
  return (*m_method_SaveWSAlertSetting)(popUpSetting);

}
DBus::MultipleReturn<int32_t, bool> com_jci_xmdataProxy::GetWSAlertSetting() {
  return (*m_method_GetWSAlertSetting)();

}
void com_jci_xmdataProxy::WSHighAlertDataOverride(uint32_t alertID) {
  (*m_method_WSHighAlertDataOverride)(alertID);

}
DBus::MultipleReturn <uint32_t, std::string, uint16_t, std::string, uint32_t> com_jci_xmdataProxy::GetWSHighAlertData() {
  return (*m_method_GetWSHighAlertData)();

}
uint32_t com_jci_xmdataProxy::SelectState(std::string stateName) {
  return (*m_method_SelectState)(stateName);

}
uint32_t com_jci_xmdataProxy::SelectCity(std::string cityName) {
  return (*m_method_SelectCity)(cityName);

}
DBus::MultipleReturn <uint32_t, std::tuple<std::vector < std::string>>>
com_jci_xmdataProxy::GetRecentCities() {
  return (*m_method_GetRecentCities)();

}
uint32_t com_jci_xmdataProxy::SetSelectedRate(uint32_t rateType) {
  return (*m_method_SetSelectedRate)(rateType);

}
DBus::MultipleReturn <uint32_t, uint32_t> com_jci_xmdataProxy::GetSelectedRate() {
  return (*m_method_GetSelectedRate)();

}
int32_t com_jci_xmdataProxy::SaveParkingCountrySetting(uint32_t parkingCountry) {
  return (*m_method_SaveParkingCountrySetting)(parkingCountry);

}
uint32_t com_jci_xmdataProxy::GetParkingCountrySetting() {
  return (*m_method_GetParkingCountrySetting)();

}
DBus::MultipleReturn <uint32_t, std::tuple<std::vector < std::string>>>
com_jci_xmdataProxy::GetLastViewedSportTeamList() {
  return (*m_method_GetLastViewedSportTeamList)();

}
uint32_t com_jci_xmdataProxy::SelectSportTeam(std::string teamInfo) {
  return (*m_method_SelectSportTeam)(teamInfo);

}
uint32_t com_jci_xmdataProxy::DisplayNNGServices(uint32_t service) {
  return (*m_method_DisplayNNGServices)(service);

}
int32_t com_jci_xmdataProxy::SaveFuelSetting(uint32_t fuelType) {
  return (*m_method_SaveFuelSetting)(fuelType);

}
int32_t com_jci_xmdataProxy::SaveFuelBrandSetting(std::tuple <std::vector<std::string>> brandList) {
  return (*m_method_SaveFuelBrandSetting)(brandList);

}
int32_t com_jci_xmdataProxy::SaveFuelCountrySetting(uint32_t fuelCountry) {
  return (*m_method_SaveFuelCountrySetting)(fuelCountry);

}
uint32_t com_jci_xmdataProxy::GetFuelSetting() {
  return (*m_method_GetFuelSetting)();

}
DBus::MultipleReturn <uint32_t, std::tuple<std::vector < std::string>>>
com_jci_xmdataProxy::GetFuelBrandSetting() {
  return (*m_method_GetFuelBrandSetting)();

}
uint32_t com_jci_xmdataProxy::GetFuelCountrySetting() {
  return (*m_method_GetFuelCountrySetting)();

}
DBus::MultipleReturn<bool, std::string> com_jci_xmdataProxy::GetWeatherCitySelect() {
  return (*m_method_GetWeatherCitySelect)();

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < uint32_t,
                                        uint8_t,
                                        uint32_t,
                                        std::string,
                                        std::string > )>> com_jci_xmdataProxy::signal_SubscriptionStatus() {
  return m_signalproxy_SubscriptionStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < std::vector < std::tuple < uint32_t, uint32_t>>>)>>
com_jci_xmdataProxy::signal_DataServiceSubscription() {
  return m_signalproxy_DataServiceSubscription;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < std::vector < std::tuple < uint32_t, uint32_t>>>)>>
com_jci_xmdataProxy::signal_DataAvailable() {
  return m_signalproxy_DataAvailable;

}
std::shared_ptr <DBus::SignalProxy<void(int32_t)>> com_jci_xmdataProxy::signal_InstallStatus() {
  return m_signalproxy_InstallStatus;

}
std::shared_ptr <DBus::SignalProxy<void(std::string)>> com_jci_xmdataProxy::signal_ESNInfo() {
  return m_signalproxy_ESNInfo;

}
std::shared_ptr <DBus::SignalProxy<void(double, double, double)>> com_jci_xmdataProxy::signal_VehicleLocation() {
  return m_signalproxy_VehicleLocation;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmdataProxy::signal_FuelDataUpdated() {
  return m_signalproxy_FuelDataUpdated;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmdataProxy::signal_StockAdded() {
  return m_signalproxy_StockAdded;

}
std::shared_ptr <DBus::SignalProxy<void(bool)>> com_jci_xmdataProxy::signal_StockRemoved() {
  return m_signalproxy_StockRemoved;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmdataProxy::signal_StockDataUpdated() {
  return m_signalproxy_StockDataUpdated;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_xmdataProxy::signal_StockOTAUnAvailable() {
  return m_signalproxy_StockOTAUnAvailable;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmdataProxy::signal_MoviesDataUpdated() {
  return m_signalproxy_MoviesDataUpdated;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmdataProxy::signal_WeatherForecastDataUpdated() {
  return m_signalproxy_WeatherForecastDataUpdated;

}
std::shared_ptr <DBus::SignalProxy<void(std::tuple < std::vector < std::tuple < uint32_t,
                                        std::string,
                                        uint16_t,
                                        std::string>>>)>>
com_jci_xmdataProxy::signal_WSAlertDataUpdated() {
  return m_signalproxy_WSAlertDataUpdated;

}
std::shared_ptr <DBus::SignalProxy<void(uint16_t)>> com_jci_xmdataProxy::signal_WSHighAlertData() {
  return m_signalproxy_WSHighAlertData;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmdataProxy::signal_CityListAvailable() {
  return m_signalproxy_CityListAvailable;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t)>> com_jci_xmdataProxy::signal_ParkingDataUpdated() {
  return m_signalproxy_ParkingDataUpdated;

}
std::shared_ptr <DBus::SignalProxy<void(uint32_t, bool)>> com_jci_xmdataProxy::signal_SportsDataUpdated() {
  return m_signalproxy_SportsDataUpdated;

}
std::shared_ptr <DBus::SignalProxy<void()>> com_jci_xmdataProxy::signal_ShowSXMServices() {
  return m_signalproxy_ShowSXMServices;

}
