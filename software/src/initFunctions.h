#ifndef INITFUNCTIONS_H
#define INITFUNCTIONS_H

#include "configuration.h"

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
#include <TypeDefinitions.h>
#include <PinDefinitions.h>
#include <StripControle.h>
#include <AnimationHandlerBus.h>
#include <AnimationHandlerPWM.h>
#include <FastLED.h>
#include <ArduinoJson.h>

extern void debugFkt(String, LogLevel);



//ToDo Fix typo
varSilo* Silo;
bool* varSiloChanged = new bool(false);

StripType type;
bool shouldSaveConfig = false;

WiFiManager wifiManager;

// Create a client ID for Wifi Name and MQTT identifier
String clientId = "RGB-Controller-" + WiFi.macAddress();

WiFiClient espClient;
WiFiClientSecure espClientSecure;

PubSubClient client;

StripControle* simpleStrip;
MicHandler* micHandler;

AnimationHandlerPWM* pwmHandler;
AnimationHandlerBus* busHandler;
//TODO: Adressable Strip


//callback notifying us of the need to save config
void saveConfigCallback () {
  debugFkt("Should save config", INFO);
  shouldSaveConfig = true;
}

void initWifi(){
  // Initializes Wifi on esp8266 uses wifi-manager to spin up a http server + captive portal for the setup process
  // Settings are saved of filesystem (json) and are recovered automatically once saved

  WiFiManagerParameter custom_mqtt_server("server", "mqtt server", mqtt_server, 40);
  WiFiManagerParameter custom_mqtt_port("port", "mqtt port", mqtt_port, 6);
  WiFiManagerParameter custom_strip_type("strip_type", "strip type", strip_type, 8);
  WiFiManagerParameter custom_strip_length("strip_length", "-1", strip_length, 5);
  WiFiManagerParameter custom_mqtt_ssl("ssl", "no", mqtt_ssl, 3);
  WiFiManagerParameter custom_mqtt_username("mqtt_username", "username", mqtt_username, 40);
  WiFiManagerParameter custom_mqtt_password("mqtt_password", "password", mqtt_password, 40);

  wifiManager.setSaveConfigCallback(saveConfigCallback);

  wifiManager.addParameter(&custom_mqtt_server);
  wifiManager.addParameter(&custom_mqtt_port);
  wifiManager.addParameter(&custom_strip_type);
  wifiManager.addParameter(&custom_strip_length);
  wifiManager.addParameter(&custom_mqtt_ssl);
  wifiManager.addParameter(&custom_mqtt_username);
  wifiManager.addParameter(&custom_mqtt_password);

  wifiManager.autoConnect(clientId.c_str());
  wifiManager.setConfigPortalTimeout(180);

  //After the WiFi Manger is done, we are most probably connected
  debugFkt("local ip", INFO);
  debugFkt(WiFi.localIP().toString(), INFO);

  //setup main Topic and debug topic path in mqtt
  strcat(mainTopic, WiFi.macAddress().c_str());
  strcat(debugTopic, mainTopic);
  strcat(debugTopic, "/debug");


  strcpy(mqtt_server, custom_mqtt_server.getValue());
  strcpy(mqtt_port, custom_mqtt_port.getValue());
  strcpy(strip_type, custom_strip_type.getValue());
  strcpy(strip_length, custom_strip_length.getValue());
  strcpy(mqtt_ssl, custom_mqtt_ssl.getValue());
  strcpy(mqtt_username, custom_mqtt_username.getValue());
  strcpy(mqtt_password, custom_mqtt_password.getValue());


  //save the custom parameters to FS
  if (shouldSaveConfig) {
    debugFkt("saving config", INFO);

    DynamicJsonDocument doc(4000);
    JsonObject json = doc.to<JsonObject>();

    json["mqtt_server"] = mqtt_server;
    json["mqtt_port"] = mqtt_port;
    json["strip_type"] = strip_type;
    json["strip_length"] = strip_length;
    json["mqtt_ssl"] = mqtt_ssl;
    json["mqtt_username"] = mqtt_username;
    json["mqtt_password"] = mqtt_password;


    File configFile = SPIFFS.open("/config.json", "w");
    if (!configFile) {
      debugFkt("failed to open config file for writing", ERROR);
    }

    serializeJson(json, Serial);
    serializeJson(json, configFile);
    configFile.close();
    //end save
  }
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
    debugFkt("Start updating " + type, INFO);
  });
  ArduinoOTA.onEnd([]() {
    debugFkt("End", INFO);
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) {
      debugFkt("Auth Failed", ERROR);
    } else if (error == OTA_BEGIN_ERROR) {
      debugFkt("Begin Failed", ERROR);
    } else if (error == OTA_CONNECT_ERROR) {
      debugFkt("Connect Failed", ERROR);
    } else if (error == OTA_RECEIVE_ERROR) {
      debugFkt("Receive Failed", ERROR);
    } else if (error == OTA_END_ERROR) {
      debugFkt("End Failed", ERROR);
    }
  });
  ArduinoOTA.begin();
}


