#include <AnimationHandlerBus.h>

void AnimationHandlerBus::wipe()
{
    debugFkt("Current mode" + (String)silo->mode, DEBUG);

    //update timing variables
    unsigned long now = millis();
    bool wipeEndReached = now > (silo->lastChange + this->silo->time);

    //init static variables
    static unsigned long timePerLed = 0;
    static unsigned long lastBufferChange = 0;
    static unsigned int nextLed = 0;

    // Catch possible undefined Configurations
    if(this->stripLength < 0){
        debugFkt("Negative Strip Length but used WipeMode",ERROR);
        return;
    }

    // handle reset of static vars through varSiloChanged
    if(millis() < silo->lastChange + UPDATE_TIME){
        //Reset static vars
        timePerLed = this->silo->time / this->stripLength;
        lastBufferChange = 0;
        nextLed = 0;

        //Validation of input vars

    }

if (!wipeEndReached)
    {       
        bool changeNextLed = lastBufferChange + now > timePerLed;
        if(changeNextLed){
            //Todo do this with conversion function
            this->leds[nextLed].setRGB(silo->colorValue.R/4,silo->colorValue.G/4,silo->colorValue.B/4);
            lastBufferChange = millis();
            nextLed++;
        }

        //set oldColor if strip is stored
        if(nextLed == this->stripLength){
            this->silo->oldColor = this->silo->colorValue;
        }
    }
    else
    {
        //strip is already final nothing to do
    }
}