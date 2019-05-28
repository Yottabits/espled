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


//Loop
if(ledChipsetBased)
{
  switch(mode){
    case 0:{
      ...
    }
    case 1:{
      ...
    }
    case 2:{
      ...
    }
  }
}
else
{
  switch(mode){
    case 0:{
      ...
    }
    case 1:{
      ...
    }
    case 2:{
      ...
    }
  }
}
```

## AnnimationHandlers
* Inside the Cases Methods of the Class AnimationHandlerPWM or AnimationHandlerBus should be called
* Example: animationHandlerBus.fade(Color,time)
* All current state Informations for timing-sensitive Modes should be stored in the AnnimationHandler-Object
* For Timing-Measurements we use the millis-command
* For Accessing the LEDs both AnimationHandlers hold attributes of the Type FastLedEndpoint and StripControleEndpoint which do the lower Level Stuff
* All Modes implemented in the AnimationHandlerPWM should also be Implemented in the AnimationHandlerBus
