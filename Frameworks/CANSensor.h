//
// Created by kyle on 6/30/23.
//

#ifndef RENNSMOTORSPORT_CANSENSOR_H
#define RENNSMOTORSPORT_CANSENSOR_H
#include "Sensor.h"

template<typename T>
template<typename U>
class CANSensor : public Sensor<T, U> {
public:
    CANSensor()  : Sensor<T>() { id = -1; }
    CANSensor(std::string name, DataLogger<T> log, int hZ, int i): Sensor<T>(name, log, hZ) { id = i; }

    //Getters:
    int getID() { return id; }
protected:
    int id;
};


#endif //RENNSMOTORSPORT_CANSENSOR_H
