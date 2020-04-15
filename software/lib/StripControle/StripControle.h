
#ifndef Definitions_h
#define Definitions_h

#include <Arduino.h>
#include <TypeDefinitions.h>
#include <PinDefinitions.h>


class StripControle{
public:

  StripControle(stripType type);
  void showColor(CRGBWW);
  void off();
  CRGBWW getColor();

private:

  stripType type;
  CRGBWW channelValue;

  CRGBWW RGBW2RGB();
  CRGBWW RGBWW2RGBW();
  CRGBWW RGBWW2RGB();

  void recalculateColor();
  void setChannels();
};


#endif
