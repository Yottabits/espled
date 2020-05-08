#include <AnimationHandler.h>

enum state {FADE_TO_MAX, MAX_WAIT, FADE_TO_MIN, WAIT_MIN, FINAL_STATE};

CRGBWW AnimationHandler::blinkColor(){

    //debugFkt("Current mode"+(String)silo->mode+" old mode"+(String) silo->oldVarSilo->mode,DEBUG);


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
            newColor.R = silo->oldColor.R+(now-stateTimer)*(difR/silo->time);
            newColor.G = silo->oldColor.G+(now-stateTimer)*(difG/silo->time);
            newColor.B = silo->oldColor.B+(now-stateTimer)*(difB/silo->time);
            newColor.CW = silo->oldColor.CW+(now-stateTimer)*(difCW/silo->time);
            newColor.WW = silo->oldColor.WW+(now-stateTimer)*(difWW/silo->time);
        }else{
            //end reached
            newColor = silo->colorValue;
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
            difR = -silo->colorValue.R;
            difG = -silo->colorValue.G;
            difB = -silo->colorValue.B;
            difCW = -silo->colorValue.CW;
            difWW = -silo->colorValue.WW;

            //Calculate new Color Values
            newColor.R = silo->colorValue.R+(now-stateTimer)*(difR/silo->time);
            newColor.G = silo->colorValue.G+(now-stateTimer)*(difG/silo->time);
            newColor.B = silo->colorValue.B+(now-stateTimer)*(difB/silo->time);
            newColor.CW = silo->colorValue.CW+(now-stateTimer)*(difCW/silo->time);
            newColor.WW = silo->colorValue.WW+(now-stateTimer)*(difWW/silo->time);
        }else{
            //end reached
            newColor = CRGBWW{0,0,0,0,0};
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
    debugFkt("currentState: " + (String)currentState + ", cycle: " + (String)currentBlinkCycle + ", newColor: " + (String)newColor.R + "|"+ (String)newColor.G + "|"+ (String)newColor.B + "|",DEBUG);
    return newColor;

}
