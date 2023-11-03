//
// Created by kyle on 6/30/23.
//

#ifndef RENNSMOTORSPORT_ANALOGSENSOR_H
#define RENNSMOTORSPORT_ANALOGSENSOR_H
#include "Sensor.h"
extern "C" {
#include "../High-Pricision_AD_HAT/c/lib/Driver/ADS1263.h" // For Analog Sensor Read
}

template<typename T>
class AnalogSensor: public Sensor<T> {
public:
    AnalogSensor() : Sensor<T>() { channel = -1; }
    AnalogSensor(std::string name, DataLogger<T> log, int c, int h)
        : Sensor<T>(name, log, h) { channel = c; }

    //Getters:
    int getChannel() { return channel; }
    auto getData() -> T override;
protected:
    UBYTE channel;
};


#endif //RENNSMOTORSPORT_ANALOGSENSOR_H
