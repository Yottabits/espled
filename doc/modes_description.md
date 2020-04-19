# Modes an mqtt 

## 0 fade2Color

### Description:
This is the most basic mode to change the strips color. You send the color a transition time. A transition time of 0 leads to an instant color jump.

### Parameters:
| Parameter | Effect | Unit | min. | man. |
|-----------|--------|------|------|------|
| mode      | changes Mode |  int    |  0    |  0    |
| color     | defines color in an Red-Green-Blue-WarmWhite-ColdWhite array | PWM  | 0    | 1023 |
| time      | time until the end color is reached | milliseconds | 0 | 4294967295 ~ 49.7d   |

### Example JSON:
``` JSON
{
  "mode":0,
  "color":[
      1023,
      1023,
      1023,
      1023,
      1023
  ],
  "time":1000
}
```


## 1 blinkColor

### Description:
This mode should be used for notifictaion. The Controller will store it's current state and blink in the selected color. You may select a number of blinks with the length parameter. 

### Parameters:
| Parameter | Effect | Unit | min. | man. |
|-----------|--------|------|------|------|
| mode      | changes Mode |  int    |  1    |  1    |
| color     | defines color in an Red-Green-Blue-WarmWhite-ColdWhite array   | PWM  | 0    | 1023 |
| time      | duration of one blink | milliseconds | 0 | 4294967295 ~ 49.7d   |
| legth      | number of blinks | int | 0 | ?   |

### Example JSON:
``` JSON
{
  "mode":1,
  "color":[
      1023,
      1023,
      1023,
      1023,
      1023
  ],
  "time":1000,
  "legth":3 
}
```

## 2 strobe
### Description:
This mode lights up the strip in the selected color and blinks it on/off in the selected frequency - no fading.

### Parameters:
| Parameter | Effect | Unit | min. | man. |
|-----------|--------|------|------|------|
| mode      | changes Mode |  t    |  2    |  2    |
| color     | defines color in an Red-Green-Blue-WarmWhite-ColdWhite array | PWM  | 0    | 1023 |
| frequency      | changes the strobe frequency |  Hz    |  1    |  60    |

### Example JSON:
``` JSON
{
  "mode":4,
  "color":[
      1023,
      0,
      0,
      0,
      0
  ],
  "time":6000,
  "minBrightnes":0,
  "maxBrightnes":1023,
  "timeVariance":3000,
  "maxBrightnesVariance":500
}
```

## 3 sound2Light

## 4 breathe
### Description:
This mode realizes a breathing function. This means the whole strip gets dimmed up and down. You can add some randomness to that through timeVariance and maxBrightnessVariance.

### Parameters:
| Parameter | Effect | Unit | min. | man. |
|-----------|--------|------|------|------|
| mode      | changes Mode |  t    |  4    |  4    |
| color     | defines color in an Red-Green-Blue-WarmWhite-ColdWhite array | PWM  | 0    | 1023 |
| time      | Period of whole "breath" (effected by time Variance) | milliseconds | 0 | 4294967295 ~ 49.7d   |
| minBrightnes | minimum Brightness | PWM | 0 | 1023 |
| maxBrightnes | maximum Brightness (effected by maxBrightnesVariance) | PWM | 0 | 1023 |
| timeVariance | if set each breath a random amount of ms within the Interval [-timeVariance <> +timeVariance] gets added to the breath time| millisceonds | 0 | 4294967295 ~ 49.7d  |
| maxBrightnesVariance | if set each breath a random amount of brightnes within the Interval [-maxBrightnesVariance <> +maxBrightnesVariance] gets added to maxBrightnes| PWM | 0 | 1023 |

### Example JSON:
``` JSON
{
  "mode":4,
  "color":[
      1023,
      0,
      0,
      0,
      0
  ],
  "time":6000,
  "minBrightnes":0,
  "maxBrightnes":1023,
  "timeVariance":3000,
  "maxBrightnesVariance":500
}
```