#ifndef ANIMATIONHANDLER_H
#define ANIMATIONHANDLER_H

#include <Arduino.h>
#include <TypeDefinitions.h>
#include <PinDefinitions.h>

#include <MicHandler.h>

extern void debugFkt(String, LogLevel);

class AnimationHandler{
  public:
    AnimationHandler(varSilo* silo, bool* varSiloChanged, MicHandler* micHandler);

    CRGBWW fade2Color();
    CRGBWW blinkColor();
    CRGBWW sound2Light();
    CRGBWW strobe();
    CRGBWW breathe();

    void rgb2hsv(CRGBWW &rgbContainer, unsigned int hsvContainer[]);
    void hsv2rgb(unsigned int hsvContainer[], CRGBWW &rgbContainer);

  protected:
    varSilo* silo;
    bool* varSiloChanged;
    long lastChange = 0;
    CRGBWW oldColor{0,0,0,0,0};

    MicHandler* micHandler;

    unsigned int fpsTimer = 0;
    unsigned int UPDATE_TIME = 16;

};

#endif
