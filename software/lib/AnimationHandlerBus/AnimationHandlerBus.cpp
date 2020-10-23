#include <AnimationHandlerBus.h>
#include <FastLED.h>

extern void debugFkt(String, LogLevel);

AnimationHandlerBus::AnimationHandlerBus(int stripLength, varSilo *silo, bool *varSiloChanged, MicHandler *micHandler)
    : AnimationHandler{silo, varSiloChanged, micHandler}
{

    //Allocate memory for CRGB led according to number of leds
    this->leds = (CRGB *)malloc(sizeof(CRGB) * stripLength);
    this->stripLength = stripLength;

    //Setup fastled lib with memory arrea and length
    //TODO setup template arguments
    FastLED.addLeds<WS2812, 2>(leds, stripLength);
}

AnimationHandlerBus::~AnimationHandlerBus()
{
    //free the leds buffer memory
    free(this->leds);
}

void AnimationHandlerBus::handle()
{
    debugFkt("Bus Handler called", INFO);
    if (silo->mode < 100)
    {
        //We are in a single color mode 

        //test
        fill_solid(this->leds[0],this->stripLength,CRGBWW2FastLedCRGB(silo->colorValue));
    }else
    {
        //Wa are in a mode for adressable strips
        //Todo Switch Case that runs functions that work directly on the memory block
        switch (silo->mode)
        {
        case WIPE:
            //fill_solid()
            break;
        
        default:
            break;
        }
    }
    FastLED.show(); 
    
}

CRGB AnimationHandlerBus::CRGBWW2FastLedCRGB(CRGBWW CRGBWWColorObject){
    CRGB CRGBColorObject;
    CRGBColorObject.r = CRGBWWColorObject.R/4;
    CRGBColorObject.g = CRGBWWColorObject.G/4;
    CRGBColorObject.b = CRGBWWColorObject.B/4;
    return CRGBColorObject;
}

CRGBWW AnimationHandlerBus::getNewColor()
{
    switch (silo->mode)
    {
    case FADE_2_COLOR:
        return fade2Color();
        break;
    case BLINK_COLOR:
        return blinkColor();
        break;
    case STROBE:
        return strobe();
        break;
    case SOUND_2_LIGHT:
        return sound2Light();
        break;
    case BREATHE:
        return breathe();
        break;
    case INDUSTRIAL_FLICKER:
        return industrialFlicker();
        break;
    default:
        debugFkt("The Selected Mode is not a uniform color mode (single color strip mode)", ERROR);
        return CRGBWW{0, 0, 0, 0, 0};
        break;
    }
}