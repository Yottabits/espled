#include "AnimationHandlerPWM.h"


void AnimationHandlerPWM::handle(StripControle* strip, varSilo* silo){
    switch (silo->mode)
    {
    case 0:
        Fade2Color(strip, silo->colorValue, silo->time)
        break;
    
    default:
        break;
    }
}
