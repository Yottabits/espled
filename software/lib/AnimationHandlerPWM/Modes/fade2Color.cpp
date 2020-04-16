#include "modes.h"
//set update frequency/time
const uint UPDATE_TIME = 16;
extern void debugFkt(String, LogLevel);


void fade2Color(StripControle* strip, CRGBWW setColor, unsigned int fadeTime, long lastChange, CRGBWW oldColor){
    debugFkt("Called fade2Color Mode Function",VERBOSE);

    //initialize timer with zero
    static unsigned long timer = 0;

    long now = millis();

    //if updateTime has passed since last timer var update set next color value
    if(now > timer + UPDATE_TIME){
        //update Timer
        timer = millis();

        bool fadeEndReached = now > (lastChange+fadeTime);
        CRGBWW newColor;

        if(!fadeEndReached){
            float difR, difG, difB, difCW, difWW;
            difR = (int)(setColor.R - oldColor.R);
            difG = (int)(setColor.G - oldColor.G);
            difB = (int)(setColor.B - oldColor.B);
            difCW = (int)(setColor.CW - oldColor.CW) ;
            difWW = (int)(setColor.WW - oldColor.WW);

            //Calculate new Color Values
            newColor.R = oldColor.R+(now-lastChange)*(difR/fadeTime);
            newColor.G = oldColor.G+(now-lastChange)*(difG/fadeTime);
            newColor.B = oldColor.B+(now-lastChange)*(difB/fadeTime);
            newColor.CW = oldColor.CW+(now-lastChange)*(difCW/fadeTime);
            newColor.WW = oldColor.WW+(now-lastChange)*(difWW/fadeTime);

            debugFkt("Fade2Color -> (now-lastChange):"+String(now-lastChange),VERBOSE);
            debugFkt("Fade2Color -> (difR/fadeTime):"+String(difR/fadeTime),VERBOSE);
            
        }else{
            newColor.R = setColor.R;
            newColor.G = setColor.G;
            newColor.B = setColor.B;
            newColor.CW = setColor.CW;
            newColor.WW = setColor.WW;
            //Write setColor to Strip
        }

        //Debugg new ColorValue that gets send to StripControle
        debugFkt("NewColorValue Fade2Color (R-G-B-CW-WW):"+(String)newColor.R+","+(String)newColor.G+","+(String)newColor.B+","+(String)newColor.CW+","+(String)newColor.WW,DEBUG);


        strip->showColor(newColor);


    }

}
