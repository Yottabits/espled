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

    CRGB color = CRGBWW2FastLedCRGB(silo->colorValue);

    if(numberOfLedsToTurnOn > maxAmplitudeLed)
      maxAmplitudeLed = numberOfLedsToTurnOn;

    switch(silo->position){
      case 0:
        for(unsigned int i = numberOfLedsToTurnOn; i < this->stripLength; i++){
          this->leds[i] = CRGB::Black;
        }
        for(unsigned int i = 0; i<numberOfLedsToTurnOn; i++){
          this->leds[i] = color;
        }
        this->leds[maxAmplitudeLed] = CRGB::Red;
        break;

      case 1:
        numberOfLedsToTurnOn /= 2;
        for(unsigned int i = 0; i < this->stripLength-numberOfLedsToTurnOn; i++){
          this->leds[i] = CRGB::Black;
          this->leds[this->stripLength-i] = CRGB::Black;
        }
        for(unsigned int i = 0; i<numberOfLedsToTurnOn; i++){
          this->leds[(this->stripLength/2)+i] = color;
          this->leds[(this->stripLength/2)-i] = color;
        }
        this->leds[(this->stripLength/2)+maxAmplitudeLed/2] = CRGB::Red;
        this->leds[(this->stripLength/2)-maxAmplitudeLed/2] = CRGB::Red;
        break;

      case 2:
        for(unsigned int i = 0; i < this->stripLength-numberOfLedsToTurnOn; i++){
          this->leds[i] = CRGB::Black;
        }
        for(unsigned int i = this->stripLength; i>this->stripLength-numberOfLedsToTurnOn; i--){
          this->leds[i] = color;
        }
        this->leds[this->stripLength-maxAmplitudeLed] = CRGB::Red;
        break;
    }


    if(now - maxLedDownTimer > 50){
      maxLedDownTimer = now;
      maxAmplitudeLed--;
    }
    if(now - fourierTimer > 500){
      fourierTimer = now;
      //micHandler->calculateFFT();
      //micHandler->printVector();
      //color = CRGB((int)(micHandler->getPeakFrequency()/2.0),0,0);
    }


}
