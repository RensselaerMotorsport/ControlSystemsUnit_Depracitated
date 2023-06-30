//
// Created by kyle on 6/30/23.
//

#ifndef RENNSMOTORSPORT_CANSENSOR_H
#define RENNSMOTORSPORT_CANSENSOR_H
#include "Sensor.h"

template<typename T>
class CANSensor : private Sensor<T> {
public:
    CANSensor()  : Sensor<T>() { frequency = -1; id = -1; }
private:
    int frequency;
    int id;
};


#endif //RENNSMOTORSPORT_CANSENSOR_H
