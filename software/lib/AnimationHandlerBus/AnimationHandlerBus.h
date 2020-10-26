#include <TypeDefinitions.h>
#include <PinDefinitions.h>

#include <AnimationHandler.h>
#include <FastLED.h>

class AnimationHandlerBus : AnimationHandler
{
public:
  AnimationHandlerBus(StripType *stripType,
                      unsigned int stripLength,
                      varSilo *silo,
                      bool *varSiloChanged,
                      MicHandler *micHandler);

  ~AnimationHandlerBus();

  void handle();

  CRGBWW getNewColor();
  void getNewStripBuffer();

  //Helpers
  CRGB CRGBWW2FastLedCRGB(CRGBWW CRGBWWColorObject);
  CRGBWW FastLedCRGB2CRGBWW(CRGB CRGBColorObject);

  //Aderssable Modes
  void wipe();
  void fire();
  void vuMeter();
  void noise();

private:
  CRGB *leds; //buffer on Heap for Adressable Strips
  unsigned int stripLength;
};
