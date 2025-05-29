#define BLYNK_TEMPLATE_ID "TMPL6HOJBzMD0"
#define BLYNK_TEMPLATE_NAME "ESP32 SensorUpdater"
#define BLYNK_AUTH_TOKEN "hJgqjTXA5cPqRychjZos7jHKfc2ZAhlD"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <ESPWifiConfig.h>

int Apin = 34;
int TDSpin = 36;
int TrigD = 14;
int EchoD = 13;
int TrigT = 33;
int EchoT = 25;
int TrigH = 32;
int EchoH = 35;

BlynkTimer timer;

int ServerPort = 80;
int Config_reset_btn = -1;

boolean debug = false; 

ESPWifiConfig WifiConfig("DapDang", ServerPort, Config_reset_btn, false, "", "", debug);

#define NO_CONNECTION_RESTART_DELAY 3600000 //ms, 1 hour
#define NO_CONNECTION_GO_WILD_DELAY 1800000 //ms, 30 minutes


unsigned long last_wifi_connect_time = 0;
unsigned long reconnect_delay = 10000;

boolean ensure_wifi_connectivity(unsigned long no_conn_go_wild_delay, unsigned long no_conn_restart_delay);

uint16_t WaterLevelSensor(int Trigpin ,int Echopin){
  digitalWrite(Trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigpin,  HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigpin, LOW);

  const unsigned long duration = pulseIn(Echopin, HIGH, 30000);

  if (duration == 0) return 999;

  int distance= duration/29/2;
  if (distance>20){distance = 20;}
  int value = 20 - distance;
  return value;
}

bool connectyet = false;

void myTimerEvent()
{
  int RawSensorValues = analogRead(Apin);

  float rawValue = analogRead(TDSpin);
  float volt = (rawValue / 4095.0)*2.3;
  int TDSValue = (133.42 * volt * volt * volt - 255.86 * volt * volt + 857.39 * volt) * 0.5;
  int Salinity = TDSValue * 0.64;
  int SalinityValue = map(Salinity, 0, 717, 0, 1000);
  int sensorValue = map(RawSensorValues, 0, 4095 ,0 ,1000);
  if (sensorValue <= 800){
    Blynk.virtualWrite(V0, 1);
  }
  else{
    Blynk.virtualWrite(V0, 0);
  }
  Blynk.virtualWrite(V4, SalinityValue);
  Blynk.virtualWrite(V2, WaterLevelSensor(TrigD ,EchoD));
  Blynk.virtualWrite(V3, WaterLevelSensor(TrigH ,EchoH));
  Blynk.virtualWrite(V1, WaterLevelSensor(TrigT ,EchoT));
}

void setup() {
  Serial.begin(115200);
  Serial.println("Start");
  Serial.println(WiFi.macAddress());

  if (WifiConfig.initialize() == AP_MODE)
  {
    WifiConfig.Start_HTTP_Server(600000); 

    Serial.println("ESP is running in AP MODE");
    Serial.print("Connect to it's Wifi named: ");
    Serial.println(WifiConfig.get_AP_name());
  }
  else 
  {
    //
  }
  WifiConfig.print_settings();
  WifiConfig.ESP_debug("Hello");

  while(connectyet == false){
    WifiConfig.handle(reconnect_delay);
    if (ensure_wifi_connectivity(NO_CONNECTION_GO_WILD_DELAY, NO_CONNECTION_RESTART_DELAY)) 
    {
      connectyet = true;
      Serial.println("Connected");
    }
    else
    {
      connectyet = false;
      WifiConfig.ESP_reset_settings();
    }
  }

  Serial.println(WifiConfig.setting[WIFI_SSID].value);
  Serial.println(WifiConfig.setting[WIFI_PASS].value);
  Blynk.begin(BLYNK_AUTH_TOKEN, WifiConfig.setting[WIFI_SSID].value, WifiConfig.setting[WIFI_PASS].value);
  Serial.println("Blynk");

  timer.setInterval(2000L, myTimerEvent);
  pinMode(TrigD, OUTPUT);
  pinMode(EchoD, INPUT);
  pinMode(TrigT, OUTPUT);
  pinMode(EchoT, INPUT);
  pinMode(TrigH, OUTPUT);
  pinMode(EchoH, INPUT);
  pinMode(Apin, INPUT);
  pinMode(TDSpin, INPUT);
}

void loop()  {
  Blynk.run();
  timer.run();
}

boolean ensure_wifi_connectivity(unsigned long no_conn_go_wild_delay, unsigned long no_conn_restart_delay)
{
  //Access point mode
  if (WifiConfig.ESP_mode == AP_MODE)
  {
    if (millis() > no_conn_go_wild_delay)
    {
      WifiConfig.goWild();
    }
  }
  else
  {
    if (WifiConfig.ESP_mode == CLIENT_MODE)
    {
      if (WifiConfig.wifi_connected)
      {
        last_wifi_connect_time = millis();
        reconnect_delay = 10000;
        return true;
      }
      else
      {
        reconnect_delay = 30000; 

        if ((millis() - last_wifi_connect_time) > no_conn_restart_delay)
        {
          Serial.println("Restarting...");
          ESP.restart();          
        }
        else if ((millis() - last_wifi_connect_time) > no_conn_go_wild_delay)
        {
          if (WifiConfig.goWild() > 0)
          {
            Serial.println("Connecting to open WiFi");
          }
          else
          {
            WifiConfig.wifiscan();
            delay(20000); 
          }
        }
      }
    }
  }
  return false;
}