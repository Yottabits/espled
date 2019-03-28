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
* You only need to insert as many MOSFETS (IRLZ34N) as you want to controle Channels

Software:
* Set define the number of Channels


### How to use it in 5V Mode with WS2812
Hardware: 
* You only need to 

Software:
* Set define mode to blabla


### How to use it in 5V Mode with APA102
Hardware: 
* You only need to 

Software:
* Set define mode to blabla


## What controle the Jumpers?
| Jumpernumber | Connects-Between | Function |
|--------------|------------------|----------|
|       1      |                  |          |
|       2      |                  |          |
|       3      |                  |          |
|       4      |                  |          |
|       5      |                  |          |
|       6      |                  |          |
|       7      |                  |          |
|       8      |                  |          |
|       9      |                  |          |
|      10      |                  |          |


## Which paarts do I need?

## Suggested MODES

| Modenumber   |        Name      | Description | used-Arguments-from-Var-Silo|
|--------------|------------------|-------------|-----------------------------|
|1|  Fade to color   |  Also used for jumps -> time = 0           | RGBWW-value, Transitiontime |
|2|  Blink color     |  Stores current State, Fades to color and back | RgBWW-value, Transition time, OnTime |
|3|Strobe|Strobe selectable color and Freq|RGBWW-value, Freq |
|4|Sound2LIGHT|adjust brightness according to soundvalue|RGbWW-value, sensivitity |
|5||||
|6||||
|7||||
|8||||
|101|Lagerfeuer Animation||centerposition|
|102|Noise|||
|103|VU-Meter|| RGbWW, Sensitivity, update rate, centerposition |



## Todo:
* Silcscreen
    * Namen
    * Bus-Icons
* Software
* Case
