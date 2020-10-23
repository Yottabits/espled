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
  CRGB CRGBWW2FastLedCRGB(CRGBWW CRGBWWColorObject);

private:
  CRGB *leds;
  int stripLength;
};
