
#include <AnimationHandler.h>
#include <StripControle.h>

class AnimationHandlerPWM : AnimationHandler{
  public:
    AnimationHandlerPWM(StripControle* strip, varSilo* silo, bool* varSiloChanged, MicHandler* micHandler);
    void handle();

  private:
    StripControle* strip;
};
