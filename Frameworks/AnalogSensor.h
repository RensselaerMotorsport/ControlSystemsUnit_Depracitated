//
// Created by kyle on 6/30/23.
//

#ifndef RENNSMOTORSPORT_ANALOGSENSOR_H
#define RENNSMOTORSPORT_ANALOGSENSOR_H
#include "Sensor.h"

template<typename T>
class AnalogSensor: public Sensor<T> {
public:
    AnalogSensor() : Sensor<T>() { channel = -1; hZ = -1; }
    AnalogSensor(std::string name, DataLogger<T> log, int p, int c, int h) : Sensor<T>(name, log, p) { channel = c; hZ = h; }

    //Getters:
    int getChannel() { return channel; }
    int getHZ() { return hZ; }
private:
    int channel;
    //sample rate?
    int hZ;
};


#endif //RENNSMOTORSPORT_ANALOGSENSOR_H
