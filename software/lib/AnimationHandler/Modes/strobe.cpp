#include <AnimationHandler.h>

CRGBWW AnimationHandler::strobe(){
    debugFkt("Called strobe mode function", VERBOSE);
    
     if(this->silo->frequency == 0 || this->silo->frequency > 60){
       debugFkt("Frequency was set to 0 or over 60 this is not possible", ERROR);
    }

    long now = millis();
    static long lastStateChange = now;
    long period = (1000/this->silo->frequency);
    static bool nextOnOff = false;
    CRGBWW newColor;

    if(now >= lastStateChange + period){
        lastStateChange = now;

        if(nextOnOff == false){
            newColor = CRGBWW{0,0,0,0,0};
            debugFkt("sent Strobe State off", VERBOSE);
            nextOnOff == true;
        }else{
            newColor.R = silo->colorValue.R;
            newColor.G = silo->colorValue.G;
            newColor.B = silo->colorValue.B;
            newColor.CW = silo->colorValue.CW;
            newColor.WW = silo->colorValue.WW;
            nextOnOff == false;
            debugFkt("sent Strobe State on", VERBOSE);
        }
        
    }

  return newColor;
}
