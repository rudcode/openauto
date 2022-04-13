#ifndef COM_JCI_XMDATAPROXY_H
#define COM_JCI_XMDATAPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class com_jci_xmdataProxy
    : public DBus::InterfaceProxy {
 protected:
  com_jci_xmdataProxy(std::string name);
 public:
  static std::shared_ptr<com_jci_xmdataProxy> create(std::string name = "com.jci.xmdata");
  uint32_t GetSubscriptionStatus();
  uint32_t GetDataServiceSubscriptions();
  uint32_t GetDataAvailable();
  int32_t GetInstallStatus();
  int32_t GetESN();
  int32_t GetVehicleLocation();
  int32_t AddStock(std::string stockSymbol);
  int32_t RemoveStock(std::string stockSymbol);
  DBus::MultipleReturn<int32_t, uint32_t> GetStockCount();
  int32_t GetWSAlertData();
  int32_t SaveWSAlertSetting(bool popUpSetting);
  DBus::MultipleReturn<int32_t, bool> GetWSAlertSetting();
  void WSHighAlertDataOverride(uint32_t alertID);
  DBus::MultipleReturn<uint32_t, std::string, uint16_t, std::string, uint32_t> GetWSHighAlertData();
  uint32_t SelectState(std::string stateName);
  uint32_t SelectCity(std::string cityName);
  DBus::MultipleReturn<uint32_t, std::tuple<std::vector<std::string>>> GetRecentCities();
  uint32_t SetSelectedRate(uint32_t rateType);
  DBus::MultipleReturn<uint32_t, uint32_t> GetSelectedRate();
  int32_t SaveParkingCountrySetting(uint32_t parkingCountry);
  uint32_t GetParkingCountrySetting();
  DBus::MultipleReturn<uint32_t, std::tuple<std::vector<std::string>>> GetLastViewedSportTeamList();
  uint32_t SelectSportTeam(std::string teamInfo);
  uint32_t DisplayNNGServices(uint32_t service);
  int32_t SaveFuelSetting(uint32_t fuelType);
  int32_t SaveFuelBrandSetting(std::tuple<std::vector<std::string>> brandList);
  int32_t SaveFuelCountrySetting(uint32_t fuelCountry);
  uint32_t GetFuelSetting();
  DBus::MultipleReturn<uint32_t, std::tuple<std::vector<std::string>>> GetFuelBrandSetting();
  uint32_t GetFuelCountrySetting();
  DBus::MultipleReturn<bool, std::string> GetWeatherCitySelect();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t,
                                                    uint8_t,
                                                    uint32_t,
                                                    std::string,
                                                    std::string>)>> signal_SubscriptionStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<std::tuple<uint32_t,
                                                                           uint32_t>>>)>> signal_DataServiceSubscription();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<std::tuple<uint32_t,
                                                                           uint32_t>>>)>> signal_DataAvailable();
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> signal_InstallStatus();
  std::shared_ptr<DBus::SignalProxy<void(std::string)>> signal_ESNInfo();
  std::shared_ptr<DBus::SignalProxy<void(double, double, double)>> signal_VehicleLocation();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_FuelDataUpdated();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_StockAdded();
  std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_StockRemoved();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_StockDataUpdated();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_StockOTAUnAvailable();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_MoviesDataUpdated();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_WeatherForecastDataUpdated();
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<std::tuple<uint32_t,
                                                                           std::string,
                                                                           uint16_t,
                                                                           std::string>>>)>> signal_WSAlertDataUpdated();
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> signal_WSHighAlertData();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_CityListAvailable();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> signal_ParkingDataUpdated();
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, bool)>> signal_SportsDataUpdated();
  std::shared_ptr<DBus::SignalProxy<void()>> signal_ShowSXMServices();
 protected:
  std::shared_ptr<DBus::MethodProxy<uint32_t()>> m_method_GetSubscriptionStatus;
  std::shared_ptr<DBus::MethodProxy<uint32_t()>> m_method_GetDataServiceSubscriptions;
  std::shared_ptr<DBus::MethodProxy<uint32_t()>> m_method_GetDataAvailable;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetInstallStatus;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetESN;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetVehicleLocation;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::string)>> m_method_AddStock;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::string)>> m_method_RemoveStock;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, uint32_t>()>> m_method_GetStockCount;
  std::shared_ptr<DBus::MethodProxy<int32_t()>> m_method_GetWSAlertData;
  std::shared_ptr<DBus::MethodProxy<int32_t(bool)>> m_method_SaveWSAlertSetting;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<int32_t, bool>()>> m_method_GetWSAlertSetting;
  std::shared_ptr<DBus::MethodProxy<void(uint32_t)>> m_method_WSHighAlertDataOverride;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, std::string, uint16_t, std::string, uint32_t>()>>
      m_method_GetWSHighAlertData;
  std::shared_ptr<DBus::MethodProxy<uint32_t(std::string)>> m_method_SelectState;
  std::shared_ptr<DBus::MethodProxy<uint32_t(std::string)>> m_method_SelectCity;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, std::tuple<std::vector<std::string>>>()>>
      m_method_GetRecentCities;
  std::shared_ptr<DBus::MethodProxy<uint32_t(uint32_t)>> m_method_SetSelectedRate;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, uint32_t>()>> m_method_GetSelectedRate;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_SaveParkingCountrySetting;
  std::shared_ptr<DBus::MethodProxy<uint32_t()>> m_method_GetParkingCountrySetting;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, std::tuple<std::vector<std::string>>>()>>
      m_method_GetLastViewedSportTeamList;
  std::shared_ptr<DBus::MethodProxy<uint32_t(std::string)>> m_method_SelectSportTeam;
  std::shared_ptr<DBus::MethodProxy<uint32_t(uint32_t)>> m_method_DisplayNNGServices;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_SaveFuelSetting;
  std::shared_ptr<DBus::MethodProxy<int32_t(std::tuple<std::vector<std::string>>)>> m_method_SaveFuelBrandSetting;
  std::shared_ptr<DBus::MethodProxy<int32_t(uint32_t)>> m_method_SaveFuelCountrySetting;
  std::shared_ptr<DBus::MethodProxy<uint32_t()>> m_method_GetFuelSetting;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<uint32_t, std::tuple<std::vector<std::string>>>()>>
      m_method_GetFuelBrandSetting;
  std::shared_ptr<DBus::MethodProxy<uint32_t()>> m_method_GetFuelCountrySetting;
  std::shared_ptr<DBus::MethodProxy<DBus::MultipleReturn<bool, std::string>()>> m_method_GetWeatherCitySelect;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<uint32_t, uint8_t, uint32_t, std::string, std::string>)>>
      m_signalproxy_SubscriptionStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<std::tuple<uint32_t, uint32_t>>>)>>
      m_signalproxy_DataServiceSubscription;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<std::tuple<uint32_t, uint32_t>>>)>>
      m_signalproxy_DataAvailable;
  std::shared_ptr<DBus::SignalProxy<void(int32_t)>> m_signalproxy_InstallStatus;
  std::shared_ptr<DBus::SignalProxy<void(std::string)>> m_signalproxy_ESNInfo;
  std::shared_ptr<DBus::SignalProxy<void(double, double, double)>> m_signalproxy_VehicleLocation;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_FuelDataUpdated;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_StockAdded;
  std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_StockRemoved;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_StockDataUpdated;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_StockOTAUnAvailable;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_MoviesDataUpdated;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_WeatherForecastDataUpdated;
  std::shared_ptr<DBus::SignalProxy<void(std::tuple<std::vector<std::tuple<uint32_t,
                                                                           std::string,
                                                                           uint16_t,
                                                                           std::string>>>)>>
      m_signalproxy_WSAlertDataUpdated;
  std::shared_ptr<DBus::SignalProxy<void(uint16_t)>> m_signalproxy_WSHighAlertData;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_CityListAvailable;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t)>> m_signalproxy_ParkingDataUpdated;
  std::shared_ptr<DBus::SignalProxy<void(uint32_t, bool)>> m_signalproxy_SportsDataUpdated;
  std::shared_ptr<DBus::SignalProxy<void()>> m_signalproxy_ShowSXMServices;
};
#endif /* COM_JCI_XMDATAPROXY_H */
