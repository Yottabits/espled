#ifndef STRIPCONTROLE_h
#define STRIPCONTROLE_h

#include <Arduino.h>
#include <TypeDefinitions.h>
#include <PinDefinitions.h>


class StripControle{
public:

  StripControle(StripType type);
  void showColor(CRGBWW);
  void off();
  CRGBWW getColor();

private:

  StripType type;
  CRGBWW channelValue;

  CRGBWW RGBW2RGB();
  CRGBWW RGBWW2RGBW();
  CRGBWW RGBWW2RGB();

  void recalculateColor();
  void setChannels();
};


#endif
