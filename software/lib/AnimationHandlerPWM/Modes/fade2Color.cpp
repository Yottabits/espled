#include "modes.h"
//set update frequency/time
const uint UPDATE_TIME = 100;


void fade2Color(StripControle* strip, CRGBWW setColor, int fadeTime){
    //initialize timer with zero
    static unsigned long timer = 0;   

    //init vars for step size
    static int stepR, stepG, stepB, stepCW, stepWW;  

    //init vars for differences
    int difR, difG, difB, difCW, difWW;

    //get old color
    CRGBWW oldColor = strip->getColor();

    int64_t now = millis();

    //do nothing if finished or nothing to do
    if(oldColor == setColor){
        //reset timer to 0
        timer = 0;
        return ;
    }

    if(timer == 0 || now > timer + UPDATE_TIME){
        //calc difference if we may need it
        //todo overload - operator and simplyfy this
        int difR = setColor.R - oldColor.R;
        int difG = setColor.G - oldColor.G;
        int difB = setColor.B - oldColor.B;
        int difCW = setColor.CW - oldColor.CW ;
        int difWW = setColor.WW - oldColor.WW;        
    }

    if(timer == 0){
        //first run of function
        //and setColor is not already reached
        //calculate stepSize

        //calc number of steps
        float Steps = fadeTime/UPDATE_TIME;

        //calc step size per Color-Channel
        if(Steps > 1){
            stepR = difR/Steps;
            stepG = difG/Steps;
            stepB = difB/Steps;
            stepCW = difCW/Steps;
            stepWW = difWW/Steps;
        }else{
            //instant Jump -> step size is difference
            stepR = difR;
            stepG = difG;
            stepB = difB;
            stepCW = difCW;
            stepWW = difWW;
        }        
    }

    //if updateTime has passed since last timer var update set next color value
    if(now > timer + UPDATE_TIME){
        //update Timer
        timer = millis();

        //calculate new Color value
        CRGBWW newColor = CRGBWW();

        //Jump to end value or approach it one step for each color:

        if(difR < stepR){
            newColor.R = setColor.R;
        }else{
            newColor.R = strip->getColor().R+stepR;
        }

        if(difG < stepG){
            newColor.G = setColor.G;
        }else{
            newColor.G = strip->getColor().G+stepG;
        }

        if(difB < stepB){
            newColor.B = setColor.B;
        }else{
            newColor.B = strip->getColor().B+stepB;
        }

        if(difCW < stepCW){
            newColor.CW = setColor.CW;
        }else{
            newColor.CW = strip->getColor().CW+stepCW;
        }

        if(difWW < stepWW){
            newColor.WW = setColor.WW;
        }else{
            newColor.WW = strip->getColor().WW+stepWW;
        }
        
        //Write new Color to strip
        strip->showColor(newColor);

        Serial.println("newColor: ");
        Serial.print(newColor.R);
        Serial.print(newColor.G);
        Serial.print(newColor.B);
    }
}