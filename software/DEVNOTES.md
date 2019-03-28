# Software development notes and ideas
## User Interface
![User Interface](/doc/user.jpg)


## Class __StripControle__
![StripControle](/doc/StripControle.jpg)
## Solution to the double class problem

```
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
