//
// Created by harshk on 10/31/2023.
//

#ifndef CONTROLSYSTEMSUNIT_ACCELEROMETERWRAPPER_H
#define CONTROLSYSTEMSUNIT_ACCELEROMETERWRAPPER_H

#include "Accelerometer.h"

class AccelerometerWrapper {
public:
    AccelerometerWrapper(Accelerometer ax, Accelerometer ay, Accelerometer az) { x = ax; y = ay; z = az; }

private:
    Accelerometer x;
    Accelerometer y;
    Accelerometer z;
};


#endif //CONTROLSYSTEMSUNIT_ACCELEROMETERWRAPPER_H
