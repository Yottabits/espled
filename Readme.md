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

## Supported Modes
See Wiki (https://github.com/Yottabits/espled/wiki/Modes-Description)

## nice Projects with led animations for insperation
* GoodListOfAnimations for individually addressable strips: https://www.tweaking4all.com/hardware/arduino/arduino-all-ledstrip-effects-in-one/
* https://github.com/Aircoookie/WLED/wiki
