void fadeToColor(StripControle* strip, CRGBWW setColor, int fadeTime){
    //initialize timer with zero
    static unsigned long timer = 0;
   
    //get old color
    CRGBWW oldColor = strip->getColor();

    //leave function if finished or nothing to do
    if(oldColor == setColor){
        //reset timer to 0
        timer = 0;
        return ;
    }

    //set update frequency/time
    int updateTime = 100

    //init vars for step size
    static int stepR, stepG, stepB, stepCW, stepWW;  

    if(timer == 0){
        //first run of function
        //and setColor is not already reached

        //calc difference
        int difR = oldColor.R - setColor.R;
        int difG = oldColor.G - setColor.G;
        int difB = oldColor.B - setColor.B;
        int difCW = oldColor.CW - setColor.CW;
        int difWW = oldColor.WW - setColor.WW;

        //calc step size per channel
        stepR = difR/(fadeTime/updateFreq);
        stepG = difG/(fadeTime/updateFreq);
        stepB = difB/(fadeTime/updateFreq);
        stepCW = difCW/(fadeTime/updateFreq);
        stepWW = difWW/(fadeTime/updateFreq);
    }

    //if updateTime has passed since last timer var update set next color value
    if( millis() > timer + updateTime){
        //update Timer
        timer = millis();
    
        //calculate new Color value
        CRGBWW newColor();
        newColor.R = strip->getColor().R+stepR;
        newColor.G = strip->getColor().G+stepG;
        newColor.B = strip->getColor().B+stepB;
        newColor.CW = strip->getColor().CW+stepCW;
        newColor.WW = strip->getColor().WW+stepWW;

        //Write new Color to strip
        strip->showColor(newColor);
}