# ESP-LED - the ultimate LED-Strip-Controller-Board!

## What can it do?
* Controle RGB-LED strip (12V Mode)
* Controle RGBWW-LED strips (12V Mode)
* Controle WW LED-Strips (12V Mode)
* Controle WS2812 individually adressable LED Strips (5V Mode)
* Controle APA102 individually adressable LED Strips (5V Mode)
* Communicate over WiFi + MQTT
* Measure surrounding Temperature
* Sound-2-Light trough integrated Microphone

## How does it look like?
![3D-View](/doc/3d-view-1.jpeg)
![3D-View](/doc/3d-view-2.jpeg)

## How does the Pinning look like?
![3D-View](/doc/Pinout.png)

## How to use it?

### How to use it in 12V Mode with RGBWW
Hardware:
* You only need to insert as many MOSFETS (IRLZ34N) as you want to controle Channels. Bridge the jumpers according to the table below

Software:
* Boot into configuration mode (see software README) and change the "LED Type" to "RGB", "RGBW" or "RGBWW" for 3, 4 or 5 active channels.


### How to use it in 5V Mode with WS2812
Hardware:
* Just bridge the Jumpers according to the table below.

Software:
* Boot into configuration mode (see software README) and change the "LED Type" to "WS2812".


### How to use it in 5V Mode with APA102
Hardware:
* Just bridge the Jumpers according to the table below.

Software:
* Boot into configuration mode (see software README) and change the "LED Type" to "APA102".


## What controle the Jumpers?
| Jumpernumber | Connects-Between | Function         |
|--------------|------------------|------------------|
|       1      |Q1 Signal - Q1 Out| WS2812, APA102                  |
|       2      |Q2 Signal - Q2 Out| APA102           |
|       3      |Q3 Signal - Q3 Out|                  |
|       4      |Q4 Signal - Q4 Out|                  |
|       5      |Q5 Signal - Q5 Out|                  |
|       6      |   IO13 - Q1      | RGB, RGBW, RGBWW |
|       7      |   IO12 - Q2      | RGB, RGBW, RGBWW |
|       8      |   IO14 - Q3      | RGB, RGBW, RGBWW |
|       9      |   IO16 - Q4      | RGBW, RGBWW      |
|      10      |   IO5 - Q5       | RGBWW            |


## Which parts do I need?
See the Bill-Of-Materials file named ESPLED.csv in the hardware folder.

## Suggested MODES

| Modenumber   |        Name      | Description | used-Arguments-from-Var-Silo|
|--------------|------------------|-------------|-----------------------------|
|1|  Fade to color   |  Also used for jumps -> time = 0           | RGBWW-value, Transitiontime |
|2|  Blink color     |  Stores current State, Fades to color and back - Maybe posibility of selectiong number of blinks | RGBWW-value, Transition time, OnTime, NumOfBlinks |
|3|Strobe|Strobe selectable color and Freq|RGBWW-value, Freq |
|4|Sound2LIGHT|adjust brightness according to soundvalue|RGBWW-value, sensivitity |
|5|Breathing|Strip turns brighter and darker periodically (some randomness) |RGBWW-value, frequency how often it should "breath"|
|6|TempVis|Visualizes Temperatur Value of Temp Sensor - Cold(Blue)<>Normal(Green)<>Hot(Red)||
|7||||
|8||||
|101| Fire Animation|(exists online)|centerposition|
|102|Noise||RGBWW,update Rate|
|103|VU-Meter|| RGbWW, Sensitivity, update rate, centerposition|
|104|StrobeParts|Small x-LED long "Parts" light up in strobe mode|RGBWW, Freq, centerposition, PartLength|
|105|Moving Parts|Small x-LED long "Parts" travel from centerpos(=Startpos) - to the end(s) of the strip|RGBWW-value, update rate, centerposition, |
|106|American Police Light|red/blue left/right (half of adress room) flash|update rate|
|107|Rainbow|fills strip with rainbow maybe moves it||


## nice Projects with led animations for insperation
* GoodListOfAnimations for individually addressable strips: https://www.tweaking4all.com/hardware/arduino/arduino-all-ledstrip-effects-in-one/
* https://github.com/Aircoookie/WLED/wiki
