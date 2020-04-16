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
//#include <pwm.c>
//--Includes--------------------------------------------------------------------




//init verSilo

//ToDo Fix typo
varSilo* Silo;

bool* varSiloChanged = new bool(false);



char mqtt_server[40];
char mqtt_port[6] = "8080";
char strip_type[8] = "RGB";
char mainTopic[80] = "/ESPLED/";

stripType type;

bool shouldSaveConfig = false;

const char* mqtt_device_id = "/rgbController/";


WiFiClient espClient;
WiFiManager wifiManager;
PubSubClient client(espClient);

StripControle* simpleStrip;
AnimationHandlerPWM* pwmHandler;
AnimationHandlerBus* busHandler;
//TODO: Adressable Strip

//callback notifying us of the need to save config
void saveConfigCallback () {
  Serial.println("Should save config");
  shouldSaveConfig = true;
}

//WARNING: If received json incomplete, increase MQTT_MAX_PACKET_SIZE in PubSunClient Library
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] with length ");
  Serial.print(length);
  for (unsigned int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }

  Serial.println();

  //use Stack
  StaticJsonDocument<1024> doc;
  //use Heap
  //DynamicJsonDocument doc(2048);

  deserializeJson(doc, payload, length);

  Silo->mode = doc["mode"];
  Silo->colorValue.R = doc["color"][0];
  Silo->colorValue.G = doc["color"][1];
  Silo->colorValue.B = doc["color"][2];
  Silo->colorValue.CW = doc["color"][3];
  Silo->colorValue.WW = doc["color"][4];
  Silo->time = doc["time"];
  Silo->frequency = doc["frequency"];
  Silo->sensitivity = doc["sensitivity"];
  Silo->length = doc["length"];
  Silo->position = doc["position"];

  Serial.println("Parsed Values");
  Serial.print("Mode:");
  Serial.println(Silo->mode);
  Serial.print("R:");
  Serial.println(Silo->colorValue.R);
  Serial.println(" G:");
  Serial.println(Silo->colorValue.G);
  Serial.println(" B:");
  Serial.println(Silo->colorValue.B);
  Serial.println(" CW:");
  Serial.println(Silo->colorValue.CW);
  Serial.println(" WW:");
  Serial.println(Silo->colorValue.WW);
  Serial.print("Time:");
  Serial.println(Silo->time);
  Serial.print("Freq:");
  Serial.println(Silo->frequency);
  Serial.print("sensitivity:");
  Serial.println(Silo->sensitivity);
  Serial.print("length:");
  Serial.println(Silo->length);
  Serial.print("position:");
  Serial.println(Silo->position);


  *varSiloChanged = true;
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
  WiFiManagerParameter custom_strip_type("strip_type", "strip type", strip_type, 8);

  wifiManager.setSaveConfigCallback(saveConfigCallback);

  wifiManager.addParameter(&custom_mqtt_server);
  wifiManager.addParameter(&custom_mqtt_port);
  wifiManager.addParameter(&custom_strip_type);

  wifiManager.autoConnect("RGB Controller Setup");
  wifiManager.setConfigPortalTimeout(180);

  //After the WiFi Manger is done, we are most probably connected
  Serial.println("local ip");
  Serial.println(WiFi.localIP());


  strcpy(mqtt_server, custom_mqtt_server.getValue());
  strcpy(mqtt_port, custom_mqtt_port.getValue());
  strcpy(strip_type, custom_strip_type.getValue());

  //save the custom parameters to FS
  if (shouldSaveConfig) {
    Serial.println("saving config");

    DynamicJsonDocument doc(4000);
    JsonObject json = doc.to<JsonObject>();

    json["mqtt_server"] = mqtt_server;
    json["mqtt_port"] = mqtt_port;
    json["strip_type"] = strip_type;

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
          strcpy(strip_type, json["strip_type"]);

        } else {
          Serial.println("failed to load json config");
        }
        configFile.close();
      }
    }
  } else {
    Serial.println("failed to mount FS");
  }
  Serial.println("Finished spiffs shit");
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
  if(strcmp(strip_type, "RGB") == 0) type = stripType::RGB;
  else if(strcmp(strip_type, "RGBW") == 0) type = stripType::RGBW;
  else if(strcmp(strip_type, "RGBWW") == 0) type = stripType::RGBWW;
  else if(strcmp(strip_type, "WS2812") == 0) type = stripType::WS2812;
  else if(strcmp(strip_type, "APA102") == 0) type = stripType::APA102;

  if(type < 6){
    Serial.print("Annimation handler, strip and Silo initilized");
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

void debugFkt(String message){
  //TODO define level enums
  client.publish(strcat(mainTopic, "/debug"), message.c_str());
  Serial.print(message);
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
  initStrip();

  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  simpleStrip->showColor(CRGBWW{0,1023,0,0,0});
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
