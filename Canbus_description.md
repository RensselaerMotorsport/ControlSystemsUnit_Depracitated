# Canbus

The Canbus class controls the two Waveshare USB-CAN-B modules, allowing other parts of the project to write to the car's three CAN buses. 

There are three CAN buses on the car: 250kbps, 500kbps, and 1000kbps. Note that this leaves one of the CAN ports unused. 

# Using multiple Canbus modules
Rensselaer Motorsport uses two Canbus modules, each with two CAN ports. Each time the program is launched, these modules are assigned to either be "module 0" or "module 1". However, which module is assigned which number may change on each startup.

To resolve this, the defaultStartCanbus function returns a vector containing the serial number of each module. The 0-th item of the vector will be the serial number of module 0, and the 1st item will be module 1.


# Setup
`std::vector<std::string> defaultStartCanbus()`: Start the CANBUS module with the default Rensselaer Motorsport settings. 

These settings are: 
- CANBUS module 0 port CAN1 set to 250 kbps
- CANBUS module 0 port CAN2 set to 500 kbps
- CANBUS module 1 port CAN1 set to 1000 kbps
- CANBUS module 1 port CAN2 unused

Returns the serial numbers of each CANBUS module, as a vector of strings. See "Using multiple Canbus modules" for details. 



`void startCanbus(int portCount, int rates[], char deviceSerialNumbers[][20])`: Start the canbus using custom, advanced settings (not recommended). Rensselaer Motorsport does not need to use this function unless they change their mind about how many ports they need (but in that case, just modify the DefaultStartCanbus function). 

`portCount`: How many Canbus ports are being initialized. For example, setting this to 3 will initialize 3 Canbus ports across 2 modules.

`rates`: Array of data rates. Length must be deviceNumber.
Data rates are in Kbps and must be 250, 500, or 1000. (Any other data rates must be manually added to the setup function.)

`deviceSerialNumbers`: Must be initialized as a deviceCount by 20 array. Serial numbers of each device will be passed into here. 



# Send data
`int sendCanbusData(int DeviceNumber, int Port, int MessageID, std::string messageData, int Length, int MessageSendType, int MessageRemoteFlag, int MessageExternFlag)`: Send a CANBUS message. 

`DeviceNumber`: Which CANBUS module to send the message to. For Rensselaer Motorsport this will always be 0 or 1. 

`Port`: 1 to send on CAN1 port, 2 to send on CAN2 port

`MessageID`: Message identifier. Direct ID format, right-aligned.

`messageData`: String of 1-8 bytes/characters of data. This is the data that will be sent as the body of the CANBUS message. 

`Length`: Length of messageData.

`MessageSendType`: = 0 indicates Normal type, = 1 indicates Single Send.

`MessageRemoteFlag`: = 1 indicates remote flag, = 0 indicates data flag.

`MessageExternFlag`: = 1 indicates extern flag, = 0 indicates standard flag.

Returns 0 if the message is sent successfully. Returns 1 if the message fails to send. 



# Receive data
`std::vector<VCI_CAN_OBJ> receiveCanbusData(int DeviceNumber, int Port)`: Receives Canbus data for a short amount of time.

`DeviceNumber`: Which Canbus module to send to (either 0 or 1 for Motorsport)

`Port`: Whether to send to port CAN1 or CAN2 

Returns a vector containing all of the Canbus frames collected while the function was running. 

Frames are in VCI_CAN_OBJ format. See documentation for how to get data from this. 
To collect for longer, run the function multiple times. 



# Development notes

The provided Canbus libraries from Waveshare are not open source; they have been pre-compiled. This means that depending on whether you are compiling for x86 Linux (for testing) or for the Jetson Nano, you may need to manually swap out these libraries. They are located in source\waveshare-lib\canbus. The Canbus program also currently uses its own Makefile. Presumably, all of these problems will be dealt with when we make one master Makefile for the entire program.