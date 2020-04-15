#include "StripControle.h"

StripControle::StripControle(stripType type){
  this->type = type;
}

void StripControle::showColor(CRGBWW color){
  channelValue = color;
  recalculateColor();
}

void StripControle::recalculateColor(){
  if(type == RGB){
    channelValue = RGBWW2RGB();
  }
  else if(type == RGBW){
    channelValue = RGBWW2RGBW();
  }
}

void StripControle::setChannels(){
  analogWrite(pinR, channelValue.R);
  analogWrite(pinG, channelValue.G);
  analogWrite(pinB, channelValue.B);
  analogWrite(pinCW, channelValue.CW);
  analogWrite(pinWW, channelValue.WW);
}

void StripControle::off(){
  channelValue = CRGBWW{0,0,0,0,0};
  setChannels();
}

CRGBWW StripControle::getColor(){
  return channelValue;
}

CRGBWW StripControle::RGBWW2RGB(){
  //TODO
  return channelValue;
}

CRGBWW StripControle::RGBWW2RGBW(){
  //TODO
  return channelValue;
}

CRGBWW StripControle::RGBW2RGB(){
  //TODO
  return channelValue;
}
