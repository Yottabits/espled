#include <AnimationHandlerBus.h>
#include <MicHandler.h>
#include <FastLED.h>


void AnimationHandlerBus::vuMeter()
{
    unsigned int now = millis();
    static unsigned int maxLedDownTimer = 0;
    static unsigned int maxAmplitudeLed = 0;
    static unsigned int fourierTimer = 0;

    unsigned int numberOfLedsToTurnOn = (micHandler->getAverageAmplitude() * (1 + (silo->sensitivity * 0.09))) * this->stripLength;
    if(numberOfLedsToTurnOn > this->stripLength)
      numberOfLedsToTurnOn = this->stripLength;

    if(numberOfLedsToTurnOn > maxAmplitudeLed)
      maxAmplitudeLed = numberOfLedsToTurnOn;

    CRGB color = CRGBWW2FastLedCRGB(silo->colorValue);

    for(unsigned int i = 0; i<numberOfLedsToTurnOn; i++){
      this->leds[i] = color;
    }
    for(unsigned int i = numberOfLedsToTurnOn; i < this->stripLength; i++){
      this->leds[i] = CRGB::Black;
    }

    this->leds[maxAmplitudeLed] = CRGB::Red;

    if(now - maxLedDownTimer > 50){
      maxLedDownTimer = now;
      maxAmplitudeLed--;
    }
    if(now - fourierTimer > 3000){
      fourierTimer = now;
      // String rawFloats;
      // for(int i = 0; i < ringBufferSize; i++){
      //   rawFloats += String(micHandler->audioRingBuffer[i]) + ", ";
      // }
      //debugFkt(rawFloats, DEBUG);
      micHandler->calculateFFT();
      micHandler->printVector();
    }


}
