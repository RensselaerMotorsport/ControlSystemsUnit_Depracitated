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


    //functions:
    void transfer_function(){

    }
public:
    float get_distance(){

    }
    float get_acceleration();
    string get_wheel_location(){ return shock_location; }
};


#endif //CONTROLSYSTEMSUNIT_SHOCKPOT_H
