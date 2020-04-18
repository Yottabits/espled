#include <AnimationHandler.h>
#include <FastLED.h>

CRGBWW AnimationHandler::breathe(){

    static int fadeTimeNoise = random16(- silo->timeVariance, silo->timeVariance);
    static int maxBrightnesNoise = random16(- silo->maxBrightnesVariance, silo->maxBrightnesVariance);

    static int noisedFadeTime = 0;
    static int noisedMaxBightnes = 0;

    static unsigned int fadeTimer = 0;
    static float angularVelocity = 0;

    unsigned int now = millis();
    if(now > fadeTimer + noisedFadeTime){
        fadeTimer = now;

        //random16 only uint -> shift
        fadeTimeNoise = random16(0, silo->timeVariance*2) - silo->timeVariance;
        maxBrightnesNoise = random16(0, silo->maxBrightnesVariance*2) - silo->maxBrightnesVariance;

        noisedFadeTime = silo->time + fadeTimeNoise;
        noisedMaxBightnes = silo->maxBrightnes +maxBrightnesNoise;

        angularVelocity = (65535.0f)/(float)(noisedFadeTime);
    }


    int rawCos = -cos16((now-fadeTimer)*angularVelocity);
    int currentBrightnes = map(rawCos,-32767,32767,silo->minBrightnes,noisedMaxBightnes);

    float scaleFactor = currentBrightnes / 1023.0;

    CRGBWW newColor;
    newColor.R = silo->colorValue.R * scaleFactor;
    newColor.G = silo->colorValue.G * scaleFactor;
    newColor.B = silo->colorValue.B * scaleFactor;
    newColor.WW = silo->colorValue.WW * scaleFactor;
    newColor.CW = silo->colorValue.CW * scaleFactor;


    debugFkt(
      "currentBrightnes: " + String(currentBrightnes) +
      " angularVelocity: " + String(angularVelocity) +
      " now-fadeTimer*angularVelocity: " + String((now - fadeTimer)*angularVelocity) +
      " noisedFadeTime: " + String(noisedFadeTime) +
      " noisedMaxBightnes" + String(noisedMaxBightnes) +
      " fadeTimeNoise: " + String(fadeTimeNoise) +
      " maxBrightnesNoise: " + String(maxBrightnesNoise),

      DEBUG);

    return newColor;
}
