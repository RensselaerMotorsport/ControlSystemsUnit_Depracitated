# SensorADC

The SensorADC class controls the Waveshare ADC1263 breakout board and the attached multiplexer board. It is used to receive data from up to 34 analog sensors. This class includes calls to the official driver functions of both the Jetson Nano and the ADC1263, as well as some control logic for the multiplexers and "channel" system. 

This implementation is designed to work with 4-to-1 multiplexers attached to analog inputs 1-8 (for slower inputs), while pins 9-10 can be used for high-speed inputs. This allows for 24 "delayed" inputs and 2 "realtime" inputs. 

## Initialization

To initialize the ADC, run the following function: ``` void InitADC()``` 

This will configure both the ADC and the GPIO pins on the Jetson Nano. 

## Fetching Data

To fetch data from the ADC, use the following function: ```UDOUBLE FetchSensor(int channel, int port)```

For example: ```bms_voltage = FetchSensor(3, 5)``` will get the sensor data on channel 3, port 5 (labeled as 3_5 on the multiplexer board). 

When fetching sensor data, it is recommended to do so one channel at a time to avoid unnecessary switching. See below explanation of "channels" for details. 

## Channels and Timing

The multiplexers effectively split the ADC into 4 "channels", with 8 analog input ports on each channel (one for each multiplexer). To allow the ADC to obtain an updated signal after the multiplexer switches signals, there is a 30 microsecond delay after switching channels. This channel switching (and delay) occurs automatically when a request is made for sensor data on a different channel. 

To avoid this delay, it is best to minimize channel switching; this can be done by putting high-speed signals on the same channel (recommended breakdown for RM25 is shown below). Inputs 8 and 9 (the two "fast" inputs) are not connected to a multiplexer. They therefore have no delay and can be considered part of every channel. 

Recommended breakdown for last year's sensors:

```
Channel 0 (Unlimited)
Steering column

Channel 1 (1000 hz):
Shock Position (4), Wheel Speed (4)

Channel 2 (200 hz):
APPS, Strain Gagues (2), Brake Pressure (2), Accelerometer (3)

Channel 3 (40 hz):
Coolant Pressure, Cooling, GPS, Brake Rotor Temperature, BMS

Channel 4: Not assigned. One input on each multiplexer is left disconnected. 
```

When fetching sensor data, it is recommended to do so one channel at a time to avoid unnecessary switching. 

Note that the official Waveshare ADC1263 documentation also refers to its 10 analog inputs as "channels". Here, we instead refer to them as "inputs" or "ports". 

## Pinout for Multiplexer Board

LSB: GPIO pin 20 on the ADC (aka 38 on the Jetson Nano) -> a0 for all multiplexers

MSB: GPIO pin 21 on the ADC (aka 40 on the Jetson Nano) -> a1 for all multiplexers

It is recommended to use four ADG1309 multiplexers (see LTSpice schematic).