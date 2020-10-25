#ifndef TYPEDEFINITIONS_H
#define TYPEDEFINITIONS_H

//Struct for Storing Color Values
class CRGBWW
{
public:
  unsigned int R, G, B, WW, CW;

  //operator overloading
  //todo put this into an c++ file
  bool operator==(const CRGBWW &color) const
  {
    return (this->R == color.R &&
            this->G == color.G &&
            this->B == color.B &&
            this->CW == color.CW &&
            this->WW == color.WW);
  }
};

//Variable Silo -> Datastructure that gets recived via MQTT and defines what the
//Annimation Handlers/Modes do
typedef struct varSilo
{
  unsigned char mode;
  CRGBWW colorValue;
  unsigned int time;
  unsigned int frequency;
  unsigned char sensitivity;
  unsigned int position;
  unsigned int length;
  unsigned int minBrightnes;
  unsigned int maxBrightnes;
  unsigned int timeVariance;
  unsigned int maxBrightnesVariance;
  unsigned int duration;
  varSilo *oldVarSilo;
  CRGBWW oldColor;
  unsigned long lastChange;
} varSilo;

//Supported LED Strip Types
enum stripType
{
  RGB_STRIP = 3,
  RGBW_STRIP,
  RGBWW_STRIP,
  WS2812_STRIP,
  APA102_STRIP
};

//LED Strip Modes
enum Mode
{
  FADE_2_COLOR,
  BLINK_COLOR,
  STROBE,
  SOUND_2_LIGHT,
  BREATHE,
  TEMPVIS,
  INDUSTRIAL_FLICKER,

  WIPE = 100,
  NOISE,
  FIRE,
  VU_METER,
  STROBE_PARTS,
  MOVING_PARTS
};

//Log LEVELS
enum LogLevel
{
  VERBOSE,
  DEBUG,
  INFO,
  WARNING,
  ERROR
};

#endif
