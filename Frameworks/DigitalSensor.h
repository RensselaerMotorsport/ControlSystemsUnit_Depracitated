/*  *///
// Created by kyle on 6/30/23.
//

#ifndef RENNSMOTORSPORT_DIGITALSENSOR_H
#define RENNSMOTORSPORT_DIGITALSENSOR_H
#include "Sensor.h"

template<typename T>
template<typename U> //Generally one or more ints
class DigitalSensor: public Sensor<T, U> {
public:
    DigitalSensor() : Sensor<T>() {}
    DigitalSensor(std::string name, DataLogger<T> log, int hz, int p) : Sensor<T>(name, log, hz) { port = p; }

    auto getData() -> T override;
private:
    int port;
};


#endif //RENNSMOTORSPORT_DIGITALSENSOR_H
