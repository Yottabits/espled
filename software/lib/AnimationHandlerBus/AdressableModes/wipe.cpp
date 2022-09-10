#include <AnimationHandlerBus.h>

void AnimationHandlerBus::wipe()
{
    //debugFkt("Current mode" + (String)silo->mode, DEBUG);

    //update timing variables
    unsigned long now = millis();
    bool wipeEndReached = now > (silo->lastChange + this->silo->time + UPDATE_TIME);
    static CRGB Color = CRGB::Black;

    //init static variables
    static unsigned long timePerLed = 0;
    
    // Catch possible undefined Configurations
    if (this->stripLength < 0)
    {
        debugFkt("Negative Strip Length but used WipeMode", ERROR);
        return;
    }

    // handle reset of static vars through varSiloChanged
    if (millis() < silo->lastChange + UPDATE_TIME)
    {
        //Reset static vars
        timePerLed = this->silo->time / this->stripLength;
        if(timePerLed < 1) timePerLed = 1;

        Color = CRGBWW2FastLedCRGB(silo->colorValue);
    }

    if (!wipeEndReached)
    {
        unsigned int numberOfLedsToTurnOn = (now - silo->lastChange) / timePerLed;
        if(numberOfLedsToTurnOn > this->stripLength) numberOfLedsToTurnOn = this->stripLength;

        
        for(unsigned int i=0; i <= numberOfLedsToTurnOn; i++ ){
            this->leds[i] = Color;
        }
    }
    else
    {
        for(unsigned int i=0; i <= this->stripLength; i++ ){
            this->leds[i] = Color;
        }
    }
}