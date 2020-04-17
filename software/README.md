# Software manual
## Introduction

Although the ESPLED board is fully customizable, the default software should satisfy most users.

## Booting procedure
![boot](/doc/boot_procedure.png)

## Configuration
The configuration mode allows you to select your local WiFi network and the type of led strip you want to use.

To enter the configuration mode, perform the following tasks:
- Press the __reset__ button
- Press and hold the __mode__ button after within 1 second after releasing the reset button
- Release the __mode__ button within 2 seconds

After sucessfully entering the configuration mode, use your smartphone or computer to connect to the wireless network called "ESPLED config" and follow the screen.

## Control LEDs
There are three different interfaces to connect to the controller.
*MQTT
*REST API
*On-Board-Button

### MQTT
The different functions of the controller are available under the following MQTT topic:
*/ESPLED/FF:FF:FF:FF:FF:FF* (replace with MAC of your device, visible in the setup routine)

The payload contais json in the following format:

```
{
  "mode": 0,
  "color": [
    1023,
    255,
    255,
    255,
    255
  ],
  "time": 1000
}
```

|   Function                               |       Topic              |      Values        |
|------------------------------------------|--------------------------|--------------------|
| Change Mode                              | mode                     | 0 to 200           |
| Color amplitudes                         | color[ R,G,B,(CW),(WW) ] | 10 bit integer     |
| Timeframe in milliseconds(ex. fade time) | time                     | unsigned integer   |
| Frequency in hertz                       | frequency                | float              |
| Relativ sensitivity                      | sensitivity              | float (0.0 to 1.0) |
| Number of leds (mode specific)           | length                   | unsigned integer   |
| Select start led (mode specific)         | position                 | unsigned integer   |
