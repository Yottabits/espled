#include "AnimationHandlerPWM.h"


extern void debugFkt(String, LogLevel);

AnimationHandlerPWM::AnimationHandlerPWM(StripControle* strip, varSilo* silo, bool* varSiloChanged){
    this->strip = strip;
    this->silo = silo;
    this->varSiloChanged = varSiloChanged;
}


void AnimationHandlerPWM::handle(){
    //Switch Case that calls the apropriate Function for Handeling the currently selected Mode
    //All Modes are Implemented as one Function in the folder Modes

    //Serial.print("Silo->time");
    //Serial.println(silo->time);


    static long lastChange = 0;
    static CRGBWW oldColor{0,0,0,0,0};

    if(*varSiloChanged){
        lastChange = millis();
        oldColor = strip->getColor();
        *varSiloChanged = false;
    }


    switch (silo->mode){
        case FADE_2_COLOR:
            fade2Color(strip, silo->colorValue, silo->time, lastChange, oldColor);
            break;
        case BLINK_COLOR:
            blinkColor(strip, silo->colorValue, silo->time, lastChange, oldColor);
            break;
        case STROBE:
            strobe(strip);
            break;
        case SOUND_2_LIGHT:
            sound2Light(strip);
            break;
        case BREATHE:
            breathe(
              strip,
              silo->colorValue,
              silo->time,
              silo->minBrightnes,
              silo->maxBrightnes,
              silo->timeVariance,
              silo->maxBrightnesVariance
            );
            break;
        default:
            debugFkt("The Selected Mode is not possible with RGB/RGBW/RGBWW Strips",ERROR);
            break;
    }

    //set varSiloChanged back to False
}
;
