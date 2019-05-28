#include <Arduino.h>

typedef struct {
  unsigned int R, G, B, CW, WW;
} CRGBWW;

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
