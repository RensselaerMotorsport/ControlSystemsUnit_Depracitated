//
// Created by harshk on 7/21/2023.
//

#ifndef CONTROLSYSTEMSUNIT_SHOCKPOT_H
#define CONTROLSYSTEMSUNIT_SHOCKPOT_H

#include "WheelSpeed.h"

class ShockPot {
private:
    //variables
    float raw_signal;
    float distance;
    float acceleration;
    WHEEL_LOCATION shock_location; //front left, front right, back left, back right


    functions:
    (void, private) transfer_function
            (double, public) get_distance
            (double, public) get_acceleration
    (string, public) get_wheel_location
};


#endif //CONTROLSYSTEMSUNIT_SHOCKPOT_H
