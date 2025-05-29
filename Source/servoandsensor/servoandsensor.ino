#define BLYNK_TEMPLATE_ID "TMPL6HOJBzMD0"
#define BLYNK_TEMPLATE_NAME "ESP32 SensorUpdater"
#define BLYNK_AUTH_TOKEN "hJgqjTXA5cPqRychjZos7jHKfc2ZAhlD"


#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>
#include <ESPWifiConfig.h>


BlynkTimer timer;

int ServerPort = 80;
int Config_reset_btn = -1;

boolean debug = true; 

ESPWifiConfig WifiConfig("DapDang2", ServerPort, Config_reset_btn, false, "","", debug);

#define NO_CONNECTION_RESTART_DELAY 3600000 //ms, 1 hour
#define NO_CONNECTION_GO_WILD_DELAY 1800000 //ms, 30 minutes


unsigned long last_wifi_connect_time = 0;
unsigned long reconnect_delay = 10000;

boolean ensure_wifi_connectivity(unsigned long no_conn_go_wild_delay, unsigned long no_conn_restart_delay);

bool connectyet = false;//To check the connect


const int servoPinfish = 12;
const int servoPin1    = 14;
const int servoPin2    = 27;
const int servoPin3    = 26;

Servo servofishladder;
Servo servo1;
Servo servo2;
Servo servo3;

bool autoFishMode = false;
int autoMode= 0;

int fishServoValue = 0;
int servo1Value    = 0;
int servo2Value    = 0;
int servo3Value    = 0;

int Thuong_Mua = 0;
int Thuong_WL = 0;
int Dap_WL = 0;
int Ha_WL = 0;
int Ha_SL = 0;
int Thuong_H = 15;
int Thuong_L = 5;
int Dap_H = 12;
int Dap_L = 5;
int Ha_H = 8;
int Ha_L = 3;
int DamWaterLevel = 8;
int VanHigh = 0;

int getangle(int high) {
  return map(high, 0, 20, 0, 180);
}

void myTimerEvent()
{
  Blynk.syncVirtual(V0);
  Blynk.syncVirtual(V1);
  Blynk.syncVirtual(V2);
  Blynk.syncVirtual(V3);
  Blynk.syncVirtual(V4);
  Blynk.syncVirtual(V6);
  Blynk.syncVirtual(V7);
}

BLYNK_WRITE(V6) {
  autoFishMode = (param.asInt() == 1);  // 1 thì bật chế độ tự động thang cá
  if (autoFishMode == true) {
    servofishladder.write(getangle(Dap_WL));
  } else {
    servofishladder.write(fishServoValue);
  }
}

BLYNK_WRITE(V0) {  
  Thuong_Mua = param.asInt();
  Serial.println(Thuong_Mua);   
}
BLYNK_WRITE(V1) {
  Thuong_WL = param.asInt();
  Serial.print("Thuong WL__: ");
  Serial.println(Thuong_WL);
}
BLYNK_WRITE(V2) {  Dap_WL  = param.asInt(); }
BLYNK_WRITE(V3) {  Ha_WL   = param.asInt(); }
BLYNK_WRITE(V4) {  Ha_SL  = param.asInt(); }
BLYNK_WRITE(V14) {
  int x = param.asInt();
  fishServoValue = map(x, 0, 100, 0, 180);
}
BLYNK_WRITE(V15) {
  int y = param.asInt();
  servo1Value = map(y, 0, 100, 0, 180);
}
BLYNK_WRITE(V16) {
  int z = param.asInt();
  servo2Value = map(z, 0, 100, 0, 180);
}
BLYNK_WRITE(V17) {
  int t = param.asInt();
  servo3Value = map(t, 0, 100, 0, 180);
}

void AutoVan(){                      
  if ((Thuong_WL >= Thuong_H)||(Dap_WL >= Dap_H)) {
    Serial.println("Nếu mực nước thượng nguồn cao");
    servo1Value = 180;
    servo2Value = 180;
    servo3Value = 180;
  } 
  if ((Thuong_WL > 5 && Thuong_WL < 15) || ((Dap_WL > Dap_L) && (Dap_WL < Dap_H))) {
    int d = Dap_WL - DamWaterLevel;
    if (d > 0) {
      VanHigh = 10*d;
    }
    else if (d < 0){
      VanHigh = 10/(abs(d));
    }
    else{
      VanHigh = 0;
    }
    servo1Value = VanHigh;
    servo2Value = VanHigh;
    servo3Value = VanHigh;
    Serial.println("Nếu mực nước thượng nguồn lớn hơn 5 và nhỏ hơn 15");
  }

  if (Ha_SL >=600 && Ha_SL <=799){
    servo1Value = VanHigh + 30;
    servo2Value = VanHigh + 40;
    servo3Value = VanHigh + 30;
  }
  if (Ha_SL >=800){
    servo1Value = VanHigh + 50;
    servo2Value = VanHigh + 60;
    servo3Value = VanHigh + 50;
    Serial.println("Độ mặn");
  }
}

BLYNK_WRITE(V7) {
  autoMode = param.asInt();  // 1 thì bật chế độ tự động van
  if (autoMode == 1) { 
    AutoVan();
    servo1.write(servo1Value);
    servo2.write(servo2Value);
    servo3.write(servo3Value);
    Serial.println("Autovan...");
  }
  else {
    servo1.write(servo1Value);
    servo2.write(servo2Value);
    servo3.write(servo3Value);
    Serial.print("servo1Value: "); Serial.println(servo1Value);
    Serial.print("servo2Value: "); Serial.println(servo2Value);
    Serial.print("servo3Value: "); Serial.println(servo3Value);
  }
}


void setup() {
  Serial.begin(115200);
  
  if (WifiConfig.initialize() == AP_MODE)//To check the mode,here AP mode
  {
  WifiConfig.Start_HTTP_Server(600000); 

  Serial.println("ESP is running in AP MODE");
  Serial.print("Connect to it's Wifi named: ");
  Serial.println(WifiConfig.get_AP_name());
  }
  else //Client mode
  {
    //dont do anything
  }
  WifiConfig.print_settings();
  WifiConfig.ESP_debug("Hello");

  while(connectyet == false){       //check the connect
    WifiConfig.handle(reconnect_delay);
    if (ensure_wifi_connectivity(NO_CONNECTION_GO_WILD_DELAY, NO_CONNECTION_RESTART_DELAY)) 
    {//if connect success
      connectyet = true;
    }
    else
    {//if Connect fail
      connectyet = false;
      WifiConfig.ESP_reset_settings();
    }
  }

  Blynk.begin(BLYNK_AUTH_TOKEN, WifiConfig.setting[WIFI_SSID].value, WifiConfig.setting[WIFI_PASS].value);
  timer.setInterval(1000L, myTimerEvent);
  Serial.println("blynk");
  servofishladder.attach(servoPinfish);
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servofishladder.write(90);
  delay(2000);
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  servofishladder.write(0);
  timer.setInterval(1000L, myTimerEvent);
}

void loop() {
  Blynk.run();
  timer.run();
}

boolean ensure_wifi_connectivity(unsigned long no_conn_go_wild_delay, unsigned long no_conn_restart_delay){
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