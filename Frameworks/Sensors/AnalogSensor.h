//
// Created by kyle on 6/30/23.
//

#ifndef RENNSMOTORSPORT_ANALOGSENSOR_H
#define RENNSMOTORSPORT_ANALOGSENSOR_H
#include "Sensor.h"
extern "C" {
#include "../../High-Pricision_AD_HAT/c/lib/Driver/ADS1263.h" // For Analog Sensor Read
}

// Maybe UDOUBLE maybe template, TODO: ask amar
template<typename T>
class AnalogSensor: public Sensor<T, UDOUBLE> {
public:
    AnalogSensor() : Sensor<T, UDOUBLE>() { channel = -1; }
    AnalogSensor(std::string name, DataLogger<T> log, int c, int h)
        : Sensor<T, UDOUBLE>(name, log, h) { channel = c; }

    //Getters:
    int getChannel() { return channel; }
    auto getData() -> UDOUBLE override {
        UDOUBLE data = ADS1263_GetChannalValue(channel);
        return data;
    }
protected:
    UBYTE channel;
};


#endif //RENNSMOTORSPORT_ANALOGSENSOR_H
