#include <AnimationHandler.h>

enum state {FADE_TO_MAX, MAX_WAIT, FADE_TO_MIN, WAIT_MIN, FINAL_STATE};

CRGBWW AnimationHandler::blinkColor(){

    //debugFkt("Current mode"+(String)silo->mode+" old mode"+(String) silo->oldVarSilo->mode,DEBUG);


    static uint currentBlinkCycle = 0;
    static long stateTimer = 0;
    static state currentState = FADE_TO_MAX;
    CRGBWW newColor;
    float multiplier;

    // handle reset of static vars through varSiloChanged
    if(millis() < silo->lastChange + UPDATE_TIME){
        //Reset static vars
        currentBlinkCycle = 0;
        stateTimer = millis();
        currentState = FADE_TO_MAX;

        //Validation of input vars
        if(silo->time == 0) silo->time = 1000;
        if(silo->duration == 0) silo->duration = 1000;
    }


    switch (currentState){
    case FADE_TO_MAX:{
        long now = millis();

        bool fadeEndReached = (now > (stateTimer + this->silo->time));

        if(!fadeEndReached){
            float difR, difG, difB, difCW, difWW;
            //Underflow of uint -> casting to signed int neccessary for negative dif
            difR = (int)(silo->colorValue.R - silo->oldColor.R);
            difG = (int)(silo->colorValue.G - silo->oldColor.G);
            difB = (int)(silo->colorValue.B - silo->oldColor.B);
            difCW = (int)(silo->colorValue.CW - silo->oldColor.CW);
            difWW = (int)(silo->colorValue.WW - silo->oldColor.WW);

            //Calculate new Color Values
            newColor.R = silo->oldColor.R+(now-stateTimer)*(difR/silo->time);
            newColor.G = silo->oldColor.G+(now-stateTimer)*(difG/silo->time);
            newColor.B = silo->oldColor.B+(now-stateTimer)*(difB/silo->time);
            newColor.CW = silo->oldColor.CW+(now-stateTimer)*(difCW/silo->time);
            newColor.WW = silo->oldColor.WW+(now-stateTimer)*(difWW/silo->time);

            //debugFkt("currentState: " + (String)currentState + ", cycle: " + (String)currentBlinkCycle + ", difR: " + (String)difR + ", difG: " + (String)difG + ", difB: " + (String)difB + ", newColor: " + (String)newColor.R + "|"+ (String)newColor.G + "|"+ (String)newColor.B + "|",DEBUG);
        }else{
            //end reached
            newColor = silo->colorValue;
            currentState = MAX_WAIT;
            stateTimer = millis();

            silo->oldColor = CRGBWW{0,0,0,0,0};
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

        //Do not fade to zero when blinking once
        if(silo->length <= 1) {
          currentState = FINAL_STATE;
          stateTimer = millis();
          newColor = silo->colorValue;
          break;
        }

        if(!fadeEndReached){
            float difR, difG, difB, difCW, difWW;
            difR = -1.0 * silo->colorValue.R;
            difG = -1.0 * silo->colorValue.G;
            difB = -1.0 * silo->colorValue.B;
            difCW = -1.0 * silo->colorValue.CW;
            difWW = -1.0 * silo->colorValue.WW;

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
            currentBlinkCycle++;
            if(currentBlinkCycle >= silo->length){
                currentState = FINAL_STATE;
            }else{
                currentState = FADE_TO_MAX;

            }
        }
        break;
    }
    case FINAL_STATE:{
        multiplier = float(millis()-stateTimer)/(float)silo->time;

        //THE SILOSWAPP XO
        varSilo *tempPointer;
        tempPointer = silo;
        silo = silo->oldVarSilo;

        //TODO move this function to annimation handler superclass
        CRGBWW returnColor = this->getNewColor();

        silo = tempPointer;


        long now = millis();

        if(silo->length <= 1){
            float difR, difG, difB, difCW, difWW;
            //Underflow of uint -> casting to signed int neccessary for negative dif
            difR = (int)(returnColor.R - silo->colorValue.R);
            difG = (int)(returnColor.G - silo->colorValue.G);
            difB = (int)(returnColor.B - silo->colorValue.B);
            difCW = (int)(returnColor.CW - silo->colorValue.CW);
            difWW = (int)(returnColor.WW - silo->colorValue.WW);

            //Calculate new Color Values
            newColor.R = silo->colorValue.R+(int)(now-stateTimer)*(difR/silo->time);
            newColor.G = silo->colorValue.G+(int)(now-stateTimer)*(difG/silo->time);
            newColor.B = silo->colorValue.B+(int)(now-stateTimer)*(difB/silo->time);
            newColor.CW = silo->colorValue.CW+(int)(now-stateTimer)*(difCW/silo->time);
            newColor.WW = silo->colorValue.WW+(int)(now-stateTimer)*(difWW/silo->time);
          }
          else{
            newColor.R = returnColor.R * multiplier;
            newColor.G = returnColor.G * multiplier;
            newColor.B = returnColor.B * multiplier;
            newColor.CW = returnColor.CW * multiplier;
            newColor.WW = returnColor.WW * multiplier;
          }



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
