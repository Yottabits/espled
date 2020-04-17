#include <TypeDefinitions.h>
#include <StripControle.h>

//declare  Modes
void fade2Color(StripControle* strip, CRGBWW setColor, unsigned int fadeTime, long lastChange, CRGBWW oldColor);
void blinkColor(StripControle* strip, CRGBWW setColor, int onTime, long lastChange, CRGBWW oldColor);
void sound2Light(StripControle* strip);
void strobe(StripControle* strip);
void breathe(StripControle* strip, CRGBWW setColor, unsigned int fadeTime, unsigned int minBrightnes, unsigned int maxBrightnes,  unsigned int timeVariance, unsigned int maxBrightnesVariance);
