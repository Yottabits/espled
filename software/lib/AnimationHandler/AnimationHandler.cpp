#include "AnimationHandler.h"

AnimationHandler::AnimationHandler(varSilo* silo, bool* varSiloChanged){
    this->silo = silo;
    this->varSiloChanged = varSiloChanged;
}
