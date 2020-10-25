#include <AnimationHandler.h>
#include <FastLED.h>

enum state {FLASH, OLD_COLOR, PERMANENT_ON};

CRGBWW AnimationHandler::industrialFlicker(){

    static state currentState;
    CRGBWW newColor;
    
  
   // handle reset of static vars through varSiloChanged
    if(millis() < silo->lastChange + UPDATE_TIME){
        //Reset static vars
        currentState = FLASH;

        //Validation of input vars
        if(silo->duration == 0 || silo->duration > UINT16_MAX) silo->duration = UINT16_MAX*(2/3);
    }

    switch (currentState){
    case FLASH:{
        newColor = silo->colorValue;
        uint16 rand = random16(0,1000);
        if(rand < 90){
            currentState = FLASH;
        }else{
            currentState = OLD_COLOR;
        }
        
        break;
    }
    case OLD_COLOR:{
        newColor = silo->oldColor;
        uint16 rand = random16(0,1000);
        if(rand > 50){
            currentState = OLD_COLOR;
        }else{
            rand = random16(0,UINT16_MAX);
            if (rand < silo->duration){
                currentState = FLASH;
            }else{
                currentState = PERMANENT_ON;
            }
        }        
        break;  
    }
    case PERMANENT_ON:{
        //end reached
        newColor = silo->colorValue;
        currentState = PERMANENT_ON;
        break;
    }
    default:{
        break;
    }
    }

    debugFkt("currentState: " + (String)currentState +
                        " R:"+ (String)newColor.R +
                        " G:"+ (String)newColor.G +
                        " B:"+ (String)newColor.B +
                        " CW:"+ (String)newColor.CW +
                        " WW:"+ (String)newColor.WW  ,DEBUG);
    return newColor;

}
