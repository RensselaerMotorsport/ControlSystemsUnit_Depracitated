# Canbus

The Canbus class controls the two Waveshare USB-CAN-B modules, allowing other parts of the project to write to the car's three CAN buses. 

There are three CAN buses on the car: 250kbps, 500kbps, and 1000kbps. Note that this leaves one of the CAN ports unused. 

# Development notes

The provided Canbus libraries from Waveshare are not open source; they have been pre-compiled. This means that depending on whether you are compiling for x86 Linux (for testing) or for the Jetson Nano, you may need to manually swap out these libraries. They are located in source\waveshare-lib\canbus. The Canbus program also currently uses its own Makefile. Presumably, all of these problems will be dealt with when we make one master Makefile for the entire program.