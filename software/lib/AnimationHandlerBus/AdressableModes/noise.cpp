#include <AnimationHandlerBus.h>
#include <FastLED.h>

void AnimationHandlerBus::noise()
{
    debugFkt("Current mode" + (String)silo->mode, DEBUG);

    if (this->silo->frequency == 0 || this->silo->frequency > 60)
    {
        debugFkt("Frequency was set to 0 or over 60 this is not possible", ERROR);
        return;
    }

    unsigned long now = millis();
    static unsigned long lastStateChange = 0;
    long period = (1000 / this->silo->frequency);

    if (now >= lastStateChange + period)
    {
        lastStateChange = now;

        CRGB Color = CRGBWW2FastLedCRGB(silo->colorValue);

        for (int i = 0; i <= this->stripLength; i++)
        {
            if(random16(0,1000)>500){
                //set Led to Color
                this->leds[i].setRGB(Color);
            }else{
                //turn led off
                this->leds[i].setRGB(0,0,0);
            }
            
        }
    }

    //update timing variables
    unsigned long now = millis();
    bool wipeEndReached = now > (silo->lastChange + this->silo->time);

    //init static variables
    static unsigned long timePerLed = 0;
    static unsigned long lastBufferChange = 0;
    static unsigned int nextLed = 0;

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
        lastBufferChange = 0;
        nextLed = 0;

        //Validation of input vars
    }

    if (!wipeEndReached)
    {
        bool changeNextLed = lastBufferChange + now > timePerLed;
        if (changeNextLed)
        {
            this->leds[nextLed].setRGB(silo->colorValue.R, silo->colorValue.G, silo->colorValue.B);
            lastBufferChange = millis();
            nextLed++;
        }

        //set oldColor if strip is stored
        if (nextLed == this->stripLength)
        {
            this->silo->oldColor = this->silo->colorValue;
        }
    }
    else
    {
        //strip is already final nothing to do
    }
}