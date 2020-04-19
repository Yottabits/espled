# Modes an mqtt 

## 0 fade2Color

### Description:
### Parameters:
| Parameter | Effect | Unit | min. | man. |
|-----------|--------|------|------|------|
| mode      | changes Mode |  t    |  0    |  0    |
| color     |        | PWM  | 0    | 1023 |
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
  ]
  "time":1000
}
```


## 1 blinkColor

### Description:
### Parameters:
### Example JSON:
'''
{
  "mode":1,
  "color":[
      1023,
      1023,
      1023,
      1023,
      1023
  ]
  "time":1000,
  "legth":3 
}
'''

## 2 strobe

## 3 sound2Light

## 4 breathe

### Description:
This mode realizes a breathing function. This means the whole strip gets dimmed up and down. You can add some randomness to that through timeVariance and maxBrightnessVariance.

### Parameters:
| Parameter | Effect | Unit | min. | man. |
|-----------|--------|------|------|------|
| mode      | changes Mode |  t    |  4    |  4    |
| color     |        | PWM  | 0    | 1023 |
| time      | Period of whole "breath" (effected by time Variance) | milliseconds | 0 | 4294967295 ~ 49.7d   |
| minBrightnes | minimum Brightness | PWM | 0 | 1023 |
| maxBrightnes | maximum Brightness (effected by maxBrightnesVariance) | PWM | 0 | 1023 |
| timeVariance | if set each breath a random amount of ms within the Interval [-timeVariance <> +timeVariance] gets added to the breath time| millisceonds | 0 | 4294967295 ~ 49.7d  |
| maxBrightnesVariance | if set each breath a random amount of brightnes within the Interval [-maxBrightnesVariance <> +maxBrightnesVariance] gets added to maxBrightnes| PWM | 0 | 1023 |

### Example JSON:
'''
{
  "mode":4,
  "color":[
      1023,
      0,
      0,
      0,
      0
  ]
  "time":6000,
  "minBrightnes":0,
  "maxBrightnes":1023,
  "timeVariance":3000,
  "maxBrightnesVariance":500
}
'''