#include "AnnimationHandlerPWM.h"
#include "Modes/Fade2Color.h"

void AnimationHandlerPWM::handle(varSilo Silo){
    switch (mode)
    {
    case 0:
        Fade2Color(Silo.colorValue, Silo.time)
        break;
    
    default:
        break;
    }
}
