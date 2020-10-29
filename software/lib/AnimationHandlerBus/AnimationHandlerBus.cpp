#include <AnimationHandlerBus.h>
#include <FastLED.h>

extern void debugFkt(String, LogLevel);

AnimationHandlerBus::AnimationHandlerBus(StripType *stripType, unsigned int stripLength, varSilo *silo, bool *varSiloChanged, MicHandler *micHandler)
    : AnimationHandler{silo, varSiloChanged, micHandler}
{

    //Allocate memory for CRGB led Buffer according to number of leds
    this->leds = (CRGB *)malloc(sizeof(CRGB) * stripLength);

    //set this Buffer to zero
    memset(this->leds, 0, stripLength * sizeof(CRGB));

    this->stripLength = stripLength;

    //Setup fastled lib with memory arrea and length
    //TODO setup template arguments
    switch(*stripType){
      case WS2812_STRIP:
        FastLED.addLeds<WS2812, pinData, GRB>(leds, stripLength);
        debugFkt("WS2812 Bus initialized", INFO);
        break;
      case APA102_STRIP:
        FastLED.addLeds<APA102, pinData, pinClock>(leds, stripLength);
        debugFkt("APA102 Bus initialized", INFO);
        break;
      default:
        debugFkt("Unknown stripType in AnimationHandlerBus or not implemented yet", ERROR);
        break;
    }
}

AnimationHandlerBus::~AnimationHandlerBus()
{
    //free the leds buffer memory
    free(this->leds);
}

void AnimationHandlerBus::handle()
{
    unsigned int now = millis();

    if (*varSiloChanged)
    {
        silo->lastChange = now;

        silo->oldColor = FastLedCRGB2CRGBWW(this->leds[0]);
        *varSiloChanged = false;
    }

    //values for new frame need to get calculated
    if (now > fpsTimer + UPDATE_TIME)
    {
        fpsTimer = now;

        if (silo->mode < 100)
        {
            //We are in a single color mode

            //Fill Complete Strip with color_Value calculated by getNewColor Function as
            //with not individually adressable Strips
            fill_solid(this->leds, this->stripLength, CRGBWW2FastLedCRGB(this->getNewColor()));
        }
        else
        {
            //Wa are in a mode for individually adressable strips
            this->getNewStripBuffer();
        }

        //Write Current this->leds Buffer to Strip
        FastLED.show();
    }
}

CRGB AnimationHandlerBus::CRGBWW2FastLedCRGB(CRGBWW CRGBWWColorObject)
{
    CRGB CRGBColorObject;
    CRGBColorObject.r = CRGBWWColorObject.R / 4;
    CRGBColorObject.g = CRGBWWColorObject.G / 4;
    CRGBColorObject.b = CRGBWWColorObject.B / 4;
    //Todo include CW WW values

    return CRGBColorObject;
}

CRGBWW AnimationHandlerBus::FastLedCRGB2CRGBWW(CRGB CRGBColorObject)
{
    CRGBWW CRGBWWColorObject;
    CRGBWWColorObject.R = CRGBColorObject.r * 4;
    CRGBWWColorObject.G = CRGBColorObject.g * 4;
    CRGBWWColorObject.B = CRGBColorObject.b * 4;
    //Todo include CW WW values

    return CRGBWWColorObject;
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

void AnimationHandlerBus::getNewStripBuffer()
{
    switch (silo->mode)
    {
    case WIPE://100
        this->wipe();
        break;
    case NOISE://101
        this->noise();
        break;
    case VU_METER:
        this->vuMeter();
        break;
    default:
        debugFkt("The Selected Mode is not implemented yet", ERROR);
        break;
    }
}
