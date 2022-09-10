# Software development notes and ideas
## User Interface
![User Interface](/doc/user.jpg)


## Class __StripControle__
![StripControle](/doc/StripControle.jpg)


## Solution to the double class problem
```cpp
//Setup
FastLed* fastLed;
StripControle* stripControle;


//Init
if(ledChipsetBased)
{
  fastLed = new FastLed(ledArray);
}
else
{
  stripControle = new StripControle;
}
```

## AnnimationHandlers
* Both Classes AnimationHandlerPWM and AnimationHandlerBus have a method handle that is periodically called
* This handler then periodically calls functions defining the modes (distinct for bus and non Bus Stips)
* Example: animationHandlerBus.fade(Color,time)
* All current state Informations for timing-sensitive Modes is stored as static variables within their periodically called functions
* For Timing-Measurements we use the millis-command
* For Accessing the LEDs both AnimationHandlers hold attributes of the Type FastLedEndpoint and StripControleEndpoint which do the lower Level Stuff
* All Modes implemented in the AnimationHandlerPWM should also be Implemented in the AnimationHandlerBus
