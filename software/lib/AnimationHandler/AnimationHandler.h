#ifndef ANIMATIONHANDLER_H
#define ANIMATIONHANDLER_H

#include <Arduino.h>
#include <TypeDefinitions.h>
#include <PinDefinitions.h>

//extern void debugFkt(String, LogLevel);

class AnimationHandler{
  public:
    AnimationHandler(varSilo* silo, bool* varSiloChanged);
    void handle();

    CRGBWW fade2Color();
    CRGBWW blinkColor();
    CRGBWW sound2Light();
    CRGBWW strobe();
    CRGBWW breathe();


  protected:
    varSilo* silo;
    bool* varSiloChanged;
    long lastChange = 0;
    CRGBWW oldColor{0,0,0,0,0};

    const unsigned int UPDATE_TIME = 16;

};

#endif
