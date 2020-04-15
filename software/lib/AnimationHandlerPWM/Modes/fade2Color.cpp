#include "modes.h"
//set update frequency/time
const uint UPDATE_TIME = 16;


void fade2Color(StripControle* strip, CRGBWW setColor, int fadeTime, long lastChange, CRGBWW oldColor){
    //initialize timer with zero
    static unsigned long timer = 0;

    long now = millis();

    //if updateTime has passed since last timer var update set next color value
    if(now > timer + UPDATE_TIME){
        //update Timer
        timer = millis();
        
        Serial.print("FadeTime: ");
        Serial.println(fadeTime);
        Serial.print("lastChange");
        Serial.println(lastChange);

        bool fadeEndReached = now > (lastChange+fadeTime);
        if(!fadeEndReached){
            
            
            float difR, difG, difB, difCW, difWW;
            difR = setColor.R - oldColor.R;
            difG = setColor.G - oldColor.G;
            difB = setColor.B - oldColor.B;
            difCW = setColor.CW - oldColor.CW ;
            difWW = setColor.WW - oldColor.WW;     


            //Calculate new Color Values
            CRGBWW newColor;
            newColor.R = oldColor.R+(now-lastChange)*(difR/fadeTime);
            Serial.print("newColor.R:");
            Serial.println(newColor.R);
            Serial.print("(now-lastChange)");
            Serial.println((now-lastChange));

            Serial.print("(difR/fadeTime)");
            Serial.println((difR/fadeTime));

        }else{
            //Write setColor to Strip
        }
        

    }

}