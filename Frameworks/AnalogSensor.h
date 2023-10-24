//
// Created by kyle on 6/30/23.
//

#ifndef RENNSMOTORSPORT_ANALOGSENSOR_H
#define RENNSMOTORSPORT_ANALOGSENSOR_H
#include "Sensor.h"

template<typename T,
        typename U> //Generally going to be one or more floats
class AnalogSensor: public Sensor<T, U> {
public:
    AnalogSensor() : Sensor<T, U>() { channel = -1; }
    AnalogSensor(std::string name, DataLogger<T, U> log, int c, int h)
        : Sensor<T>(name, log, h) { channel = c; }

    //Getters:
    int getChannel() { return channel; }
    auto getData() -> T override;
protected:
    int channel;
};


#endif //RENNSMOTORSPORT_ANALOGSENSOR_H
