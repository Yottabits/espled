#include <AnimationHandlerBus.h>
#include <MicHandler.h>
#include <FastLED.h>


void AnimationHandlerBus::vuMeter()
{
    unsigned int now = millis();
    static unsigned int lastStateChange = 0;

    if(now - lastStateChange > 1000){
      lastStateChange = now;
      micHandler->calculateFFT();
      micHandler->printVector();
    }
}
