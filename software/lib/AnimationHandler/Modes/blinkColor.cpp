#include <AnimationHandler.h>

enum state {FADE_TO_MAX, MAX_WAIT, FADE_TO_MIN, WAIT_MIN, FINAL_STATE};

CRGBWW AnimationHandler::blinkColor(){
    
    debugFkt("Current mode"+(String)silo->mode+" old mode"+(String) silo->oldVarSilo->mode,DEBUG);
    
    
    static uint currentBlinkCycle = 0;
    static long stateTimer = 0;
    static state currentState = FADE_TO_MAX;
    CRGBWW newColor;

    // handle reset of static vars through varSiloChanged
    if(millis() < silo->lastChange + UPDATE_TIME){
        //Reset static vars
        currentBlinkCycle = 0;
        stateTimer = millis();
        currentState = FADE_TO_MAX;
    }

    debugFkt("currentState"+(String)currentState,DEBUG);

    switch (currentState){
    case FADE_TO_MAX:{
        long now = millis();

        bool fadeEndReached = (now > (stateTimer + this->silo->time));

        if(!fadeEndReached){
            float difR, difG, difB, difCW, difWW;
            difR = (int)(silo->colorValue.R - silo->oldColor.R);
            difG = (int)(silo->colorValue.G - silo->oldColor.G);
            difB = (int)(silo->colorValue.B - silo->oldColor.B);
            difCW = (int)(silo->colorValue.CW - silo->oldColor.CW) ;
            difWW = (int)(silo->colorValue.WW - silo->oldColor.WW);

            //Calculate new Color Values
            newColor.R = silo->oldColor.R+(now-silo->lastChange)*(difR/silo->time);
            newColor.G = silo->oldColor.G+(now-silo->lastChange)*(difG/silo->time);
            newColor.B = silo->oldColor.B+(now-silo->lastChange)*(difB/silo->time);
            newColor.CW = silo->oldColor.CW+(now-silo->lastChange)*(difCW/silo->time);
            newColor.WW = silo->oldColor.WW+(now-silo->lastChange)*(difWW/silo->time);
        }else{
            //end reached
            currentState = MAX_WAIT;
            stateTimer = millis();
        }
        break;
    }
    case MAX_WAIT:{
    newColor = silo->colorValue;
        if(millis() > stateTimer + silo->duration){
            currentState = FADE_TO_MIN;
            stateTimer = millis();
        }
        break;
    }
    case FADE_TO_MIN:{
        long now = millis();

        bool fadeEndReached = now > (stateTimer + this->silo->time);
        

        if(!fadeEndReached){
            float difR, difG, difB, difCW, difWW;
            difR = 0 - silo->colorValue.R;
            difG = 0 - silo->colorValue.G;
            difB = 0 - silo->colorValue.B;
            difCW = 0 - silo->colorValue.CW;
            difWW = 0 - silo->colorValue.WW;

            //Calculate new Color Values
            newColor.R = silo->colorValue.R+(now-silo->lastChange)*(difR/silo->time);
            newColor.G = silo->colorValue.G+(now-silo->lastChange)*(difG/silo->time);
            newColor.B = silo->colorValue.B+(now-silo->lastChange)*(difB/silo->time);
            newColor.CW = silo->colorValue.CW+(now-silo->lastChange)*(difCW/silo->time);
            newColor.WW = silo->colorValue.WW+(now-silo->lastChange)*(difWW/silo->time);
        }else{
            //end reached
            currentState = WAIT_MIN;
            stateTimer = millis();
        }
        break;
    }
    case WAIT_MIN:{
        newColor = {0,0,0,0,0};
        if(millis() > stateTimer + silo->duration){
            stateTimer = millis();
            if(currentBlinkCycle >= silo->length){
                currentState = FINAL_STATE;
            }else{
                currentState = FADE_TO_MAX;
                currentBlinkCycle++;
            }
        }
        break;
    }
    case FINAL_STATE:{
        float multiplier = (millis()-stateTimer)/silo->time;

        //THE SILOSWAPP XO
        varSilo *tempPointer;
        tempPointer = silo;
        silo = silo->oldVarSilo;
        
        //TODO move this function to annimation handler superclass
        newColor = this->getNewColor();

        silo = tempPointer;

        newColor.R *= multiplier;
        newColor.G *= multiplier;
        newColor.B *= multiplier;
        newColor.CW *= multiplier;
        newColor.WW *= multiplier;

        if(millis() > stateTimer + silo->time){
            // make a deep copy
            *silo = *(silo->oldVarSilo);
        }
        break;
    }
    default:{
        break;
    }
    }

    return newColor;

}
