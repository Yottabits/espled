#include <AnimationHandler.h>

CRGBWW AnimationHandler::fade2Color(){
  debugFkt("Called fade2Color Mode Function", VERBOSE);

  long now = millis();

  bool fadeEndReached = now > (silo->lastChange + this->silo->time);
  CRGBWW newColor;

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

    debugFkt("Fade2Color -> (now-lastChange):"+String(now-silo->lastChange),VERBOSE);
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
