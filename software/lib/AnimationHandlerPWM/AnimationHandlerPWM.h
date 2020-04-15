//#include <TypeDefinitions.h>
#include <StripControle.h>
#include <Modes/modes.h>

class AnimationHandlerPWM{
  public:
    AnimationHandlerPWM(StripControle* strip, varSilo* silo);
    void handle();
    
  private:
    StripControle* strip;
    varSilo* silo;
};

