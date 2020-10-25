#include <TypeDefinitions.h>
#include <PinDefinitions.h>

#include <AnimationHandler.h>
#include <FastLED.h>

class AnimationHandlerBus : AnimationHandler
{
public:
  AnimationHandlerBus(int stripLength, varSilo *silo, bool *varSiloChanged, MicHandler *micHandler);
  ~AnimationHandlerBus();

  void handle();

  CRGBWW getNewColor();
  void getNewStripBuffer();
  
  //Helpers
  CRGB CRGBWW2FastLedCRGB(CRGBWW CRGBWWColorObject);

  //Aderssable Modes
  void wipe();
  void fire();
  void vuMeter();

private:
  CRGB *leds; //buffer on Heap for Adressable Strips
  int stripLength;
};