void initFS(){
  debugFkt("mounting FS...", INFO);

  if (SPIFFS.begin()) {
    debugFkt("mounted file system", INFO);
    if (SPIFFS.exists("/config.json")) {
      //file exists, reading and loading
      debugFkt("reading config file", INFO);
      File configFile = SPIFFS.open("/config.json", "r");
      if (configFile) {
        debugFkt("opened config file", INFO);
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
          debugFkt("parsed json", INFO);

          strcpy(mqtt_server, json["mqtt_server"]);
          strcpy(mqtt_port, json["mqtt_port"]);
          strcpy(strip_type, json["strip_type"]);
          strcpy(strip_length, json["strip_length"]);
          strcpy(mqtt_ssl, json["mqtt_ssl"]);
          strcpy(mqtt_username, json["mqtt_username"]);
          strcpy(mqtt_password, json["mqtt_password"]);

        } else {
          debugFkt("failed to load json config", ERROR);
        }
        configFile.close();
      }
    }
  } else {
    debugFkt("failed to mount FS", ERROR);
  }
  debugFkt("Finished spiffs", INFO);
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

  analogWriteFreq(pwmFreq);
}

void initStrip(){
  // initializes strip and variable Silo
  // depends on Strip-Settings made during wifi-setup process

  if(strcmp(strip_type, "RGB") == 0) type = StripType::RGB_STRIP;
  else if(strcmp(strip_type, "RGBW") == 0) type = StripType::RGBW_STRIP;
  else if(strcmp(strip_type, "RGBWW") == 0) type = StripType::RGBWW_STRIP;
  else if(strcmp(strip_type, "WS2812") == 0) type = StripType::WS2812_STRIP;
  else if(strcmp(strip_type, "APA102") == 0) type = StripType::APA102_STRIP;

  // allokate Storage for varSilo and oldVarSilo
  Silo = new varSilo();
  Silo->oldVarSilo = new varSilo();

  micHandler = new MicHandler(Silo);

  if(type < 6){
    debugFkt("Animation handler, strip and Silo initialized [uniform strip]", INFO);

    simpleStrip = new StripControle(type);
    pwmHandler = new AnimationHandlerPWM(simpleStrip, Silo, varSiloChanged, micHandler);
  }
  else{

    debugFkt("Animation handler, strip and Silo initialized [adressable strip]", INFO);
    //TODO

    //get strip length:
    int length = atoi(strip_length);
    if(length < 0){
      debugFkt("Negative Strip_Length specified -> Bus Handler inititilized with one led, resetup board", ERROR);
      busHandler = new AnimationHandlerBus(1, Silo, varSiloChanged, micHandler);
    }else{
      busHandler = new AnimationHandlerBus(length, Silo, varSiloChanged, micHandler);
    }
  }
}


