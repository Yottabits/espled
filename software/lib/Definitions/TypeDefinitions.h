#ifndef TYPEDEFINITIONS_H
#define TYPEDEFINITIONS_H

//Struct for Storing Color Values
class CRGBWW{
  public:
    unsigned int R, G, B, CW, WW;

    //operator overloading
    //todo put this into an c++ file
    bool operator==(const CRGBWW &color) const{
      return (this->R == color.R && 
          this->G == color.G &&  
          this->B == color.B && 
          this->CW == color.CW && 
          this->WW == color.WW);
    }
};


//Variable Silo -> Datastructure that gets recived via MQTT and defines what the 
//Annimation Handlers/Modes do
typedef struct{
  unsigned char mode;
  CRGBWW colorValue;
  unsigned int time;
  unsigned int frequency;
  unsigned char sensitivity;
  unsigned int position;
  unsigned int length;
} varSilo;

//Supported LED Strip Types
enum stripType {RGB = 3, RGBW, RGBWW, WS2812, APA102};


//LED Strip Modes
enum Mode {FADE_2_COLOR, BLINK_COLOR, STROBE, SOUND_2_LIGHT, FIRE, NOISE, VU_METER, STROBE_PARTS, MOVING_PARTS};

#endif
