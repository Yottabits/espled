#include "modes.h"
#include <FastLED.h>

extern void debugFkt(String, LogLevel);

void breathe(StripControle* strip) {
  static unsigned int timer = 0;
  if(millis() > timer + 16){
    timer = millis();
    int rawSin = sin16(millis()*5);
    unsigned int mappedSin = map(rawSin,-32768,32767,0,1023);
    debugFkt(String(mappedSin), DEBUG);
    strip->showColor(CRGBWW{0,0,0,mappedSin,0});
  }

}
