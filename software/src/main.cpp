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
#include <DHTesp.h>
//--Includes--------------------------------------------------------------------


//ToDo Fix typo
varSilo* Silo;

bool* varSiloChanged = new bool(false);

const unsigned int pwmFreq = 2000;

char mqtt_server[40];
char mqtt_port[6] = "8080";
char strip_type[8] = "RGB";
char mqtt_ssl[3] = "no";
char mqtt_username[40] = "esp";
char mqtt_password[40] = "supersecurepassword";

char mainTopic[80] = "/ESPLED/";
char debugTopic[80];

//Fingerprint of odroid
const char* fingerprint = "A6 AE 85 65 63 DD D8 7C 70 F7 92 73 DE 8F 18 2B 9F DA 0A 76";

stripType type;

bool shouldSaveConfig = false;

const char* mqtt_device_id = "/rgbController/";

const LogLevel LOGLEVEL = VERBOSE;

WiFiManager wifiManager;

WiFiClient espClient;
WiFiClientSecure espClientSecure;

PubSubClient client;

StripControle* simpleStrip;
MicHandler* micHandler;

AnimationHandlerPWM* pwmHandler;
AnimationHandlerBus* busHandler;
//TODO: Adressable Strip

DHTesp dht;



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


    // Create a client ID
    String clientId = "RGB-Controller";

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
      //setup main Topic and debug topic path in mqtt
      strcat(mainTopic, WiFi.macAddress().c_str());
      strcat(debugTopic, mainTopic);
      strcat(debugTopic, "/debug");

      //Publish Info that Board Connected in /ESPLED/Topic
      //client.publish(mainTopic, strcat((char *) "espled-board connected -> ", WiFi.macAddress().c_str()));
      //delay(500);
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

void initWifi()
{
  WiFiManagerParameter custom_mqtt_server("server", "mqtt server", mqtt_server, 40);
  WiFiManagerParameter custom_mqtt_port("port", "mqtt port", mqtt_port, 6);
  WiFiManagerParameter custom_strip_type("strip_type", "strip type", strip_type, 8);
  WiFiManagerParameter custom_mqtt_ssl("ssl", "no", mqtt_ssl, 3);
  WiFiManagerParameter custom_mqtt_username("mqtt_username", "username", mqtt_username, 40);
  WiFiManagerParameter custom_mqtt_password("mqtt_password", "password", mqtt_password, 40);

  wifiManager.setSaveConfigCallback(saveConfigCallback);

  wifiManager.addParameter(&custom_mqtt_server);
  wifiManager.addParameter(&custom_mqtt_port);
  wifiManager.addParameter(&custom_strip_type);
  wifiManager.addParameter(&custom_mqtt_ssl);
  wifiManager.addParameter(&custom_mqtt_username);
  wifiManager.addParameter(&custom_mqtt_password);

  wifiManager.autoConnect("RGB Controller Setup");
  wifiManager.setConfigPortalTimeout(180);

  //After the WiFi Manger is done, we are most probably connected
  debugFkt("local ip", INFO);
  debugFkt(WiFi.localIP().toString(), INFO);


  strcpy(mqtt_server, custom_mqtt_server.getValue());
  strcpy(mqtt_port, custom_mqtt_port.getValue());
  strcpy(strip_type, custom_strip_type.getValue());
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
  dht.setup(pinSensor, DHTesp::DHT11); // Connect DHT sensor to GPIO 17
}

void initStrip(){
  if(strcmp(strip_type, "RGB") == 0) type = stripType::RGB_STRIP;
  else if(strcmp(strip_type, "RGBW") == 0) type = stripType::RGBW_STRIP;
  else if(strcmp(strip_type, "RGBWW") == 0) type = stripType::RGBWW_STRIP;
  else if(strcmp(strip_type, "WS2812") == 0) type = stripType::WS2812_STRIP;
  else if(strcmp(strip_type, "APA102") == 0) type = stripType::APA102_STRIP;

  Silo = new varSilo();
  micHandler = new MicHandler(Silo);

  if(type < 6){
    debugFkt("Animation handler, strip and Silo initialized", INFO);

    simpleStrip = new StripControle(type);
    pwmHandler = new AnimationHandlerPWM(simpleStrip, Silo, varSiloChanged, micHandler);
  }
  else{
    //TODO
    //busHandler = new AnimationHandlerBus()
  }
}

void runAnimationHandler(){
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
  debugFkt("IP address: " + WiFi.localIP().toString(), INFO);
  simpleStrip->showColor(CRGBWW{0,1023,0,1023,0});
  delay(500);
  simpleStrip->showColor(CRGBWW{0,0,0,0,0});
}

void handleReconnect(){
  if(!client.connected()) {
      initMQTT();
    }
}

unsigned int cycleCount = 0;
unsigned int freeHeap = 0;

void loop() {
  //cycleCount = ESP.getCycleCount();
  //OTA Handler
  ArduinoOTA.handle();

  //Run PWM Handler handle
  runAnimationHandler();

  //Run Microphone Handler handle
  micHandler->handleMic();

  //Reconnect MQTT if conenction is lost
  handleReconnect();

  //Handle MQTT routine
  client.loop();



  //Debug system resources
  if(!(millis() % 500)){
    debugFkt(
      "cycleCount: " + String(ESP.getCycleCount() - cycleCount) +
      " LoopTime: " + String((ESP.getCycleCount() - cycleCount) / 80000.0) + "ms" +
      " freeHeap: " + String(ESP.getFreeHeap() / 1000.0) + "kB"
    , VERBOSE);
    debugFkt(
      "Temperature: " + String(dht.getTemperature()) +  "°C"
      " Humidity: " + String(dht.getHumidity()) + "%"
    , VERBOSE);
  }
}
