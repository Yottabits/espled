
#ifndef Definitions_h
#define Definitions_h

#include <Arduino.h>
#include <TypeDefinitions.h>
#include <PinDefinitions.h>


class StripControle{
public:
  void showColor(CRGBWW);
  void off();
  CRGBWW getColor();


private:
  enum {RGB = 3, RGBW, RGBWW};
  byte stripType;
  CRGBWW channelValue;

  CRGBWW RGBW2RGB();
  CRGBWW RGBWW2RGBW();
  CRGBWW RGBWW2RGB();

  void recalculateColor();
  void setChannels();
};


#endif
