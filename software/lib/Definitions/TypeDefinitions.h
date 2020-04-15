#ifndef TYPEDEFINITIONS_H
#define TYPEDEFINITIONS_H

typedef struct {
  unsigned int R, G, B, CW, WW;
} CRGBWW;


typedef struct{
  unsigned char mode;
  CRGBWW colorValue;
  unsigned int time;
  unsigned int frequency;
  unsigned char sensitivity;
  unsigned int position;
  unsigned int length;
} varSilo;

#endif
