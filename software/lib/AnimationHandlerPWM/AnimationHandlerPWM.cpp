#include "AnimationHandlerPWM.h"

AnimationHandlerPWM::AnimationHandlerPWM(StripControle* strip, varSilo* silo){
    this->strip = strip;
    this->silo = silo;
}


void AnimationHandlerPWM::handle(){
    //Switch Case that calls the apropriate Function for Handeling the currently selected Mode
    //All Modes are Implemented as one Function in the folder Modes
    
    //Serial.println(silo->mode);
    //Serial.println(silo->colorValue.R);
    
    switch (silo->mode){
        case FADE_2_COLOR:
            fade2Color(strip, silo->colorValue, silo->time);
            break;
        case BLINK_COLOR:
            blinkColor(strip, silo->colorValue, silo->time);
            break;
        case STROBE:
            strobe(strip);
            break;
        case SOUND_2_LIGHT:
            sound2Light(strip);
            break;
        default:
            Serial.print("The Selected Mode is not possible with RGB/RGBW/RGBWW Strips");
            break;
    }
    
}
