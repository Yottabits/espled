#include <StripControle.h>


StripControle::StripControle(StripType type){
  this->type = type;
  this->off();
}

void StripControle::showColor(CRGBWW color){
  channelValue = color;
  recalculateColor();
  setChannels();
}

void StripControle::recalculateColor(){
  if(type == RGB_STRIP){
    channelValue = RGBWW2RGB();
  }
  else if(type == RGBW_STRIP){
    channelValue = RGBWW2RGBW();
  }
}

void StripControle::setChannels(){
  analogWrite(pinR, channelValue.R);
  //Serial.println(channelValue.R);
  analogWrite(pinG, channelValue.G);
  analogWrite(pinB, channelValue.B);
  analogWrite(pinWW, channelValue.WW);
  analogWrite(pinCW, channelValue.CW);
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
