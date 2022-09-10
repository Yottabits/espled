#include <AnimationHandler.h>

CRGBWW AnimationHandler::sound2Light(){

    static unsigned int myTimer = 0;
    if(millis() - myTimer > 200){
      myTimer = millis();
      
      micHandler->calculateFFT();
      micHandler->printVector();
    }
    return CRGBWW{0,0,0,0,0};
}
