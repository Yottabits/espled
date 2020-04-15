#include <TypeDefinitions.h>
#include <StripControle.h>

//declare  Modes
void fade2Color(StripControle* strip, CRGBWW setColor, int fadeTime);
void blinkColor(StripControle* strip, CRGBWW setColor, int onTime);
void sound2Light(StripControle* strip);
void strobe(StripControle* strip);