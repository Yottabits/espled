//--Includes--------------------------------------------------------------------
#include <initFunctions.h>
//--Includes--------------------------------------------------------------------


void debugFkt(String message, LogLevel LevelOfMessage){
  // Function which handles the debugging
  // Prints messages depending on log_level to MQTT and Serial

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
      if(client.connected())
        client.publish(debugTopic, message.c_str());
      Serial.println(message);
    //}

  }
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

  dht.setup(pinSensor, DHTesp::DHT11);

  firmmareReset();
  Serial.begin(115200);
  delay(50);
  debugFkt("Booting", INFO);

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

void handleSensor(){
  if(!(millis() % 10000)){
    debugFkt("Transmit temperature at " + (String(mainTopic) + String("/temperature")), VERBOSE);
    client.publish((String(mainTopic) + String("/temperature")).c_str(), String(dht.getTemperature()).c_str());
    client.publish((String(mainTopic) + String("/humidity")).c_str(), String(dht.getHumidity()).c_str());
}
}



void loop() {
  unsigned int cycleCount = 0;
  unsigned int freeHeap = 0;
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

  //Transmit sensor data
  handleSensor();

  //Debug system resources
  if(!(millis() % 500)){

    debugFkt(
      "cycleCount: " + String(ESP.getCycleCount() - cycleCount) +
      " LoopTime: " + String((ESP.getCycleCount() - cycleCount) / 80000.0) + "ms" +
      " freeHeap: " + String(ESP.getFreeHeap() / 1000.0) + "kB"
    , VERBOSE);
  }
}