//WARNING: If received json incomplete, increase MQTT_MAX_PACKET_SIZE in PubSunClient Library
void callback(char* topic, byte* payload, unsigned int length) {
  for (unsigned int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }

  //use Stack
  StaticJsonDocument<1024> doc;
  //use Heap
  //DynamicJsonDocument doc(2048);

  deserializeJson(doc, payload, length);

  // if we are currently in a temporary mode and the new mode in the mqtt message is
  // also a temporary mode - dismiss message
  if(Silo->oldVarSilo->mode == 1 && doc["mode"] == 1){
    return;
  }

  //Store varSilo State to oldVarSilo (deep copy)
  *(Silo->oldVarSilo) = *Silo;

  if(doc.containsKey("mode")) Silo->mode = doc["mode"];
  if(doc.containsKey("color")){
    Silo->colorValue.R = doc["color"][0];
    Silo->colorValue.G = doc["color"][1];
    Silo->colorValue.B = doc["color"][2];
    Silo->colorValue.WW = doc["color"][3];
    Silo->colorValue.CW = doc["color"][4];
  }
  if(doc.containsKey("time")) Silo->time = doc["time"];
  if(doc.containsKey("frequency")) Silo->frequency = doc["frequency"];
  if(doc.containsKey("sensitivity")) Silo->sensitivity = doc["sensitivity"];
  if(doc.containsKey("length")) Silo->length = doc["length"];
  if(doc.containsKey("position")) Silo->position = doc["position"];
  if(doc.containsKey("minBrightnes")) Silo->minBrightnes = doc["minBrightnes"];
  if(doc.containsKey("maxBrightnes")) Silo->maxBrightnes = doc["maxBrightnes"];
  if(doc.containsKey("timeVariance")) Silo->timeVariance = doc["timeVariance"];
  if(doc.containsKey("maxBrightnesVariance")) Silo->maxBrightnesVariance = doc["maxBrightnesVariance"];
  if(doc.containsKey("duration")) Silo->duration = doc["duration"];


  debugFkt("Message arrived, Length: " + String(length), INFO);

  debugFkt("Parsed Values", DEBUG);
  debugFkt("Mode: " + String(Silo->mode), DEBUG);
  debugFkt("(R-G-B-CW-WW): "+(String)Silo->colorValue.R+ "-" + (String)Silo->colorValue.G+ "-" + (String)Silo->colorValue.B+ "-" + (String)Silo->colorValue.CW+ "-" + (String)Silo->colorValue.WW,DEBUG);
  debugFkt("Time: " + String(Silo->time), DEBUG);
  debugFkt("Freq: " + String(Silo->frequency), DEBUG);
  debugFkt("sensitivity: " + String(Silo->sensitivity), DEBUG);
  debugFkt("length: " + String(Silo->length), DEBUG);
  debugFkt("position: " + String(Silo->position), DEBUG);
  debugFkt("maxBrightnes: " + String(Silo->maxBrightnes), DEBUG);
  debugFkt("minBrightnes: " + String(Silo->minBrightnes), DEBUG);
  debugFkt("timeVariance: " + String(Silo->timeVariance), DEBUG);
  debugFkt("maxBrightnesVariance: " + String(Silo->maxBrightnesVariance), DEBUG);

  *varSiloChanged = true;
}



void initMQTT() {
  if(strcmp(mqtt_ssl, "yes") == 0){
    client = PubSubClient(espClientSecure);
    debugFkt("Will compare SSL-Fingerprint and use WifiClientSecure", INFO);
    espClientSecure.setFingerprint(fingerprint);
  }else{
    client = PubSubClient(espClient);
    debugFkt("Will not use SSL -> Standard WifiClient", INFO);
  }

  //set the server and callback function
  client.setServer(mqtt_server, atoi(mqtt_port));
  client.setCallback(callback);


  // Loop until we're reconnected
  byte reconnectCounter = 0;
  while (!client.connected())
  {
    debugFkt("Attempting MQTT connection with: [server, port, ssl, user, pw]", INFO);
    debugFkt(mqtt_server, INFO);
    debugFkt(String(atoi(mqtt_port)), INFO);
    debugFkt(mqtt_ssl, INFO);
    debugFkt(mqtt_username, INFO);
    debugFkt(mqtt_password, INFO);



    client.setServer(mqtt_server, atoi(mqtt_port));
    client.setCallback(callback);

    // Attempt to connect
    bool connected = false;
    if(strcmp(mqtt_ssl, "yes") == 0){
      debugFkt("connecting to mqtt server with password and username", INFO);
      connected = client.connect(clientId.c_str(), mqtt_username, mqtt_password);
    }else{
      debugFkt("connecting to mqtt server without username and password", INFO);
      connected = client.connect(clientId.c_str());
    }

    //react to outcome of connect try
    if (connected) {

      debugFkt("Now Connected - Main Topic of this device: ", INFO);
      debugFkt(mainTopic, INFO);
      debugFkt("-------------", INFO);

      //subscribe this device's topic
      client.subscribe(mainTopic);

      debugFkt("subscribed main Topic ", INFO);

      //Publish Info that Board Connected
      //client.publish("/ESPLED/",WiFi.macAddress().c_str());
      String HelloMessage = "espled-board "+ WiFi.macAddress() + " connected";
      client.publish("/ESPLED/", HelloMessage.c_str());
    }
    else
    {
      //Display Error and retry
      debugFkt("failed, rc=", ERROR);
      debugFkt(String(client.state()), ERROR);
      debugFkt("Try again in 5 seconds", ERROR);

      //restart esp after 10 tries
      if(reconnectCounter++ > 10) ESP.restart();

      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

#endif
