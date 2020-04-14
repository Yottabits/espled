
#ifndef Definitions_h
#define Definitions_h

#include <Arduino.h>
#include <Definitions.h>


class StripControle{
public:
  void showColor();
  void off();
  CRGBWW getColor();


private:
  enum {RGB = 3, RGBW, RGBWW};
  byte channelCount;
  CRGBWW channelValue;

  CRGBWW RGBW2RGB();
  CRGBWW RGBWW2RGBW();
  CRGBWW RGBWW2RGB();
};

#endif 
