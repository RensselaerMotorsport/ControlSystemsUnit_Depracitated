//
// Created by kyle on 6/30/23.
//

#ifndef RENNSMOTORSPORT_DIGITALSENSOR_H
#define RENNSMOTORSPORT_DIGITALSENSOR_H
#include "Sensor.h"

template<typename T>
class DigitalSensor: private Sensor<T> {
public:
    DigitalSensor() : Sensor<T>() { port = -1; }
private:
    int port;
};


#endif //RENNSMOTORSPORT_DIGITALSENSOR_H
