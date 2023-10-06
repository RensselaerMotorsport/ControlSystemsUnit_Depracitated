/*  *///
// Created by kyle on 6/30/23.
//

#ifndef RENNSMOTORSPORT_DIGITALSENSOR_H
#define RENNSMOTORSPORT_DIGITALSENSOR_H
#include "Sensor.h"

template<typename T>
class DigitalSensor: public Sensor<T> {
public:
    DigitalSensor() : Sensor<T>() {}
    DigitalSensor(std::string name, DataLogger<T> log, int p, int hz) : Sensor<T>(name, log, p, hz) {}
private:

};


#endif //RENNSMOTORSPORT_DIGITALSENSOR_H
