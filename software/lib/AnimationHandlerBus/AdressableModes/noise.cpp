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
}