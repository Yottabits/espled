//--Includes--------------------------------------------------------------------
#include <FS.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <string.h>
#include <ArduinoOTA.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include <PubSubClient.h>
#include <StripControle.h>
#include <ArduinoJson.h>
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

typedef struct{
  unsigned byte mode;
  CRGBWW colorValue;
  unsigned int time;
  unsigned int frequency;
  unsigned byte sensitivity;
  unsigned int position;
  unsigned int length;
} varSilo;


char mqtt_server[40];
char mqtt_port[6] = "8080";
bool shouldSaveConfig = false;

//const char* mqtt_server = "broker.mqtt-dashboard.com";
const char* mqtt_device_id = "/rgbController/";
//const unsigned int mqtt_port = 1883;

WiFiClient espClient;
WiFiManager wifiManager;
PubSubClient client(espClient);


//long lastMsg = 0;
//char msg[50];
//int value = 0;


//callback notifying us of the need to save config
void saveConfigCallback () {
  Serial.println("Should save config");
  shouldSaveConfig = true;
}





typedef struct{
  int r, g, b;
} ColorValue;

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

void initMQTT() {
  // Loop until we're reconnected
  while (!client.connected())
  {
    Serial.println("Attempting MQTT connection with:");
    Serial.println(mqtt_server);
    Serial.println(atoi(mqtt_port));
    // Create a random client ID
    String clientId = "RGB-Controller";
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      char mainTopic[80] = "/ESPLED/";
      strcat(mainTopic, WiFi.macAddress().c_str());
      Serial.print("Main Topic: ");
      Serial.println(mainTopic);

      Serial.println("connected");

      char readyTopic[80];
      strcat(readyTopic, mainTopic);
      strcat(readyTopic, "/status");

      client.publish(readyTopic, "ready");
      client.subscribe(mainTopic);
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

void initWifi(){
  if(digitalRead(pinM) == LOW){
    wifiManager.resetSettings();
    digitalWrite(pinB, HIGH);
    delay(500);
    digitalWrite(pinB, LOW);
  }
  WiFiManagerParameter custom_mqtt_server("server", "mqtt server", mqtt_server, 40);
  WiFiManagerParameter custom_mqtt_port("port", "mqtt port", mqtt_port, 6);

  wifiManager.setSaveConfigCallback(saveConfigCallback);

  wifiManager.addParameter(&custom_mqtt_server);
  wifiManager.addParameter(&custom_mqtt_port);

  wifiManager.autoConnect("RGB Controller Setup");
  wifiManager.setConfigPortalTimeout(180);

  //After the WiFi Manger is done, we are most probably connected
  Serial.println("local ip");
  Serial.println(WiFi.localIP());


  strcpy(mqtt_server, custom_mqtt_server.getValue());
  strcpy(mqtt_port, custom_mqtt_port.getValue());

  //save the custom parameters to FS
  if (shouldSaveConfig) {
    Serial.println("saving config");

    DynamicJsonDocument doc(4000);
    JsonObject json = doc.to<JsonObject>();

    json["mqtt_server"] = mqtt_server;
    json["mqtt_port"] = mqtt_port;

    File configFile = SPIFFS.open("/config.json", "w");
    if (!configFile) {
      Serial.println("failed to open config file for writing");
    }

    serializeJson(json, Serial);
    serializeJson(json, configFile);
    configFile.close();
    //end save
  }
  client.setServer(mqtt_server, atoi(mqtt_port));
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

void initFS(){
  Serial.println("mounting FS...");

  if (SPIFFS.begin()) {
    Serial.println("mounted file system");
    if (SPIFFS.exists("/config.json")) {
      //file exists, reading and loading
      Serial.println("reading config file");
      File configFile = SPIFFS.open("/config.json", "r");
      if (configFile) {
        Serial.println("opened config file");
        size_t size = configFile.size();
        // Allocate a buffer to store contents of the file.
        std::unique_ptr<char[]> buf(new char[size]);

        configFile.readBytes(buf.get(), size);

        DynamicJsonDocument doc(2000);
        DeserializationError error = deserializeJson(doc, buf.get());
        if (error) {
        }
        JsonObject json = doc.as<JsonObject>();



        serializeJson(json, Serial);
        if (!json.isNull()) {
          Serial.println("\nparsed json");

          strcpy(mqtt_server, json["mqtt_server"]);
          strcpy(mqtt_port, json["mqtt_port"]);

        } else {
          Serial.println("failed to load json config");
        }
        configFile.close();
      }
    }
  } else {
    Serial.println("failed to mount FS");
  }
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

  initFS();
  initWifi();
  initMQTT();
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
  client.loop();
}
