#include <AnimationHandler.h>

enum state {FLASH, OLD_COLOR, FADE_ON, FADE_OFF, DARK, PERMANENT_ON, FLICKER_ON};

CRGBWW AnimationHandler::industrialFlicker(){

    //debugFkt("Current mode"+(String)silo->mode+" old mode"+(String) silo->oldVarSilo->mode,DEBUG);

    static long stateTimer = 0;
    static state currentState;
    CRGBWW newColor;
    
    // handle reset of static vars through varSiloChanged
    if(millis() < silo->lastChange + UPDATE_TIME){
        //Reset static vars
        stateTimer = millis();

        //add randomness or control
        currentState = FLASH;

        //Validation of input vars
        if(silo->time == 0) silo->time = 1000;
        if(silo->duration == 0) silo->duration = 1000;
    }


    switch (currentState){
    case FLASH:{
        newColor = silo->colorValue;
        currentState = OLD_COLOR;
        break;
    }
    case OLD_COLOR:{
        //end reached
        newColor = silo->oldColor;
        
        currentState = PERMANENT_ON;
        break;  
    }
    case FADE_ON:{
        break;
    }
    case FADE_OFF:{
        break;
    }
    case DARK:{
        newColor = CRGBWW{0,0,0,0,0};
        currentState = FLASH;
        stateTimer = millis();
        break;
    }
    case PERMANENT_ON:{
        //end reached
        newColor = silo->colorValue;
        silo->oldColor = newColor;
        currentState = PERMANENT_ON;
        break;
    }
    case FLICKER_ON:{
        newColor = {0,0,0,0,0};
        break;
    }
    default:{
        break;
    }
    }

    debugFkt("currentState: " + (String)currentState +" R:"+ (String)newColor.R ,DEBUG);
    return newColor;

}
