//
// Created by kyle on 6/30/23.
//

#ifndef RENNSMOTORSPORT_ANALOGSENSOR_H
#define RENNSMOTORSPORT_ANALOGSENSOR_H
#include "Sensor.h"

template<typename T>
class AnalogSensor: public Sensor<T> {
public:
    AnalogSensor(std::string name) : Sensor<T>(name) { channel = -1; hZ = -1; }
private:
    int channel;
    //sample rate?
    int hZ;
};


#endif //RENNSMOTORSPORT_ANALOGSENSOR_H
