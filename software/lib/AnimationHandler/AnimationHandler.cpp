#include <AnimationHandler.h>

AnimationHandler::AnimationHandler(varSilo* silo, bool* varSiloChanged, MicHandler* micHandler){
    this->silo = silo;
    this->varSiloChanged = varSiloChanged;
    this->micHandler = micHandler;
}


 void AnimationHandler::rgb2hsv(CRGBWW &rgbContainer, unsigned int hsvContainer[])
{
    float r = rgbContainer.R / 1023.0f;
    float g = rgbContainer.G / 1023.0f;
    float b = rgbContainer.B / 1023.0f;

    float h, s, v; // h:0-360.0, s:0.0-1.0, v:0.0-1.0

    float min =  fminf(r, fminf(g, b));
    float max =  fmaxf(r, fmaxf(g, b));

    v = max;

    if (max == 0.0f) {
        s = 0;
        h = 0;
    }
    else if (max - min == 0.0f) {
        s = 0;
        h = 0;
    }
    else {
        s = (max - min) / max;

        if (max == r) {
            h = 60 * ((g - b) / (max - min)) + 0;
        }
        else if (max == g) {
            h = 60 * ((b - r) / (max - min)) + 120;
        }
        else {
            h = 60 * ((r - g) / (max - min)) + 240;
        }
    }
    if (h < 0) h += 360.0f;

    hsvContainer[0] = (unsigned int)(h / 2);   // dst_h : 0-180
    hsvContainer[1] = (unsigned int)(s * 1023); // dst_s : 0-255
    hsvContainer[2] = (unsigned int)(v * 1023); // dst_v : 0-255
}

void AnimationHandler::hsv2rgb(unsigned int hsvContainer[], CRGBWW &rgbContainer)
{
    float h = hsvContainer[0] *   2.0f; // 0-360
    float s = hsvContainer[1] / 1023.0f; // 0.0-1.0
    float v = hsvContainer[2] / 1023.0f; // 0.0-1.0

    float r, g, b; // 0.0-1.0

    int   hi = (int)(h / 60.0f) % 6;
    float f  = (h / 60.0f) - hi;
    float p  = v * (1.0f - s);
    float q  = v * (1.0f - s * f);
    float t  = v * (1.0f - s * (1.0f - f));

    switch(hi) {
        case 0: r = v, g = t, b = p; break;
        case 1: r = q, g = v, b = p; break;
        case 2: r = p, g = v, b = t; break;
        case 3: r = p, g = q, b = v; break;
        case 4: r = t, g = p, b = v; break;
        case 5: r = v, g = p, b = q; break;
    }

    rgbContainer.R = (unsigned int)(r * 1023); // dst_r : 0-255
    rgbContainer.G = (unsigned int)(g * 1023); // dst_r : 0-255
    rgbContainer.B = (unsigned int)(b * 1023); // dst_r : 0-255
}
