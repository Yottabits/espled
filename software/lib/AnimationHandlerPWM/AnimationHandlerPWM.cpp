#include <AnimationHandlerPWM.h>

extern void debugFkt(String, LogLevel);

AnimationHandlerPWM::AnimationHandlerPWM(StripControle *strip, varSilo *silo, bool *varSiloChanged, MicHandler *micHandler)
    : AnimationHandler{silo, varSiloChanged, micHandler}
{
    this->strip = strip;
}

void AnimationHandlerPWM::handle()
{
    //Switch Case that calls the apropriate Function for Handeling the currently selected Mode
    //All Modes are Implemented as one Function in the folder Modes

    unsigned int now = millis();

    if (*varSiloChanged)
    {
        silo->lastChange = now;
        silo->oldColor = strip->getColor();
        *varSiloChanged = false;
    }

    //values for new frame need to get calculated
    if (now > fpsTimer + UPDATE_TIME)
    {
        fpsTimer = now;

        // Switch based on mode parameter in var Silo
        // Calculate new color (done by mode-functions)
        // And write them to strip

        //TODO move this function to annimation handler superclass
        strip->showColor(getNewColor());
    }
}

//TODO move this function to annimation handler superclass
CRGBWW AnimationHandlerPWM::getNewColor()
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
        debugFkt("The Selected Mode is not possible with RGB/RGBW/RGBWW Strips", ERROR);
        return CRGBWW{0,0,0,0,0};
        break;
    }
}