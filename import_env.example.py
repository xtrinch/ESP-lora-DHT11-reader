Import("env")

env.Append(CPPDEFINES=[
  ("SLEEP_SECONDS", 300), # how long the board will sleep between measurements in seconds
  ("SENSOR_DASHBOARD_URL", "sensor-dashboard.trina.si"),
  ("ONBOARD_WIFI_SSID", "ONBOARD-WIFI-SSID"), # onboard AP SSID during configuration
  ("ONBOARD_WIFI_PASSWORD", "ONBOARD-WIFI-PASSWORD") # onboard AP PASSWORD during configuration
  ("WIFI_SSID", "GNX3B7B4D"), # wifi ssid, applicable with PRECONFIGURED flag
	("WIFI_PASSWORD", "TDS9ULEWW2FQ"), # wifi password, applicable with PRECONFIGURED flag
  ("ACCESS_TOKEN", "2fe570e8-2c32-4603-95cd-416a02362aae"), # access token, applicable with PRECONFIGURED flag
  ("PING_URL", "/api/forwarders/ping"), # ping url, if pinging is enabled
  ("PRECONFIGURED") # remove if config is dynamic (saved in EEPROM)
])