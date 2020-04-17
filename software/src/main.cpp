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
#include <TypeDefinitions.h>
#include <PinDefinitions.h>
#include <StripControle.h>
#include <AnimationHandlerBus.h>
#include <AnimationHandlerPWM.h>
#include <ArduinoJson.h>
#include <FastLED.h>
//--Includes--------------------------------------------------------------------




//init verSilo

//ToDo Fix typo
varSilo* Silo;

bool* varSiloChanged = new bool(false);



char mqtt_server[40];
char mqtt_port[6] = "8080";
char strip_type[8] = "RGB";
char mainTopic[80] = "/ESPLED/";
char debugTopic[80];

stripType type;

bool shouldSaveConfig = false;

const char* mqtt_device_id = "/rgbController/";

const LogLevel LOGLEVEL = DEBUG;

WiFiClient espClient;
WiFiManager wifiManager;
PubSubClient client(espClient);

StripControle* simpleStrip;
AnimationHandlerPWM* pwmHandler;
AnimationHandlerBus* busHandler;
//TODO: Adressable Strip


void debugFkt(String message, LogLevel LevelOfMessage){
  if(LOGLEVEL <= LevelOfMessage){
    //Add Level to message
    switch (LevelOfMessage)
    {
    case VERBOSE:
      message = "[VERBOSE]:"+message;
      break;
    case DEBUG:
      message = "[DEBUG]:"+message;
      break;
    case INFO:
      message = "[INFO]:"+message;
      break;
    case WARNING:
      message = "[WARNING]:"+message;
      break;
    case ERROR:
      message = "[ERROR]:"+message;
      break;
    default:
      break;
    }
    message += "";

    static unsigned int lastMQTTPublished = 0;
    //if(millis() > lastMQTTPublished + 100F){
      lastMQTTPublished = millis();
      client.publish(debugTopic, message.c_str());
      Serial.println(message);
    //}

  }
}

//callback notifying us of the need to save config
void saveConfigCallback () {
  debugFkt("Should save config", INFO);
  shouldSaveConfig = true;
}

void firmmareReset(){
  if(digitalRead(pinM) == LOW){
    wifiManager.resetSettings();
    SPIFFS.format();
    digitalWrite(pinB, HIGH);
    delay(500);
    digitalWrite(pinB, LOW);
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
  Silo->mode = doc["mode"];
  Silo->colorValue.R = doc["color"][0];
  Silo->colorValue.G = doc["color"][1];
  Silo->colorValue.B = doc["color"][2];
  Silo->colorValue.WW = doc["color"][3];
  Silo->colorValue.CW = doc["color"][4];
  Silo->time = doc["time"];
  Silo->frequency = doc["frequency"];
  Silo->sensitivity = doc["sensitivity"];
  Silo->length = doc["length"];
  Silo->position = doc["position"];
  Silo->minBrightnes = doc["minBrightnes"];
  Silo->maxBrightnes = doc["maxBrightnes"];
  Silo->timeVariance = doc["timeVariance"];
  Silo->maxBrightnesVariance = doc["maxBrightnesVariance"];


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
  // Loop until we're reconnected
  while (!client.connected())
  {
    debugFkt("Attempting MQTT connection with:", INFO);
    debugFkt(mqtt_server, INFO);
    debugFkt(String(atoi(mqtt_port)), INFO);
    // Create a random client ID
    String clientId = "RGB-Controller";
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      strcat(mainTopic, WiFi.macAddress().c_str());
      strcat(debugTopic, mainTopic);
      strcat(debugTopic, "/debug");

      debugFkt("Main Topic: ", INFO);
      debugFkt(mainTopic, INFO);

      debugFkt("-------------", INFO);

      char readyTopic[80];
      strcat(readyTopic, mainTopic);
      strcat(readyTopic, "/status");

      client.publish(readyTopic, "ready");
      client.subscribe(mainTopic);
    }
    else
    {
      debugFkt("failed, rc=", ERROR);
      debugFkt(String(client.state()), ERROR);
      debugFkt("Try again in 5 seconds", ERROR);
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void initWifi()
{
  WiFiManagerParameter custom_mqtt_server("server", "mqtt server", mqtt_server, 40);
  WiFiManagerParameter custom_mqtt_port("port", "mqtt port", mqtt_port, 6);
  WiFiManagerParameter custom_strip_type("strip_type", "strip type", strip_type, 8);

  wifiManager.setSaveConfigCallback(saveConfigCallback);

  wifiManager.addParameter(&custom_mqtt_server);
  wifiManager.addParameter(&custom_mqtt_port);
  wifiManager.addParameter(&custom_strip_type);

  wifiManager.autoConnect("RGB Controller Setup");
  wifiManager.setConfigPortalTimeout(180);

  //After the WiFi Manger is done, we are most probably connected
  debugFkt("local ip", INFO);
  debugFkt(String(WiFi.localIP()), INFO);


  strcpy(mqtt_server, custom_mqtt_server.getValue());
  strcpy(mqtt_port, custom_mqtt_port.getValue());
  strcpy(strip_type, custom_strip_type.getValue());

  //save the custom parameters to FS
  if (shouldSaveConfig) {
    debugFkt("saving config", INFO);

    DynamicJsonDocument doc(4000);
    JsonObject json = doc.to<JsonObject>();

    json["mqtt_server"] = mqtt_server;
    json["mqtt_port"] = mqtt_port;
    json["strip_type"] = strip_type;

    File configFile = SPIFFS.open("/config.json", "w");
    if (!configFile) {
      debugFkt("failed to open config file for writing", ERROR);
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
          debugFkt("\nparsed json", INFO);

          strcpy(mqtt_server, json["mqtt_server"]);
          strcpy(mqtt_port, json["mqtt_port"]);
          strcpy(strip_type, json["strip_type"]);

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
}

void initStrip(){
  if(strcmp(strip_type, "RGB") == 0) type = stripType::RGB_STRIP;
  else if(strcmp(strip_type, "RGBW") == 0) type = stripType::RGBW_STRIP;
  else if(strcmp(strip_type, "RGBWW") == 0) type = stripType::RGBWW_STRIP;
  else if(strcmp(strip_type, "WS2812") == 0) type = stripType::WS2812_STRIP;
  else if(strcmp(strip_type, "APA102") == 0) type = stripType::APA102_STRIP;

  if(type < 6){
    debugFkt("Annimation handler, strip and Silo initialized", INFO);
    Silo = new varSilo();
    simpleStrip = new StripControle(type);
    pwmHandler = new AnimationHandlerPWM(simpleStrip, Silo, varSiloChanged);
  }
  else{
    //TODO
    //busHandler = new AnimationHandlerBus()
  }
}

void runAnnimationHandler(){
  if(type < 6){
    pwmHandler->handle();
  }
  else{
    //TODO
    //busHandler->handle();
  }
}


void setup(){
  initPins();

  firmmareReset();
  Serial.begin(115200);
  delay(50);
  debugFkt("Booting", INFO);

  delay(500);

  initFS();
  initWifi();
  initMQTT();
  initOta();
  initStrip();

  debugFkt("Ready", INFO);
  debugFkt("IP address: ", INFO);
  debugFkt(String(WiFi.localIP()), INFO);
  simpleStrip->showColor(CRGBWW{0,1023,0,1023,0});
  delay(500);
  simpleStrip->showColor(CRGBWW{0,0,0,0,0});
}

void loop() {
  //OTA Handler
  ArduinoOTA.handle();

  //Run PWM Handler handle
  runAnnimationHandler();

  //if(str)
  //TODO: Reconnect
  client.loop();
}
