//--Includes--------------------------------------------------------------------
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include <PubSubClient.h>
//#include <pwm.c>
//--Includes--------------------------------------------------------------------


//--PinDefines------------------------------------------------------------------
#define pinR 16
#define pinG 5
#define pinB 14
#define pinM 2
#define pinWW 12
#define pinCW 13
//------------------------------------------------------------------------------

const char* mqtt_server = "broker.mqtt-dashboard.com";
const char* mqtt_device_id = "/rgbController/";
const unsigned int mqtt_port = 1883;

WiFiClient espClient;
WiFiManager wifiManager;
PubSubClient client(espClient);



long lastMsg = 0;
char msg[50];
int value = 0;








typedef struct{
  int r, g, b;
} ColorValue;

#define PWM_CHANNELS 5
const uint32_t period = 5000; // * 200ns ^= 1 kHz

// PWM setup
uint32 io_info[PWM_CHANNELS][3] = {
	// MUX, FUNC, PIN
	{PERIPHS_IO_MUX_MTDI_U,  FUNC_GPIO12, 12},
	{PERIPHS_IO_MUX_MTDO_U,  FUNC_GPIO15, 15},
	{PERIPHS_IO_MUX_MTCK_U,  FUNC_GPIO13, 13},
	{PERIPHS_IO_MUX_MTMS_U,  FUNC_GPIO14, 14},
	{PERIPHS_IO_MUX_GPIO5_U, FUNC_GPIO5 ,  5},
};

// initial duty: all off
uint32 pwm_duty_init[PWM_CHANNELS] = {0, 0, 0, 0, 0};
/*
pwm_init(period, pwm_duty_init, PWM_CHANNELS, io_info);
pwm_start();

// do something like this whenever you want to change duty
pwm_set_duty(500, 1);  // GPIO15: 10%
pwm_set_duty(5000, 1); // GPIO15: 100%
pwm_start();           // commit
*/
ColorValue currentRGB;
ColorValue finalRGB;



void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");

  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }

  Serial.println();
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "RGB-Controller";
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      //client.publish("outTopic", "hello world");
      //client.subscribe("inTopic");
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void handleFade(){}



  Serial.println("local ip");
  Serial.println(WiFi.localIP());
}

void initWifi(){
  if(digitalRead(pinM) == LOW){
    wifiManager.resetSettings();
    digitalWrite(pinB, HIGH);
    delay(500);
    digitalWrite(pinB, LOW);
  }

  wifiManager.autoConnect("RGB Controller Setup");
  wifiManager.setConfigPortalTimeout(180);

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void initOta(){
  //TODO: Password
  //Init OTA update routine
  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) {
      type = "sketch";
    } else { // U_SPIFFS
      type = "filesystem";
    }
    Serial.println("Start updating " + type);
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) {
      Serial.println("Auth Failed");
    } else if (error == OTA_BEGIN_ERROR) {
      Serial.println("Begin Failed");
    } else if (error == OTA_CONNECT_ERROR) {
      Serial.println("Connect Failed");
    } else if (error == OTA_RECEIVE_ERROR) {
      Serial.println("Receive Failed");
    } else if (error == OTA_END_ERROR) {
      Serial.println("End Failed");
    }
  });
  ArduinoOTA.begin();
}

void initPins(){
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinWW, OUTPUT);
  pinMode(pinCW, OUTPUT);

  pinMode(pinM, INPUT_PULLUP);

  digitalWrite(pinR, LOW);
  digitalWrite(pinG, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinWW, LOW);
  digitalWrite(pinCW, LOW);
}




void setup(){
  initPins();

  Serial.begin(115200);
  delay(50);
  Serial.println("Booting");

  delay(500);

  initWifi();
  initOta();

  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  ArduinoOTA.handle();


  // for(int i=0; i<1023; i++){
  //   analogWrite(pinR, i);
  //   delay(1);
  // }
  // digitalWrite(pinR, LOW);
  // for(int i=0; i<1023; i++){
  //   analogWrite(pinG, i);
  //   delay(1);
  // }
  // digitalWrite(pinG, LOW);
  // for(int i=0; i<1023; i++){
  //   analogWrite(pinB, i);
  //   delay(1);
  // }
  // digitalWrite(pinB, LOW);
  // for(int i=0; i<1023; i++){
  //   analogWrite(pinWW, i);
  //   delay(1);
  // }
  // digitalWrite(pinWW, LOW);
  // for(int i=0; i<1023; i++){
  //   analogWrite(pinCW, i);
  //   delay(1);
  // }
  // digitalWrite(pinCW, LOW);
  // //reconnect();

}
