//#include <TypeDefinitions.h>
#include <StripControle.h>
#include <Modes/modes.h>

class AnimationHandlerPWM{
  public:
    AnimationHandlerPWM(StripControle* strip, varSilo* silo, bool* varSiloChanged);
    void handle();
    
  private:
    StripControle* strip;
    varSilo* silo;
    bool* varSiloChanged;
};

