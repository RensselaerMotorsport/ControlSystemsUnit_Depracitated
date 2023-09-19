//
// Created by kyle on 6/30/23.
//

#ifndef RENNSMOTORSPORT_DIGITALSENSOR_H
#define RENNSMOTORSPORT_DIGITALSENSOR_H
#include "Sensor.h"

template<typename T>
class DigitalSensor: private Sensor<T> {
public:
    DigitalSensor() : Sensor<T>() {}
    DigitalSensor(std::string name, DataLogger<T> log, int p) : Sensor<T>(name, log, p) {}
private:

};


#endif //RENNSMOTORSPORT_DIGITALSENSOR_H
