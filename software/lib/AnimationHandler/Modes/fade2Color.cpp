#include <AnimationHandler.h>

extern void debugFkt(String, LogLevel);

CRGBWW AnimationHandler::fade2Color(){
  debugFkt("Called fade2Color Mode Function", VERBOSE);

  long now = millis();

  bool fadeEndReached = now > (this->lastChange + this->silo->time);
  CRGBWW newColor;

  if(!fadeEndReached){
    float difR, difG, difB, difCW, difWW;
    difR = (int)(silo->colorValue.R - oldColor.R);
    difG = (int)(silo->colorValue.G - oldColor.G);
    difB = (int)(silo->colorValue.B - oldColor.B);
    difCW = (int)(silo->colorValue.CW - oldColor.CW) ;
    difWW = (int)(silo->colorValue.WW - oldColor.WW);

    //Calculate new Color Values
    newColor.R = oldColor.R+(now-lastChange)*(difR/silo->time);
    newColor.G = oldColor.G+(now-lastChange)*(difG/silo->time);
    newColor.B = oldColor.B+(now-lastChange)*(difB/silo->time);
    newColor.CW = oldColor.CW+(now-lastChange)*(difCW/silo->time);
    newColor.WW = oldColor.WW+(now-lastChange)*(difWW/silo->time);

    debugFkt("Fade2Color -> (now-lastChange):"+String(now-lastChange),VERBOSE);
    debugFkt("Fade2Color -> (difR/time):"+String(difR/silo->time),VERBOSE);

    //Debugg new ColorValue that gets send to StripControle
    debugFkt("NewColorValue Fade2Color (R-G-B-WW-CW):"+(String)newColor.R+","+(String)newColor.G+","+(String)newColor.B+","+(String)newColor.WW+","+(String)newColor.CW,DEBUG);

  }else{
    newColor.R = silo->colorValue.R;
    newColor.G = silo->colorValue.G;
    newColor.B = silo->colorValue.B;
    newColor.CW = silo->colorValue.CW;
    newColor.WW = silo->colorValue.WW;
    //Write colorValue to Strip
  }
  return newColor;
}
