#include "modes.h"

void blinkColor(StripControle* strip, CRGBWW setColor, int onTime, long lastChange, CRGBWW oldColor){
    //initialize timer with zero
    static unsigned long timer = 0;

    long now = millis();

    //if updateTime has passed since last timer var update set next color value
    if(now > timer + UPDATE_TIME){
        //update Timer
        timer = millis();

        /*Serial.print("FadeTime: ");
        Serial.println(fadeTime);
        Serial.print("lastChange");
        Serial.println(lastChange);

        Serial.print("setColor R: ");
        Serial.println(setColor.R);
        Serial.print("D: ");
        Serial.println(setColor.R); */
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

            Serial.print("newColor.R:");
            Serial.println(newColor.R);
            Serial.print("(now-lastChange)");
            Serial.println((now-lastChange));

            Serial.print("(difR/fadeTime)");
            Serial.println((difR/fadeTime));

        }else{
            newColor.R = setColor.R;
            newColor.G = setColor.G;
            newColor.B = setColor.B;
            newColor.CW = setColor.CW;
            newColor.WW = setColor.WW;
            //Write setColor to Strip
        }

        strip->showColor(newColor);


    }
}